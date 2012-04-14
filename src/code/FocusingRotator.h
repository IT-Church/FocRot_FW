// FocusingRotator.h
// Header file for FocusingRotator.c
#ifndef FOCUSING_ROTATOR_H
#define FOCUSING_ROTATOR_H

#include "GenericTypeDefs.h"
#include "TCPIP Stack/TCPIP.h"
#include "CommandProcessing.h"

// Error codes used to send to host device in times of crisis
#define ERR_UNACCEPTABLE_PRM		"ER=1 Unacceptable Parameter Received In Command"
#define ERR_CMD_TOO_LONG			"ER=2 Received Command Was Too Long"
#define ERR_CMD_UNKNOWN				"ER=3 Unknown Command Received"
#define ERR_DEVICE_MOVING			"ER=4 Cannot Execute Command While Device Is Moving"
#define ERR_DEVICE_IS_HOMING		"ER=5 Cannot Execute Command - Device Is Homing"
#define ERR_DEVICE_SLEEPING			"ER=6 Cannot Execute Command While Device Is Sleeping"
#define ERR_NO_TEMP_PROBE			"ER=7 Cannot Execute Command Without Temp Probe Attached"
#define ERR_WIFI_COMM_BAD			"ER=8 Communication problem with Wi-Fi Board"
#define ERR_WIFI_INFO_INC			"ER=9 Cannot Push Settings. Necessary Settings Are Missing"
#define ERR_DEV_TYPE_INC			"ER=10 Device Type Is Set Incorrectly"

										
#define DUTYS_TO_AVERAGE			15  // Number of duty cycles to avereage for a temp reading.

										

#define FIRMWARE_VERSION_MAJOR		'0'	// These must be 0 through 9
#define FIRMWARE_VERSION_MINOR		'0'
#define FIRMWARE_VERSION_REVISION	'1'

// ***** TYPEDEFS STRUCTS AND ENUMS ***************************************************************/




typedef enum{
	SEARCHING,
	VALIDATING,
	ATTACHED
} ATTACHMENT_STATE;

typedef enum{
	NO_DEVICE,
	TEMP_PROBE,
	IN_OUT_REMOTE,
} DIN_DEVICE_TYPE;

typedef enum {
	NO_PRESS,
	IN,
	OUT
}BUTTON_PRESSED_ENUM;	

typedef enum {
	SM_IDLE,
	SM_RESET,
	SM_CALC_DELAY,
	SM_DELAY,
	SM_STEP
}TEMP_COMP_STATES;


typedef struct {
	char DeviceType;				// 2 bytes
	char DeviceNickname[17];		// 16 char + 1 null term
	unsigned char LedBrightness;	// 1 Byte
	unsigned char BacklashCompSteps;	
	
	// Individual bits
	unsigned char TempCompAtStart:1;	// 1 bit
	unsigned char BacklashCompOn:1;
	unsigned char HomeAtStart:1;
	
} focuserConfig;

typedef struct {
	char DeviceNickname[17];
	unsigned char BacklashCompSteps;	
	DWORD SkyPaOffset;
	
	// Individual bits
	unsigned char HomeAtStart:1;
	unsigned char BacklashCompOn:1;	
	unsigned char Reverse:1;
} rotatorConfig;

typedef struct{
	volatile SHORT CurrentTemp;				// 2 bytes
	volatile DWORD CurrentPosition;			// 2 bytes
	volatile DWORD TargetPosition;			// 2 bytes
	unsigned char LastSavedPositionOffset;  // 1 byte
	volatile DWORD LastSavedPosition;		// 2 bytes
		
	// 8 Individual Bits	// 1 byte
	volatile unsigned char 	IsMoving:1;
	volatile unsigned char	IsHoming:1;
	volatile unsigned char	IsHomed:1;
	volatile unsigned char 	RemoteInOutAttached:1;
	volatile unsigned char  HandControllerAttached:1;
	volatile unsigned char  TempProbeAttached:1;	
}focuserStatus;

typedef struct{
	volatile DWORD CurrentPosition;			// 2 bytes
	volatile DWORD TargetPosition;			// 2 bytes
	unsigned char LastSavedPositionOffset;  // 1 byte
	volatile DWORD LastSavedPosition;		// 2 bytes 
	
	// 8 Individual Bits	// 1 byte
	volatile unsigned char 	IsMoving:1;
	volatile unsigned char	IsHoming:1;
	volatile unsigned char	IsHomed:1;
	volatile unsigned char 	AtHomeSw:1;        
	volatile unsigned char  MoveDirection:1;	

}rotatorStatus;
	
typedef struct {
	volatile ATTACHMENT_STATE AttachmentState;
	DIN_DEVICE_TYPE AttachedDevice;
	DIN_DEVICE_TYPE LastDeviceType;
	char ReadyForNewTimes;
	char NewTimesReady;
	unsigned int NewTimesWaitCount;
	unsigned int ValidationCounter;
	WORD CapturedTimes[3];
	WORD DutyCycleArray[DUTYS_TO_AVERAGE];
	int DutyCycleBufferCount;
	WORD DutyCycleAvg;
	WORD CurrentTempX10;
	BUTTON_PRESSED_ENUM RemoteState;
	DWORD PressStartTime;
	int PressCnt; 	
	float LastDutyCycle;
	float CurrentDutyCycle;
	unsigned int Period;
} inputDevice;

typedef struct{
	int TempCoeffs[5];				// 10 bytes
	char TempCompMode;				// 1 byte
	WORD LastTempCompStartPos;
	unsigned char LastTempCompStartPosOffset;
	int LastTempCompStartTemp;
	unsigned char LastTempCompStartTempOffset;
	TEMP_COMP_STATES TempCompState;
	DWORD NextTCStepTime;
	char ResetRequired;
	int ResetCounter;
	char TempCompOn;
}tempCompInfo;

typedef struct {
	WORD ActualTargetPos;
	WORD BlcTargetPos;	
	unsigned char Motion_SM_State;
	unsigned char CurrentMotionRequest;
	unsigned char TempCompAtStartComplete;	
	DWORD RelMoveStartTime;
	DWORD MaxPosition;
	char LastMagExitDir;
	char LastMagEnterDir;
}motionInfo;

typedef struct{
	focuserStatus statusStr;
	focuserConfig configStr;
	tempCompInfo tempCompInfoStr;
	motionInfo motionInfoStr;
	inputDevice inputDeviceStr;
	char focuserNumber;
}focuser;	

typedef struct{
	rotatorStatus statusStr;
	rotatorConfig configStr;
	motionInfo motionInfoStr;
}rotator;



typedef struct 
{
	char FirmwareVersion[3];
	char InSleepMode;	
} hubInfo;	

typedef struct __attribute__((__packed__))
{	
	BYTE		FirmwareVersion[3];		// WiFi Board Firmware Version.
	IP_ADDR		MyIPAddr;				// WiFi Board Current IP address
	BYTE		MySSID[32];             // Wireless SSID (if using MRF24WB0M)
	BYTE        SsidLength;             // number of bytes in SSID
	BYTE        SecurityMode;           // WF_SECURITY_OPEN or one of the other security modes
	BYTE        SecurityKey[64];        // WiFi Security key, or passphrase.   
	BYTE        SecurityKeyLength;      // number of bytes in security key (can be 0)
	BYTE        WepKeyIndex;            // WEP key index (only valid for WEP)
	BYTE 		WiFiConnectedToNetwork;	// Connection Status of WiFi board.
	BYTE		networkType;			// Infrastructure Network or Adhoc
	BYTE		Command[16];			// Used to send commands from WiFi module to motherboard only
	BYTE		CheckSum;				// Used to validate transferred data
} wiFiSettings;

typedef struct __attribute__((__packed__)) {
	wiFiSettings CurrentSettings;
	wiFiSettings PendingSettings;
	BYTE CurrentSettingsValid;
	BYTE WiFiModuleAttached;
	BYTE WiFiHasCorrectFirmware;
	BYTE ChangesArePending;
}wiFiInfo;

// ***** GLOBAL VARIABLE DECLARATIONS **************************************************/
extern focuser MyFocuser1;
extern rotator MyRotator1;
extern hubInfo HubInfo;
extern volatile wiFiInfo WiFiInfo;


// ***** GLOBAL FUNCTION PROTOTYPES ****************************************************/
void InitFocusers(void);
void AddCmdToBfr(char devNumber, focusingRotatorCommand * cmd);
void ProcessReceivedCommands(void);
void DoFocuserOperations(void);
void FocuserMotionStateMachine();
void RotatorMoveStateMachine();
void RotatorHomeStateMachine();
void RequestDIN_InputStartMoveIN(focuser * focuserPtr);
void RequestDIN_InputStartMoveOUT(focuser * focuserPtr);
void RequestAbsoluteMoveFoc(WORD newPos);
void RequestAbsoluteMoveRot(WORD newPos);
void RequestHaltFoc();
void RequestHaltRot();
void RequestHomeStartFoc();
void RequestHomeStartRot();
void StartRelativeMoveFoc(char in);
void StartRelativeMoveRot(char dir);
void EndRelativeMoveFoc();
void EndRelativeMoveRot();
void getTempString(SHORT temp, char * tempString);
void getUnsignedDecString(DWORD pos, char * posString, char n);
//void CheckHomeSwitch(char foc);
//void CheckHomeSwitch(char foc);

#endif
