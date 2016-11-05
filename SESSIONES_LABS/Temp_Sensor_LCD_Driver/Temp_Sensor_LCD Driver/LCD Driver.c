/*
 * LCD_Driver.c
 *
 * Created: 10/28/2016 11:58:14 PM
 *  Author: Islam Muhammed
 */ 


#include "LCD.h"

void LCD_SendCommand(unsigned char command)
{	CLEAR_BIT(MrLCD_Control_Port,RS);//clear RS to Select Instruction mode	
	CLEAR_BIT(MrLCD_Control_Port,RW); //clear RW to Write command tom lcd
	_delay_us(1000); // delay for processing
	SET_BIT(MrLCD_Control_Port,EN);//Enable LCD
	MrLCD_DATA_Port=command;
	_delay_us(1000);
	CLEAR_BIT(MrLCD_Control_Port,EN);//Disable LCD
	_delay_us(1000);
	
	
}
void LCD_SendChar(unsigned char data)
{
	SET_BIT(MrLCD_Control_Port,RS); //Set RS to Select Data mode
	CLEAR_BIT(MrLCD_Control_Port,RW); //clear RW to Write Data to LCD
	_delay_us(1000);
	SET_BIT(MrLCD_Control_Port,EN);// Enable LCD
	MrLCD_DATA_Port=data;
	_delay_us(1000);
	CLEAR_BIT(MrLCD_Control_Port,EN);// Disable LCD
	_delay_us(1000);
	
	
	}
void LCD_DisplayString(char *Str)
{
	while(*Str !='\0')
	{
		LCD_SendChar(*Str);//<<<
		Str++;
	}
	
}
void LCD_DisplayString_ATXY(unsigned char row,unsigned char col,char *str)
{	unsigned char Address; //to get the address to display at
	if(row==0) Address=col;
	else Address=col+0x40;
	LCD_SendCommand(Address | 0x80);//<<<
	LCD_DisplayString(str);

	
}
void LCD_init(void)
{
	MrLCD_DATA_Port_DIR=0xff;
	MrLCD_Control_Port_DIR |=((1<<RS) | (1<<RW) | (1<<EN));
	LCD_SendCommand(0x38); // use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode
	LCD_SendCommand(0x0c); // cursor off
	LCD_SendCommand(0x01); // clear LCD at the beginning
	
}
void LCD_GoTo_XY(unsigned char row,unsigned char col)
{
	unsigned char Address; /*  calculate the required address */
	if(row==0)	Address=col;
	else	Address=col+0x40;	//first location in the second row is 0x40
	
	LCD_SendCommand(Address | 0x80 ); // coursor position on display	0x80+add* "
	/* to write to a specific address in the LCD 
	 we need to apply the corresponding command (0x80)0b10000000+Address */
	
}

void LCD_ClearScreen(void)
{
	LCD_SendCommand(0x01); //Clear Display (also clear DDRAM content)	0x01
}
void Int_TO_String(int data)
{
	unsigned char buff[16];
	itoa(data,buff,10);
	LCD_DisplayString(buff);
}

void check_LCD_isbusy(void)
{
	CLEAR_BIT(MrLCD_DATA_Port_DIR,7);
	SET_BIT(MrLCD_Control_Port,RW);
	while(MrLCD_DATA_Port>=0x80);

}
