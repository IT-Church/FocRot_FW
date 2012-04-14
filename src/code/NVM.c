// NVM.c
// Contains functions for storing and retrieving data from non-volatile memory

#include "NVM.h"
#include "HardwareProfile.h"
#include "GenericTypeDefs.h"

#include <string.h>

#define NVM_START_ADDR					1

#define SEE_WRSR						1
#define SEE_WRITE						2
#define SEE_READ						3
#define SEE_WDI							4
#define SEE_STAT						5
#define SEE_WEN							6
#define SPI_MASTER						0x0122
#define SPI_ENABLE						0x8000
#define CURRENT_VERSION					4

// Private (local) function prototypes
void readDeviceSettingsFromNVM (unsigned char addr);
void setupSPI();
unsigned char readSR();
unsigned char writeEEP_SPI( unsigned char data);
unsigned char ReadNVM( unsigned char address);
void writeEnable(void);
void writeNVM(unsigned char address, unsigned char data);
void saveDeviceSettingsToNVM();

// This struct defines the structure of the focuser settings in NVM.
typedef struct __attribute__((__packed__)) 
{
	int versionNum;
	char lastMagEnterDir;
	char lastMagExitDir;
	char ledBrightness;	
	
	char deviceTypeFoc;	
	char deviceNicknameFoc[17];
	WORD backlashStepsFoc;
	char tempCompMode;
	int tempCoeffs[5];
	unsigned char lastTempCompPosOffset;
	DWORD  lastTempCompPosition[5];
	unsigned char lastTempCompTempOffset;
	int  lastTempCompTemperature[5];
	unsigned char lastPhysicalPositionMemOffsetFoc;
	DWORD lastPhysicalPositionFoc[5];
	
	char deviceNicknameRot[17];
	BYTE backlashStepsRot;
	unsigned char lastPhysicalPositionMemOffsetRot;
	DWORD lastPhysicalPositionRot[5];
	LONG skyPaOffset;
	
	// Flags
	unsigned char tempCompEnabled:1;
	unsigned char tempCompAtStart:1;
	unsigned char backlashCompEnabledFoc:1;
	unsigned char backlashCompEnabledRot:1;
	unsigned char rotatorReverse:1;
	unsigned char homeOnStartRot:1;
	unsigned char homeOnStartFoc:1;
	unsigned char rotatorIsHomed:1;
	
	unsigned char focuserIsHomed:1;
	unsigned char unused2:1;
	unsigned char unused3:1;
	unsigned char unused4:1;
	unsigned char unused5:1;
	unsigned char unused6:1;
	unsigned char unused7:1;
	unsigned char unused8:1;
	
}settings;

static union byteArray
{
	unsigned char bytes[sizeof(settings)];
	settings Settings;	
} DeviceSettings;

// Summary:
//   This function reads the Non-volatile focusing rotator settings from EEPROM
//   If the lock password is not read from memory the values have not been stored yet
//   thus the default values must be loaded. This function returns 1 if that is the case.
//   If the lock password is found, this function will load the read data into the focuser
//   structure and return 0.
char LoadConfigFromNVM(focuser * focuserPtr, rotator * rotatorPtr)
{
	// Setup the SPI peripheral for communication
	// We have to do this because we arn't the only ones using the SPI!
	setupSPI();
	
	// Read the data from EEPROM
	readDeviceSettingsFromNVM(NVM_START_ADDR);
	
	// Check if the lock code is found.
	if(DeviceSettings.Settings.versionNum != CURRENT_VERSION)
		return 1;
	else
	{	// Valid data has been found
		
		// Load the device nickname for the focuser
		memcpy(&focuserPtr->configStr.DeviceNickname[0], &DeviceSettings.Settings.deviceNicknameFoc[0], 17);
		// Load the temperature coefficients
		memcpy(&focuserPtr->tempCompInfoStr.TempCoeffs[0], &DeviceSettings.Settings.tempCoeffs[0],10);
		// Load the current temperature compensation mode
		focuserPtr->tempCompInfoStr.TempCompMode = DeviceSettings.Settings.tempCompMode;
		// Load the temp comp enabled
		focuserPtr->tempCompInfoStr.TempCompOn = DeviceSettings.Settings.tempCompEnabled;
		focuserPtr->tempCompInfoStr.ResetRequired = 1;
		// Load the device type
	 	focuserPtr->configStr.DeviceType = DeviceSettings.Settings.deviceTypeFoc;
	 	// Load the IsHomed flag for the focuser
	 	focuserPtr->statusStr.IsHomed = DeviceSettings.Settings.focuserIsHomed;
		// Load the Backlash Compensation Steps for the focuser
	 	focuserPtr->configStr.BacklashCompSteps = DeviceSettings.Settings.backlashStepsFoc;
		// Load the Backlash Compensation On flag for the focuser
	 	focuserPtr->configStr.BacklashCompOn = DeviceSettings.Settings.backlashCompEnabledFoc;
		// Load the LastSavedPositionOffset value for the focuser
	 	focuserPtr->statusStr.LastSavedPositionOffset = DeviceSettings.Settings.lastPhysicalPositionMemOffsetFoc;
	 	// Load the LastSavedPositon value for the focuser
	    focuserPtr->statusStr.LastSavedPosition = DeviceSettings.Settings.lastPhysicalPositionFoc[focuserPtr->statusStr.LastSavedPositionOffset];
	    // Load the lastTempCompStartTempOffset value
	    focuserPtr->tempCompInfoStr.LastTempCompStartTempOffset = DeviceSettings.Settings.lastTempCompTempOffset;
	    // Load the lastTempCompStartTemp value
	    focuserPtr->tempCompInfoStr.LastTempCompStartTemp = DeviceSettings.Settings.lastTempCompTemperature[focuserPtr->tempCompInfoStr.LastTempCompStartTempOffset];
	    // Load the lastTempCompStartPosOffset value
	    focuserPtr->tempCompInfoStr.LastTempCompStartPosOffset = DeviceSettings.Settings.lastTempCompPosOffset;
	    // Load the lastTempCompStartPos value
	    focuserPtr->tempCompInfoStr.LastTempCompStartPos = DeviceSettings.Settings.lastTempCompPosition[focuserPtr->tempCompInfoStr.LastTempCompStartPosOffset];
		// Load the tempCompAtStart flag
		focuserPtr->configStr.TempCompAtStart = DeviceSettings.Settings.tempCompAtStart;
		// Load the focuser home on start flag
		focuserPtr->configStr.HomeAtStart = DeviceSettings.Settings.homeOnStartFoc;
		
		// Load the device nickname for the rotator
		memcpy(&rotatorPtr->configStr.DeviceNickname[0], &DeviceSettings.Settings.deviceNicknameRot[0], 17);
	 	// Load the IsHomed flag for the rotator
	 	rotatorPtr->statusStr.IsHomed = DeviceSettings.Settings.rotatorIsHomed;	
	 	// Load the Backlash Compensation Steps for the rotator
	 	rotatorPtr->configStr.BacklashCompSteps = DeviceSettings.Settings.backlashStepsRot; 	
	 	// Loas the Backlash Compensation On flag for the rotator
	 	rotatorPtr->configStr.BacklashCompOn = DeviceSettings.Settings.backlashCompEnabledRot;
	 	// Load the LastSavedPositionOffset value for the rotator
	 	rotatorPtr->statusStr.LastSavedPositionOffset = DeviceSettings.Settings.lastPhysicalPositionMemOffsetRot;
	    // Load the LastSavedPositon value for the rotator
	    rotatorPtr->statusStr.LastSavedPosition = DeviceSettings.Settings.lastPhysicalPositionRot[rotatorPtr->statusStr.LastSavedPositionOffset];
		// Load the rotator reverse flag
		rotatorPtr->configStr.Reverse = DeviceSettings.Settings.rotatorReverse;
		// Load the home at start flag
		rotatorPtr->configStr.HomeAtStart = DeviceSettings.Settings.homeOnStartRot;
		// Load the SkyPaOffset
		rotatorPtr->configStr.SkyPaOffset = DeviceSettings.Settings.skyPaOffset;
		// Load the last magnet states
		rotatorPtr->motionInfoStr.LastMagEnterDir = DeviceSettings.Settings.lastMagEnterDir;
		rotatorPtr->motionInfoStr.LastMagExitDir = DeviceSettings.Settings.lastMagExitDir;
		
		// Load the LED Brightness value
	 	focuserPtr->configStr.LedBrightness = DeviceSettings.Settings.ledBrightness;
		
		return 0;	
	}		
}


void readDeviceSettingsFromNVM (unsigned char addr)
{
	// Read the data from the EEPROM into the FocuserSettings Struct
	int i;
	char c;
	unsigned int size = sizeof(settings);
	for (i = 0; i < size; i++)
	{
		 c = ReadNVM( addr + i);
		 DeviceSettings.bytes[i] = c;
	}	
}

void SaveDeviceConfig(focuser focuserStr, rotator rotatorStr)
{
	// Load all of the physical position bits with 1's first to prolong life of Memory
	DeviceSettings.Settings.lastPhysicalPositionFoc[0] = 0xFFFFFFFF;
	DeviceSettings.Settings.lastPhysicalPositionFoc[1] = 0xFFFFFFFF;
	DeviceSettings.Settings.lastPhysicalPositionFoc[2] = 0xFFFFFFFF;
	DeviceSettings.Settings.lastPhysicalPositionFoc[3] = 0xFFFFFFFF;
	DeviceSettings.Settings.lastPhysicalPositionFoc[4] = 0xFFFFFFFF;
	DeviceSettings.Settings.lastPhysicalPositionFoc[focuserStr.statusStr.LastSavedPositionOffset] = 
		focuserStr.statusStr.CurrentPosition;
	DeviceSettings.Settings.lastPhysicalPositionMemOffsetFoc = focuserStr.statusStr.LastSavedPositionOffset;
	DeviceSettings.Settings.lastTempCompPosOffset = focuserStr.tempCompInfoStr.LastTempCompStartPosOffset;
	DeviceSettings.Settings.lastTempCompTempOffset = focuserStr.tempCompInfoStr.LastTempCompStartTempOffset;
	DeviceSettings.Settings.tempCompEnabled = focuserStr.tempCompInfoStr.TempCompOn;
	memcpy(&DeviceSettings.Settings.deviceNicknameFoc[0],&focuserStr.configStr.DeviceNickname[0], 17);
	memcpy(&DeviceSettings.Settings.tempCoeffs[0], &focuserStr.tempCompInfoStr.TempCoeffs[0], 10);
	DeviceSettings.Settings.tempCompMode = focuserStr.tempCompInfoStr.TempCompMode;
 	DeviceSettings.Settings.deviceTypeFoc = focuserStr.configStr.DeviceType;
 	DeviceSettings.Settings.backlashStepsFoc = focuserStr.configStr.BacklashCompSteps;
 	DeviceSettings.Settings.backlashCompEnabledFoc = focuserStr.configStr.BacklashCompOn;
 	DeviceSettings.Settings.tempCompAtStart = focuserStr.configStr.TempCompAtStart;
 	DeviceSettings.Settings.homeOnStartFoc = focuserStr.configStr.HomeAtStart;
	
	// Rotator Settings
	DeviceSettings.Settings.lastPhysicalPositionRot[0] = 0xFFFFFFFF;
	DeviceSettings.Settings.lastPhysicalPositionRot[1] = 0xFFFFFFFF;
	DeviceSettings.Settings.lastPhysicalPositionRot[2] = 0xFFFFFFFF;
	DeviceSettings.Settings.lastPhysicalPositionRot[3] = 0xFFFFFFFF;
	DeviceSettings.Settings.lastPhysicalPositionRot[4] = 0xFFFFFFFF;	
	DeviceSettings.Settings.lastPhysicalPositionRot[rotatorStr.statusStr.LastSavedPositionOffset] = 
		rotatorStr.statusStr.CurrentPosition;
	DeviceSettings.Settings.lastPhysicalPositionMemOffsetRot = rotatorStr.statusStr.LastSavedPositionOffset;
 	memcpy(&DeviceSettings.Settings.deviceNicknameRot[0],&rotatorStr.configStr.DeviceNickname[0], 17);
 	DeviceSettings.Settings.backlashStepsRot = rotatorStr.configStr.BacklashCompSteps;
 	DeviceSettings.Settings.backlashCompEnabledRot = rotatorStr.configStr.BacklashCompOn;
 	DeviceSettings.Settings.rotatorReverse = rotatorStr.configStr.Reverse;
 	DeviceSettings.Settings.skyPaOffset = rotatorStr.configStr.SkyPaOffset;
 	DeviceSettings.Settings.homeOnStartRot = rotatorStr.configStr.HomeAtStart;
 	
 	// Non Device Specific Settings
 	DeviceSettings.Settings.ledBrightness = focuserStr.configStr.LedBrightness;
 	DeviceSettings.Settings.versionNum = CURRENT_VERSION;
 	
 	// Save the settings
 	saveDeviceSettingsToNVM();
}	

void saveDeviceSettingsToNVM()
{
	int i;
	for (i = 0; i < sizeof(settings); i++)
	{
		writeNVM(NVM_START_ADDR + i, DeviceSettings.bytes[i]);
	}	
}	


void SaveTempCompStartPoint(focuser * focuserPtr)
{
	int i;
	DWORD_VAL j;
	unsigned int offset1, offset2, offset;
StartOver:
	// First save and validate the position data.
	offset1 = (unsigned int)&DeviceSettings.Settings.lastTempCompPosition[focuserPtr->tempCompInfoStr.LastTempCompStartPosOffset];
	offset2 = (unsigned int)&DeviceSettings.Settings.versionNum;
	offset = offset1 - offset2;
	// Set the position value in memory
	DeviceSettings.Settings.lastTempCompPosition[focuserPtr->tempCompInfoStr.LastTempCompStartPosOffset] = focuserPtr->tempCompInfoStr.LastTempCompStartPos;
	// Write the new value to EEPROM
	for(i=0; i<4; i++)
	{
		writeNVM(NVM_START_ADDR + offset + i, DeviceSettings.bytes[offset+i]);
	}	
	// Now check if the write was successful...
	j.v[0] = ReadNVM(NVM_START_ADDR + offset);
	j.v[1] = ReadNVM(NVM_START_ADDR + offset + 1);
	j.v[2] = ReadNVM(NVM_START_ADDR + 2);	// Was used when position was 32bit
	j.v[3] = ReadNVM(NVM_START_ADDR + offset + 3);
	
	if(j.Val != DeviceSettings.Settings.lastTempCompPosition[focuserPtr->tempCompInfoStr.LastTempCompStartPosOffset])
	{
		focuserPtr->tempCompInfoStr.LastTempCompStartPosOffset++;
		// recursivly call this funtion...
		goto StartOver;
	}
StartOver2:
	// now repeat for the temperature
	offset1 = (unsigned int)&DeviceSettings.Settings.lastTempCompTemperature[focuserPtr->tempCompInfoStr.LastTempCompStartTempOffset];
	offset = offset1 - offset2;
	// Set the temperature value in memory
	DeviceSettings.Settings.lastTempCompTemperature[focuserPtr->tempCompInfoStr.LastTempCompStartTempOffset] = focuserPtr->tempCompInfoStr.LastTempCompStartTemp;
	// Write the new value to EEPROM
	for(i=0; i<2; i++)
	{
		writeNVM(NVM_START_ADDR + offset + i, DeviceSettings.bytes[offset+i]);
	}
	// Now check if the write was successful...
	j.v[0] = ReadNVM(NVM_START_ADDR + offset);
	j.v[1] = ReadNVM(NVM_START_ADDR + offset + 1);
	if(j.Val != DeviceSettings.Settings.lastTempCompTemperature[focuserPtr->tempCompInfoStr.LastTempCompStartTempOffset])
	{
		focuserPtr->tempCompInfoStr.LastTempCompStartTempOffset++;
		// recursivly call this funtion...
		goto StartOver2;
	}
	
}
void SaveCurrentPositionFoc(focuser * focuserPtr)
{
	int i;
	DWORD_VAL j;
	unsigned int offset1, offset2, offset;
	offset1 = (unsigned int)&DeviceSettings.Settings.lastPhysicalPositionFoc[focuserPtr->statusStr.LastSavedPositionOffset];
	offset2 = (unsigned int)&DeviceSettings.Settings.versionNum;
	offset = offset1 - offset2;
	// Write the new value to EEPROM
	DeviceSettings.Settings.lastPhysicalPositionFoc[focuserPtr->statusStr.LastSavedPositionOffset] = focuserPtr->statusStr.CurrentPosition;
	for(i = 0; i<4; i++)
	{
		writeNVM(NVM_START_ADDR + offset + i, DeviceSettings.bytes[offset + i]);
	}	
	
	// Now check if the write was successful...
	j.v[0] = ReadNVM(NVM_START_ADDR + offset);
	j.v[1] = ReadNVM(NVM_START_ADDR + offset + 1);
	j.v[2] = ReadNVM(NVM_START_ADDR + offset + 2);
	j.v[3] = ReadNVM(NVM_START_ADDR + offset + 3);
	if(j.Val == DeviceSettings.Settings.lastPhysicalPositionFoc[focuserPtr->statusStr.LastSavedPositionOffset])
		return;
	else
	{
		focuserPtr->statusStr.LastSavedPositionOffset++;
		// recursivly call this funtion...
		SaveCurrentPositionFoc(focuserPtr);
	}		
}

void SaveCurrentPositionRot(rotator * rotatorPtr)
{
	int i;
	DWORD_VAL j;
	unsigned int offset1, offset2, offset;
	offset1 = (unsigned int)&DeviceSettings.Settings.lastPhysicalPositionRot[rotatorPtr->statusStr.LastSavedPositionOffset];
	offset2 = (unsigned int)&DeviceSettings.Settings.versionNum;
	offset = offset1 - offset2;
	// Write the new value to EEPROM
	DeviceSettings.Settings.lastPhysicalPositionRot[rotatorPtr->statusStr.LastSavedPositionOffset] = rotatorPtr->statusStr.CurrentPosition;
	for(i = 0; i<4; i++)
	{
		writeNVM(NVM_START_ADDR + offset + i, DeviceSettings.bytes[offset + i]);
	}	
	
	// Now check if the write was successful...
	j.v[0] = ReadNVM(NVM_START_ADDR + offset);
	j.v[1] = ReadNVM(NVM_START_ADDR + offset + 1);
	j.v[2] = ReadNVM(NVM_START_ADDR+ offset + 2);
	j.v[3] = ReadNVM(NVM_START_ADDR + offset + 3);
	if(j.Val == DeviceSettings.Settings.lastPhysicalPositionRot[rotatorPtr->statusStr.LastSavedPositionOffset])
		return;
	else
	{
		rotatorPtr->statusStr.LastSavedPositionOffset++;
		// recursivly call this funtion...
		SaveCurrentPositionRot(rotatorPtr);
	}
}	
void SaveMagnetState()
{
	unsigned int offset = (unsigned int)&DeviceSettings.Settings.lastMagEnterDir - (unsigned int)&DeviceSettings.Settings.versionNum;
	
	DeviceSettings.Settings.lastMagEnterDir = MyRotator1.motionInfoStr.LastMagEnterDir;
	DeviceSettings.Settings.lastMagExitDir = MyRotator1.motionInfoStr.LastMagExitDir;
	
	writeNVM(NVM_START_ADDR + offset, DeviceSettings.bytes[offset]);
	writeNVM(NVM_START_ADDR + offset, DeviceSettings.bytes[offset + 1]);
	// Do we really need to check if it saved okay? I say no!
}
	
//Force a reset to factory defaults
void ResetToDefaults()
{
	DeviceSettings.Settings.versionNum++;
	saveDeviceSettingsToNVM();
}
		
void setupSPI()
{
	EEPROM_MAC_CS_IO = 1;	// Deassert the chip
	EEPROM_SPICON1 = SPI_MASTER;	// set the con registers
	EEPROM_SPISTAT = SPI_ENABLE;	
}		

unsigned char writeEEP_SPI( unsigned char data)
{
	EEPROM_SSPBUF = data;
	while (!EEPROM_SPISTATbits.SPIRBF);
	return EEPROM_SSPBUF;
}

unsigned char readSR()
{ // Check the status register
	int i;
	EEPROM_MAC_CS_IO = 0;
	writeEEP_SPI(SEE_STAT);
	i = writeEEP_SPI(0);
	EEPROM_MAC_CS_IO = 1;
	return i;
}	

unsigned char ReadNVM( unsigned char address)
{
	char byteRead;
	// wait until any work in progress is completed
	while (readSR() & 0x3);
	// perform an 8-bit read requence (two sequential bytes)
	EEPROM_MAC_CS_IO = 0;
	writeEEP_SPI(SEE_READ);
	writeEEP_SPI(address);
	byteRead = writeEEP_SPI(0);
	EEPROM_MAC_CS_IO = 1;
	return byteRead;
}

void writeNVM(unsigned char address, unsigned char data)
{
	while (readSR() & 0x3);	// wait for any work in progress to complete
	writeEnable();			// Set the write enable bit in the SR
	EEPROM_MAC_CS_IO = 0;
	writeEEP_SPI(SEE_WRITE);
	writeEEP_SPI(address);
	writeEEP_SPI(data);
	EEPROM_MAC_CS_IO = 1;
}	

void writeEnable(void)
{
	EEPROM_MAC_CS_IO = 0;
	writeEEP_SPI(SEE_WEN);
	EEPROM_MAC_CS_IO = 1;
}	

void GetMacAddrFromNvm(APP_CONFIG * app_con)
{
	unsigned char addr = 0xFA;	// The MAC address is pre-programmed into the device starting at 0xFA.
	app_con->MyMACAddr.v[0] = ReadNVM(addr++);
	app_con->MyMACAddr.v[1] = ReadNVM(addr++);
	app_con->MyMACAddr.v[2] = ReadNVM(addr++);
	app_con->MyMACAddr.v[3] = ReadNVM(addr++);
	app_con->MyMACAddr.v[4] = ReadNVM(addr++);
	app_con->MyMACAddr.v[5] = ReadNVM(addr++);
}	
