/*
 * USART.h
 *
 *  Created on: Sep 28, 2017
 *
 *      Author: Keroles Shenouda
 *      https://www.facebook.com/groups/embedded.system.KS/
 */

#ifndef USART_USART_H_
#define USART_USART_H_



//Configuration
#define USART_BAUD				1200
#define USART_FOSC				1000000
enum USART_SYNCH_MODE
{
	USART_ASYNCH =0 ,
	USART_SYNC = (1<<6)
};
enum USART_SPEED_MODE
{
	USART_NORMAL_SPEED,
	USART_DOUBLE_SPEED
};
enum USART_TRANSMIT
{
	USART_TRANSMIT_DISABLE,
	USART_TRANSMIT_ENABLE
};
enum USART_RECIEVE
{
	USART_RECIEVE_DISABLE,
	USART_RECIEVE_ENABLE
};
enum USART_CHAR_SIZE
{
	USART_5_Bit_CHAR 	=	(0b00<<1),
	USART_6_Bit_CHAR 	=	(0b01<<1),
	USART_7_Bit_CHAR	 =   (0b10<<1),
	USART_8_Bit_CHAR	 =   (0b11<<1),
	USART_9_Bit_CHAR	 =   (0b111<<1)
};
enum USART_PARITY_MODE
{
	USART_NO_PARITY		=(0<<4),
	USART_EVEN_PARITY		=(2<<4),
	USART_ODD_PARITY 	   = (3<<4)
};
enum USART_STOPBIT
{
	USART_1_STOPBIT =	(0<<3),
	USART_2_STOPBIT =(1<<3)
};
enum USART_RECIEVE_INT
{
	USART_RECIEVER_ENABLE 	=	(1<<7),
	USART_RECIEVER_DISABLE 	=	(0<<7)
};
enum USART_TRANSMITER_INT
{
	USART_TRANSMITER_ENABLE 	=(1<<6),
	USART_TRANSMITER_DISABLE =	(0<<6)
};

struct USART_Config
{
	enum USART_SYNCH_MODE SYNCH_MODE ;
	enum USART_SPEED_MODE SPEED_MODE;
	enum USART_TRANSMIT TRANSMIT;
	enum USART_RECIEVE RECIEVE;
	enum USART_CHAR_SIZE CHAR_SIZE ;
	enum USART_PARITY_MODE PARITY_MODE;
	enum USART_STOPBIT STOPBIT;
	enum USART_RECIEVE_INT RECIEVE_INT;
	enum USART_TRANSMITER_INT TRANSMITER_INT;
};

///////////////////////////////////APIs
  void USART_Init(struct USART_Config Config);
 void USART_Transmit(unsigned short data);
 unsigned char USART_Receive(unsigned short *Ptr_To_Val);
 void USART_Rec_Int_Enable(void);
 void USART_Rec_Int_Disable(void);
 void USART_Trans_Int_Enable(void);
 void USART_Trans_Int_Disable(void);
 void USART_Rec_Enable(void);
 void USART_Rec_Disable(void);
 void USART_Trans_Enable(void);
 void USART_Trans_Disable(void);
 void USART_callback_Rec_Int(void (*Ptr_to_Func)(void));
 void USART_callback_Trans_Int(void (*Ptr_to_Func)(void));
/********************************Registers***********************************/


/**********************UCSRA************************/
#define RXC 	7
#define TXC 	6
#define UDRE 	5
#define FE 		4
#define DOR		3
#define PE 		2
#define U2X		1
#define MPCM	0

/**********************UCSRB************************/
#define RXCIE 	7
#define TXCIE	6
#define UDRIE	5
#define RXEN 	4
#define TXEN	3
#define UCSZ2	2
#define RXB8	1
#define TXB8	0

/**********************UCSRC************************/
#define URSEL	7
#define UMSEL	6
#define UPM1	5
#define UPM0	4
#define USBS	3
#define UCSZ1	2
#define UCSZ0	1
#define UCPOL	0




#endif /* USART_USART_H_ */
