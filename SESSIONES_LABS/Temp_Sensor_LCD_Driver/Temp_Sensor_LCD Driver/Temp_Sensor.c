/*
 * Temp_Sensor.c
 *
 * Created: 24/04/2014 02:55:48 م
 *  Author: Mohamed Tarek
 */ 


#include "LCD.h"

int main(void)
{
	unsigned long temp;
	LCD_init();
	ADC_Init();
	LCD_ClearScreen();
	LCD_DisplayString("Temp= ");
	LCD_GoTo_XY(0,12);
	LCD_SendChar('C');
	while(1)
	{
		LCD_GoTo_XY(0,9);
		temp=ADC_Read(0);
		temp = (temp*150*5)/(1023*1.5); //calculate the temp 
		Int_TO_String(temp);//display the temp on LCD Screen
		
		
	}
	
	
}