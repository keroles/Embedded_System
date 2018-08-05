/*
 * SPI.h
 *
 *  Created on: Oct 6, 2017
 *      Author: kkhalil
 */

#ifndef SPI_SPI_H_
#define SPI_SPI_H_

enum SPI_SLAVE_MODE
{
	SPI_MASTER =1,
	SPI_SLAVE = 0
};

enum SPI_PRESCALAR
{
	SPI_Fosc4 = 0b00,
	SPI_Fosc16 = 0b01,
	SPI_Fosc64 = 0b10,
	SPI_Fosc128 = 0b11
};

enum SPI_ENABLE
{
	SPI_ENABLE_ON =1 ,
	SPI_ENABLE_OFF = 0
};

enum SPI_DOUBLE_SPEED
{
	SPI_DOUBLE_SPEED_MODE_OFF,
	SPI_DOUBLE_SPEED_MODE_ON
};

enum SPI_OPERATING_LEVEL
{
	SPI_IDLE_LOW,
	SPI_IDLE_HIGH
};

enum SPI_SAMPLING_EDGE
{
	SPI_RISING =1 ,
	SPI_FALLING = 0
};


enum SPI_INT_ENABLE
{
	SPI_INT_OFF,
	SPI_INT_ON
};
enum SPI_DATA_ORDER
{
	SPI_LSB_FISRT = 1,
	SPI_MSB_FISRT = 0
};

struct S_SPI_Configuration
{
	enum SPI_SLAVE_MODE SLAVE_MODE ;
	enum SPI_PRESCALAR  PRESCALAR ;
	enum SPI_ENABLE  ENABLE;
	enum SPI_DOUBLE_SPEED  DOUBLE_SPEED;
	enum SPI_OPERATING_LEVEL  OPERATING_LEVEL;
	enum SPI_SAMPLING_EDGE   SAMPLING_EDGE;
	enum SPI_INT_ENABLE    INT_ENABLE;
	enum SPI_DATA_ORDER  DATA_ORDER ;
};

/*****************SPCR*************/
#define SPIE 	7
#define SPE 	6
#define DORD 	5
#define MSTR 	4
#define CPOL 	3
#define CPHA 	2
#define SPR1	1
#define SPR0	0
/*****************SPSR*************/
#define SPIF	7
#define WCOL	6
#define SPI2X	0


#define okay  1
#define error 0
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long  u32;
typedef signed long   s32;
typedef unsigned long   u64;
typedef signed long   s64;
typedef float f32;
typedef double f64;
#define GetBit(Reg,BitNo) ((Reg>>BitNo)&1)
#define ClrBit(Reg,BitNo)  ((Reg)&=~(1<<(BitNo)))
#define SetBit(Reg,BitNo)  (Reg|=(1<<BitNo))
#define ToggelBit(Reg,BitNo) (Reg^(1<<BitNo))

 void SPI_voidInit(struct S_SPI_Configuration spi_Config);
 u8  SPI_Send_And_receive(u8 Copy_u8Data);
 u8 SPI_Checks_for_collision(void);
 void SPI_callBackFunc_Assign(void(*PtrToSPI_Isr)(void));



#endif /* SPI_SPI_H_ */
