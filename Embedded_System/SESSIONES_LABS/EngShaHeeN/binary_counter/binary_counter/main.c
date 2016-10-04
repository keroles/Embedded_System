/*
 * counter.c
 * This program make a binary counter and displays it on 3 LEDs at pins 4,5,6 on PORTD 
 * as well as showing the counts on 7-segment display 
 * It has two switches on Pins 0,1 on PORTD 
 * if Switch0 is Pressed it counts forward
 * if Switch1 is Pressed it counts backward
 *
 * Created: 9/30/2016 4:41:55 PM
 * Author : EngShaHeeN
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{	
	int inc=1;
	int  Num = 0;
		
	DDRD = 0xE0;
	DDRC = 0xF4;
	 
    while (1) 
    {
		
		if(PIND & 1){
			while(PIND & 1);
			inc = 1;
		}
		if(PIND & 2){
			while(PIND & 2);
			inc = -1;
		}
		
		Num += inc;
		if(Num == 8) Num = 0;
		else if(Num == -1) Num =7;
		PORTC = Num << 4;
		PORTC |= 1 << 2;
		PORTD = Num << 5; 
		_delay_ms(5000);
		
    }
}