/*
 * Timer0.h
 *
 *  Created on: Sep 14, 2017
 *      Author: Keroles Shenouda
 */

#ifndef TIMER0_TIMER0_H_
#define TIMER0_TIMER0_H_

#include "../Data_Types.h"
/////User Configuration////////////////////

enum WAVE_FORM_GEN   //Timer/Counter0 Output Compare Match Interrupt Enable
{
	CTC,
	NORMAL
} ;

enum TOVFIE0
{
	TOIE0_enable,
	TOIE0_disable
} ;

enum OCMIE0   //Timer/Counter0 Output Compare Match Interrupt Enable
{
	OCIE0_enable ,
	OCIE0_disable
} ;



enum TMR0_PRESCALAR
{
	NO_CLK_SRC = 0, //Timer Disable
	NO_PRESCALING = 1,
	PRESCALING_CLK8 = 2,
	PRESCALING_CLK64 = 3,
	PRESCALING_CLK256 = 4,
	PRESCALING_CLK1024 = 5,
	EXT_CLK_FALLING=6,
	EXT_CLK_RISING = 7
} ;


struct STimer0_Settings
{
	enum TOVFIE0 Timer0_OVFI ;
	enum OCMIE0 Timer0_OCIE;
	enum WAVE_FORM_GEN Timer0_Mode ;
	enum TMR0_PRESCALAR Timer0_PRESCALAR;
};
//////////////////////////////////////////

/////////////////////Timer0 Interface


extern void TMR0_Init(struct STimer0_Settings Configuration);
extern void TMR0_ReadCounterValue(u8* u8NumOfTicks);
extern void TMR0_Set_Compare_Value(u8 u8Val);

extern void TMR0_Set_OV_Number(u8 u8Val);
extern void TMR0_Get_TOV_Number(u8 *u8Val);

////SW Counter
extern void TMR0_Get_Ticks_of_SWcounter (u32 *u8Val);

//ISR
extern void callback_TMR0_Overflow_Interrupt (void(*Ptr_to_OVI_Function)(void));
extern void callback_OCR0_Compare_Match_Interrupt(void(*Ptr_to_OCM_Function)(void));








//////////////////////////////////////////

//////////////////////////////Private HW registers

/********************************EXT INT ISR**********************************/
#define ISR(vector, ...) \
	void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
	void vector(void)

/**************************TMR0 Registers*************************************/
#define TCCR0	*((volatile u8*) (0x53))
#define TCNT0	*((volatile u8*) (0x52))
#define TIMSK	*((volatile u8*) (0x59))
#define OCR0	*((volatile u8*) (0x5C))

/**************************TCCR0 Registers*************************************/
#define FOC0 	7
#define WGM00	6
#define COM01 	5
#define COM00	4
#define WGM01	3
#define CS02 	2
#define CS01 	1
#define CS00 	0
/**************************Enable TMR0 Pin*************************************/
#define TOIE0	0
#define OCIE0	1


/////////////////////////////////////////////////



#endif /* TIMER0_TIMER0_H_ */
