/*
 * ADC.c
 *
 * Created: 11/2/2016 9:31:58 PM
 *  Author: loma
 */ 
#include "ADC.h"

void ADC_Init(void)
{
	ADMUX=0;
	/* Bits Description:
	 * REFS1:0=0,0 to choose to connect external reference voltage by input this voltage through AREF pin
	 * ADLAR = 0 right adjusted 
	 */
	/*ADCSRA register
	ADEN(Bit 7)=1 to enable ADC, 
	ADPS1(bit1),ADSP0(bit 0) ==1,1 to prescale the input frequcene /8>>ADC must operate in range 50-200Khz to get the maximun accuracy  
	we used freq 1M so 1M/8=125kHz*/
	ADCSRA=(1<<7)| (1<<1) | (1<<0);
	
}
unsigned short ADC_Read(unsigned char channel_num)

{	channel_num &=0x07;//must be from 0>>7 to select one of these pin ADC0,1,2 to provide negitaive value 
	ADMUX &=0xE0; //to clear from MUX4 to MUX0 before set the requried bit 
	ADMUX=ADMUX|channel_num; //choose the correct channel by setting the channel number in MUX4:0 bits
	ADCSRA |= (1<<6); //to start the conversion by set Bit (ADSC)
	while(!(ADCSRA &(1<<4)));//wait for the conversion to complete and ADIF(Bit 4) become 1
	ADCSRA |=(1<<4); //clear ADIF by write'1' to it :)
	return ADC; //combine ADCL +ADCH
}
