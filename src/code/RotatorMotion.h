// RotatorMotion.h
//

#ifndef ROTATOR_MOTION_H
#define ROTATOR_MOTION_H

#include "FocuserProfiles.h"

void HomingStateMachine();
void MovingStateMachine();
void MagnetMonitorStateMachine();

#define ON					0
#define OFF					1

#endif

