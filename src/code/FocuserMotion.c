// Motion.c
// This file contains the main motion state machine and functios to start and end moves.

#include "FocusingRotator.h"
#include "HardwareProfile.h"
#include "Stepper.h"
#include "TCPIP Stack/Tick.h"
#include "NVM.h"


#define isHomedFlag					MyFocuser1.statusStr.IsHomed
#define isHomingFlag				MyFocuser1.statusStr.IsHoming
#define isMovingFlag				MyFocuser1.statusStr.IsMoving	
#define TARGET_POS					MyFocuser1.statusStr.TargetPosition
#define CURRENT_POS					MyFocuser1.statusStr.CurrentPosition

#define HOME_SWITCH					HomeSwitch1Input
#define ON							0
#define OFF							1

#define motionRequest_NONE			0
#define motionRequest_HOME			1
#define motionRequest_MOVE_ABS		2
#define motionRequest_HALT			3
#define motionRequest_DIN_Input		4
#define motionRequest_REL_MOVE_IN	5
#define motionRequest_REL_MOVE_OUT	6

#define motionState_RESET					0
#define motionState_START_HOME		  		1
#define motionState_MOVING_OFF_HOME_SW 		2
#define motionState_MOVING_BEYOND_HOME_SW	3
#define motionState_MOVING_TO_HOME_SW		4
#define motionState_MOVING_TO_BOTTOM_OUT	5
#define motionState_MOVING_PRE_BLC			7
#define motionState_MOVING_POST_BLC			8
#define motionState_DIN_BTN_IN_PRESS		9
#define motionState_DIN_BTN_OUT_PRESS		10
#define motionState_DIN_BTN_HELD_SLOW		11
#define motionState_DIN_BTN_HELD_FAST		12
#define motionState_REL_MOVE_IN_SLOW		13
#define motionState_REL_MOVE_IN_FAST		14
#define motionState_REL_MOVE_OUT_SLOW		15
#define motionState_REL_MOVE_OUT_FAST		16

//#define REL_MOVE_TIMEOUT 			(TICKS_PER_SECOND/10)

// LOCAL VARIABLES

// FUNCTION PROTOTYPES
void finalizeMove();
void DoFinalHomeMove();

void FocHomeFailed();

char motionState = 0;
char motionRequest = 0;
    
void FocuserMotionStateMachine()
{
   
	
	switch(motionState)
	{	
		case motionState_RESET:
		{
			if( motionRequest == motionRequest_NONE) 
			{
				break;
			}	
			else if (motionRequest == motionRequest_HALT)
			{
				// Stop the move first.
				TARGET_POS = CURRENT_POS;
				//Cut the motor power
				SetFocCurrentLOW();
				// If it was homing, clear the homing flag.
				isHomingFlag = 0; isMovingFlag = 0;
				// Turn off temp comp...
				MyFocuser1.tempCompInfoStr.TempCompOn = 0;
				// Clear the requset we don't get stuck halting forever!
				motionRequest = motionRequest_NONE;
			}
			else if (motionRequest == motionRequest_REL_MOVE_OUT)
			{
				SetFocCurrentHIGH();
				SetFocSpeedLOW();
				TARGET_POS = MyFocuser1.motionInfoStr.MaxPosition;
				motionState = motionState_REL_MOVE_OUT_SLOW;
				motionRequest = motionRequest_NONE;
				MyFocuser1.motionInfoStr.RelMoveStartTime = TickGet();
			}
			else if (motionRequest == motionRequest_REL_MOVE_IN)
			{
				SetFocCurrentHIGH();
				SetFocSpeedLOW();
				TARGET_POS = 0;
				motionState = motionState_REL_MOVE_IN_SLOW;
				motionRequest = motionRequest_NONE;
				MyFocuser1.motionInfoStr.RelMoveStartTime = TickGet();
			}			
			else if (motionRequest == motionRequest_HOME)
			{
				motionState = motionState_START_HOME;
			}	
			else if (motionRequest == motionRequest_MOVE_ABS)
			{
				// Set the motor speed and power
				SetFocCurrentHIGH();
				SetFocSpeedHIGH();
				if(MyFocuser1.configStr.BacklashCompOn == 0 ||
				 	MyFocuser1.configStr.BacklashCompSteps == 0 ||
				 	MyFocuser1.motionInfoStr.ActualTargetPos == MyFocuser1.motionInfoStr.MaxPosition ||
				 	MyFocuser1.motionInfoStr.ActualTargetPos <= CURRENT_POS )
				{
					// No backlash compensation necessary/possible
					TARGET_POS = MyFocuser1.motionInfoStr.ActualTargetPos;
					// Skip the Pre Backlash Comp step and go to the post backlash comp state.
					motionState = motionState_MOVING_POST_BLC;
				}		
				else
				{
					long i = (long)MyFocuser1.motionInfoStr.ActualTargetPos + (long)MyFocuser1.configStr.BacklashCompSteps;
					if(i > MyFocuser1.motionInfoStr.MaxPosition)
					{
						MyFocuser1.motionInfoStr.BlcTargetPos = MyFocuser1.motionInfoStr.MaxPosition;
					}	
					else
					{
						MyFocuser1.motionInfoStr.BlcTargetPos = MyFocuser1.motionInfoStr.ActualTargetPos + 
						MyFocuser1.configStr.BacklashCompSteps;
					}
					TARGET_POS = MyFocuser1.motionInfoStr.BlcTargetPos;
					// To to the first backlash compensation state
					motionState = motionState_MOVING_PRE_BLC;
				}				
			}	
			else if (motionRequest == motionRequest_DIN_Input)
			{
				if(isHomingFlag) 
					motionRequest = motionRequest_NONE;
				else
				{
					if(MyFocuser1.motionInfoStr.ActualTargetPos == 0)
					{
						// Move the focuser one step IN if possible
						if(CURRENT_POS > 0)
						{
							// Set the is moving flag
							isMovingFlag = 1;
							// Set the motor power and speed to high.
							SetFocCurrentHIGH();
							SetFocSpeedHIGH();
							TARGET_POS--;
							motionState = motionState_DIN_BTN_IN_PRESS;	
							MyFocuser1.inputDeviceStr.PressStartTime = TickGet();
						}
						else
						{
							isMovingFlag = 0;
							SetFocSpeedLOW();
							motionState = motionState_RESET;	
						}			
					}	
					else 
					{
						// Move the focuser one step OUT if possible
						if(CURRENT_POS < MyFocuser1.motionInfoStr.MaxPosition)
						{
							// Set the is moving flag
							isMovingFlag = 1;
							// Set the motor power and speed to high.
							SetFocCurrentHIGH();
							SetFocSpeedHIGH();
							TARGET_POS++;
							motionState = motionState_DIN_BTN_OUT_PRESS;
							MyFocuser1.inputDeviceStr.PressStartTime = TickGet();	
						}
						else
						{
							isMovingFlag = 0;
							SetFocSpeedLOW();
							motionState = motionState_RESET;	
						}
					}	
				}	
			}		
			else return;	
			break;
		}	
			
		case motionState_START_HOME:
		{
			/*
			// First check that the appropriate conditions are present to start 
			// a home procedure
			if(MyFocuser1.statusStr.FocuserDetected == 0)
			{
				// abort the home
				motionRequest = motionRequest_NONE;
				motionState = motionState_RESET;
				break;
			}
			*/	
			
			// We are clear to begin homing
			// Set the homing flags
			isHomingFlag = 1;
			isHomedFlag = 0;
			isMovingFlag = 1;
			// Clear the request so that we don't start homing again
			motionRequest = motionRequest_NONE;
			// Set Motor Current High for Homing
			SetFocCurrentHIGH();
			// Set Motor Speed for Home
			SetFocSpeedHIGH();

			if(HOME_SWITCH == ON)
			{
				CURRENT_POS = 0;
				TARGET_POS = 1000;	// Only allow the focuser to move 1000
				motionState = motionState_MOVING_OFF_HOME_SW;	// steps to get off the switch.
			}	
			else
			{
				CURRENT_POS = MyFocuser1.motionInfoStr.MaxPosition;
				TARGET_POS = 0;
				motionState = motionState_MOVING_TO_HOME_SW;
			}
			break;			
		}			
			
		case motionState_MOVING_OFF_HOME_SW:
		{
			if(HOME_SWITCH == OFF)
			{
				// Move 100 steps off of the home switch
				CURRENT_POS = 0;
				TARGET_POS = 1000;	
				motionState = motionState_MOVING_BEYOND_HOME_SW;
			}
			else if (CURRENT_POS == TARGET_POS)
			{
				FocHomeFailed();				// This means the 
			}		
			break;
		}	
			
		case motionState_MOVING_BEYOND_HOME_SW:
		{
			// The last case sent the focuser to 1000 steps past the switch. Now send it back to the switch.
			if(CURRENT_POS == TARGET_POS)
			{
				CURRENT_POS = 1200;
				TARGET_POS = 0;
				motionState = motionState_MOVING_TO_HOME_SW;
			}	
			break;
		}	
			
		case motionState_MOVING_TO_HOME_SW:
		{
			if(HOME_SWITCH == ON)
			{ // It has reached the Home Switch
				// Set current position to 0 or Home
				CURRENT_POS = 0;
				// Request Final Homing Move
				DoFinalHomeMove();
			}
			else if(CURRENT_POS == 0)
			{
				FocHomeFailed();
			}
			break;
		}	
			
			
		
		case motionState_MOVING_PRE_BLC:
		{
			if( CURRENT_POS == TARGET_POS)
			{
				// we have reached the turn around point
				TARGET_POS = MyFocuser1.motionInfoStr.ActualTargetPos;
				motionState = motionState_MOVING_POST_BLC;
			}	
			break;	
		}
		case motionState_MOVING_POST_BLC:
		{
			if( CURRENT_POS == TARGET_POS)
			{
				finalizeMove();
			}	
			break;	
		}
	
		case motionState_REL_MOVE_IN_SLOW:
			{
				// Determine if it is time to go fast...
				DWORD time = TickGet() - MyFocuser1.motionInfoStr.RelMoveStartTime;
				if(time > (TICKS_PER_SECOND * 3))
				{
					SetFocSpeedHIGH();						// Set the speed HIGH
					motionState = motionState_REL_MOVE_IN_FAST;		// go to the fast state
				}
				break;			
			}	
			
		case motionState_REL_MOVE_IN_FAST:
			{
				// Check if the target position has been reached
				if(CURRENT_POS == TARGET_POS)
				{
					// Move is finished
					finalizeMove();
					return;
				}
				break;	
			}	
			
		case motionState_REL_MOVE_OUT_SLOW:
			{
				// Determine if it is time to go fast...
				DWORD time = TickGet() - MyFocuser1.motionInfoStr.RelMoveStartTime;
				if(time > (TICKS_PER_SECOND * 3))
				{
					SetFocSpeedHIGH();						// Set the speed HIGH
					motionState = motionState_REL_MOVE_OUT_FAST;		// go to the fast state
				}	
				break;	
			}	
			
		case motionState_REL_MOVE_OUT_FAST:
			{				
				// Check if the target position has been reached
				if(CURRENT_POS == TARGET_POS)
				{
					// Move is finished
					finalizeMove();
					return;
				}	
				break;	
			}			
	}				
} 


void finalizeMove()
{
	// Set the motor current to LOW
	SetFocCurrentLOW();
	// clear the isMoving flag
	isMovingFlag = 0;
	// clear the isHoming flag
	isHomingFlag = 0;
	// clear the motion request
	motionRequest = motionRequest_NONE;
	// set the motion state back to reset
	motionState = motionState_RESET;
	// save the new "lastPosition" to EEPROM
	SaveCurrentPositionFoc(&MyFocuser1);
}	

void abortHome()
{
	// Stop the move
	TARGET_POS = CURRENT_POS;
	// Set current and speed low
	SetFocCurrentLOW();
	SetFocSpeedLOW();
	// Set flags
	isMovingFlag = 0;
	isHomingFlag = 0;
	isHomedFlag = 0;
	// clear the motion request
	motionRequest = motionRequest_NONE;
	// Set state
	motionState = motionState_RESET;
}	

void RequestHaltFoc()
{
	// Set the request to halt for the state machine.
	motionRequest = motionRequest_HALT;
	motionState = motionState_RESET;
}
/*	
void RequestDIN_InputStartMoveIN(focuser * focuserPtr)
{
	// Reset temp comp if it's enabled
	MyFocuser1.tempCompInfoStr.ResetRequired = 1;
	// Set the target pos
	MyFocuser1.motionInfoStr.ActualTargetPos = 0;
	// Start the move
	motionRequest = motionRequest_DIN_Input;
	motionState = motionState_RESET;
}

void RequestDIN_InputStartMoveOUT(focuser * focuserPtr)
{
	// Reset temp comp if it's enabled
	focuserPtr->tempCompInfoStr.ResetRequired = 1;	
	// Set the target pos
	focuserPtr->motionInfoStr.ActualTargetPos = focuserPtr->motionInfoStr.MaxPosition;
	// Start the move
	motionRequest = motionRequest_DIN_Input;
	motionState = motionState_RESET;
}		

*/
void RequestAbsoluteMoveFoc(WORD newPos)
{
	// The program should have already verified that the device is homed and that the position is within the 
	// appropriate bounds.
	
	// Reset temp comp if it's enabled
	MyFocuser1.tempCompInfoStr.ResetRequired = 1;
	// Set the target position
	MyFocuser1.motionInfoStr.ActualTargetPos = newPos;
	// Start the move
	motionRequest = motionRequest_MOVE_ABS;
	motionState = motionState_RESET;
}	

void RequestHomeStartFoc()
{

	if(MyFocuser1.statusStr.IsHoming) 
		return;
	else
	{
		// Reset temp comp if it's enabled
		MyFocuser1.tempCompInfoStr.ResetRequired = 1;
		motionRequest = motionRequest_HOME;
		motionState = motionState_RESET;
	}		
}	

void StartRelativeMoveFoc(char in)
{
	// Reset temp comp if it's enabled
	MyFocuser1.tempCompInfoStr.ResetRequired = 1;
	
	if(in)	// Request to (continue)move IN
	{
		// Check to see if the direction has changed
		if(motionState == motionState_REL_MOVE_OUT_SLOW || motionState == motionState_REL_MOVE_OUT_FAST)
		{
			// DIRECTION CHANGED... So reset the state machine to the beginning so the move starts properly.
			motionRequest = motionRequest_REL_MOVE_IN;
			motionState = motionState_RESET;
		}
		else	
		{
			// Direction is the same just update the last ping time
			// the motion request and motion state values can remain the same
			motionRequest = motionRequest_REL_MOVE_IN;
	//		focuserPtr->motionInfoStr.RelMoveLastPing = TickGet();
		}	
	}
	else	// Request to (continue) move OUT
	{
		// Check to see if the direction has changed
		if(motionState == motionState_REL_MOVE_IN_SLOW || motionState == motionState_REL_MOVE_IN_FAST)
		{
			// DIRECTION CHANGED... So reset the state machine to the beginning so the move starts properly.
			motionRequest = motionRequest_REL_MOVE_OUT;
			motionState = motionState_RESET;
		}	
		else
		{
			// Direction is the same just update the last ping time
			// the motion request and motion state values can remain the same
			motionRequest = motionRequest_REL_MOVE_OUT;
		//	focuserPtr->motionInfoStr.RelMoveLastPing = TickGet();
		}	
	}
	return;	
}	



void EndRelativeMoveFoc ()
{
	TARGET_POS = CURRENT_POS;
	finalizeMove();
}	
void DoFinalHomeMove() 
{

	if(MyFocuser1.configStr.TempCompAtStart == 0 || MyFocuser1.statusStr.TempProbeAttached != 1 )
	{
		MyFocuser1.statusStr.IsHomed = 1;
		MyFocuser1.statusStr.IsHoming = 0;
		RequestAbsoluteMoveFoc(MyFocuser1.statusStr.LastSavedPosition);
	}	
	else if(MyFocuser1.motionInfoStr.TempCompAtStartComplete == 0)
	{
		// Determine what position we need to move to
		SHORT currentTemp = MyFocuser1.statusStr.CurrentTemp;
		SHORT index = (int)(MyFocuser1.tempCompInfoStr.TempCompMode - 'A');
		SHORT deltaTemp = currentTemp - MyFocuser1.tempCompInfoStr.LastTempCompStartTemp;
		LONG deltaSteps = (deltaTemp * MyFocuser1.tempCompInfoStr.TempCoeffs[index]) / 10;
		WORD calculatedPos;
		// Make sure the calculated pos is going to be positive and less than the maxPos
		if((deltaSteps < 0) && ((0-deltaSteps) > MyFocuser1.tempCompInfoStr.LastTempCompStartPos))
		{
			// calculated pos will be less than zero
			calculatedPos = 0;
		}	
		else if((deltaSteps + MyFocuser1.tempCompInfoStr.LastTempCompStartPos) > MyFocuser1.motionInfoStr.MaxPosition)
		{
			calculatedPos = MyFocuser1.motionInfoStr.MaxPosition;
		}
		else	
			calculatedPos = MyFocuser1.tempCompInfoStr.LastTempCompStartPos + deltaSteps;
			
		// Request an Absolute Move to the calculated position
		MyFocuser1.statusStr.IsHomed = 1;
		MyFocuser1.statusStr.IsHoming = 0;
		MyFocuser1.statusStr.IsMoving = 0;
		RequestAbsoluteMoveFoc(calculatedPos);
	}
	else
	{	
		// The temp comp is already done. No need to do it again.
		MyFocuser1.statusStr.IsHomed = 1;
		MyFocuser1.statusStr.IsHoming = 0;
		MyFocuser1.statusStr.IsMoving = 0;
		RequestAbsoluteMoveFoc(MyFocuser1.statusStr.LastSavedPosition);
	}
	
	// Set this flag so that it's true from now on.
	MyFocuser1.motionInfoStr.TempCompAtStartComplete = 1;
}	

void FocHomeFailed()
{
	// Stop any motion
	CURRENT_POS = TARGET_POS;
	// Turn the motor current down(off)
	SetFocCurrentLOW();
	// Turn the speed down
	SetFocSpeedLOW();
	// Set the flags
	isMovingFlag = 0;
	isHomingFlag = 0;
	isHomedFlag = 0;
	// Set the motion state
	motionState = motionState_RESET;
	
}	
