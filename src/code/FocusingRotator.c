// Focuser.c
// Contains members that define a Temperature Compensating Focuser

// ***** INCLUDES **********************************************************************/
#include "FocusingRotator.h"
#include "Client_Serial.h"
#include "Client_HandControl.h"
#include "Client_Ethernet.h"
#include "Client_WiFi.h"
#include "NVM.h"
#include "Stepper.h"
#include "TempComp.h"
#include "DIN_Input.h"
#include "FocuserProfiles.h"

#include <string.h>
#define CmdBuffer1IsEmpty()			(CmdBuff1Head == CmdBuff1Tail)
#define CmdBuffer2IsEmpty()			(CmdBuff2Head == CmdBuff2Tail)
#define HubBufferIsEmpty()			(HubBuffHead == HubBuffTail)


// ***** GLOBAL VARIABLE DEFINITIONS ***************************************************/
focuser MyFocuser1;
rotator MyRotator1;
hubInfo HubInfo;
volatile wiFiInfo WiFiInfo;
focusingRotatorCommand CommandBuffer1[CMD_BUFFER_SIZE];
focusingRotatorCommand CommandBuffer2[CMD_BUFFER_SIZE];
focusingRotatorCommand HubCommandBuffer[CMD_BUFFER_SIZE];

// ***** LOCAL VARIABLE DEFINITIONS ****************************************************/
volatile int CmdBuff1Head = 0;
volatile int CmdBuff1Tail = 0;
volatile int CmdBuff2Head = 0;
volatile int CmdBuff2Tail = 0;
volatile int HubBuffHead = 0;
volatile int HubBuffTail = 0;

// ***** PRIVATE FUNCTIONS *************************************************************/
void sendOutput(char * text, CMD_SOURCE src);
void InitFocusingRotator(focuser * focuserPtr, rotator * rotatorPtr);
void ProcessFocusingRotatorCmd(focusingRotatorCommand cmd);
void ProcessRotatorCmd(focusingRotatorCommand cmd);
void prepareStatusString( char * strPtr, focuser focuserStr);
void prepareConfigString ( char * strPtr, focuser focuserStr );
void prepareStatusStringRot( char * strPtr, rotator rotatorStr);
void prepareConfigStringRot( char * strPtr, rotator rotatorStr );
void prepareHubInfoString (char * strPtr);
void prepareDiagString (char * strPtr);
char conditionsOkToStartMove(focusingRotatorCommand cmd);

void getSignedDecString(LONG pos, char * posString, char n);
WORD getUnsignedIntFromString( char * string, char strSize);
char CheckConfigSubCommand(char * Parameters);
void CalculateTemp(focuser * focuserStr);
void CheckRemoteInOutPress(focuser * focuserPtr);
void ResetLED(void);
void GetIPString(IP_ADDR ip, char* dest);

void InitFocusers(void)
{
	HubInfo.FirmwareVersion[0] = FIRMWARE_VERSION_MAJOR;
	HubInfo.FirmwareVersion[1] = FIRMWARE_VERSION_MINOR;
	HubInfo.FirmwareVersion[2] = FIRMWARE_VERSION_REVISION;
	HubInfo.InSleepMode = 0;
	WiFiInfo.CurrentSettings.FirmwareVersion[0] = (BYTE)'0';
	WiFiInfo.CurrentSettings.FirmwareVersion[1] = (BYTE)'0';
	WiFiInfo.CurrentSettings.FirmwareVersion[2] = (BYTE)'0';
	
//	MyFocuser1.focuserNumber = '1';
//	MyFocuser2.focuserNumber = '2';
	
//	MyFocuser1.configStr.NvmStartAddr = NVM_START_ADDR_F1;	// NVM_START_ADDR_F1 is defined
//	MyFocuser2.configStr.NvmStartAddr = NVM_START_ADDR_F2;  // in NVM.h
//	MyFocuser1.motionInfoStr.TimerPeriodPtr = &PR4;	
//	MyFocuser2.motionInfoStr.TimerPeriodPtr = &PR5;
//	MyFocuser1.motionInfoStr.PowerTimerDuty = &OC1RS;
//	MyFocuser2.motionInfoStr.PowerTimerDuty = &OC2RS;
	InitFocusingRotator(&MyFocuser1, &MyRotator1);

	InitDIN_Input();
	InitSteppers();
	InitTempComp(&MyFocuser1);
	ResetLED();
	
	//CheckHomeSwitch(1);	// Check focuser home switch
	//CheckHomeSwitch(0);	// Check rotator home switch
	
	if(!MyFocuser1.statusStr.IsHomed)
		RequestHomeStartFoc();
	if(!MyRotator1.statusStr.IsHomed)
		RequestHomeStartRot();
}	

void InitFocusingRotator(focuser * focuserPtr, rotator * rotatorPtr)
{	
	char valuesAreDefault = 0;
	FreezeStepper(1);	// freeze the focuser
	FreezeStepper(0);	// freeze the rotator
	focuserPtr->motionInfoStr.TempCompAtStartComplete = 0;
	focuserPtr->statusStr.CurrentPosition = 0;
	focuserPtr->statusStr.TargetPosition = 0;
	focuserPtr->statusStr.IsMoving = 0;
	focuserPtr->statusStr.IsHoming = 0;
	focuserPtr->statusStr.IsHomed = 0;
	focuserPtr->statusStr.TempProbeAttached = 0;
	focuserPtr->tempCompInfoStr.ResetRequired = 1;
	
	rotatorPtr->statusStr.CurrentPosition = 0;
	rotatorPtr->statusStr.TargetPosition = 0;
	rotatorPtr->statusStr.IsMoving = 0;
	rotatorPtr->statusStr.IsHoming = 0;
	rotatorPtr->statusStr.IsHomed = 0;
	
	// Try to load saved config settings and restore defaults if 
	// unsuccessful.
	if(LoadConfigFromNVM(focuserPtr, rotatorPtr))
	{		
		// Settings have not been saved yet. Load the defaults
		valuesAreDefault = 1;
		// Set Device nickname
		focuserPtr->configStr.DeviceNickname[0] = 'F';
		focuserPtr->configStr.DeviceNickname[1] = 'o';
		focuserPtr->configStr.DeviceNickname[2] = 'c';
		focuserPtr->configStr.DeviceNickname[3] = 'u';
		focuserPtr->configStr.DeviceNickname[4] = 's';
		focuserPtr->configStr.DeviceNickname[5] = 'e';
		focuserPtr->configStr.DeviceNickname[6] = 'r';
		focuserPtr->configStr.DeviceNickname[7] = 0;
		focuserPtr->configStr.DeviceNickname[8] = 0;
		focuserPtr->configStr.DeviceNickname[9] = 0;
		focuserPtr->configStr.DeviceNickname[10] = 0;
		focuserPtr->configStr.DeviceNickname[11] = 0;
		focuserPtr->configStr.DeviceNickname[12] = 0;
		focuserPtr->configStr.DeviceNickname[13] = 0;
		focuserPtr->configStr.TempCompAtStart = 0;
		
		focuserPtr->configStr.DeviceType = 'A';			// Default type to No Device type
		focuserPtr->statusStr.LastSavedPositionOffset = 0;
		focuserPtr->tempCompInfoStr.LastTempCompStartPosOffset = 0;
		focuserPtr->tempCompInfoStr.LastTempCompStartTempOffset = 0;
		focuserPtr->tempCompInfoStr.TempCompOn = 0;
		focuserPtr->tempCompInfoStr.TempCoeffs[0] = 86;
		focuserPtr->tempCompInfoStr.TempCoeffs[1] = 86;
		focuserPtr->tempCompInfoStr.TempCoeffs[2] = 86;
		focuserPtr->tempCompInfoStr.TempCoeffs[3] = 86;
		focuserPtr->tempCompInfoStr.TempCoeffs[4] = 86;
		focuserPtr->tempCompInfoStr.TempCompMode = 'A';
		focuserPtr->configStr.BacklashCompSteps = 40;
		focuserPtr->configStr.BacklashCompOn = 0;
		focuserPtr->configStr.LedBrightness = 75;
		focuserPtr->configStr.HomeAtStart = 1;
		
		rotatorPtr->configStr.DeviceNickname[0] = 'R';
		rotatorPtr->configStr.DeviceNickname[1] = 'o';
		rotatorPtr->configStr.DeviceNickname[2] = 't';
		rotatorPtr->configStr.DeviceNickname[3] = 'a';
		rotatorPtr->configStr.DeviceNickname[4] = 't';
		rotatorPtr->configStr.DeviceNickname[5] = 'o';
		rotatorPtr->configStr.DeviceNickname[6] = 'r';
		rotatorPtr->configStr.DeviceNickname[7] = 0;
		rotatorPtr->configStr.DeviceNickname[8] = 0;
		rotatorPtr->configStr.DeviceNickname[9] = 0;
		rotatorPtr->configStr.DeviceNickname[10] = 0;
		rotatorPtr->configStr.DeviceNickname[11] = 0;
		rotatorPtr->configStr.DeviceNickname[12] = 0;
		rotatorPtr->configStr.DeviceNickname[13] = 0;
		rotatorPtr->configStr.Reverse = 0;
		rotatorPtr->configStr.HomeAtStart = 1;
		rotatorPtr->configStr.BacklashCompOn = 0;
		rotatorPtr->configStr.BacklashCompSteps = 40;
		
		SaveDeviceConfig(*focuserPtr, *rotatorPtr);
	}		
	
	rotatorPtr->motionInfoStr.MaxPosition = MAX_POS_ROTATOR;
	
	if(focuserPtr->configStr.DeviceType == 'A') focuserPtr->motionInfoStr.MaxPosition = MAX_POS_FOCUSER_A;
	else if (focuserPtr->configStr.DeviceType == 'B') focuserPtr->motionInfoStr.MaxPosition = MAX_POS_FOCUSER_B;
		
	UnfreezeStepper(1);	// unfreeze the focuser
	UnfreezeStepper(0);	// unfreeze the rotator
}	

void ResetLED(void)
{
	// The timer is alredy set in the InitPic function
	
	// Setup the output compare module
	OC3CONbits.OCM = 0b110;	// Set output compare module for "PWM mode without fault protection"
	OC3CONbits.OCTSEL = 1; 	// Set output compare module to use Timer 2 as it's clock source
	OC3RS = (unsigned int)MyFocuser1.configStr.LedBrightness;
}

void AddCmdToBfr(char devNumber, focusingRotatorCommand * cmd )
{
	if(cmd->deviceType == 'F')					// This is a command for the Focuser
	{
		CommandBuffer1[CmdBuff1Tail] = *cmd;
		if( (CmdBuff1Tail+1) % CMD_BUFFER_SIZE != CmdBuff1Head)
			CmdBuff1Tail++;
		CmdBuff1Tail %= CMD_BUFFER_SIZE;
	}
	else if (cmd->deviceType == 'R')				// This is a command for Rotator
	{
		CommandBuffer2[CmdBuff2Tail] = *cmd;
		if( (CmdBuff2Tail+1) % CMD_BUFFER_SIZE != CmdBuff2Head)
			CmdBuff2Tail++;
		CmdBuff2Tail %= CMD_BUFFER_SIZE;
	}	
	else if (devNumber == 'H')				// This is a command for the Hub
	{
		HubCommandBuffer[HubBuffTail] = *cmd;
		if( (HubBuffTail+1) % CMD_BUFFER_SIZE != HubBuffHead)
			HubBuffTail++;
		HubBuffTail %= CMD_BUFFER_SIZE;
	}	
}	



void ProcessReceivedCommands()
{
	focusingRotatorCommand CurrentCommand;
	
	if(CmdBuffer1IsEmpty()); 	// Do nothing	
	else
	{
		// New command received,  read a command from the buffer...
		CurrentCommand = CommandBuffer1[CmdBuff1Head++];
		CmdBuff1Head %= CMD_BUFFER_SIZE;
		ProcessFocusingRotatorCmd(CurrentCommand);
	}
	
	if(CmdBuffer2IsEmpty());	// Do nothing
	else
	{
		// New command received,  read a command from the buffer...
		CurrentCommand = CommandBuffer2[CmdBuff2Head++];
		CmdBuff2Head %= CMD_BUFFER_SIZE;
		ProcessFocusingRotatorCmd(CurrentCommand);
	}	
	
	if(HubBufferIsEmpty());	// Do nothing
	else
	{
		CurrentCommand = HubCommandBuffer[HubBuffHead++];
		HubBuffHead %= CMD_BUFFER_SIZE;
		ProcessFocusingRotatorCmd (CurrentCommand);	// cast 0x00 as a focuser pointer 
															    // to match the function prototype
															    // this value will not be used for anything.
	}		
}	

void ProcessFocusingRotatorCmd(focusingRotatorCommand cmd)
{
	char longString[300] = {0};
	focuser * focuserPtr = &MyFocuser1;	// So I don't have to rewrite every command.
	rotator * rotatorPtr = &MyRotator1;	
	switch (cmd.command)
	{
		default:
		case CMD_NONE:
			break;
			
		case CMD_HELLO:
			if(cmd.deviceType == 'F')
				sendOutput(focuserPtr->configStr.DeviceNickname, cmd.source);
			else
				sendOutput(MyRotator1.configStr.DeviceNickname, cmd.source);
			break;
			
		case CMD_SLEEP:
			// Halt both of the devices
			//RequestHaltDevice(&MyFocuser1);		// This will also disable temp comp mode if enabled
			//RequestHaltDevice(&MyFocuser2);
			// TODO: Put device in sleep mode
			//HubInfo.InSleepMode = 1;
		//	sendOutput("ZZZ", cmd.source);
			break;
			
		case CMD_WAKEUP:
			//HubInfo.InSleepMode = 0;
			// TODO: Wake up the device
		//	sendOutput("AWAKE", cmd.source);
			break;
			
		case CMD_HOME:
		
			// Check if ok to home
			if(!conditionsOkToStartMove(cmd))
			{
				// do nothing, error has already been sent to the command source
				break;
			}
			if(cmd.deviceType == 'F')
			{
				if (focuserPtr->statusStr.IsHoming)
					sendOutput("H", cmd.source);	
				// Check if the device is in sleep mode
				else if(HubInfo.InSleepMode)
				{
					sendOutput(ERR_DEVICE_SLEEPING, cmd.source);
				}	
				else
				{
					RequestHomeStartFoc();	// Request focuser home
					sendOutput("H", cmd.source);
				}	
			}
			else 
			{
				RequestHomeStartRot();
				sendOutput("H", cmd.source);
			}	
			break;
			
		case CMD_CENTER:
			
			if(cmd.deviceType == 'R') // Command does not exist for rotators
				return;
			if(!conditionsOkToStartMove(cmd))
			{
				// do nothing, error has already been sent to the command source
				break;
			}	
			else
			{	
				RequestAbsoluteMoveFoc((focuserPtr->motionInfoStr.MaxPosition/2));
				sendOutput("M", cmd.source);
			}	
			break;
			
		case CMD_GETSTATUS:
			if(cmd.deviceType == 'F')	
				prepareStatusString(longString, *focuserPtr);			
			else 
				prepareStatusStringRot(longString, MyRotator1);
			// Send the status 
			sendOutput(longString, cmd.source);
			break;
			
		case CMD_GETCONFIG:
			if(cmd.deviceType == 'F')
				prepareConfigString(longString, *focuserPtr);
			else 
				prepareConfigStringRot(longString, MyRotator1);
			// Send the config
			sendOutput(longString, cmd.source);
			break;
			
		case CMD_HALT:
			// No checks here becuase the device always needs to be able to halt on request.
			if(cmd.deviceType == 'F')
			{
				RequestHaltFoc();
				sendOutput("HALTED FOC", cmd.source);
			}
			else
			{
				RequestHaltRot();
				sendOutput("HALTED ROT", cmd.source);
			}	
			break;	
				
		case CMD_MOVEABS:
			{		
				if(!conditionsOkToStartMove(cmd))
				{
					// do nothing, error has already been sent do the command source
					break;
				}
				else
				{	
					DWORD newPos = 0;
					// Get the new position as an int
					newPos = getUnsignedIntFromString(&cmd.parameters[0], 6);
					if(cmd.deviceType == 'F')
					{
						// Check if it's in the proper range.
						if(newPos > focuserPtr->motionInfoStr.MaxPosition)
						{
							sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
						}	
						else
						{
							if(newPos != focuserPtr->statusStr.CurrentPosition)
								RequestAbsoluteMoveFoc(newPos);
							sendOutput("M", cmd.source);
						}
					}
					else
					{
						// Check if it's in the proper range.
						if(newPos > rotatorPtr->motionInfoStr.MaxPosition)
						{
							sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
						}	
						else
						{
							RequestAbsoluteMoveRot(newPos);
							sendOutput("M", cmd.source);
						}
					}	
				}			
			}
			break;	
			
		case CMD_MOVE_IN_1:
			if(!conditionsOkToStartMove(cmd))
			{
				// do nothing, error has already been sent do the command source
				break;
			}
			else if( cmd.deviceType == 'F')
			{
				if( focuserPtr->statusStr.CurrentPosition > 0 )
				{
					RequestAbsoluteMoveFoc((focuserPtr->statusStr.CurrentPosition - 1));
					sendOutput("M", cmd.source);
				}		
			}	
			else
			{
				if(MyRotator1.statusStr.CurrentPosition == 0)
					RequestAbsoluteMoveRot(MyRotator1.motionInfoStr.MaxPosition);
				else 
					RequestAbsoluteMoveRot((MyRotator1.statusStr.CurrentPosition - 1));
			}	
			
			break;
			
		case CMD_MOVE_OUT_1:
			if(!conditionsOkToStartMove(cmd))
			{
				// do nothing, error has already been sent do the command source
				break;
			}
			else if( cmd.deviceType == 'F')
			{
				if( focuserPtr->statusStr.CurrentPosition < focuserPtr->motionInfoStr.MaxPosition )
				{
					RequestAbsoluteMoveFoc((focuserPtr->statusStr.CurrentPosition + 1));
					sendOutput("M", cmd.source);
				}		
			}	
			else
			{
				if(MyRotator1.statusStr.CurrentPosition == MyRotator1.motionInfoStr.MaxPosition)
					RequestAbsoluteMoveRot(0);
				else 
					RequestAbsoluteMoveRot((MyRotator1.statusStr.CurrentPosition + 1));
			}
			
		case CMD_RELATIVE_MOVEIN:
			{
				if(!conditionsOkToStartMove(cmd))
				{
					// do nothing, error has already been sent do the command source
					break;
				}
				else
				{
					if(cmd.deviceType == 'F')
						StartRelativeMoveFoc(1);
					else
						StartRelativeMoveRot(1);
					sendOutput("M", cmd.source);
				}	
			}
			break;	
		
		case CMD_RELATIVE_MOVEOUT:
			{
				if(!conditionsOkToStartMove(cmd))
				{
					// do nothing, error has already been sent do the command source
					break;
				}
				else
				{
					if(cmd.deviceType == 'F')
						StartRelativeMoveFoc(0);
					else
						StartRelativeMoveRot(0);
					sendOutput("M", cmd.source);
				}	
			}
			break;
			
		case CMD_END_RELATIVE_MOVE:
			{
				if(cmd.deviceType == 'F')
					EndRelativeMoveFoc();
				else
					EndRelativeMoveRot();
				sendOutput("STOPPED", cmd.source);
			}
			break;	
			
		case CMD_SET_DNN: 	// Set the device Nickname
			// 1. Make sure it's at least one character 
			if(cmd.parameters[0] <= 0x20)
			{
				sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
				return;
			}
			if(cmd.parameters[16]!= 0x00)
			{
				sendOutput(ERR_CMD_TOO_LONG, cmd.source);
				return;
			}	
			if(cmd.deviceType == 'F')	// 2. Set the name of the focuser
				strcpy(focuserPtr->configStr.DeviceNickname, cmd.parameters);
			else 
				strcpy(rotatorPtr->configStr.DeviceNickname, cmd.parameters);
			// Flush the new config value to NVM
			SaveDeviceConfig(MyFocuser1, MyRotator1 );
			sendOutput("SET", cmd.source);
			break;
			
		case CMD_SET_DT:	// Set the device type for the focuser
			// Make sure the command is for the focuser
			if(cmd.deviceType != 'F')
			{
				sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
				return;
			}	
			// Make sure the new value is within A and Z
			if(cmd.parameters[0] != 'A' && cmd.parameters[0] != 'B')
			{
				sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
				return;
			}

			// Halt the steppers so that the focuser doesn't take off when we change the 
			// current position.
			FreezeStepper(focuserPtr->focuserNumber);
			
			//Set the new value in volatile memory
			focuserPtr->configStr.DeviceType = cmd.parameters[0];
		
			
			// Save the new device type to NVM
			SaveDeviceConfig(MyFocuser1, MyRotator1);
			
			// Reinitialize the focusers now... This will leave the communications intact.
			InitFocusingRotator(&MyFocuser1, &MyRotator1);
			
			// Request the device to begin homing
			focuserPtr->statusStr.LastSavedPosition = focuserPtr->motionInfoStr.MaxPosition / 2;
		
		
			// Home the device
			RequestHomeStartFoc();
				
				
			// Allow the stepper control to begin functioning again.
			UnfreezeStepper(focuserPtr->focuserNumber);
			
			// Acknowledge that the process is complete.
			sendOutput("SET", cmd.source);
			break;
			
		case CMD_SET_TCM:	// Set the current temp comp mode
			// Make sure the command is for the focuser
			if(cmd.deviceType != 'F')
			{
				sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
				return;
			}
			if(cmd.parameters[0] < 'A' || cmd.parameters[0] > 'E')
			{
				sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
				return;
			}
			focuserPtr->tempCompInfoStr.TempCompMode = cmd.parameters[0];
			// Flush the new config vlaue to NVM
			SaveDeviceConfig(MyFocuser1, MyRotator1);
			sendOutput("SET", cmd.source);	
			break;
				
		case CMD_SET_TCE:	// Enable/Disable temp compensation
			// Make sure the command is for the focuser
			if(cmd.deviceType != 'F')
			{
				sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
				return;
			}
			if(cmd.parameters[0] == '1')
			{
				// Make sure the probe is attached.
				if(focuserPtr->statusStr.TempProbeAttached != 1)
				{
					sendOutput(ERR_NO_TEMP_PROBE, cmd.source);
					return;
				}	
				else
				{
					focuserPtr->tempCompInfoStr.TempCompOn = 1;
					SaveDeviceConfig(MyFocuser1, MyRotator1);
				}	
			}
			else
			{
				focuserPtr->tempCompInfoStr.TempCompOn = 0;
				SaveDeviceConfig(MyFocuser1, MyRotator1);
			}
			sendOutput("SET", cmd.source);		
			break;
			
		case CMD_SET_TCS:	// Enable/Disable TempCompAtStart
		{
			// Make sure the command is for the focuser
			if(cmd.deviceType != 'F')
			{
				sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
				return;
			}
			if(cmd.parameters[0] == '1')
			{
				focuserPtr->configStr.TempCompAtStart = 1;
			}
			else focuserPtr->configStr.TempCompAtStart = 0;
			SaveDeviceConfig(MyFocuser1, MyRotator1);
			sendOutput("SET", cmd.source);
			break;	
		}	
		
		case CMD_SET_TCO:	// Set the TempCompCoefficient
		{
			int v = 0;
			char c = 0;
			
			// Make sure the command is for the focuser
			if(cmd.deviceType != 'F')
			{
				sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
				return;
			}
			
			// 1. Check if Offset designator is acceptable
			if(cmd.parameters[0] < 'A' || cmd.parameters[0] > 'E')
			{
				sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
				return;
			}
			// 2. Check for acceptable sign character
			c = cmd.parameters[1];
			if( (c != '0') && (c != '+') && (c != '1') && (c != '-'))
			{
				sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
				return;
			}	
			
			//3. Get the coefficient value
			v = getUnsignedIntFromString( &cmd.parameters[2], 4 );
			
			// 4. Check if the value is acceptable
			if ( v > 9999 )
			{
				sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
				return;
			}	
			
			// 5. Set the value
			if((c == '-') || (c == '1')) 
				v *= (-1);
			focuserPtr->tempCompInfoStr.TempCoeffs[cmd.parameters[0] - 'A'] = v;
			
			// 6. Flush the new config to NVM
			SaveDeviceConfig(MyFocuser1, MyRotator1);
			sendOutput("SET", cmd.source);
		}			
		break;
		
		case CMD_SET_BCE:		// Enable/Disable backlash compensation
			if(cmd.deviceType == 'F')
				focuserPtr->configStr.BacklashCompOn = (cmd.parameters[0] == '1') ? 1 : 0;	
			else 
				rotatorPtr->configStr.BacklashCompOn = (cmd.parameters[0] == '1') ? 1 : 0;
			
			// Store the new setting to NVM
			SaveDeviceConfig(MyFocuser1, MyRotator1);
			sendOutput("SET", cmd.source);
			break;
		
		case CMD_SET_BCS:		// Set Backlash compensation steps
			{
				int v = 0;

				// 2. Get the coefficient value
				v = getUnsignedIntFromString( &cmd.parameters[0], 2 );
				
				// 3. Check if the value is acceptable
				if ( v > 99 )
				{
					sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
					return;
				}
				// 4. Set the value in RAM
				if(cmd.deviceType == 'F')
					focuserPtr->configStr.BacklashCompSteps = (char)v;
				else 
					rotatorPtr->configStr.BacklashCompSteps = (char)v;
				// 5. Flush the new config value to NVM
				SaveDeviceConfig(MyFocuser1, MyRotator1);
				sendOutput("SET", cmd.source);
			}	
			break;
			
		case CMD_SET_HOMEONSTART:
			{
				if(cmd.parameters[0] != '1' && cmd.parameters[0] != '0')
				{
					sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
					return;
				}
				else
				{		
					if(cmd.deviceType == 'F')
						focuserPtr->configStr.HomeAtStart = cmd.parameters[0] - '0';
					else 
						rotatorPtr->configStr.HomeAtStart = cmd.parameters[0] - '0';
					SaveDeviceConfig(MyFocuser1, MyRotator1);
					sendOutput("SET", cmd.source);
				}	
					
			}
			break;	
		
		case CMD_SET_SPA_OFF:
			{
				DWORD newPos = 0;
				// Check the device type
				if(cmd.deviceType != 'F')
				{
					sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
					return;
				}		
				// Get the new offset as an integer
				newPos = getUnsignedIntFromString(&cmd.parameters[0], 6);
				// Make sure the sky pa offset is acceptable
				if(newPos > MAX_POS_ROTATOR)
				{
					sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
					return;
				}	
				MyRotator1.configStr.SkyPaOffset = newPos;
				SaveDeviceConfig(MyFocuser1, MyRotator1);
				sendOutput("SET", cmd.source);
			}		
			break;
			
		case CMD_SET_LED:
			{
				// 1. Get the value
				unsigned int v = getUnsignedIntFromString (cmd.parameters, 3 );
				// 2. Make sure it's in the acceptable range
				if ( v > 100 )
				{
					sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
					return;
				}
				// 3. Set the value in RAM to BOTH focusers
				MyFocuser1.configStr.LedBrightness = (unsigned char)v;
			
				// 4. Flush the new config value to NVM
				SaveDeviceConfig(MyFocuser1, MyRotator1);	// We only need to save Focuser 1 here because that is the one that gets checked during init.
				ResetLED();
				sendOutput("SET", cmd.source);
			}
			break;
			
		case CMD_SET_CP:
		{
			/*
			// Get the new position as an unsigned int
			WORD newPos = 0;
			newPos = getUnsignedIntFromString(cmd.parameters, 6);
			// Don't allow if focuser can home
			if(focuserPtr->motionInfoStr.CanHome)
			{
				sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
			}
			// Check if it's in the proper range.	
			else if(newPos > focuserPtr->motionInfoStr.MaxPosition)
			{
				sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
			}	
			else
			{
				FreezeStepper(focuserPtr->focuserNumber);
				focuserPtr->statusStr.CurrentPosition = newPos;
				focuserPtr->statusStr.TargetPosition = newPos;
				SaveCurrentPosition(focuserPtr);
				UnfreezeStepper(focuserPtr->focuserNumber);
			}	
			*/		
		}
		break;
			
		case CMD_FOC_RST_DEFAULTS:
		{
			//Ensure a version check failure
			ResetToDefaults(focuserPtr);
			//This function resets factory defaults on version check failure
			InitFocusingRotator(&MyFocuser1, &MyRotator1);
			
			sendOutput("SET", cmd.source);
		}
		break;
		
		case CMD_SET_SSID:
			{
				// Set the WiFi Network SSID--may have to send the key in chunks of 16 characters, numbered 0 and 1
				char index = cmd.parameters[0]-'0';
				if (cmd.parameters[1]-'0' > -1)
				{
					if ((index > -1) && (index < 2))
					{
						strcpy(((char*)&WiFiInfo.PendingSettings.MySSID+(16*index)), (cmd.parameters+1));
						WiFiInfo.PendingSettings.SsidLength = strlen((char *)WiFiInfo.PendingSettings.MySSID);	
						// Don't set ChangesArePendingHere we do that in the PUSH command
						sendOutput("SET", cmd.source);	
					}
					else
						sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
				}
				else
					sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source); //If we are trying to set the SSID, then the SSID needs to be at least 1 character long.
				break;
			}	
			
		case CMD_SET_SECMD:
			if(cmd.parameters[0] == 'A' || cmd.parameters[0] == 'B' || cmd.parameters[0] == 'C' || cmd.parameters[0] == 'D' || cmd.parameters[0] == 'E')
			{
			WiFiInfo.PendingSettings.SecurityMode = cmd.parameters[0];
			sendOutput("SET", cmd.source);
			}
			else
				sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
			break;
				
		case CMD_SET_SKEY:
			{
			// Set the WiFi Network Security Key--may have to send the key in chunks of 16 characters, numbered 0-3
				char index = cmd.parameters[0]-'0';
				if (cmd.parameters[1]-'0' > -1)
				{
					if ((index > -1) && (index < 4))
					{
						strcpy(((char*)&WiFiInfo.PendingSettings.SecurityKey+(16*index)), (cmd.parameters+1));
						WiFiInfo.PendingSettings.SecurityKeyLength = strlen((char *)WiFiInfo.PendingSettings.SecurityKey);	
						// Don't set ChangesArePendingHere we do that in the PUSH command
						sendOutput("SET", cmd.source);	
					}
					else
						sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
				}
				else
					sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source); //If we are trying to set the security key, then the key needs to be at least 1 character long.
				break;
			}	
		case CMD_SET_WEPI:
			{
			// Set the Key Index used for WEP security.
			char index = cmd.parameters[0]-'0';
			// The key index is a number between 1 and 4
			if ((index > 0) && (index < 5))
			{
				WiFiInfo.PendingSettings.WepKeyIndex = cmd.parameters[0];
				sendOutput("SET", cmd.source);
			}
			else
				sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
			break;
			}
		case CMD_GET_HUBINFO:
			{
			// Someone is requesting the WiFi Info
			prepareHubInfoString(longString);
			sendOutput(longString, cmd.source);
			break;
			}
		case CMD_WF_PUSH_SET:
			{
			if(WiFiInfo.WiFiHasCorrectFirmware)
			{	
				//Make sure that PendingSettings has all of the information it needs to change networks
				if(WiFiInfo.PendingSettings.SsidLength == 0 || WiFiInfo.PendingSettings.SecurityMode == 0)
					sendOutput(ERR_WIFI_INFO_INC, cmd.source);
				else if(WiFiInfo.PendingSettings.SecurityMode != 'A' && WiFiInfo.PendingSettings.SecurityKeyLength == 0)
					sendOutput(ERR_WIFI_INFO_INC, cmd.source);
				else if((WiFiInfo.PendingSettings.SecurityMode == 'D' || WiFiInfo.PendingSettings.SecurityMode == 'E') && WiFiInfo.PendingSettings.SecurityMode == 0)
					sendOutput(ERR_WIFI_INFO_INC, cmd.source);
				else 
				{
				strcpy((char*)&WiFiInfo.PendingSettings.Command, "STORE");	// Set the command
				WiFiInfo.ChangesArePending = 1;		// Alert the WiFi comm handler that a cmd is ready
				sendOutput("SET", cmd.source);
				}
			}
			else sendOutput(ERR_WIFI_COMM_BAD, cmd.source);
			break;
			}
		case CMD_WF_RST_DEFAULTS:
			{
			if(WiFiInfo.WiFiHasCorrectFirmware)
			{
				strcpy((char*)&WiFiInfo.PendingSettings.Command, "DEFAULTS");	// Set the command
				WiFiInfo.ChangesArePending = 1;		// Alert the WiFi comm handler that a cmd is ready
				sendOutput("SET", cmd.source);
			}
			else sendOutput(ERR_WIFI_COMM_BAD, cmd.source);
			break;
			}
		case CMD_WF_RESET:
			{
			if(WiFiInfo.WiFiHasCorrectFirmware)
			{		
				strcpy((char*)&WiFiInfo.PendingSettings.Command, "RESET");	// Set the command
				WiFiInfo.ChangesArePending = 1;		// Alert the WiFi comm handler that a cmd is ready
				sendOutput("SET", cmd.source);
			}
			else sendOutput(ERR_WIFI_COMM_BAD, cmd.source);
			break;
			}
		case CMD_DIAG_REPORT:
			{
			prepareDiagString(longString);
			sendOutput(longString, cmd.source);
			break;
			}
	}		
}	


char conditionsOkToStartMove(focusingRotatorCommand cmd)
{
	
	// Check if the device is in sleep mode
	if(HubInfo.InSleepMode)
	{
		sendOutput(ERR_DEVICE_SLEEPING, cmd.source);
		return 0;
	}
	if(cmd.deviceType == 'F')
	{
		if(MyFocuser1.statusStr.IsHoming)
		{
			sendOutput(ERR_DEVICE_IS_HOMING, cmd.source);
			return 0;
		}
	}	
	else if (cmd.deviceType == 'R')
	{
		if(MyRotator1.statusStr.IsHoming)
		{
			sendOutput(ERR_DEVICE_IS_HOMING, cmd.source);
			return 0;
		}
	}	
	else
	{
		sendOutput(ERR_UNACCEPTABLE_PRM, cmd.source);
		return 0;
	}		

	
	return 1;
}	


// ***** PRIVATE FUNCTIONS *************************************************************/

void sendOutput(char * text, CMD_SOURCE src)
{
	switch (src)
	{
		default:
		case NONE:	// This should never happen...
			#if defined (__DEBUG)
			while(1);	
			#endif
			break;
		case SERIAL:
			sendStringUART(text, 1);
			break;
		case HAND_CONTROL:
			sendStringUART_HC(text,1);
			break;
		case WIRED_ETHERNET:
			sendStringEthernet(text, 1);
			break;
		case WIFI:
			SendStringWiFiPassThru(text, 1);
			break;
		case WIRED_HTTP:
			// Do nothing here because the HTTP functionality doesn't require feedback.
		case WIFI_HTTP:
		 	// Do nothing here because the HTTP functionality doesn't require feedback.
		 	break;
		 
	}	
}	



void prepareConfigString ( char * strPtr, focuser focuserStr )
{
	char newLine[2] = {0};
	char boolString[2] = {0};
	char posString[7] = {0};
	newLine[0] = 10; 		// 0x10 = LineFeed

	strcat(strPtr, "CONFIG - FOC");
	strcat(strPtr, newLine);
	strcat(strPtr, "Nickname = ");
	strcat(strPtr, focuserStr.configStr.DeviceNickname);
	strcat(strPtr, newLine);
	strcat(strPtr, "Max Pos  = ");
	getUnsignedDecString(focuserStr.motionInfoStr.MaxPosition, posString, 6);
	strcat(strPtr, posString);
	strcat(strPtr, newLine);
//	strcat(strPtr, "Max Spd  = ");
//	getUnsignedDecString(focuserStr.motionInfoStr.HighSpeed, posString, 4);
//	strcat(strPtr, posString);
//	strcat(strPtr, newLine);
//	strcat(strPtr, "Max Pwr  = ");
//	getUnsignedDecString(focuserStr.motionInfoStr.MotorCurrentHigh, posString, 3);
//	strcat(strPtr, posString);
//	strcat(strPtr, newLine);
	strcat(strPtr, "Dev Typ  = ");
	strncat(strPtr, &focuserStr.configStr.DeviceType, 1);
	strcat(strPtr, newLine);
	strcat(strPtr, "TComp ON = ");
	boolString[0] = focuserStr.tempCompInfoStr.TempCompOn + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newLine);
	strcat(strPtr, "TempCo A = ");
	getSignedDecString(focuserStr.tempCompInfoStr.TempCoeffs[0], posString, 4);
	strcat(strPtr, posString);
	strcat(strPtr, newLine);
	strcat(strPtr, "TempCo B = ");
	getSignedDecString(focuserStr.tempCompInfoStr.TempCoeffs[1], posString, 4);
	strcat(strPtr, posString);
	strcat(strPtr, newLine);
	strcat(strPtr, "TempCo C = ");
	getSignedDecString(focuserStr.tempCompInfoStr.TempCoeffs[2], posString, 4);
	strcat(strPtr, posString);
	strcat(strPtr, newLine);
	strcat(strPtr, "TempCo D = ");
	getSignedDecString(focuserStr.tempCompInfoStr.TempCoeffs[3], posString, 4);
	strcat(strPtr, posString);
	strcat(strPtr, newLine);
	strcat(strPtr, "TempCo E = ");
	getSignedDecString(focuserStr.tempCompInfoStr.TempCoeffs[4], posString, 4);
	strcat(strPtr, posString);
	strcat(strPtr, newLine);
	strcat(strPtr, "TC Mode  = ");
	strncat(strPtr, &focuserStr.tempCompInfoStr.TempCompMode, 1);
	strcat(strPtr, newLine);
	strcat(strPtr, "BLC En   = ");
	boolString[0] = focuserStr.configStr.BacklashCompOn + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newLine);
	strcat(strPtr, "BLC Stps = ");
	getSignedDecString(focuserStr.configStr.BacklashCompSteps, posString, 2);
	strcat(strPtr, posString);
	strcat(strPtr, newLine);
	strcat(strPtr, "LED Brt  = ");
	getUnsignedDecString(focuserStr.configStr.LedBrightness, posString, 3);
	strcat(strPtr, posString);
	strcat(strPtr, newLine);
	strcat(strPtr, "TC@Start = ");
	boolString[0] = focuserStr.configStr.TempCompAtStart + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newLine);
	strcat(strPtr, "END");
		
}	

void prepareConfigStringRot (char * strPtr, rotator rotatorStr)
{
	char newLine[2] = {0};
	char boolString[2] = {0};
	char posString[7] = {0};
	newLine[0] = 10; 		// 0x10 = LineFeed
	
	strcat(strPtr, "CONFIG - ROT");
	strcat(strPtr, newLine);
	strcat(strPtr, "Nickname = ");
	strcat(strPtr, rotatorStr.configStr.DeviceNickname);
	strcat(strPtr, newLine);
	strcat(strPtr, "Max Pos  = ");
	getUnsignedDecString(rotatorStr.motionInfoStr.MaxPosition, posString, 6);
	strcat(strPtr, posString);
	strcat(strPtr, newLine);
	strcat(strPtr, "BLC En   = ");
	boolString[0] = rotatorStr.configStr.BacklashCompOn + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newLine);
	strcat(strPtr, "BLC Stps = ");
	getSignedDecString(rotatorStr.configStr.BacklashCompSteps, posString, 2);
	strcat(strPtr, posString);
	strcat(strPtr, newLine);
	strcat(strPtr, "SkyPAOff = ");
	getSignedDecString(rotatorStr.configStr.SkyPaOffset, posString, 6);
	strcat(strPtr, posString);
	strcat(strPtr, newLine);
	strcat(strPtr, "Home@Str = ");
	boolString[0] = rotatorStr.configStr.HomeAtStart + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newLine);
	strcat(strPtr, "Reverse  = ");
	boolString[0] = rotatorStr.configStr.Reverse + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newLine);
	strcat(strPtr, "END");
	
}	
void prepareStatusString( char * strPtr, focuser focuserStr)
{
	char newline[2] = {10,0};
	char tempString[6] = {0};
	char posString[6] = {0};
	char boolString[2] = {0};
	
	strcat(strPtr, "STATUS - FOC");
	strcat(strPtr, newline);
	strcat(strPtr, "Temp(C)  = ");
	if(focuserStr.statusStr.TempProbeAttached)
	{
		getTempString(focuserStr.statusStr.CurrentTemp, tempString);
		strcat(strPtr, tempString);	
	}
	else strcat(strPtr, "NP");
	strcat(strPtr, newline);
	strcat(strPtr, "Curr Pos = ");
	getUnsignedDecString(focuserStr.statusStr.CurrentPosition, posString, 6);
	strcat(strPtr, posString);
	strcat(strPtr, newline);
	strcat(strPtr, "Targ Pos = ");
	getUnsignedDecString(focuserStr.statusStr.TargetPosition, posString, 6);
	strcat(strPtr, posString);
	strcat(strPtr, newline);
	strcat(strPtr, "IsMoving = ");
	boolString[0] = focuserStr.statusStr.IsMoving + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newline);
	strcat(strPtr, "IsHoming = ");
	boolString[0] = focuserStr.statusStr.IsHoming + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newline);
	strcat(strPtr, "IsHomed  = ");
	boolString[0] = focuserStr.statusStr.IsHomed + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newline);
	
	strcat(strPtr, "TmpProbe = ");
	boolString[0] = focuserStr.statusStr.TempProbeAttached + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newline);
	strcat(strPtr, "RemoteIO = ");
	boolString[0] = focuserStr.statusStr.RemoteInOutAttached + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newline);
	strcat(strPtr, "Hnd Ctlr = ");
	boolString[0] = focuserStr.statusStr.HandControllerAttached + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newline);
	strcat(strPtr, "END");
}		
	
void prepareStatusStringRot(char * strPtr, rotator rotatorStr)
{
	char newline[2] = {10,0};
//	char tempString[6] = {0};
	char posString[6] = {0};
	char boolString[2] = {0};
	
	strcat(strPtr, "STATUS - ROT");
	strcat(strPtr, newline);
	strcat(strPtr, "Curr Pos = ");
	getUnsignedDecString(rotatorStr.statusStr.CurrentPosition, posString, 6);
	strcat(strPtr, posString);
	strcat(strPtr, newline);
	strcat(strPtr, "Targ Pos = ");
	getUnsignedDecString(rotatorStr.statusStr.TargetPosition, posString, 6);
	strcat(strPtr, posString);
	strcat(strPtr, newline);
	strcat(strPtr, "IsMoving = ");
	boolString[0] = rotatorStr.statusStr.IsMoving + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newline);
	strcat(strPtr, "IsHoming = ");
	boolString[0] = rotatorStr.statusStr.IsHoming + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newline);
	strcat(strPtr, "IsHomed  = ");
	boolString[0] = rotatorStr.statusStr.IsHomed + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newline);
	strcat(strPtr, "END");
	
}	
void prepareHubInfoString( char * strPtr)
{
	char newline[2] = {10,0};
	char boolString[2] = {0};
	char tempString[16] = {FIRMWARE_VERSION_MAJOR, '.', FIRMWARE_VERSION_MINOR, '.', FIRMWARE_VERSION_REVISION};
	char wfFirmString[16] = {WiFiInfo.CurrentSettings.FirmwareVersion[0], '.', WiFiInfo.CurrentSettings.FirmwareVersion[1], '.', 
							 WiFiInfo.CurrentSettings.FirmwareVersion[2]};
	
	strcat(strPtr, "HUB INFO");
	strcat(strPtr, newline);
	strcat(strPtr, "Hub FVer = ");
	strcat(strPtr, tempString);		// tempString is initialized with the firmware version
	strcat(strPtr, newline);
	strcat(strPtr, "Sleeping = ");
	boolString[0] = HubInfo.InSleepMode + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newline);
	strcat(strPtr, "Wired IP = ");
	GetIPString(AppConfig.MyIPAddr, tempString);
	strcat(strPtr, tempString);
	strcat(strPtr, newline);
	strcat(strPtr, "WF Atchd = ");
	boolString[0] = WiFiInfo.WiFiModuleAttached + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newline);
	strcat(strPtr, "WF Conn  = ");
	boolString[0] = WiFiInfo.CurrentSettings.WiFiConnectedToNetwork + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newline);
	strcat(strPtr, "WF FVer  = ");
	strcat(strPtr, wfFirmString);
	strcat(strPtr, newline);
	strcat(strPtr, "WF FV OK = ");
	boolString[0] = WiFiInfo.WiFiHasCorrectFirmware + '0';
	strcat(strPtr, boolString);
	strcat(strPtr, newline);
	strcat(strPtr, "WF SSID  = ");
	strcat(strPtr, (char*)WiFiInfo.CurrentSettings.MySSID);
	strcat(strPtr, newline);
	strcat(strPtr, "WF IP    = ");
	GetIPString(WiFiInfo.CurrentSettings.MyIPAddr, tempString);
	strcat(strPtr, tempString);
	strcat(strPtr, newline);
//	strcat(strPtr, "WF SSLen = ");
//	uitoa( (unsigned int) WiFiInfo.CurrentSettings.SsidLength, (BYTE*)tempString);	
//	strcat(strPtr, tempString);
//	strcat(strPtr, newline);
	strcat(strPtr, "WF SecMd = ");
	if (WiFiInfo.CurrentSettings.SecurityMode == 0)//Need to translate between front-end indices (A-E) and back-end indices (0-8)
		boolString[0] = 'A';	
	else if (WiFiInfo.CurrentSettings.SecurityMode == 8)
		boolString[0] = 'B';
	else if (WiFiInfo.CurrentSettings.SecurityMode == 7)
		boolString[0] = 'C';
	else if (WiFiInfo.CurrentSettings.SecurityMode == 1)
		boolString[0] = 'D';	
	else if (WiFiInfo.CurrentSettings.SecurityMode == 2)
		boolString[0] = 'E';
	strcat(strPtr, boolString);
	strcat(strPtr, newline);
	strcat(strPtr, "WF SecKy = ");
	strcat(strPtr, (char*) WiFiInfo.CurrentSettings.SecurityKey);
	strcat(strPtr, newline);
//	strcat(strPtr, "WF SecKL = ");
//	uitoa( (unsigned int) WiFiInfo.CurrentSettings.SecurityKeyLength, (BYTE*)tempString);
//	strcat(strPtr, tempString);	
//	strcat(strPtr, newline);
	strcat(strPtr, "WF WepKI = ");
	boolString[0] = (char)WiFiInfo.CurrentSettings.WepKeyIndex + '0';	// use bool string b/c already null terminated!
	strcat(strPtr, boolString);
	strcat(strPtr, newline);
	strcat(strPtr, "END");
}	
void prepareDiagString( char * strPtr)
{
	
	char newline[2] = {10,0};
//	char boolString[2] = {0};
	//char tempString[16] = {0};

	strcat(strPtr, "DIAG. REPORT");
	strcat(strPtr, newline);
/*
	strcat(strPtr, "TC Pos Off. 1 = ");
	uitoa( (unsigned int) MyFocuser1.tempCompInfoStr.LastTempCompStartPosOffset, (BYTE*)tempString);
	strcat(strPtr, tempString);
	strcat(strPtr, newline);
	strcat(strPtr, "TC Pos 1 = ");
	strcat(strPtr, newline);
	strcat(strPtr, "TC Tem Off. 1 = ");
	uitoa( (unsigned int) MyFocuser1.tempCompInfoStr.LastTempCompStartTempOffset, (BYTE*)tempString);
	strcat(strPtr, tempString);
	strcat(strPtr, newline);
	strcat(strPtr, "TC Tem 1 = ");
	strcat(strPtr, newline);
	strcat(strPtr, "TC Pos Off. 2 = ");
	uitoa( (unsigned int) MyFocuser2.tempCompInfoStr.LastTempCompStartPosOffset, (BYTE*)tempString);
	strcat(strPtr, tempString);
	strcat(strPtr, newline);
	strcat(strPtr, "TC Pos 2 = ");
	strcat(strPtr, newline);
	strcat(strPtr, "TC Tem Off. 2 = ");
	uitoa( (unsigned int) MyFocuser2.tempCompInfoStr.LastTempCompStartTempOffset, (BYTE*)tempString);
	strcat(strPtr, tempString);
	strcat(strPtr, newline);
	strcat(strPtr, "TC Tem 2 = ");
	strcat(strPtr, newline);
	strcat(strPtr, "Lst Pos Off1 = ");
	uitoa( (unsigned int) MyFocuser1.statusStr.LastSavedPositionOffset, (BYTE*)tempString);
	strcat(strPtr, tempString);
	strcat(strPtr, newline);
	strcat(strPtr, "Lst Pos 1 = ");
	uitoa( (unsigned int) MyFocuser1.statusStr.LastSavedPosition, (BYTE*)tempString);
	strcat(strPtr, tempString);
	strcat(strPtr, newline);
	strcat(strPtr, "Lst Pos Off2 = ");
	uitoa( (unsigned int) MyFocuser2.statusStr.LastSavedPositionOffset, (BYTE*)tempString);
	strcat(strPtr, tempString);
	strcat(strPtr, newline);
	strcat(strPtr, "Lst Pos 2 = ");
	uitoa( (unsigned int) MyFocuser2.statusStr.LastSavedPosition, (BYTE*)tempString);
	strcat(strPtr, tempString);
	strcat(strPtr, newline);
*/
	strcat(strPtr, "END");
	
}	
void getTempString(SHORT temp, char * tempString)
{
	if(temp < 0)
	{
		tempString[0] = '-';
		temp *= (-1);
	}
	else	
	tempString[0] =  '+' ;
	tempString[1] = (temp/100) + '0';
	temp = temp - (temp/100)*100;
	tempString[2] = (temp/10) + '0';
	tempString[3] = '.';
	temp = temp - (temp/10) * 10;
	tempString[4] = temp + '0';
	tempString[5] = 0;
}

void getSignedDecString(LONG pos, char * posString, char n)
{
	int i = 0;
	
	if(pos < 0)
	{ 
		pos *= (-1);
		posString[i++] = '-';
	}	
	else posString[i++] = '+';
	
	switch (n)
	{
		case 6:
			posString[i++] = (pos/100000) + '0';
			pos = pos - (pos/100000)*100000;
		case 5:
			posString[i++] = (pos/10000) + '0';
			pos = pos - (pos/10000)*10000;
		case 4:
			posString[i++] = (pos/1000) + '0';
			pos = pos - (pos/1000)*1000;
		case 3:
			posString[i++] = (pos/100) + '0';
			pos = pos - (pos/100)*100;		
		case 2:
			posString[i++] = (pos/10) + '0';
			pos = pos - (pos/10)*10;
		case 1:
			posString[i++] = pos + '0';
		default:
			posString[i] = 0;
		break;
	}
}

void getUnsignedDecString(DWORD pos, char * posString, char n)
{
	int i = 0;
	switch (n)
	{
		case 6: 
			posString[i++] = (pos/100000) + '0';
			pos = pos - (pos/100000)*100000;
		case 5:
			posString[i++] = (pos/10000) + '0';
			pos = pos - (pos/10000)*10000;
		case 4:
			posString[i++] = (pos/1000) + '0';
			pos = pos - (pos/1000)*1000;
		case 3:
			posString[i++] = (pos/100) + '0';
			pos = pos - (pos/100)*100;
		case 2:
			posString[i++] = (pos/10) + '0';
			pos = pos - (pos/10)*10;
		case 1:
			posString[i++] = pos + '0';
		default:
			posString[i] = 0;
		break;
	}
}

WORD getUnsignedIntFromString( char * string, char strSize)
{
	char *end;
	return (WORD)strtoul(string, &end, 10);
}	

void DoFocuserOperations(void)
{
	static enum doFocuserOpsState{
		GETTEMP1,
		PROCESS_BTN_PRESS1,
		DO_TEMP_COMP1,
	} DoFocuserOpsState;
	
	ProcessDinInData(&MyFocuser1.inputDeviceStr);

	switch (DoFocuserOpsState++)
	{	
		default:
			DoFocuserOpsState = GETTEMP1;
		case GETTEMP1:
				CalculateTemp(&MyFocuser1);
			break;
		case PROCESS_BTN_PRESS1:
			CheckRemoteInOutPress(&MyFocuser1);
			break;
		case DO_TEMP_COMP1:
			DoTempComp(&MyFocuser1);
			break;	
	}	
	
	FocuserMotionStateMachine(&MyFocuser1);	
}	



void CalculateTemp(focuser * focuserPtr)
{
	float avg;
	int i;
	unsigned int t;
	
		
	// Calculate process the temp data and update the current temperature

	if(focuserPtr->inputDeviceStr.AttachmentState != ATTACHED)
	{ 
		focuserPtr->statusStr.TempProbeAttached = 0;
		focuserPtr->statusStr.RemoteInOutAttached = 0;
		focuserPtr->inputDeviceStr.DutyCycleBufferCount = 0;
		return;
	}	
	else if(focuserPtr->inputDeviceStr.AttachedDevice == TEMP_PROBE)
	{
		if(focuserPtr->inputDeviceStr.DutyCycleBufferCount < DUTYS_TO_AVERAGE )
		{
			if(focuserPtr->inputDeviceStr.CurrentDutyCycle != focuserPtr->inputDeviceStr.LastDutyCycle) 
			{
				focuserPtr->inputDeviceStr.LastDutyCycle = focuserPtr->inputDeviceStr.CurrentDutyCycle;
				focuserPtr->inputDeviceStr.DutyCycleArray[focuserPtr->inputDeviceStr.DutyCycleBufferCount++] = 
				focuserPtr->inputDeviceStr.CurrentDutyCycle * 10000 ;
			}	
		}	
		else 
		{
			// Find the average of the duty cycles	
			avg = 0;
			for(i = 0; i < DUTYS_TO_AVERAGE; i++)
			{
				avg += focuserPtr->inputDeviceStr.DutyCycleArray[i];
			}	
			avg /= DUTYS_TO_AVERAGE;
				
			focuserPtr->inputDeviceStr.DutyCycleBufferCount = 0;
			t = (int)avg * 4;
			t /= 10;
			focuserPtr->inputDeviceStr.CurrentTempX10 = 2350 - t;
			
			// Set the status information
			focuserPtr->statusStr.CurrentTemp = focuserPtr->inputDeviceStr.CurrentTempX10;
			focuserPtr->statusStr.TempProbeAttached = 1;
			focuserPtr->statusStr.RemoteInOutAttached = 0;
		

		}	
	}
	else 
		focuserPtr->statusStr.TempProbeAttached = 0;		
}	


void CheckRemoteInOutPress(focuser * focuserPtr)
{
	
	#define STATE				focuserPtr->inputDeviceStr.RemoteState
	#define PERIOD 				focuserPtr->inputDeviceStr.Period
	#define IN_IS_PRESSED()		(PERIOD < 575)
	#define OUT_IS_PRESSED()	(PERIOD > 725)
	
	if(focuserPtr->inputDeviceStr.AttachedDevice != IN_OUT_REMOTE)
	{
		focuserPtr->statusStr.RemoteInOutAttached = 0;
		STATE = NO_PRESS;
		return;	
	}
	else
	{
		// While the device is homing disregard remote button presses.
		if(focuserPtr->statusStr.IsHoming) 
			return;
			
		switch (STATE)
		{
			default:
			case NO_PRESS:
				if(IN_IS_PRESSED())
				{
				//	RequestDIN_InputStartMoveIN(focuserPtr);
					STATE = IN;
				}
				else if (OUT_IS_PRESSED())
				{
				//	RequestDIN_InputStartMoveOUT(focuserPtr);
					STATE = OUT;
				}		
				break;
			case IN:
				if(!IN_IS_PRESSED())
					STATE = NO_PRESS;
				break;
			case OUT:
				if(!OUT_IS_PRESSED())
					STATE = NO_PRESS;
				break;
		}	
	}	
	
	/*
	// Make sure a remote is attached.
	if(focuserStr.inputDeviceStr.attachedDevice != IN_OUT_REMOTE)
	{
		focuserStr.statusStr.RemoteInOutAttached = 0;
		STATE = SM_NO_PRESS;
		return;	
	}		
	
	switch(STATE)
	{
		case SM_NO_PRESS:
			focuserStr.statusStr.RemoteInOutAttached = 1;
			if(BTN_IS_PRESSED())
			{
				START_TIME = TickGet();
				
				if(IN_IS_PRESSED() && CURRENT_POS != 0)
				{
					RequestAbsoluteMove(CURRENT_POS - 1 );
				}
				else if(OUT_IS_PRESSED() && (CURRENT_POS < focuserPtr->motionInfoStr.MaxPosition))
				{
					RequestAbsoluteMove(CURRENT_POS + 1 );
				}	
					
				STATE = SM_PRESS_INITIAL;
			}	
			break;
			
		case SM_PRESS_INITIAL:
			if(!BTN_IS_PRESSED())
			{	// Button is released
				STATE = SM_NO_PRESS;
			}	
			else if((TickGet() - START_TIME) > (TICKS_PER_SECOND/2))
			{	
				// Speed is already set to low...
				STATE = SM_PRESS_SHORT;	
				
				PRESS_COUNT	 = 0;
			}	
			break;
			
		case SM_PRESS_SHORT:
		{
			
			if(!BTN_IS_PRESSED())
			{	// Button is released. Stop moving.
				TARGET_POS = CURRENT_POS;
				STATE = SM_NO_PRESS;
				PRESS_COUNT	= 0;
			}	
			else
			{
				//if((TickGet() - START_TIME) > (TICKS_PER_SECOND * 3))
				if(++PRESS_COUNT == 600)
				{
					// Set the speed to the fastest setting
					SetSpeedHIGH(focuserStr.motionInfoStr);
					STATE = SM_PRESS_LONG;
					PRESS_COUNT = 0;
				}	
				else if(CURRENT_POS == TARGET_POS)
				{
					if(IN_IS_PRESSED())
						TARGET_POS -= 10;
					else
						TARGET_POS += 10;	
				}	
			}
			break;
		}	
		
		case SM_PRESS_LONG:
			if(!BTN_IS_PRESSED())
			{	// Button is released. Stop moving.
				TARGET_POS = CURRENT_POS;
				STATE = SM_NO_PRESS;
			}		
			else if(CURRENT_POS == TARGET_POS)
			{
				if(IN_IS_PRESSED())
					TARGET_POS -= 10;
				else
					TARGET_POS += 10;	
			}	
			break;
	}	
	*/

	/*
	switch (RemoteState)
	{
		case SM_NO_PRESS:
			if( focuserPtr.
	}	
	*/	
	
	/*
	else if (dev.attachedDevice == IN_OUT_REMOTE)
	{
		
		if(dev.focuserIdentifier == 1)
		{
			MyFocuser1.statusStr.RemoteInOutAttached = 1;
			MyFocuser1.statusStr.TempProbeAttached = 0;
			// Check if a button is pressed
			if(dev.period < 225) MyFocuser1.statusStr.TargetPosition--;
			else if (dev.period > 275) MyFocuser1.statusStr.TargetPosition++;
		}	
		else
		{
			MyFocuser2.statusStr.RemoteInOutAttached = 1;
			MyFocuser2.statusStr.TempProbeAttached = 0;
			// Check if a button is pressed
			if(dev.period < 225) MyFocuser2.statusStr.TargetPosition--;
			else if (dev.period > 275) MyFocuser2.statusStr.TargetPosition++;
		}	
	}
	*/
}	


void GetIPString(IP_ADDR ip, char* dest)
{
	char digits[4];	
	*dest = 0;
	uitoa(ip.v[0], (BYTE*)digits);
	strcat(dest, digits);
	strcat(dest, ".");
	uitoa(ip.v[1], (BYTE*)digits);
	strcat(dest, digits);
	strcat(dest, ".");
	uitoa(ip.v[2], (BYTE*)digits);
	strcat(dest, digits);
	strcat(dest, ".");
	uitoa(ip.v[3], (BYTE*)digits);
	strcat(dest, digits);
}

/*
void CheckHomeSwitch(char foc)
{
//	char oscillating = 0; 
//	char totalTime = 0;

	//If Focuser 1
	if(focuserPtr == &MyFocuser1)
	{
		char focuserInput = HomeSwitch1Input; 
		//Find out whether the signal is oscillating
		while (totalTime < 4)
		{
			DelayMs(1);
			totalTime += 1;
			if(HomeSwitch1Input != focuserInput)
			{
				oscillating = 1;
				break;
			}
		}
		if(oscillating)
		{
			focuserPtr->statusStr.FastFocusAtHomeSw = 0;
			focuserPtr->statusStr.FastFocusDetected = 1;
		}
		else
		{
			if(HomeSwitch1Input == 1)
			{
				focuserPtr->statusStr.FastFocusAtHomeSw = 1;
				focuserPtr->statusStr.FastFocusDetected = 1;
			}
			else
			{
				focuserPtr->statusStr.FastFocusAtHomeSw = 0;
				focuserPtr->statusStr.FastFocusDetected = 0;
			}		
		}
	}
	//If Focuser 2
	else if (focuserPtr == &MyFocuser2)
	{
		char focuserInput = HomeSwitch2Input; 
		//Find out whether the signal is oscillating
		while (totalTime < 4)
		{
			DelayMs(1);
			totalTime += 1;
			if(HomeSwitch2Input != focuserInput)
			{
				oscillating = 1;
				break;
			}
		}
		if(oscillating)
		{
			focuserPtr->statusStr.FastFocusAtHomeSw = 0;
			focuserPtr->statusStr.FastFocusDetected = 1;
		}
		else
		{
			if(HomeSwitch2Input == 1)
			{
				focuserPtr->statusStr.FastFocusAtHomeSw = 1;
				focuserPtr->statusStr.FastFocusDetected = 1;
			}
			else
			{
				focuserPtr->statusStr.FastFocusAtHomeSw = 0;
				focuserPtr->statusStr.FastFocusDetected = 0;
			}		
		}		
	}
	

}

*/
