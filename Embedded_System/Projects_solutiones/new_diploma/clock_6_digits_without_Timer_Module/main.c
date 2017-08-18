/*
 * main.c
 *
 *  Created on: August 9, 2017
 *      Author: Amaero01
 */
#define SECONDS_PORT			PORTA
#define SS_ENABLE_PORT				PORTB
#define MINUTS_PORT				PORTC
#define HOURS_PORT				PORTD
#define PORT_DIRECTION_OUTPUT	0xFF
#define COUNTS_OF_SECOND		10
#define INITIAL_STATE			(char)0
#include <avr/io.h>
#include <util/delay.h>
unsigned char ones_of_seconds = INITIAL_STATE, tens_of_seconds = INITIAL_STATE,
	 ones_of_minuts = INITIAL_STATE, tens_of_hours = INITIAL_STATE,
	 ones_of_hours = INITIAL_STATE, tens_of_minuts = INITIAL_STATE,
	 seconds_counter = INITIAL_STATE;
unsigned char DISPLAY [10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x18};
int main()
{
	DDRA = PORT_DIRECTION_OUTPUT;
	DDRB = PORT_DIRECTION_OUTPUT;
	DDRC = PORT_DIRECTION_OUTPUT;
	DDRD = PORT_DIRECTION_OUTPUT;
	SS_ENABLE_PORT = PORT_DIRECTION_OUTPUT;
	SECONDS_PORT = DISPLAY [INITIAL_STATE];
	MINUTS_PORT = DISPLAY [INITIAL_STATE];
	HOURS_PORT = DISPLAY [INITIAL_STATE];
	for(;;)
	{
		for(seconds_counter = INITIAL_STATE; seconds_counter < COUNTS_OF_SECOND; seconds_counter++)
		{
			SS_ENABLE_PORT |= (1<<0);
			SS_ENABLE_PORT &= ~(1<<1);
			SECONDS_PORT = DISPLAY[ones_of_seconds];
			SS_ENABLE_PORT |= (1<<2);
			SS_ENABLE_PORT &= ~(1<<3);
			MINUTS_PORT = DISPLAY[ones_of_minuts];
			SS_ENABLE_PORT |= (1<<4);
			SS_ENABLE_PORT &= ~(1<<5);
			HOURS_PORT = DISPLAY[ones_of_hours];
			_delay_ms(50);
			SS_ENABLE_PORT |= (1<<1);
			SS_ENABLE_PORT &= ~(1<<0);
			SECONDS_PORT = DISPLAY[tens_of_seconds];
			SS_ENABLE_PORT |= (1<<3);
			SS_ENABLE_PORT &= ~(1<<2);
			MINUTS_PORT = DISPLAY[tens_of_minuts];
			SS_ENABLE_PORT |= (1<<5);
			SS_ENABLE_PORT &= ~(1<<4);
			HOURS_PORT = DISPLAY[tens_of_hours];
			_delay_ms(50);
		}
		ones_of_seconds++;
		if(ones_of_seconds == 9)
		{
			ones_of_seconds = INITIAL_STATE;
			tens_of_seconds++;
			if(((ones_of_seconds+(tens_of_seconds*10)) == 60))
			{
				ones_of_seconds = INITIAL_STATE;
				tens_of_seconds = INITIAL_STATE;
				ones_of_minuts++;
				if(ones_of_minuts == 9)
				{
					ones_of_minuts = INITIAL_STATE;
					tens_of_minuts++;
					if(ones_of_minuts+(10*tens_of_minuts) == 60)
					{
						ones_of_minuts = INITIAL_STATE;
						tens_of_minuts = INITIAL_STATE;
						ones_of_seconds = INITIAL_STATE;
						tens_of_seconds = INITIAL_STATE;
						ones_of_hours++;
						if(ones_of_hours == 9)
						{
							ones_of_hours = INITIAL_STATE;
							tens_of_hours++;
							if(ones_of_hours+(10*tens_of_hours) == 24)
							{
								ones_of_seconds = INITIAL_STATE;
								tens_of_seconds = INITIAL_STATE;
								ones_of_minuts = INITIAL_STATE;
								tens_of_minuts = INITIAL_STATE;
								ones_of_hours = INITIAL_STATE;
								tens_of_hours = INITIAL_STATE;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

