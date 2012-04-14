// Client_HandControl.h
// Header file for Client_HandControl.c 

#ifndef CLIENT_HANDCONTROL_H
#define CLIENT_HANDCONTROL_H

#if defined (__PIC24F__)
#define BRATE						34			// for 115 kBaud
#elif defined (__PIC24H__)
#define BRATE						21			// for 115 kBaud
#endif
#define SERIAL_BUFFER_SIZE			50			// bytes to hold incoming serial data

void InitClient_HandControl(void);
int sendByteUART_HC( int c);
char sendStringUART_HC( char * p, char newLine );
void ReceiveSerialCmds_HC(void);

#endif
