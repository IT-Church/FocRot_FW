//Client_WiFi.c
// Handles incoming commands and sending data to WiFi board -> some other client
// The WiFi board connects to the main board via the SPI2 module

#include "Client_WiFi.h"
#include "FocusingRotator.h"
#include "HardwareProfile.h"
#include "TCPIP Stack/Tick.h"


#define WiFiBufferIsEmpty()				(WiFiBfrRead == WiFiBfrWrite)
#define readByteSpi()	writeByteSpi(0)


// ***** LOCAL FUNCTION PROTOTYPES *****************************************************/
void ProcessBufferData(void);
void pushByteToWiFiBuffer(char b);
char ExitPassThruMode(void);
char EnterPassThruMode(void);
char writeByteSpi(char b);
char GetWiFiData();
char SetWiFiData( char cmdChar, char * bfrPtr, int length);

static inline __attribute__((__always_inline__)) void WaitForDataByte( void );

// ***** LOCAL VARIABLE DEFINITIONS ****************************************************/
char WiFiBuffer[WIFI_BUFFER_SIZE] = {0};
volatile int WiFiBfrRead = 0;
volatile int WiFiBfrWrite = 0;
static DWORD WiFiConnTimeout = 0;
static DWORD WiFiGetConfigTimer = 0;
static DWORD WiFiSetStatusTimer = 0;
deviceStatus DeviceStatus;
const char MinReqVersion[3] = {'1','0','2'};
BYTE lastStatusChkSum;

static enum _WiFiModuleMode{
	UNKNOWN,
	PASS_THRU,
	CMD_READY
} WiFiModuleMode = UNKNOWN;

// ***** GLOBAL FUNCTIONS **************************************************************/

// Function: InitClient_WiFi()
// Summeary: This funtion re-initializes the WiFi communication variables which forces the DoWork to perform 
void InitClient_WiFi(void)
{
	// We do not need to initialize the SPI registers because they use the same parameters as the 
	// EEPROM modules. We let the EEPROM_Init take care or setting up the module.
    WiFiModuleMode = UNKNOWN;
	WiFiBfrRead = 0;
	WiFiBfrWrite = 0;
	
	// Invalidate the WiFi module settings to force device to refresh it's settings
	WiFiInfo.WiFiModuleAttached = 0;
	WiFiInfo.WiFiHasCorrectFirmware = 0;
	WiFiInfo.ChangesArePending = 0;			// At this point we do not have any pending changes.
	
	// Set the WiFi Timeout to current time so the first connection attempt is delayed 5 seconds
	WiFiConnTimeout = TickGet();
}	
// Function: DoWiFiWork()
// Summary: This function maintains the connection status with the WiFi module and sets the status
//			variables accordingly. Once connection is established this function updates the WiFi module with 
// 			up to date information regarding the focusers and also reads up to date information regarding the 
// 			WiFi configuration on the WiFi module. Finally, this method checks if there are incoming commands 
// 			from the WiFi module and adds them to the command buffer when necessary.
void DoWiFiWork()
{
	// First check if the WiFi board connection is verified. ********************************************
	if(!WiFiInfo.CurrentSettings.WiFiConnectedToNetwork)
	{
		// Try to connect if it has been longer than 5 seconds
		if((TickGet() - WiFiConnTimeout) > (TICKS_PER_SECOND * 5))
		{
			WiFiConnTimeout = TickGet();
			if( GetWiFiData() != 0)
			{
				// Error proper data from the device...
				// We don't need to do anything else because we can't communcicate properly.
				// GetWifiData has already set ConnectedTo invalid
				// The mode is already set by the enter/exit pass thru methods.
				return;
			}
			else
			{
				// Received proper data from the device. Check the version info
				if(WiFiInfo.CurrentSettings.FirmwareVersion[0] < MinReqVersion[0] ||
				WiFiInfo.CurrentSettings.FirmwareVersion[1] < MinReqVersion[1] ||
				WiFiInfo.CurrentSettings.FirmwareVersion[2] < MinReqVersion[2])
				{
					WiFiInfo.WiFiHasCorrectFirmware = 0;
				}
				else
				{
					WiFiInfo.WiFiHasCorrectFirmware = 1;
				}
			}			
		}
		return;
	}
	// If the connection is established, make sure the Firmware Version is correct before doing anything else
	if(WiFiInfo.WiFiHasCorrectFirmware == 0)
	{
		// Set the connection state false so that the device attempts to reconnect...
		WiFiInfo.CurrentSettings.WiFiConnectedToNetwork = 0;
		return;
	}	
	
	
	// ***************************************************************************************************
	// The connection has been verified, try to get new info from the device if the desired amount of time has
	// passed.
	if( (TickGet() - WiFiGetConfigTimer) > (TICKS_PER_SECOND / 2))	// Only check every 1/2 second.
	{
		WiFiGetConfigTimer = TickGet();	// Update the timer value.
		if(GetWiFiData() != 0)return;
		// if an error occurs stop now.
		
		// Data has been read from the device. Update the device with focuser status.
				
		
		// Check for a received command that the WiFi client has requested.
		if(WiFiInfo.CurrentSettings.Command[0] == '<')
		{
			char errorMsg[100] = {0x00};
			// The WiFi board wants us to process a command 
			focusingRotatorCommand newCmd;
			int len;
			// Make sure the 'F' is present
			if(WiFiInfo.CurrentSettings.Command[1] != 'F') return;
			// Make sure a correct target is specified.
			if(	(WiFiInfo.CurrentSettings.Command[2] != '1') &&
				(WiFiInfo.CurrentSettings.Command[2] != '2') &&
				(WiFiInfo.CurrentSettings.Command[2] != 'H')) return;
			// Determine the Command Length
			for(len=0; len<22; len++)
			{
				if(WiFiInfo.CurrentSettings.Command[len] == '>') break; 		
			}	
			len-=4;		// To get rid of <,F,1, and > characters
			newCmd.source = WIFI_HTTP;
			InterpretCommandString((char*)&WiFiInfo.CurrentSettings.Command[3], len, &newCmd, errorMsg);
			// Ignore the error message for now because this should never get an error!
			AddCmdToBfr((char)WiFiInfo.CurrentSettings.Command[2], &newCmd );
		}
	}	

	// ***************************************************************************************************
	//  Try to send the device the latest focuser status to the WiFi Module
	if( (TickGet() - WiFiSetStatusTimer) > (TICKS_PER_SECOND / 2)) // Only check every half second
	{
		WiFiSetStatusTimer = TickGet();		// Update the timer value
		strcpy((char*)&DeviceStatus.F1Nickname, (char*)&MyFocuser1.configStr.DeviceNickname);
//		strcpy((char*)&DeviceStatus.F2Nickname, (char*)&MyFocuser2.configStr.DeviceNickname);
		DeviceStatus.F1CurrentPos = MyFocuser1.statusStr.CurrentPosition;
//		DeviceStatus.F2CurrentPos = MyFocuser2.statusStr.CurrentPosition;
		DeviceStatus.F1CurrentTemp = MyFocuser1.statusStr.CurrentTemp;
//		DeviceStatus.F2CurrentTemp = MyFocuser2.statusStr.CurrentTemp;
		DeviceStatus.F1MaxPos = MyFocuser1.motionInfoStr.MaxPosition;
//		DeviceStatus.F2MaxPos = MyFocuser2.motionInfoStr.MaxPosition;
		DeviceStatus.F1TempCompOn = MyFocuser1.tempCompInfoStr.TempCompOn;
//		DeviceStatus.F2TempCompOn = MyFocuser2.tempCompInfoStr.TempCompOn;
		SetWiFiData('S', (char*)&DeviceStatus, sizeof(deviceStatus));
	}	
	// ***************************************************************************************************
	// If there are pending changes to WiFi Module settings send the changes now...
	if(WiFiInfo.ChangesArePending)
	{
		// Calculate a new Checksum for the PendingSettings
		WiFiInfo.PendingSettings.CheckSum = CalcIPChecksum((BYTE*)&WiFiInfo.PendingSettings, sizeof(wiFiSettings) - 1);
		// Send the new settings to the WiFi board
		SetWiFiData('C', (char*)&WiFiInfo.PendingSettings, sizeof(wiFiSettings));
		WiFiInfo.ChangesArePending = 0;
	}	
	
}

	
// Function: ReceiveWiFiCmds()
// Summary: The main program loop must call this program regularly to ensure stable communication with
//			a WiFi client.

void ReceiveWiFiCmds()
{
	int maxRead;
	static char ReceiveCmdState = 0;
	static char CurrentCmd[23] = {0};
	static int charCount = 0;
	static char deviceNum = 0;
	static char deviceType = 0;
	char c;

	// Make sure it's in pass thru mode. Return if we can't enter
	if(WiFiModuleMode != PASS_THRU)
	{
		if(EnterPassThruMode())	// Returns 0 if success, 1 if error	
			return;
	}

		
	// Next we need to read any pass thru data that the WiFi board has in it's buffer. Read until we receive 0.
	for (maxRead = 0; maxRead< 1000; maxRead++)
	{
		c = readByteSpi();
		if(c) 
			pushByteToWiFiBuffer(c);
		else 
			break;
	}	
	c = 0;
	
	// Finally check the receive buffer for commands just like every other client
	switch (ReceiveCmdState)
	{
		default:
		case 0:		
			// Check if the buffer contains data
			if (WiFiBufferIsEmpty()) return;
			charCount = 0;
			// Buffer has data, get the first item
			CurrentCmd[0] = WiFiBuffer[WiFiBfrRead++];
			WiFiBfrRead %= WIFI_BUFFER_SIZE;
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
			if (WiFiBufferIsEmpty()) return;
			
			// Read the next value from the buffer and Change the buffer read pointer
			c = WiFiBuffer[WiFiBfrRead++];
			WiFiBfrRead %= WIFI_BUFFER_SIZE;
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
				SendStringWiFiPassThru(ERR_CMD_UNKNOWN, 1);
				ReceiveCmdState = 0;
				break;
			}		
		case 2:
			// Check if the buffer contains data
			if (WiFiBufferIsEmpty()) return;
			charCount = 0;
			// Read the next value from the buffer and Change the buffer read pointer
			c = WiFiBuffer[WiFiBfrRead++];
			WiFiBfrRead %= WIFI_BUFFER_SIZE;
			// Check if it's '1' or '2' or 'H'
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
				SendStringWiFiPassThru( ERR_CMD_UNKNOWN, 1);
				ReceiveCmdState = 0;
				break;
			}
		case 3:
			// Now we are shifting in the command data, stay here until
			// the end command or begin command is received.
			if (WiFiBufferIsEmpty()) return;
			// Read the next value from the buffer and Change the buffer read pointer
			c = WiFiBuffer[WiFiBfrRead++];
			WiFiBfrRead %= WIFI_BUFFER_SIZE;
			
			if(charCount > (FOCUSER_COMMAND_SIZE + 4))
			{
					// Send command too long error
					SendStringWiFiPassThru(ERR_CMD_TOO_LONG, 1);
					// Wait for new command
					ReceiveCmdState = 0;
			}
			else if(c == '>')
			{
				// THE COMMAND IS COMPLETE
				CurrentCmd[charCount] = 0;
				SendStringWiFiPassThru("!", 1);
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
			newCmd.source = WIFI;
			newCmd.deviceType = deviceType;
			InterpretCommandString(CurrentCmd, charCount, &newCmd, errorMsg);
			// Make sure a valid command has been set
			if(newCmd.command == CMD_NONE)
				SendStringWiFiPassThru(ERR_CMD_UNKNOWN, 1);
			else if (newCmd.command == CMD_ERROR)
				SendStringWiFiPassThru(errorMsg, 1);
			else
				AddCmdToBfr(deviceNum, &newCmd);
				
			ReceiveCmdState = 0;
		}
		break;	
	}
	
}	

		

// Function: SendStringWiFiPassThru(char *p, char newLine)
// Description: Use this function to send characters to the client device connected to the WiFi board
// 				The function will EnterPassThruMode if necessary and then begin sending data.
void SendStringWiFiPassThru(char * p, char newLine )
{
	char c;
	// Make sure the device is in pass through mode
	if(WiFiModuleMode != PASS_THRU)
		{
		if(EnterPassThruMode())
		{
			// Freeze here if debugging. This means ther is no device connected
			#if defined (__DEBUG) 
				while(1);
			#endif
			return;
		}		
	}
	// Send the text
	while (*p)
	{
		c = writeByteSpi(*p++);
		// Every write could also be a read so add the data to the receive buffer
		if(c) pushByteToWiFiBuffer(c);		
	}
	// Send the newline character
	if(newLine) 
	{
		c = writeByteSpi(10);
		// Every write could also be a read so add the data to the receive buffer
		if(c) pushByteToWiFiBuffer(c);
	}	
		// Do not exit PassThru Mode.	
	
}	

// Function: pushByteToWiFiBuffer(char b)
// Description: This function adds a byte to the RxBuffer (pass thru buffer)
//              All bytes in the RxBuffer will be read as inputs to the  
void pushByteToWiFiBuffer(char b)
{
	WiFiBuffer[WiFiBfrWrite] = b;
			if( (WiFiBfrWrite+1) % WIFI_BUFFER_SIZE != WiFiBfrRead)	// check if buffer full
				WiFiBfrWrite++;
			WiFiBfrWrite %= WIFI_BUFFER_SIZE;
}	

// Function: writeByteSpi(char b)
// Description: sends one byte (b) to the slave spi device and reads one byte at the same time.
// Return: the byte read simultaneously.
char writeByteSpi(char b)
{
	unsigned int i;
	WIFI_CS_IO = 0;		// assert the WiFi board
	WIFI_SSPBUF = b;	// write byte to be sent during exchange
	WaitForDataByte();	// wait for exchange to complete.
	WIFI_CS_IO = 1;		// deassert the WiFi board
	// pause before sending the next byte
	for (i = 0; i < 300; i++);
	return WIFI_SSPBUF;	// return the byte that was received during the exchange
}	


// Function: WaitForDataByte(void)
// Description: pauses until the SPI hardware is finished with the send/receive process of a single byte
static inline __attribute__((__always_inline__)) void WaitForDataByte( void )
{
    while ((WIFI_SPISTATbits.SPITBF == 1) || (WIFI_SPISTATbits.SPIRBF == 0));
}



// Function: ExitPassThruMode()
// Description: Send the « character to alert the WiFi board that we want to send a command
// The slave device will respond back with « to indicate that it is out of pass through mode.
// Any non-zero data received before the acknowledgment byte needs to be passed through.
// This function will attempt to enter pass through mode upto 1000 times and then timeout.
// Return: 0 if successfull. 1 if unsuccessful.
char ExitPassThruMode()
{
	char c;
		
	// Send the exit pass thru command
    writeByteSpi('«');
	c = readByteSpi();
	if(c == '«')
	{
		WiFiModuleMode = CMD_READY;
		return 0;
	}
	else if ((c == (char)0) || (c == (char)0xFF))
	{
		// No data here...
	}
	else
	{
		// This is data we need to "pass through" because we aren't successfully in cmd mode yet.
		pushByteToWiFiBuffer(c);
	}			
	
	// If we got this far the transfer attempt timed out. 
	WiFiModuleMode = UNKNOWN;
	return 1;
}

// Function: EnterPassThruMode()
// Summary: This function should be used to instruct the slave device (WiFi Board) to enter pass thru mode.
// Description: The funciton will send the '»' character to the slave device and then read a response back.
//				The device must respond back with '»' to acknowledge that it is in pass through mode.
char EnterPassThruMode()
{
	char c;
	writeByteSpi('»');	// The first byte is junk. Most likely 0.
	c = readByteSpi();  // This should be the response
	if(c == '»'){
		WiFiModuleMode = PASS_THRU;
	 	return 0;
	} 
	else
	{ 
		return 1;
		WiFiModuleMode = UNKNOWN;
	}
	return 0;	
}	



// Function: GetWiFiData() 
// Summary:	This function should exit the slave from pass through mode and send the 'G' command to GET the 
// 			data from the WiFi device. This function will then calculate the checksum and return it's success. 
// Return: 0 if Success, 1 if Fail to read any data, 2 is checksum is not correct
char GetWiFiData()
{
	int i;	
	char* ptr;
	char c;
	volatile BYTE chksum;

	// First Exit pass thru mode if necessary
	if(WiFiModuleMode != CMD_READY)
	{
		if(ExitPassThruMode() != 0) return 1;
	}
	
	// Send the "G" command to get the WiFi Boards data.
	writeByteSpi('G');
	c = readByteSpi();
    if( c != 'G')
    { 
	    // The WiFi board didn't respond correctly. Something is wrong.
	    WiFiInfo.CurrentSettings.WiFiConnectedToNetwork = 0;
	    WiFiModuleMode = UNKNOWN;
	    return 1;
   	} 
   	WiFiInfo.WiFiModuleAttached = 1;
	// Now try to read the data.
	for	(i=0; i<sizeof(wiFiSettings); i++)
	{
		ptr = (char*)&WiFiInfo.CurrentSettings + i;
		*ptr = readByteSpi();
	}
	
	// Calculate the checksum on the data to verify good data
	chksum = CalcIPChecksum((BYTE*)&WiFiInfo.CurrentSettings, sizeof(wiFiSettings) - 1);
	if(chksum == WiFiInfo.CurrentSettings.CheckSum)
		WiFiInfo.CurrentSettings.WiFiConnectedToNetwork = 1;
	else
		WiFiInfo.CurrentSettings.WiFiConnectedToNetwork = 0;
	return !WiFiInfo.CurrentSettings.WiFiConnectedToNetwork;
	
	
}	

char SetWiFiData( char cmdChar, char * bfrPtr, int length)
{
	int i;	// for keeping track of bytes read.
	char c;
	// First Exit pass thru mode if necessary
	if(WiFiModuleMode == PASS_THRU)
	{
		if(ExitPassThruMode() != 0) return 1;
	}
	
	// Send a command
	writeByteSpi(cmdChar);
	c = writeByteSpi(*bfrPtr++);
	if(c != cmdChar) return 1;	// Check to make sure we got the ack back.
	length--;					// subtract one from length because we just send the first byte.	
	
	for	(i=0; i<length; i++)
	{
		writeByteSpi(*bfrPtr);
		bfrPtr++;	// Increment the pointer to the next byte
	}	
	return 0; // return 0 = SUCCESS
}
