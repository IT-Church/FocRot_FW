// Stepper.c
// Contains members for control stepper motors
// Note: Use of this file requires exclusive access to Timer3.

#include "Stepper.h"
#include "FocusingRotator.h"

#define FOC_TIMER_PERIOD_REG	PR4
#define ROT_TIMER_PERIOD_REG	PR5

#define FOC_POWER_TIMER_DUTY	OC1RS
#define ROT_POWER_TIMER_DUTY	OC2RS



#define MAX_CURRENT 	605
// ***** Private Variables *************************************************************/


// ***** Private Function Prototypes ***************************************************/


// ***** Functions *********************************************************************/
void InitSteppers()
{
	// The timers are initialized in main.c
	
	// Setup the Output compare module
	// The OCM's are used to produce the PWM output for the stepper reference voltage output.
	
	_OCM = 0b110;	// Set output compare module for "PWM mode without fault protection"
	_OCTSEL = 1; 	// Set output compare module to use Timer 3 as it's clock source
	
	STEP_PWR_F1_TRIS = 0;	// Set the stepper power tristate registers to output
	STEP_PWR_F2_TRIS = 0;
	
	OC2CONbits.OCM = 0b110; // Set output compare module for "PWM mode without fault protection"
	OC2CONbits.OCTSEL = 1; // Set output compare module to use Timer 3 as it's clock source
	
	// Initialize steppers with low current
	SetFocCurrentLOW();	
	SetRotCurrentLOW();
	
	// Enable the stepper motor interrupts
	_T4IE = 1;
	_T5IE = 1;
}	


void _ISR _NOPSV _T4Interrupt(void)
{
	static char StepperIndex1 = 'A';	
	
	if(MyFocuser1.statusStr.CurrentPosition == MyFocuser1.statusStr.TargetPosition)
	{
		MyFocuser1.statusStr.IsMoving = 0;
		// Do Nothing
	}	
	else if (MyFocuser1.statusStr.CurrentPosition > MyFocuser1.statusStr.TargetPosition)
	{
		switch (StepperIndex1)		// MOVE OUT
		{
			case 'A':
				SetMotor1PosB();
				StepperIndex1 = 'B';
				break;
			case 'B':
				SetMotor1PosC();
				StepperIndex1 = 'C';
				break;
			case 'C':
				SetMotor1PosD();
				StepperIndex1 = 'D';
				break;
			case 'D':
				default:
				SetMotor1PosA();
				StepperIndex1 = 'A';
				break;		
		}
		MyFocuser1.statusStr.CurrentPosition--;	
		MyFocuser1.statusStr.IsMoving = 1;
	}	
	else
	{
		switch (StepperIndex1)		// MOVE IN 
		{
			case 'A':
				SetMotor1PosD();
				StepperIndex1 = 'D';
				break;
			case 'B':
				SetMotor1PosA();
				StepperIndex1 = 'A';
				break;
			case 'C':
				SetMotor1PosB();
				StepperIndex1 = 'B';
				break;
			case 'D':
				default:
				SetMotor1PosC();
				StepperIndex1 = 'C';
				break;		
		}
		MyFocuser1.statusStr.CurrentPosition++;
		MyFocuser1.statusStr.IsMoving = 1;
	}	
	_T4IF = 0;			// Clear the Timer 4 Interrupt Flag.
}



void _ISR _NOPSV _T5Interrupt(void)
{
	// This ISR moves the rotator motor
	static char StepperIndex2 = 'A';
	if(MyRotator1.statusStr.TargetPosition == MyRotator1.statusStr.CurrentPosition)
	{
		MyRotator1.statusStr.IsMoving = 0;
		// Don't return because we need to clear the Interrupt Flag
	}	
	else if(MyRotator1.statusStr.MoveDirection == CW)	// Move Clockwise
	{
		switch(StepperIndex2)	
		{
			case 'A':
				SetMotor2PosB();
				StepperIndex2 = 'B';
				break;
			case 'B':
				SetMotor2PosC();
				StepperIndex2 = 'C';
				break;
			case 'C':
				SetMotor2PosD();
				StepperIndex2 = 'D';
				break;
			case 'D':
				default:
				SetMotor2PosA();
				StepperIndex2 = 'A';
				break;		
		}	
		if(MyRotator1.configStr.Reverse)
		{
			if(MyRotator1.statusStr.CurrentPosition < MAX_POS_ROTATOR)
				 MyRotator1.statusStr.CurrentPosition++;
			else MyRotator1.statusStr.CurrentPosition = 0;		
		}	
		else
		{
			if(MyRotator1.statusStr.CurrentPosition > 0)
				 MyRotator1.statusStr.CurrentPosition--;
			else MyRotator1.statusStr.CurrentPosition = MAX_POS_ROTATOR;	
		}	
		MyRotator1.statusStr.IsMoving = 1;
	}	
	else												// Move Counter-Clockwise
	{
		switch(StepperIndex2)
		{
			case 'A':
				SetMotor2PosD();
				StepperIndex2 = 'D';
				break;
			case 'B':
				SetMotor2PosA();
				StepperIndex2 = 'A';
				break;
			case 'C':
				SetMotor2PosB();
				StepperIndex2 = 'B';
				break;
			case 'D':
				default:
				SetMotor2PosC();
				StepperIndex2 = 'C';
				break;		
		}
		if(MyRotator1.configStr.Reverse)
		{
			if(MyRotator1.statusStr.CurrentPosition > 0)
				 MyRotator1.statusStr.CurrentPosition--;
			else MyRotator1.statusStr.CurrentPosition = MAX_POS_ROTATOR;	
		}	
		else
		{
			if(MyRotator1.statusStr.CurrentPosition < MAX_POS_ROTATOR)
				 MyRotator1.statusStr.CurrentPosition++;
			else MyRotator1.statusStr.CurrentPosition = 0;		
		}
		MyRotator1.statusStr.IsMoving = 1;
	}	
	
	_T5IF = 0;			// Clear the Timer 5 Interrupt Flag.
}	



void SetStepperSpeedPPS(char foc, unsigned int speed)
{
	unsigned int t = 65535;
	
	if(speed != 0)
	{
		UnfreezeStepper(foc);
		t = (GetPeripheralClock() / speed) >> 8;
	}
	else
	{
		// dissable the interrupt so that it doesn't slow us down!
		FreezeStepper(foc);
	}	
	
//	*focuserPtr->motionInfoStr.TimerPeriodPtr = t;
	
	if(foc)
		FOC_TIMER_PERIOD_REG = t;
	else 
		ROT_TIMER_PERIOD_REG = t;
}

void SetStepperCurrent( char foc, unsigned int pwr_mA )
{
	// Turn the stepper driver on or off
/*	if(pwr_mA != 0)
	{
		if(focuserStr.isFocuser1) STEP_PWR_F1 = 1;
		else STEP_PWR_F2 = 1;
	}	
	else
	{
		if(focuserStr.isFocuser1) STEP_PWR_F1 = 0;
		else STEP_PWR_F2 = 0;
	}	
*/
	
	// Make sure the current is not greater than MAX_CURRENT
	if(pwr_mA >= MAX_CURRENT)
	{
		pwr_mA = MAX_CURRENT;
		
		if(foc) FOC_POWER_TIMER_DUTY = 100;
		else ROT_POWER_TIMER_DUTY = 100;
		
		//return;
	}		
	else
	{
		unsigned int i = pwr_mA * 100 / MAX_CURRENT;
		if(pwr_mA)
		{
			if(foc) FOC_POWER_TIMER_DUTY = i;
			else ROT_POWER_TIMER_DUTY = i;
		}	
		else
		{
			if(foc) FOC_POWER_TIMER_DUTY = 0;
			else ROT_POWER_TIMER_DUTY = 0;
		}
	}
	unsigned int i = 0;
	
	// This delay gives the motor current current some time to rise before making the step
	for (i=0; i<500; i++)
		Nop();
}	

void FreezeStepper(char foc)
{
	// Just disable the stepper interrupt.
	if(foc != 0)
		_T4IE = 0;
	else
		_T5IE = 0;
}	

void UnfreezeStepper(char foc)
{
	// Enable the stepper interrupts
	if(foc != 0)
		_T4IE = 1;
	else
		_T5IE = 1;
}	

