// TempComp.h
// Header file for TempComp.c

#ifndef TEMPCOMP_H
#define TEMPCOMP_H

#include "FocusingRotator.h"
#include "Stepper.h"
#include "NVM.h"

void InitTempComp(focuser * p_focuser);
void DoTempComp(focuser * focuserPtr);

#endif
