#include "CommandProcessing.h"
#include "string.h"

void InterpretCommandString(char * CmdString, int length, focusingRotatorCommand * const newCmd, char * errorOut)
{
	if(!strcmp("HELLO", CmdString))
	{
		newCmd->command = CMD_HELLO;
	}
	else if (!strcmp("HALT", CmdString))
	{
		newCmd->command = CMD_HALT;
	}		
	else if (!strcmp("HOME", CmdString))
	{
		newCmd->command = CMD_HOME;
	}	
	else if (!strcmp("CENTER", CmdString))
	{
		newCmd->command = CMD_CENTER;
	}	
	else if (!strncmp("M1I", CmdString, 3))
	{
		newCmd->command = CMD_MOVE_IN_1;
	}	
	else if (!strncmp("M1O", CmdString, 3))
	{
		newCmd->command = CMD_MOVE_OUT_1;
	}
	else if (!strncmp("MOR", CmdString, 3))
	{
		newCmd->command = CMD_RELATIVE_MOVEOUT;
	}	
	else if (!strncmp("MIR", CmdString, 3))
	{
		newCmd->command = CMD_RELATIVE_MOVEIN;
	}	
	else if (!strncmp("MA", CmdString, 2))
	{
		newCmd->command = CMD_MOVEABS;
		memcpy(newCmd->parameters, (CmdString + 2), 6);
	}
	else if (!strncmp("ERM", CmdString, 3))
	{
		newCmd->command = CMD_END_RELATIVE_MOVE;
		memcpy(newCmd->parameters, (CmdString + 2), 6);
	} 
	else if(!strcmp("SLEEP", CmdString))
	{
		newCmd->command = CMD_SLEEP;
	}	
	else if (!strcmp("WAKE", CmdString))
	{
		newCmd->command = CMD_WAKEUP;
	}
	else if (!strcmp("GETSTATUS", CmdString))
	{
		newCmd->command = CMD_GETSTATUS;
	}
	else if (!strcmp("GETCONFIG", CmdString))
	{
		newCmd->command = CMD_GETCONFIG;
	}
	else if (!strncmp("SCDT", CmdString, 4))
	{
		newCmd->command = CMD_SET_DT;
		newCmd->parameters[0] = CmdString[4];
	}	
	else if (!strncmp("SCTC", CmdString, 4))
	{
		// Set a temperature coefficient
		newCmd->command = CMD_SET_TCO;
		memcpy(newCmd->parameters, (CmdString + 4), 6);	
	}	
	else if (!strncmp("SCTM", CmdString, 4))
	{
		// Set the current Temp Comp Mode
		newCmd->command = CMD_SET_TCM;
		newCmd->parameters[0] = CmdString[4];
	}	
	else if (!strncmp("SCTE", CmdString, 4))
	{
		// Set Temp Comp Enabled
		newCmd->command = CMD_SET_TCE;
		newCmd->parameters[0]  = CmdString[4];
	}	
	else if (!strncmp("SCTS", CmdString, 4))
	{
		newCmd->command = CMD_SET_TCS;
		newCmd->parameters[0] = CmdString[4];
	}	
	else if (!strncmp("SCNN", CmdString, 4))
	{
		// Set the device nickname
		strcpy(newCmd->parameters, (CmdString + 4));
		newCmd->command = CMD_SET_DNN;
	}	
	else if (!strncmp("SCBS", CmdString, 4))
	{
		// Set the number of backlash steps
		newCmd->command = CMD_SET_BCS;
		memcpy(newCmd->parameters, (CmdString + 4), 2);
	}	
	else if (!strncmp("SCBE", CmdString, 4))
	{
		// Set the Backlash Enabled flag
		newCmd->command = CMD_SET_BCE;
		newCmd->parameters[0] = CmdString[4];
	}	
	else if (!strncmp("SCLB", CmdString, 4))
	{
		// Set the LED brightness
		newCmd->command = CMD_SET_LED;
		newCmd->parameters[0] = CmdString[4];
		newCmd->parameters[1] = CmdString[5];
		newCmd->parameters[2] = CmdString[6];
	}	
	else if (!strncmp("SCCP", CmdString, 4))
	{
		// Set the current position equal to xxxxx
		newCmd->command = CMD_SET_CP;
		memcpy(newCmd->parameters, (CmdString + 4), 6);
		
	}	
	else if (!strncmp("GETHUBINFO", CmdString, 7))
	{
		// Get the Hub Info String
		newCmd->command = CMD_GET_HUBINFO;
	}
	
	else if (!strncmp("RESET", CmdString, 5))
	{
		//Reset the focuser configuration to defaults
		newCmd->command = CMD_FOC_RST_DEFAULTS;
	}
	
	else if( !strncmp("SWSS", CmdString, 4))
	{
		// Set the WiFi SSID 
		newCmd->command = CMD_SET_SSID;
		memcpy(newCmd->parameters, (CmdString + 4), (length-4));
	}
	else if(!strncmp("SWSM", CmdString, 4))
	{
		// Set the WiFi Security Mode
		newCmd->command = CMD_SET_SECMD;
		newCmd->parameters[0] = CmdString[4];
	}	
	else if(!strncmp("SWSK", CmdString, 4))
	{
		// Set the WiFi Security Key 
		newCmd->command = CMD_SET_SKEY;
		memcpy(newCmd->parameters, (CmdString + 4), (length-4));
	}
	else if(!strncmp("SWWI", CmdString, 4))
	{
		// Set the WEP Security Key Index
		newCmd->command = CMD_SET_WEPI;
		newCmd->parameters[0] = CmdString[4];
	}
			
	else if(!strncmp("SWPS", CmdString, 4))
	{
		// Push pending WiFi Settings to the WiFi module.
		newCmd->command = CMD_WF_PUSH_SET;
		memcpy(newCmd->parameters, (CmdString + 4), 17);
	}		
	else if(!strncmp("WIFIRESET", CmdString, 8))
	{
		// Force a software reset of the WiFi Module firmware
		newCmd->command = CMD_WF_RESET;
	}	
	else if(!strncmp("WIFIDEFAULTS", CmdString, 8))
	{
		// Force the WiFi Module to invalidate it's settings and start
		// over using an ADHOC network.
		newCmd->command = CMD_WF_RST_DEFAULTS;
	}
	else if (!strcmp("DIAG", CmdString))
	{
		newCmd->command = CMD_DIAG_REPORT;
	}	
	else
	{
		newCmd->command = CMD_NONE;
	}
}	
