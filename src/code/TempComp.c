// TempComp.C
// Handles Temperature Compensation Functionality

#include "TempComp.h"

#define TEMPCOMPSTATE 		focuserPtr->tempCompInfoStr.TempCompState 
#define RESET_CNTR			focuserPtr->tempCompInfoStr.ResetCounter

STATIC int calculateDeltaSteps(focuser * focuserPtr);

void InitTempComp( focuser * p_focuser)
{
	// Make sure both start from the reset state.
	//MyFocuser1.tempCompInfoStr.ResetRequired = 1;
	p_focuser->tempCompInfoStr.ResetRequired = 1;
}	

void DoTempComp(focuser * focuserPtr)
{
	if(focuserPtr->tempCompInfoStr.TempCompOn == 0) 
	{
		if(focuserPtr->tempCompInfoStr.TempCompState != SM_IDLE)
		{
			// stop the move
			focuserPtr->tempCompInfoStr.TempCompState = SM_IDLE;
			focuserPtr->statusStr.TargetPosition = focuserPtr->statusStr.CurrentPosition;
		}		
	}
	else if(!focuserPtr->statusStr.IsHomed)
		return;
	else if(focuserPtr->tempCompInfoStr.ResetRequired == 1) 
		focuserPtr->tempCompInfoStr.TempCompState = SM_RESET;		
						
	switch (TEMPCOMPSTATE)
	{	
		case SM_IDLE:
			// Here we are waiting for Temp Comp flag to be turned on...
			if(focuserPtr->tempCompInfoStr.TempCompOn == 1) 
			{
				RESET_CNTR = 0;
				TEMPCOMPSTATE = SM_RESET;
			}	
			break;
			
		case SM_RESET:
			// Make sure all movement has stopped...
			if(focuserPtr->statusStr.CurrentPosition == focuserPtr->statusStr.TargetPosition)
			{
				// The reset counter provides a delay before temp comp turns back on
				// after a move was executed.
				if(++RESET_CNTR > 100)
				{
					RESET_CNTR = 0;
					// Set the new starting temps and positions
					focuserPtr->tempCompInfoStr.LastTempCompStartTemp = focuserPtr->statusStr.CurrentTemp;
					focuserPtr->tempCompInfoStr.LastTempCompStartPos = focuserPtr->statusStr.CurrentPosition;
					
					//Store the Temp Comp Info in EEPROM now...
					SaveTempCompStartPoint(focuserPtr);
					
					focuserPtr->tempCompInfoStr.ResetRequired = 0;	// Clear the reset flag
					focuserPtr->tempCompInfoStr.NextTCStepTime = TickGet();
					SetFocSpeedLOW();	
					TEMPCOMPSTATE = SM_CALC_DELAY;
				}
			}
			else 
				RESET_CNTR = 0;
			break;
			
		case SM_CALC_DELAY:
		{
			// Here we set tempCompInfoStr.NextTCStepTime for the delay state
			// The delay time is based on the xx_HighSpeedTempComp and xx_LowSpeedTempComp values
			// which are declared in FocuserProfiles.h.
			// The temp comp speeds are in units of steps per second * 100. For example a value of
			// 50 would be equivalent to a speed of 50/100 or .5 steps per second
			
			DWORD delay = 0;
			// Use HighSpeed delay time if delta steps is greater than 100, else use LowSpeed delay time
			int deltaSt = calculateDeltaSteps(focuserPtr);
		
			if( deltaSt < 100)
				delay = (DWORD)LOW_SPEED_TEMP_COMP_FOCUSER;
			else delay = (DWORD)HIGH_SPEED_TEMP_COMP_FOCUSER; 
			delay = delay * TICKS_PER_SECOND;
			delay = delay / 100;
			focuserPtr->tempCompInfoStr.NextTCStepTime += delay;
			//focuserPtr->tempCompInfoStr.NextTCStepTime /= 100;
			TEMPCOMPSTATE = SM_DELAY;
			break;
		}
		case SM_DELAY:
			// Now we simply wait for the proper delay time
			{
			DWORD now = TickGet();
			if(now > focuserPtr->tempCompInfoStr.NextTCStepTime)
			{
				// It is time to request the step
				int deltaSt = 0;
				
				deltaSt = calculateDeltaSteps(focuserPtr);
				if(deltaSt > 0) 
				{
					SetFocCurrentHIGH();
					if(focuserPtr->statusStr.CurrentPosition != focuserPtr->motionInfoStr.MaxPosition)
						focuserPtr->statusStr.TargetPosition++;
				}
				else if (deltaSt < 0)
				{
					SetFocCurrentHIGH();
					if(focuserPtr->statusStr.CurrentPosition != 0)
						focuserPtr->statusStr.TargetPosition--;		
				}	
				else TEMPCOMPSTATE = SM_CALC_DELAY;	
				TEMPCOMPSTATE = SM_STEP;
			}	
			}
			break;
			
		case SM_STEP:
			// Here we have already requested the step and we are waiting for it to complete so that we can set the current back to low
			if(focuserPtr->statusStr.TargetPosition == focuserPtr->statusStr.CurrentPosition)
			{
				SetFocCurrentLOW();
				TEMPCOMPSTATE = SM_CALC_DELAY;	// go back to calculate the next step.
				focuserPtr->tempCompInfoStr.NextTCStepTime = TickGet();
			}	
			break;
		
		/*
		case SM_COMPENSATE:
			{
				SHORT currentTemp;	
				SHORT deltaTemp;	 
				LONG deltaSteps; // 32-bit signed datatype, +/- 4 million
				WORD calculatedPos;
				SHORT index;
				// Make sure the device is homed
				if(!focuserPtr->statusStr.IsHomed)
					return;
				currentTemp = focuserPtr->statusStr.CurrentTemp;
				index = (int)(focuserPtr->tempCompInfoStr.TempCompMode - 'A');
				deltaTemp = currentTemp - focuserPtr->tempCompInfoStr.LastTempCompStartTemp;
				deltaSteps = (deltaTemp * focuserPtr->tempCompInfoStr.TempCoeffs[index]) / 10 ;
				calculatedPos = focuserPtr->tempCompInfoStr.LastTempCompStartPos + deltaSteps;
				// Validate the new calculated position
				if(calculatedPos > focuserPtr->motionInfoStr.MaxPosition)
					calculatedPos = focuserPtr->motionInfoStr.MaxPosition;
				// Set the new target position
				focuserPtr->statusStr.TargetPosition = calculatedPos;
			}	
			break;
		*/
	}		
}	

STATIC int calculateDeltaSteps(focuser * focuserPtr)
{
	SHORT currentTemp;	
	SHORT deltaTemp;	 
	LONG deltaSteps; // 32-bit signed datatype, +/- 4 million
	WORD calculatedPos;
	SHORT index;
	int diff;

	currentTemp = focuserPtr->statusStr.CurrentTemp;
	index = (int)(focuserPtr->tempCompInfoStr.TempCompMode - 'A');
	deltaTemp = currentTemp - focuserPtr->tempCompInfoStr.LastTempCompStartTemp;
	deltaSteps = (deltaTemp * focuserPtr->tempCompInfoStr.TempCoeffs[index]) / 10 ;
	calculatedPos = focuserPtr->tempCompInfoStr.LastTempCompStartPos + deltaSteps;
	// Validate the new calculated position
	if(calculatedPos > focuserPtr->motionInfoStr.MaxPosition) 
		calculatedPos = focuserPtr->motionInfoStr.MaxPosition;
	diff = (int)(calculatedPos - focuserPtr->statusStr.CurrentPosition);
	return diff;
}	
