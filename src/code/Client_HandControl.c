// Client_HandControl.c
// This file contians functions for communication between the mother board and an auxillary hand control unit.


// ***** INCLUDES **********************************************************************/
#include <string.h>
#include "Client_HandControl.h"
#include "FocusingRotator.h"
#include "NVM.h"
#include "HardwareProfile.h"

// This is to get rid of compiler warnings on iterrupt service routines
#define _NOPSV  __attribute__((no_auto_psv)) 	
#define HandControlBufferIsEmpty()				(HCB_Read == HCB_Write)

// ***** LOCAL FUNCTION PROTOTYPES *****************************************************/
void ProcessSerialCmds(void);

// ***** LOCAL VARIABLE DEFINITIONS ****************************************************/
char HandControlBuffer[SERIAL_BUFFER_SIZE] = {0};
volatile int HCB_Read = 0;
volatile int HCB_Write = 0;


// ***** PUBLIC FUNCTION DEFINITIONS ***************************************************/
void InitClient_HandControl(void)
{
	// Setup the UART2 Module
	U2MODEbits.UARTEN =1; 		// UART Enabled 
	U2MODEbits.USIDL = 0; 		// Stop in Idle Mode Bit 
	U2MODEbits.IREN = 0; 			// IrDA Encoder and Decoder Disabled 
	U2MODEbits.RTSMD = 0; 		// UxRTS in SIMPLEX mode 
	U2MODEbits.UEN = 0; 			// Tx and Rx pins are used,UxCTS,UxRTS, BCLK are controlled by port latch 
	U2MODEbits.WAKE = 0; 			// Wake up disabled on sleep mode 
	U2MODEbits.LPBACK = 0; 		// Loopback is disabled 
	U2MODEbits.ABAUD = 0; 		// Baud rate measurement is disabled 
	#if defined (__PIC24F__)
	U2MODEbits.RXINV = 0; 		// Idle state is '1' 
	#elif defined (__PIC24H__)
	U2MODEbits.URXINV = 0; 		// Idle state is '1' 
	#endif
	U2MODEbits.BRGH = 0; 			// High baurdate disabled
	U2MODEbits.PDSEL = 00; 		// No parity, 8bits 
	U2MODEbits.STSEL = 0; 		// 1 Stop bit 
	U2BRG = BRATE;		// Sets the Baud Rate to value selected in UART.h file
	U2STA = 0x0400;		//Enable Transmission, Clear all flags
	IFS1bits.U2RXIF = 0;	// Clear the interrupt flag
	IEC1bits.U2RXIE = 1;	// Enable interrupt for UART2 Module	
}

// Send byte over the UART
int sendByteUART_HC( int c)
{
	while(U2STAbits.UTXBF);
	U2TXREG = c;
	return c;
}

char sendStringUART_HC( char * p, char newLine )
{
	while(*p)
	{
		sendByteUART_HC(*p++);
	}
	if(newLine)
		sendByteUART_HC(10);
	return 1;
}

void _ISR _NOPSV _U2RXInterrupt(void) 
{
	char c;
		
	while(U2STAbits.URXDA)
	{
		c = U2RXREG;
		if(c == 10 || c == 13)
		{
			// Ignore newline characters
		}
		else
		{
			HandControlBuffer[HCB_Write] = c;
			if( (HCB_Write+1) % SERIAL_BUFFER_SIZE != HCB_Read)	// check if buffer full
				HCB_Write++;
			HCB_Write %= SERIAL_BUFFER_SIZE;
		}
	}	
	if(!U2STAbits.URXDA)	// Don't clear the flag if more data already arrived
		IFS1bits.U2RXIF = 0;
}	


void ReceiveSerialCmds_HC(void)
{
	static char ReceiveCmdState = 0;
	static char CurrentCmd[23] = {0};
	char c;
	static int charCount = 0;
	static char deviceNum = 0;
	static char deviceType = 0;
	
	//TODO: Clear the overflow flag if set
	if(U2STAbits.OERR)
	{
		U2STAbits.OERR = 0;
		#ifdef __DEBUG
			while(1);	// Freeze here if it occurs while debugging!
		#endif
	}	
	
	switch (ReceiveCmdState)
	{
		default:
		case 0:		
			// Check if the buffer contains data
			if (HandControlBufferIsEmpty()) return;
			charCount = 0;
			// Buffer has data, get the first item
			CurrentCmd[0] = HandControlBuffer[HCB_Read++];
			HCB_Read %= SERIAL_BUFFER_SIZE;
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
			if (HandControlBufferIsEmpty()) return;
			
			// Read the next value from the buffer and Change the buffer read pointer
			c = HandControlBuffer[HCB_Read++];
			HCB_Read %= SERIAL_BUFFER_SIZE;
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
				sendStringUART_HC(ERR_CMD_UNKNOWN, 1);
				ReceiveCmdState = 0;
				break;
			}		
		case 2:
			// Check if the buffer contains data
			if (HandControlBufferIsEmpty()) return;
			charCount = 0;
			// Read the next value from the buffer and Change the buffer read pointer
			c = HandControlBuffer[HCB_Read++];
			HCB_Read %= SERIAL_BUFFER_SIZE;
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
				sendStringUART_HC( ERR_CMD_UNKNOWN, 1);
				ReceiveCmdState = 0;
				break;
			}
		case 3:
			// Now we are shifting in the command data, stay here until
			// the end command or begin command is received.
			if (HandControlBufferIsEmpty()) return;
			// Read the next value from the buffer and Change the buffer read pointer
			c = HandControlBuffer[HCB_Read++];
			HCB_Read %= SERIAL_BUFFER_SIZE;
			
			if(charCount > (FOCUSER_COMMAND_SIZE + 4))
			{
					// Send command too long error
					sendStringUART_HC(ERR_CMD_TOO_LONG, 1);
					// Wait for new command
					ReceiveCmdState = 0;
			}
			else if(c == '>')
			{
				// THE COMMAND IS COMPLETE
				CurrentCmd[charCount] = 0;
				sendStringUART_HC("!", 1);
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
			char errorMsg[100] = {0};
			// We have a command. Determine what it is.
			focusingRotatorCommand newCmd;
			memset(&newCmd, 0x00, sizeof(focusingRotatorCommand));
			newCmd.source = HAND_CONTROL;
			newCmd.deviceType = deviceType;
			InterpretCommandString(CurrentCmd, charCount, &newCmd, errorMsg);
			// Make sure a valid command has been set
			if(newCmd.command == CMD_NONE)
				sendStringUART_HC(ERR_CMD_UNKNOWN, 1);
			else if (newCmd.command == CMD_ERROR)
				sendStringUART_HC(errorMsg, 1);
			else
				AddCmdToBfr(deviceNum, &newCmd);
				
			ReceiveCmdState = 0;
		}
		break;	
	}	
}	
