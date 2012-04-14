// DIN_Input.h
// Header file for DIN_Input.c

#ifndef DIN_INPUT_H
#define DIN_INPUT_H

#include "HardwareProfile.h"
#include "GenericTypeDefs.h"
#include "FocusingRotator.h"
#include "TCPIP Stack/Tick.h"



// DEFINE STATEMENTS
#ifndef _NOPSV
	#define _NOPSV  __attribute__((no_auto_psv)) 	// This is to get rid of compiler warnings on iterrupt service routines
#endif



// ***** GLOBAL VARIABLES **************************************************************/


// ***** PUBLIC FUNCTION DEFINITIONS ***************************************************/
void InitDIN_Input();
void ProcessDinInData(inputDevice * devPtr);


#endif

