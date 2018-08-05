/*
 * Atmega32_registers.h
 *
 *  Created on: Aug 4, 2017
 *   *      Author: Keroles Shenouda
 *      https://www.facebook.com/groups/embedded.system.KS/
 */

#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_

#define mySREG   *((volatile unsigned char* const)0X5F)
#define mySPH    *((volatile unsigned char* const)0X5E)
#define mySPL    *((volatile unsigned char* const)0X5D)
#define myOCR0   *((volatile unsigned char* const)0X5C)
#define myGICR   *((volatile unsigned char* const)0X5B)
#define myGIFR   *((volatile unsigned char* const)0X5A)
#define myTIMSK  *((volatile unsigned char* const)0X59)
#define myTIFR   *((volatile unsigned char* const)0X58)
#define mySPMCR  *((volatile unsigned char* const)0X57)
#define myTWCR   *((volatile unsigned char* const)0X56)
#define myMCUCR  *((volatile unsigned char* const)0X55)
#define myMCUCSR *((volatile unsigned char* const)0X54)
#define myTCCR0  *((volatile unsigned char* const)0X53)
#define myTCNT0  *((volatile unsigned char* const)0X52)
#define myOSCCAL *((volatile unsigned char* const)0X51)
#define myOCDR   *((volatile unsigned char* const)0X51)
#define mySFIOR  *((volatile unsigned char* const)0X50)
#define myTCCR1A *((volatile unsigned char* const)0X4F)
#define myTCCR1B *((volatile unsigned char* const)0X4E)
#define myTCNT1H *((volatile unsigned char* const)0X4D)
#define myTCNT1L *((volatile unsigned char* const)0X4C)
#define myOCR1AH *((volatile unsigned char* const)0X4B)
#define myOCR1AL *((volatile unsigned char* const)0X4A)
#define myOCR1BH *((volatile unsigned char* const)0X49)
#define myOCR1BL *((volatile unsigned char* const)0X48)
#define myICR1H  *((volatile unsigned char* const)0X47)
#define myICR1L  *((volatile unsigned char* const)0X46)
#define myTCCR2  *((volatile unsigned char* const)0X45)
#define myTCNT2  *((volatile unsigned char* const)0X44)
#define myOCR2   *((volatile unsigned char* const)0X43)
#define myASSR   *((volatile unsigned char* const)0X42)
#define myWDTCR  *((volatile unsigned char* const)0X41)
#define myUBRRH  *((volatile unsigned char* const)0X40)
#define myUCSRC  *((volatile unsigned char* const)0X40)
#define myEEARH  *((volatile unsigned char* const)0X3F)
#define myEEARL  *((volatile unsigned char* const)0X3E)
#define myEEDR   *((volatile unsigned char* const)0X3D)
#define myEECR   *((volatile unsigned char* const)0X3C)

#define myPORTA  *((volatile unsigned char* const)0X3B)
#define myDDRA   *((volatile unsigned char* const)0X3A)
#define myPINA   *((volatile unsigned char* const)0X39)
#define myPORTB  *((volatile unsigned char* const)0X38)
#define myDDRB   *((volatile unsigned char* const)0X37)
#define myPINB   *((volatile unsigned char* const)0X36)
#define myPORTC  *((volatile unsigned char* const)0X35)
#define myDDRC   *((volatile unsigned char* const)0X34)
#define myPINC   *((volatile unsigned char* const)0X33)
#define myPORTD  *((volatile unsigned char* const)0X32)
#define myDDRD   *((volatile unsigned char* const)0X31)
#define myPIND   *((volatile unsigned char* const)0X30)

#define mySPDR   *((volatile unsigned char* const)0X2F)
#define mySPSR   *((volatile unsigned char* const)0X2E)
#define mySPCR   *((volatile unsigned char* const)0X2D)
#define myUDR    *((volatile unsigned char* const)0X2C)
#define myUCSRA  *((volatile unsigned char* const)0X2B)
#define myUCSRB  *((volatile unsigned char* const)0X2A)
#define myUBRRL  *((volatile unsigned char* const)0X29)
#define myACSR   *((volatile unsigned char* const)0X28)
#define myADMUX  *((volatile unsigned char* const)0X27)
#define myADCSRA *((volatile unsigned char* const)0X26)
#define myADCH   *((volatile unsigned char* const)0X25)
#define myADCL   *((volatile unsigned char* const)0X24)
#define myTWDR   *((volatile unsigned char* const)0X23)
#define myTWAR   *((volatile unsigned char* const)0X22)
#define myTWSR   *((volatile unsigned char* const)0X21)
#define myTWBR   *((volatile unsigned char* const)0X20)


#endif /* ATMEGA32_REGISTERS_H_ */
