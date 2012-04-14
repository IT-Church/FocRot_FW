// Rotator.c
// Functions for high level rotator control

#include "Rotator.h"
#include "RotatorMotion.h"

void DoRotatorOperations()
{
	HomingStateMachine();
	MovingStateMachine();
	MagnetMonitorStateMachine();	
}

