/*
 * sevenSegment.c
 *
 *  Created on: August 8, 2017
 *      Author: Amaero01
 */
#include <avr/io.h>
#include "port.h"
#include "sevenSegment.h"

int count_ones, count_tens;
char DISPLAY [10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x18};
void SS_init(void)
{
	DDRD |= ((1<<0) | (1<<1));
	PORTD |= ((1<<0) | (1<<1));
	DDRC = 0xFF;
	PORTC = DISPLAY[0];
	count_ones = 0;
	count_tens = 0;
}
void seven_segment_display(unsigned char value, SS_EN_T ss_en)
{
	switch(ss_en)
	{
	case ones_enable:
		SET_BIT(PORTD, 1);
		CLEAR_BIT(PORTD, 0);
		PORTC = DISPLAY[value];
		break;
	case tens_enable:
		SET_BIT(PORTD, 0);
		CLEAR_BIT(PORTD, 1);
		PORTC = DISPLAY[value];
		break;
	}
}
void increment_ones(void)
{
	count_ones++;
	if(count_ones > 9)
		count_ones = 0;
}
void increment_tens(void)
{
	count_tens++;
	if(count_tens > 9)
		count_tens = 0;
}
SS_NUM_T counts_number(void)
{
	if((count_ones+(10*count_tens)) == 45)
		return PASS;
	else
		return WRONG;
}
