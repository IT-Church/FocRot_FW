// Stepper.h
// Header file for Stepper.c

#ifndef STEPPER_H
#define STEPPER_H

#include "HardwareProfile.h"
#include "FocuserProfiles.h"
#include "GenericTypeDefs.h"
#include "FocusingRotator.h"

// ***** DEFINE STATEMENTS
#ifndef _NOPSV
	#define _NOPSV  __attribute__((no_auto_psv)) 	// This is to get rid of compiler warnings on iterrupt service routines
#endif

#define SetMotor1PosA() 	M1P1 = 1; M1P2 = 1
#define SetMotor1PosB() 	M1P1 = 0; M1P2 = 1 
#define SetMotor1PosC() 	M1P1 = 0; M1P2 = 0
#define SetMotor1PosD() 	M1P1 = 1; M1P2 = 0

#define SetMotor2PosA() 	M2P1 = 1; M2P2 = 1
#define SetMotor2PosB() 	M2P1 = 0; M2P2 = 1
#define SetMotor2PosC() 	M2P1 = 0; M2P2 = 0
#define SetMotor2PosD() 	M2P1 = 1; M2P2 = 0

#define SetFocSpeedHIGH()				SetStepperSpeedPPS(1, HIGH_SPEED_FOCUSER)
#define SetFocSpeedLOW()				SetStepperSpeedPPS(1, LOW_SPEED_FOCUSER)
#define SetRotSpeedHIGH()				SetStepperSpeedPPS(0, HIGH_SPEED_ROTATOR)
#define SetRotSpeedLOW()				SetStepperSpeedPPS(0, LOW_SPEED_ROTATOR)
#define SetSpeedTEMPCOMP_HIGH()			SetStepperSpeedPPS(1, HIGH_SPEED_TEMP_COMP_FOCUSER)
#define SetSpeedTEMPCOMP_LOW()			SetStepperSpeedPPS(1, LOW_SPEED_TEMP_COMP_FOCUSER)

#define SetFocCurrentHIGH()				SetStepperCurrent(1, MOTOR_CURRENT_HIGH_FOCUSER)
#define SetFocCurrentLOW()				SetStepperCurrent(1, MOTOR_CURRENT_LOW_FOCUSER)
#define SetRotCurrentHIGH()				SetStepperCurrent(0, MOTOR_CURRENT_HIGH_ROTATOR)
#define SetRotCurrentLOW()				SetStepperCurrent(0, MOTOR_CURRENT_LOW_ROTATOR)

// ***** PUBLIC FUNCTION DECLARATIONS *****
void InitSteppers(void);
void SetStepperSpeedPPS(char foc, unsigned int speed);
void SetStepperCurrent(char foc, unsigned int pwr_mA);
void FreezeStepper(char foc);
void UnfreezeStepper(char foc);
#endif
