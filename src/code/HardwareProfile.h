// HardwareProfile.h
// Defines Port setups

#include "Compiler.h"

// Create a macro for the maximum supported internal clock
// Clock frequency values
// Create a PIC dependant macro for the maximum supported internal clock
#if defined(__PIC24F__) || defined(__PIC24FK__)
	#define MAXIMUM_PIC_FREQ		(32000000ul)
#else	// dsPIC33F, PIC24H
	#define MAXIMUM_PIC_FREQ		(80000000ul)
#endif



// These directly influence timed events using the Tick module.  They also are used for UART and SPI baud rate generation.
#define GetSystemClock()		(MAXIMUM_PIC_FREQ)			// Hz
#define GetInstructionClock()	(GetSystemClock()/2)	// Normally GetSystemClock()/4 for PIC18, GetSystemClock()/2 for PIC24/dsPIC, and GetSystemClock()/1 for PIC32.  Might need changing if using Doze modes.
#define GetPeripheralClock()	(GetSystemClock()/2)	// Normally GetSystemClock()/4 for PIC18, GetSystemClock()/2 for PIC24/dsPIC, and GetSystemClock()/1 for PIC32.  Divisor may be different if using a PIC32 since it's configurable.
#define TICKS_PER_SECOND ((GetPeripheralClock()+128ull)/256ull)    // Internal core clock drives timer with 1:256 prescaler


// DIN INPUT ASSIGMENTS

#define DinInput1RPn 					14 		
#define DinInput1Tris					_TRISB14
#define DinInput1						_RB14

#define DinInput2RPn   					10		
#define DinInput2Tris					_TRISB10
#define DinInput2						_RB10

#define HomeSwitch1Input				_RA7
#define HomeSwitch1Tris					_TRISA7
#define HomeSwitch2Input				_RB11
#define HomeSwitch2Tris					_TRISB11

#define M1P1							_LATA1
#define M1P2							_LATA0
#define M2P1							_LATA10
#define M2P2							_LATB13

#define M1P1Tris						_TRISA1
#define M1P2Tris						_TRISA0
#define M2P1Tris						_TRISA10
#define M2P2Tris						_TRISB13

#define VRefPWM_F1_Tris					_TRISB15				
#define VRefPWM_F2_Tris					_TRISB12
#define VRefPWM_F1_RPOR					_RP15R
#define VRefPWM_F2_RPOR					_RP12R

#define STEP_PWR_F1_TRIS				_TRISC1
#define STEP_PWR_F1						_LATC1
#define STEP_PWR_F2_TRIS				_TRISC0
#define STEP_PWR_F2						_LATC0

#define PwrLEDTris						_TRISB3	
#define PwrLED_RPOR						_RP3R

#define UART_PC_Rx_RPn					25		// Port C9
#define UART_HC_Rx_RPn					22		// Port C6
#define UART_PC_Tx_RPOR					_RP24R	// Port C8																		
#define UART_HC_Tx_RPOR					_RP23R	// Port C7

#define EEPROM_CS_TRIS		(TRISAbits.TRISA9)
#define EEPROM_CS_IO		(LATAbits.LATA9)
#define EEPROM_SCK_TRIS		(TRISCbits.TRISC4)
#define EEPROM_SDI_TRIS		(TRISCbits.TRISC5)
#define EEPROM_SDO_TRIS		(TRISCbits.TRISC3)
#define EEPROM_SPI_IF		(IFS2bits.SPI2IF)
#define EEPROM_SSPBUF		(SPI2BUF)
#define EEPROM_SPICON1		(SPI2CON1)
#define EEPROM_SPICON1bits	(SPI2CON1bits)
#define EEPROM_SPICON2		(SPI2CON2)
#define EEPROM_SPISTAT		(SPI2STAT)
#define EEPROM_SPISTATbits	(SPI2STATbits)

#define EEPROM_MAC_CS_TRIS  (TRISAbits.TRISA4)
#define EEPROM_MAC_CS_IO	(LATAbits.LATA4)

// The ENCJ28J60 gets the SPI1 module all to itself!
#define ENC_CS_TRIS			(TRISBbits.TRISB9)	
#define ENC_CS_IO			(LATBbits.LATB9)
#define ENC_SPI_IF			(_SPI1IF)	
#define ENC_SSPBUF			(SPI1BUF)		
#define ENC_SPISTAT			(SPI1STAT) 	
#define ENC_SPISTATbits		(SPI1STATbits)
#define ENC_SPICON1			(SPI1CON1)
#define ENC_SPICON1bits		(SPI1CON1bits)
#define ENC_SPICON2			(SPI1CON2)

// The WiFi board uses the same SPI2 module as the EEPROM chips
#define WIFI_CS_TRIS		(TRISBbits.TRISB2)
#define WIFI_CS_IO			(LATBbits.LATB2)

#define WIFI_SCK_TRIS		(TRISCbits.TRISC4)
#define WIFI_SDI_TRIS		(TRISCbits.TRISC5)
#define WIFI_SDO_TRIS		(TRISCbits.TRISC3)
#define WIFI_SPI_IF			(IFS2bits.SPI2IF)
#define WIFI_SSPBUF			(SPI2BUF)
#define WIFI_SPICON1		(SPI2CON1)
#define WIFI_SPICON1bits	(SPI2CON1bits)
#define WIFI_SPICON2		(SPI2CON2)
#define WIFI_SPISTAT		(SPI2STAT)
#define WIFI_SPISTATbits	(SPI2STATbits)


// For rotator motion
#define CW  				1
#define CCW  				0
