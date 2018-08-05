#include "GPIO/GPIO.h"
#include "LCD/lcd.h"
#include "Keypad/keypad.h"
#include "Stack_Calculator/StackCalculator.h"
#include <string.h>

#define KEYPAD_NO_BUTTON 'A'
#define KEYPAD_CLEAR_BUTTON '?'
#define KEYPAD_CALCULATE_BUTTON '='
#define MAX_EQUATION_LENGTH 32

int main(void)
{
	char keypad_pressed_key;
	char equation[MAX_EQUATION_LENGTH + 1];
	
	LCD_lcd_init();
	LCD_Send_A_Command(LCD_FUNCTION_8BIT_2LINES);
	Keypad_init();
    while(1)
    {
		keypad_pressed_key = Keypad_getkey();
		if(keypad_pressed_key == KEYPAD_CLEAR_BUTTON){
			LCD_clear_screen();
			equation[0] = '\0';
		}else if(keypad_pressed_key != KEYPAD_NO_BUTTON){
			if(keypad_pressed_key == KEYPAD_CALCULATE_BUTTON){
				LCD_clear_screen();
				LCD_display_number(evaluateEquation(equation));
			}else{
				if(strlen(equation) == MAX_EQUATION_LENGTH / 2 + 1){
					LCD_Send_A_Command(LCD_BEGIN_AT_SECOND_RAW);
					LCD_Send_A_Character(keypad_pressed_key);
				}else{
					LCD_Send_A_Character(keypad_pressed_key);
				}
				
				if(strlen(equation) < MAX_EQUATION_LENGTH){
					equation[strlen(equation) + 1] = '\0';
					equation[strlen(equation)] = keypad_pressed_key;
				}	
			}
				
		}
    }
}