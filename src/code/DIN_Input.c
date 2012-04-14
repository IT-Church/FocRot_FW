// DIN_Input.c
// Contians functions for reading data from inputs connected to the 
// focusers din sockets.

#include "DIN_Input.h"

// Private Variable Definitions


void InitDIN_Input()
{
	MyFocuser1.inputDeviceStr.RemoteState = NO_PRESS;
//	MyFocuser2.inputDeviceStr.RemoteState = NO_PRESS;
	
	// The timer is initialized in main.c
	
	// Configure Input Capture Module 2
	IC1CON = 0;
//	IC2CON = 0;
	
	IC1CONbits.ICTMR = 0b001;	// Set IC2 to use Timer2
	IC1CONbits.ICM = 0b001;		// Set IC2 to capture on every falling edge
	
//	IC2CONbits.ICTMR = 0b001;	// Set IC2 to use Timer2
//	IC2CONbits.ICM = 0b001;		// Set IC2 to capture on every falling edge
	
	IFS0bits.IC1IF = 0;			// Clear the interrupt flag
	IEC0bits.IC1IE = 1;			// Enable the InCap interrupts	
	_IC1IP = 6;			// Set interrupt priority
	
	
//	IFS0bits.IC2IF = 0;			// Clear the interrupt flag
//	IEC0bits.IC2IE = 1;			// Enable the InCap interrupts
//	_IC2IP = 6;			// Set interrupt priority
	

}

// Input Capture Module 1 Event Handler
void _ISR _NOPSV _IC1Interrupt(void)
{
	// Input Capture interrupt service routine

	unsigned int trash;
	static int intCnt = 0;
	
	if(IC1CONbits.ICOV)
	{
		while(IC1CONbits.ICBNE)	// Clear the buffer
				trash = IC1BUF;
		intCnt = 0;
	}
	else
	{
		if(intCnt++ == 4)
		{
			if(MyFocuser1.inputDeviceStr.ReadyForNewTimes)
			{
				if(DinInput1 == 0)
				{
					MyFocuser1.inputDeviceStr.CapturedTimes[0] = IC1BUF;
					MyFocuser1.inputDeviceStr.CapturedTimes[1] = IC1BUF;
					MyFocuser1.inputDeviceStr.CapturedTimes[2] = IC1BUF;
					trash = IC1BUF;				// Discard one value
				}
				else
				{
					trash = IC1BUF; 			// Discard one value
					MyFocuser1.inputDeviceStr.CapturedTimes[0] = IC1BUF;
					MyFocuser1.inputDeviceStr.CapturedTimes[1] = IC1BUF;
					MyFocuser1.inputDeviceStr.CapturedTimes[2] = IC1BUF;	
				}
				MyFocuser1.inputDeviceStr.NewTimesReady = 1;
				MyFocuser1.inputDeviceStr.ReadyForNewTimes = 0;
			}
			else	
			{
				// The program is not ready for new data so just discard it.
				while(IC1CONbits.ICBNE)	// Clear the buffer
					trash = IC1BUF;
			}	
			intCnt = 0;
		}	
	}				
	IFS0bits.IC1IF = 0;					// Clear the interrupt flag	
}


/*
void _ISR _NOPSV _IC2Interrupt(void)
{
	// Input Capture interrupt service routine

	unsigned int trash;
	static int intCnt = 0;
	
	if(IC2CONbits.ICOV)
	{
		while(IC2CONbits.ICBNE)	// Clear the buffer
				trash = IC2BUF;
		intCnt = 0;
	}
	else
	{
		if(intCnt++ == 4)
		{
			if(MyFocuser2.inputDeviceStr.ReadyForNewTimes) 
			{
				if(DinInput2 == 0)
				{
					MyFocuser2.inputDeviceStr.CapturedTimes[0] = IC2BUF;
					MyFocuser2.inputDeviceStr.CapturedTimes[1] = IC2BUF;
					MyFocuser2.inputDeviceStr.CapturedTimes[2] = IC2BUF;
					trash = IC2BUF;				// Discard one value
				}
				else
				{
					trash = IC2BUF; 			// Discard one value
					MyFocuser2.inputDeviceStr.CapturedTimes[0] = IC2BUF;
					MyFocuser2.inputDeviceStr.CapturedTimes[1] = IC2BUF;
					MyFocuser2.inputDeviceStr.CapturedTimes[2] = IC2BUF;	
				}	
				MyFocuser2.inputDeviceStr.NewTimesReady = 1;
				MyFocuser2.inputDeviceStr.ReadyForNewTimes = 0;
			}
			else	
			{
				// The program is not ready for new data so just discard it.
				while(IC2CONbits.ICBNE)	// Clear the buffer
				trash = IC2BUF;
			}
			intCnt = 0;	
		}	
	}				
	IFS0bits.IC2IF = 0;					// Clear the interrupt flag	
}



*/
void ProcessDinInData( inputDevice * devPtr)
{
	unsigned int highTime, lowTime, tempPeriod;			// High time and low time of the input signal from DIN socket.
	
	switch (devPtr->AttachmentState)
	{
		default:
		case SEARCHING:
			//
			// This state means that no device has been validated. Simply wait for data to be received.
			//
			
			devPtr->AttachedDevice = NO_DEVICE;		// Clear the AttachedDevice
			devPtr->ValidationCounter = 0;			// Reset the validation counter
			devPtr->NewTimesWaitCount = 0;			// Reset the wait count for the next state.
			
			if(devPtr->NewTimesReady)				// Process new times if they are ready
			{
				devPtr->NewTimesReady = 0;			// Clear the NewTimesReady flag.
				devPtr->ReadyForNewTimes = 1;		// Set Ready for new times
				
				// We now have times. Check them to see if they match a device (could be noise)
				lowTime= (devPtr->CapturedTimes[1] - devPtr->CapturedTimes[0]) % 0xFFFF;
				highTime = (devPtr->CapturedTimes[2] - devPtr->CapturedTimes[1]) % 0xFFFF;	
				tempPeriod = highTime + lowTime;
				if((highTime > 100) && (tempPeriod > 250) && (tempPeriod < 20000))
					devPtr->AttachmentState = VALIDATING;	// Go to the next state
			}
			else
			{
				// Make sure the ISR knows we are waiting for data...
				if(devPtr->ReadyForNewTimes != 1) devPtr->ReadyForNewTimes = 1;
			}		
			break;
			
		case VALIDATING:
			//
			// In this state a device signal has been detected. We must validate the signal by getting 10
			// good data samples in a row. If we are successful then move on to attached.
			//	
			if(devPtr->NewTimesReady)				// Process new times if they are ready
			{
				devPtr->NewTimesWaitCount = 0;		// Clear the wait count
				devPtr->NewTimesReady = 0;			// Clear the NewTimesReady flag.
				devPtr->ReadyForNewTimes = 1;		// Set Ready for new times
				
				// New times are ready to process
				lowTime = (devPtr->CapturedTimes[1] - devPtr->CapturedTimes[0]) % 0xFFFF;
				highTime = (devPtr->CapturedTimes[2] - devPtr->CapturedTimes[1]) % 0xFFFF;	
				tempPeriod = highTime + lowTime;
				
				// Set the device type based on the period
				if( highTime < 100 )
				{
					devPtr->LastDeviceType = NO_DEVICE;
					devPtr->AttachedDevice = NO_DEVICE;
				}	
				else if(tempPeriod < 250)
				{
					devPtr->LastDeviceType = NO_DEVICE;
					devPtr->AttachedDevice = NO_DEVICE;
				}	
				else if (tempPeriod < 1000)
				{
					devPtr->LastDeviceType = devPtr->AttachedDevice;
					devPtr->AttachedDevice = IN_OUT_REMOTE;
				}	
				else if ((tempPeriod > 3000) && (tempPeriod < 20000))
				{
					devPtr->LastDeviceType = devPtr->AttachedDevice;
					devPtr->AttachedDevice = TEMP_PROBE;
				}	
				else 
				{
					devPtr->LastDeviceType = devPtr->AttachedDevice;
					devPtr->AttachedDevice = NO_DEVICE;	
				}
				
				// Make sure the device type didn't change
				if(devPtr->AttachedDevice != devPtr->LastDeviceType)
					devPtr->ValidationCounter = 0;				// Reset if they don't match.
				
				// Check if Validation is complete
				if(devPtr->AttachedDevice != NO_DEVICE)	// if a valid device was found
				{
					if(devPtr->ValidationCounter++ >= 20)
					{ 	
						devPtr->AttachmentState = ATTACHED;			// Go to the next state.
						// The AttachedDevice property is already set.
						devPtr->ValidationCounter = 10;
					}	
				}	
				else
				{
					devPtr->ValidationCounter = 0;			// Reset because we want 10 good times in a row.
					devPtr->AttachmentState = SEARCHING;	// Go back to the beginning. 
				}	
			}
			else
			{
				// Make sure the ISR knows we are waiting for data...
				if(devPtr->ReadyForNewTimes != 1) devPtr->ReadyForNewTimes = 1;
				
				// Check if the device is removed...
				if(devPtr->NewTimesWaitCount++ >= 10000) 
				devPtr->AttachmentState = SEARCHING; // Go back to the beginning. 
			}	
				
			break;
			
		case ATTACHED:
			//
			// In this state the attached device has been validated successfully. 10 data sets have been
			// received indicating the same device type in a row. Now, in order to invalidate the device we
			// have to receive 3 bad sets of data in a row.
			//
			if(devPtr->NewTimesReady)				// Process new times if they are ready
			{
				devPtr->NewTimesWaitCount = 0;		// Reset the wait count
				devPtr->NewTimesReady = 0;			// Clear the NewTimesReady flag.
				devPtr->ReadyForNewTimes = 1;		// Set Ready for new times
				
				// New data is available, process it.
				lowTime = (devPtr->CapturedTimes[1] - devPtr->CapturedTimes[0]) % 0xFFFF;
				highTime = (devPtr->CapturedTimes[2] - devPtr->CapturedTimes[1]) % 0xFFFF;	
				tempPeriod = highTime + lowTime;
				
				// Determine the device type
				if( highTime < 100)
				{
					devPtr->ValidationCounter--;	
				}	
				else if(tempPeriod < 250)
				{
					//devPtr->AttachedDevice = NO_DEVICE;
					devPtr->ValidationCounter--;
				}	
				else if (tempPeriod < 1000)
				{
					if(devPtr->AttachedDevice != IN_OUT_REMOTE)
						devPtr->ValidationCounter--;
					else 
					{
						// Set the duty cycle and period and reset validation counter
						devPtr->CurrentDutyCycle = (float)highTime / (float)lowTime;
						devPtr->Period = tempPeriod;
						devPtr->ValidationCounter = 10;	
					}	
				}	
				else if ((tempPeriod > 3000) && (tempPeriod < 20000))
				{
					if(devPtr->AttachedDevice != TEMP_PROBE)
						devPtr->ValidationCounter--;
					else 
					{
						// Set the duty cycle and period and reset validation counter
						devPtr->CurrentDutyCycle = (float)highTime / (float)lowTime;
						devPtr->Period = tempPeriod;
						devPtr->ValidationCounter = 10;		
					}	
				}	
				else 	// Device period is unrecognized
				{
					devPtr->ValidationCounter--;
				}	
				
				// Check if the device is invalidated... If it is reset the state machine.
				if(devPtr->ValidationCounter <= 5) 
					devPtr->AttachmentState = SEARCHING;	// Go back to the beginning	
			}
			else
			{
				// Make sure the ISR knows we are waiting for data...
				if(devPtr->ReadyForNewTimes != 1) devPtr->ReadyForNewTimes = 1;
				
				// Check if the device is removed...
				if(devPtr->NewTimesWaitCount++ >= 100) devPtr->AttachmentState = SEARCHING; // Go back to the beginning. 
			}
			break;				
	}	
}	















