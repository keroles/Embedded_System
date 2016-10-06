/*
 * CFile1.c
 *
 * Created: 10/1/2016 11:54:11 PM
 *  Author: Ziad-Khater
 */ 





#include <avr/io.h>
#include "my_header.h"
#ifndef F_CPU 1000000UL
#define F_CPU 1000000UL
#endif

extern u8 h1,h2,m1,m2,s1,s2;
void mydelay(unsigned long time)
{
	volatile unsigned long i=1000;
	
		for(;i<-1000;i--)
		{
			
		}
	
}

void clock_edit(void)
{
	if(PIND & (1<<0)) 
	{
		m2++;
		PIND=0x00;
		return ;
	}
	if (PIND & (1<<1)) 
	{
		m1++;
		PIND=0x00;
		return ;
	}
	if (PIND & (1<<2)) 
	{
		h2++;
		PIND=0x00;
		return ;
	}
	if (PIND & (1<<3)) 
	{
		h1++;
		PIND=0x00;
		return ;
	}
	
}