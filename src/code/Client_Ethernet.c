// Client_Ethernet.c
// Handles communication with the device via a wired Ethernet Connection

#include "Client_Ethernet.h"

#define EthernetBufferIsEmpty()				(EB_Read == EB_Write)

// ***** LOCAL FUNCTION PROTOTYPES *****************************************************/

void ProcessBufferData(void);

// ***** LOCAL VARIABLE DEFINITIONS ****************************************************/
char EthernetBuffer[ETHERNET_BUFFER_SIZE] = {0};
volatile int EB_Read = 0;
volatile int EB_Write = 0;
TCP_SOCKET	MySocket;

void ReceiveEthernetCmds()
{
	
	WORD wMaxGet, wBytesRead;
	BYTE b;
	static enum _TCPServerState
	{
		SM_HOME = 0,
		SM_LISTENING,
        SM_CLOSING,
	} TCPServerState = SM_HOME;
	
	switch(TCPServerState)
	{
		case SM_HOME:
			// Allocate a socket for this server to listen and accept connections on
			MySocket = TCPOpen(0, TCP_OPEN_SERVER, SERVER_PORT, TCP_PURPOSE_GENERIC_TCP_SERVER);
			if(MySocket == INVALID_SOCKET)
				return;

			TCPServerState = SM_LISTENING;
			break;

		case SM_LISTENING:
			// See if anyone is connected to us
			if(!TCPIsConnected(MySocket))
				return;
				
			// Figure out how many bytes have been received and how many we can transmit.
			wMaxGet = TCPIsGetReady(MySocket);	// Get TCP RX FIFO byte count
			
			
			// Read the data into the buffer
			wBytesRead = 0;
			while (wBytesRead < wMaxGet)
			{
				if(!TCPGet(MySocket, &b)) 
					break;	// Byte NOT read... (No connection or no data to read)
				
				if(b == 10 || b == 13)
				{
					// Ignore newline characters
				}
				else
				{
					EthernetBuffer[EB_Write] = b;
					if( (EB_Write+1) % ETHERNET_BUFFER_SIZE != EB_Read)	// check if buffer full
						EB_Write++;
					EB_Write %= ETHERNET_BUFFER_SIZE;
				}
				wBytesRead++;
			}	
	
			break;
			
		case SM_CLOSING:
			// Close the socket connection.
            TCPClose(MySocket);

			TCPServerState = SM_HOME;
			break;
	}
	
	ProcessBufferData();
	
}	

void ProcessBufferData(void)
{

	static char CurrentCmd[23] = {0};
	char c;
	static int charCount = 0;
	static char deviceNum = 0;
	static char deviceType = 0;
	static enum _ProcessBufferState
	{
		SM_BEGIN = 0,
		SM_GET_F,
        SM_GET_DEV_NUM,
        SM_GET_DATA,
        SM_PROC_CMD
	} ProcessBufferState = SM_BEGIN;
	
	switch (ProcessBufferState)
	{
		case SM_BEGIN:

			// Check if the buffer contains data
			if (EthernetBufferIsEmpty()) return;
			charCount = 0;
			// Buffer has data, get the first item
			CurrentCmd[0] = EthernetBuffer[EB_Read++];
			EB_Read %= ETHERNET_BUFFER_SIZE;
			if(CurrentCmd[charCount] == '<')
			{
				ProcessBufferState = SM_GET_F;	// Increment to the next state
				// DON'T BREAK, FALL THROUGH TO NEXT STATE
			}
			else
			{
				break;
			}
	
		case SM_GET_F:

			// Check if the buffer contains data
			if (EthernetBufferIsEmpty()) return;
			
			// Read the next value from the buffer and Change the buffer read pointer
			c = EthernetBuffer[EB_Read++];
			EB_Read %= ETHERNET_BUFFER_SIZE;
			// Check if it's 'F'
			if(c == 'F' || c == 'R')
			{
				ProcessBufferState = SM_GET_DEV_NUM;
				deviceType = c;
				// DON'T BREAK, FALL THROUGH TO NEXT STATE
			}
			else
			{
				// unrecognized command just start the cycle over...
				sendStringEthernet(ERR_CMD_UNKNOWN, 1);
				ProcessBufferState = SM_BEGIN;
				break;
			}
	
		case SM_GET_DEV_NUM:

			// Check if the buffer contains data
			if (EthernetBufferIsEmpty()) return;
			charCount = 0;
			// Read the next value from the buffer and Change the buffer read pointer
			c = EthernetBuffer[EB_Read++];
			EB_Read %= ETHERNET_BUFFER_SIZE;
			// Check if it's '1' or '2'
			if(c == '1' || c == 'H')
			{
				deviceNum = c;
				charCount = 0;
				ProcessBufferState = SM_GET_DATA;
				// DON'T BREAK, FALL THROUGH TO NEXT STATE
			}
			else
			{
				// Unrecognized command received. Send error
				sendStringEthernet( ERR_CMD_UNKNOWN, 1);
				ProcessBufferState = SM_BEGIN;
				break;
			}
				
		case SM_GET_DATA:
			// Now we are shifting in the command data, stay here until
			// the end command or begin command is received.
			if (EthernetBufferIsEmpty()) return;
			// Read the next value from the buffer and Change the buffer read pointer
			c = EthernetBuffer[EB_Read++];
			EB_Read %= ETHERNET_BUFFER_SIZE;
			
			if(charCount > (FOCUSER_COMMAND_SIZE + 4))
			{
					// Send command too long error
					sendStringEthernet(ERR_CMD_TOO_LONG, 1);
					// Wait for new command
					ProcessBufferState = SM_BEGIN;
			}
			else if(c == '>')
			{
				// THE COMMAND IS COMPLETE
				CurrentCmd[charCount] = 0;
				sendStringEthernet("!", 1);
				ProcessBufferState = SM_PROC_CMD;
			}
			else if ( c == '<')
			{
				ProcessBufferState = SM_GET_F;	
			}
			
			else 	
			{		
				CurrentCmd[charCount++] = c;
			}	
			break;

		case SM_PROC_CMD:
		{
			char errorMsg[100] = {0x00};
			// We have a command. Determine what it is.
			focusingRotatorCommand newCmd;
			memset(&newCmd, 0x00, sizeof(focusingRotatorCommand));
			newCmd.source = WIRED_ETHERNET;
			newCmd.deviceType = deviceType;
			InterpretCommandString(CurrentCmd, charCount, &newCmd, errorMsg);
			// Make sure a valid command has been set
			if(newCmd.command == CMD_NONE)
				sendStringEthernet(ERR_CMD_UNKNOWN, 1);
			else if (newCmd.command == CMD_ERROR)
			{
				sendStringEthernet(errorMsg, 1);
			}
			else
				AddCmdToBfr(deviceNum, &newCmd);
					
			ProcessBufferState = SM_BEGIN;			
		}
		break;
	}	
}	

void sendStringEthernet( char * p, char newLine )
{

	int l = 0;
	WORD wMaxPut;
	
	// Make sure the Socket is connected to something!
	if(!TCPIsConnected(MySocket)) return;
	
	// Find the length of the string
	while (*(p+l) != 0x00) l++;
	
	if(l)
	{
		wMaxPut = TCPIsPutReady(MySocket);
		if(wMaxPut < l)
		{
			#ifdef __DEBUG
			while(1);	// Hold here while debugging
			#endif
		}
		else
		{
			// Transfer the data out of our local processing buffer and into the TCP TX FIFO.
			TCPPutArray(MySocket, (BYTE*)p, l);
		}		
	}
	if(newLine) TCPPut(MySocket, 10);
		
	
	TCPFlush(MySocket); // Send the data immediatly!

}	


