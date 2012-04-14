// Client_Serial.c
// This handles the communications to a client connected via the serial (RS-232) 
// interface. This module uses UART1.

// ***** INCLUDES **********************************************************************/
#include <string.h>
#include "Client_Serial.h"
#include "FocusingRotator.h"
#include "NVM.h"
#include "HardwareProfile.h"

// This is to get rid of compiler warnings on iterrupt service routines
#define _NOPSV  __attribute__((no_auto_psv)) 	
#define SerialBufferIsEmpty()				(SB_Read == SB_Write)

// ***** LOCAL FUNCTION PROTOTYPES *****************************************************/
void ProcessSerialCmds(void);

// ***** LOCAL VARIABLE DEFINITIONS ****************************************************/
char SerialBuffer[SERIAL_BUFFER_SIZE] = {0};
volatile int SB_Read = 0;
volatile int SB_Write = 0;


// ***** PUBLIC FUNCTION DEFINITIONS ***************************************************/
void InitClient_Serial(void)
{
	// Setup the UART Module
	_UARTEN = 1; 		// UART Enable 
	_USIDL = 0; 		// Stop in Idle Mode Bit 
	_IREN = 0; 			// IrDA Encoder and Decoder Disabled 
	_RTSMD = 0; 		// UxRTS in SIMPLEX mode 
	_UEN = 0; 			// Tx and Rx pins are used,UxCTS,UxRTS, BCLK are controlled by port latch 
	_WAKE = 0; 			// Wake up disabled on sleep mode 
	_LPBACK = 0; 		// Loopback is disabled 
	_ABAUD = 0; 		// Baud rate measurement is disabled 
	#if defined (__PIC24F__)
	_RXINV = 0; 		// Idle state is '1' 
	#elif defined (__PIC24H__)
	_URXINV = 0; 		// Idle state is '1' 
	#endif
	_BRGH = 0; 			// High baurdate disabled
	_PDSEL = 00; 		// No parity, 8bits 
	_STSEL = 0; 		// 1 Stop bit 
	U1BRG = BRATE;		// Sets the Baud Rate to value selected in UART.h file
	U1STA = 0x0400;		//Enable Transmission, Clear all flags
	_U1RXIP = 6;
	IFS0bits.U1RXIF = 0;	// Now clear the interrupt flag
	IEC0bits.U1RXIE = 1;	// Enable Interrupt for UART1 module
}

// Send byte over the UART
int sendByteUART( int c)
{
	while(U1STAbits.UTXBF);
	U1TXREG = c;
	return c;
}

char sendStringUART( char * p, char newLine )
{
	while(*p)
	{
		sendByteUART(*p++);
	}
	if(newLine)
		sendByteUART(10);
	return 1;
}

void _ISR _NOPSV _U1RXInterrupt(void) 
{
	char c;
		
	while(U1STAbits.URXDA)
	{
		c = U1RXREG;
		if(c == 10 || c == 13)
		{
			// Ignore newline characters
		}
		else
		{
			SerialBuffer[SB_Write] = c;
			if( (SB_Write+1) % SERIAL_BUFFER_SIZE != SB_Read)	// check if buffer full
				SB_Write++;
			SB_Write %= SERIAL_BUFFER_SIZE;
		}
	}	
	if(!U1STAbits.URXDA)	// Don't clear the flag if more data already arrived
		IFS0bits.U1RXIF = 0;	// Now clear the interrupt flag
}	


void ReceiveSerialCmds(void)
{
	static char ReceiveCmdState = 0;
	static char CurrentCmd[23] = {0};
	
	char c;
	static int charCount = 0;
	static char deviceNum = 0;
	static char deviceType = 0;
	
	//TODO: Clear the overflow flag if set
	if(_OERR)
	{
		_OERR = 0;
		#ifdef __DEBUG
			while(1);	// Freeze here if it occurs while debugging!
		#endif
	}	
	
	switch (ReceiveCmdState)
	{
		default:
		case 0:		
			// Check if the buffer contains data
			if (SerialBufferIsEmpty()) return;
			charCount = 0;
			// Buffer has data, get the first item
			CurrentCmd[0] = SerialBuffer[SB_Read++];
			SB_Read %= SERIAL_BUFFER_SIZE;
			if(CurrentCmd[charCount] == '<')
			{
				ReceiveCmdState = 1;	// Increment to the next state
				// DON'T BREAK, FALL THROUGH TO NEXT STATE
			}
			else
			{
				break;
			}
			
		case 1:
			// Check if the buffer contains data
			if (SerialBufferIsEmpty()) return;
			
			// Read the next value from the buffer and Change the buffer read pointer
			c = SerialBuffer[SB_Read++];
			SB_Read %= SERIAL_BUFFER_SIZE;
			// Check if it's 'F'
			if(c == 'F' || c == 'R')
			{
				ReceiveCmdState = 2;
				deviceType = c;
				// DON'T BREAK, FALL THROUGH TO NEXT STATE
			}	
			else
			{
				// unrecognized command just start the cycle over...
				sendStringUART(ERR_CMD_UNKNOWN, 1);
				ReceiveCmdState = 0;
				break;
			}		
		case 2:
			// Check if the buffer contains data
			if (SerialBufferIsEmpty()) return;
			charCount = 0;
			// Read the next value from the buffer and Change the buffer read pointer
			c = SerialBuffer[SB_Read++];
			SB_Read %= SERIAL_BUFFER_SIZE;
			// Check if it's '1' or '2'
			if(c == '1' || c == 'H')
			{
				deviceNum = c;
				charCount = 0;
				ReceiveCmdState = 3;
				// DON'T BREAK, FALL THROUGH TO NEXT STATE
			}
			else
			{
				// Unrecognized command received. Send error
				sendStringUART( ERR_CMD_UNKNOWN, 1);
				ReceiveCmdState = 0;
				break;
			}
		case 3:
			// Now we are shifting in the command data, stay here until
			// the end command or begin command is received.
			if (SerialBufferIsEmpty()) return;
			// Read the next value from the buffer and Change the buffer read pointer
			c = SerialBuffer[SB_Read++];
			SB_Read %= SERIAL_BUFFER_SIZE;
			
			if(charCount > (FOCUSER_COMMAND_SIZE + 4))
			{
					// Send command too long error
					sendStringUART(ERR_CMD_TOO_LONG, 1);
					// Wait for new command
					ReceiveCmdState = 0;
			}
			else if(c == '>')
			{
				// THE COMMAND IS COMPLETE
				CurrentCmd[charCount] = 0;
				sendStringUART("!", 1);
				ReceiveCmdState = 4;
			}
			else if ( c == '<')
			{
				ReceiveCmdState = 1;		
			}
			
			else 	
			{		
				CurrentCmd[charCount++] = c;
			}	

			break;	
		
		case 4:
		{
			char errorMsg[] = {0x00};
			// We have a command. Determine what it is.
			focusingRotatorCommand newCmd;
			memset(&newCmd, 0x00, sizeof(focusingRotatorCommand));
			newCmd.source = SERIAL;
			newCmd.deviceType = deviceType;
			InterpretCommandString(CurrentCmd, charCount, &newCmd, errorMsg);
		
			// Make sure a valid command has been set
			if(newCmd.command == CMD_NONE)
				sendStringUART(ERR_CMD_UNKNOWN, 1);
			else if(newCmd.command == CMD_ERROR)
				sendStringUART(errorMsg, 1);
			else
				AddCmdToBfr(deviceNum, &newCmd);
				
			ReceiveCmdState = 0;
		}
		break;	
	}	
}	

