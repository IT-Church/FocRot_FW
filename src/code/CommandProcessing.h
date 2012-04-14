#ifndef COMMAND_PROC_H
#define COMMAND_PROC_H

#define FOCUSER_COMMAND_SIZE 	 	17	// Max number of bytes that a focuser command can use.


#define CMD_BUFFER_SIZE				16	// Allow for this many commands to be pending...
										// TODO: Determine if this needs to be larger than n, where n is the number of possible hosts.

typedef enum 
{
	CMD_NONE, 				// The command was not recognized...
	CMD_ERROR, 				// The command was invalid. Likely bad parameters
	CMD_HELLO,				// Detect if device is connected
	CMD_SLEEP,				// go to sleep
	CMD_WAKEUP,				// wake from sleep mode
	CMD_CENTER,				// go to center of travel
	CMD_HOME,				// Home the device
	CMD_RELATIVE_MOVEIN,	// Request begin relative move IN
	CMD_RELATIVE_MOVEOUT,	// Request begin relative move OUT
	CMD_END_RELATIVE_MOVE,	// End a relative move in progress
	CMD_MOVEABS,			// Move focuser to Abs. Pos.
	CMD_MOVE_IN_1,			// Move 1 step in
	CMD_MOVE_OUT_1,			// Move 1 step out
	CMD_HALT, 				// Halt the device
	CMD_GETPOS,	  			// request current position
	CMD_GETTEMP,			// request current temp
	CMD_GETSTATUS,			// request focuser status
	CMD_GETCONFIG,			// request config
	CMD_SET_TCO,			// Set Temp Coefficient
	CMD_SET_TCM, 			// Set Temp Comp Mode
	CMD_SET_TCE,			// Set Temp Comp Enabled/disabled
	CMD_SET_TCS,			// Set TempCompAtStart flag
	CMD_SET_DNN,			// Set device nickname
	CMD_SET_DT,				// Set device type
	CMD_SET_BCE,			// Set Backlash Compensation Enabled
	CMD_SET_BCS, 			// Set Backlash Compensation steps
	CMD_SET_LED,			// Set the LED Brightness
	CMD_SET_CP,				// Set the current position equal to x
	CMD_SET_SPA_OFF,		// Set the rotator Sky PA Offset
	CMD_GET_HUBINFO,		// Get the hub info
	CMD_SET_HOMEONSTART,	// Set the home on start property
	CMD_FOC_RST_DEFAULTS,   // Restore the focuser configuration settings to defaults
	CMD_SET_SSID,			// Set the WiFi SSID
	CMD_SET_SECMD,			// Set the WiFi Security Mode
	CMD_SET_SKEY,			// Set the WiFi Security Key
	CMD_SET_WEPI,			// Set WEP Key Index
	CMD_WF_PUSH_SET,		// Push any changed WiFi settings to the WiFi Module
	CMD_WF_RESET,			// WiFi module software reset
	CMD_WF_RST_DEFAULTS,	// WiFi module restore default settings	
	CMD_DIAG_REPORT,		// Print Diagnostic Report	
					
}COMMAND;

typedef enum 
{
	NONE,	// This is just so that Serial is non-zero... Should not be used.
	SERIAL,
	HAND_CONTROL,
	WIRED_ETHERNET,
	WIFI,
	WIFI_HTTP,
	WIRED_HTTP
}CMD_SOURCE;

typedef struct
{
	COMMAND command;
	CMD_SOURCE source;
	char deviceType;
	char parameters[FOCUSER_COMMAND_SIZE];
} focusingRotatorCommand;	

void InterpretCommandString(char * CmdString, int length, focusingRotatorCommand * const newCmd, char * errorOut);

extern focusingRotatorCommand CommandBuffer[CMD_BUFFER_SIZE];

#endif
