// Main.c
// Contains device configuration and main program loop.

// ***** INCLUDES **********************************************************************/

#include "TCPIP Stack/TCPIP.h"
#include "TCPIP Stack/Tick.h"
#include "Main.h"

#include "FocusingRotator.h"
#include "Rotator.h"
#include "Client_Serial.h"
#include "Client_HandControl.h"
#include "Client_Ethernet.h"
#include "Client_WiFi.h"
#include "DIN_Input.h"

// ***** FUNCTION PROTOTYPES ***********************************************************/
void InitPic(void);



// ***** CONFIGURATION BITS ************************************************************/	
_FOSC(OSCIOFNC_OFF & POSCMD_XT)	// XT Osc
_FOSCSEL(FNOSC_PRIPLL)			// PLL enabled
_FWDT(FWDTEN_OFF)				// Disable Watchdog timer

// Declare AppConfig structure and some other supporting stack variables
APP_CONFIG AppConfig;
static unsigned short wOriginalAppConfigChecksum;	// Checksum of the ROM defaults for AppConfig
BYTE AN0String[8];

static void InitAppConfig(void);

// C30 and C32 Exception Handlers
// If your code gets here, you either tried to read or write
// a NULL pointer, or your application overflowed the stack
// by having too many local variables or parameters declared
void _ISR __attribute__((__no_auto_psv__)) _AddressError(void)
	{
	    Nop();
		Nop();
	}
void _ISR __attribute__((__no_auto_psv__)) _StackError(void)
	{
	    Nop();
		Nop();
	}
int main(void)
{
	// Initialize the device clock speed, ports and peripherals
	InitPic();
		
	// Initialize stack-related hardware components that may be 
	// required by the UART configuration routines
    TickInit();
	MPFSInit();
	
	// Initialize Stack and application related NV variables into AppConfig.
	InitAppConfig();
	
	InitFocusers();
	InitClient_Serial();
	InitClient_HandControl();
	InitClient_WiFi();
	
	/*
	// Restore the defaults for the stack settings...
	XEEBeginWrite(0x0000);
    XEEWrite(0xFF);
    XEEWrite(0xFF);
    XEEEndWrite();
    */
	
	// Initialize core stack layers (MAC, ARP, TCP, UDP) and
	// application modules (HTTP, SNMP, etc.)
    StackInit();
		
	// MAIN PROGRAM LOOP
	while(1)
	{
		
		// 1. Perform necessary TCP/IP stack operations
			
			// This task performs normal stack task including checking
			// for incoming packets, type of packet and calling
			// appropriate stack entity to process it.
			StackTask();
			
			// This tasks invokes each of the core stack application tasks
			StackApplications();
			
		
		// 2. Check if command received from serial port host
		ReceiveSerialCmds();
		
		// 3. Process WiFi HTTP operations
		DoWiFiWork();
		
		// 4. Check if command received from WiFi host
		ReceiveWiFiCmds();
		
		// 5. Check if command received from Wired Ethernet host
		ReceiveEthernetCmds();
		
		// 6. Check if command received from Hand Control Box
		ReceiveSerialCmds_HC();
		
		// 7. Process any command received for Focusers from any client...
		ProcessReceivedCommands();
		
		// 8. Perform Focuser Operations
		//      (i.e. Get current temp, Operate motion state machine, etc.)
	 	DoFocuserOperations();
	 	
	 	// 9. Perform Rotator Operations
	 	DoRotatorOperations();
	 	 
	}	
	
}

void InitPic()
{
	// Setup the oscillator
	CLKDIV = 0x0000;  // 	FRC: divide by 2, PLLPOST: divide by 2, PLLPRE: divide by 2
	PLLFBD = 40;				// Multiply by 40 for 160MHz VCO output (8MHz XT oscillator)
	_PLLPRE = 0b00000;			// N1 = 2
	_PLLPOST = 0b00;			// N2 = 2
	
	// Initialize all of the timers ***********************************************
	// Timer 1 is used by Tick.c and is initialized by the TCP/IP stack
	
	// Timer 2 is used to measure the DIN Input duty cycles
	T2CON = 0x0000;			// Clear timer settings and stop the timer.
	T2CONbits.TCS = 0;			// Set clock source to internal clock (Fcy)
	T2CONbits.TCKPS = 0b10;		// Set the timer clock prescaler to 1:64
	T2CONbits.TSIDL = 1;		// Timer is DISABLED when in Idle mode.
	PR2 = 0xFFFF;				// Set the period of this timer for the PWM outputs
	T2CONbits.TON = 1;			// Turn the timer on
	
	// Timer 3 is used for the VRefPWM outputs and the LED brightness
	T3CON = 0x0000;				// Clear timer settings and stop the timer.
	T3CONbits.TCS = 0;			// Set clock source to internal clock (Fcy)
	T3CONbits.TCKPS = 0b00;		// Set the timer clock prescaler to 1:1
	T3CONbits.TSIDL = 1;		// Timer is DISABLED when in Idle mode.
	PR3 = 100;					// Set the period of this timer for the PWM outputs
	T3CONbits.TON = 1;			// Turn the timer on
	
	
	// Timer 4 is used to to control stepper motor 1. This timers period and frequency will change depending
	// on the selected device type and the selected motor speed. It should only be used for Stepper motor 1.
	T4CON = 0x0000;				// Clear timer settings and stop the timer.
	T4CONbits.TCS = 0;			// Set clock source to internal FRC osc / 2.
	T4CONbits.TSIDL = 1;		// Timer is DISABLED when in Idle mode.
	T4CONbits.TCKPS = 0b11;		// Prescaler = 1:256
	T4CONbits.TON = 1;			// Turn Timer 3 ON
	_T4IP = 5;					// Set Interrupt Proirity higher than default.
	_T4IF = 0;					// Clear the Timer 3 Interrupt Flag.
	//_T4IE = 1; 				// The interrupt will get enabled in the InitSteppers() function
	
	// Timer 5 is used to to control stepper motor 2. This timers period and frequency will change depending
	// on the selected device type and the selected motor speed. It should only be used for Stepper motor 2.
	T5CON = 0x0000;				// Clear timer settings and stop the timer.
	T5CONbits.TCS = 0;			// Set clock source to internal FRC osc / 2.
	T5CONbits.TSIDL = 1;		// Timer is DISABLED when in Idle mode.
	T5CONbits.TCKPS = 0b11;		// Prescaler = 1:256
	TMR5 = 0;
	PR5 = 52083;
	_T5IP = 5;					// Set Interrupt Proirity higher than default.
	_T5IF = 0;					// Clear the Timer 4 Interrupt Flag.
//	_T5IE = 1; 					// The interrupt will get enabled in the InitSteppers() function
	T5CONbits.TON = 1;			// Turn Timer 4 ON
		
	// Drive all pins low.
	LATA = 0x00;
	LATB = 0x00;
	LATC = 0x00;
	
	// Make all pins outputs
	TRISA = 0x00;
	TRISB = 0x00;
	TRISC = 0x00;
	
	//  Set all pins digital (Not analog)
	AD1PCFGL = 0xffff;   
	
	// Make the DIN Input Pins Inputs and assign them to the input capture modules
	DinInput1Tris = 1;
	DinInput2Tris = 1;
	_IC1R = DinInput1RPn;
	_IC2R = DinInput2RPn;
	
	// Make the Home Switchs Inputs
	HomeSwitch1Tris = 1;
	HomeSwitch2Tris = 1;
	
	// Make Motor Phase pins and Motor Power pins outputs;
	M1P1Tris = 0;
	M1P2Tris = 0;
	M2P1Tris = 0;
	M2P2Tris = 0;
	VRefPWM_F1_Tris	= 0;
	VRefPWM_F2_Tris = 0;
	
	// Assign the Motor Power output pins and Power LED pins to the Output Compare Modules
	VRefPWM_F1_RPOR = 0b10010;		// OC1
	VRefPWM_F2_RPOR = 0b10011;		// OC2
	PwrLED_RPOR = 0b10100;			// OC3
	
	// Assign UART PPS pins. UART1 is for PC, UART2 is for Hand Control Box
	_TRISC9 = 1;
	_TRISC6 = 1;
	_U1RXR = UART_PC_Rx_RPn;			// All of the TRIS functionality
	_U2RXR = UART_HC_Rx_RPn;			// is set automatically for these.
	UART_PC_Tx_RPOR = 3;				//
	UART_HC_Tx_RPOR = 5;				//
	
	// Setup the SPI Pins for the EEPROM and Ethernet Controller ***************
	// The ENC28J60 eth. controller is on SPI1 module
	// The EEPROM units and the WiFi board are on SPI2 module
	
	// Deassert the chip select lines (Set them high) and set them as outputs
	EEPROM_CS_IO = 1;	
	EEPROM_CS_TRIS = 0;
	EEPROM_MAC_CS_IO = 1;
	EEPROM_MAC_CS_TRIS = 0;
	ENC_CS_IO = 1;
	ENC_CS_TRIS = 0;
	WIFI_CS_IO = 1;
	WIFI_CS_TRIS = 0;
	
	
	// SPI Inputs for SPI1 and SPI2 modules
	_TRISB6 = 1;
	_SDI1R = 6;					// SDI1 = B6 = RP6
	
	_SDI2R = 21; 				// SDI2 = C5 = RP21
	
	// SPI Outputs for SPI1 and SPI2 modules
	_TRISB8 = 0;
	_RP8R = 8;			// B8 = SCK1
	_TRISB7 = 0;
	_RP7R = 7;			// B7 = SDO1
	
	_RP20R = 0b01011;	// C4 = SCK2
	_RP19R = 0b01010;	// C3 = SDO2

	// Initialize the EEPROM 
	XEEInit();
}

	




static ROM BYTE SerializedMACAddress[6] = {MY_DEFAULT_MAC_BYTE1, MY_DEFAULT_MAC_BYTE2, MY_DEFAULT_MAC_BYTE3, MY_DEFAULT_MAC_BYTE4, MY_DEFAULT_MAC_BYTE5, MY_DEFAULT_MAC_BYTE6};
static void InitAppConfig(void)
{
	unsigned char vNeedToSaveDefaults = 0;
	while(1)
	{
		// Start out zeroing all AppConfig bytes to ensure all fields are 
		// deterministic for checksum generation
		memset((void*)&AppConfig, 0x00, sizeof(AppConfig));
		
		AppConfig.Flags.bIsDHCPEnabled = TRUE;
		AppConfig.Flags.bInConfigMode = TRUE;
		// Get the MAC Address from NVM
		GetMacAddrFromNvm(&AppConfig);	
		AppConfig.MyIPAddr.Val = MY_DEFAULT_IP_ADDR_BYTE1 | MY_DEFAULT_IP_ADDR_BYTE2<<8ul | MY_DEFAULT_IP_ADDR_BYTE3<<16ul | MY_DEFAULT_IP_ADDR_BYTE4<<24ul;
		AppConfig.DefaultIPAddr.Val = AppConfig.MyIPAddr.Val;
		AppConfig.MyMask.Val = MY_DEFAULT_MASK_BYTE1 | MY_DEFAULT_MASK_BYTE2<<8ul | MY_DEFAULT_MASK_BYTE3<<16ul | MY_DEFAULT_MASK_BYTE4<<24ul;
		AppConfig.DefaultMask.Val = AppConfig.MyMask.Val;
		AppConfig.MyGateway.Val = MY_DEFAULT_GATE_BYTE1 | MY_DEFAULT_GATE_BYTE2<<8ul | MY_DEFAULT_GATE_BYTE3<<16ul | MY_DEFAULT_GATE_BYTE4<<24ul;
		AppConfig.PrimaryDNSServer.Val = MY_DEFAULT_PRIMARY_DNS_BYTE1 | MY_DEFAULT_PRIMARY_DNS_BYTE2<<8ul  | MY_DEFAULT_PRIMARY_DNS_BYTE3<<16ul  | MY_DEFAULT_PRIMARY_DNS_BYTE4<<24ul;
		AppConfig.SecondaryDNSServer.Val = MY_DEFAULT_SECONDARY_DNS_BYTE1 | MY_DEFAULT_SECONDARY_DNS_BYTE2<<8ul  | MY_DEFAULT_SECONDARY_DNS_BYTE3<<16ul  | MY_DEFAULT_SECONDARY_DNS_BYTE4<<24ul;
	
	
		// SNMP Community String configuration
		#if defined(STACK_USE_SNMP_SERVER)
		{
			BYTE i;
			static ROM char * ROM cReadCommunities[] = SNMP_READ_COMMUNITIES;
			static ROM char * ROM cWriteCommunities[] = SNMP_WRITE_COMMUNITIES;
			ROM char * strCommunity;
			
			for(i = 0; i < SNMP_MAX_COMMUNITY_SUPPORT; i++)
			{
				// Get a pointer to the next community string
				strCommunity = cReadCommunities[i];
				if(i >= sizeof(cReadCommunities)/sizeof(cReadCommunities[0]))
					strCommunity = "";
	
				// Ensure we don't buffer overflow.  If your code gets stuck here, 
				// it means your SNMP_COMMUNITY_MAX_LEN definition in TCPIPConfig.h 
				// is either too small or one of your community string lengths 
				// (SNMP_READ_COMMUNITIES) are too large.  Fix either.
				if(strlenpgm(strCommunity) >= sizeof(AppConfig.readCommunity[0]))
					while(1);
				
				// Copy string into AppConfig
				strcpypgm2ram((char*)AppConfig.readCommunity[i], strCommunity);
	
				// Get a pointer to the next community string
				strCommunity = cWriteCommunities[i];
				if(i >= sizeof(cWriteCommunities)/sizeof(cWriteCommunities[0]))
					strCommunity = "";
	
				// Ensure we don't buffer overflow.  If your code gets stuck here, 
				// it means your SNMP_COMMUNITY_MAX_LEN definition in TCPIPConfig.h 
				// is either too small or one of your community string lengths 
				// (SNMP_WRITE_COMMUNITIES) are too large.  Fix either.
				if(strlenpgm(strCommunity) >= sizeof(AppConfig.writeCommunity[0]))
					while(1);
	
				// Copy string into AppConfig
				strcpypgm2ram((char*)AppConfig.writeCommunity[i], strCommunity);
			}
		}
		#endif
	
		// Load the default NetBIOS Host Name
		memcpypgm2ram(AppConfig.NetBIOSName, (ROM void*)MY_DEFAULT_HOST_NAME, 16);
		FormatNetBIOSName(AppConfig.NetBIOSName);
	
		#if defined(WF_CS_TRIS)
			// Load the default SSID Name
			WF_ASSERT(sizeof(MY_DEFAULT_SSID_NAME) <= sizeof(AppConfig.MySSID));
			memcpypgm2ram(AppConfig.MySSID, (ROM void*)MY_DEFAULT_SSID_NAME, sizeof(MY_DEFAULT_SSID_NAME));
			AppConfig.SsidLength = sizeof(MY_DEFAULT_SSID_NAME) - 1;
	
	        AppConfig.SecurityMode = MY_DEFAULT_WIFI_SECURITY_MODE;
	        AppConfig.WepKeyIndex  = MY_DEFAULT_WEP_KEY_INDEX;
	        
	        #if (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_OPEN)
	            memset(AppConfig.SecurityKey, 0x00, sizeof(AppConfig.SecurityKey));
	            AppConfig.SecurityKeyLength = 0;
	
	        #elif MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WEP_40
	            memcpypgm2ram(AppConfig.SecurityKey, (ROM void*)MY_DEFAULT_WEP_KEYS_40, sizeof(MY_DEFAULT_WEP_KEYS_40) - 1);
	            AppConfig.SecurityKeyLength = sizeof(MY_DEFAULT_WEP_KEYS_40) - 1;
	
	        #elif MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WEP_104
			    memcpypgm2ram(AppConfig.SecurityKey, (ROM void*)MY_DEFAULT_WEP_KEYS_104, sizeof(MY_DEFAULT_WEP_KEYS_104) - 1);
			    AppConfig.SecurityKeyLength = sizeof(MY_DEFAULT_WEP_KEYS_104) - 1;
	
	        #elif (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA_WITH_KEY)       || \
	              (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA2_WITH_KEY)      || \
	              (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA_AUTO_WITH_KEY)
			    memcpypgm2ram(AppConfig.SecurityKey, (ROM void*)MY_DEFAULT_PSK, sizeof(MY_DEFAULT_PSK) - 1);
			    AppConfig.SecurityKeyLength = sizeof(MY_DEFAULT_PSK) - 1;
	
	        #elif (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA_WITH_PASS_PHRASE)     || \
	              (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA2_WITH_PASS_PHRASE)    || \
	              (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA_AUTO_WITH_PASS_PHRASE)
	            memcpypgm2ram(AppConfig.SecurityKey, (ROM void*)MY_DEFAULT_PSK_PHRASE, sizeof(MY_DEFAULT_PSK_PHRASE) - 1);
	            AppConfig.SecurityKeyLength = sizeof(MY_DEFAULT_PSK_PHRASE) - 1;
	
	        #else 
	            #error "No security defined"
	        #endif /* MY_DEFAULT_WIFI_SECURITY_MODE */
	
		#endif

		// Compute the checksum of the AppConfig defaults as loaded from ROM
		wOriginalAppConfigChecksum = CalcIPChecksum((BYTE*)&AppConfig, sizeof(AppConfig));

		#if defined(EEPROM_CS_TRIS) || defined(SPIFLASH_CS_TRIS)
		{
			NVM_VALIDATION_STRUCT NVMValidationStruct;

			// Check to see if we have a flag set indicating that we need to 
			// save the ROM default AppConfig values.
			if(vNeedToSaveDefaults)
				SaveAppConfig(&AppConfig);
		
			// Read the NVMValidation record and AppConfig struct out of EEPROM/Flash
			#if defined(EEPROM_CS_TRIS)
			{
				XEEReadArray(0x0000, (BYTE*)&NVMValidationStruct, sizeof(NVMValidationStruct));
				XEEReadArray(sizeof(NVMValidationStruct), (BYTE*)&AppConfig, sizeof(AppConfig));
			}
			#elif defined(SPIFLASH_CS_TRIS)
			{
				SPIFlashReadArray(0x0000, (BYTE*)&NVMValidationStruct, sizeof(NVMValidationStruct));
				SPIFlashReadArray(sizeof(NVMValidationStruct), (BYTE*)&AppConfig, sizeof(AppConfig));
			}
			#endif
	
			// Check EEPROM/Flash validitity.  If it isn't valid, set a flag so 
			// that we will save the ROM default values on the next loop 
			// iteration.
			if((NVMValidationStruct.wConfigurationLength != sizeof(AppConfig)) ||
			   (NVMValidationStruct.wOriginalChecksum != wOriginalAppConfigChecksum) ||
			   (NVMValidationStruct.wCurrentChecksum != CalcIPChecksum((BYTE*)&AppConfig, sizeof(AppConfig))))
			{
				// Check to ensure that the vNeedToSaveDefaults flag is zero, 
				// indicating that this is the first iteration through the do 
				// loop.  If we have already saved the defaults once and the 
				// EEPROM/Flash still doesn't pass the validity check, then it 
				// means we aren't successfully reading or writing to the 
				// EEPROM/Flash.  This means you have a hardware error and/or 
				// SPI configuration error.
				if(vNeedToSaveDefaults)
				{
					while(1);
				}
				
				// Set flag and restart loop to load ROM defaults and save them
				vNeedToSaveDefaults = 1;
				continue;
			}
			
			// If we get down here, it means the EEPROM/Flash has valid contents 
			// and either matches the ROM defaults or previously matched and 
			// was run-time reconfigured by the user.  In this case, we shall 
			// use the contents loaded from EEPROM/Flash.
			break;
		}
		#endif
		break;
	}
}

void SaveAppConfig(const APP_CONFIG *ptrAppConfig)
{
	NVM_VALIDATION_STRUCT NVMValidationStruct;

	// Ensure adequate space has been reserved in non-volatile storage to 
	// store the entire AppConfig structure.  If you get stuck in this while(1) 
	// trap, it means you have a design time misconfiguration in TCPIPConfig.h.
	// You must increase MPFS_RESERVE_BLOCK to allocate more space.
	#if defined(STACK_USE_MPFS) || defined(STACK_USE_MPFS2)
		if(sizeof(NVMValidationStruct) + sizeof(AppConfig) > MPFS_RESERVE_BLOCK)
			while(1);
	#endif

	// Get proper values for the validation structure indicating that we can use 
	// these EEPROM/Flash contents on future boot ups
	NVMValidationStruct.wOriginalChecksum = wOriginalAppConfigChecksum;
	NVMValidationStruct.wCurrentChecksum = CalcIPChecksum((BYTE*)ptrAppConfig, sizeof(APP_CONFIG));
	NVMValidationStruct.wConfigurationLength = sizeof(APP_CONFIG);

	// Write the validation struct and current AppConfig contents to EEPROM/Flash
	#if defined(EEPROM_CS_TRIS)
	    XEEBeginWrite(0x0000);
	    XEEWriteArray((BYTE*)&NVMValidationStruct, sizeof(NVMValidationStruct));
		XEEWriteArray((BYTE*)ptrAppConfig, sizeof(APP_CONFIG));
    #else
		SPIFlashBeginWrite(0x0000);
		SPIFlashWriteArray((BYTE*)&NVMValidationStruct, sizeof(NVMValidationStruct));
		SPIFlashWriteArray((BYTE*)ptrAppConfig, sizeof(APP_CONFIG));
    #endif
}
