/*
 * InterruptTest.c
 *
 * 
 *  Author: Keroles shenouda
 */ 
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect)
{
	//DDRD = 0xff;
	PORTD |= 1<<5;
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	//DDRD = 0xff;
	PORTD |= 1<<6;
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	//DDRD = 0xff;
	PORTD |= 1<<7 ;
	_delay_ms(1000);
}
int main(void)
{

	
	/* Int0 any change*
	   Int 1 /rising edge
	   int2 falling edge*/
	MCUCR |= (1<<0 |  1<<2 | 1<< 3);
	MCUCR &= ~(1<<1);
	MCUCSR &= ~(1<<6);
	GICR |= (1<<5 |  1<<6 | 1<< 7);
	sei(); // enable SREG [global interrupt enable]
	DDRD |= (1<<5) | (1<<6) | (1<<7) ; 
    while(1)
    {
        
	
		PORTD &= ~((1<<5) | (1<<6) | (1<<7)) ; 
		_delay_ms(1000);
    }
}