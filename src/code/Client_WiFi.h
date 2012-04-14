// Client_WiFi.h
// Header file for Client_WiFi.c

#ifndef WIFI_CLIENT
#define WIFI_CLIENT

// ***** INCLUDES **********************************************************************/
#include <string.h>
#include "GenericTypeDefs.h"

#define SERVER_PORT						9760 // Defines which port the server will listen
#define WIFI_BUFFER_SIZE				50   // Bytes

typedef enum 
{
	MOD_NOT_ATTACHED,
	MOD_BAD_FIRM_VER,
	TRYING_TO_CONNECT,
	UNABLE_TO_CONNECT,
	CONN_DATA_INVALID,
	CONN_DATA_VALID	
}WIFI_STATUS;	

typedef struct __attribute__((__packed__)) {
	char 	F1Nickname[17];
	char 	F2Nickname[17];
	WORD 	F1CurrentPos;
	WORD 	F2CurrentPos;
	WORD	F1CurrentTemp;
	WORD	F2CurrentTemp;
	WORD	F1MaxPos;
	WORD	F2MaxPos;
	BYTE	F1TempCompOn;
	BYTE	F2TempCompOn;
	BYTE	CheckSum;
} deviceStatus;	
// ***** GLOBAL VARIABLE DECLARATIONS

// ***** FUNCTION PROTOTYPES **************
void InitClient_WiFi(void);
void ReceiveWiFiCmds();
void SendStringWiFiPassThru(char * p, char newLine );
//char SendWiFiCmdGetResponse(char * cmd, char * resp);
void DoWiFiWork();

#endif
