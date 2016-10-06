/*
 * Digital_Clock_Ziad.c
 *
 * Created: 10/5/2016 8:41:17 PM
 *  Author: Ziad-Khater
 */ 


#include <avr/io.h>
#include "my_header.h"
#include "util/delay.h"
u8 h1,h2,m1,m2,s1,s2;
int main(void)
{
	DDRA=0xFF;
	DDRB=0xFF;
	DDRC=0xFF;
	DDRD=0x00;
	
    while(1)
    {
beginning : for(h1=0;h1<=2;h1++)
			for(h2=0;h2<=23;h2++)
		
			for(m1=0;m1<=5;m1++)
			for(m2=0;m2<=9;m2++)
		
			for(s1=0;s1<=5;s1++)
			for(s2=0;s2<=9;s2++)		 
			{
				//clock_edit();
				if((h1==2) && (h2==4))
				{
					goto beginning;
				}
				PORTA=(s2<<0)|(s1<<4);
				PORTB=(m2<<0)|(m1<<4);
				PORTC=(h2<<0)|(h1<<4);
				_delay_ms(1000);
				
			}

	}
}