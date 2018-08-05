/*
 * lcd.c
 *
 *  Created on: Jan 19, 2017
 *      Author: Keroles shenouda
 */

#include "lcd.h"

void LCD_lcd_init(void)
{

	_delay_ms(20);
	DataDir_LCD_control |= (1<<EN_switch | 1<<ReadWrite | 1<<RS_switch) ;
	LCD_control &= ~(1<<EN_switch | 1<<ReadWrite | 1<<RS_switch) ;

	DataDir_LCD_port = 0xff ;
	_delay_ms(15);

	LCD_clear_screen ();

#ifdef EIGHT_BIT_MODE
	LCD_Send_A_Command(LCD_FUNCTION_8BIT_2LINES);

#endif
#ifdef FOUR_BIT_MODE
	LCD_Send_A_Command(0x02);

	LCD_Send_A_Command(LCD_FUNCTION_4BIT_2LINES);

#endif

	LCD_Send_A_Command(LCD_ENTRY_MODE);
	LCD_Send_A_Command(LCD_BEGIN_AT_FIRST_RAW);
	LCD_Send_A_Command(LCD_DISP_ON_CURSOR_BLINK);

}

void LCD_clear_screen ()
{
	LCD_Send_A_Command(LCD_CLEAR_SCREEN); // clear the screen



}

void LCD_GotoXY(unsigned char line, unsigned char position )
{

	if(line==0)
	{
		if (position < 16 && position >=0)
			LCD_Send_A_Command(0x80+position);
	}
	else if (line==1)
	{
		if (position < 16 && position >=0)
			LCD_Send_A_Command(0xc0 + position);
	}
}





void LCD_check_lcd_isbusy()
{
	DataDir_LCD_port &= ~(0xff<<DATA_shift) ;
	LCD_control |= (1<<ReadWrite); // read
	LCD_control &= ~ (1<<RS_switch);

	//	while (LCD_port >= 0x80)
	//	{
	LCD_lcd_kick ();
	//	}

	//	_delay_ms (500) ;
	DataDir_LCD_port = 0xFF; //0xFF means 0b11111111
	LCD_control &= ~ (1<<ReadWrite); //write
}




void LCD_lcd_kick ()
{
	LCD_control &= ~ (1<<EN_switch);
	asm volatile ("nop");
	asm volatile ("nop");
	_delay_ms (50) ;
	LCD_control |= 1<<EN_switch;
}


void LCD_Send_A_Command(unsigned char command)
{
#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();

	LCD_port = command  ;
	LCD_control &= ~ ((1<<ReadWrite)|(1<<RS_switch));
	LCD_lcd_kick ();
	//LCD_port = 0;
#endif
#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_port = (LCD_port & 0x0F) | (command & 0xF0);
	//LCD_VoidLcd_waitIfBusy();
	//SET_DATA_DIRECTION_REGISTER(LCD_DATA_DIRECTION_PORT, PORT_OUTPUT_DIRECTION);
	//LCD_SET_REGISTER_SELECT(LCD_REGISTER_SELECT_DISABLE);
	//	LCD_SET_READ_WRITE(WRITE_TO_LCD);
	LCD_control &= ~ ((1<<ReadWrite)|(1<<RS_switch));
	//LCD_VoidLcd_referish();
	LCD_lcd_kick ();
	LCD_port = (LCD_port & 0x0F) | (command << 4);
	//LCD_VoidLcd_waitIfBusy();
	LCD_control &= ~ ((1<<ReadWrite)|(1<<RS_switch));
	//LCD_VoidLcd_referish();
	LCD_lcd_kick ();
#endif

}

void LCD_Send_A_Command_4mode(unsigned char command)
{
	LCD_check_lcd_isbusy();
	LCD_port&= 0x0F;
	LCD_port |= (command&0xF0);
	LCD_control &= ~ ((1<<ReadWrite)|(1<<RS_switch));
	LCD_lcd_kick ();
	LCD_control &= 0x0F;  // Make Data Nibble as 0000
	LCD_control |= ((command<<4)&0xF0);
	LCD_lcd_kick ();
	//LCD_port = 0;
}




void LCD_Send_A_Character(unsigned char character)
{

#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();

	LCD_control |= 1<<RS_switch; //turn RS ON for Data mode.
	LCD_port = ( ( (character  ) << DATA_shift)   )  ;
	LCD_control |= 1<<RS_switch; //turn RS ON for Data mode.
	LCD_control &= ~ (1<<ReadWrite);//turn RW off so you can write.


	LCD_lcd_kick ();
	//LCD_port = 0;
#endif

#ifdef FOUR_BIT_MODE
	LCD_port = (LCD_port & 0x0F) | (character & 0xF0);
	LCD_control |= 1<<RS_switch; //turn RS ON for Data mode.
	LCD_control &= ~ (1<<ReadWrite);//turn RW off so you can write.
	LCD_lcd_kick ();
	LCD_port = (LCD_port & 0x0F) | (character << 4);
	LCD_control |= 1<<RS_switch; //turn RS ON for Data mode.
	LCD_control &= ~ (1<<ReadWrite);//turn RW off so you can write.
	LCD_lcd_kick ();

#endif


}

void LCD_Send_A_String(char *StringOfCharacters)
{


	int count=0 ;//to count how much char on the line (it should be 16 char only)
	while(*StringOfCharacters > 0)
	{
		count++;
		LCD_Send_A_Character(*StringOfCharacters++);
		if (count == 16  ) // go to the second line
		{
			LCD_GotoXY(1,0); //line 1 position zero
		}
		else if (count == 32 || count==33) // clear screen and show again
		{
			LCD_clear_screen();
			LCD_GotoXY(0,0); //line 0 position zero
			count = 0 ;
		}
	}
}


void LCD_display_number (int Number )
{

	char  str[7];

	sprintf(str,"%d",Number);	// Adjust the formatting to your liking.

	LCD_Send_A_String (str) ;

}

void LCD_display_real_number (double  Number )
{

	char  str[16];


	char *tmpSign = (Number < 0) ? "-" : "";
	float tmpVal = (Number < 0) ? -Number : Number;

	int tmpInt1 = tmpVal;                  // Get the integer (678).
	float tmpFrac = tmpVal - tmpInt1;      // Get fraction (0.0123).
	int tmpInt2 = tmpFrac * 10000;  // Turn into integer (123).

	// Print as parts, note that you need 0-padding for fractional bit.

	sprintf (str, "%s%d.%04d", tmpSign, tmpInt1, tmpInt2);



	LCD_Send_A_String (str) ;

}
