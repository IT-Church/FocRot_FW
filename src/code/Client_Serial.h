// Client_Serial.h
// Header file for Client_Serial.c

#ifndef CLIENT_SERIAL_H
#define CLIENT_SERIAL_H

#if defined (__PIC24F__)
#define BRATE						34			// for 115 kBaud
#elif defined (__PIC24H__)
#define BRATE						21			// for 115 kBaud
#endif
#define SERIAL_BUFFER_SIZE			50			//bytes

void InitClient_Serial(void);

int sendByteUART( int c);
char sendStringUART( char * p, char newLine );
void ReceiveSerialCmds(void);

#endif

