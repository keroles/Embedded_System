/*
 * seven_segment.c
 *
 * Created: 9/30/2016 5:28:36 PM
 * Author : EngSh
 */ 
//#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define wait 5000 // The duration for displaying the number on each 7-segment display in Microseconds
#define menu_wait 50 // The duration of displaying the number in the MUNE mode in MilliSeconds

//Encoded Number from PCM to 7-segment
int gEncoder[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
volatile int gCounter = 0;
volatile int gHr=0,gMin=0,gSec=0;
volatile char gMenu = 0;

ISR(TIMER0_OVF_vect)
{
	if(gCounter < 4) gCounter++;
	else
	{
		gCounter = 0;
		if(gSec < 60) gSec++;
		else
		{
			gSec = 0;
			if(gMin < 60) gMin++;
			else
			{
				gMin = 0;
				if(gHr < 24) gHr++;
				else
				{
					gHr = 0;
				}
			}
		}
	}
}
ISR(INT0_vect)
{
	//if (gMenu == 0) gMenu = 1:
	//else gMenu = 0;
	gMenu ^= 1;
	TIMSK ^= 1;
	PORTA = gMenu;
}

int main(void)
{	
	char mode = 0; // determine the menu mode 0 for Seconds, 1 for Minutes and 2 for Hours
	//Initializing Ports
	DDRA |= 1; 
	PORTA &= ~1;
	DDRC = 0xFF; // setting Port C direction to be OUTPUT
	DDRB = 0xFF; // setting Port B direction to be OUTPuT
	DDRD = 0x00; // setting Port D direction to be INPUT
	PORTD = 0xFF; // Enabling PULLUP resistor for port D
	//Timer 0 initialization (prescaler CLK/1024)
	TCCR0 = 0x05;
	TIMSK |= 1;
	//External Interrupt initializing for INT0 as (FALLING edge)
	MCUCR |= 2;
	GICR |= 1<<6;
	
	sei(); // Enable general interrupt mask

    while (1) 
    {	
		// while NOT in MENU mode (MENU button not pressed) 
		if(~gMenu) 
		{
			PORTC = ~1;
			PORTB = gEncoder[gSec%10];
			_delay_us(wait);
			
			PORTC = ~2;
			PORTB = gEncoder[gSec/10];
			_delay_us(wait);
			
			PORTC = ~4;
			PORTB = gEncoder[gMin%10];
			_delay_us(wait);
			
			PORTC = ~8;
			PORTB = gEncoder[gMin/10];
			_delay_us(wait);
			
			PORTC = ~16;
			PORTB = gEncoder[gHr%10];
			_delay_us(wait);
			
			PORTC = ~32;
			PORTB = gEncoder[gHr/10];
			_delay_us(wait);
		}
		
		// While in MENU mode (MENU button pressed)
		if(gMenu)
		{
			 // if LEFT button pressed (single press) 
			 // change the mode (Seconds >> Minutes >> Hours and then repeat) 
			if (~PIND & 64)
			{
				while(~PIND & 64); 
				if(mode < 2) mode++;
				else mode = 0;
				
			}
			
			// if RIGHT button pressed (single press)
			// change the mode (Hours >> Minutes >> Seconds and then repeat)
			if (~PIND & 32)
			{
				while(~PIND & 32);
				if(mode > 0) mode--;
				else mode = 2;
				
			}
			
			// if UP button pressed (single press)
			// increment the current mode by one
			if(~PIND & 8)
			{
				while(~PIND & 8);
				switch(mode)
				{
					case (0):
						if(gSec < 59) gSec++;
						else gSec = 0;
						break;
					case (1):
						if(gMin < 59) gMin++;
						else gMin = 0;
						break;
					case (2):
						if(gHr < 23) gHr++;
						else gHr = 0;
						break;
				}
				
			}
			
			// if DOWN button pressed (single press)
			// decrement the current mode by one
			if(~PIND & 16)
			{
				while (~PIND & 16);
				switch(mode)
				{
					case (0):
						if(gSec > 0) gSec--;
						else gSec = 59;
						break;
					case (1):
						if(gMin > 0) gMin--;
						else gMin = 59;
						break;
					case (2):
						if(gHr > 0) gHr--;
						else gHr = 23;
						break;
				}
			}
			// flash current mode
			switch(mode)
			{
				// 200 * wait = delay 500 milliseconds 
				case (0):
					PORTC = ~1;
					PORTB = gEncoder[gSec%10];
					_delay_ms(menu_wait); 
					
					PORTC = ~2;
					PORTB = gEncoder[gSec/10];
					_delay_ms(menu_wait);
					break;
				case (1):
					PORTC = ~4;
					PORTB = gEncoder[gMin%10];
					_delay_ms(menu_wait);
					
					PORTC = ~8;
					PORTB = gEncoder[gMin/10];
					_delay_ms(menu_wait);
					break;
				case (2):
					PORTC = ~16;
					PORTB = gEncoder[gHr%10];
					_delay_ms(menu_wait);
					
					PORTC = ~32;
					PORTB = gEncoder[gHr/10];
					_delay_ms(menu_wait);
					break;
			}
		
		}
    }
}

