/*
 * LCD_LED.c
 *
 * Created: 9/18/2016 3:05:14 PM
 *  Author: Mohamed Abo Arab
 */ 



#include "LCD_Led.h"
#define F_CPU 1000000UL //1MHZ
int main(void)
{
	myDDRA=0XFF;
	myDDRB=0xff;
	myDDRC=0xff;
	myDDRD=0xff;
	
    while(1)
    {
		
		Draw_char(0,'A');
		Draw_char(1,'B');
		Draw_char(0,'C');
		Draw_char(1,'D');
		Draw_char(0,'E');
		Draw_char(3,'A');
		
		}
		
    }
	
	