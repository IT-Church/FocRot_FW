/*-------------------------------------------------------------------------
 * MPLAB-Cxx  dsPIC30F3010 processor header
 *
 * (c) Copyright 1999-2011 Microchip Technology, All rights reserved
 *-------------------------------------------------------------------------*/

#ifndef __dsPIC30F3010__
#error "Include file does not match processor setting"
#endif

#ifndef __30F3010_H
#define __30F3010_H

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

extern volatile unsigned int  INTCON1 __attribute__((__sfr__));
typedef struct tagINTCON1BITS {
  unsigned :1;
  unsigned OSCFAIL:1;
  unsigned STKERR:1;
  unsigned ADDRERR:1;
  unsigned MATHERR:1;
  unsigned :3;
  unsigned COVTE:1;
  unsigned OVBTE:1;
  unsigned OVATE:1;
  unsigned :4;
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
  unsigned IC2IF:1;
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
  unsigned CNIF:1;
} IFS0BITS;
extern volatile IFS0BITS IFS0bits __attribute__((__sfr__));

extern volatile unsigned int  IFS1 __attribute__((__sfr__));
typedef struct tagIFS1BITS {
  unsigned INT1IF:1;
  unsigned IC7IF:1;
  unsigned IC8IF:1;
  unsigned OC3IF:1;
  unsigned OC4IF:1;
  unsigned T4IF:1;
  unsigned T5IF:1;
  unsigned INT2IF:1;
} IFS1BITS;
extern volatile IFS1BITS IFS1bits __attribute__((__sfr__));

extern volatile unsigned int  IFS2 __attribute__((__sfr__));
typedef struct tagIFS2BITS {
  unsigned :7;
  unsigned PWMIF:1;
  unsigned QEIIF:1;
  unsigned :2;
  unsigned FLTAIF:1;
} IFS2BITS;
extern volatile IFS2BITS IFS2bits __attribute__((__sfr__));

extern volatile unsigned int  IEC0 __attribute__((__sfr__));
typedef struct tagIEC0BITS {
  unsigned INT0IE:1;
  unsigned IC1IE:1;
  unsigned OC1IE:1;
  unsigned T1IE:1;
  unsigned IC2IE:1;
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
  unsigned CNIE:1;
} IEC0BITS;
extern volatile IEC0BITS IEC0bits __attribute__((__sfr__));

extern volatile unsigned int  IEC1 __attribute__((__sfr__));
typedef struct tagIEC1BITS {
  unsigned INT1IE:1;
  unsigned IC7IE:1;
  unsigned IC8IE:1;
  unsigned OC3IE:1;
  unsigned OC4IE:1;
  unsigned T4IE:1;
  unsigned T5IE:1;
  unsigned INT2IE:1;
} IEC1BITS;
extern volatile IEC1BITS IEC1bits __attribute__((__sfr__));

extern volatile unsigned int  IEC2 __attribute__((__sfr__));
typedef struct tagIEC2BITS {
  unsigned :7;
  unsigned PWMIE:1;
  unsigned QEIIE:1;
  unsigned :2;
  unsigned FLTAIE:1;
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
      unsigned IC2IP:3;
      unsigned :1;
      unsigned OC2IP:3;
      unsigned :1;
      unsigned T2IP:3;
      unsigned :1;
      unsigned T3IP:3;
    };
    struct {
      unsigned IC2IP0:1;
      unsigned IC2IP1:1;
      unsigned IC2IP2:1;
      unsigned :1;
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
      unsigned :1;
      unsigned CNIP:3;
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
      unsigned :1;
      unsigned CNIP0:1;
      unsigned CNIP1:1;
      unsigned CNIP2:1;
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
      unsigned IC7IP:3;
      unsigned :1;
      unsigned IC8IP:3;
    };
    struct {
      unsigned INT1IP0:1;
      unsigned INT1IP1:1;
      unsigned INT1IP2:1;
      unsigned :1;
      unsigned IC7IP0:1;
      unsigned IC7IP1:1;
      unsigned IC7IP2:1;
      unsigned :1;
      unsigned IC8IP0:1;
      unsigned IC8IP1:1;
      unsigned IC8IP2:1;
    };
  };
} IPC4BITS;
extern volatile IPC4BITS IPC4bits __attribute__((__sfr__));

extern volatile unsigned int  IPC5 __attribute__((__sfr__));
__extension__ typedef struct tagIPC5BITS {
  union {
    struct {
      unsigned :4;
      unsigned T4IP:3;
      unsigned :1;
      unsigned T5IP:3;
      unsigned :1;
      unsigned INT2IP:3;
    };
    struct {
      unsigned :4;
      unsigned T4IP0:1;
      unsigned T4IP1:1;
      unsigned T4IP2:1;
      unsigned :1;
      unsigned T5IP0:1;
      unsigned T5IP1:1;
      unsigned T5IP2:1;
      unsigned :1;
      unsigned INT2IP0:1;
      unsigned INT2IP1:1;
      unsigned INT2IP2:1;
    };
  };
} IPC5BITS;
extern volatile IPC5BITS IPC5bits __attribute__((__sfr__));

extern volatile unsigned int  IPC9 __attribute__((__sfr__));
__extension__ typedef struct tagIPC9BITS {
  union {
    struct {
      unsigned :12;
      unsigned PWMIP:3;
    };
    struct {
      unsigned :12;
      unsigned PWMIP0:1;
      unsigned PWMIP1:1;
      unsigned PWMIP2:1;
    };
  };
} IPC9BITS;
extern volatile IPC9BITS IPC9bits __attribute__((__sfr__));

extern volatile unsigned int  IPC10 __attribute__((__sfr__));
__extension__ typedef struct tagIPC10BITS {
  union {
    struct {
      unsigned QEIIP:3;
      unsigned :9;
      unsigned FLTAIP:3;
    };
    struct {
      unsigned QEIIP0:1;
      unsigned QEIIP1:1;
      unsigned QEIIP2:1;
      unsigned :9;
      unsigned FLTAIP0:1;
      unsigned FLTAIP1:1;
      unsigned FLTAIP2:1;
    };
  };
} IPC10BITS;
extern volatile IPC10BITS IPC10bits __attribute__((__sfr__));

extern volatile unsigned int  INTTREG __attribute__((__sfr__));
__extension__ typedef struct tagINTTREGBITS {
  union {
    struct {
      unsigned VECNUM:6;
      unsigned :2;
      unsigned ILR:4;
      unsigned :1;
      unsigned VHOLD:1;
      unsigned TMODE:1;
      unsigned IRQTOCPU:1;
    };
    struct {
      unsigned VECNUM0:1;
      unsigned VECNUM1:1;
      unsigned VECNUM2:1;
      unsigned VECNUM3:1;
      unsigned VECNUM4:1;
      unsigned VECNUM5:1;
      unsigned :2;
      unsigned ILR0:1;
      unsigned ILR1:1;
      unsigned ILR2:1;
      unsigned ILR3:1;
    };
  };
} INTTREGBITS;
extern volatile INTTREGBITS INTTREGbits __attribute__((__sfr__));

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

extern volatile unsigned int  CNEN2 __attribute__((__sfr__));
typedef struct tagCNEN2BITS {
  unsigned :1;
  unsigned CN17IE:1;
  unsigned CN18IE:1;
} CNEN2BITS;
extern volatile CNEN2BITS CNEN2bits __attribute__((__sfr__));

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

extern volatile unsigned int  CNPU2 __attribute__((__sfr__));
typedef struct tagCNPU2BITS {
  unsigned :1;
  unsigned CN17PUE:1;
  unsigned CN18PUE:1;
} CNPU2BITS;
extern volatile CNPU2BITS CNPU2bits __attribute__((__sfr__));

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

extern volatile unsigned int  TMR4 __attribute__((__sfr__));
extern volatile unsigned int  TMR5HLD __attribute__((__sfr__));
extern volatile unsigned int  TMR5 __attribute__((__sfr__));
extern volatile unsigned int  PR4 __attribute__((__sfr__));
extern volatile unsigned int  PR5 __attribute__((__sfr__));
extern volatile unsigned int  T4CON __attribute__((__sfr__));
__extension__ typedef struct tagT4CONBITS {
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
} T4CONBITS;
extern volatile T4CONBITS T4CONbits __attribute__((__sfr__));

extern volatile unsigned int  T5CON __attribute__((__sfr__));
__extension__ typedef struct tagT5CONBITS {
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
} T5CONBITS;
extern volatile T5CONBITS T5CONbits __attribute__((__sfr__));

extern volatile unsigned int  QEICON __attribute__((__sfr__));
__extension__ typedef struct tagQEICONBITS {
  union {
    struct {
      unsigned UPDN_SRC:1;
      unsigned TQCS:1;
      unsigned POSRES:1;
      unsigned TQCKPS0:1;
      unsigned TQCKPS1:1;
      unsigned TQGATE:1;
      unsigned PCDOUT:1;
      unsigned SWPAB:1;
      unsigned QEIM0:1;
      unsigned QEIM1:1;
      unsigned QEIM2:1;
      unsigned UPDN:1;
      unsigned INDX:1;
      unsigned QEISIDL:1;
      unsigned :1;
      unsigned CNTERR:1;
    };
    struct {
      unsigned :3;
      unsigned TQCKPS:2;
      unsigned :3;
      unsigned QEIM:3;
    };
  };
} QEICONBITS;
extern volatile QEICONBITS QEICONbits __attribute__((__sfr__));

extern volatile unsigned int  DFLTCON __attribute__((__sfr__));
__extension__ typedef struct tagDFLTCONBITS {
  union {
    struct {
      unsigned :4;
      unsigned QECK0:1;
      unsigned QECK1:1;
      unsigned QECK2:1;
      unsigned QEOUT:1;
      unsigned CEID:1;
      unsigned IMV0:1;
      unsigned IMV1:1;
    };
    struct {
      unsigned :4;
      unsigned QECK:3;
      unsigned :2;
      unsigned IMV:2;
    };
  };
} DFLTCONBITS;
extern volatile DFLTCONBITS DFLTCONbits __attribute__((__sfr__));

extern volatile unsigned int  POSCNT __attribute__((__sfr__));
extern volatile unsigned int  MAXCNT __attribute__((__sfr__));

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


/* SFR blocks for Input Capture modules */
extern volatile IC IC2 __attribute__((__sfr__));

extern volatile unsigned int  IC2BUF __attribute__((__sfr__));
extern volatile unsigned int  IC2CON __attribute__((__sfr__));
__extension__ typedef struct tagIC2CONBITS {
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
} IC2CONBITS;
extern volatile IC2CONBITS IC2CONbits __attribute__((__sfr__));


/* SFR blocks for Input Capture modules */
extern volatile IC IC7 __attribute__((__sfr__));

extern volatile unsigned int  IC7BUF __attribute__((__sfr__));
extern volatile unsigned int  IC7CON __attribute__((__sfr__));
__extension__ typedef struct tagIC7CONBITS {
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
} IC7CONBITS;
extern volatile IC7CONBITS IC7CONbits __attribute__((__sfr__));


/* SFR blocks for Input Capture modules */
extern volatile IC IC8 __attribute__((__sfr__));

extern volatile unsigned int  IC8BUF __attribute__((__sfr__));
extern volatile unsigned int  IC8CON __attribute__((__sfr__));
__extension__ typedef struct tagIC8CONBITS {
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
} IC8CONBITS;
extern volatile IC8CONBITS IC8CONbits __attribute__((__sfr__));


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

extern volatile unsigned int  PTCON __attribute__((__sfr__));
__extension__ typedef struct tagPTCONBITS {
  union {
    struct {
      unsigned PTMOD:2;
      unsigned PTCKPS:2;
      unsigned PTOPS:4;
      unsigned :5;
      unsigned PTSIDL:1;
      unsigned :1;
      unsigned PTEN:1;
    };
    struct {
      unsigned PTMOD0:1;
      unsigned PTMOD1:1;
      unsigned PTCKPS0:1;
      unsigned PTCKPS1:1;
      unsigned PTOPS0:1;
      unsigned PTOPS1:1;
      unsigned PTOPS2:1;
      unsigned PTOPS3:1;
    };
  };
} PTCONBITS;
extern volatile PTCONBITS PTCONbits __attribute__((__sfr__));

extern volatile unsigned int  PTMR __attribute__((__sfr__));
typedef struct tagPTMRBITS {
  unsigned PTMR:15;
  unsigned PTDIR:1;
} PTMRBITS;
extern volatile PTMRBITS PTMRbits __attribute__((__sfr__));

extern volatile unsigned int  PTPER __attribute__((__sfr__));
typedef struct tagPTPERBITS {
  unsigned PTPER:15;
} PTPERBITS;
extern volatile PTPERBITS PTPERbits __attribute__((__sfr__));

extern volatile unsigned int  SEVTCMP __attribute__((__sfr__));
typedef struct tagSEVTCMPBITS {
  unsigned SEVTCMP:15;
  unsigned SEVTDIR:1;
} SEVTCMPBITS;
extern volatile SEVTCMPBITS SEVTCMPbits __attribute__((__sfr__));

extern volatile unsigned int  PWMCON1 __attribute__((__sfr__));
__extension__ typedef struct tagPWMCON1BITS {
  union {
    struct {
      unsigned PEN1L:1;
      unsigned PEN2L:1;
      unsigned PEN3L:1;
      unsigned :1;
      unsigned PEN1H:1;
      unsigned PEN2H:1;
      unsigned PEN3H:1;
      unsigned :1;
      unsigned PTMOD1:1;
      unsigned PTMOD2:1;
      unsigned PTMOD3:1;
    };
    struct {
      unsigned :8;
      unsigned PMOD1:1;
      unsigned PMOD2:1;
      unsigned PMOD3:1;
    };
  };
} PWMCON1BITS;
extern volatile PWMCON1BITS PWMCON1bits __attribute__((__sfr__));

extern volatile unsigned int  PWMCON2 __attribute__((__sfr__));
__extension__ typedef struct tagPWMCON2BITS {
  union {
    struct {
      unsigned UDIS:1;
      unsigned OSYNC:1;
      unsigned IUE:1;
      unsigned :5;
      unsigned SEVOPS:4;
    };
    struct {
      unsigned :8;
      unsigned SEVOPS0:1;
      unsigned SEVOPS1:1;
      unsigned SEVOPS2:1;
      unsigned SEVOPS3:1;
    };
  };
} PWMCON2BITS;
extern volatile PWMCON2BITS PWMCON2bits __attribute__((__sfr__));

extern volatile unsigned int  DTCON1 __attribute__((__sfr__));
__extension__ typedef struct tagDTCON1BITS {
  union {
    struct {
      unsigned DTA:6;
      unsigned DTAPS:2;
    };
    struct {
      unsigned DTA0:1;
      unsigned DTA1:1;
      unsigned DTA2:1;
      unsigned DTA3:1;
      unsigned DTA4:1;
      unsigned DTA5:1;
      unsigned DTAPS0:1;
      unsigned DTAPS1:1;
    };
  };
} DTCON1BITS;
extern volatile DTCON1BITS DTCON1bits __attribute__((__sfr__));

extern volatile unsigned int  FLTACON __attribute__((__sfr__));
typedef struct tagFLTACONBITS {
  unsigned FAEN1:1;
  unsigned FAEN2:1;
  unsigned FAEN3:1;
  unsigned :4;
  unsigned FLTAM:1;
  unsigned FAOV1L:1;
  unsigned FAOV1H:1;
  unsigned FAOV2L:1;
  unsigned FAOV2H:1;
  unsigned FAOV3L:1;
  unsigned FAOV3H:1;
} FLTACONBITS;
extern volatile FLTACONBITS FLTACONbits __attribute__((__sfr__));

extern volatile unsigned int  OVDCON __attribute__((__sfr__));
typedef struct tagOVDCONBITS {
  unsigned POUT1L:1;
  unsigned POUT1H:1;
  unsigned POUT2L:1;
  unsigned POUT2H:1;
  unsigned POUT3L:1;
  unsigned POUT3H:1;
  unsigned :2;
  unsigned POVD1L:1;
  unsigned POVD1H:1;
  unsigned POVD2L:1;
  unsigned POVD2H:1;
  unsigned POVD3L:1;
  unsigned POVD3H:1;
} OVDCONBITS;
extern volatile OVDCONBITS OVDCONbits __attribute__((__sfr__));

extern volatile unsigned int  PDC1 __attribute__((__sfr__));
extern volatile unsigned int  PDC2 __attribute__((__sfr__));
extern volatile unsigned int  PDC3 __attribute__((__sfr__));
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
      unsigned :2;
      unsigned ABAUD:1;
      unsigned LPBACK:1;
      unsigned WAKE:1;
      unsigned :2;
      unsigned ALTIO:1;
      unsigned :2;
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
      unsigned :3;
      unsigned UTXISEL:1;
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
__extension__ typedef struct tagU1TXREGBITS {
  union {
    struct {
      unsigned UTXREG0:1;
      unsigned UTXREG1:1;
      unsigned UTXREG2:1;
      unsigned UTXREG3:1;
      unsigned UTXREG4:1;
      unsigned UTXREG5:1;
      unsigned UTXREG6:1;
      unsigned UTXREG7:1;
      unsigned UTXREG8:1;
    };
    struct {
      unsigned :8;
      unsigned UTX8:1;
    };
  };
} U1TXREGBITS;
extern volatile U1TXREGBITS U1TXREGbits __attribute__((__sfr__));

extern volatile unsigned int  U1RXREG __attribute__((__sfr__));
__extension__ typedef struct tagU1RXREGBITS {
  union {
    struct {
      unsigned URXREG0:1;
      unsigned URXREG1:1;
      unsigned URXREG2:1;
      unsigned URXREG3:1;
      unsigned URXREG4:1;
      unsigned URXREG5:1;
      unsigned URXREG6:1;
      unsigned URXREG7:1;
      unsigned URXREG8:1;
    };
    struct {
      unsigned :8;
      unsigned URX8:1;
    };
  };
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

extern volatile unsigned int  SPI1CON __attribute__((__sfr__));
__extension__ typedef struct tagSPI1CONBITS {
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
      unsigned :1;
      unsigned SPIFSD:1;
      unsigned FRMEN:1;
    };
    struct {
      unsigned PPRE:2;
      unsigned SPRE:3;
    };
  };
} SPI1CONBITS;
extern volatile SPI1CONBITS SPI1CONbits __attribute__((__sfr__));

extern volatile unsigned int  SPI1BUF __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF0 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF1 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF2 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF3 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF4 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF5 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF6 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF7 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF8 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUF9 __attribute__((__sfr__));
extern volatile unsigned int  ADCBUFA __attribute__((__sfr__));
extern volatile unsigned int  ADCBUFB __attribute__((__sfr__));
extern volatile unsigned int  ADCBUFC __attribute__((__sfr__));
extern volatile unsigned int  ADCBUFD __attribute__((__sfr__));
extern volatile unsigned int  ADCBUFE __attribute__((__sfr__));
extern volatile unsigned int  ADCBUFF __attribute__((__sfr__));
extern volatile unsigned int  ADCON1 __attribute__((__sfr__));
__extension__ typedef struct tagADCON1BITS {
  union {
    struct {
      unsigned DONE:1;
      unsigned SAMP:1;
      unsigned ASAM:1;
      unsigned SIMSAM:1;
      unsigned :1;
      unsigned SSRC:3;
      unsigned FORM:2;
      unsigned :3;
      unsigned ADSIDL:1;
      unsigned :1;
      unsigned ADON:1;
    };
    struct {
      unsigned :5;
      unsigned SSRC0:1;
      unsigned SSRC1:1;
      unsigned SSRC2:1;
      unsigned FORM0:1;
      unsigned FORM1:1;
    };
  };
} ADCON1BITS;
extern volatile ADCON1BITS ADCON1bits __attribute__((__sfr__));

extern volatile unsigned int  ADCON2 __attribute__((__sfr__));
__extension__ typedef struct tagADCON2BITS {
  union {
    struct {
      unsigned ALTS:1;
      unsigned BUFM:1;
      unsigned SMPI:4;
      unsigned :1;
      unsigned BUFS:1;
      unsigned CHPS:2;
      unsigned CSCNA:1;
      unsigned :2;
      unsigned VCFG:3;
    };
    struct {
      unsigned :2;
      unsigned SMPI0:1;
      unsigned SMPI1:1;
      unsigned SMPI2:1;
      unsigned SMPI3:1;
      unsigned :2;
      unsigned CHPS0:1;
      unsigned CHPS1:1;
      unsigned :3;
      unsigned VCFG0:1;
      unsigned VCFG1:1;
      unsigned VCFG2:1;
    };
  };
} ADCON2BITS;
extern volatile ADCON2BITS ADCON2bits __attribute__((__sfr__));

extern volatile unsigned int  ADCON3 __attribute__((__sfr__));
__extension__ typedef struct tagADCON3BITS {
  union {
    struct {
      unsigned ADCS:6;
      unsigned :1;
      unsigned ADRC:1;
      unsigned SAMC:5;
    };
    struct {
      unsigned ADCS0:1;
      unsigned ADCS1:1;
      unsigned ADCS2:1;
      unsigned ADCS3:1;
      unsigned ADCS4:1;
      unsigned ADCS5:1;
      unsigned :2;
      unsigned SAMC0:1;
      unsigned SAMC1:1;
      unsigned SAMC2:1;
      unsigned SAMC3:1;
      unsigned SAMC4:1;
    };
  };
} ADCON3BITS;
extern volatile ADCON3BITS ADCON3bits __attribute__((__sfr__));

extern volatile unsigned int  ADCHS __attribute__((__sfr__));
__extension__ typedef struct tagADCHSBITS {
  union {
    struct {
      unsigned CH0SA:4;
      unsigned CH0NA:1;
      unsigned CH123SA:1;
      unsigned CH123NA:2;
      unsigned CH0SB:4;
      unsigned CH0NB:1;
      unsigned CH123SB:1;
      unsigned CH123NB:2;
    };
    struct {
      unsigned CH0SA0:1;
      unsigned CH0SA1:1;
      unsigned CH0SA2:1;
      unsigned CH0SA3:1;
      unsigned :2;
      unsigned CH123NA0:1;
      unsigned CH123NA1:1;
      unsigned CH0SB0:1;
      unsigned CH0SB1:1;
      unsigned CH0SB2:1;
      unsigned CH0SB3:1;
      unsigned :2;
      unsigned CH123NB0:1;
      unsigned CH123NB1:1;
    };
  };
} ADCHSBITS;
extern volatile ADCHSBITS ADCHSbits __attribute__((__sfr__));

extern volatile unsigned int  ADPCFG __attribute__((__sfr__));
typedef struct tagADPCFGBITS {
  unsigned PCFG0:1;
  unsigned PCFG1:1;
  unsigned PCFG2:1;
  unsigned PCFG3:1;
  unsigned PCFG4:1;
  unsigned PCFG5:1;
} ADPCFGBITS;
extern volatile ADPCFGBITS ADPCFGbits __attribute__((__sfr__));

extern volatile unsigned int  ADCSSL __attribute__((__sfr__));
typedef struct tagADCSSLBITS {
  unsigned CSSL0:1;
  unsigned CSSL1:1;
  unsigned CSSL2:1;
  unsigned CSSL3:1;
  unsigned CSSL4:1;
  unsigned CSSL5:1;
} ADCSSLBITS;
extern volatile ADCSSLBITS ADCSSLbits __attribute__((__sfr__));

extern volatile unsigned int  TRISB __attribute__((__sfr__));
typedef struct tagTRISBBITS {
  unsigned TRISB0:1;
  unsigned TRISB1:1;
  unsigned TRISB2:1;
  unsigned TRISB3:1;
  unsigned TRISB4:1;
  unsigned TRISB5:1;
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
} LATBBITS;
extern volatile LATBBITS LATBbits __attribute__((__sfr__));

extern volatile unsigned int  TRISC __attribute__((__sfr__));
typedef struct tagTRISCBITS {
  unsigned :13;
  unsigned TRISC13:1;
  unsigned TRISC14:1;
  unsigned TRISC15:1;
} TRISCBITS;
extern volatile TRISCBITS TRISCbits __attribute__((__sfr__));

extern volatile unsigned int  PORTC __attribute__((__sfr__));
typedef struct tagPORTCBITS {
  unsigned :13;
  unsigned RC13:1;
  unsigned RC14:1;
  unsigned RC15:1;
} PORTCBITS;
extern volatile PORTCBITS PORTCbits __attribute__((__sfr__));

extern volatile unsigned int  LATC __attribute__((__sfr__));
typedef struct tagLATCBITS {
  unsigned :13;
  unsigned LATC13:1;
  unsigned LATC14:1;
  unsigned LATC15:1;
} LATCBITS;
extern volatile LATCBITS LATCbits __attribute__((__sfr__));

extern volatile unsigned int  TRISD __attribute__((__sfr__));
typedef struct tagTRISDBITS {
  unsigned TRISD0:1;
  unsigned TRISD1:1;
} TRISDBITS;
extern volatile TRISDBITS TRISDbits __attribute__((__sfr__));

extern volatile unsigned int  PORTD __attribute__((__sfr__));
typedef struct tagPORTDBITS {
  unsigned RD0:1;
  unsigned RD1:1;
} PORTDBITS;
extern volatile PORTDBITS PORTDbits __attribute__((__sfr__));

extern volatile unsigned int  LATD __attribute__((__sfr__));
typedef struct tagLATDBITS {
  unsigned LATD0:1;
  unsigned LATD1:1;
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
  unsigned :2;
  unsigned TRISE8:1;
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
  unsigned :2;
  unsigned RE8:1;
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
  unsigned :2;
  unsigned LATE8:1;
} LATEBITS;
extern volatile LATEBITS LATEbits __attribute__((__sfr__));

extern volatile unsigned int  TRISF __attribute__((__sfr__));
typedef struct tagTRISFBITS {
  unsigned :2;
  unsigned TRISF2:1;
  unsigned TRISF3:1;
} TRISFBITS;
extern volatile TRISFBITS TRISFbits __attribute__((__sfr__));

extern volatile unsigned int  PORTF __attribute__((__sfr__));
typedef struct tagPORTFBITS {
  unsigned :2;
  unsigned RF2:1;
  unsigned RF3:1;
} PORTFBITS;
extern volatile PORTFBITS PORTFbits __attribute__((__sfr__));

extern volatile unsigned int  LATF __attribute__((__sfr__));
typedef struct tagLATFBITS {
  unsigned :2;
  unsigned LATF2:1;
  unsigned LATF3:1;
} LATFBITS;
extern volatile LATFBITS LATFbits __attribute__((__sfr__));

extern volatile unsigned int  RCON __attribute__((__sfr__));
typedef struct tagRCONBITS {
  unsigned POR:1;
  unsigned BOR:1;
  unsigned IDLE:1;
  unsigned SLEEP:1;
  unsigned WDTO:1;
  unsigned SWDTEN:1;
  unsigned SWR:1;
  unsigned EXTR:1;
  unsigned :5;
  unsigned BGST:1;
  unsigned IOPUWR:1;
  unsigned TRAPR:1;
} RCONBITS;
extern volatile RCONBITS RCONbits __attribute__((__sfr__));

extern volatile unsigned int  OSCCON __attribute__((__sfr__));
__extension__ typedef struct tagOSCCONBITS {
  union {
    struct {
      unsigned OSWEN:1;
      unsigned LPOSCEN:1;
      unsigned :1;
      unsigned CF:1;
      unsigned :1;
      unsigned LOCK:1;
      unsigned POST:2;
      unsigned NOSC:3;
      unsigned :1;
      unsigned COSC:3;
    };
    struct {
      unsigned :6;
      unsigned POST0:1;
      unsigned POST1:1;
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
    };
    struct {
      unsigned TUN0:1;
      unsigned TUN1:1;
      unsigned TUN2:1;
      unsigned TUN3:1;
    };
  };
} OSCTUNBITS;
extern volatile OSCTUNBITS OSCTUNbits __attribute__((__sfr__));

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
  unsigned KEY:8;
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
  unsigned QEIMD:1;
  unsigned T1MD:1;
  unsigned T2MD:1;
  unsigned T3MD:1;
  unsigned T4MD:1;
  unsigned T5MD:1;
} PMD1BITS;
extern volatile PMD1BITS PMD1bits __attribute__((__sfr__));

extern volatile unsigned int  PMD2 __attribute__((__sfr__));
typedef struct tagPMD2BITS {
  unsigned OC1MD:1;
  unsigned OC2MD:1;
  unsigned :6;
  unsigned IC1MD:1;
  unsigned IC2MD:1;
  unsigned :4;
  unsigned IC7MD:1;
  unsigned IC8MD:1;
} PMD2BITS;
extern volatile PMD2BITS PMD2bits __attribute__((__sfr__));



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

/* INTCON1 */
#define _OSCFAIL INTCON1bits.OSCFAIL
#define _STKERR INTCON1bits.STKERR
#define _ADDRERR INTCON1bits.ADDRERR
#define _MATHERR INTCON1bits.MATHERR
#define _COVTE INTCON1bits.COVTE
#define _OVBTE INTCON1bits.OVBTE
#define _OVATE INTCON1bits.OVATE
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
#define _IC2IF IFS0bits.IC2IF
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
#define _CNIF IFS0bits.CNIF

/* IFS1 */
#define _INT1IF IFS1bits.INT1IF
#define _IC7IF IFS1bits.IC7IF
#define _IC8IF IFS1bits.IC8IF
#define _OC3IF IFS1bits.OC3IF
#define _OC4IF IFS1bits.OC4IF
#define _T4IF IFS1bits.T4IF
#define _T5IF IFS1bits.T5IF
#define _INT2IF IFS1bits.INT2IF

/* IFS2 */
#define _PWMIF IFS2bits.PWMIF
#define _QEIIF IFS2bits.QEIIF
#define _FLTAIF IFS2bits.FLTAIF

/* IEC0 */
#define _INT0IE IEC0bits.INT0IE
#define _IC1IE IEC0bits.IC1IE
#define _OC1IE IEC0bits.OC1IE
#define _T1IE IEC0bits.T1IE
#define _IC2IE IEC0bits.IC2IE
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
#define _CNIE IEC0bits.CNIE

/* IEC1 */
#define _INT1IE IEC1bits.INT1IE
#define _IC7IE IEC1bits.IC7IE
#define _IC8IE IEC1bits.IC8IE
#define _OC3IE IEC1bits.OC3IE
#define _OC4IE IEC1bits.OC4IE
#define _T4IE IEC1bits.T4IE
#define _T5IE IEC1bits.T5IE
#define _INT2IE IEC1bits.INT2IE

/* IEC2 */
#define _PWMIE IEC2bits.PWMIE
#define _QEIIE IEC2bits.QEIIE
#define _FLTAIE IEC2bits.FLTAIE

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
#define _IC2IP IPC1bits.IC2IP
#define _OC2IP IPC1bits.OC2IP
#define _T2IP IPC1bits.T2IP
#define _T3IP IPC1bits.T3IP
#define _IC2IP0 IPC1bits.IC2IP0
#define _IC2IP1 IPC1bits.IC2IP1
#define _IC2IP2 IPC1bits.IC2IP2
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
#define _CNIP IPC3bits.CNIP
#define _NVMIP0 IPC3bits.NVMIP0
#define _NVMIP1 IPC3bits.NVMIP1
#define _NVMIP2 IPC3bits.NVMIP2
#define _SI2CIP0 IPC3bits.SI2CIP0
#define _SI2CIP1 IPC3bits.SI2CIP1
#define _SI2CIP2 IPC3bits.SI2CIP2
#define _MI2CIP0 IPC3bits.MI2CIP0
#define _MI2CIP1 IPC3bits.MI2CIP1
#define _MI2CIP2 IPC3bits.MI2CIP2
#define _CNIP0 IPC3bits.CNIP0
#define _CNIP1 IPC3bits.CNIP1
#define _CNIP2 IPC3bits.CNIP2

/* IPC4 */
#define _INT1IP IPC4bits.INT1IP
#define _IC7IP IPC4bits.IC7IP
#define _IC8IP IPC4bits.IC8IP
#define _INT1IP0 IPC4bits.INT1IP0
#define _INT1IP1 IPC4bits.INT1IP1
#define _INT1IP2 IPC4bits.INT1IP2
#define _IC7IP0 IPC4bits.IC7IP0
#define _IC7IP1 IPC4bits.IC7IP1
#define _IC7IP2 IPC4bits.IC7IP2
#define _IC8IP0 IPC4bits.IC8IP0
#define _IC8IP1 IPC4bits.IC8IP1
#define _IC8IP2 IPC4bits.IC8IP2

/* IPC5 */
#define _T4IP IPC5bits.T4IP
#define _T5IP IPC5bits.T5IP
#define _INT2IP IPC5bits.INT2IP
#define _T4IP0 IPC5bits.T4IP0
#define _T4IP1 IPC5bits.T4IP1
#define _T4IP2 IPC5bits.T4IP2
#define _T5IP0 IPC5bits.T5IP0
#define _T5IP1 IPC5bits.T5IP1
#define _T5IP2 IPC5bits.T5IP2
#define _INT2IP0 IPC5bits.INT2IP0
#define _INT2IP1 IPC5bits.INT2IP1
#define _INT2IP2 IPC5bits.INT2IP2

/* IPC9 */
#define _PWMIP IPC9bits.PWMIP
#define _PWMIP0 IPC9bits.PWMIP0
#define _PWMIP1 IPC9bits.PWMIP1
#define _PWMIP2 IPC9bits.PWMIP2

/* IPC10 */
#define _QEIIP IPC10bits.QEIIP
#define _FLTAIP IPC10bits.FLTAIP
#define _QEIIP0 IPC10bits.QEIIP0
#define _QEIIP1 IPC10bits.QEIIP1
#define _QEIIP2 IPC10bits.QEIIP2
#define _FLTAIP0 IPC10bits.FLTAIP0
#define _FLTAIP1 IPC10bits.FLTAIP1
#define _FLTAIP2 IPC10bits.FLTAIP2

/* INTTREG */
#define _VECNUM INTTREGbits.VECNUM
#define _ILR INTTREGbits.ILR
#define _VHOLD INTTREGbits.VHOLD
#define _TMODE INTTREGbits.TMODE
#define _IRQTOCPU INTTREGbits.IRQTOCPU
#define _VECNUM0 INTTREGbits.VECNUM0
#define _VECNUM1 INTTREGbits.VECNUM1
#define _VECNUM2 INTTREGbits.VECNUM2
#define _VECNUM3 INTTREGbits.VECNUM3
#define _VECNUM4 INTTREGbits.VECNUM4
#define _VECNUM5 INTTREGbits.VECNUM5
#define _ILR0 INTTREGbits.ILR0
#define _ILR1 INTTREGbits.ILR1
#define _ILR2 INTTREGbits.ILR2
#define _ILR3 INTTREGbits.ILR3

/* CNEN1 */
#define _CN0IE CNEN1bits.CN0IE
#define _CN1IE CNEN1bits.CN1IE
#define _CN2IE CNEN1bits.CN2IE
#define _CN3IE CNEN1bits.CN3IE
#define _CN4IE CNEN1bits.CN4IE
#define _CN5IE CNEN1bits.CN5IE
#define _CN6IE CNEN1bits.CN6IE
#define _CN7IE CNEN1bits.CN7IE

/* CNEN2 */
#define _CN17IE CNEN2bits.CN17IE
#define _CN18IE CNEN2bits.CN18IE

/* CNPU1 */
#define _CN0PUE CNPU1bits.CN0PUE
#define _CN1PUE CNPU1bits.CN1PUE
#define _CN2PUE CNPU1bits.CN2PUE
#define _CN3PUE CNPU1bits.CN3PUE
#define _CN4PUE CNPU1bits.CN4PUE
#define _CN5PUE CNPU1bits.CN5PUE
#define _CN6PUE CNPU1bits.CN6PUE
#define _CN7PUE CNPU1bits.CN7PUE

/* CNPU2 */
#define _CN17PUE CNPU2bits.CN17PUE
#define _CN18PUE CNPU2bits.CN18PUE

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
/* Bitname _T32 cannot be defined because it is used by more than one SFR */
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

/* T4CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
/* Bitname _T32 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* T5CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* QEICON */
#define _UPDN_SRC QEICONbits.UPDN_SRC
#define _TQCS QEICONbits.TQCS
#define _POSRES QEICONbits.POSRES
#define _TQCKPS0 QEICONbits.TQCKPS0
#define _TQCKPS1 QEICONbits.TQCKPS1
#define _TQGATE QEICONbits.TQGATE
#define _PCDOUT QEICONbits.PCDOUT
#define _SWPAB QEICONbits.SWPAB
#define _QEIM0 QEICONbits.QEIM0
#define _QEIM1 QEICONbits.QEIM1
#define _QEIM2 QEICONbits.QEIM2
#define _UPDN QEICONbits.UPDN
#define _INDX QEICONbits.INDX
#define _QEISIDL QEICONbits.QEISIDL
#define _CNTERR QEICONbits.CNTERR
#define _TQCKPS QEICONbits.TQCKPS
#define _QEIM QEICONbits.QEIM

/* DFLTCON */
#define _QECK0 DFLTCONbits.QECK0
#define _QECK1 DFLTCONbits.QECK1
#define _QECK2 DFLTCONbits.QECK2
#define _QEOUT DFLTCONbits.QEOUT
#define _CEID DFLTCONbits.CEID
#define _IMV0 DFLTCONbits.IMV0
#define _IMV1 DFLTCONbits.IMV1
#define _QECK DFLTCONbits.QECK
#define _IMV DFLTCONbits.IMV

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

/* IC2CON */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTMR cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */

/* IC7CON */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTMR cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */

/* IC8CON */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTMR cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */

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

/* PTCON */
#define _PTMOD PTCONbits.PTMOD
#define _PTCKPS PTCONbits.PTCKPS
#define _PTOPS PTCONbits.PTOPS
#define _PTSIDL PTCONbits.PTSIDL
#define _PTEN PTCONbits.PTEN
#define _PTMOD0 PTCONbits.PTMOD0
/* Bitname _PTMOD1 cannot be defined because it is used by more than one SFR */
#define _PTCKPS0 PTCONbits.PTCKPS0
#define _PTCKPS1 PTCONbits.PTCKPS1
#define _PTOPS0 PTCONbits.PTOPS0
#define _PTOPS1 PTCONbits.PTOPS1
#define _PTOPS2 PTCONbits.PTOPS2
#define _PTOPS3 PTCONbits.PTOPS3

/* PTMR */
#define _PTMR PTMRbits.PTMR
#define _PTDIR PTMRbits.PTDIR

/* PTPER */
#define _PTPER PTPERbits.PTPER

/* SEVTCMP */
#define _SEVTCMP SEVTCMPbits.SEVTCMP
#define _SEVTDIR SEVTCMPbits.SEVTDIR

/* PWMCON1 */
#define _PEN1L PWMCON1bits.PEN1L
#define _PEN2L PWMCON1bits.PEN2L
#define _PEN3L PWMCON1bits.PEN3L
#define _PEN1H PWMCON1bits.PEN1H
#define _PEN2H PWMCON1bits.PEN2H
#define _PEN3H PWMCON1bits.PEN3H
/* Bitname _PTMOD1 cannot be defined because it is used by more than one SFR */
#define _PTMOD2 PWMCON1bits.PTMOD2
#define _PTMOD3 PWMCON1bits.PTMOD3
#define _PMOD1 PWMCON1bits.PMOD1
#define _PMOD2 PWMCON1bits.PMOD2
#define _PMOD3 PWMCON1bits.PMOD3

/* PWMCON2 */
#define _UDIS PWMCON2bits.UDIS
#define _OSYNC PWMCON2bits.OSYNC
#define _IUE PWMCON2bits.IUE
#define _SEVOPS PWMCON2bits.SEVOPS
#define _SEVOPS0 PWMCON2bits.SEVOPS0
#define _SEVOPS1 PWMCON2bits.SEVOPS1
#define _SEVOPS2 PWMCON2bits.SEVOPS2
#define _SEVOPS3 PWMCON2bits.SEVOPS3

/* DTCON1 */
#define _DTA DTCON1bits.DTA
#define _DTAPS DTCON1bits.DTAPS
#define _DTA0 DTCON1bits.DTA0
#define _DTA1 DTCON1bits.DTA1
#define _DTA2 DTCON1bits.DTA2
#define _DTA3 DTCON1bits.DTA3
#define _DTA4 DTCON1bits.DTA4
#define _DTA5 DTCON1bits.DTA5
#define _DTAPS0 DTCON1bits.DTAPS0
#define _DTAPS1 DTCON1bits.DTAPS1

/* FLTACON */
#define _FAEN1 FLTACONbits.FAEN1
#define _FAEN2 FLTACONbits.FAEN2
#define _FAEN3 FLTACONbits.FAEN3
#define _FLTAM FLTACONbits.FLTAM
#define _FAOV1L FLTACONbits.FAOV1L
#define _FAOV1H FLTACONbits.FAOV1H
#define _FAOV2L FLTACONbits.FAOV2L
#define _FAOV2H FLTACONbits.FAOV2H
#define _FAOV3L FLTACONbits.FAOV3L
#define _FAOV3H FLTACONbits.FAOV3H

/* OVDCON */
#define _POUT1L OVDCONbits.POUT1L
#define _POUT1H OVDCONbits.POUT1H
#define _POUT2L OVDCONbits.POUT2L
#define _POUT2H OVDCONbits.POUT2H
#define _POUT3L OVDCONbits.POUT3L
#define _POUT3H OVDCONbits.POUT3H
#define _POVD1L OVDCONbits.POVD1L
#define _POVD1H OVDCONbits.POVD1H
#define _POVD2L OVDCONbits.POVD2L
#define _POVD2H OVDCONbits.POVD2H
#define _POVD3L OVDCONbits.POVD3L
#define _POVD3H OVDCONbits.POVD3H

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
#define _ABAUD U1MODEbits.ABAUD
#define _LPBACK U1MODEbits.LPBACK
#define _WAKE U1MODEbits.WAKE
#define _ALTIO U1MODEbits.ALTIO
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
#define _UTXISEL U1STAbits.UTXISEL
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
#define _UTXREG8 U1TXREGbits.UTXREG8
#define _UTX8 U1TXREGbits.UTX8

/* U1RXREG */
#define _URXREG0 U1RXREGbits.URXREG0
#define _URXREG1 U1RXREGbits.URXREG1
#define _URXREG2 U1RXREGbits.URXREG2
#define _URXREG3 U1RXREGbits.URXREG3
#define _URXREG4 U1RXREGbits.URXREG4
#define _URXREG5 U1RXREGbits.URXREG5
#define _URXREG6 U1RXREGbits.URXREG6
#define _URXREG7 U1RXREGbits.URXREG7
#define _URXREG8 U1RXREGbits.URXREG8
#define _URX8 U1RXREGbits.URX8

/* SPI1STAT */
#define _SPIRBF SPI1STATbits.SPIRBF
#define _SPITBF SPI1STATbits.SPITBF
#define _SPIROV SPI1STATbits.SPIROV
#define _SPISIDL SPI1STATbits.SPISIDL
#define _SPIEN SPI1STATbits.SPIEN

/* SPI1CON */
#define _PPRE0 SPI1CONbits.PPRE0
#define _PPRE1 SPI1CONbits.PPRE1
#define _SPRE0 SPI1CONbits.SPRE0
#define _SPRE1 SPI1CONbits.SPRE1
#define _SPRE2 SPI1CONbits.SPRE2
#define _MSTEN SPI1CONbits.MSTEN
#define _CKP SPI1CONbits.CKP
#define _SSEN SPI1CONbits.SSEN
#define _CKE SPI1CONbits.CKE
#define _SMP SPI1CONbits.SMP
#define _MODE16 SPI1CONbits.MODE16
#define _DISSDO SPI1CONbits.DISSDO
#define _SPIFSD SPI1CONbits.SPIFSD
#define _FRMEN SPI1CONbits.FRMEN
#define _PPRE SPI1CONbits.PPRE
#define _SPRE SPI1CONbits.SPRE

/* ADCON1 */
#define _DONE ADCON1bits.DONE
#define _SAMP ADCON1bits.SAMP
#define _ASAM ADCON1bits.ASAM
#define _SIMSAM ADCON1bits.SIMSAM
#define _SSRC ADCON1bits.SSRC
#define _FORM ADCON1bits.FORM
#define _ADSIDL ADCON1bits.ADSIDL
#define _ADON ADCON1bits.ADON
#define _SSRC0 ADCON1bits.SSRC0
#define _SSRC1 ADCON1bits.SSRC1
#define _SSRC2 ADCON1bits.SSRC2
#define _FORM0 ADCON1bits.FORM0
#define _FORM1 ADCON1bits.FORM1

/* ADCON2 */
#define _ALTS ADCON2bits.ALTS
#define _BUFM ADCON2bits.BUFM
#define _SMPI ADCON2bits.SMPI
#define _BUFS ADCON2bits.BUFS
#define _CHPS ADCON2bits.CHPS
#define _CSCNA ADCON2bits.CSCNA
#define _VCFG ADCON2bits.VCFG
#define _SMPI0 ADCON2bits.SMPI0
#define _SMPI1 ADCON2bits.SMPI1
#define _SMPI2 ADCON2bits.SMPI2
#define _SMPI3 ADCON2bits.SMPI3
#define _CHPS0 ADCON2bits.CHPS0
#define _CHPS1 ADCON2bits.CHPS1
#define _VCFG0 ADCON2bits.VCFG0
#define _VCFG1 ADCON2bits.VCFG1
#define _VCFG2 ADCON2bits.VCFG2

/* ADCON3 */
#define _ADCS ADCON3bits.ADCS
#define _ADRC ADCON3bits.ADRC
#define _SAMC ADCON3bits.SAMC
#define _ADCS0 ADCON3bits.ADCS0
#define _ADCS1 ADCON3bits.ADCS1
#define _ADCS2 ADCON3bits.ADCS2
#define _ADCS3 ADCON3bits.ADCS3
#define _ADCS4 ADCON3bits.ADCS4
#define _ADCS5 ADCON3bits.ADCS5
#define _SAMC0 ADCON3bits.SAMC0
#define _SAMC1 ADCON3bits.SAMC1
#define _SAMC2 ADCON3bits.SAMC2
#define _SAMC3 ADCON3bits.SAMC3
#define _SAMC4 ADCON3bits.SAMC4

/* ADCHS */
#define _CH0SA ADCHSbits.CH0SA
#define _CH0NA ADCHSbits.CH0NA
#define _CH123SA ADCHSbits.CH123SA
#define _CH123NA ADCHSbits.CH123NA
#define _CH0SB ADCHSbits.CH0SB
#define _CH0NB ADCHSbits.CH0NB
#define _CH123SB ADCHSbits.CH123SB
#define _CH123NB ADCHSbits.CH123NB
#define _CH0SA0 ADCHSbits.CH0SA0
#define _CH0SA1 ADCHSbits.CH0SA1
#define _CH0SA2 ADCHSbits.CH0SA2
#define _CH0SA3 ADCHSbits.CH0SA3
#define _CH123NA0 ADCHSbits.CH123NA0
#define _CH123NA1 ADCHSbits.CH123NA1
#define _CH0SB0 ADCHSbits.CH0SB0
#define _CH0SB1 ADCHSbits.CH0SB1
#define _CH0SB2 ADCHSbits.CH0SB2
#define _CH0SB3 ADCHSbits.CH0SB3
#define _CH123NB0 ADCHSbits.CH123NB0
#define _CH123NB1 ADCHSbits.CH123NB1

/* ADPCFG */
#define _PCFG0 ADPCFGbits.PCFG0
#define _PCFG1 ADPCFGbits.PCFG1
#define _PCFG2 ADPCFGbits.PCFG2
#define _PCFG3 ADPCFGbits.PCFG3
#define _PCFG4 ADPCFGbits.PCFG4
#define _PCFG5 ADPCFGbits.PCFG5

/* ADCSSL */
#define _CSSL0 ADCSSLbits.CSSL0
#define _CSSL1 ADCSSLbits.CSSL1
#define _CSSL2 ADCSSLbits.CSSL2
#define _CSSL3 ADCSSLbits.CSSL3
#define _CSSL4 ADCSSLbits.CSSL4
#define _CSSL5 ADCSSLbits.CSSL5

/* TRISB */
#define _TRISB0 TRISBbits.TRISB0
#define _TRISB1 TRISBbits.TRISB1
#define _TRISB2 TRISBbits.TRISB2
#define _TRISB3 TRISBbits.TRISB3
#define _TRISB4 TRISBbits.TRISB4
#define _TRISB5 TRISBbits.TRISB5

/* PORTB */
#define _RB0 PORTBbits.RB0
#define _RB1 PORTBbits.RB1
#define _RB2 PORTBbits.RB2
#define _RB3 PORTBbits.RB3
#define _RB4 PORTBbits.RB4
#define _RB5 PORTBbits.RB5

/* LATB */
#define _LATB0 LATBbits.LATB0
#define _LATB1 LATBbits.LATB1
#define _LATB2 LATBbits.LATB2
#define _LATB3 LATBbits.LATB3
#define _LATB4 LATBbits.LATB4
#define _LATB5 LATBbits.LATB5

/* TRISC */
#define _TRISC13 TRISCbits.TRISC13
#define _TRISC14 TRISCbits.TRISC14
#define _TRISC15 TRISCbits.TRISC15

/* PORTC */
#define _RC13 PORTCbits.RC13
#define _RC14 PORTCbits.RC14
#define _RC15 PORTCbits.RC15

/* LATC */
#define _LATC13 LATCbits.LATC13
#define _LATC14 LATCbits.LATC14
#define _LATC15 LATCbits.LATC15

/* TRISD */
#define _TRISD0 TRISDbits.TRISD0
#define _TRISD1 TRISDbits.TRISD1

/* PORTD */
#define _RD0 PORTDbits.RD0
#define _RD1 PORTDbits.RD1

/* LATD */
#define _LATD0 LATDbits.LATD0
#define _LATD1 LATDbits.LATD1

/* TRISE */
#define _TRISE0 TRISEbits.TRISE0
#define _TRISE1 TRISEbits.TRISE1
#define _TRISE2 TRISEbits.TRISE2
#define _TRISE3 TRISEbits.TRISE3
#define _TRISE4 TRISEbits.TRISE4
#define _TRISE5 TRISEbits.TRISE5
#define _TRISE8 TRISEbits.TRISE8

/* PORTE */
#define _RE0 PORTEbits.RE0
#define _RE1 PORTEbits.RE1
#define _RE2 PORTEbits.RE2
#define _RE3 PORTEbits.RE3
#define _RE4 PORTEbits.RE4
#define _RE5 PORTEbits.RE5
#define _RE8 PORTEbits.RE8

/* LATE */
#define _LATE0 LATEbits.LATE0
#define _LATE1 LATEbits.LATE1
#define _LATE2 LATEbits.LATE2
#define _LATE3 LATEbits.LATE3
#define _LATE4 LATEbits.LATE4
#define _LATE5 LATEbits.LATE5
#define _LATE8 LATEbits.LATE8

/* TRISF */
#define _TRISF2 TRISFbits.TRISF2
#define _TRISF3 TRISFbits.TRISF3

/* PORTF */
#define _RF2 PORTFbits.RF2
#define _RF3 PORTFbits.RF3

/* LATF */
#define _LATF2 LATFbits.LATF2
#define _LATF3 LATFbits.LATF3

/* RCON */
#define _POR RCONbits.POR
#define _BOR RCONbits.BOR
#define _IDLE RCONbits.IDLE
#define _SLEEP RCONbits.SLEEP
#define _WDTO RCONbits.WDTO
#define _SWDTEN RCONbits.SWDTEN
#define _SWR RCONbits.SWR
#define _EXTR RCONbits.EXTR
#define _BGST RCONbits.BGST
#define _IOPUWR RCONbits.IOPUWR
#define _TRAPR RCONbits.TRAPR

/* OSCCON */
#define _OSWEN OSCCONbits.OSWEN
#define _LPOSCEN OSCCONbits.LPOSCEN
#define _CF OSCCONbits.CF
#define _LOCK OSCCONbits.LOCK
#define _POST OSCCONbits.POST
#define _NOSC OSCCONbits.NOSC
#define _COSC OSCCONbits.COSC
#define _POST0 OSCCONbits.POST0
#define _POST1 OSCCONbits.POST1
#define _NOSC0 OSCCONbits.NOSC0
#define _NOSC1 OSCCONbits.NOSC1
#define _NOSC2 OSCCONbits.NOSC2
#define _COSC0 OSCCONbits.COSC0
#define _COSC1 OSCCONbits.COSC1
#define _COSC2 OSCCONbits.COSC2

/* OSCTUN */
#define _TUN OSCTUNbits.TUN
#define _TUN0 OSCTUNbits.TUN0
#define _TUN1 OSCTUNbits.TUN1
#define _TUN2 OSCTUNbits.TUN2
#define _TUN3 OSCTUNbits.TUN3

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
#define _KEY NVMKEYbits.KEY

/* PMD1 */
#define _ADCMD PMD1bits.ADCMD
#define _SPI1MD PMD1bits.SPI1MD
#define _U1MD PMD1bits.U1MD
#define _I2CMD PMD1bits.I2CMD
#define _PWMMD PMD1bits.PWMMD
#define _QEIMD PMD1bits.QEIMD
#define _T1MD PMD1bits.T1MD
#define _T2MD PMD1bits.T2MD
#define _T3MD PMD1bits.T3MD
#define _T4MD PMD1bits.T4MD
#define _T5MD PMD1bits.T5MD

/* PMD2 */
#define _OC1MD PMD2bits.OC1MD
#define _OC2MD PMD2bits.OC2MD
#define _IC1MD PMD2bits.IC1MD
#define _IC2MD PMD2bits.IC2MD
#define _IC7MD PMD2bits.IC7MD
#define _IC8MD PMD2bits.IC8MD


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

/* Register FUID0 (0x8005c0)                               */

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

/* Register FUID1 (0x8005c2)                               */

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

/* Register FUID2 (0x8005c4)                               */

extern __attribute__((space(prog))) int _FUID2;
#define _FUID2(x) __attribute__((section("__FUID2.sec"),space(prog))) int _FUID2 = (x);

/*
** Only one invocation of FUID2 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FUID2.
** Multiple options may be combined, as shown:
**
** _FUID2( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
*/

/* Register FUID3 (0x8005c6)                               */

extern __attribute__((space(prog))) int _FUID3;
#define _FUID3(x) __attribute__((section("__FUID3.sec"),space(prog))) int _FUID3 = (x);

/*
** Only one invocation of FUID3 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FUID3.
** Multiple options may be combined, as shown:
**
** _FUID3( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
*/

/* Register FOSC (0xf80000)                               */

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
**   Oscillator:
**     LP                   Low-Power 32KHz Osc (No change to Primary Osc Mode bits)
**     FRC                  Internal Fast RC (No change to Primary Osc Mode bits)
**     LPRC                 Internal Low-Power RC (No change to Primary Osc Mode bits)
**     XTL                  XTL
**     HS                   HS
**     XT                   XT
**     ERCIO                ERCIO
**     ERC                  ERC
**     EC                   EC
**     ECIO                 ECIO
**     FRC_PLL4             FRC w/PLL 4x
**     FRC_PLL16            FRC w/PLL 16x
**     XT_PLL4              XT w/PLL 4x
**     XT_PLL8              XT w/PLL 8x
**     XT_PLL16             XT w/PLL 16x
**     FRC_PLL8             FRC w/PLL 8x
**     ECIO_PLL4            ECIO w/PLL 4x
**     ECIO_PLL8            ECIO w/PLL 8x
**     ECIO_PLL16           ECIO w/PLL 16x
**     HS2_PLL4             HS2 w/PLL 4x
**     HS2_PLL8             HS2 w/PLL 8x
**     HS2_PLL16            HS2 w/PLL 16x
**     HS3_PLL4             HS3 w/PLL 4x
**     HS3_PLL8             HS3 w/PLL 8x
**     HS3_PLL16            HS3 w/PLL 16x
**
**   Clock Switching and Monitor:
**     CSW_FSCM_ON          Sw Enabled, Mon Enabled
**     CSW_ON_FSCM_OFF      Sw Enabled, Mon Disabled
**     CSW_FSCM_OFF         Sw Disabled, Mon Disabled
**
*/

#define LP                   0xF8E0
#define FRC                  0xF9E0
#define LPRC                 0xFAE0
#define XTL                  0xFBE0
#define HS                   0xFBE2
#define XT                   0xFBE4
#define ERCIO                0xFBE8
#define ERC                  0xFBE9
#define EC                   0xFBEB
#define ECIO                 0xFBEC
#define FRC_PLL4             0xFFE1
#define FRC_PLL16            0xFFE3
#define XT_PLL4              0xFFE5
#define XT_PLL8              0xFFE6
#define XT_PLL16             0xFFE7
#define FRC_PLL8             0xFFEA
#define ECIO_PLL4            0xFFED
#define ECIO_PLL8            0xFFEE
#define ECIO_PLL16           0xFFEF
#define HS2_PLL4             0xFFF1
#define HS2_PLL8             0xFFF2
#define HS2_PLL16            0xFFF3
#define HS3_PLL4             0xFFF5
#define HS3_PLL8             0xFFF6
#define HS3_PLL16            0xFFF7

#define CSW_FSCM_ON          0x3FFF
#define CSW_ON_FSCM_OFF      0x7FFF
#define CSW_FSCM_OFF         0xBFFF

/* Register FWDT (0xf80002)                               */

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
**   WDT Prescaler B:
**     WDTPSB_1             1:1
**     WDTPSB_2             1:2
**     WDTPSB_3             1:3
**     WDTPSB_4             1:4
**     WDTPSB_5             1:5
**     WDTPSB_6             1:6
**     WDTPSB_7             1:7
**     WDTPSB_8             1:8
**     WDTPSB_9             1:9
**     WDTPSB_10            1:10
**     WDTPSB_11            1:11
**     WDTPSB_12            1:12
**     WDTPSB_13            1:13
**     WDTPSB_14            1:14
**     WDTPSB_15            1:15
**     WDTPSB_16            1:16
**
**   WDT Prescaler A:
**     WDTPSA_1             1:1
**     WDTPSA_8             1:8
**     WDTPSA_64            1:64
**     WDTPSA_512           1:512
**
**   Watchdog Timer:
**     WDT_OFF              Disabled
**     WDT_ON               Enabled
**
*/

#define WDTPSB_1             0xFFF0
#define WDTPSB_2             0xFFF1
#define WDTPSB_3             0xFFF2
#define WDTPSB_4             0xFFF3
#define WDTPSB_5             0xFFF4
#define WDTPSB_6             0xFFF5
#define WDTPSB_7             0xFFF6
#define WDTPSB_8             0xFFF7
#define WDTPSB_9             0xFFF8
#define WDTPSB_10            0xFFF9
#define WDTPSB_11            0xFFFA
#define WDTPSB_12            0xFFFB
#define WDTPSB_13            0xFFFC
#define WDTPSB_14            0xFFFD
#define WDTPSB_15            0xFFFE
#define WDTPSB_16            0xFFFF

#define WDTPSA_1             0xFFCF
#define WDTPSA_8             0xFFDF
#define WDTPSA_64            0xFFEF
#define WDTPSA_512           0xFFFF

#define WDT_OFF              0x7FFF
#define WDT_ON               0xFFFF

/* Register FBORPOR (0xf80004)                               */

extern __attribute__((space(prog))) int _FBORPOR;
#define _FBORPOR(x) __attribute__((section("__FBORPOR.sec"),space(prog))) int _FBORPOR = (x);

/*
** Only one invocation of FBORPOR should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FBORPOR.
** Multiple options may be combined, as shown:
**
** _FBORPOR( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   POR Timer Value:
**     PWRT_OFF             Timer Disabled
**     PWRT_4               4ms
**     PWRT_16              16ms
**     PWRT_64              64ms
**
**   Brown Out Voltage:
**     BORV45               4.5V
**     BORV42               4.2V
**     BORV27               2.7V
**     BORV20               Reserved
**
**   PBOR Enable:
**     PBOR_OFF             Disabled
**     PBOR_ON              Enabled
**
**   Low-side PWM Output Polarity:
**     PWMxL_ACT_LO         Active Low
**     PWMxL_ACT_HI         Active High
**
**   High-side PWM Output Polarity:
**     PWMxH_ACT_LO         Active Low
**     PWMxH_ACT_HI         Active High
**
**   PWM Output Pin Reset:
**     RST_PWMPIN           Control with HPOL/LPOL bits
**     RST_IOPIN            Control with PORT/TRIS regs
**
**   Master Clear Enable:
**     MCLR_DIS             Disabled
**     MCLR_EN              Enabled
**
*/

#define PWRT_OFF             0xFFFC
#define PWRT_4               0xFFFD
#define PWRT_16              0xFFFE
#define PWRT_64              0xFFFF

#define BORV45               0xFFCF
#define BORV42               0xFFDF
#define BORV27               0xFFEF
#define BORV20               0xFFFF

#define PBOR_OFF             0xFF7F
#define PBOR_ON              0xFFFF

#define PWMxL_ACT_LO         0xFEFF
#define PWMxL_ACT_HI         0xFFFF

#define PWMxH_ACT_LO         0xFDFF
#define PWMxH_ACT_HI         0xFFFF

#define RST_PWMPIN           0xFBFF
#define RST_IOPIN            0xFFFF

#define MCLR_DIS             0x7FFF
#define MCLR_EN              0xFFFF

/* Register RESERVED1 (0xf80006)                               */

extern __attribute__((space(prog))) int _RESERVED1;
#define _RESERVED1(x) __attribute__((section("__RESERVED1.sec"),space(prog))) int _RESERVED1 = (x);

/*
** Only one invocation of RESERVED1 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set RESERVED1.
** Multiple options may be combined, as shown:
**
** _RESERVED1( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
*/

/* Register RESERVED2 (0xf80008)                               */

extern __attribute__((space(prog))) int _RESERVED2;
#define _RESERVED2(x) __attribute__((section("__RESERVED2.sec"),space(prog))) int _RESERVED2 = (x);

/*
** Only one invocation of RESERVED2 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set RESERVED2.
** Multiple options may be combined, as shown:
**
** _RESERVED2( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
*/

/* Register FGS (0xf8000a)                               */

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
**     GWRP_ON              Enabled
**     GWRP_OFF             Disabled
**
**   General Segment Code Protection:
**     CODE_PROT_ON         Enabled
**     CODE_PROT_OFF        Disabled
**
*/

#define GWRP_ON              0xFFFE
#define GWRP_OFF             0xFFFF

#define CODE_PROT_ON         0xFFF9
#define CODE_PROT_OFF        0xFFFF

/* Register FICD (0xf8000c)                               */

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
**     ICS_PGD3             Use EMUC3 and EMUD3
**     PGD3                 Use EMUC3 and EMUD3
**     ICS_PGD2             Use EMUC2 and EMUD2
**     PGD2                 Use EMUC2 and EMUD2
**     ICS_PGD1             Use EMUC1 and EMUD1
**     PGD1                 Use EMUC1 and EMUD1
**     ICS_PGD              Use PGC/EMUC and PGD/EMUD
**     PGD                  Use PGC/EMUC and PGD/EMUD
**
*/

#define ICS_PGD3             0xFFFC
#define PGD3                 0xFFFC
#define ICS_PGD2             0xFFFD
#define PGD2                 0xFFFD
#define ICS_PGD1             0xFFFE
#define PGD1                 0xFFFE
#define ICS_PGD              0xFFFF
#define PGD                  0xFFFF


#endif
