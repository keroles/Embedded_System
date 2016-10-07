/*
 * intrupt.c
 *
 * Created: 9/30/2016 8:51:34 PM
 * Author : EngSh
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


ISR(INT0_vect){
	
	PORTD |= 1<<5;
	_delay_ms(1000);
}
ISR(INT1_vect){
	PORTD |= 1<<6;
	_delay_ms(1000);
}
ISR(INT2_vect){
	PORTD |= 1<<7;
	_delay_ms(1000);
}


int main(void)
{
	//Initialization 
	sei();
	MCUCR |= (1<<0 | 1<<2 | 1<<3);
	MCUCSR &= ~(1<<6);
	GICR |= 7<<5;
	DDRD |= 7<<5;
    /* Replace with your application code */
    while (1) 
    {
		PORTD &= ~(7<<5);
    }
}

