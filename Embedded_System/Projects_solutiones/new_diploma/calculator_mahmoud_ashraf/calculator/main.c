/*
 * calculator.c
 *
 * Created: 7/31/2018 5:26:44 PM
 * Author : Mahmoud Ashtaf
 */ 
#include "calculator.h"
 extern mode ;
/*============================================================================*/
/*=====================================Main Code==============================*/

int main(void)
{
	Keypad_init();
	LCD_lcd_init();
   
    while (1) 
    {
		switch(mode)
		{
			
		case '0':
		intro_interface();
		get_mode();
		LCD_clear_screen();
		break;
		case '1':
		Arth_mode();
		break;
		case '2':
		logic_mode();
		}

    }
}
