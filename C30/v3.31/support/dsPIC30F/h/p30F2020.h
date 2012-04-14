/*-------------------------------------------------------------------------
 * MPLAB-Cxx  dsPIC30F2020 processor header
 *
 * (c) Copyright 1999-2011 Microchip Technology, All rights reserved
 *-------------------------------------------------------------------------*/

#ifndef __dsPIC30F2020__
#error "Include file does not match processor setting"
#endif

#ifndef __30F2020_H
#define __30F2020_H

extern volatile unsigned int  WREG0 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG1 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG2 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG3 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG4 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG5 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG6 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG7 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG8 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG9 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG10 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG11 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG12 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG13 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG14 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  WREG15 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int  SPLIM __attribute__((__sfr__));
typedef struct tagACC {
    unsigned int L;
    unsigned int H;
    unsigned char U;
} ACC;

/* SFR blocks for each ACC module */
extern volatile ACC ACCA __attribute__((__sfr__));

extern volatile unsigned int  ACCAL __attribute__((__sfr__));
extern volatile unsigned int  ACCAH __attribute__((__sfr__));
extern volatile unsigned char ACCAU __attribute__((__sfr__));

/* SFR blocks for each ACC module */
extern volatile ACC ACCB __attribute__((__sfr__));

extern volatile unsigned int  ACCBL __attribute__((__sfr__));
extern volatile unsigned int  ACCBH __attribute__((__sfr__));
extern volatile unsigned char ACCBU __attribute__((__sfr__));
extern volatile unsigned int  PCL __attribute__((__sfr__));
extern volatile unsigned char PCH __attribute__((__sfr__));
extern volatile unsigned char TBLPAG __attribute__((__sfr__));
extern volatile unsigned char PSVPAG __attribute__((__sfr__));
extern volatile unsigned int  RCOUNT __attribute__((__sfr__));
extern volatile unsigned int  DCOUNT __attribute__((__sfr__));
extern volatile unsigned int  DOSTARTL __attribute__((__sfr__));
extern volatile unsigned int  DOSTARTH __attribute__((__sfr__));
extern volatile unsigned int  DOENDL __attribute__((__sfr__));
extern volatile unsigned int  DOENDH __attribute__((__sfr__));
extern volatile unsigned int  SR __attribute__((__sfr__));
__extension__ typedef struct tagSRBITS {
  union {
    struct {
      unsigned C:1;
      unsigned Z:1;
      unsigned OV:1;
      unsigned N:1;
      unsigned RA:1;
      unsigned IPL:3;
      unsigned DC:1;
      unsigned DA:1;
      unsigned SAB:1;
      unsigned OAB:1;
      unsigned SB:1;
      unsigned SA:1;
      unsigned OB:1;
      unsigned OA:1;
    };
    struct {
      unsigned :5;
      unsigned IPL0:1;
      unsigned IPL1:1;
      unsigned IPL2:1;
    };
  };
} SRBITS;
extern volatile SRBITS SRbits __attribute__((__sfr__));

extern volatile unsigned int  CORCON __attribute__((__sfr__));
__extension__ typedef struct tagCORCONBITS {
  union {
    struct {
      unsigned IF:1;
      unsigned RND:1;
      unsigned PSV:1;
      unsigned IPL3:1;
      unsigned ACCSAT:1;
      unsigned SATDW:1;
      unsigned SATB:1;
      unsigned SATA:1;
      unsigned DL:3;
      unsigned EDT:1;
      unsigned US:1;
    };
    struct {
      unsigned :8;
      unsigned DL0:1;
      unsigned DL1:1;
      unsigned DL2:1;
    };
  };
} CORCONBITS;
extern volatile CORCONBITS CORCONbits __attribute__((__sfr__));

extern volatile unsigned int  MODCON __attribute__((__sfr__));
__extension__ typedef struct tagMODCONBITS {
  union {
    struct {
      unsigned XWM:4;
      unsigned YWM:4;
      unsigned BWM:4;
      unsigned :2;
      unsigned YMODEN:1;
      unsigned XMODEN:1;
    };
    struct {
      unsigned XWM0:1;
      unsigned XWM1:1;
      unsigned XWM2:1;
      unsigned XWM3:1;
      unsigned YWM0:1;
      unsigned YWM1:1;
      unsigned YWM2:1;
      unsigned YWM3:1;
      unsigned BWM0:1;
      unsigned BWM1:1;
      unsigned BWM2:1;
      unsigned BWM3:1;
    };
  };
} MODCONBITS;
extern volatile MODCONBITS MODCONbits __attribute__((__sfr__));

extern volatile unsigned int  XMODSRT __attribute__((__sfr__));
extern volatile unsigned int  XMODEND __attribute__((__sfr__));
extern volatile unsigned int  YMODSRT __attribute__((__sfr__));
extern volatile unsigned int  YMODEND __attribute__((__sfr__));
extern volatile unsigned int  XBREV __attribute__((__sfr__));
__extension__ typedef struct tagXBREVBITS {
  union {
    struct {
      unsigned XB:15;
      unsigned BREN:1;
    };
    struct {
      unsigned XB0:1;
      unsigned XB1:1;
      unsigned XB2:1;
      unsigned XB3:1;
      unsigned XB4:1;
      unsigned XB5:1;
      unsigned XB6:1;
      unsigned XB7:1;
      unsigned XB8:1;
      unsigned XB9:1;
      unsigned XB10:1;
      unsigned XB11:1;
      unsigned XB12:1;
      unsigned XB13:1;
      unsigned XB14:1;
    };
  };
} XBREVBITS;
extern volatile XBREVBITS XBREVbits __attribute__((__sfr__));

extern volatile unsigned int  DISICNT __attribute__((__sfr__));
typedef struct tagDISICNTBITS {
  unsigned DISICNT:14;
} DISICNTBITS;
extern volatile DISICNTBITS DISICNTbits __attribute__((__sfr__));

extern volatile unsigned int  CNEN1 __attribute__((__sfr__));
typedef struct tagCNEN1BITS {
  unsigned CN0IE:1;
  unsigned CN1IE:1;
  unsigned CN2IE:1;
  unsigned CN3IE:1;
  unsigned CN4IE:1;
  unsigned CN5IE:1;
  unsigned CN6IE:1;
  unsigned CN7IE:1;
} CNEN1BITS;
extern volatile CNEN1BITS CNEN1bits __attribute__((__sfr__));

extern volatile unsigned int  CNPU1 __attribute__((__sfr__));
typedef struct tagCNPU1BITS {
  unsigned CN0PUE:1;
  unsigned CN1PUE:1;
  unsigned CN2PUE:1;
  unsigned CN3PUE:1;
  unsigned CN4PUE:1;
  unsigned CN5PUE:1;
  unsigned CN6PUE:1;
  unsigned CN7PUE:1;
} CNPU1BITS;
extern volatile CNPU1BITS CNPU1bits __attribute__((__sfr__));

extern volatile unsigned int  INTCON1 __attribute__((__sfr__));
typedef struct tagINTCON1BITS {
  unsigned :1;
  unsigned OSCFAIL:1;
  unsigned STKERR:1;
  unsigned ADDRERR:1;
  unsigned MATHERR:1;
  unsigned :1;
  unsigned DIV0ERR:1;
  unsigned SFTACERR:1;
  unsigned COVTE:1;
  unsigned OVBTE:1;
  unsigned OVATE:1;
  unsigned COVBERR:1;
  unsigned COVAERR:1;
  unsigned OVBERR:1;
  unsigned OVAERR:1;
  unsigned NSTDIS:1;
} INTCON1BITS;
extern volatile INTCON1BITS INTCON1bits __attribute__((__sfr__));

extern volatile unsigned int  INTCON2 __attribute__((__sfr__));
typedef struct tagINTCON2BITS {
  unsigned INT0EP:1;
  unsigned INT1EP:1;
  unsigned INT2EP:1;
  unsigned :11;
  unsigned DISI:1;
  unsigned ALTIVT:1;
} INTCON2BITS;
extern volatile INTCON2BITS INTCON2bits __attribute__((__sfr__));

extern volatile unsigned int  IFS0 __attribute__((__sfr__));
typedef struct tagIFS0BITS {
  unsigned INT0IF:1;
  unsigned IC1IF:1;
  unsigned OC1IF:1;
  unsigned T1IF:1;
  unsigned :1;
  unsigned OC2IF:1;
  unsigned T2IF:1;
  unsigned T3IF:1;
  unsigned SPI1IF:1;
  unsigned U1RXIF:1;
  unsigned U1TXIF:1;
  unsigned ADIF:1;
  unsigned NVMIF:1;
  unsigned SI2CIF:1;
  unsigned MI2CIF:1;
} IFS0BITS;
extern volatile IFS0BITS IFS0bits __attribute__((__sfr__));

extern volatile unsigned int  IFS1 __attribute__((__sfr__));
__extension__ typedef struct tagIFS1BITS {
  union {
    struct {
      unsigned INT1IF:1;
      unsigned INT2IF:1;
      unsigned PSEMIF:1;
      unsigned PWM1IF:1;
      unsigned PWM2IF:1;
      unsigned PWM3IF:1;
      unsigned PWM4IF:1;
      unsigned :4;
      unsigned CNIF:1;
      unsigned :1;
      unsigned AC1IF:1;
      unsigned AC2IF:1;
      unsigned AC3IF:1;
    };
    struct {
      unsigned :2;
      unsigned PWMEVIF:1;
    };
  };
} IFS1BITS;
extern volatile IFS1BITS IFS1bits __attribute__((__sfr__));

extern volatile unsigned int  IFS2 __attribute__((__sfr__));
typedef struct tagIFS2BITS {
  unsigned AC4IF:1;
  unsigned :4;
  unsigned ADCP0IF:1;
  unsigned ADCP1IF:1;
  unsigned ADCP2IF:1;
  unsigned ADCP3IF:1;
} IFS2BITS;
extern volatile IFS2BITS IFS2bits __attribute__((__sfr__));

extern volatile unsigned int  IEC0 __attribute__((__sfr__));
typedef struct tagIEC0BITS {
  unsigned INT0IE:1;
  unsigned IC1IE:1;
  unsigned OC1IE:1;
  unsigned T1IE:1;
  unsigned :1;
  unsigned OC2IE:1;
  unsigned T2IE:1;
  unsigned T3IE:1;
  unsigned SPI1IE:1;
  unsigned U1RXIE:1;
  unsigned U1TXIE:1;
  unsigned ADIE:1;
  unsigned NVMIE:1;
  unsigned SI2CIE:1;
  unsigned MI2CIE:1;
} IEC0BITS;
extern volatile IEC0BITS IEC0bits __attribute__((__sfr__));

extern volatile unsigned int  IEC1 __attribute__((__sfr__));
__extension__ typedef struct tagIEC1BITS {
  union {
    struct {
      unsigned INT1IE:1;
      unsigned INT2IE:1;
      unsigned PSEMIE:1;
      unsigned PWM1IE:1;
      unsigned PWM2IE:1;
      unsigned PWM3IE:1;
      unsigned PWM4IE:1;
      unsigned :4;
      unsigned CNIE:1;
      unsigned :1;
      unsigned AC1IE:1;
      unsigned AC2IE:1;
      unsigned AC3IE:1;
    };
    struct {
      unsigned :2;
      unsigned PWMEVIE:1;
    };
  };
} IEC1BITS;
extern volatile IEC1BITS IEC1bits __attribute__((__sfr__));

extern volatile unsigned int  IEC2 __attribute__((__sfr__));
typedef struct tagIEC2BITS {
  unsigned AC4IE:1;
  unsigned :4;
  unsigned ADCP0IE:1;
  unsigned ADCP1IE:1;
  unsigned ADCP2IE:1;
  unsigned ADCP3IE:1;
} IEC2BITS;
extern volatile IEC2BITS IEC2bits __attribute__((__sfr__));

extern volatile unsigned int  IPC0 __attribute__((__sfr__));
__extension__ typedef struct tagIPC0BITS {
  union {
    struct {
      unsigned INT0IP:3;
      unsigned :1;
      unsigned IC1IP:3;
      unsigned :1;
      unsigned OC1IP:3;
      unsigned :1;
      unsigned T1IP:3;
    };
    struct {
      unsigned INT0IP0:1;
      unsigned INT0IP1:1;
      unsigned INT0IP2:1;
      unsigned :1;
      unsigned IC1IP0:1;
      unsigned IC1IP1:1;
      unsigned IC1IP2:1;
      unsigned :1;
      unsigned OC1IP0:1;
      unsigned OC1IP1:1;
      unsigned OC1IP2:1;
      unsigned :1;
      unsigned T1IP0:1;
      unsigned T1IP1:1;
      unsigned T1IP2:1;
    };
  };
} IPC0BITS;
extern volatile IPC0BITS IPC0bits __attribute__((__sfr__));

extern volatile unsigned int  IPC1 __attribute__((__sfr__));
__extension__ typedef struct tagIPC1BITS {
  union {
    struct {
      unsigned :4;
      unsigned OC2IP:3;
      unsigned :1;
      unsigned T2IP:3;
      unsigned :1;
      unsigned T3IP:3;
    };
    struct {
      unsigned :4;
      unsigned OC2IP0:1;
      unsigned OC2IP1:1;
      unsigned OC2IP2:1;
      unsigned :1;
      unsigned T2IP0:1;
      unsigned T2IP1:1;
      unsigned T2IP2:1;
      unsigned :1;
      unsigned T3IP0:1;
      unsigned T3IP1:1;
      unsigned T3IP2:1;
    };
  };
} IPC1BITS;
extern volatile IPC1BITS IPC1bits __attribute__((__sfr__));

extern volatile unsigned int  IPC2 __attribute__((__sfr__));
__extension__ typedef struct tagIPC2BITS {
  union {
    struct {
      unsigned SPI1IP:3;
      unsigned :1;
      unsigned U1RXIP:3;
      unsigned :1;
      unsigned U1TXIP:3;
      unsigned :1;
      unsigned ADIP:3;
    };
    struct {
      unsigned SPI1IP0:1;
      unsigned SPI1IP1:1;
      unsigned SPI1IP2:1;
      unsigned :1;
      unsigned U1RXIP0:1;
      unsigned U1RXIP1:1;
      unsigned U1RXIP2:1;
      unsigned :1;
      unsigned U1TXIP0:1;
      unsigned U1TXIP1:1;
      unsigned U1TXIP2:1;
      unsigned :1;
      unsigned ADIP0:1;
      unsigned ADIP1:1;
      unsigned ADIP2:1;
    };
  };
} IPC2BITS;
extern volatile IPC2BITS IPC2bits __attribute__((__sfr__));

extern volatile unsigned int  IPC3 __attribute__((__sfr__));
__extension__ typedef struct tagIPC3BITS {
  union {
    struct {
      unsigned NVMIP:3;
      unsigned :1;
      unsigned SI2CIP:3;
      unsigned :1;
      unsigned MI2CIP:3;
    };
    struct {
      unsigned NVMIP0:1;
      unsigned NVMIP1:1;
      unsigned NVMIP2:1;
      unsigned :1;
      unsigned SI2CIP0:1;
      unsigned SI2CIP1:1;
      unsigned SI2CIP2:1;
      unsigned :1;
      unsigned MI2CIP0:1;
      unsigned MI2CIP1:1;
      unsigned MI2CIP2:1;
    };
  };
} IPC3BITS;
extern volatile IPC3BITS IPC3bits __attribute__((__sfr__));

extern volatile unsigned int  IPC4 __attribute__((__sfr__));
__extension__ typedef struct tagIPC4BITS {
  union {
    struct {
      unsigned INT1IP:3;
      unsigned :1;
      unsigned INT2IP:3;
      unsigned :1;
      unsigned PSEMIP:3;
      unsigned :1;
      unsigned PWM1IP:3;
    };
    struct {
      unsigned INT1IP0:1;
      unsigned INT1IP1:1;
      unsigned INT1IP2:1;
      unsigned :1;
      unsigned INT2IP0:1;
      unsigned INT2IP1:1;
      unsigned INT2IP2:1;
      unsigned :1;
      unsigned PSEMIP0:1;
      unsigned PSEMIP1:1;
      unsigned PSEMIP2:1;
      unsigned :1;
      unsigned PWM1IP0:1;
      unsigned PWM1IP1:1;
      unsigned PWM1IP2:1;
    };
  };
} IPC4BITS;
extern volatile IPC4BITS IPC4bits __attribute__((__sfr__));

extern volatile unsigned int  IPC5 __attribute__((__sfr__));
__extension__ typedef struct tagIPC5BITS {
  union {
    struct {
      unsigned PWM2IP:3;
      unsigned :1;
      unsigned PWM3IP:3;
      unsigned :1;
      unsigned PWM4IP:3;
    };
    struct {
      unsigned PWM2IP0:1;
      unsigned PWM2IP1:1;
      unsigned PWM2IP2:1;
      unsigned :1;
      unsigned PWM3IP0:1;
      unsigned PWM3IP1:1;
      unsigned PWM3IP2:1;
      unsigned :1;
      unsigned PWM4IP0:1;
      unsigned PWM4IP1:1;
      unsigned PWM4IP2:1;
    };
  };
} IPC5BITS;
extern volatile IPC5BITS IPC5bits __attribute__((__sfr__));

extern volatile unsigned int  IPC6 __attribute__((__sfr__));
__extension__ typedef struct tagIPC6BITS {
  union {
    struct {
      unsigned :12;
      unsigned CNIP:3;
    };
    struct {
      unsigned :12;
      unsigned CNIP0:1;
      unsigned CNIP1:1;
      unsigned CNIP2:1;
    };
  };
} IPC6BITS;
extern volatile IPC6BITS IPC6bits __attribute__((__sfr__));

extern volatile unsigned int  IPC7 __attribute__((__sfr__));
__extension__ typedef struct tagIPC7BITS {
  union {
    struct {
      unsigned :4;
      unsigned AC1IP:3;
      unsigned :1;
      unsigned AC2IP:3;
      unsigned :1;
      unsigned AC3IP:3;
    };
    struct {
      unsigned :4;
      unsigned AC1IP0:1;
      unsigned AC1IP1:1;
      unsigned AC1IP2:1;
      unsigned :1;
      unsigned AC2IP0:1;
      unsigned AC2IP1:1;
      unsigned AC2IP2:1;
      unsigned :1;
      unsigned AC3IP0:1;
      unsigned AC3IP1:1;
      unsigned AC3IP2:1;
    };
  };
} IPC7BITS;
extern volatile IPC7BITS IPC7bits __attribute__((__sfr__));

extern volatile unsigned int  IPC8 __attribute__((__sfr__));
__extension__ typedef struct tagIPC8BITS {
  union {
    struct {
      unsigned AC4IP:3;
    };
    struct {
      unsigned AC4IP0:1;
      unsigned AC4IP1:1;
      unsigned AC4IP2:1;
    };
  };
} IPC8BITS;
extern volatile IPC8BITS IPC8bits __attribute__((__sfr__));

extern volatile unsigned int  IPC9 __attribute__((__sfr__));
__extension__ typedef struct tagIPC9BITS {
  union {
    struct {
      unsigned :4;
      unsigned ADCP0IP:3;
      unsigned :1;
      unsigned ADCP1IP:3;
      unsigned :1;
      unsigned ADCP2IP:3;
    };
    struct {
      unsigned :4;
      unsigned ADCP0IP0:1;
      unsigned ADCP0IP1:1;
      unsigned ADCP0IP2:1;
      unsigned :1;
      unsigned ADCP1IP0:1;
      unsigned ADCP1IP1:1;
      unsigned ADCP1IP2:1;
      unsigned :1;
      unsigned ADCP2IP0:1;
      unsigned ADCP2IP1:1;
      unsigned ADCP2IP2:1;
    };
  };
} IPC9BITS;
extern volatile IPC9BITS IPC9bits __attribute__((__sfr__));

extern volatile unsigned int  IPC10 __attribute__((__sfr__));
__extension__ typedef struct tagIPC10BITS {
  union {
    struct {
      unsigned ADCP3IP:3;
    };
    struct {
      unsigned ADCP3IP0:1;
      unsigned ADCP3IP1:1;
      unsigned ADCP3IP2:1;
    };
  };
} IPC10BITS;
extern volatile IPC10BITS IPC10bits __attribute__((__sfr__));

extern volatile unsigned int  INTTREG __attribute__((__sfr__));
__extension__ typedef struct tagINTTREGBITS {
  union {
    struct {
      unsigned VECNUM:7;
      unsigned :1;
      unsigned ILR:4;
    };
    struct {
      unsigned VECNUM0:1;
      unsigned VECNUM1:1;
      unsigned VECNUM2:1;
      unsigned VECNUM3:1;
      unsigned VECNUM4:1;
      unsigned VECNUM5:1;
      unsigned VECNUM6:1;
      unsigned :1;
      unsigned ILR0:1;
      unsigned ILR1:1;
      unsigned ILR2:1;
      unsigned ILR3:1;
    };
  };
} INTTREGBITS;
extern volatile INTTREGBITS INTTREGbits __attribute__((__sfr__));

extern volatile unsigned int  TMR1 __attribute__((__sfr__));
extern volatile unsigned int  PR1 __attribute__((__sfr__));
extern volatile unsigned int  T1CON __attribute__((__sfr__));
__extension__ typedef struct tagT1CONBITS {
  union {
    struct {
      unsigned :1;
      unsigned TCS:1;
      unsigned TSYNC:1;
      unsigned :1;
      unsigned TCKPS:2;
      unsigned TGATE:1;
      unsigned :6;
      unsigned TSIDL:1;
      unsigned :1;
      unsigned TON:1;
    };
    struct {
      unsigned :4;
      unsigned TCKPS0:1;
      unsigned TCKPS1:1;
    };
  };
} T1CONBITS;
extern volatile T1CONBITS T1CONbits __attribute__((__sfr__));

extern volatile unsigned int  TMR2 __attribute__((__sfr__));
extern volatile unsigned int  TMR3HLD __attribute__((__sfr__));
extern volatile unsigned int  TMR3 __attribute__((__sfr__));
extern volatile unsigned int  PR2 __attribute__((__sfr__));
extern volatile unsigned int  PR3 __attribute__((__sfr__));
extern volatile unsigned int  T2CON __attribute__((__sfr__));
__extension__ typedef struct tagT2CONBITS {
  union {
    struct {
      unsigned :1;
      unsigned TCS:1;
      unsigned :1;
      unsigned T32:1;
      unsigned TCKPS:2;
      unsigned TGATE:1;
      unsigned :6;
      unsigned TSIDL:1;
      unsigned :1;
      unsigned TON:1;
    };
    struct {
      unsigned :4;
      unsigned TCKPS0:1;
      unsigned TCKPS1:1;
    };
  };
} T2CONBITS;
extern volatile T2CONBITS T2CONbits __attribute__((__sfr__));

extern volatile unsigned int  T3CON __attribute__((__sfr__));
__extension__ typedef struct tagT3CONBITS {
  union {
    struct {
      unsigned :1;
      unsigned TCS:1;
      unsigned :2;
      unsigned TCKPS:2;
      unsigned TGATE:1;
      unsigned :6;
      unsigned TSIDL:1;
      unsigned :1;
      unsigned TON:1;
    };
    struct {
      unsigned :4;
      unsigned TCKPS0:1;
      unsigned TCKPS1:1;
    };
  };
} T3CONBITS;
extern volatile T3CONBITS T3CONbits __attribute__((__sfr__));


/* Generic structure of entire SFR area for Input Capture modules */
typedef struct tagIC {
        unsigned int icxbuf;
        unsigned int icxcon;
} IC, *PIC;


/* SFR blocks for Input Capture modules */
extern volatile IC IC1 __attribute__((__sfr__));

extern volatile unsigned int  IC1BUF __attribute__((__sfr__));
extern volatile unsigned int  IC1CON __attribute__((__sfr__));
__extension__ typedef struct tagIC1CONBITS {
  union {
    struct {
      unsigned ICM:3;
      unsigned ICBNE:1;
      unsigned ICOV:1;
      unsigned ICI:2;
      unsigned ICTMR:1;
      unsigned :5;
      unsigned ICSIDL:1;
    };
    struct {
      unsigned ICM0:1;
      unsigned ICM1:1;
      unsigned ICM2:1;
      unsigned :2;
      unsigned ICI0:1;
      unsigned ICI1:1;
    };
  };
} IC1CONBITS;
extern volatile IC1CONBITS IC1CONbits __attribute__((__sfr__));


/* Generic structure of entire SFR area for Output Compare modules */
typedef struct tagOC {
        unsigned int ocxrs;
        unsigned int ocxr;
        unsigned int ocxcon;
} OC, *POC;


/* SFR blocks for Output Compare modules */
extern volatile OC OC1 __attribute__((__sfr__));

extern volatile unsigned int  OC1RS __attribute__((__sfr__));
extern volatile unsigned int  OC1R __attribute__((__sfr__));
extern volatile unsigned int  OC1CON __attribute__((__sfr__));
__extension__ typedef struct tagOC1CONBITS {
  union {
    struct {
      unsigned OCM:3;
      unsigned OCTSEL:1;
      unsigned OCFLT:1;
      unsigned :8;
      unsigned OCSIDL:1;
    };
    struct {
      unsigned OCM0:1;
      unsigned OCM1:1;
      unsigned OCM2:1;
    };
  };
} OC1CONBITS;
extern volatile OC1CONBITS OC1CONbits __attribute__((__sfr__));


/* SFR blocks for Output Compare modules */
extern volatile OC OC2 __attribute__((__sfr__));

extern volatile unsigned int  OC2RS __attribute__((__sfr__));
extern volatile unsigned int  OC2R __attribute__((__sfr__));
extern volatile unsigned int  OC2CON __attribute__((__sfr__));
__extension__ typedef struct tagOC2CONBITS {
  union {
    struct {
      unsigned OCM:3;
      unsigned OCTSEL:1;
      unsigned OCFLT:1;
      unsigned :8;
      unsigned OCSIDL:1;
    };
    struct {
      unsigned OCM0:1;
      unsigned OCM1:1;
      unsigned OCM2:1;
    };
  };
} OC2CONBITS;
extern volatile OC2CONBITS OC2CONbits __attribute__((__sfr__));

extern volatile unsigned int  I2CRCV __attribute__((__sfr__));
__extension__ typedef struct tagI2CRCVBITS {
  union {
    struct {
      unsigned I2CRCV:8;
    };
    struct {
      unsigned I2CRCV0:1;
      unsigned I2CRCV1:1;
      unsigned I2CRCV2:1;
      unsigned I2CRCV3:1;
      unsigned I2CRCV4:1;
      unsigned I2CRCV5:1;
      unsigned I2CRCV6:1;
      unsigned I2CRCV7:1;
    };
  };
} I2CRCVBITS;
extern volatile I2CRCVBITS I2CRCVbits __attribute__((__sfr__));

extern volatile unsigned int  I2CTRN __attribute__((__sfr__));
__extension__ typedef struct tagI2CTRNBITS {
  union {
    struct {
      unsigned I2CTRN:8;
    };
    struct {
      unsigned I2CTRN0:1;
      unsigned I2CTRN1:1;
      unsigned I2CTRN2:1;
      unsigned I2CTRN3:1;
      unsigned I2CTRN4:1;
      unsigned I2CTRN5:1;
      unsigned I2CTRN6:1;
      unsigned I2CTRN7:1;
    };
  };
} I2CTRNBITS;
extern volatile I2CTRNBITS I2CTRNbits __attribute__((__sfr__));

extern volatile unsigned int  I2CBRG __attribute__((__sfr__));
typedef struct tagI2CBRGBITS {
  unsigned I2CBRG:9;
} I2CBRGBITS;
extern volatile I2CBRGBITS I2CBRGbits __attribute__((__sfr__));

extern volatile unsigned int  I2CCON __attribute__((__sfr__));
typedef struct tagI2CCONBITS {
  unsigned SEN:1;
  unsigned RSEN:1;
  unsigned PEN:1;
  unsigned RCEN:1;
  unsigned ACKEN:1;
  unsigned ACKDT:1;
  unsigned STREN:1;
  unsigned GCEN:1;
  unsigned SMEN:1;
  unsigned DISSLW:1;
  unsigned A10M:1;
  unsigned IPMIEN:1;
  unsigned SCLREL:1;
  unsigned I2CSIDL:1;
  unsigned :1;
  unsigned I2CEN:1;
} I2CCONBITS;
extern volatile I2CCONBITS I2CCONbits __attribute__((__sfr__));

extern volatile unsigned int  I2CSTAT __attribute__((__sfr__));
__extension__ typedef struct tagI2CSTATBITS {
  union {
    struct {
      unsigned TBF:1;
      unsigned RBF:1;
      unsigned R_NOT_W:1;
      unsigned S:1;
      unsigned P:1;
      unsigned D_NOT_A:1;
      unsigned I2COV:1;
      unsigned IWCOL:1;
      unsigned ADD10:1;
      unsigned GCSTAT:1;
      unsigned BCL:1;
      unsigned :3;
      unsigned TRSTAT:1;
      unsigned ACKSTAT:1;
    };
    struct {
      unsigned :2;
      unsigned R_W:1;
      unsigned :2;
      unsigned D_A:1;
    };
  };
} I2CSTATBITS;
extern volatile I2CSTATBITS I2CSTATbits __attribute__((__sfr__));

extern volatile unsigned int  I2CADD __attribute__((__sfr__));
typedef struct tagI2CADDBITS {
  unsigned I2CADD:10;
} I2CADDBITS;
extern volatile I2CADDBITS I2CADDbits __attribute__((__sfr__));


/* Generic structure of entire SFR area for each UART module */
typedef struct tagUART {
        unsigned int uxmode;
        unsigned int uxsta;
        unsigned int uxtxreg;
        unsigned int uxrxreg;
        unsigned int uxbrg;
} UART, *PUART;

#define UxMODEBITS U1MODEBITS
#define UxSTABITS U1STABITS
#define UxTXREGBITS U1TXREGBITS
#define UxRXREGBITS U1RXREGBITS
#define UxBRGBITS U1BRGBITS


/* SFR blocks for each UART module */
extern volatile UART UART1 __attribute__((__sfr__));

extern volatile unsigned int  U1MODE __attribute__((__sfr__));
__extension__ typedef struct tagU1MODEBITS {
  union {
    struct {
      unsigned STSEL:1;
      unsigned PDSEL:2;
      unsigned BRGH:1;
      unsigned RXINV:1;
      unsigned ABAUD:1;
      unsigned LPBACK:1;
      unsigned WAKE:1;
      unsigned :2;
      unsigned ALTIO:1;
      unsigned :1;
      unsigned IREN:1;
      unsigned USIDL:1;
      unsigned :1;
      unsigned UARTEN:1;
    };
    struct {
      unsigned :1;
      unsigned PDSEL0:1;
      unsigned PDSEL1:1;
    };
  };
} U1MODEBITS;
extern volatile U1MODEBITS U1MODEbits __attribute__((__sfr__));

extern volatile unsigned int  U1STA __attribute__((__sfr__));
__extension__ typedef struct tagU1STABITS {
  union {
    struct {
      unsigned URXDA:1;
      unsigned OERR:1;
      unsigned FERR:1;
      unsigned PERR:1;
      unsigned RIDLE:1;
      unsigned ADDEN:1;
      unsigned URXISEL:2;
      unsigned TRMT:1;
      unsigned UTXBF:1;
      unsigned UTXEN:1;
      unsigned UTXBRK:1;
      unsigned :1;
      unsigned UTXISEL0:1;
      unsigned UTXINV:1;
      unsigned UTXISEL1:1;
    };
    struct {
      unsigned :6;
      unsigned URXISEL0:1;
      unsigned URXISEL1:1;
    };
  };
} U1STABITS;
extern volatile U1STABITS U1STAbits __attribute__((__sfr__));

extern volatile unsigned int  U1TXREG __attribute__((__sfr__));
typedef struct tagU1TXREGBITS {
  unsigned UTXREG0:1;
  unsigned UTXREG1:1;
  unsigned UTXREG2:1;
  unsigned UTXREG3:1;
  unsigned UTXREG4:1;
  unsigned UTXREG5:1;
  unsigned UTXREG6:1;
  unsigned UTXREG7:1;
} U1TXREGBITS;
extern volatile U1TXREGBITS U1TXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U1RXREG __attribute__((__sfr__));
typedef struct tagU1RXREGBITS {
  unsigned URXREG0:1;
  unsigned URXREG1:1;
  unsigned URXREG2:1;
  unsigned URXREG3:1;
  unsigned URXREG4:1;
  unsigned URXREG5:1;
  unsigned URXREG6:1;
  unsigned URXREG7:1;
} U1RXREGBITS;
extern volatile U1RXREGBITS U1RXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U1BRG __attribute__((__sfr__));

/* Generic structure of entire SFR area for each SPI module */
typedef struct tagSPI {
        unsigned int spixstat;
        unsigned int spixcon1;
        unsigned int spixcon2;
        unsigned int unused;
        unsigned int spixbuf;
} SPI, *PSPI;

#define SPIxSTATBITS SPI1STATBITS
#define SPIxCONBITS SPI1CONBITS


/* SFR blocks for each SPI module */
extern volatile SPI SPI1 __attribute__((__sfr__));

extern volatile unsigned int  SPI1STAT __attribute__((__sfr__));
typedef struct tagSPI1STATBITS {
  unsigned SPIRBF:1;
  unsigned SPITBF:1;
  unsigned :4;
  unsigned SPIROV:1;
  unsigned :6;
  unsigned SPISIDL:1;
  unsigned :1;
  unsigned SPIEN:1;
} SPI1STATBITS;
extern volatile SPI1STATBITS SPI1STATbits __attribute__((__sfr__));

extern volatile unsigned int  SPI1CON1 __attribute__((__sfr__));
__extension__ typedef struct tagSPI1CON1BITS {
  union {
    struct {
      unsigned PPRE0:1;
      unsigned PPRE1:1;
      unsigned SPRE0:1;
      unsigned SPRE1:1;
      unsigned SPRE2:1;
      unsigned MSTEN:1;
      unsigned CKP:1;
      unsigned SSEN:1;
      unsigned CKE:1;
      unsigned SMP:1;
      unsigned MODE16:1;
      unsigned DISSDO:1;
      unsigned DISSCK:1;
    };
    struct {
      unsigned PPRE:2;
      unsigned SPRE:3;
    };
  };
} SPI1CON1BITS;
extern volatile SPI1CON1BITS SPI1CON1bits __attribute__((__sfr__));

extern volatile unsigned int  SPI1CON2 __attribute__((__sfr__));
typedef struct tagSPI1CON2BITS {
  unsigned :1;
  unsigned FRMDLY:1;
  unsigned :11;
  unsigned FRMPOL:1;
  unsigned SPIFSD:1;
  unsigned FRMEN:1;
} SPI1CON2BITS;
extern volatile SPI1CON2BITS SPI1CON2bits __attribute__((__sfr__));

extern volatile unsigned int  SPI1BUF __attribute__((__sfr__));
extern volatile unsigned int  TRISA __attribute__((__sfr__));
typedef struct tagTRISABITS {
  unsigned :9;
  unsigned TRISA9:1;
} TRISABITS;
extern volatile TRISABITS TRISAbits __attribute__((__sfr__));

extern volatile unsigned int  PORTA __attribute__((__sfr__));
typedef struct tagPORTABITS {
  unsigned :9;
  unsigned RA9:1;
} PORTABITS;
extern volatile PORTABITS PORTAbits __attribute__((__sfr__));

extern volatile unsigned int  LATA __attribute__((__sfr__));
typedef struct tagLATABITS {
  unsigned :9;
  unsigned LATA9:1;
} LATABITS;
extern volatile LATABITS LATAbits __attribute__((__sfr__));

extern volatile unsigned int  TRISB __attribute__((__sfr__));
typedef struct tagTRISBBITS {
  unsigned TRISB0:1;
  unsigned TRISB1:1;
  unsigned TRISB2:1;
  unsigned TRISB3:1;
  unsigned TRISB4:1;
  unsigned TRISB5:1;
  unsigned TRISB6:1;
  unsigned TRISB7:1;
} TRISBBITS;
extern volatile TRISBBITS TRISBbits __attribute__((__sfr__));

extern volatile unsigned int  PORTB __attribute__((__sfr__));
typedef struct tagPORTBBITS {
  unsigned RB0:1;
  unsigned RB1:1;
  unsigned RB2:1;
  unsigned RB3:1;
  unsigned RB4:1;
  unsigned RB5:1;
  unsigned RB6:1;
  unsigned RB7:1;
} PORTBBITS;
extern volatile PORTBBITS PORTBbits __attribute__((__sfr__));

extern volatile unsigned int  LATB __attribute__((__sfr__));
typedef struct tagLATBBITS {
  unsigned LATB0:1;
  unsigned LATB1:1;
  unsigned LATB2:1;
  unsigned LATB3:1;
  unsigned LATB4:1;
  unsigned LATB5:1;
  unsigned LATB6:1;
  unsigned LATB7:1;
} LATBBITS;
extern volatile LATBBITS LATBbits __attribute__((__sfr__));

extern volatile unsigned int  TRISD __attribute__((__sfr__));
typedef struct tagTRISDBITS {
  unsigned TRISD0:1;
} TRISDBITS;
extern volatile TRISDBITS TRISDbits __attribute__((__sfr__));

extern volatile unsigned int  PORTD __attribute__((__sfr__));
typedef struct tagPORTDBITS {
  unsigned RD0:1;
} PORTDBITS;
extern volatile PORTDBITS PORTDbits __attribute__((__sfr__));

extern volatile unsigned int  LATD __attribute__((__sfr__));
typedef struct tagLATDBITS {
  unsigned LATD0:1;
} LATDBITS;
extern volatile LATDBITS LATDbits __attribute__((__sfr__));

extern volatile unsigned int  TRISE __attribute__((__sfr__));
typedef struct tagTRISEBITS {
  unsigned TRISE0:1;
  unsigned TRISE1:1;
  unsigned TRISE2:1;
  unsigned TRISE3:1;
  unsigned TRISE4:1;
  unsigned TRISE5:1;
  unsigned TRISE6:1;
  unsigned TRISE7:1;
} TRISEBITS;
extern volatile TRISEBITS TRISEbits __attribute__((__sfr__));

extern volatile unsigned int  PORTE __attribute__((__sfr__));
typedef struct tagPORTEBITS {
  unsigned RE0:1;
  unsigned RE1:1;
  unsigned RE2:1;
  unsigned RE3:1;
  unsigned RE4:1;
  unsigned RE5:1;
  unsigned RE6:1;
  unsigned RE7:1;
} PORTEBITS;
extern volatile PORTEBITS PORTEbits __attribute__((__sfr__));

extern volatile unsigned int  LATE __attribute__((__sfr__));
typedef struct tagLATEBITS {
  unsigned LATE0:1;
  unsigned LATE1:1;
  unsigned LATE2:1;
  unsigned LATE3:1;
  unsigned LATE4:1;
  unsigned LATE5:1;
  unsigned LATE6:1;
  unsigned LATE7:1;
} LATEBITS;
extern volatile LATEBITS LATEbits __attribute__((__sfr__));

extern volatile unsigned int  TRISF __attribute__((__sfr__));
typedef struct tagTRISFBITS {
  unsigned :6;
  unsigned TRISF6:1;
  unsigned TRISF7:1;
  unsigned TRISF8:1;
} TRISFBITS;
extern volatile TRISFBITS TRISFbits __attribute__((__sfr__));

extern volatile unsigned int  PORTF __attribute__((__sfr__));
typedef struct tagPORTFBITS {
  unsigned :6;
  unsigned RF6:1;
  unsigned RF7:1;
  unsigned RF8:1;
} PORTFBITS;
extern volatile PORTFBITS PORTFbits __attribute__((__sfr__));

extern volatile unsigned int  LATF __attribute__((__sfr__));
typedef struct tagLATFBITS {
  unsigned :6;
  unsigned LATF6:1;
  unsigned LATF7:1;
  unsigned LATF8:1;
} LATFBITS;
extern volatile LATFBITS LATFbits __attribute__((__sfr__));

extern volatile unsigned int  ADCON __attribute__((__sfr__));
__extension__ typedef struct tagADCONBITS {
  union {
    struct {
      unsigned ADCS:3;
      unsigned :2;
      unsigned SEQSAMP:1;
      unsigned ORDER:1;
      unsigned EIE:1;
      unsigned FORM:1;
      unsigned :1;
      unsigned GSWTRG:1;
      unsigned :2;
      unsigned ADSIDL:1;
      unsigned :1;
      unsigned ADON:1;
    };
    struct {
      unsigned ADCS0:1;
      unsigned ADCS1:1;
      unsigned ADCS2:1;
    };
  };
} ADCONBITS;
extern volatile ADCONBITS ADCONbits __attribute__((__sfr__));

extern volatile unsigned int  ADPCFG __attribute__((__sfr__));
typedef struct tagADPCFGBITS {
  unsigned PCFG0:1;
  unsigned PCFG1:1;
  unsigned PCFG2:1;
  unsigned PCFG3:1;
  unsigned PCFG4:1;
  unsigned PCFG5:1;
  unsigned PCFG6:1;
  unsigned PCFG7:1;
  unsigned PCFG8:1;
  unsigned PCFG9:1;
  unsigned PCFG10:1;
  unsigned PCFG11:1;
} ADPCFGBITS;
extern volatile ADPCFGBITS ADPCFGbits __attribute__((__sfr__));

extern volatile unsigned int  ADSTAT __attribute__((__sfr__));
typedef struct tagADSTATBITS {
  unsigned P0RDY:1;
  unsigned P1RDY:1;
  unsigned P2RDY:1;
  unsigned P3RDY:1;
} ADSTATBITS;
extern volatile ADSTATBITS ADSTATbits __attribute__((__sfr__));

extern volatile unsigned int  ADBASE __attribute__((__sfr__));
typedef struct tagADBASEBITS {
  unsigned :1;
  unsigned ADBASE:15;
} ADBASEBITS;
extern volatile ADBASEBITS ADBASEbits __attribute__((__sfr__));

extern volatile unsigned int  ADCPC0 __attribute__((__sfr__));
__extension__ typedef struct tagADCPC0BITS {
  union {
    struct {
      unsigned TRGSRC0:5;
      unsigned SWTRG0:1;
      unsigned PEND0:1;
      unsigned IRQEN0:1;
      unsigned TRGSRC1:5;
      unsigned SWTRG1:1;
      unsigned PEND1:1;
      unsigned IRQEN1:1;
    };
    struct {
      unsigned TRGSRC00:1;
      unsigned TRGSRC01:1;
      unsigned TRGSRC02:1;
      unsigned TRGSRC03:1;
      unsigned TRGSRC04:1;
      unsigned :3;
      unsigned TRGSRC10:1;
      unsigned TRGSRC11:1;
      unsigned TRGSRC12:1;
      unsigned TRGSRC13:1;
      unsigned TRGSRC14:1;
    };
  };
} ADCPC0BITS;
extern volatile ADCPC0BITS ADCPC0bits __attribute__((__sfr__));

extern volatile unsigned int  ADCPC1 __attribute__((__sfr__));
__extension__ typedef struct tagADCPC1BITS {
  union {
    struct {
      unsigned TRGSRC2:5;
      unsigned SWTRG2:1;
      unsigned PEND2:1;
      unsigned IRQEN2:1;
      unsigned TRGSRC3:5;
      unsigned SWTRG3:1;
      unsigned PEND3:1;
      unsigned IRQEN3:1;
    };
    struct {
      unsigned TRGSRC20:1;
      unsigned TRGSRC21:1;
      unsigned TRGSRC22:1;
      unsigned TRGSRC23:1;
      unsigned TRGSRC24:1;
      unsigned :3;
      unsigned TRGSRC30:1;
      unsigned TRGSRC31:1;
      unsigned TRGSRC32:1;
      unsigned TRGSRC33:1;
      unsigned TRGSRC34:1;
    };
  };
} ADCPC1BITS;
extern volatile ADCPC1BITS ADCPC1bits __attribute__((__sfr__));

extern volatile unsigned int  ADCBUF0 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF1 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF2 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF3 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF4 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF5 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF6 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF7 __attribute__((__sfr__));
extern volatile unsigned int  PTCON __attribute__((__sfr__));
__extension__ typedef struct tagPTCONBITS {
  union {
    struct {
      unsigned SEVTPS:4;
      unsigned SYNCSRC:3;
      unsigned SYNCEN:1;
      unsigned SYNCOEN:1;
      unsigned SYNCPOL:1;
      unsigned EIPU:1;
      unsigned SEIEN:1;
      unsigned SESTAT:1;
      unsigned PTSIDL:1;
      unsigned :1;
      unsigned PTEN:1;
    };
    struct {
      unsigned SEVTPS0:1;
      unsigned SEVTPS1:1;
      unsigned SEVTPS2:1;
      unsigned SEVTPS3:1;
      unsigned SYNCSRC0:1;
      unsigned SYNCSRC1:1;
      unsigned SYNCSRC2:1;
    };
  };
} PTCONBITS;
extern volatile PTCONBITS PTCONbits __attribute__((__sfr__));

extern volatile unsigned int  PTPER __attribute__((__sfr__));
typedef struct tagPTPERBITS {
  unsigned :3;
  unsigned PTPER:13;
} PTPERBITS;
extern volatile PTPERBITS PTPERbits __attribute__((__sfr__));

extern volatile unsigned int  MDC __attribute__((__sfr__));
extern volatile unsigned int  SEVTCMP __attribute__((__sfr__));
typedef struct tagSEVTCMPBITS {
  unsigned :3;
  unsigned SEVTCMP:13;
} SEVTCMPBITS;
extern volatile SEVTCMPBITS SEVTCMPbits __attribute__((__sfr__));

extern volatile unsigned int  PWMCON1 __attribute__((__sfr__));
__extension__ typedef struct tagPWMCON1BITS {
  union {
    struct {
      unsigned IUE:1;
      unsigned XPRES:1;
      unsigned :4;
      unsigned DTC:2;
      unsigned MDCS:1;
      unsigned ITB:1;
      unsigned TRGIEN:1;
      unsigned CLIEN:1;
      unsigned FLTIEN:1;
      unsigned TRGSTAT:1;
      unsigned CLSTAT:1;
      unsigned FLTSTAT:1;
    };
    struct {
      unsigned :6;
      unsigned DTC0:1;
      unsigned DTC1:1;
    };
  };
} PWMCON1BITS;
extern volatile PWMCON1BITS PWMCON1bits __attribute__((__sfr__));

extern volatile unsigned int  IOCON1 __attribute__((__sfr__));
__extension__ typedef struct tagIOCON1BITS {
  union {
    struct {
      unsigned OSYNC:1;
      unsigned :1;
      unsigned CLDAT:2;
      unsigned FLTDAT:2;
      unsigned OVRDAT:2;
      unsigned OVRENL:1;
      unsigned OVRENH:1;
      unsigned PMOD:2;
      unsigned POLL:1;
      unsigned POLH:1;
      unsigned PENL:1;
      unsigned PENH:1;
    };
    struct {
      unsigned :2;
      unsigned CLDAT0:1;
      unsigned CLDAT1:1;
      unsigned FLTDAT0:1;
      unsigned FLTDAT1:1;
      unsigned OVRDAT0:1;
      unsigned OVRDAT1:1;
      unsigned :2;
      unsigned PMOD0:1;
      unsigned PMOD1:1;
    };
  };
} IOCON1BITS;
extern volatile IOCON1BITS IOCON1bits __attribute__((__sfr__));

extern volatile unsigned int  FCLCON1 __attribute__((__sfr__));
__extension__ typedef struct tagFCLCON1BITS {
  union {
    struct {
      unsigned FLTMOD:2;
      unsigned FLTPOL:1;
      unsigned FLTSRC:4;
      unsigned CLMODE:1;
      unsigned CLPOL:1;
      unsigned CLSRC:4;
    };
    struct {
      unsigned FLTMOD0:1;
      unsigned FLTMOD1:1;
      unsigned :1;
      unsigned FLTSRC0:1;
      unsigned FLTSRC1:1;
      unsigned FLTSRC2:1;
      unsigned FLTSRC3:1;
      unsigned :2;
      unsigned CLSRC0:1;
      unsigned CLSRC1:1;
      unsigned CLSRC2:1;
      unsigned CLSRC3:1;
    };
  };
} FCLCON1BITS;
extern volatile FCLCON1BITS FCLCON1bits __attribute__((__sfr__));

extern volatile unsigned int  PDC1 __attribute__((__sfr__));
extern volatile unsigned int  PHASE1 __attribute__((__sfr__));
extern volatile unsigned int  DTR1 __attribute__((__sfr__));
extern volatile unsigned int  ALTDTR1 __attribute__((__sfr__));
extern volatile unsigned int  TRIG1 __attribute__((__sfr__));
typedef struct tagTRIG1BITS {
  unsigned :4;
  unsigned TRIG:12;
} TRIG1BITS;
extern volatile TRIG1BITS TRIG1bits __attribute__((__sfr__));

extern volatile unsigned int  TRGCON1 __attribute__((__sfr__));
__extension__ typedef struct tagTRGCON1BITS {
  union {
    struct {
      unsigned TRGSTRT:6;
      unsigned :7;
      unsigned TRGDIV:3;
    };
    struct {
      unsigned TRGSTRT0:1;
      unsigned TRGSTRT1:1;
      unsigned TRGSTRT2:1;
      unsigned TRGSTRT3:1;
      unsigned TRGSTRT4:1;
      unsigned TRGSTRT5:1;
      unsigned :7;
      unsigned TRGDIV0:1;
      unsigned TRGDIV1:1;
      unsigned TRGDIV2:1;
    };
  };
} TRGCON1BITS;
extern volatile TRGCON1BITS TRGCON1bits __attribute__((__sfr__));

extern volatile unsigned int  LEBCON1 __attribute__((__sfr__));
__extension__ typedef struct tagLEBCON1BITS {
  union {
    struct {
      unsigned :3;
      unsigned LEB:7;
      unsigned CLLEBEN:1;
      unsigned FLTLEBEN:1;
      unsigned PLF:1;
      unsigned PLR:1;
      unsigned PHF:1;
      unsigned PHR:1;
    };
    struct {
      unsigned :3;
      unsigned LEB0:1;
      unsigned LEB1:1;
      unsigned LEB2:1;
      unsigned LEB3:1;
      unsigned LEB4:1;
      unsigned LEB5:1;
      unsigned LEB6:1;
    };
  };
} LEBCON1BITS;
extern volatile LEBCON1BITS LEBCON1bits __attribute__((__sfr__));

extern volatile unsigned int  PWMCON2 __attribute__((__sfr__));
__extension__ typedef struct tagPWMCON2BITS {
  union {
    struct {
      unsigned IUE:1;
      unsigned XPRES:1;
      unsigned :4;
      unsigned DTC:2;
      unsigned MDCS:1;
      unsigned ITB:1;
      unsigned TRGIEN:1;
      unsigned CLIEN:1;
      unsigned FLTIEN:1;
      unsigned TRGSTAT:1;
      unsigned CLSTAT:1;
      unsigned FLTSTAT:1;
    };
    struct {
      unsigned :6;
      unsigned DTC0:1;
      unsigned DTC1:1;
    };
  };
} PWMCON2BITS;
extern volatile PWMCON2BITS PWMCON2bits __attribute__((__sfr__));

extern volatile unsigned int  IOCON2 __attribute__((__sfr__));
__extension__ typedef struct tagIOCON2BITS {
  union {
    struct {
      unsigned OSYNC:1;
      unsigned :1;
      unsigned CLDAT:2;
      unsigned FLTDAT:2;
      unsigned OVRDAT:2;
      unsigned OVRENL:1;
      unsigned OVRENH:1;
      unsigned PMOD:2;
      unsigned POLL:1;
      unsigned POLH:1;
      unsigned PENL:1;
      unsigned PENH:1;
    };
    struct {
      unsigned :2;
      unsigned CLDAT0:1;
      unsigned CLDAT1:1;
      unsigned FLTDAT0:1;
      unsigned FLTDAT1:1;
      unsigned OVRDAT0:1;
      unsigned OVRDAT1:1;
      unsigned :2;
      unsigned PMOD0:1;
      unsigned PMOD1:1;
    };
  };
} IOCON2BITS;
extern volatile IOCON2BITS IOCON2bits __attribute__((__sfr__));

extern volatile unsigned int  FCLCON2 __attribute__((__sfr__));
__extension__ typedef struct tagFCLCON2BITS {
  union {
    struct {
      unsigned FLTMOD:2;
      unsigned FLTPOL:1;
      unsigned FLTSRC:4;
      unsigned CLMODE:1;
      unsigned CLPOL:1;
      unsigned CLSRC:4;
    };
    struct {
      unsigned FLTMOD0:1;
      unsigned FLTMOD1:1;
      unsigned :1;
      unsigned FLTSRC0:1;
      unsigned FLTSRC1:1;
      unsigned FLTSRC2:1;
      unsigned FLTSRC3:1;
      unsigned :2;
      unsigned CLSRC0:1;
      unsigned CLSRC1:1;
      unsigned CLSRC2:1;
      unsigned CLSRC3:1;
    };
  };
} FCLCON2BITS;
extern volatile FCLCON2BITS FCLCON2bits __attribute__((__sfr__));

extern volatile unsigned int  PDC2 __attribute__((__sfr__));
extern volatile unsigned int  PHASE2 __attribute__((__sfr__));
extern volatile unsigned int  DTR2 __attribute__((__sfr__));
extern volatile unsigned int  ALTDTR2 __attribute__((__sfr__));
extern volatile unsigned int  TRIG2 __attribute__((__sfr__));
typedef struct tagTRIG2BITS {
  unsigned :4;
  unsigned TRIG:12;
} TRIG2BITS;
extern volatile TRIG2BITS TRIG2bits __attribute__((__sfr__));

extern volatile unsigned int  TRGCON2 __attribute__((__sfr__));
__extension__ typedef struct tagTRGCON2BITS {
  union {
    struct {
      unsigned TRGSTRT:6;
      unsigned :7;
      unsigned TRGDIV:3;
    };
    struct {
      unsigned TRGSTRT0:1;
      unsigned TRGSTRT1:1;
      unsigned TRGSTRT2:1;
      unsigned TRGSTRT3:1;
      unsigned TRGSTRT4:1;
      unsigned TRGSTRT5:1;
      unsigned :7;
      unsigned TRGDIV0:1;
      unsigned TRGDIV1:1;
      unsigned TRGDIV2:1;
    };
  };
} TRGCON2BITS;
extern volatile TRGCON2BITS TRGCON2bits __attribute__((__sfr__));

extern volatile unsigned int  LEBCON2 __attribute__((__sfr__));
__extension__ typedef struct tagLEBCON2BITS {
  union {
    struct {
      unsigned :3;
      unsigned LEB:7;
      unsigned CLLEBEN:1;
      unsigned FLTLEBEN:1;
      unsigned PLF:1;
      unsigned PLR:1;
      unsigned PHF:1;
      unsigned PHR:1;
    };
    struct {
      unsigned :3;
      unsigned LEB0:1;
      unsigned LEB1:1;
      unsigned LEB2:1;
      unsigned LEB3:1;
      unsigned LEB4:1;
      unsigned LEB5:1;
      unsigned LEB6:1;
    };
  };
} LEBCON2BITS;
extern volatile LEBCON2BITS LEBCON2bits __attribute__((__sfr__));

extern volatile unsigned int  PWMCON3 __attribute__((__sfr__));
__extension__ typedef struct tagPWMCON3BITS {
  union {
    struct {
      unsigned IUE:1;
      unsigned XPRES:1;
      unsigned :4;
      unsigned DTC:2;
      unsigned MDCS:1;
      unsigned ITB:1;
      unsigned TRGIEN:1;
      unsigned CLIEN:1;
      unsigned FLTIEN:1;
      unsigned TRGSTAT:1;
      unsigned CLSTAT:1;
      unsigned FLTSTAT:1;
    };
    struct {
      unsigned :6;
      unsigned DTC0:1;
      unsigned DTC1:1;
    };
  };
} PWMCON3BITS;
extern volatile PWMCON3BITS PWMCON3bits __attribute__((__sfr__));

extern volatile unsigned int  IOCON3 __attribute__((__sfr__));
__extension__ typedef struct tagIOCON3BITS {
  union {
    struct {
      unsigned OSYNC:1;
      unsigned :1;
      unsigned CLDAT:2;
      unsigned FLTDAT:2;
      unsigned OVRDAT:2;
      unsigned OVRENL:1;
      unsigned OVRENH:1;
      unsigned PMOD:2;
      unsigned POLL:1;
      unsigned POLH:1;
      unsigned PENL:1;
      unsigned PENH:1;
    };
    struct {
      unsigned :2;
      unsigned CLDAT0:1;
      unsigned CLDAT1:1;
      unsigned FLTDAT0:1;
      unsigned FLTDAT1:1;
      unsigned OVRDAT0:1;
      unsigned OVRDAT1:1;
      unsigned :2;
      unsigned PMOD0:1;
      unsigned PMOD1:1;
    };
  };
} IOCON3BITS;
extern volatile IOCON3BITS IOCON3bits __attribute__((__sfr__));

extern volatile unsigned int  FCLCON3 __attribute__((__sfr__));
__extension__ typedef struct tagFCLCON3BITS {
  union {
    struct {
      unsigned FLTMOD:2;
      unsigned FLTPOL:1;
      unsigned FLTSRC:4;
      unsigned CLMODE:1;
      unsigned CLPOL:1;
      unsigned CLSRC:4;
    };
    struct {
      unsigned FLTMOD0:1;
      unsigned FLTMOD1:1;
      unsigned :1;
      unsigned FLTSRC0:1;
      unsigned FLTSRC1:1;
      unsigned FLTSRC2:1;
      unsigned FLTSRC3:1;
      unsigned :2;
      unsigned CLSRC0:1;
      unsigned CLSRC1:1;
      unsigned CLSRC2:1;
      unsigned CLSRC3:1;
    };
  };
} FCLCON3BITS;
extern volatile FCLCON3BITS FCLCON3bits __attribute__((__sfr__));

extern volatile unsigned int  PDC3 __attribute__((__sfr__));
extern volatile unsigned int  PHASE3 __attribute__((__sfr__));
extern volatile unsigned int  DTR3 __attribute__((__sfr__));
extern volatile unsigned int  ALTDTR3 __attribute__((__sfr__));
extern volatile unsigned int  TRIG3 __attribute__((__sfr__));
typedef struct tagTRIG3BITS {
  unsigned :4;
  unsigned TRIG:12;
} TRIG3BITS;
extern volatile TRIG3BITS TRIG3bits __attribute__((__sfr__));

extern volatile unsigned int  TRGCON3 __attribute__((__sfr__));
__extension__ typedef struct tagTRGCON3BITS {
  union {
    struct {
      unsigned TRGSTRT:6;
      unsigned :7;
      unsigned TRGDIV:3;
    };
    struct {
      unsigned TRGSTRT0:1;
      unsigned TRGSTRT1:1;
      unsigned TRGSTRT2:1;
      unsigned TRGSTRT3:1;
      unsigned TRGSTRT4:1;
      unsigned TRGSTRT5:1;
      unsigned :7;
      unsigned TRGDIV0:1;
      unsigned TRGDIV1:1;
      unsigned TRGDIV2:1;
    };
  };
} TRGCON3BITS;
extern volatile TRGCON3BITS TRGCON3bits __attribute__((__sfr__));

extern volatile unsigned int  LEBCON3 __attribute__((__sfr__));
__extension__ typedef struct tagLEBCON3BITS {
  union {
    struct {
      unsigned :3;
      unsigned LEB:7;
      unsigned CLLEBEN:1;
      unsigned FLTLEBEN:1;
      unsigned PLF:1;
      unsigned PLR:1;
      unsigned PHF:1;
      unsigned PHR:1;
    };
    struct {
      unsigned :3;
      unsigned LEB0:1;
      unsigned LEB1:1;
      unsigned LEB2:1;
      unsigned LEB3:1;
      unsigned LEB4:1;
      unsigned LEB5:1;
      unsigned LEB6:1;
    };
  };
} LEBCON3BITS;
extern volatile LEBCON3BITS LEBCON3bits __attribute__((__sfr__));

extern volatile unsigned int  PWMCON4 __attribute__((__sfr__));
__extension__ typedef struct tagPWMCON4BITS {
  union {
    struct {
      unsigned IUE:1;
      unsigned XPRES:1;
      unsigned :4;
      unsigned DTC:2;
      unsigned MDCS:1;
      unsigned ITB:1;
      unsigned TRGIEN:1;
      unsigned CLIEN:1;
      unsigned FLTIEN:1;
      unsigned TRGSTAT:1;
      unsigned CLSTAT:1;
      unsigned FLTSTAT:1;
    };
    struct {
      unsigned :6;
      unsigned DTC0:1;
      unsigned DTC1:1;
    };
  };
} PWMCON4BITS;
extern volatile PWMCON4BITS PWMCON4bits __attribute__((__sfr__));

extern volatile unsigned int  IOCON4 __attribute__((__sfr__));
__extension__ typedef struct tagIOCON4BITS {
  union {
    struct {
      unsigned OSYNC:1;
      unsigned :1;
      unsigned CLDAT:2;
      unsigned FLTDAT:2;
      unsigned OVRDAT:2;
      unsigned OVRENL:1;
      unsigned OVRENH:1;
      unsigned PMOD:2;
      unsigned POLL:1;
      unsigned POLH:1;
      unsigned PENL:1;
      unsigned PENH:1;
    };
    struct {
      unsigned :2;
      unsigned CLDAT0:1;
      unsigned CLDAT1:1;
      unsigned FLTDAT0:1;
      unsigned FLTDAT1:1;
      unsigned OVRDAT0:1;
      unsigned OVRDAT1:1;
      unsigned :2;
      unsigned PMOD0:1;
      unsigned PMOD1:1;
    };
  };
} IOCON4BITS;
extern volatile IOCON4BITS IOCON4bits __attribute__((__sfr__));

extern volatile unsigned int  FCLCON4 __attribute__((__sfr__));
__extension__ typedef struct tagFCLCON4BITS {
  union {
    struct {
      unsigned FLTMOD:2;
      unsigned FLTPOL:1;
      unsigned FLTSRC:4;
      unsigned CLMODE:1;
      unsigned CLPOL:1;
      unsigned CLSRC:4;
    };
    struct {
      unsigned FLTMOD0:1;
      unsigned FLTMOD1:1;
      unsigned :1;
      unsigned FLTSRC0:1;
      unsigned FLTSRC1:1;
      unsigned FLTSRC2:1;
      unsigned FLTSRC3:1;
      unsigned :2;
      unsigned CLSRC0:1;
      unsigned CLSRC1:1;
      unsigned CLSRC2:1;
      unsigned CLSRC3:1;
    };
  };
} FCLCON4BITS;
extern volatile FCLCON4BITS FCLCON4bits __attribute__((__sfr__));

extern volatile unsigned int  PDC4 __attribute__((__sfr__));
extern volatile unsigned int  PHASE4 __attribute__((__sfr__));
extern volatile unsigned int  DTR4 __attribute__((__sfr__));
extern volatile unsigned int  ALTDTR4 __attribute__((__sfr__));
extern volatile unsigned int  TRIG4 __attribute__((__sfr__));
typedef struct tagTRIG4BITS {
  unsigned :4;
  unsigned TRIG:12;
} TRIG4BITS;
extern volatile TRIG4BITS TRIG4bits __attribute__((__sfr__));

extern volatile unsigned int  TRGCON4 __attribute__((__sfr__));
__extension__ typedef struct tagTRGCON4BITS {
  union {
    struct {
      unsigned TRGSTRT:6;
      unsigned :7;
      unsigned TRGDIV:3;
    };
    struct {
      unsigned TRGSTRT0:1;
      unsigned TRGSTRT1:1;
      unsigned TRGSTRT2:1;
      unsigned TRGSTRT3:1;
      unsigned TRGSTRT4:1;
      unsigned TRGSTRT5:1;
      unsigned :7;
      unsigned TRGDIV0:1;
      unsigned TRGDIV1:1;
      unsigned TRGDIV2:1;
    };
  };
} TRGCON4BITS;
extern volatile TRGCON4BITS TRGCON4bits __attribute__((__sfr__));

extern volatile unsigned int  LEBCON4 __attribute__((__sfr__));
__extension__ typedef struct tagLEBCON4BITS {
  union {
    struct {
      unsigned :3;
      unsigned LEB:7;
      unsigned CLLEBEN:1;
      unsigned FLTLEBEN:1;
      unsigned PLF:1;
      unsigned PLR:1;
      unsigned PHF:1;
      unsigned PHR:1;
    };
    struct {
      unsigned :3;
      unsigned LEB0:1;
      unsigned LEB1:1;
      unsigned LEB2:1;
      unsigned LEB3:1;
      unsigned LEB4:1;
      unsigned LEB5:1;
      unsigned LEB6:1;
    };
  };
} LEBCON4BITS;
extern volatile LEBCON4BITS LEBCON4bits __attribute__((__sfr__));

extern volatile unsigned int  CMPCON1 __attribute__((__sfr__));
__extension__ typedef struct tagCMPCON1BITS {
  union {
    struct {
      unsigned RANGE:1;
      unsigned CMPPOL:1;
      unsigned :1;
      unsigned CMPSTAT:1;
      unsigned :1;
      unsigned EXTREF:1;
      unsigned INSEL:2;
      unsigned :5;
      unsigned CMPSIDL:1;
      unsigned :1;
      unsigned CMPON:1;
    };
    struct {
      unsigned :6;
      unsigned INSEL0:1;
      unsigned INSEL1:1;
    };
  };
} CMPCON1BITS;
extern volatile CMPCON1BITS CMPCON1bits __attribute__((__sfr__));

extern volatile unsigned int  CMPDAC1 __attribute__((__sfr__));
__extension__ typedef struct tagCMPDAC1BITS {
  union {
    struct {
      unsigned CMREF0:1;
      unsigned CMREF1:1;
      unsigned CMREF2:1;
      unsigned CMREF3:1;
      unsigned CMREF4:1;
      unsigned CMREF5:1;
      unsigned CMREF6:1;
      unsigned CMREF7:1;
      unsigned CMREF8:1;
      unsigned CMREF9:1;
    };
    struct {
      unsigned CMREF:10;
    };
  };
} CMPDAC1BITS;
extern volatile CMPDAC1BITS CMPDAC1bits __attribute__((__sfr__));

extern volatile unsigned int  CMPCON2 __attribute__((__sfr__));
__extension__ typedef struct tagCMPCON2BITS {
  union {
    struct {
      unsigned RANGE:1;
      unsigned CMPPOL:1;
      unsigned :1;
      unsigned CMPSTAT:1;
      unsigned :1;
      unsigned EXTREF:1;
      unsigned INSEL:2;
      unsigned :5;
      unsigned CMPSIDL:1;
      unsigned :1;
      unsigned CMPON:1;
    };
    struct {
      unsigned :6;
      unsigned INSEL0:1;
      unsigned INSEL1:1;
    };
  };
} CMPCON2BITS;
extern volatile CMPCON2BITS CMPCON2bits __attribute__((__sfr__));

extern volatile unsigned int  CMPDAC2 __attribute__((__sfr__));
__extension__ typedef struct tagCMPDAC2BITS {
  union {
    struct {
      unsigned CMREF0:1;
      unsigned CMREF1:1;
      unsigned CMREF2:1;
      unsigned CMREF3:1;
      unsigned CMREF4:1;
      unsigned CMREF5:1;
      unsigned CMREF6:1;
      unsigned CMREF7:1;
      unsigned CMREF8:1;
      unsigned CMREF9:1;
    };
    struct {
      unsigned CMREF:10;
    };
  };
} CMPDAC2BITS;
extern volatile CMPDAC2BITS CMPDAC2bits __attribute__((__sfr__));

extern volatile unsigned int  CMPCON3 __attribute__((__sfr__));
__extension__ typedef struct tagCMPCON3BITS {
  union {
    struct {
      unsigned RANGE:1;
      unsigned CMPPOL:1;
      unsigned :1;
      unsigned CMPSTAT:1;
      unsigned :1;
      unsigned EXTREF:1;
      unsigned INSEL:2;
      unsigned :5;
      unsigned CMPSIDL:1;
      unsigned :1;
      unsigned CMPON:1;
    };
    struct {
      unsigned :6;
      unsigned INSEL0:1;
      unsigned INSEL1:1;
    };
  };
} CMPCON3BITS;
extern volatile CMPCON3BITS CMPCON3bits __attribute__((__sfr__));

extern volatile unsigned int  CMPDAC3 __attribute__((__sfr__));
__extension__ typedef struct tagCMPDAC3BITS {
  union {
    struct {
      unsigned CMREF0:1;
      unsigned CMREF1:1;
      unsigned CMREF2:1;
      unsigned CMREF3:1;
      unsigned CMREF4:1;
      unsigned CMREF5:1;
      unsigned CMREF6:1;
      unsigned CMREF7:1;
      unsigned CMREF8:1;
      unsigned CMREF9:1;
    };
    struct {
      unsigned CMREF:10;
    };
  };
} CMPDAC3BITS;
extern volatile CMPDAC3BITS CMPDAC3bits __attribute__((__sfr__));

extern volatile unsigned int  CMPCON4 __attribute__((__sfr__));
__extension__ typedef struct tagCMPCON4BITS {
  union {
    struct {
      unsigned RANGE:1;
      unsigned CMPPOL:1;
      unsigned :1;
      unsigned CMPSTAT:1;
      unsigned :1;
      unsigned EXTREF:1;
      unsigned INSEL:2;
      unsigned :5;
      unsigned CMPSIDL:1;
      unsigned :1;
      unsigned CMPON:1;
    };
    struct {
      unsigned :6;
      unsigned INSEL0:1;
      unsigned INSEL1:1;
    };
  };
} CMPCON4BITS;
extern volatile CMPCON4BITS CMPCON4bits __attribute__((__sfr__));

extern volatile unsigned int  CMPDAC4 __attribute__((__sfr__));
__extension__ typedef struct tagCMPDAC4BITS {
  union {
    struct {
      unsigned CMREF0:1;
      unsigned CMREF1:1;
      unsigned CMREF2:1;
      unsigned CMREF3:1;
      unsigned CMREF4:1;
      unsigned CMREF5:1;
      unsigned CMREF6:1;
      unsigned CMREF7:1;
      unsigned CMREF8:1;
      unsigned CMREF9:1;
    };
    struct {
      unsigned CMREF:10;
    };
  };
} CMPDAC4BITS;
extern volatile CMPDAC4BITS CMPDAC4bits __attribute__((__sfr__));

extern volatile unsigned int  RCON __attribute__((__sfr__));
typedef struct tagRCONBITS {
  unsigned POR:1;
  unsigned :1;
  unsigned IDLE:1;
  unsigned SLEEP:1;
  unsigned WDTO:1;
  unsigned SWDTEN:1;
  unsigned SWR:1;
  unsigned EXTR:1;
  unsigned :6;
  unsigned IOPUWR:1;
  unsigned TRAPR:1;
} RCONBITS;
extern volatile RCONBITS RCONbits __attribute__((__sfr__));

extern volatile unsigned int  OSCCON __attribute__((__sfr__));
__extension__ typedef struct tagOSCCONBITS {
  union {
    struct {
      unsigned OSWEN:1;
      unsigned :1;
      unsigned TSEQEN:1;
      unsigned CF:1;
      unsigned PRCDEN:1;
      unsigned LOCK:1;
      unsigned :1;
      unsigned CLKLOCK:1;
      unsigned NOSC:3;
      unsigned :1;
      unsigned COSC:3;
    };
    struct {
      unsigned :8;
      unsigned NOSC0:1;
      unsigned NOSC1:1;
      unsigned NOSC2:1;
      unsigned :1;
      unsigned COSC0:1;
      unsigned COSC1:1;
      unsigned COSC2:1;
    };
  };
} OSCCONBITS;
extern volatile OSCCONBITS OSCCONbits __attribute__((__sfr__));

extern volatile unsigned char OSCCONL __attribute__((__sfr__));
extern volatile unsigned char OSCCONH __attribute__((__sfr__));
extern volatile unsigned int  OSCTUN __attribute__((__sfr__));
__extension__ typedef struct tagOSCTUNBITS {
  union {
    struct {
      unsigned TUN:4;
      unsigned TSEQ1:4;
      unsigned TSEQ2:4;
      unsigned TSEQ3:4;
    };
    struct {
      unsigned TUN0:1;
      unsigned TUN1:1;
      unsigned TUN2:1;
      unsigned TUN3:1;
      unsigned TSEQ10:1;
      unsigned TSEQ11:1;
      unsigned TSEQ12:1;
      unsigned TSEQ13:1;
      unsigned TSEQ20:1;
      unsigned TSEQ21:1;
      unsigned TSEQ22:1;
      unsigned TSEQ23:1;
      unsigned TSEQ30:1;
      unsigned TSEQ31:1;
      unsigned TSEQ32:1;
      unsigned TSEQ33:1;
    };
  };
} OSCTUNBITS;
extern volatile OSCTUNBITS OSCTUNbits __attribute__((__sfr__));

extern volatile unsigned int  OSCTUN2 __attribute__((__sfr__));
__extension__ typedef struct tagOSCTUN2BITS {
  union {
    struct {
      unsigned TSEQ4:4;
      unsigned TSEQ5:4;
      unsigned TSEQ6:4;
      unsigned TSEQ7:4;
    };
    struct {
      unsigned TSEQ40:1;
      unsigned TSEQ41:1;
      unsigned TSEQ42:1;
      unsigned TSEQ43:1;
      unsigned TSEQ50:1;
      unsigned TSEQ51:1;
      unsigned TSEQ52:1;
      unsigned TSEQ53:1;
      unsigned TSEQ60:1;
      unsigned TSEQ61:1;
      unsigned TSEQ62:1;
      unsigned TSEQ63:1;
      unsigned TSEQ70:1;
      unsigned TSEQ71:1;
      unsigned TSEQ72:1;
      unsigned TSEQ73:1;
    };
  };
} OSCTUN2BITS;
extern volatile OSCTUN2BITS OSCTUN2bits __attribute__((__sfr__));

extern volatile unsigned int  LFSR __attribute__((__sfr__));
extern volatile unsigned int  BSRAM __attribute__((__sfr__));
typedef struct tagBSRAMBITS {
  unsigned RL_BSR:1;
  unsigned IR_BSR:1;
  unsigned IW_BSR:1;
} BSRAMBITS;
extern volatile BSRAMBITS BSRAMbits __attribute__((__sfr__));

extern volatile unsigned int  NVMCON __attribute__((__sfr__));
__extension__ typedef struct tagNVMCONBITS {
  union {
    struct {
      unsigned PROGOP:7;
      unsigned :1;
      unsigned TWRI:1;
      unsigned :4;
      unsigned WRERR:1;
      unsigned WREN:1;
      unsigned WR:1;
    };
    struct {
      unsigned PROGOP0:1;
      unsigned PROGOP1:1;
      unsigned PROGOP2:1;
      unsigned PROGOP3:1;
      unsigned PROGOP4:1;
      unsigned PROGOP5:1;
      unsigned PROGOP6:1;
    };
  };
} NVMCONBITS;
extern volatile NVMCONBITS NVMCONbits __attribute__((__sfr__));

extern volatile unsigned int  NVMADR __attribute__((__sfr__));
extern volatile unsigned int  NVMADRU __attribute__((__sfr__));
typedef struct tagNVMADRUBITS {
  unsigned NVMADR:8;
} NVMADRUBITS;
extern volatile NVMADRUBITS NVMADRUbits __attribute__((__sfr__));

extern volatile unsigned int  NVMKEY __attribute__((__sfr__));
typedef struct tagNVMKEYBITS {
  unsigned NVMKEY:8;
} NVMKEYBITS;
extern volatile NVMKEYBITS NVMKEYbits __attribute__((__sfr__));

extern volatile unsigned int  PMD1 __attribute__((__sfr__));
typedef struct tagPMD1BITS {
  unsigned ADCMD:1;
  unsigned :2;
  unsigned SPI1MD:1;
  unsigned :1;
  unsigned U1MD:1;
  unsigned :1;
  unsigned I2CMD:1;
  unsigned :1;
  unsigned PWMMD:1;
  unsigned :1;
  unsigned T1MD:1;
  unsigned T2MD:1;
  unsigned T3MD:1;
} PMD1BITS;
extern volatile PMD1BITS PMD1bits __attribute__((__sfr__));

extern volatile unsigned int  PMD2 __attribute__((__sfr__));
typedef struct tagPMD2BITS {
  unsigned OC1MD:1;
  unsigned OC2MD:1;
  unsigned :6;
  unsigned IC1MD:1;
} PMD2BITS;
extern volatile PMD2BITS PMD2bits __attribute__((__sfr__));

extern volatile unsigned int  PMD3 __attribute__((__sfr__));
typedef struct tagPMD3BITS {
  unsigned :11;
  unsigned CMP_PSMD:1;
} PMD3BITS;
extern volatile PMD3BITS PMD3bits __attribute__((__sfr__));



/* ---------------------------------------------------------- */
/* Defines for unique SFR bit names                           */
/* ---------------------------------------------------------- */

/* SR */
#define _C SRbits.C
#define _Z SRbits.Z
#define _OV SRbits.OV
#define _N SRbits.N
#define _RA SRbits.RA
#define _IPL SRbits.IPL
#define _DC SRbits.DC
#define _DA SRbits.DA
#define _SAB SRbits.SAB
#define _OAB SRbits.OAB
#define _SB SRbits.SB
#define _SA SRbits.SA
#define _OB SRbits.OB
#define _OA SRbits.OA
#define _IPL0 SRbits.IPL0
#define _IPL1 SRbits.IPL1
#define _IPL2 SRbits.IPL2

/* CORCON */
#define _IF CORCONbits.IF
#define _RND CORCONbits.RND
#define _PSV CORCONbits.PSV
#define _IPL3 CORCONbits.IPL3
#define _ACCSAT CORCONbits.ACCSAT
#define _SATDW CORCONbits.SATDW
#define _SATB CORCONbits.SATB
#define _SATA CORCONbits.SATA
#define _DL CORCONbits.DL
#define _EDT CORCONbits.EDT
#define _US CORCONbits.US
#define _DL0 CORCONbits.DL0
#define _DL1 CORCONbits.DL1
#define _DL2 CORCONbits.DL2

/* MODCON */
#define _XWM MODCONbits.XWM
#define _YWM MODCONbits.YWM
#define _BWM MODCONbits.BWM
#define _YMODEN MODCONbits.YMODEN
#define _XMODEN MODCONbits.XMODEN
#define _XWM0 MODCONbits.XWM0
#define _XWM1 MODCONbits.XWM1
#define _XWM2 MODCONbits.XWM2
#define _XWM3 MODCONbits.XWM3
#define _YWM0 MODCONbits.YWM0
#define _YWM1 MODCONbits.YWM1
#define _YWM2 MODCONbits.YWM2
#define _YWM3 MODCONbits.YWM3
#define _BWM0 MODCONbits.BWM0
#define _BWM1 MODCONbits.BWM1
#define _BWM2 MODCONbits.BWM2
#define _BWM3 MODCONbits.BWM3

/* XBREV */
#define _XB XBREVbits.XB
#define _BREN XBREVbits.BREN
#define _XB0 XBREVbits.XB0
#define _XB1 XBREVbits.XB1
#define _XB2 XBREVbits.XB2
#define _XB3 XBREVbits.XB3
#define _XB4 XBREVbits.XB4
#define _XB5 XBREVbits.XB5
#define _XB6 XBREVbits.XB6
#define _XB7 XBREVbits.XB7
#define _XB8 XBREVbits.XB8
#define _XB9 XBREVbits.XB9
#define _XB10 XBREVbits.XB10
#define _XB11 XBREVbits.XB11
#define _XB12 XBREVbits.XB12
#define _XB13 XBREVbits.XB13
#define _XB14 XBREVbits.XB14

/* DISICNT */
#define _DISICNT DISICNTbits.DISICNT

/* CNEN1 */
#define _CN0IE CNEN1bits.CN0IE
#define _CN1IE CNEN1bits.CN1IE
#define _CN2IE CNEN1bits.CN2IE
#define _CN3IE CNEN1bits.CN3IE
#define _CN4IE CNEN1bits.CN4IE
#define _CN5IE CNEN1bits.CN5IE
#define _CN6IE CNEN1bits.CN6IE
#define _CN7IE CNEN1bits.CN7IE

/* CNPU1 */
#define _CN0PUE CNPU1bits.CN0PUE
#define _CN1PUE CNPU1bits.CN1PUE
#define _CN2PUE CNPU1bits.CN2PUE
#define _CN3PUE CNPU1bits.CN3PUE
#define _CN4PUE CNPU1bits.CN4PUE
#define _CN5PUE CNPU1bits.CN5PUE
#define _CN6PUE CNPU1bits.CN6PUE
#define _CN7PUE CNPU1bits.CN7PUE

/* INTCON1 */
#define _OSCFAIL INTCON1bits.OSCFAIL
#define _STKERR INTCON1bits.STKERR
#define _ADDRERR INTCON1bits.ADDRERR
#define _MATHERR INTCON1bits.MATHERR
#define _DIV0ERR INTCON1bits.DIV0ERR
#define _SFTACERR INTCON1bits.SFTACERR
#define _COVTE INTCON1bits.COVTE
#define _OVBTE INTCON1bits.OVBTE
#define _OVATE INTCON1bits.OVATE
#define _COVBERR INTCON1bits.COVBERR
#define _COVAERR INTCON1bits.COVAERR
#define _OVBERR INTCON1bits.OVBERR
#define _OVAERR INTCON1bits.OVAERR
#define _NSTDIS INTCON1bits.NSTDIS

/* INTCON2 */
#define _INT0EP INTCON2bits.INT0EP
#define _INT1EP INTCON2bits.INT1EP
#define _INT2EP INTCON2bits.INT2EP
#define _DISI INTCON2bits.DISI
#define _ALTIVT INTCON2bits.ALTIVT

/* IFS0 */
#define _INT0IF IFS0bits.INT0IF
#define _IC1IF IFS0bits.IC1IF
#define _OC1IF IFS0bits.OC1IF
#define _T1IF IFS0bits.T1IF
#define _OC2IF IFS0bits.OC2IF
#define _T2IF IFS0bits.T2IF
#define _T3IF IFS0bits.T3IF
#define _SPI1IF IFS0bits.SPI1IF
#define _U1RXIF IFS0bits.U1RXIF
#define _U1TXIF IFS0bits.U1TXIF
#define _ADIF IFS0bits.ADIF
#define _NVMIF IFS0bits.NVMIF
#define _SI2CIF IFS0bits.SI2CIF
#define _MI2CIF IFS0bits.MI2CIF

/* IFS1 */
#define _INT1IF IFS1bits.INT1IF
#define _INT2IF IFS1bits.INT2IF
#define _PSEMIF IFS1bits.PSEMIF
#define _PWM1IF IFS1bits.PWM1IF
#define _PWM2IF IFS1bits.PWM2IF
#define _PWM3IF IFS1bits.PWM3IF
#define _PWM4IF IFS1bits.PWM4IF
#define _CNIF IFS1bits.CNIF
#define _AC1IF IFS1bits.AC1IF
#define _AC2IF IFS1bits.AC2IF
#define _AC3IF IFS1bits.AC3IF
#define _PWMEVIF IFS1bits.PWMEVIF

/* IFS2 */
#define _AC4IF IFS2bits.AC4IF
#define _ADCP0IF IFS2bits.ADCP0IF
#define _ADCP1IF IFS2bits.ADCP1IF
#define _ADCP2IF IFS2bits.ADCP2IF
#define _ADCP3IF IFS2bits.ADCP3IF

/* IEC0 */
#define _INT0IE IEC0bits.INT0IE
#define _IC1IE IEC0bits.IC1IE
#define _OC1IE IEC0bits.OC1IE
#define _T1IE IEC0bits.T1IE
#define _OC2IE IEC0bits.OC2IE
#define _T2IE IEC0bits.T2IE
#define _T3IE IEC0bits.T3IE
#define _SPI1IE IEC0bits.SPI1IE
#define _U1RXIE IEC0bits.U1RXIE
#define _U1TXIE IEC0bits.U1TXIE
#define _ADIE IEC0bits.ADIE
#define _NVMIE IEC0bits.NVMIE
#define _SI2CIE IEC0bits.SI2CIE
#define _MI2CIE IEC0bits.MI2CIE

/* IEC1 */
#define _INT1IE IEC1bits.INT1IE
#define _INT2IE IEC1bits.INT2IE
#define _PSEMIE IEC1bits.PSEMIE
#define _PWM1IE IEC1bits.PWM1IE
#define _PWM2IE IEC1bits.PWM2IE
#define _PWM3IE IEC1bits.PWM3IE
#define _PWM4IE IEC1bits.PWM4IE
#define _CNIE IEC1bits.CNIE
#define _AC1IE IEC1bits.AC1IE
#define _AC2IE IEC1bits.AC2IE
#define _AC3IE IEC1bits.AC3IE
#define _PWMEVIE IEC1bits.PWMEVIE

/* IEC2 */
#define _AC4IE IEC2bits.AC4IE
#define _ADCP0IE IEC2bits.ADCP0IE
#define _ADCP1IE IEC2bits.ADCP1IE
#define _ADCP2IE IEC2bits.ADCP2IE
#define _ADCP3IE IEC2bits.ADCP3IE

/* IPC0 */
#define _INT0IP IPC0bits.INT0IP
#define _IC1IP IPC0bits.IC1IP
#define _OC1IP IPC0bits.OC1IP
#define _T1IP IPC0bits.T1IP
#define _INT0IP0 IPC0bits.INT0IP0
#define _INT0IP1 IPC0bits.INT0IP1
#define _INT0IP2 IPC0bits.INT0IP2
#define _IC1IP0 IPC0bits.IC1IP0
#define _IC1IP1 IPC0bits.IC1IP1
#define _IC1IP2 IPC0bits.IC1IP2
#define _OC1IP0 IPC0bits.OC1IP0
#define _OC1IP1 IPC0bits.OC1IP1
#define _OC1IP2 IPC0bits.OC1IP2
#define _T1IP0 IPC0bits.T1IP0
#define _T1IP1 IPC0bits.T1IP1
#define _T1IP2 IPC0bits.T1IP2

/* IPC1 */
#define _OC2IP IPC1bits.OC2IP
#define _T2IP IPC1bits.T2IP
#define _T3IP IPC1bits.T3IP
#define _OC2IP0 IPC1bits.OC2IP0
#define _OC2IP1 IPC1bits.OC2IP1
#define _OC2IP2 IPC1bits.OC2IP2
#define _T2IP0 IPC1bits.T2IP0
#define _T2IP1 IPC1bits.T2IP1
#define _T2IP2 IPC1bits.T2IP2
#define _T3IP0 IPC1bits.T3IP0
#define _T3IP1 IPC1bits.T3IP1
#define _T3IP2 IPC1bits.T3IP2

/* IPC2 */
#define _SPI1IP IPC2bits.SPI1IP
#define _U1RXIP IPC2bits.U1RXIP
#define _U1TXIP IPC2bits.U1TXIP
#define _ADIP IPC2bits.ADIP
#define _SPI1IP0 IPC2bits.SPI1IP0
#define _SPI1IP1 IPC2bits.SPI1IP1
#define _SPI1IP2 IPC2bits.SPI1IP2
#define _U1RXIP0 IPC2bits.U1RXIP0
#define _U1RXIP1 IPC2bits.U1RXIP1
#define _U1RXIP2 IPC2bits.U1RXIP2
#define _U1TXIP0 IPC2bits.U1TXIP0
#define _U1TXIP1 IPC2bits.U1TXIP1
#define _U1TXIP2 IPC2bits.U1TXIP2
#define _ADIP0 IPC2bits.ADIP0
#define _ADIP1 IPC2bits.ADIP1
#define _ADIP2 IPC2bits.ADIP2

/* IPC3 */
#define _NVMIP IPC3bits.NVMIP
#define _SI2CIP IPC3bits.SI2CIP
#define _MI2CIP IPC3bits.MI2CIP
#define _NVMIP0 IPC3bits.NVMIP0
#define _NVMIP1 IPC3bits.NVMIP1
#define _NVMIP2 IPC3bits.NVMIP2
#define _SI2CIP0 IPC3bits.SI2CIP0
#define _SI2CIP1 IPC3bits.SI2CIP1
#define _SI2CIP2 IPC3bits.SI2CIP2
#define _MI2CIP0 IPC3bits.MI2CIP0
#define _MI2CIP1 IPC3bits.MI2CIP1
#define _MI2CIP2 IPC3bits.MI2CIP2

/* IPC4 */
#define _INT1IP IPC4bits.INT1IP
#define _INT2IP IPC4bits.INT2IP
#define _PSEMIP IPC4bits.PSEMIP
#define _PWM1IP IPC4bits.PWM1IP
#define _INT1IP0 IPC4bits.INT1IP0
#define _INT1IP1 IPC4bits.INT1IP1
#define _INT1IP2 IPC4bits.INT1IP2
#define _INT2IP0 IPC4bits.INT2IP0
#define _INT2IP1 IPC4bits.INT2IP1
#define _INT2IP2 IPC4bits.INT2IP2
#define _PSEMIP0 IPC4bits.PSEMIP0
#define _PSEMIP1 IPC4bits.PSEMIP1
#define _PSEMIP2 IPC4bits.PSEMIP2
#define _PWM1IP0 IPC4bits.PWM1IP0
#define _PWM1IP1 IPC4bits.PWM1IP1
#define _PWM1IP2 IPC4bits.PWM1IP2

/* IPC5 */
#define _PWM2IP IPC5bits.PWM2IP
#define _PWM3IP IPC5bits.PWM3IP
#define _PWM4IP IPC5bits.PWM4IP
#define _PWM2IP0 IPC5bits.PWM2IP0
#define _PWM2IP1 IPC5bits.PWM2IP1
#define _PWM2IP2 IPC5bits.PWM2IP2
#define _PWM3IP0 IPC5bits.PWM3IP0
#define _PWM3IP1 IPC5bits.PWM3IP1
#define _PWM3IP2 IPC5bits.PWM3IP2
#define _PWM4IP0 IPC5bits.PWM4IP0
#define _PWM4IP1 IPC5bits.PWM4IP1
#define _PWM4IP2 IPC5bits.PWM4IP2

/* IPC6 */
#define _CNIP IPC6bits.CNIP
#define _CNIP0 IPC6bits.CNIP0
#define _CNIP1 IPC6bits.CNIP1
#define _CNIP2 IPC6bits.CNIP2

/* IPC7 */
#define _AC1IP IPC7bits.AC1IP
#define _AC2IP IPC7bits.AC2IP
#define _AC3IP IPC7bits.AC3IP
#define _AC1IP0 IPC7bits.AC1IP0
#define _AC1IP1 IPC7bits.AC1IP1
#define _AC1IP2 IPC7bits.AC1IP2
#define _AC2IP0 IPC7bits.AC2IP0
#define _AC2IP1 IPC7bits.AC2IP1
#define _AC2IP2 IPC7bits.AC2IP2
#define _AC3IP0 IPC7bits.AC3IP0
#define _AC3IP1 IPC7bits.AC3IP1
#define _AC3IP2 IPC7bits.AC3IP2

/* IPC8 */
#define _AC4IP IPC8bits.AC4IP
#define _AC4IP0 IPC8bits.AC4IP0
#define _AC4IP1 IPC8bits.AC4IP1
#define _AC4IP2 IPC8bits.AC4IP2

/* IPC9 */
#define _ADCP0IP IPC9bits.ADCP0IP
#define _ADCP1IP IPC9bits.ADCP1IP
#define _ADCP2IP IPC9bits.ADCP2IP
#define _ADCP0IP0 IPC9bits.ADCP0IP0
#define _ADCP0IP1 IPC9bits.ADCP0IP1
#define _ADCP0IP2 IPC9bits.ADCP0IP2
#define _ADCP1IP0 IPC9bits.ADCP1IP0
#define _ADCP1IP1 IPC9bits.ADCP1IP1
#define _ADCP1IP2 IPC9bits.ADCP1IP2
#define _ADCP2IP0 IPC9bits.ADCP2IP0
#define _ADCP2IP1 IPC9bits.ADCP2IP1
#define _ADCP2IP2 IPC9bits.ADCP2IP2

/* IPC10 */
#define _ADCP3IP IPC10bits.ADCP3IP
#define _ADCP3IP0 IPC10bits.ADCP3IP0
#define _ADCP3IP1 IPC10bits.ADCP3IP1
#define _ADCP3IP2 IPC10bits.ADCP3IP2

/* INTTREG */
#define _VECNUM INTTREGbits.VECNUM
#define _ILR INTTREGbits.ILR
#define _VECNUM0 INTTREGbits.VECNUM0
#define _VECNUM1 INTTREGbits.VECNUM1
#define _VECNUM2 INTTREGbits.VECNUM2
#define _VECNUM3 INTTREGbits.VECNUM3
#define _VECNUM4 INTTREGbits.VECNUM4
#define _VECNUM5 INTTREGbits.VECNUM5
#define _VECNUM6 INTTREGbits.VECNUM6
#define _ILR0 INTTREGbits.ILR0
#define _ILR1 INTTREGbits.ILR1
#define _ILR2 INTTREGbits.ILR2
#define _ILR3 INTTREGbits.ILR3

/* T1CON */
#define _TCS T1CONbits.TCS
#define _TSYNC T1CONbits.TSYNC
#define _TCKPS T1CONbits.TCKPS
#define _TGATE T1CONbits.TGATE
#define _TSIDL T1CONbits.TSIDL
#define _TON T1CONbits.TON
#define _TCKPS0 T1CONbits.TCKPS0
#define _TCKPS1 T1CONbits.TCKPS1

/* T2CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
#define _T32 T2CONbits.T32
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* T3CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* IC1CON */
#define _ICM IC1CONbits.ICM
#define _ICBNE IC1CONbits.ICBNE
#define _ICOV IC1CONbits.ICOV
#define _ICI IC1CONbits.ICI
#define _ICTMR IC1CONbits.ICTMR
#define _ICSIDL IC1CONbits.ICSIDL
#define _ICM0 IC1CONbits.ICM0
#define _ICM1 IC1CONbits.ICM1
#define _ICM2 IC1CONbits.ICM2
#define _ICI0 IC1CONbits.ICI0
#define _ICI1 IC1CONbits.ICI1

/* OC1CON */
#define _OCM OC1CONbits.OCM
#define _OCTSEL OC1CONbits.OCTSEL
#define _OCFLT OC1CONbits.OCFLT
#define _OCSIDL OC1CONbits.OCSIDL
#define _OCM0 OC1CONbits.OCM0
#define _OCM1 OC1CONbits.OCM1
#define _OCM2 OC1CONbits.OCM2

/* OC2CON */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */

/* I2CRCV */
#define _I2CRCV I2CRCVbits.I2CRCV
#define _I2CRCV0 I2CRCVbits.I2CRCV0
#define _I2CRCV1 I2CRCVbits.I2CRCV1
#define _I2CRCV2 I2CRCVbits.I2CRCV2
#define _I2CRCV3 I2CRCVbits.I2CRCV3
#define _I2CRCV4 I2CRCVbits.I2CRCV4
#define _I2CRCV5 I2CRCVbits.I2CRCV5
#define _I2CRCV6 I2CRCVbits.I2CRCV6
#define _I2CRCV7 I2CRCVbits.I2CRCV7

/* I2CTRN */
#define _I2CTRN I2CTRNbits.I2CTRN
#define _I2CTRN0 I2CTRNbits.I2CTRN0
#define _I2CTRN1 I2CTRNbits.I2CTRN1
#define _I2CTRN2 I2CTRNbits.I2CTRN2
#define _I2CTRN3 I2CTRNbits.I2CTRN3
#define _I2CTRN4 I2CTRNbits.I2CTRN4
#define _I2CTRN5 I2CTRNbits.I2CTRN5
#define _I2CTRN6 I2CTRNbits.I2CTRN6
#define _I2CTRN7 I2CTRNbits.I2CTRN7

/* I2CBRG */
#define _I2CBRG I2CBRGbits.I2CBRG

/* I2CCON */
#define _SEN I2CCONbits.SEN
#define _RSEN I2CCONbits.RSEN
#define _PEN I2CCONbits.PEN
#define _RCEN I2CCONbits.RCEN
#define _ACKEN I2CCONbits.ACKEN
#define _ACKDT I2CCONbits.ACKDT
#define _STREN I2CCONbits.STREN
#define _GCEN I2CCONbits.GCEN
#define _SMEN I2CCONbits.SMEN
#define _DISSLW I2CCONbits.DISSLW
#define _A10M I2CCONbits.A10M
#define _IPMIEN I2CCONbits.IPMIEN
#define _SCLREL I2CCONbits.SCLREL
#define _I2CSIDL I2CCONbits.I2CSIDL
#define _I2CEN I2CCONbits.I2CEN

/* I2CSTAT */
#define _TBF I2CSTATbits.TBF
#define _RBF I2CSTATbits.RBF
#define _R_NOT_W I2CSTATbits.R_NOT_W
#define _S I2CSTATbits.S
#define _P I2CSTATbits.P
#define _D_NOT_A I2CSTATbits.D_NOT_A
#define _I2COV I2CSTATbits.I2COV
#define _IWCOL I2CSTATbits.IWCOL
#define _ADD10 I2CSTATbits.ADD10
#define _GCSTAT I2CSTATbits.GCSTAT
#define _BCL I2CSTATbits.BCL
#define _TRSTAT I2CSTATbits.TRSTAT
#define _ACKSTAT I2CSTATbits.ACKSTAT
#define _R_W I2CSTATbits.R_W
#define _D_A I2CSTATbits.D_A

/* I2CADD */
#define _I2CADD I2CADDbits.I2CADD

/* U1MODE */
#define _STSEL U1MODEbits.STSEL
#define _PDSEL U1MODEbits.PDSEL
#define _BRGH U1MODEbits.BRGH
#define _RXINV U1MODEbits.RXINV
#define _ABAUD U1MODEbits.ABAUD
#define _LPBACK U1MODEbits.LPBACK
#define _WAKE U1MODEbits.WAKE
#define _ALTIO U1MODEbits.ALTIO
#define _IREN U1MODEbits.IREN
#define _USIDL U1MODEbits.USIDL
#define _UARTEN U1MODEbits.UARTEN
#define _PDSEL0 U1MODEbits.PDSEL0
#define _PDSEL1 U1MODEbits.PDSEL1

/* U1STA */
#define _URXDA U1STAbits.URXDA
#define _OERR U1STAbits.OERR
#define _FERR U1STAbits.FERR
#define _PERR U1STAbits.PERR
#define _RIDLE U1STAbits.RIDLE
#define _ADDEN U1STAbits.ADDEN
#define _URXISEL U1STAbits.URXISEL
#define _TRMT U1STAbits.TRMT
#define _UTXBF U1STAbits.UTXBF
#define _UTXEN U1STAbits.UTXEN
#define _UTXBRK U1STAbits.UTXBRK
#define _UTXISEL0 U1STAbits.UTXISEL0
#define _UTXINV U1STAbits.UTXINV
#define _UTXISEL1 U1STAbits.UTXISEL1
#define _URXISEL0 U1STAbits.URXISEL0
#define _URXISEL1 U1STAbits.URXISEL1

/* U1TXREG */
#define _UTXREG0 U1TXREGbits.UTXREG0
#define _UTXREG1 U1TXREGbits.UTXREG1
#define _UTXREG2 U1TXREGbits.UTXREG2
#define _UTXREG3 U1TXREGbits.UTXREG3
#define _UTXREG4 U1TXREGbits.UTXREG4
#define _UTXREG5 U1TXREGbits.UTXREG5
#define _UTXREG6 U1TXREGbits.UTXREG6
#define _UTXREG7 U1TXREGbits.UTXREG7

/* U1RXREG */
#define _URXREG0 U1RXREGbits.URXREG0
#define _URXREG1 U1RXREGbits.URXREG1
#define _URXREG2 U1RXREGbits.URXREG2
#define _URXREG3 U1RXREGbits.URXREG3
#define _URXREG4 U1RXREGbits.URXREG4
#define _URXREG5 U1RXREGbits.URXREG5
#define _URXREG6 U1RXREGbits.URXREG6
#define _URXREG7 U1RXREGbits.URXREG7

/* SPI1STAT */
#define _SPIRBF SPI1STATbits.SPIRBF
#define _SPITBF SPI1STATbits.SPITBF
#define _SPIROV SPI1STATbits.SPIROV
#define _SPISIDL SPI1STATbits.SPISIDL
#define _SPIEN SPI1STATbits.SPIEN

/* SPI1CON1 */
#define _PPRE0 SPI1CON1bits.PPRE0
#define _PPRE1 SPI1CON1bits.PPRE1
#define _SPRE0 SPI1CON1bits.SPRE0
#define _SPRE1 SPI1CON1bits.SPRE1
#define _SPRE2 SPI1CON1bits.SPRE2
#define _MSTEN SPI1CON1bits.MSTEN
#define _CKP SPI1CON1bits.CKP
#define _SSEN SPI1CON1bits.SSEN
#define _CKE SPI1CON1bits.CKE
#define _SMP SPI1CON1bits.SMP
#define _MODE16 SPI1CON1bits.MODE16
#define _DISSDO SPI1CON1bits.DISSDO
#define _DISSCK SPI1CON1bits.DISSCK
#define _PPRE SPI1CON1bits.PPRE
#define _SPRE SPI1CON1bits.SPRE

/* SPI1CON2 */
#define _FRMDLY SPI1CON2bits.FRMDLY
#define _FRMPOL SPI1CON2bits.FRMPOL
#define _SPIFSD SPI1CON2bits.SPIFSD
#define _FRMEN SPI1CON2bits.FRMEN

/* TRISA */
#define _TRISA9 TRISAbits.TRISA9

/* PORTA */
#define _RA9 PORTAbits.RA9

/* LATA */
#define _LATA9 LATAbits.LATA9

/* TRISB */
#define _TRISB0 TRISBbits.TRISB0
#define _TRISB1 TRISBbits.TRISB1
#define _TRISB2 TRISBbits.TRISB2
#define _TRISB3 TRISBbits.TRISB3
#define _TRISB4 TRISBbits.TRISB4
#define _TRISB5 TRISBbits.TRISB5
#define _TRISB6 TRISBbits.TRISB6
#define _TRISB7 TRISBbits.TRISB7

/* PORTB */
#define _RB0 PORTBbits.RB0
#define _RB1 PORTBbits.RB1
#define _RB2 PORTBbits.RB2
#define _RB3 PORTBbits.RB3
#define _RB4 PORTBbits.RB4
#define _RB5 PORTBbits.RB5
#define _RB6 PORTBbits.RB6
#define _RB7 PORTBbits.RB7

/* LATB */
#define _LATB0 LATBbits.LATB0
#define _LATB1 LATBbits.LATB1
#define _LATB2 LATBbits.LATB2
#define _LATB3 LATBbits.LATB3
#define _LATB4 LATBbits.LATB4
#define _LATB5 LATBbits.LATB5
#define _LATB6 LATBbits.LATB6
#define _LATB7 LATBbits.LATB7

/* TRISD */
#define _TRISD0 TRISDbits.TRISD0

/* PORTD */
#define _RD0 PORTDbits.RD0

/* LATD */
#define _LATD0 LATDbits.LATD0

/* TRISE */
#define _TRISE0 TRISEbits.TRISE0
#define _TRISE1 TRISEbits.TRISE1
#define _TRISE2 TRISEbits.TRISE2
#define _TRISE3 TRISEbits.TRISE3
#define _TRISE4 TRISEbits.TRISE4
#define _TRISE5 TRISEbits.TRISE5
#define _TRISE6 TRISEbits.TRISE6
#define _TRISE7 TRISEbits.TRISE7

/* PORTE */
#define _RE0 PORTEbits.RE0
#define _RE1 PORTEbits.RE1
#define _RE2 PORTEbits.RE2
#define _RE3 PORTEbits.RE3
#define _RE4 PORTEbits.RE4
#define _RE5 PORTEbits.RE5
#define _RE6 PORTEbits.RE6
#define _RE7 PORTEbits.RE7

/* LATE */
#define _LATE0 LATEbits.LATE0
#define _LATE1 LATEbits.LATE1
#define _LATE2 LATEbits.LATE2
#define _LATE3 LATEbits.LATE3
#define _LATE4 LATEbits.LATE4
#define _LATE5 LATEbits.LATE5
#define _LATE6 LATEbits.LATE6
#define _LATE7 LATEbits.LATE7

/* TRISF */
#define _TRISF6 TRISFbits.TRISF6
#define _TRISF7 TRISFbits.TRISF7
#define _TRISF8 TRISFbits.TRISF8

/* PORTF */
#define _RF6 PORTFbits.RF6
#define _RF7 PORTFbits.RF7
#define _RF8 PORTFbits.RF8

/* LATF */
#define _LATF6 LATFbits.LATF6
#define _LATF7 LATFbits.LATF7
#define _LATF8 LATFbits.LATF8

/* ADCON */
#define _ADCS ADCONbits.ADCS
#define _SEQSAMP ADCONbits.SEQSAMP
#define _ORDER ADCONbits.ORDER
#define _EIE ADCONbits.EIE
#define _FORM ADCONbits.FORM
#define _GSWTRG ADCONbits.GSWTRG
#define _ADSIDL ADCONbits.ADSIDL
#define _ADON ADCONbits.ADON
#define _ADCS0 ADCONbits.ADCS0
#define _ADCS1 ADCONbits.ADCS1
#define _ADCS2 ADCONbits.ADCS2

/* ADPCFG */
#define _PCFG0 ADPCFGbits.PCFG0
#define _PCFG1 ADPCFGbits.PCFG1
#define _PCFG2 ADPCFGbits.PCFG2
#define _PCFG3 ADPCFGbits.PCFG3
#define _PCFG4 ADPCFGbits.PCFG4
#define _PCFG5 ADPCFGbits.PCFG5
#define _PCFG6 ADPCFGbits.PCFG6
#define _PCFG7 ADPCFGbits.PCFG7
#define _PCFG8 ADPCFGbits.PCFG8
#define _PCFG9 ADPCFGbits.PCFG9
#define _PCFG10 ADPCFGbits.PCFG10
#define _PCFG11 ADPCFGbits.PCFG11

/* ADSTAT */
#define _P0RDY ADSTATbits.P0RDY
#define _P1RDY ADSTATbits.P1RDY
#define _P2RDY ADSTATbits.P2RDY
#define _P3RDY ADSTATbits.P3RDY

/* ADBASE */
#define _ADBASE ADBASEbits.ADBASE

/* ADCPC0 */
#define _TRGSRC0 ADCPC0bits.TRGSRC0
#define _SWTRG0 ADCPC0bits.SWTRG0
#define _PEND0 ADCPC0bits.PEND0
#define _IRQEN0 ADCPC0bits.IRQEN0
#define _TRGSRC1 ADCPC0bits.TRGSRC1
#define _SWTRG1 ADCPC0bits.SWTRG1
#define _PEND1 ADCPC0bits.PEND1
#define _IRQEN1 ADCPC0bits.IRQEN1
#define _TRGSRC00 ADCPC0bits.TRGSRC00
#define _TRGSRC01 ADCPC0bits.TRGSRC01
#define _TRGSRC02 ADCPC0bits.TRGSRC02
#define _TRGSRC03 ADCPC0bits.TRGSRC03
#define _TRGSRC04 ADCPC0bits.TRGSRC04
#define _TRGSRC10 ADCPC0bits.TRGSRC10
#define _TRGSRC11 ADCPC0bits.TRGSRC11
#define _TRGSRC12 ADCPC0bits.TRGSRC12
#define _TRGSRC13 ADCPC0bits.TRGSRC13
#define _TRGSRC14 ADCPC0bits.TRGSRC14

/* ADCPC1 */
#define _TRGSRC2 ADCPC1bits.TRGSRC2
#define _SWTRG2 ADCPC1bits.SWTRG2
#define _PEND2 ADCPC1bits.PEND2
#define _IRQEN2 ADCPC1bits.IRQEN2
#define _TRGSRC3 ADCPC1bits.TRGSRC3
#define _SWTRG3 ADCPC1bits.SWTRG3
#define _PEND3 ADCPC1bits.PEND3
#define _IRQEN3 ADCPC1bits.IRQEN3
#define _TRGSRC20 ADCPC1bits.TRGSRC20
#define _TRGSRC21 ADCPC1bits.TRGSRC21
#define _TRGSRC22 ADCPC1bits.TRGSRC22
#define _TRGSRC23 ADCPC1bits.TRGSRC23
#define _TRGSRC24 ADCPC1bits.TRGSRC24
#define _TRGSRC30 ADCPC1bits.TRGSRC30
#define _TRGSRC31 ADCPC1bits.TRGSRC31
#define _TRGSRC32 ADCPC1bits.TRGSRC32
#define _TRGSRC33 ADCPC1bits.TRGSRC33
#define _TRGSRC34 ADCPC1bits.TRGSRC34

/* PTCON */
#define _SEVTPS PTCONbits.SEVTPS
#define _SYNCSRC PTCONbits.SYNCSRC
#define _SYNCEN PTCONbits.SYNCEN
#define _SYNCOEN PTCONbits.SYNCOEN
#define _SYNCPOL PTCONbits.SYNCPOL
#define _EIPU PTCONbits.EIPU
#define _SEIEN PTCONbits.SEIEN
#define _SESTAT PTCONbits.SESTAT
#define _PTSIDL PTCONbits.PTSIDL
#define _PTEN PTCONbits.PTEN
#define _SEVTPS0 PTCONbits.SEVTPS0
#define _SEVTPS1 PTCONbits.SEVTPS1
#define _SEVTPS2 PTCONbits.SEVTPS2
#define _SEVTPS3 PTCONbits.SEVTPS3
#define _SYNCSRC0 PTCONbits.SYNCSRC0
#define _SYNCSRC1 PTCONbits.SYNCSRC1
#define _SYNCSRC2 PTCONbits.SYNCSRC2

/* PTPER */
#define _PTPER PTPERbits.PTPER

/* SEVTCMP */
#define _SEVTCMP SEVTCMPbits.SEVTCMP

/* PWMCON1 */
/* Bitname _IUE cannot be defined because it is used by more than one SFR */
/* Bitname _XPRES cannot be defined because it is used by more than one SFR */
/* Bitname _DTC cannot be defined because it is used by more than one SFR */
/* Bitname _MDCS cannot be defined because it is used by more than one SFR */
/* Bitname _ITB cannot be defined because it is used by more than one SFR */
/* Bitname _TRGIEN cannot be defined because it is used by more than one SFR */
/* Bitname _CLIEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTIEN cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _CLSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _DTC0 cannot be defined because it is used by more than one SFR */
/* Bitname _DTC1 cannot be defined because it is used by more than one SFR */

/* IOCON1 */
/* Bitname _OSYNC cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT cannot be defined because it is used by more than one SFR */
/* Bitname _OVRENL cannot be defined because it is used by more than one SFR */
/* Bitname _OVRENH cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD cannot be defined because it is used by more than one SFR */
/* Bitname _POLL cannot be defined because it is used by more than one SFR */
/* Bitname _POLH cannot be defined because it is used by more than one SFR */
/* Bitname _PENL cannot be defined because it is used by more than one SFR */
/* Bitname _PENH cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD0 cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD1 cannot be defined because it is used by more than one SFR */

/* FCLCON1 */
/* Bitname _FLTMOD cannot be defined because it is used by more than one SFR */
/* Bitname _FLTPOL cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC cannot be defined because it is used by more than one SFR */
/* Bitname _CLMODE cannot be defined because it is used by more than one SFR */
/* Bitname _CLPOL cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMOD0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMOD1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC2 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC3 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC0 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC1 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC2 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC3 cannot be defined because it is used by more than one SFR */

/* TRIG1 */
/* Bitname _TRIG cannot be defined because it is used by more than one SFR */

/* TRGCON1 */
/* Bitname _TRGSTRT cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT2 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT3 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT4 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT5 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV2 cannot be defined because it is used by more than one SFR */

/* LEBCON1 */
/* Bitname _LEB cannot be defined because it is used by more than one SFR */
/* Bitname _CLLEBEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTLEBEN cannot be defined because it is used by more than one SFR */
/* Bitname _PLF cannot be defined because it is used by more than one SFR */
/* Bitname _PLR cannot be defined because it is used by more than one SFR */
/* Bitname _PHF cannot be defined because it is used by more than one SFR */
/* Bitname _PHR cannot be defined because it is used by more than one SFR */
/* Bitname _LEB0 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB1 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB2 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB3 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB4 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB5 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB6 cannot be defined because it is used by more than one SFR */

/* PWMCON2 */
/* Bitname _IUE cannot be defined because it is used by more than one SFR */
/* Bitname _XPRES cannot be defined because it is used by more than one SFR */
/* Bitname _DTC cannot be defined because it is used by more than one SFR */
/* Bitname _MDCS cannot be defined because it is used by more than one SFR */
/* Bitname _ITB cannot be defined because it is used by more than one SFR */
/* Bitname _TRGIEN cannot be defined because it is used by more than one SFR */
/* Bitname _CLIEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTIEN cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _CLSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _DTC0 cannot be defined because it is used by more than one SFR */
/* Bitname _DTC1 cannot be defined because it is used by more than one SFR */

/* IOCON2 */
/* Bitname _OSYNC cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT cannot be defined because it is used by more than one SFR */
/* Bitname _OVRENL cannot be defined because it is used by more than one SFR */
/* Bitname _OVRENH cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD cannot be defined because it is used by more than one SFR */
/* Bitname _POLL cannot be defined because it is used by more than one SFR */
/* Bitname _POLH cannot be defined because it is used by more than one SFR */
/* Bitname _PENL cannot be defined because it is used by more than one SFR */
/* Bitname _PENH cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD0 cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD1 cannot be defined because it is used by more than one SFR */

/* FCLCON2 */
/* Bitname _FLTMOD cannot be defined because it is used by more than one SFR */
/* Bitname _FLTPOL cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC cannot be defined because it is used by more than one SFR */
/* Bitname _CLMODE cannot be defined because it is used by more than one SFR */
/* Bitname _CLPOL cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMOD0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMOD1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC2 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC3 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC0 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC1 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC2 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC3 cannot be defined because it is used by more than one SFR */

/* TRIG2 */
/* Bitname _TRIG cannot be defined because it is used by more than one SFR */

/* TRGCON2 */
/* Bitname _TRGSTRT cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT2 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT3 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT4 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT5 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV2 cannot be defined because it is used by more than one SFR */

/* LEBCON2 */
/* Bitname _LEB cannot be defined because it is used by more than one SFR */
/* Bitname _CLLEBEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTLEBEN cannot be defined because it is used by more than one SFR */
/* Bitname _PLF cannot be defined because it is used by more than one SFR */
/* Bitname _PLR cannot be defined because it is used by more than one SFR */
/* Bitname _PHF cannot be defined because it is used by more than one SFR */
/* Bitname _PHR cannot be defined because it is used by more than one SFR */
/* Bitname _LEB0 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB1 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB2 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB3 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB4 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB5 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB6 cannot be defined because it is used by more than one SFR */

/* PWMCON3 */
/* Bitname _IUE cannot be defined because it is used by more than one SFR */
/* Bitname _XPRES cannot be defined because it is used by more than one SFR */
/* Bitname _DTC cannot be defined because it is used by more than one SFR */
/* Bitname _MDCS cannot be defined because it is used by more than one SFR */
/* Bitname _ITB cannot be defined because it is used by more than one SFR */
/* Bitname _TRGIEN cannot be defined because it is used by more than one SFR */
/* Bitname _CLIEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTIEN cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _CLSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _DTC0 cannot be defined because it is used by more than one SFR */
/* Bitname _DTC1 cannot be defined because it is used by more than one SFR */

/* IOCON3 */
/* Bitname _OSYNC cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT cannot be defined because it is used by more than one SFR */
/* Bitname _OVRENL cannot be defined because it is used by more than one SFR */
/* Bitname _OVRENH cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD cannot be defined because it is used by more than one SFR */
/* Bitname _POLL cannot be defined because it is used by more than one SFR */
/* Bitname _POLH cannot be defined because it is used by more than one SFR */
/* Bitname _PENL cannot be defined because it is used by more than one SFR */
/* Bitname _PENH cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD0 cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD1 cannot be defined because it is used by more than one SFR */

/* FCLCON3 */
/* Bitname _FLTMOD cannot be defined because it is used by more than one SFR */
/* Bitname _FLTPOL cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC cannot be defined because it is used by more than one SFR */
/* Bitname _CLMODE cannot be defined because it is used by more than one SFR */
/* Bitname _CLPOL cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMOD0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMOD1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC2 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC3 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC0 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC1 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC2 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC3 cannot be defined because it is used by more than one SFR */

/* TRIG3 */
/* Bitname _TRIG cannot be defined because it is used by more than one SFR */

/* TRGCON3 */
/* Bitname _TRGSTRT cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT2 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT3 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT4 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT5 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV2 cannot be defined because it is used by more than one SFR */

/* LEBCON3 */
/* Bitname _LEB cannot be defined because it is used by more than one SFR */
/* Bitname _CLLEBEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTLEBEN cannot be defined because it is used by more than one SFR */
/* Bitname _PLF cannot be defined because it is used by more than one SFR */
/* Bitname _PLR cannot be defined because it is used by more than one SFR */
/* Bitname _PHF cannot be defined because it is used by more than one SFR */
/* Bitname _PHR cannot be defined because it is used by more than one SFR */
/* Bitname _LEB0 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB1 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB2 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB3 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB4 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB5 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB6 cannot be defined because it is used by more than one SFR */

/* PWMCON4 */
/* Bitname _IUE cannot be defined because it is used by more than one SFR */
/* Bitname _XPRES cannot be defined because it is used by more than one SFR */
/* Bitname _DTC cannot be defined because it is used by more than one SFR */
/* Bitname _MDCS cannot be defined because it is used by more than one SFR */
/* Bitname _ITB cannot be defined because it is used by more than one SFR */
/* Bitname _TRGIEN cannot be defined because it is used by more than one SFR */
/* Bitname _CLIEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTIEN cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _CLSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _DTC0 cannot be defined because it is used by more than one SFR */
/* Bitname _DTC1 cannot be defined because it is used by more than one SFR */

/* IOCON4 */
/* Bitname _OSYNC cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT cannot be defined because it is used by more than one SFR */
/* Bitname _OVRENL cannot be defined because it is used by more than one SFR */
/* Bitname _OVRENH cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD cannot be defined because it is used by more than one SFR */
/* Bitname _POLL cannot be defined because it is used by more than one SFR */
/* Bitname _POLH cannot be defined because it is used by more than one SFR */
/* Bitname _PENL cannot be defined because it is used by more than one SFR */
/* Bitname _PENH cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _CLDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT0 cannot be defined because it is used by more than one SFR */
/* Bitname _OVRDAT1 cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD0 cannot be defined because it is used by more than one SFR */
/* Bitname _PMOD1 cannot be defined because it is used by more than one SFR */

/* FCLCON4 */
/* Bitname _FLTMOD cannot be defined because it is used by more than one SFR */
/* Bitname _FLTPOL cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC cannot be defined because it is used by more than one SFR */
/* Bitname _CLMODE cannot be defined because it is used by more than one SFR */
/* Bitname _CLPOL cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMOD0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTMOD1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC0 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC1 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC2 cannot be defined because it is used by more than one SFR */
/* Bitname _FLTSRC3 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC0 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC1 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC2 cannot be defined because it is used by more than one SFR */
/* Bitname _CLSRC3 cannot be defined because it is used by more than one SFR */

/* TRIG4 */
/* Bitname _TRIG cannot be defined because it is used by more than one SFR */

/* TRGCON4 */
/* Bitname _TRGSTRT cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT2 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT3 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT4 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGSTRT5 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV0 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV1 cannot be defined because it is used by more than one SFR */
/* Bitname _TRGDIV2 cannot be defined because it is used by more than one SFR */

/* LEBCON4 */
/* Bitname _LEB cannot be defined because it is used by more than one SFR */
/* Bitname _CLLEBEN cannot be defined because it is used by more than one SFR */
/* Bitname _FLTLEBEN cannot be defined because it is used by more than one SFR */
/* Bitname _PLF cannot be defined because it is used by more than one SFR */
/* Bitname _PLR cannot be defined because it is used by more than one SFR */
/* Bitname _PHF cannot be defined because it is used by more than one SFR */
/* Bitname _PHR cannot be defined because it is used by more than one SFR */
/* Bitname _LEB0 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB1 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB2 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB3 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB4 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB5 cannot be defined because it is used by more than one SFR */
/* Bitname _LEB6 cannot be defined because it is used by more than one SFR */

/* CMPCON1 */
/* Bitname _RANGE cannot be defined because it is used by more than one SFR */
/* Bitname _CMPPOL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _EXTREF cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPON cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL1 cannot be defined because it is used by more than one SFR */

/* CMPDAC1 */
/* Bitname _CMREF0 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF1 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF2 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF3 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF4 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF5 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF6 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF7 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF8 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF9 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF cannot be defined because it is used by more than one SFR */

/* CMPCON2 */
/* Bitname _RANGE cannot be defined because it is used by more than one SFR */
/* Bitname _CMPPOL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _EXTREF cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPON cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL1 cannot be defined because it is used by more than one SFR */

/* CMPDAC2 */
/* Bitname _CMREF0 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF1 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF2 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF3 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF4 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF5 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF6 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF7 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF8 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF9 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF cannot be defined because it is used by more than one SFR */

/* CMPCON3 */
/* Bitname _RANGE cannot be defined because it is used by more than one SFR */
/* Bitname _CMPPOL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _EXTREF cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPON cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL1 cannot be defined because it is used by more than one SFR */

/* CMPDAC3 */
/* Bitname _CMREF0 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF1 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF2 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF3 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF4 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF5 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF6 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF7 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF8 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF9 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF cannot be defined because it is used by more than one SFR */

/* CMPCON4 */
/* Bitname _RANGE cannot be defined because it is used by more than one SFR */
/* Bitname _CMPPOL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPSTAT cannot be defined because it is used by more than one SFR */
/* Bitname _EXTREF cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _CMPON cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _INSEL1 cannot be defined because it is used by more than one SFR */

/* CMPDAC4 */
/* Bitname _CMREF0 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF1 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF2 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF3 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF4 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF5 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF6 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF7 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF8 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF9 cannot be defined because it is used by more than one SFR */
/* Bitname _CMREF cannot be defined because it is used by more than one SFR */

/* RCON */
#define _POR RCONbits.POR
#define _IDLE RCONbits.IDLE
#define _SLEEP RCONbits.SLEEP
#define _WDTO RCONbits.WDTO
#define _SWDTEN RCONbits.SWDTEN
#define _SWR RCONbits.SWR
#define _EXTR RCONbits.EXTR
#define _IOPUWR RCONbits.IOPUWR
#define _TRAPR RCONbits.TRAPR

/* OSCCON */
#define _OSWEN OSCCONbits.OSWEN
#define _TSEQEN OSCCONbits.TSEQEN
#define _CF OSCCONbits.CF
#define _PRCDEN OSCCONbits.PRCDEN
#define _LOCK OSCCONbits.LOCK
#define _CLKLOCK OSCCONbits.CLKLOCK
#define _NOSC OSCCONbits.NOSC
#define _COSC OSCCONbits.COSC
#define _NOSC0 OSCCONbits.NOSC0
#define _NOSC1 OSCCONbits.NOSC1
#define _NOSC2 OSCCONbits.NOSC2
#define _COSC0 OSCCONbits.COSC0
#define _COSC1 OSCCONbits.COSC1
#define _COSC2 OSCCONbits.COSC2

/* OSCTUN */
#define _TUN OSCTUNbits.TUN
#define _TSEQ1 OSCTUNbits.TSEQ1
#define _TSEQ2 OSCTUNbits.TSEQ2
#define _TSEQ3 OSCTUNbits.TSEQ3
#define _TUN0 OSCTUNbits.TUN0
#define _TUN1 OSCTUNbits.TUN1
#define _TUN2 OSCTUNbits.TUN2
#define _TUN3 OSCTUNbits.TUN3
#define _TSEQ10 OSCTUNbits.TSEQ10
#define _TSEQ11 OSCTUNbits.TSEQ11
#define _TSEQ12 OSCTUNbits.TSEQ12
#define _TSEQ13 OSCTUNbits.TSEQ13
#define _TSEQ20 OSCTUNbits.TSEQ20
#define _TSEQ21 OSCTUNbits.TSEQ21
#define _TSEQ22 OSCTUNbits.TSEQ22
#define _TSEQ23 OSCTUNbits.TSEQ23
#define _TSEQ30 OSCTUNbits.TSEQ30
#define _TSEQ31 OSCTUNbits.TSEQ31
#define _TSEQ32 OSCTUNbits.TSEQ32
#define _TSEQ33 OSCTUNbits.TSEQ33

/* OSCTUN2 */
#define _TSEQ4 OSCTUN2bits.TSEQ4
#define _TSEQ5 OSCTUN2bits.TSEQ5
#define _TSEQ6 OSCTUN2bits.TSEQ6
#define _TSEQ7 OSCTUN2bits.TSEQ7
#define _TSEQ40 OSCTUN2bits.TSEQ40
#define _TSEQ41 OSCTUN2bits.TSEQ41
#define _TSEQ42 OSCTUN2bits.TSEQ42
#define _TSEQ43 OSCTUN2bits.TSEQ43
#define _TSEQ50 OSCTUN2bits.TSEQ50
#define _TSEQ51 OSCTUN2bits.TSEQ51
#define _TSEQ52 OSCTUN2bits.TSEQ52
#define _TSEQ53 OSCTUN2bits.TSEQ53
#define _TSEQ60 OSCTUN2bits.TSEQ60
#define _TSEQ61 OSCTUN2bits.TSEQ61
#define _TSEQ62 OSCTUN2bits.TSEQ62
#define _TSEQ63 OSCTUN2bits.TSEQ63
#define _TSEQ70 OSCTUN2bits.TSEQ70
#define _TSEQ71 OSCTUN2bits.TSEQ71
#define _TSEQ72 OSCTUN2bits.TSEQ72
#define _TSEQ73 OSCTUN2bits.TSEQ73

/* BSRAM */
#define _RL_BSR BSRAMbits.RL_BSR
#define _IR_BSR BSRAMbits.IR_BSR
#define _IW_BSR BSRAMbits.IW_BSR

/* NVMCON */
#define _PROGOP NVMCONbits.PROGOP
#define _TWRI NVMCONbits.TWRI
#define _WRERR NVMCONbits.WRERR
#define _WREN NVMCONbits.WREN
#define _WR NVMCONbits.WR
#define _PROGOP0 NVMCONbits.PROGOP0
#define _PROGOP1 NVMCONbits.PROGOP1
#define _PROGOP2 NVMCONbits.PROGOP2
#define _PROGOP3 NVMCONbits.PROGOP3
#define _PROGOP4 NVMCONbits.PROGOP4
#define _PROGOP5 NVMCONbits.PROGOP5
#define _PROGOP6 NVMCONbits.PROGOP6

/* NVMADRU */
#define _NVMADR NVMADRUbits.NVMADR

/* NVMKEY */
#define _NVMKEY NVMKEYbits.NVMKEY

/* PMD1 */
#define _ADCMD PMD1bits.ADCMD
#define _SPI1MD PMD1bits.SPI1MD
#define _U1MD PMD1bits.U1MD
#define _I2CMD PMD1bits.I2CMD
#define _PWMMD PMD1bits.PWMMD
#define _T1MD PMD1bits.T1MD
#define _T2MD PMD1bits.T2MD
#define _T3MD PMD1bits.T3MD

/* PMD2 */
#define _OC1MD PMD2bits.OC1MD
#define _OC2MD PMD2bits.OC2MD
#define _IC1MD PMD2bits.IC1MD

/* PMD3 */
#define _CMP_PSMD PMD3bits.CMP_PSMD


/* ---------------------------------------------------------- */
/* Some useful macros for inline assembler instructions       */
/* ---------------------------------------------------------- */

#define Nop()    __builtin_nop()
#define ClrWdt() {__asm__ volatile ("clrwdt");}
#define Sleep()  {__asm__ volatile ("pwrsav #0");}
#define Idle()   {__asm__ volatile ("pwrsav #1");}

/*----------------------------------------------------------- */
/* Some useful macros for allocating data memory              */
/*----------------------------------------------------------- */

/* The following macros require an argument N that specifies  */
/* alignment. N must a power of two, minimum value = 2.       */
/* For example, to declare an uninitialized array in X memory */
/* that is aligned to a 32 byte address:                      */
/*                                                            */
/* int _XBSS(32) xbuf[16];                                    */
/*                                                            */
#define _XBSS(N)    __attribute__((space(xmemory),far,aligned(N)))
#define _XDATA(N)   __attribute__((space(xmemory),far,aligned(N)))
#define _YBSS(N)    __attribute__((space(ymemory),far,aligned(N)))
#define _YDATA(N)   __attribute__((space(ymemory),far,aligned(N)))
/*                                                            */
/* To declare an initialized array in data EEPROM without     */
/* special alignment:                                         */
/*                                                            */
/* int _EEDATA(2) table1[] = {0, 1, 1, 2, 3, 5, 8, 13, 21};   */
/*                                                            */
#define _EEDATA(N)   __attribute__((space(eedata),aligned(N)))

/* The following macros do not require an argument. They can  */
/* be used to locate a variable in persistent data memory or  */
/* in near data memory. For example, to declare two variables */
/* that retain their values across a device reset:            */
/*                                                            */
/* int _PERSISTENT var1,var2;                                 */
/*                                                            */
#define _PERSISTENT __attribute__((persistent))
#define _NEAR       __attribute__((near))

/* ---------------------------------------------------------- */
/* Some useful macros for declaring functions                 */
/* ---------------------------------------------------------- */

/* The following macros can be used to declare interrupt      */
/* service routines (ISRs). For example, to declare an ISR    */
/* for the timer1 interrupt:                                  */
/*                                                            */
/* void _ISR _T1Interrupt(void);                              */
/*                                                            */
/* To declare an ISR for the SPI1 interrupt with fast         */
/* context save:                                              */
/*                                                            */
/* void _ISRFAST _SPI1Interrupt(void);                        */
/*                                                            */
/* Note: ISRs will be installed into the interrupt vector     */
/* tables automatically if the reserved names listed in the   */
/* MPLAB C30 Compiler User's Guide (DS51284) are used.        */
/*                                                            */
#define _ISR __attribute__((interrupt))
#define _ISRFAST __attribute__((interrupt, shadow))

/* ---------------------------------------------------------- */
/* Some useful macros for changing the CPU IPL                */
/* ---------------------------------------------------------- */

/* The following macros can be used to modify the current CPU */
/* IPL. The definition of the macro may vary from device to   */
/* device.                                                    */
/*                                                            */
/* To safely set the CPU IPL, use SET_CPU_IPL(ipl); the       */
/* valid range of ipl is 0-7, it may be any expression.       */
/*                                                            */
/* SET_CPU_IPL(7);                                            */
/*                                                            */
/* To preserve the current IPL and save it use                */
/* SET_AND_SAVE_CPU_IPL(save_to, ipl); the valid range of ipl */
/* is 0-7 and may be any expression, save_to should denote    */
/* some temporary storage.                                    */
/*                                                            */
/* int old_ipl;                                               */
/*                                                            */
/* SET_AND_SAVE_CPU_IPL(old_ipl, 7);                          */
/*                                                            */
/* The IPL can be restored with RESTORE_CPU_IPL(saved_to)     */
/*                                                            */
/* RESTORE_CPU_IPL(old_ipl);                                  */

#define SET_CPU_IPL(ipl) {       \
  int DISI_save;                 \
                                 \
  DISI_save = DISICNT;           \
  asm volatile ("disi #0x3FFF"); \
  SRbits.IPL = ipl;              \
  DISICNT = DISI_save; } (void) 0;

#define SET_AND_SAVE_CPU_IPL(save_to, ipl) { \
  save_to = SRbits.IPL; \
  SET_CPU_IPL(ipl); } (void) 0;

#define RESTORE_CPU_IPL(saved_to) SET_CPU_IPL(saved_to)



/* -------------------------------------------------------- */
/* Macros for setting device configuration registers        */
/* -------------------------------------------------------- */

/* Register FBS (0xf80000)                               */

extern __attribute__((space(prog))) int _FBS;
#define _FBS(x) __attribute__((section("__FBS.sec"),space(prog))) int _FBS = (x);

/*
** Only one invocation of FBS should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FBS.
** Multiple options may be combined, as shown:
**
** _FBS( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Boot Segment Write Protect:
**     BWRP_ON              Boot Segment is write protected
**     WR_PROT_BOOT_ON      Boot Segment is write protected
**     BWRP_OFF             Boot Segment may be written
**     WR_PROT_BOOT_OFF     Boot Segment may be written
**
**   Boot Segment Program Flash Code Protection:
**     HIGH_MEDIUM_BOOT_CODEHigh Security, Medium-sized Boot Flash
**     HIGH_SMALL_BOOT_CODE High Security, Small-sized Boot Flash
**     STRD_MEDIUM_BOOT_CODEStandard Security, Medium-sized Boot Flash
**     STRD_SMALL_BOOT_CODE Standard Security, Small-sized Boot Flash
**     NO_BOOT_CODE         No Boot Segment
**
*/

#define BWRP_ON              0xFFFE
#define WR_PROT_BOOT_ON      0xFFFE
#define BWRP_OFF             0xFFFF
#define WR_PROT_BOOT_OFF     0xFFFF

#define HIGH_MEDIUM_BOOT_CODE 0xFFF3
#define HIGH_SMALL_BOOT_CODE 0xFFF5
#define STRD_MEDIUM_BOOT_CODE 0xFFFB
#define STRD_SMALL_BOOT_CODE 0xFFFD
#define NO_BOOT_CODE         0xFFFF

/* Register FGS (0xf80004)                               */

extern __attribute__((space(prog))) int _FGS;
#define _FGS(x) __attribute__((section("__FGS.sec"),space(prog))) int _FGS = (x);

/*
** Only one invocation of FGS should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FGS.
** Multiple options may be combined, as shown:
**
** _FGS( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   General Code Segment Write Protect:
**     GWRP_ON              General Segment is write protected
**     GWRP_OFF             General Segment may be written
**
**   General Segment Code Protection:
**     GSS_HIGH             High Security Code Protection Enabled
**     GSS_ON               Enabled
**     GSS_STD              Enabled
**     CODE_PROT_ON         Enabled
**     GSS_OFF              Disabled
**     CODE_PROT_OFF        Disabled
**
*/

#define GWRP_ON              0xFFFE
#define GWRP_OFF             0xFFFF

#define GSS_HIGH             0xFFFB
#define GSS_ON               0xFFFD
#define GSS_STD              0xFFFD
#define CODE_PROT_ON         0xFFFD
#define GSS_OFF              0xFFFF
#define CODE_PROT_OFF        0xFFFF

/* Register FOSCSEL (0xf80006)                               */

extern __attribute__((space(prog))) int _FOSCSEL;
#define _FOSCSEL(x) __attribute__((section("__FOSCSEL.sec"),space(prog))) int _FOSCSEL = (x);

/*
** Only one invocation of FOSCSEL should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FOSCSEL.
** Multiple options may be combined, as shown:
**
** _FOSCSEL( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Oscillator Mode:
**     FRC                  Internal Fast RC (FRC)
**     FRC_PLL              Internal Fast RC (FRC) w/ PLL
**     PRIOSC               Primary Oscillator (HS, EC)
**     PRIOSC_PLL           Primary Oscillator (HS, EC) w/ PLL
**
*/

#define FRC                  0xFFFC
#define FRC_PLL              0xFFFD
#define PRIOSC               0xFFFE
#define PRIOSC_PLL           0xFFFF

/* Register FOSC (0xf80008)                               */

extern __attribute__((space(prog))) int _FOSC;
#define _FOSC(x) __attribute__((section("__FOSC.sec"),space(prog))) int _FOSC = (x);

/*
** Only one invocation of FOSC should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FOSC.
** Multiple options may be combined, as shown:
**
** _FOSC( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Primary Oscillator Source:
**     EC                   EC Oscillator Mode
**     HS                   HS Oscillator Mode
**     PRIOSC_OFF           Primary Oscillator Disabled
**     HS_EC_DIS            Primary Oscillator Disabled
**
**   OSCI/OSCO Pin Function:
**     OSC2_IO              OSCO pin has digital I/O function
**     OSC2_CLKO            OSCO pin has clock out function
**
**   Frequency Range Select:
**     FRC_LO_RANGE         Low Range
**     FRC_HI_RANGE         High Range
**
**   Clock Switching and Monitor:
**     CSW_FSCM_ON          Sw Enabled, Mon Enabled
**     CSW_ON_FSCM_OFF      Sw Enabled, Mon Disabled
**     CSW_FSCM_OFF         Sw Disabled, Mon Disabled
**
*/

#define EC                   0xFFFC
#define HS                   0xFFFE
#define PRIOSC_OFF           0xFFFF
#define HS_EC_DIS            0xFFFF

#define OSC2_IO              0xFFFB
#define OSC2_CLKO            0xFFFF

#define FRC_LO_RANGE         0xFFDF
#define FRC_HI_RANGE         0xFFFF

#define CSW_FSCM_ON          0xFF3F
#define CSW_ON_FSCM_OFF      0xFF7F
#define CSW_FSCM_OFF         0xFFBF

/* Register FWDT (0xf8000a)                               */

extern __attribute__((space(prog))) int _FWDT;
#define _FWDT(x) __attribute__((section("__FWDT.sec"),space(prog))) int _FWDT = (x);

/*
** Only one invocation of FWDT should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FWDT.
** Multiple options may be combined, as shown:
**
** _FWDT( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Watchdog Timer Postscaler:
**     WDTPOST_PS1          1:1
**     WDTPOST_PS2          1:2
**     WDTPOST_PS4          1:4
**     WDTPOST_PS8          1:8
**     WDTPOST_PS16         1:16
**     WDTPOST_PS32         1:32
**     WDTPOST_PS64         1:64
**     WDTPOST_PS128        1:128
**     WDTPOST_PS256        1:256
**     WDTPOST_PS512        1:512
**     WDTPOST_PS1024       1:1,024
**     WDTPOST_PS2048       1:2,048
**     WDTPOST_PS4096       1:4,096
**     WDTPOST_PS8192       1:8,192
**     WDTPOST_PS16384      1:16,384
**     WDTPOST_PS32768      1:32,768
**
**   WDT Prescaler:
**     WDTPRE_PR32          1:32
**     WDTPRE_PR128         1:128
**
**   Watchdog Timer Window:
**     WINDIS_ON            Window mode
**     WINDIS_OFF           Non-Window mode
**
**   Watchdog Timer Enable:
**     FWDTEN_OFF           Disable
**     FWDTEN_ON            Enable
**
*/

#define WDTPOST_PS1          0xFFF0
#define WDTPOST_PS2          0xFFF1
#define WDTPOST_PS4          0xFFF2
#define WDTPOST_PS8          0xFFF3
#define WDTPOST_PS16         0xFFF4
#define WDTPOST_PS32         0xFFF5
#define WDTPOST_PS64         0xFFF6
#define WDTPOST_PS128        0xFFF7
#define WDTPOST_PS256        0xFFF8
#define WDTPOST_PS512        0xFFF9
#define WDTPOST_PS1024       0xFFFA
#define WDTPOST_PS2048       0xFFFB
#define WDTPOST_PS4096       0xFFFC
#define WDTPOST_PS8192       0xFFFD
#define WDTPOST_PS16384      0xFFFE
#define WDTPOST_PS32768      0xFFFF

#define WDTPRE_PR32          0xFFEF
#define WDTPRE_PR128         0xFFFF

#define WINDIS_ON            0xFFBF
#define WINDIS_OFF           0xFFFF

#define FWDTEN_OFF           0xFF7F
#define FWDTEN_ON            0xFFFF

/* Register FPOR (0xf8000c)                               */

extern __attribute__((space(prog))) int _FPOR;
#define _FPOR(x) __attribute__((section("__FPOR.sec"),space(prog))) int _FPOR = (x);

/*
** Only one invocation of FPOR should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FPOR.
** Multiple options may be combined, as shown:
**
** _FPOR( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   POR Timer Value:
**     PWRT_OFF             Off
**     PWRT_2               2ms
**     PWRT_4               4ms
**     PWRT_8               8ms
**     PWRT_16              16ms
**     PWRT_32              32ms
**     PWRT_64              64ms
**     PWRT_128             128ms
**
*/

#define PWRT_OFF             0xFFF8
#define PWRT_2               0xFFF9
#define PWRT_4               0xFFFA
#define PWRT_8               0xFFFB
#define PWRT_16              0xFFFC
#define PWRT_32              0xFFFD
#define PWRT_64              0xFFFE
#define PWRT_128             0xFFFF

/* Register FICD (0xf8000e)                               */

extern __attribute__((space(prog))) int _FICD;
#define _FICD(x) __attribute__((section("__FICD.sec"),space(prog))) int _FICD = (x);

/*
** Only one invocation of FICD should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FICD.
** Multiple options may be combined, as shown:
**
** _FICD( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Comm Channel Select:
**     NONE                 Reserved
**     ICS_PGD2             Use EMUC2 and EMUD2
**     ICS_PGD1             Use EMUC1 and EMUD1
**     ICS_PGD              Use PGC/EMUC and PGD/EMUD
**
*/

#define NONE                 0xFFFC
#define ICS_PGD2             0xFFFD
#define ICS_PGD1             0xFFFE
#define ICS_PGD              0xFFFF

/* Register FUID0 (0xf80010)                               */

extern __attribute__((space(prog))) int _FUID0;
#define _FUID0(x) __attribute__((section("__FUID0.sec"),space(prog))) int _FUID0 = (x);

/*
** Only one invocation of FUID0 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FUID0.
** Multiple options may be combined, as shown:
**
** _FUID0( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
*/

/* Register FUID1 (0xf80012)                               */

extern __attribute__((space(prog))) int _FUID1;
#define _FUID1(x) __attribute__((section("__FUID1.sec"),space(prog))) int _FUID1 = (x);

/*
** Only one invocation of FUID1 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FUID1.
** Multiple options may be combined, as shown:
**
** _FUID1( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
*/


#endif
