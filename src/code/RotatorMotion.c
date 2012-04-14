// RotatorMotion.c
//

#include "RotatorMotion.h"
#include "FocusingRotator.h"
#include "Stepper.h"
#include "NVM.h"

#define DEVICE_IS_HOMED		MyRotator1.statusStr.IsHomed
#define DEVICE_IS_HOMING 	MyRotator1.statusStr.IsHoming
#define DEVICE_IS_MOVING	MyRotator1.statusStr.IsMoving
#define STEPS_PER_REV		STEPS_PER_REV_ROT
#define STEPS_PER_HALF		(STEPS_PER_REV / 2)
#define CURRENT_POS			MyRotator1.statusStr.CurrentPosition
#define TARGET_POS			MyRotator1.statusStr.TargetPosition
#define REVERSE 			MyRotator1.configStr.Reverse
#define MOVE_DIRECTION		MyRotator1.statusStr.MoveDirection
#define BLC_DIRECTION		CCW
#define HOME_SWITCH			HomeSwitch2Input


// Local function prototypes
void HomeFailed();
void HomeCompleted();
void FinalizeMove();
void StartHomeMove(char direction);
char GetShortestMoveDirection(DWORD target);


// Enums
enum _HomingStates{
	HOME_IDLE,
	START_HOME,
	MOVING_TO_SW,
	MOVING_OFF_SW,
	MOVING_BEYOND_SW,
	MOVING_TO_SW_FINAL
} HOMING_STATE;

enum _MovingStates{
	MOVE_IDLE,
	START_MOVE,
	MOVING_TO_BLC_TARGET,
	MOVING_TO_FINAL_TARGET
} MOVING_STATE;

	

// Local variables	

DWORD absMoveTargetPos = 0;


//-----------------------------------------------------------------------------
// HomingStateMachine()
//-----------------------------------------------------------------------------
// This performs the home operation
void HomingStateMachine()
{
	switch (HOMING_STATE)
	{
		case HOME_IDLE:
			break;
		case START_HOME:
		{
			DEVICE_IS_HOMED = FALSE;
			DEVICE_IS_HOMING = TRUE;
			SetRotCurrentHIGH();
			SetRotSpeedHIGH();
			if(HOME_SWITCH == OFF)
			{
				if(MyRotator1.motionInfoStr.LastMagEnterDir == MyRotator1.motionInfoStr.LastMagExitDir)
				{
					// This means the device was shut off over the home switch 
					// but turned on off the home switch. This can happen because
					// of the switchs hysterisis.
					if(MyRotator1.motionInfoStr.LastMagEnterDir == CW) 
						StartHomeMove(CCW);
					else 
						StartHomeMove(CW);
					HOMING_STATE = MOVING_TO_SW;
				}
				else
				{
					StartHomeMove(CCW);
					HOMING_STATE = MOVING_TO_SW_FINAL;
				}		
			}
			else	// The home switch is on 
			{
				if(MyRotator1.motionInfoStr.LastMagEnterDir == CW) 
					StartHomeMove(CCW);
				else 
					StartHomeMove(CW);
				HOMING_STATE = MOVING_OFF_SW;
			}		
					
			break;
		}	
		case MOVING_TO_SW:
			if(HOME_SWITCH == ON)
				HOMING_STATE = MOVING_OFF_SW;
			else if(CURRENT_POS == TARGET_POS)
				HomeFailed();
			break;
		case MOVING_OFF_SW:
			if(HOME_SWITCH == OFF)
			{
				if(CURRENT_POS < TARGET_POS)
					CURRENT_POS = (TARGET_POS - 1000);
				else 
					CURRENT_POS = (TARGET_POS + 1000);
				HOMING_STATE = MOVING_BEYOND_SW;
			}	
			else if(CURRENT_POS == TARGET_POS)
				HomeFailed();
			break;
		case MOVING_BEYOND_SW:
			if(CURRENT_POS == TARGET_POS)
			{
				StartHomeMove(CCW);
				HOMING_STATE = MOVING_TO_SW_FINAL;
			}	
			break;
		case MOVING_TO_SW_FINAL:
			if(HOME_SWITCH == ON)
			{
				FreezeStepper(0);
				CURRENT_POS = STEPS_PER_HALF;
				TARGET_POS = STEPS_PER_HALF;
				UnfreezeStepper(0);
				HomeCompleted();
			}	
			else if(CURRENT_POS == TARGET_POS)
				HomeFailed();
			break;
	}	
}

void RequestHomeStartRot()
{
	// Make sure the device is not already homing
	if(HOMING_STATE != HOME_IDLE) return;
	// Start the home
	HOMING_STATE = START_HOME;
}
void RequestHaltRot()
{
	// Halt the rotator motion;
	FreezeStepper(0);
	DEVICE_IS_MOVING = FALSE;
	DEVICE_IS_HOMING = FALSE;
	SetRotSpeedLOW();
	SetRotCurrentLOW();
	TARGET_POS = CURRENT_POS;
	SaveCurrentPositionRot(&MyRotator1);
	MOVING_STATE = MOVE_IDLE;
	UnfreezeStepper(0);
}	
void StartRelativeMoveRot(char dir)
{
	MOVE_DIRECTION == dir;
	DWORD newPos = 0;
	if(REVERSE)
	{
		if(dir == CCW)
			newPos = (CURRENT_POS + 1);
		else newPos = (CURRENT_POS - 1);	
	}
	else
	{
		if(dir == CCW)
			newPos = (CURRENT_POS - 1);
		else newPos = (CURRENT_POS + 1);	
	}	
	RequestAbsoluteMoveRot(newPos);	
}	
	
void EndRelativeMoveRot()
{
	FreezeStepper(0);
	TARGET_POS == CURRENT_POS;
	FinalizeMove();
	UnfreezeStepper(0);
}	

void HomeFailed()
{
	DEVICE_IS_HOMED = FALSE;
	DEVICE_IS_HOMING = FALSE;
	DEVICE_IS_MOVING = FALSE;
	SetRotSpeedLOW();
	SetRotCurrentLOW();
	HOMING_STATE = HOME_IDLE;
}	
void HomeCompleted()
{
	DEVICE_IS_HOMED = TRUE;
	DEVICE_IS_HOMING = FALSE;
	DEVICE_IS_MOVING = FALSE;
	SetRotSpeedLOW();
	SetRotCurrentLOW();
	// Move to the last remembered position.
	HOMING_STATE = HOME_IDLE;
	RequestAbsoluteMoveRot(MyRotator1.statusStr.LastSavedPosition);
}	

void MovingStateMachine()
{
	switch(MOVING_STATE)
	{
		case MOVE_IDLE:
			break;
			
		case START_MOVE:
			FreezeStepper(0);
			SetRotCurrentHIGH();	
			SetRotSpeedHIGH();
			if(MyRotator1.configStr.BacklashCompOn)
			{				
				if(GetShortestMoveDirection(absMoveTargetPos) == BLC_DIRECTION)
				{
					// Do a BLC move
					DWORD backlashTargetPos = absMoveTargetPos + MyRotator1.configStr.BacklashCompSteps;
					MOVE_DIRECTION = BLC_DIRECTION;
					TARGET_POS = (backlashTargetPos % MAX_POS_ROTATOR);
					MOVING_STATE = MOVING_TO_BLC_TARGET;
				}
				else
				{
					// Do not do a BLC move
					MOVE_DIRECTION = (BLC_DIRECTION == CW) ? CCW : CW;
					TARGET_POS = absMoveTargetPos;
					MOVING_STATE = MOVING_TO_FINAL_TARGET;
				}		
			}
			else
			{	// BLC is disabled
				MOVE_DIRECTION = GetShortestMoveDirection(absMoveTargetPos);
				TARGET_POS = absMoveTargetPos;
				MOVING_STATE = MOVING_TO_FINAL_TARGET;
			}
			DEVICE_IS_MOVING = 1;
			UnfreezeStepper(0);	
			break;
			
		case MOVING_TO_BLC_TARGET:
			if(CURRENT_POS == TARGET_POS)
			{
				// Reverse the move direction
				MOVE_DIRECTION = (MOVE_DIRECTION == CW) ? CCW : CW;
				TARGET_POS = absMoveTargetPos;
				MOVING_STATE = MOVING_TO_FINAL_TARGET;
			}	
			break;
			
		case MOVING_TO_FINAL_TARGET:
			if(CURRENT_POS == TARGET_POS)
			{
				// The move is complete
				FinalizeMove();
			}	
			break;
	}	
}
void FinalizeMove()
{
	DEVICE_IS_MOVING = FALSE;
	SetRotSpeedLOW();
	SetRotCurrentLOW();
	SaveCurrentPositionRot(&MyRotator1);
	MOVING_STATE = MOVE_IDLE;
}	
void RequestAbsoluteMoveRot(WORD newPos)
{
	// Make sure the device is not homing
	if(HOMING_STATE != HOME_IDLE) return;
	// Make sure we are not already there
	if(newPos == CURRENT_POS) return;
	// Start the move
	absMoveTargetPos = newPos;
	MOVING_STATE = START_MOVE;	
}	

// Function: StartHomeMove(char direction)
// Desctiption: Given the direction as either CW, or CCW, this function will set
// the current position and target position such that a move of greatest possible
// travel is started. This function must take into account the current "Reverse" 
// configuration setting. This will also set the travel direction accordingly.
void StartHomeMove(char direction)
{
	FreezeStepper(0);	// Freeze the rotator stepper
	MOVE_DIRECTION = direction;	// Tell the ISR to move in the correct direction.
	if(REVERSE)
	{
		if(direction == CCW)
		{
			CURRENT_POS = MAX_POS_ROTATOR;
			TARGET_POS = 0;
		}	
		else
		{
			CURRENT_POS = 0;
			TARGET_POS = MAX_POS_ROTATOR;
		}	
	}	
	else
	{
		if(direction == CCW)
		{
			CURRENT_POS = 0;
			TARGET_POS = MAX_POS_ROTATOR;
		}	
		else
		{
			CURRENT_POS = MAX_POS_ROTATOR;
			TARGET_POS = 0;
		}
	}	
	UnfreezeStepper(0);	// Unfreeze the rotator stepper.
}	
char GetShortestMoveDirection(DWORD target){
	char dir = 0;
	if(CURRENT_POS > STEPS_PER_HALF)
	{
		if(target < CURRENT_POS)
		{
			if(target <= STEPS_PER_HALF)
				dir = CCW;
			else
				dir = CW;
		}
		else
			dir = CCW;	
	}
	else
	{
		if(target < CURRENT_POS)
			dir = CW;
		else
		{
			if(target <= STEPS_PER_HALF)
				dir = CCW;
			else
				dir = CW;
		}
	}
	if(MyRotator1.configStr.Reverse)
	{
		// Swap the direction.
		dir = (dir == CCW) ? CW : CCW;
	}	
	return dir;
}

void MagnetMonitorStateMachine()
{
	static char state = 0;
	
	switch (state)
	{
		case 0:
			if(HOME_SWITCH == ON)
			{
				MyRotator1.motionInfoStr.LastMagEnterDir = MOVE_DIRECTION;
				MyRotator1.motionInfoStr.LastMagExitDir = MOVE_DIRECTION;
				SaveMagnetState();
				state = 1;
			}	
			break;
			
		case 1:
			if(HOME_SWITCH == OFF)
			{
				MyRotator1.motionInfoStr.LastMagExitDir = MOVE_DIRECTION;
				state = 0;
				SaveMagnetState();
			}
			break;	
	}	
}
