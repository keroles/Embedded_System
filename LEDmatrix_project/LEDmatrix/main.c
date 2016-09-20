/*
 * LEDmatrix.c
 *
 * Created: 9/20/2016 8:06:05 PM
 * Author : moh
 */ 

#include <avr/io.h>
#define F_CPU 1000000

enum Frame_select{
	Frame0;
	Frame1;
	};
/*--------------------------------------------------------------------------------------------------
                                     Character generator

             This table defines the  characters in a dot format.
--------------------------------------------------------------------------------------------------*/
  static int CHARACTERS[][8]=
  {
    {},   // sp
	{},   //1
    {},   // 2
    {},   // 3
    {},   // 4
    {},   // 5
    {},   // 6
    {},   // 7
    {},   // 8
    {},   // 9
    {},   // :
    {},   // ;
    {},   // <
    {},   // =
    {},   // >
    {},   // ?
    {},   // @
    {},   // A
    {},   // B
    {},   // C
    {},   // D
    {},   // E
    {},   // F
    {},   // G
    {},   // H
    {},   // I
    {},   // J
    {},   // K
    {},   // L
    {},   // M
    {},   // N
    {},   // O
    {},   // P
    {},   // Q
    {},   // R
    {},   // S
    {},   // T
    {},   // U
    {},   // V
    {},   // W
    {},   // X
    {},   // Y
    {},   // Z
    {},   // [
    {},   // ]
    {},   // ^
    {},   // _
    {},    // '   
    {},   // a
    {},   // b
    {},   // c
    {},   // d
    {},   // e
    {},   // f
    {},   // g
    {},   // h
    {},   // i
    {},   // j
    {},   // k
    {},   // l
    {},   // m
    {},   // n
    {},   // o
    {},   // p
    {},   // q
    {},   // r
    {},   // s
    {}   // t
    {},   // u
    {},   // v
    {},   // w
    {},   // x
    {},   // y
    {}    // z
};

/*--------------------------------------------------------------------------------------------------
         								PORTA,B,C,D are set as output
--------------------------------------------------------------------------------------------------*/
DDRA = 0xFF;
DDRB = 0xFF;
DDRC = 0xFF;
DDRD = 0xFF;	
/*--------------------------------------------------------------------------------------------------
         								Delay Function 
--------------------------------------------------------------------------------------------------*/
void  delay_us (unsigned long time)
{
	while(time>0){
		volatile int i = 13333;
		while (i>0){
			i--;
		}
		time --;
	}
}

/*--------------------------------------------------------------------------------------------------
         								display Function 
--------------------------------------------------------------------------------------------------*/
void DisplayChar_frame0 (char *NAME)	
{ 
	char PORT[8] = {1,2,4,8,16,32,64,128};//pin values of PORT
	unsigned char l =0;

	for (int m=0;m<sizeof *NAME;m++)
	{
		l = *NAME[m];
		for (int n=0;n<200;n++)//execute 200 times for the eye to catch
		{
			for (int j=0;j<4;j++)
			{
				PORTB = PORT[j];// ROW
				PORTD = ~CHARACTERS[l][j];//show half of character (COLUMN)
				delay_us(500);
				    
			}
			PORTB=0x00;//clear screen after show
			for (int k=0;k<4;k++)
			{
				PORTC = PORT[k];// ROW
				    
				PORTD = ~CHARACTERS[l][k+4];//show other half of character(COLUMN)
				delay_us(500);
				    
			}
			PORTC=0x00;//clear screen after show.
			    
		}
	}
}

void DisplayChar_frame1 (char *NAME)
{
	char PORT[8] = {1,2,4,8,16,32,64,128};//pin values of PORT
	unsigned char l =0;

	for (int m=0;m<sizeof *NAME;m++)
	{
		l = *NAME[m];
		for (int n=0;n<200;n++)//execute 200 times for the eye to catch
		{
			for (int j=0;j<4;j++)
			{
				PORTB = PORT[j];// ROW
				PORTA = ~CHARACTERS[l][j];//show half of character (COLUMN)
				delay_us(500);
				
			}
			PORTB=0x00;//clear screen after show
			for (int k=0;k<4;k++)
			{
				PORTC = PORT[k];// ROW
				
				PORTA = ~CHARACTERS[l][k+4];//show other half of character(COLUMN)
				delay_us(500);
				
			}
			PORTC=0x00;//clear screen after show.
			
		}
	}
}
			
int main(void)
{
	
/*--------------------------------------------------------------------------------------------------
         								input character 
--------------------------------------------------------------------------------------------------*/

    char NAME[]={};//character values
    int Frame_selection=0;
	
    while(1)
    {
		if (Frame_selection== Frame0)
		 {
			DisplayChar_frame0 (char NAME);	 
		 }
		 else
		 {
			 DisplayChar_frame1 (char NAME);		 
		 }
		
	    
	    
	    delay_us(220*1000);
	    delay_us(220*1000);
	    delay_us(220*1000);
	    delay_us(220*1000);
	    delay_us(220*1000);
	    
    }
    }

