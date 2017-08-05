/*
 * GPIO.h
 *
 *  Created on: Aug 4, 2017
 * *      Author: Keroles Shenouda
 *      https://www.facebook.com/groups/embedded.system.KS/
 */


#ifndef GPIO_H_
#define GPIO_H_


#include "../Data_Types.h"


#define myPORTA  ((volatile unsigned char* const)0X3B)
#define myDDRA   ((volatile unsigned char* const)0X3A)
#define myPINA   ((volatile unsigned char* const)0X39)
#define myPORTB  ((volatile unsigned char* const)0X38)
#define myDDRB   ((volatile unsigned char* const)0X37)
#define myPINB   ((volatile unsigned char* const)0X36)
#define myPORTC  ((volatile unsigned char* const)0X35)
#define myDDRC   ((volatile unsigned char* const)0X34)
#define myPINC   ((volatile unsigned char* const)0X33)
#define myPORTD  ((volatile unsigned char* const)0X32)
#define myDDRD   ((volatile unsigned char* const)0X31)
#define myPIND   ((volatile unsigned char* const)0X30)


#define u8_Direction_input 0x00
#define u8_Direction_output 0xFF
//choose the default intialization for GPIO
#define Init_direction_default  u8_Direction_input
#define no_of_pins_on_port  8
//=========================Initialization====================================
/*Comment!: Initialization function */
 void GPIO_voidInit(void);
//====================================================================

//===================PIN==========================
//Data
/*Comment!: Read Pin Value */
 extern u8 GPIO_u8_ReadPinVal(u8 PinIdx,u8* PtrToVal, u8 Port_Name);

/*Comment!: Write Pin Value */
 extern u8 GPIO_u8_WritePinVal(u8 PinIdx,u8 PinVal , u8 Port_Name);

//Direction
/*Comment!: Write Pin Direction */
 extern u8 GPIO_u8_WritePinDir(u8 PinIdx,u8 PinDir, u8 Port_Name);

/*Comment!: Read Pin Direction */
 extern u8 GPIO_u8_ReadPinDir(u8 PinIdx,u8* PtrToDir, u8 Port_Name);

//===================PORT==========================
//Data
/*Comment!: Read Port Value */
 extern u8 GPIO_u8_ReadPortVal(u8* PtrToVal , u8 Port_Name);

/*Comment!: Write Port Value */
 extern u8 GPIO_u8_WritePortVal(u8 PortVal , u8 Port_Name);

//Direction
/*Comment!: Write Port Direction */
 extern u8 GPIO_u8_WritePortDir(u8 PortDir, u8 Port_Name);

/*Comment!: Read Port Direction */
 extern u8 GPIO_u8_ReadPortDir(u8* PtrToDir, u8 Port_Name);
//====================================================================

#endif
