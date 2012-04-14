// NVM.h
// Header file for NVM.c

#ifndef NVM_H
#define NVM_H
#include "FocusingRotator.h"
#include "Rotator.h"
#include "TCPIP Stack/TCPIP.h"

void SaveDeviceConfig( focuser focuserStr, rotator rotatorStr);
char LoadConfigFromNVM( focuser * focuserPtr, rotator * rotatorPtr);
void GetMacAddrFromNvm(APP_CONFIG * app_con);
void SaveTempCompStartPoint(focuser * focuserPtr);
void SaveCurrentPositionFoc( focuser * focuserPtr);
void SaveCurrentPositionRot( rotator * rotatorPtr);
void SaveMagnetState();
void ResetToDefaults();

#endif
