// FocuserProfiles.h
// Profile information for the different focuser option types

#ifndef FOCUSERPROFILES_H
#define FOCUSERPROFILES_H

#include "FocusingRotator.h"

// IMPORTANT: The temperature compensation speeds are multiplied by 100. For example, if xx_HighSpeedTempComp is
// set to 200 the focuser will move at 2 steps per second while in high speed temp comp mode. This allows speeds
// slower than 1 step per second while temperature compensating.

// ****************************************************************************************************************
// INSTRUCTIONS FOR ADDING DEVICE TYPES: 
// 1) Add the device specific settings in this file. Optec devices should use designators A through I.
// 2) Add the device to the switch statement in the InitFocuser() function in Focuser.c
// ****************************************************************************************************************

#define MAX_POS_FOCUSER_A				76800ul
#define MAX_POS_FOCUSER_B				250000ul
#define STEPS_PER_REV_ROT				432000ul
#define MAX_POS_ROTATOR					(STEPS_PER_REV_ROT - 1)


#define HIGH_SPEED_FOCUSER				800
#define LOW_SPEED_FOCUSER				400	
#define HIGH_SPEED_ROTATOR				800
#define LOW_SPEED_ROTATOR				400
#define HIGH_SPEED_TEMP_COMP_FOCUSER	800	
#define LOW_SPEED_TEMP_COMP_FOCUSER		400
#define MOTOR_CURRENT_HIGH_FOCUSER		350	   // Max safe for this focuser is 350. I set it lower to keep it cool.
#define MOTOR_CURRENT_LOW_FOCUSER		0
#define MOTOR_CURRENT_HIGH_ROTATOR		350	   // Max safe for this focuser is 350. I set it lower to keep it cool.
#define MOTOR_CURRENT_LOW_ROTATOR		0

#endif

