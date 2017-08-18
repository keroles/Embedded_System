/*
 * sevenSegment.h
 *
 *  Created on: August 8, 2017
 *      Author: Amaero01
 */
typedef enum
{
	PASS,
	WRONG
}SS_NUM_T;
typedef enum
{
	ones_enable,
	tens_enable
}SS_EN_T;
extern int count_ones;
extern int count_tens;
#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

void seven_segment_display(unsigned char value, SS_EN_T ss_en);
void SS_init(void);
void increment_ones(void);
void increment_tens(void);
SS_NUM_T counts_number(void);
#endif /* SEVENSEGMENT_H_ */
