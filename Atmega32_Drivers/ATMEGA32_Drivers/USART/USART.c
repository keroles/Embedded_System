/*
 * USART.C
 *
 *  Created on: Sep 28, 2017
 *
 *      Author: Keroles Shenouda
 *      https://www.facebook.com/groups/embedded.system.KS/
 */
#include "USART.h"
#include "avr/io.h"
#include "avr/interrupt.h"
/******************Pointer to functions to be assigned to ISR*******************/

static void (*Ptr_To_Trans_Int) (void);
static void (*Ptr_To_Rec_Int) (void);

struct USART_Config global_USART_Config ;


/*********************************/
 void USART_Init(struct USART_Config Config) {

	unsigned long UBRR_VAL ;
	global_USART_Config = Config ;


	/************** Set baud rate **************/

	if ((global_USART_Config.SYNCH_MODE == USART_ASYNCH) && (global_USART_Config.SPEED_MODE == USART_NORMAL_SPEED))
	{
		UBRR_VAL = (unsigned long)((USART_FOSC/(16*USART_BAUD))-1) ;
	}
	else if ((global_USART_Config.SYNCH_MODE == USART_ASYNCH) && (global_USART_Config.SPEED_MODE == USART_DOUBLE_SPEED))
	{
		UBRR_VAL = (unsigned short)((USART_FOSC/(8*USART_BAUD))-1) ;

	}
	else if  ((global_USART_Config.SYNCH_MODE == USART_SYNC))
	{
		UBRR_VAL = (unsigned long)((USART_FOSC/(2*USART_BAUD))-1) ;

	}

	UBRRH =(unsigned char) (UBRR_VAL >> 8);

	UBRRL = (unsigned char) UBRR_VAL;

	/************** Enable transmitter **************/
 if ( global_USART_Config.TRANSMIT == USART_TRANSMIT_ENABLE )
 {
	 UCSRB = UCSRB | (1 << TXEN);

 }
 else if ( global_USART_Config.TRANSMIT == USART_TRANSMIT_DISABLE )
 {

		UCSRB &= ~(1<<TXEN);
 }

	/************** Enable receiver **************/
 if ( global_USART_Config.RECIEVE == USART_RECIEVE_ENABLE )
 {
	 UCSRB = UCSRB | (1 << RXEN);

 }
 else if ( global_USART_Config.RECIEVE == USART_RECIEVE_DISABLE )
 {

		UCSRB &= ~(1<<RXEN);
 }


	/**************** Set character size***************/
 if ( global_USART_Config.CHAR_SIZE != USART_9_Bit_CHAR )
 {
		UCSRC = (1 << URSEL) | (global_USART_Config.CHAR_SIZE);

 }
 else if (global_USART_Config.CHAR_SIZE == USART_9_Bit_CHAR )
 {

		UCSRC = (1 << URSEL) |( (global_USART_Config.CHAR_SIZE)&0b11);
		UCSRB |= 1<<2 ;
 }


	/**************** Set Double speed***************/
if ((global_USART_Config.SYNCH_MODE == USART_ASYNCH) && (global_USART_Config.SPEED_MODE == USART_DOUBLE_SPEED))
{
	UCSRA |= 1<< U2X ;

}
	/**************** Set Parity Bit***************/
	UCSRC |= (1<<URSEL) | global_USART_Config.PARITY_MODE;
	/**************** Set SYNCH ASYNCH***************/
	UCSRC |= (1<<URSEL) | global_USART_Config.SYNCH_MODE;
	/**************** Set Stop Bit***************/
	UCSRC |= (1<<URSEL) | global_USART_Config.STOPBIT;
	/***************RECIEVER INT ENABLE**********/
	UCSRB |= global_USART_Config.RECIEVE_INT;
	/***************TRANSMITER INT ENABLE**********/
	UCSRB |= global_USART_Config.TRANSMITER_INT;
}



 void USART_Transmit(unsigned short data) {
	/* Wait for empty transmit buffer */
	while (!( UCSRA & (1 << UDRE)))
		;
	/***********if the data to be transmitted is 9 bits, write the MSB first*****************/
	if ( global_USART_Config.CHAR_SIZE  ==	USART_9_Bit_CHAR )
	{
		UCSRB |= ((data >> 8) & 1);
	}
		/* Put data into buffer, sends the data */
	UDR = (unsigned char)data;
}




 unsigned char USART_Receive(unsigned short *Ptr_To_Val) {
	unsigned char local_u8ParityError = 0; // 0 means error
	*Ptr_To_Val = 0;
	/* Wait for data to be received */
	while (!(UCSRA & (1 << RXC)) )
		;
	/****************Check if parity error is not ON********/
	if(((UCSRA >> PE)& 1) != 1)
	{/***********if the data to be recieved is 9 bits, get the MSB first*****************/
	if (global_USART_Config.CHAR_SIZE  ==	USART_9_Bit_CHAR)
	{
		*Ptr_To_Val = (((UCSRB >> 1)& 1) << 8) ;
	}

		/* Get and return received data from buffer */
		*Ptr_To_Val |= UDR;
		local_u8ParityError = 1; //no error
	}
	return local_u8ParityError;

}




 void USART_Rec_Int_Enable(void)
{
	UCSRB |= 1<< RXCIE ;

}

 void USART_Rec_Int_Disable(void)
{
	UCSRB &= ~(1<<RXCIE);
}




 void USART_Trans_Int_Enable(void)
{
	UCSRB |= 1<< TXCIE ;
}


 void USART_Trans_Int_Disable(void)
{
	UCSRB &= ~ (1<<TXCIE);

}








 void USART_Rec_Enable(void)
{
	UCSRB |= 1<< RXEN ;

}

 void USART_Rec_Disable(void)
{
	UCSRB &=~(1<<RXEN);

}





 void USART_Trans_Enable(void)
{
	UCSRB |= 1<<TXEN;
}

 void USART_Trans_Disable(void)
{
	UCSRB &= ~ (1<<TXEN) ;
}





 void USART_callback_Rec_Int(void (*Ptr_to_Func)(void))
{
	Ptr_To_Rec_Int = Ptr_to_Func;
}
 void USART_callback_Trans_Int(void (*Ptr_to_Func)(void))
{
	Ptr_To_Trans_Int = Ptr_to_Func;
}


ISR(USART_RXC_vect)
{
	(*Ptr_To_Rec_Int)();
}

ISR(USART_TXC_vect)
{
	(*Ptr_To_Trans_Int)();
}
