// Client_Serial.h
// Header file for Client_Serial.h

#ifndef CLIENT_ETHERNET_H
#define CLIENT_ETHERNET_H

// ***** INCLUDES **********************************************************************/
#include <string.h>
#include "FocusingRotator.h"
#include "NVM.h"
#include "HardwareProfile.h"
#include "TCPIPConfig.h"
#include "TCPIP Stack/TCPIP.h"

#define SERVER_PORT						9760 // Defines which port the server will listen
#define ETHERNET_BUFFER_SIZE			50   // Bytes

// ***** GLOBAL VARIABLE DECLARATIONS
void ReceiveEthernetCmds();
void sendStringEthernet( char * p, char newLine );

#endif

