/*
 * seven_segment.c
 *
 * Created: 9/30/2016 5:28:36 PM
 * Author : EngSh
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

//Encoded Number from PCM to 7-segment
int gEncoder[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};

int main(void)
{	
	int hr=0,min=0,sec=0,i;
	//Initializing Ports
	DDRC = 0xFF;
	DDRB = 0xFF;

    while (1) 
    {
		for(hr=1;hr<13;hr++){ //for loop to change hours
			for(min=0;min<60;min++){ //for loop to change minutes
				for(sec=0;sec<60;sec++){ //for to change seconds
					for(i=0;i<30;i++){ //for loop to multiplex and render with frequency of 30 Hz (the frequency that the eye can see )
						
						PORTC = ~1;
						PORTB = gEncoder[sec%10];
						_delay_ms(5);
						
						PORTC = ~2;
						PORTB = gEncoder[sec/10];
						_delay_ms(5);
						
						PORTC = ~4;
						PORTB = gEncoder[min%10];
						_delay_ms(5);
						
						PORTC = ~8;
						PORTB = gEncoder[min/10];
						_delay_ms(5);
						
						PORTC = ~16;
						PORTB = gEncoder[hr%10];
						_delay_ms(5);
						
						PORTC = ~32;
						PORTB = gEncoder[hr/10];
						_delay_ms(5);
					}
				}
			}
		}
    }
}

