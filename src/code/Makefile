# MPLAB IDE generated this makefile for use with GNU make.
# Project: EthernetFocuserHJ.mcp
# Date: Tue Mar 08 10:49:20 2011

AS = pic30-as.exe
CC = pic30-gcc.exe
LD = pic30-ld.exe
AR = pic30-ar.exe
HX = pic30-bin2hex.exe
RM = rm

EthernetFocuserHJ.hex : EthernetFocuserHJ.cof
	$(HX) "EthernetFocuserHJ.cof"

EthernetFocuserHJ.cof : Main.o Client_Serial.o Focuser.o NVM.o DIN_Input.o TempComp.o Stepper.o Tick.o Motion.o
	$(CC) -mcpu=24HJ128GP204 "Main.o" "Client_Serial.o" "Focuser.o" "NVM.o" "DIN_Input.o" "TempComp.o" "Stepper.o" "Tick.o" "Motion.o" -o"EthernetFocuserHJ.cof" -Wl,-Tp24HJ128GP204.gld,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=__ICD2RAM=1,-Map="EthernetFocuserHJ.map",--report-mem

Main.o : c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24HJ128GP204.h c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24Hxxxx.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/Compiler.h HardwareProfile.h DIN_Input.h Tick.h Client_Serial.h C:/Program\ Files\ (x86)/Microchip/mplabc30/v3.25/include/stddef.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/GenericTypeDefs.h Focuser.h Main.c
	$(CC) -mcpu=24HJ128GP204 -x c -c "Main.c" -o"Main.o" -I"C:\Program Files (x86)\Microchip\App Lib 2\Microchip Solutions v2010-10-19\Microchip\Include" -I"C:\Program Files (x86)\Microchip\mplabc30\v3.25\include" -I"I:\Firmware Development\Microchip PIC24\EthernetFocuser" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

Client_Serial.o : c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24HJ128GP204.h c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24Hxxxx.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/Compiler.h HardwareProfile.h NVM.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/GenericTypeDefs.h Focuser.h Client_Serial.h C:/Program\ Files\ (x86)/Microchip/mplabc30/v3.25/include/stddef.h C:/Program\ Files\ (x86)/Microchip/mplabc30/v3.25/include/string.h Client_Serial.c
	$(CC) -mcpu=24HJ128GP204 -x c -c "Client_Serial.c" -o"Client_Serial.o" -I"C:\Program Files (x86)\Microchip\App Lib 2\Microchip Solutions v2010-10-19\Microchip\Include" -I"C:\Program Files (x86)\Microchip\mplabc30\v3.25\include" -I"I:\Firmware Development\Microchip PIC24\EthernetFocuser" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

Focuser.o : C:/Program\ Files\ (x86)/Microchip/mplabc30/v3.25/include/string.h Tick.h HardwareProfile.h DIN_Input.h TempComp.h FocuserProfiles.h c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24HJ128GP204.h c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24Hxxxx.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/Compiler.h HardwareProfile.h Stepper.h NVM.h Client_Serial.h C:/Program\ Files\ (x86)/Microchip/mplabc30/v3.25/include/stddef.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/GenericTypeDefs.h Focuser.h Focuser.c
	$(CC) -mcpu=24HJ128GP204 -x c -c "Focuser.c" -o"Focuser.o" -I"C:\Program Files (x86)\Microchip\App Lib 2\Microchip Solutions v2010-10-19\Microchip\Include" -I"C:\Program Files (x86)\Microchip\mplabc30\v3.25\include" -I"I:\Firmware Development\Microchip PIC24\EthernetFocuser" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

NVM.o : C:/Program\ Files\ (x86)/Microchip/mplabc30/v3.25/include/string.h c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24HJ128GP204.h c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24Hxxxx.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/Compiler.h HardwareProfile.h C:/Program\ Files\ (x86)/Microchip/mplabc30/v3.25/include/stddef.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/GenericTypeDefs.h Focuser.h NVM.h NVM.c
	$(CC) -mcpu=24HJ128GP204 -x c -c "NVM.c" -o"NVM.o" -I"C:\Program Files (x86)\Microchip\App Lib 2\Microchip Solutions v2010-10-19\Microchip\Include" -I"C:\Program Files (x86)\Microchip\mplabc30\v3.25\include" -I"I:\Firmware Development\Microchip PIC24\EthernetFocuser" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

DIN_Input.o : Tick.h Focuser.h C:/Program\ Files\ (x86)/Microchip/mplabc30/v3.25/include/stddef.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/GenericTypeDefs.h c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24HJ128GP204.h c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24Hxxxx.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/Compiler.h HardwareProfile.h DIN_Input.h DIN_Input.c
	$(CC) -mcpu=24HJ128GP204 -x c -c "DIN_Input.c" -o"DIN_Input.o" -I"C:\Program Files (x86)\Microchip\App Lib 2\Microchip Solutions v2010-10-19\Microchip\Include" -I"C:\Program Files (x86)\Microchip\mplabc30\v3.25\include" -I"I:\Firmware Development\Microchip PIC24\EthernetFocuser" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

TempComp.o : NVM.h FocuserProfiles.h c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24HJ128GP204.h c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24Hxxxx.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/Compiler.h HardwareProfile.h Stepper.h C:/Program\ Files\ (x86)/Microchip/mplabc30/v3.25/include/stddef.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/GenericTypeDefs.h Focuser.h TempComp.h TempComp.c
	$(CC) -mcpu=24HJ128GP204 -x c -c "TempComp.c" -o"TempComp.o" -I"C:\Program Files (x86)\Microchip\App Lib 2\Microchip Solutions v2010-10-19\Microchip\Include" -I"C:\Program Files (x86)\Microchip\mplabc30\v3.25\include" -I"I:\Firmware Development\Microchip PIC24\EthernetFocuser" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

Stepper.o : C:/Program\ Files\ (x86)/Microchip/mplabc30/v3.25/include/stddef.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/GenericTypeDefs.h Focuser.h FocuserProfiles.h c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24HJ128GP204.h c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24Hxxxx.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/Compiler.h HardwareProfile.h Stepper.h Stepper.c
	$(CC) -mcpu=24HJ128GP204 -x c -c "Stepper.c" -o"Stepper.o" -I"C:\Program Files (x86)\Microchip\App Lib 2\Microchip Solutions v2010-10-19\Microchip\Include" -I"C:\Program Files (x86)\Microchip\mplabc30\v3.25\include" -I"I:\Firmware Development\Microchip PIC24\EthernetFocuser" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

Tick.o : c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24HJ128GP204.h c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24Hxxxx.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/Compiler.h HardwareProfile.h C:/Program\ Files\ (x86)/Microchip/mplabc30/v3.25/include/stddef.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/GenericTypeDefs.h Tick.c
	$(CC) -mcpu=24HJ128GP204 -x c -c "I:\Firmware Development\Microchip PIC24\EthernetFocuser\Tick.c" -o"Tick.o" -I"C:\Program Files (x86)\Microchip\App Lib 2\Microchip Solutions v2010-10-19\Microchip\Include" -I"C:\Program Files (x86)\Microchip\mplabc30\v3.25\include" -I"I:\Firmware Development\Microchip PIC24\EthernetFocuser" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

Motion.o : c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24HJ128GP204.h c:/program\ files\ (x86)/microchip/mplabc30/v3.25/support/PIC24H/h/p24Hxxxx.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/Compiler.h HardwareProfile.h C:/Program\ Files\ (x86)/Microchip/mplabc30/v3.25/include/stddef.h C:/Program\ Files\ (x86)/Microchip/App\ Lib\ 2/Microchip\ Solutions\ v2010-10-19/Microchip/Include/GenericTypeDefs.h Focuser.h Motion.c
	$(CC) -mcpu=24HJ128GP204 -x c -c "Motion.c" -o"Motion.o" -I"C:\Program Files (x86)\Microchip\App Lib 2\Microchip Solutions v2010-10-19\Microchip\Include" -I"C:\Program Files (x86)\Microchip\mplabc30\v3.25\include" -I"I:\Firmware Development\Microchip PIC24\EthernetFocuser" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

clean : 
	$(RM) "Main.o" "Client_Serial.o" "Focuser.o" "NVM.o" "DIN_Input.o" "TempComp.o" "Stepper.o" "Tick.o" "Motion.o" "EthernetFocuserHJ.cof" "EthernetFocuserHJ.hex"

