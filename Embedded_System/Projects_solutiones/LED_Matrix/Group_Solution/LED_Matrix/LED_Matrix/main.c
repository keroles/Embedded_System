

#include <avr/io.h>
#define F_CPU 1000000

/*--------------------------------------------------------------------------------------------------
                                     Character generator

             This table defines the  characters in a dot format.
--------------------------------------------------------------------------------------------------*/
char gCharacter[][8]=
  {
    {},   // 0
	{},   // 1
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
    {0b00111100,0b01111110,0b11000011,0b11000011,0b11111111,0b11111111,0b11000011,0b11000011},   // A
    {0xFC,0xC3,0xC3,0xFC,0xC3,0xC3,0xC3,0xFC},   // B
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
    {},   // '   
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
    {},   // t
    {},   // u
    {},   // v
    {},   // w
    {},   // x
    {},   // y
    {}    // z
};

// Functions' Prototypes
void delay_us (unsigned long time);
void Display_Frame0(char ch);
void Display_Frame1(char ch);

int main(void){
	
    char ch1 = 'A';
	char ch2 = 'B';
    //int Frame_selection=0;
	//port initialization
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	
    while(1){
		Display_Frame0(ch1);
		Display_Frame1(ch2);
    }
}

// Functions' Definition 

void delay_us (unsigned long time){
	while(time>0){
		volatile int i = 13333;
		while (i>0){
			i--;
		}
		time --;
	}
}

void Display_Frame0(char ch){
	
	static int Row = 0; //Frame Column
	int index = ch - 48; //index to choose the character from global array gCharacter
	char Col = gCharacter[index][Row]; //Frame Row
	PORTA = 1<<Row;
	PORTB = ~Col;
	if (Row == 7) Row=0;
	else Row++;
}


void Display_Frame1(char ch){
	
	static int Row = 0; //Frame Column
	int index = ch - 48; //index to choose the character from global array gCharacter
	char Col = gCharacter[index][Row]; //Frame Row
	PORTC = 1<<Row;
	PORTD = ~Col;
	if (Row == 7) Row=0;
	else Row++;
}