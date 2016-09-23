


#ifndef ATMEGA32_LIB_H
#define ATMEGA32_LIB_H

typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned long U32;

/*
							   *************
******************************** GPIO, DIO *****************************
							   *************
*/
/*
** The DDxn bit in the DDRx Register selects the direction of this pin. If DDxn is written logic one, Pxn is configured as an output pin. 
** If DDxn is written logic zero, Pxn is configured as an input pin. 
** If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is activated.
** To switch the pull-up resistor off, PORTxn has to be written logic zero or the pin has to be configured as an output pin.
*/

#define INPUT				0x00
#define OUTPUT				0x01
#define TRUE_DIR(dir)		(dir==INPUT||dir==OUTPUT)

/* Port A */
#define PINA	*(volatile U8 *const)0x39
#define DDRA	*(volatile U8 *const)0x3A
#define PORTA	*(volatile U8 *const)0x3B
/* Port B */
#define PINB	*(volatile U8 *const)0x36
#define DDRB	*(volatile U8 *const)0x37
#define PORTB	*(volatile U8 *const)0x38
/* Port C */
#define PINC	*(volatile U8 *const)0x33
#define DDRC	*(volatile U8 *const)0x34
#define PORTC	*(volatile U8 *const)0x35
/* Port D */
#define PIND	*(volatile U8 *const)0x30
#define DDRD	*(volatile U8 *const)0x31
#define PORTD	*(volatile U8 *const)0x32

/* 
** second way for simplicity in GPIO Driver 
*/
#define A		0x39
#define B		0x36
#define C		0x33
#define D		0x30

#define TRUE_PORT(port_base)	(port_base==0x39||port_base==0x36||port_base==0x33||port_base==0x30)
#define TRUE_PIN(pin)			(pin>=0&&pin<=7)

#define DDR(port_base)	*((volatile U8 *const)(port_base+0x01))
#define PORT(port_base)	*((volatile U8 *const)(port_base+0x02))
#define PIN(port_base)	*((volatile U8 *const)(port_base+0x00))


/*
** About PIN_INT0 & PIN_INT1 & PIN_INT2: if enabled it will be serve interrupt as input even if it was setted output in GPIO.
*/
/********** 7 **********/
#define PIN_OC2		7
#define PIN_SCK		7
#define PIN_ADC7	7
#define PIN_TOSC2	7
/********** 6 **********/
#define PIN_MISO	6
#define PIN_ADC6	6
#define PIN_TOSC1	6
#define PIN_ICP1	6
/********** 5 **********/
#define PIN_MOSI	5
#define PIN_TDI		5
#define PIN_ADC5	5
#define PIN_OC1A	5
/********** 4 **********/
#define PIN_ADC4	4
#define PIN_TDO		4
#define PIN_OC1B	4
#define PIN_SS		4
/********** 3 **********/
#define PIN_INT1	3
#define PIN_TMS		3
#define PIN_AIN1	3
#define PIN_OC0		3
#define PIN_ADC3	3
/********** 2 **********/
#define PIN_INT0	2
#define PIN_TCK		2
#define PIN_AIN0	2	
#define PIN_T2		2
#define PIN_ADC2	2
/********** 1 **********/
#define PIN_TXD		1
#define PIN_SDA		1
#define PIN_T1		1
#define PIN_ADC1	1
/********** 0 **********/
#define PIN_RXD		0
#define PIN_SCL		0
#define PIN_XCK		0
#define PIN_T0		0
#define PIN_ADC0	0


#define SET_BIT(reg,pin)		reg|=(1<<pin)
#define CLR_BIT(reg,pin)		reg&=~(1<<pin)
#define READ_BIT(reg,pin)		((reg&(1<<pin))>>pin)
#define TOGGLE_BIT(reg,pin)		reg^=(1<<pin)

/*
			    *************************
***************************** CPU special registers *******************************
 			    *************************
*/
/* CPU stack pointer high */
#define SPL *(volatile U8 *const)0x5D
#define SP8	 0
#define SP9  1
#define SP10 2
#define SP11 3

/* CPU stack pointer low */
#define SPH *(volatile U8 *const)0x5E
#define SP0 0
#define SP1 1
#define SP2 2
#define SP3 3
#define SP4 4
#define SP5 5
#define SP6 6
#define SP7 7

/* 
** status register
*/
#define SREG *(volatile U8 *const)0x5F
/*
** C: Carry Flag
*/
#define C_carry 0
#define c 0
/*
** Z: Zero Flag
*/
#define Z 1
/*
** N: Negative Flag
*/
#define N 2
/*
** V: Two’s Complement Overflow Flag
*/
#define V 3
/*
** S: Sign Bit, S = N ⊕ V
*/
#define S 4
/*
** H: Half Carry Flag
*/
#define H 5
/*
** T: Bit Copy Storage
*/
#define T 6
/*
** I: Global Interrupt Enable
*/
#define I 7

#define Active_Global_INT()	SET_BIT(SREG,I)

/*
			       ***********************************
******************************** Interrupts, External Interrupts.*************************************
			       ***********************************
*/
/* 
** general interrupt control register.
** External Interrupts control in MCU Control Register"MCUCR"
*/
#define GICR *(volatile U8 *const)0x5B
/*
** iInterrupt vector change enable.
** must be written to logic one to enable change of the IVSEL bit.
** is cleared by hardware four cycles after it is written or when IVSEL is written.
** 
*/
#define IVCE 	0
/*
** interrupt vector select
** clear(zero), the Interrupt Vectors are placed at the start of the Flash memory.
** set (one), the Interrupt Vectors are moved to the beginning of the Boot Loader section of the Flash.
** The actual address of the start of the boot Flash section is determined by the BOOTSZ Fuses.
** a special write procedure must be followed to change the IVSEL bit:
** (1) Write the Interrupt Vector Change Enable (IVCE) bit to one.
** (2) Within four cycles, write the desired value to IVSEL while writing a zero to IVCE.
** Interrupts are disabled in the cycle IVCE is set, and they remain disabled until after the instruction following the write to IVSEL. 
** If IVSEL is not written, interrupts remain disabled for four cycles.
*/
#define IVSEL	1
/*
** INT2: External Interrupt Request 2 Enable
** When the INT2 bit is set (one) and the I-bit in the Status Register (SREG) is set (one), the external pin interrupt is enabled.
** Activity on the pin will cause an interrupt request even if INT2 is configured as an output
*/
#define INT2	5
/*
** INT0: External Interrupt Request 0 Enable.
** When the INT0 bit is set (one) and the I-bit in the Status Register (SREG) is set (one), the external pin interrupt is enabled.
** Activity on the pin will cause an interrupt request even if INT0 is configured as an output.
*/
#define INT0	6
/*
** INT1: External Interrupt Request 1 Enable
** When the INT1 bit is set (one) and the I-bit in the Status Register (SREG) is set (one), the external pin interrupt is enabled.
** Activity on the pin will cause an interrupt request even if INT1 is configured as an output.
*/
#define INT1	7
/**********************************
** General Interrupt Flag Register.
*/
#define GIFR *(volatile U8 *const)0x5A
/*
** INTF1: External Interrupt Flag 1
** When an event on the INT1 pin triggers an interrupt request, INTF1 becomes set (one).
** If the I-bit in SREG and the INT1 bit in GICR are set (one), the MCU will jump to the corresponding Interrupt Vector.
** The flag is cleared when the interrupt routine is executed. Alternatively, the flag can be cleared by writing a logical one to it.
*/
#define INTF1	7
/*
** INTF0: External Interrupt Flag 0
** When an event on the INT0 pin triggers an interrupt request, INTF0 becomes set (one).
** If the I-bit in SREG and the INT0 bit in GICR are set (one), the MCU will jump to the corresponding Interrupt Vector.
** The flag is cleared when the interrupt routine is executed. Alternatively, the flag can be cleared by writing a logical one to it.
*/
#define INTF0	6
/*
** INTF2: External Interrupt Flag 2
** When an event on the INT2 pin triggers an interrupt request, INTF0 becomes set (one).
** If the I-bit in SREG and the INT2 bit in GICR are set (one), the MCU will jump to the corresponding Interrupt Vector.
** The flag is cleared when the interrupt routine is executed. Alternatively, the flag can be cleared by writing a logical one to it.
** Note that when entering some sleep modes with the INT2 interrupt disabled.
*/
#define INTF2	5
/*
			       ******************************************************
******************************** MCU Power management & External Interrupts control *************************************
			       ******************************************************
*/
/*
** MCU Control Register, contains control bits for power management.
*/
#define MCUCR *(volatile U8 *const)0x55
/*
** set(one) to make the MCU enter the sleep mode when the SLEEP instruction is executed.
*/
#define SE  7
/*
** Power control.
** SM2, SM1, SM0 = { 000 to Idle Mode, 
**					 001 ADC noise Reduction Mode,
**					 010 Power-down Mode,
**                   011 Power-Save Mode,
** 					 110 Standby Mode,
**					 111 Extended Standby Mode }
*/
#define SM0 4
#define SM1 5
#define SM2 6
/***
** External Interrupts control
** Ext interrupt2 INT2 controlled from ISC2 in MCUCSR Bit6.
****
** ISC0n: Interrupt Sense Control 0 Bit 1 and Bit 0 [n = 1:0]
** ISC01, ISC00 = { 00: The low level of INT0 generates an interrupt request,
**					01: Any logical change on INT0 generates an interrupt request,
**					10: The falling edge of INT0 generates an interrupt request,
**					11: The rising edge of INT0 generates an interrupt request  }
*/
#define ISC00	0
#define ISC01	1
/*
** ISC1n: Interrupt Sense Control 1 Bit 1 and Bit 0 [n = 1:0]
** ISC11, ISC10 = { 00: The low level of INT1 generates an interrupt request,
**					01: Any logical change on INT1 generates an interrupt request,
**					10: The falling edge of INT1 generates an interrupt request,
**					11: The rising edge of INT1 generates an interrupt request }
*/
#define ISC10	2
#define ISC11	3

/*
			       *********************************************************
******************************** MCU Rset Control & Ext INT2 control & jTAG En/Disable *************************************
			       *********************************************************
*/
/*
************************************************************************
** MCU Control and status register, provides information on which reset source caused an MCU Reset.
*/
#define MCUCSR *(volatile U8 *const)0x54
/*
** PORF: Power-on Reset Flag
** This bit is set if a Power-on Reset occurs. The bit is reset only by writing a logic zero to the flag. To make
** use of the Reset Flags to identify a reset condition, the user should read and then reset the MCUCSR as
** early as possible in the program. If the register is cleared before another reset occurs, the source of the
** reset can be found by examining the Reset Flags.
*/
#define PORF	0
/*
** EXTRF: External Reset Flag
** This bit is set if an External Reset occurs. The bit is reset by a Power-on Reset, or by writing a logic zero to the flag.
*/
#define EXTRF	1
/*
** BORF: Brown-out Reset Flag
** This bit is set if a Brown-out Reset occurs. The bit is reset by a Power-on Reset, or by writing a logic zero to the flag.
*/
#define BORF	2
/*
** WDRF: Watchdog Reset Flag.
** This bit is set if a Watchdog Reset occurs. The bit is reset by a Power-on Reset, or by writing a logic zero to the flag.
*/
#define WDRF	3
/*
** JTRF: JTAG Reset Flag.
** This bit is set if a reset is being caused by a logic one in the JTAG Reset Register selected by the JTAG
** instruction AVR_RESET. This bit is reset by a Power-on Reset, or by writing a logic zero to the flag.
*/
#define JTRF	4
/*
** JTD: JTAG Interface Disable.
** When this bit is zero, the JTAG interface is enabled if the JTAGEN fuse is programmed.
** If this bit is one, the JTAG interface is disabled.
** In order to avoid unintentional disabling or enabling of the JTAG interface, a timed sequence must be followed when changing this bit:>>
** >> The application software must write this bit to the desired value twice within four cycles to change its value.
** >> If the JTAG interface is left unconnected to other JTAG circuitry, the JTD bit should be set to one. The reason for 
** this is to avoid static current at the TDO pin in the JTAG interface.
*/
#define JTD		7
/*
** CONTRO EXTERNAL INTERRUPT INT2
** ISC2: Interrupt Sense Control 2, for External Interrupt 2.
** The Asynchronous External Interrupt 2 is activated by the external pin INT2,
** if the SREG I-bit and the corresponding interrupt mask in GICR are set
** If ISC2 is written to (zero), a falling edge on INT2 activates the interrupt.
** If ISC2 is written to (one), a rising edge on INT2 activates the interrupt.
** When changing the ISC2 bit, an interrupt can occur. Therefore, it is recommended to first disable INT2 by clearing its
** Interrupt Enable bit in the GICR Register. Then, the ISC2 bit can be changed.
*/
#define ISC2	6
/*
			       ***************************************
******************************** The Oscillator Calibration Register ******************************
			       ***************************************
*/
/*
** OSCCAL: The Oscillator Calibration Register.
** Oscillator Calibration Value [n = 7:0]
** Read page 47 on latest data sheet.
*/
#define OSCCAL	*(volatile U8 *const)0x51
#define CAL0	0
#define CAL1	1
#define CAL2	2
#define CAL3	3
#define CAL4	4
#define CAL5	5
#define CAL6	6
#define CAL7	7
/*
			       ********************
******************************** On-Chip debugger ******************************
			       ********************
*/
/*
** OCDR: On-Chip debugger 
** The OCDR Register provides a communication channel from the running program in the microcontroller
** to the debugger. The CPU can transfer a byte to the debugger by writing to this location. At the same
** time, an internal flag; I/O Debug Register Dirty – IDRD – is set to indicate to the debugger that the register has been written.
*/
#define OCDR	*(volatile U8 *const)0x51

#define OCDR0	0
#define OCDR1 	1
#define OCDR2	2
#define OCDR3	3
#define OCDR4	4
#define OCDR5	5
#define OCDR6	6
#define OCDR7	7
/*
** IDRD: I/O Debug Register Dirty
** When the CPU reads the OCDR Register the 7 LSB will be from the OCDR Register, while the MSB is the IDRD bit.
** An internal flag, is set(one) to indicate to the debugger that the register has been written.
** The debugger clears(zero) the IDRD bit when it has read the information.
*/
#define IDRD	7
/*
			       *****************************************
******************************** Store Program Memory Control Register ******************************
			       *****************************************
*/
/*
** SPMCR – Store Program Memory Control Register
** 
*/
#define SPMCR	*(volatile U8 *const)0x57
/*
** SPMEN: Store Program Memory.
** This bit enables the SPM instruction for the next four clock cycles. If written to one together with eitherRWWSRE, 
** BLBSET, PGWRT or PGERS, the following SPM instruction will have a special meaning, see description in page 327.
** If only SPMEN is written, the following SPM instruction will store the value in R1:R0 in the temporary page buffer addressed by the Z-pointer.
** The LSB of the Z-pointer is ignored. The SPMEN bit will auto-clear upon completion of an SPM instruction,
** or if no SPM instruction is executed within four clock cycles. During Page Erase and Page Write, 
** the SPMEN bit remains high until the operation is completed.
** Writing any other combination than “10001”, “01001”, “00101”, “00011” or “00001” in the lower five bits will have no effect.
*/
#define SPMEN	0
/*
** PGERS: Page Erase.
** If this bit is written to one at the same time as SPMEN, the next SPM instruction within four clock cycles executes Page Erase.
** The page address is taken from the high part of the Z-pointer. The data in R1 and R0 are ignored.
** The PGERS bit will auto-clear upon completion of a Page Erase, or if no SPM instruction is executed within four clock cycles.
** The CPU is halted during the entire Page Write operation if the NRWW section is addressed.
*/
#define PGERS	1
/*
** PGWRT: Page Write
** If this bit is written to one at the same time as SPMEN, the next SPM instruction within four clock cycles executes Page Write, 
** with the data stored in the temporary buffer. The page address is taken from the high part of the Zpointer. The data in R1 and R0 are ignored.
** The PGWRT bit will auto-clear upon completion of a Page Write, or if no SPM instruction is executed within four clock cycles.
** The CPU is halted during the entire Page Write operation if the NRWW section is addressed.
*/
#define PGWRT	2
/*
** BLBSET: Boot Lock Bit Set.
** If this bit is written to one at the same time as SPMEN, the next SPM instruction within four clock cycles 
** sets Boot Lock bits, according to the data in R0. The data in R1 and the address in the Z-pointer are ignored.
** The BLBSET bit will automatically be cleared upon completion of the Lock bit set, or if no SPM 
** instruction is executed within four clock cycles.
** An LPM instruction within three cycles after BLBSET and SPMEN are set in the SPMCR Register(SPMCR.BLBSET and SPMCR.SPMEN), 
** will read either the Lock bits or the Fuse bits (depending on Z0 in the Z-pointer) into the destination register.
*/
#define BLBSET	3
/*
** RWWSRE: Read-While-Write Section Read Enable
** When programming (Page Erase or Page Write) to the RWW section, the RWW section is blocked for reading (the RWWSB will be set by hardware).
** To re-enable the RWW section, the user software must wait until the programming is completed (SPMEN will be cleared).
** Then, if the RWWSRE bit is written to one at the same time as SPMEN, the next SPM instruction within 
** four clock cycles re-enables the RWW section.
** The RWW section cannot be re-enabled while the Flash is busy with a Page Erase or a Page Write (SPMEN is set).
** If the RWWSRE bit is written while the Flash is being loaded, the Flash load operation will abort and the data loaded will be lost.
*/
#define RWWSRE	4
/*
** RWWSB: Read-While-Write Section Busy.
** When a Self-Programming (page erase or page write) operation to the RWW section is initiated, the RWWSB will be set (one) by hardware.
** When the RWWSB bit is set, the RWW section cannot be accessed.
** The RWWSB bit will be cleared if the RWWSRE bit is written to one after a Self-Programming operation is completed.
*/
#define RWWSB	6
/*
** SPMIE: SPM Interrupt Enable.
** When the SPMIE bit is written to one, and the I-bit in the Status Register is set (one), the SPM ready interrupt will be enabled.
** The SPM ready Interrupt will be executed as long as the SPMEN bit in the SPMCR Register is cleared.
*/
#define SPMIE	7
/*
			       ********************************
******************************** Special Function IO Register ******************************
			       ********************************
*/
/*
** SFIOR – Special Function IO Register
*/
#define SFIOR	*(volatile U8 *const)0x50
/*
** When this bit is written to one, the pull-ups in the I/O ports are disabled even if the DDxn and PORTxn 
** Registers are configured to enable the pull-ups ({DDxn, PORTxn} = 0b01)
*/
#define PUD		2
/*
** PSR2: Prescaler Reset Timer/Counter2
** When this bit is written to one, the Timer/Counter2 prescaler will be reset. The bit will be cleared by hardware after the operation is 
** performed. Writing a zero to this bit will have no effect. This bit will always be read as zero if Timer/Counter2 is clocked by 
** the internal CPU clock. If this bit is written when Timer/Counter2 is operating in Asynchronous mode, the bit will remain one until 
** the prescaler has been reset.
*/
#define PSR2	1
/*
** ACME: Analog Comparator Multiplexer Enable
** When this bit is written logic one and the ADC is switched off (ADEN in ADCSRA is zero), the ADC multiplexer selects the negative input to 
** the Analog Comparator. When this bit is written logic zero, AIN1 is applied to the negative input of the Analog Comparator.
*/
#define ACME	3
/*
** ADTSn: ADC Auto Trigger Source [n = 2:0]
** If ADATE in ADCSRA is written to one, the value of these bits selects which source will trigger an ADC conversion.
** If ADATE is cleared, the ADTS2:0 settings will have no effect. A conversion will be triggered by the rising edge of the 
** selected Interrupt Flag. Note that switching from a trigger source that is cleared to a trigger source that is set, 
** will generate a positive edge on the trigger signal. If ADEN in ADCSRA is set, this will start a conversion. 
** Switching to Free Running mode (ADTS[2:0]=0) will not cause a trigger event, even if the ADC Interrupt Flag is set.
** ADC Auto Trigger Source Selections:
** ADTS2, ADTS1, ADTS0 = { 0 0 0: Free Running mode
						   0 0 1: Analog Comparator
						   0 1 0: External Interrupt Request 0
						   0 1 1: Timer/Counter0 Compare Match
						   1 0 0: Timer/Counter0 Overflow
						   1 0 1: Timer/Counter1 Compare Match B
						   1 1 0: Timer/Counter1 Overflow
						   1 1 1: Timer/Counter1 Capture Event }.
*/
#define ADTS2 	7
#define ADTS1	6
#define ADTS0	5
/*
			       ************************
******************************** 8-bit Timer/Counter0 ******************************
			       ************************
*/
/*
** TCCR0 – Timer/Counter Control Register.
** 
*/
#define TCCR0	*(volatile U8 *const)0x45
/*
** FOC0: Force Output Compare
** The FOC0 bit is only active when the WGM00 bit specifies a non-PWM mode. However, for ensuring
** compatibility with future devices, this bit must be set to zero when TCCR0 is written when operating in PWM mode.
** When writing a logical one to the FOC0 bit, an immediate Compare Match is forced on the waveform generation unit.
** The OC0 output is changed according to its COM21:0 bits setting. Note that the FOC0 bit is implemented as a strobe.
** Therefore it is the value present in the COM01:0 bits that determines the effect of the forced compare.
** A FOC0 strobe will not generate any interrupt, nor will it clear the timer in CTC mode using OCR0 as TOP. 
** The FOC0 bit is always read as zero.
*/
#define FOC0	7
/*
** WGM01(CTC0), WGM00(PWM0): Waveform Generation Mode.
** These bits control the counting sequence of the counter, the source for the maximum (TOP) counter value, 
** and what type of waveform generation to be used.
** Modes of operation supported by the Timer/Counter unit are: Normal mode, Clear Timer on Compare Match (CTC) mode, 
** and two types of Pulse Width Modulation (PWM) modes.
** Waveform Generation Mode Bit Description:
** WGM01(CTC0), WGM00(PWM0) = { 0 0: Normal mode, 			>>TOP= 0xFF, Update of OCR0= Immediate, TOV0 Flag Set= MAX,
**								0 1: PWM, Phase Correct, 	>>TOP= 0xFF, Update of OCR0= TOP, 		TOV0 Flag Set= BOTTOM,
**								1 0: CTC Mode,				>>TOP= OCR0, Update of OCR0= Immediate, TOV0 Flag Set= MAX,
**								1 1: Fast PWM 				>>TOP= 0xFF, Update of OCR0= BOTTOM, 	TOV0 Flag Set= MAX, }.
** >>Each one of these modes has special 4 modes by WGM00 & COM01 to control the Output Compare Pin (OC0) behavior.
*/
#define WGM00	6
#define WGM01	3
/*
** COM0n: Compare Match Output Mode [n = 1:0]
** These bits control the Output Compare Pin (OC0) behavior. If one or both of the COM01:0 bits are set,
** the OC0 output overrides the normal port functionality of the I/O pin it is connected to. However, note that the 
** Data Direction Register (DDR) bit corresponding to the OC0 pin must be set in order to enable the output driver.
** >>When OC0 is connected to the pin, the function of the COM01:0 bits depends on the WGM01:0 bit setting.
** Compare Output Mode, Non-PWM Mode ( Normal mode & CTC Mode ):
** COM01, COM00 = { 0 0: Normal port operation, OC0 disconnected.,
**				    0 1: Toggle OC0 on Compare Match,
**				    1 0: Clear OC0 on Compare Match,
**				    1 1: Set OC0 on Compare Match }.
** Compare Output Mode, Phase Correct PWM Mode:
** COM01, COM00 = { 0 0: Normal port operation, OC0 disconnected.,
**				    0 1: Reserved
**				    1 0: Clear OC0 on Compare Match when up-counting. Set OC0 on Compare Match when downcounting.
**				    1 1: Set OC0 on Compare Match when up-counting. Clear OC0 on Compare Match when downcounting. }.
** Compare Output Mode, Fast PWM Mode:
** COM01, COM00 = { 0 0: Normal port operation, OC0 disconnected.
**				    0 1: Reserved
**				    1 0: Clear OC0 on Compare Match, set OC0 at BOTTOM, (non-inverting mode)
**				    1 1: Set OC0 on Compare Match, clear OC0 at BOTTOM, (inverting mode) }.
*/
#define COM00	4
#define COM01	5
/*
** CS0n: Clock Select [n = 2:0]
** The three Clock Select bits select the clock source to be used by the Timer/Counter.
** Clock Select Bit Description:
** CS02, CS01, CS00 = { 0 0 0: No clock source (Timer/Counter stopped),
**						0 0 1: clk I/O /1 (No prescaling),
**						0 1 0: clk I/O /8 (From prescaler),
**						0 1 1: clk I/O /64 (From prescaler),
**						1 0 0: clkI/O/256 (From prescaler),
**						1 0 1: clk I/O /1024 (From prescaler),
**						1 1 0: External clock source on T0 pin. Clock on falling edge,
**						1 1 1: External clock source on T0 pin. Clock on falling edge. }.
*/
#define CS02	2
#define CS01	1
#define CS00	0
/*
** TCNT0 – Timer/Counter Register
** The Timer/Counter Register gives direct access, both for read and write operations, to the Timer/Counter unit 8-bit counter.
** Modifying the counter (TCNT0) while the counter is running, introduces a risk of missing a Compare Match between TCNT0 and the OCR0 Register.
** Writing to the TCNT0 Register blocks (removes) the Compare Match on the following timer clock.
*/
#define TCNT0	*(volatile U8 *const)0x44
/*
** OCR0 – Output Compare Register
** The Output Compare Register contains an 8-bit value that is continuously compared with the counter value (TCNT0).
** A match can be used to generate an Output Compare interrupt, or to generate a waveform output on the OC0 pin.
*/
#define OCR0	*(volatile U8 *const)0x43
/*
** TIMSK – Timer/Counter Interrupt Mask Register.
** 
*/
#define TIMSK	*(volatile U8 *const)0x59
/*
** OCIE0: Timer/CounterTimer/Counter0 Output Compare Match Interrupt Enable.
** When the OCIE0 bit is written to one and the I-bit in the Status Register is set (one), the Timer/Counter0 Compare Match interrupt is enabled.
** The corresponding interrupt is executed if a Compare Match in Timer/Counter0 occurs
** (i.e., when the OCF0 bit is set in the Timer/Counter Interrupt Flag Register – TIFR).
*/
#define OCIE0	1
/*
** TOIE0: Timer/CounterTimer/Counter0 Overflow Interrupt Enable.
** When the TOIE0 bit is written to one and the I-bit in the Status Register is set (one), the Timer/Counter0 Overflow interrupt is enabled.
** The corresponding interrupt is executed if an overflow in Timer/Counter0 occurs 
** (i.e., when the TOV0 bit is set in the Timer/Counter Interrupt Flag Register – TIFR).
*/
#define TOIE0	0
/*
** TIFR – Timer/Counter Interrupt Flag Register
*/
#define TIFR	*(volatile U8 *const)0x58
/*
** OCF0: Output Compare Flag 0.
** The OCF0 bit is set (one) when a Compare Match occurs between the Timer/Counter0 and the data in OCR0 – Output Compare Register0. 
** OCF0 is cleared by hardware when executing the corresponding interrupt Handling Vector. Alternatively, 
** OCF0 is cleared by writing a logic one to the flag. When the I-bit in SREG, OCIE0 (Timer/Counter0 Compare Match Interrupt Enable),
** and OCF0 are set (one), the Timer/Counter0 Compare Match Interrupt is executed.
*/
#define OCF0	1
/*
** TOV0: Timer/Counter0 Overflow Flag.
** The TOV0 bit is set (one) when an overflow occurs in Timer/Counter0. TOV0 is cleared by hardware when executing the 
** corresponding interrupt Handling Vector. Alternatively, TOV0 is cleared by writing a logic one to the flag. When the SREG I-bit, 
** TOIE0 (Timer/Counter0 Overflow Interrupt Enable), and TOV0 are set (one), the Timer/Counter0 Overflow interrupt is executed. 
** In PWM mode, this bit is set when Timer/Counter0 changes counting direction at 0x00.
*/
#define TOV0	0
/*
			       **************************
******************************** 16-bit Timer/Counter1  ******************************
			       **************************

** TCCR1A – Timer/Counter1 Control Register A
*/
#define TCCR1A	*(volatile U8 *const)0x4F
/*
** COM1An: Compare Output Mode for Channel A [n = 1:0].
*/
#define COM1A1	0
#define COM1A0	1
/*
** COM1Bn: Compare Output Mode for Channel B [n = 1:0].
** The COM1A1:0 and COM1B1:0 control the Output Compare pins (OC1A and OC1B respectively) behavior.
** If one or both of the COM1A1:0 bits are written to one, the OC1A output overrides the normal port functionality of 
** the I/O pin it is connected to. If one or both of the COM1B1:0 bit are written to one, the OC1B output overrides the 
** normal port functionality of the I/O pin it is connected to. . However, note that the Data Direction Register (DDR) bit corresponding to
** the OC1A or OC1B pin must be set in order to enable the output driver. When the OC1A or OC1B is connected to the pin, the function of the
** COM1n1:0 bits is dependent of the WGM13:0 bits setting. The table below shows the COM1n1:0 bit functionality when the WGM13:0 bits are
** set to a Normal or a CTC mode (non-PWM).
** Compare Output Mode, non-PWM:
** COM1A1/COM1B1, COM1A0/COM1B0 = { 0 0: Normal port operation, OC1A/OC1B disconnected,
**									0 1: Toggle OC1A/OC1B on Compare Match,
**									1 0: Clear OC1A/OC1B on Compare Match (Set output to low level),
**									1 1: Set OC1A/OC1B on Compare Match (Set output to high level).  }
** Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM:
** COM1A1/COM1B1, COM1A0/COM1B0 = { 0 0: Normal port operation, OC1A/OC1B disconnected,
**									0 1: WGM13:0 = 9 or 14: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation). 
**										 For all other WGM1 settings, normal port operation, OC1A/OC1B disconnected,
**									1 0: Clear OC1A/OC1B on Compare Match when up-counting. Set OC1A/OC1B on Compare Match when down-counting,
**									1 1: Set OC1A/OC1B on Compare Match when up-counting. Clear OC1A/OC1B on Compare Match when down-counting. }
** Compare Output Mode, Fast PWM:
** COM1A1/COM1B1, COM1A0/COM1B0 = { 0 0: Normal port operation, OC1A/OC1B disconnected,
**									0 1: WGM13:0 = 15: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation). 
**										 For all other WGM1 settings, normal port operation, OC1A/OC1B disconnected,
**									1 0: Clear OC1A/OC1B on Compare Match, set OC1A/OC1B at BOTTOM (non-inverting mode),
**									1 1: Set OC1A/OC1B on Compare Match, clear OC1A/OC1B at BOTTOM (inverting mode). }
*/
#define COM1B1	2
#define COM1B0	3
/*
** FOC1A: Force Output Compare for channel A.
*/
#define FOC1A	4
/*
** FOC1B: Force Output Compare for channel B.
** The FOC1A/FOC1B bits are only active when the WGM13:0 bits specifies a non-PWM mode. However, for ensuring compatibility with 
** future devices, these bits must be set to zero when TCCR1A is written when operating in a PWM mode.
** When writing a logical one to the FOC1A/FOC1B bit, an immediate Compare Match is forced on the waveform generation unit.
** The OC1A/OC1B output is changed according to its COM1x1:0 bits setting. Note that the FOC1A/FOC1B bits are implemented as strobes. 
** Therefore it is the value present in the COM1x1:0 bits that determine the effect of the forced compare.
** A FOC1A/FOC1B strobe will not generate any interrupt nor will it clear the timer in Clear Timer on Compare Match (CTC) mode using OCR1A as TOP.
** The FOC1A/FOC1B bits are always read as zero.
*/
#define FOC1B	5
/*
** WGM1n: Waveform Generation Mode [n = 1:0].
** Combined with the WGM13:2 bits found in the TCCR1B Register, these bits control the counting sequence of the counter, 
** the source for maximum (TOP) counter value, and what type of waveform generation to be used, refer to the table below. 
** Modes of operation supported by the Timer/Counter unit are: Normal mode (counter), Clear Timer on Compare match (CTC) mode, 
** and three types of Pulse Width Modulation (PWM) modes.
** Waveform Generation Mode Bit Description:
** WGM13, WGM12, WGM11, WGM10 = { 0 0 0 0: Normal,							>>TOP= 0xFFFF, UpdateOf OCR1x at= Immediate,TOV1 FlagSetOn= MAX,
**								  0 0 0 1: PWM, Phase Correct, 8-bit,		>>TOP= 0x00FF, UpdateOf OCR1x at= TOP,		TOV1 FlagSetOn= BOTTOM,
**								  0 0 1 0: PWM, Phase Correct, 9-bit,		>>TOP= 0x01FF, UpdateOf OCR1x at= TOP,		TOV1 FlagSetOn= BOTTOM,
**								  0 0 1 1: PWM, Phase Correct, 10-bit,		>>TOP= 0x03FF, UpdateOf OCR1x at= TOP,		TOV1 FlagSetOn= BOTTOM,
**								  0 1 0 0: CTC "Clear on compare match",	>>TOP= OCR1A,  UpdateOf OCR1x at= Immediate,TOV1 FlagSetOn= MAX,
**								  0 1 0 1: Fast PWM, 8-bit,					>>TOP= 0x00FF, UpdateOf OCR1x at= BOTTOM,	TOV1 FlagSetOn= TOP,
**								  0 1 1 0: Fast PWM, 9-bit,					>>TOP= 0x01FF, UpdateOf OCR1x at= BOTTOM,	TOV1 FlagSetOn= TOP,
**								  0 1 1 1: Fast PWM, 10-bit,				>>TOP= 0x03FF, UpdateOf OCR1x at= BOTTOM,	TOV1 FlagSetOn= TOP,
**								  1 0 0 0: PWM, Phase and Frequency Correct,>>TOP= ICR1,   UpdateOf OCR1x at= BOTTOM,	TOV1 FlagSetOn= BOTTOM,
**								  1 0 0 1: PWM, Phase and Frequency Correct,>>TOP= OCR1A,  UpdateOf OCR1x at= BOTTOM,	TOV1 FlagSetOn=	BOTTOM,
**								  1 0 1 0: PWM, Phase Correct,				>>TOP= ICR1,   UpdateOf OCR1x at= TOP,		TOV1 FlagSetOn= BOTTOM,
**								  1 0 1 1: PWM, Phase Correct,				>>TOP= OCR1A,  UpdateOf OCR1x at= TOP,		TOV1 FlagSetOn= BOTTOM,
**								  1 1 0 0: CTC,	"Clear on compare match"	>>TOP= CR1,	   UpdateOf OCR1x at= Immediate,TOV1 FlagSetOn= MAX,
**								  1 1 0 1: Reserved,						>>- - - - - - - - - - - - -  - - - - - - - - - - - - - - - - - - - -
**								  1 1 1 0: Fast PWM,						>>TOP= ICR1,   UpdateOf OCR1x at= BOTTOM,	TOV1 FlagSetOn= TOP,
**								  1 1 1 1: Fast PWM,						>>TOP= OCR1A,  UpdateOf OCR1x at= BOTTOM,	TOV1 FlagSetOn= TOP, }
*/
#define WGM10	7
#define WGM11	6

/*
** TCCR1B – Timer/Counter1 Control Register B
*/
#define TCCR1B	*(volatile U8 *const)0x4E
/*
** ICNC1: Input Capture Noise Canceler.
** Setting this bit (to one) activates the Input Capture Noise Canceler. When the noise canceler is activated, 
** the input from the Input Capture pin (ICP1) is filtered. The filter function requires four successive equal valued samples of the 
** ICP1 pin for changing its output. The Input Capture is therefore delayed by four Oscillator cycles when the noise canceler is enabled.
*/
#define ICNC1 	7
/*
** ICES1: Input Capture Edge Select.
** This bit selects which edge on the Input Capture pin (ICP1) that is used to trigger a capture event. When the ICES1 bit is written to zero, 
** a falling (negative) edge is used as trigger, and when the ICES1 bit is written to one, a rising (positive) edge will trigger the capture.
** When a capture is triggered according to the ICES1 setting, the counter value is copied into the Input Capture Register (ICR1). 
** The event will also set the Input Capture Flag (ICF1), and this can be used to cause an Input Capture Interrupt, if this interrupt is enabled.
** When the ICR1 is used as TOP value (see description of the WGM13:0 bits located in the TCCR1A and the TCCR1B Register), 
** the ICP1 is disconnected and consequently the Input Capture function is disabled.
*/
#define ICES1	6
/*
** with FOC1A.
*/
#define WGM13	4
#define WGM12	3
/*
** CS1n: Clock Select [n = 0:2].
** The three Clock Select bits select the clock source to be used by the Timer/Counter. Refer to figures Timer/Counter Timing Diagram, 
** Setting of OCF1x, no Prescaling and Timer/Counter Timing Diagram, Setting of OCF1x, with Prescaler (f clk_I/O /8).
** Clock Select Bit Description:
** CS12, CS11, CS10 = { 0 0 0: No clock source (Timer/Counter stopped),
**						0 0 1: clk I/O /1 (No prescaling),
**						0 1 0: clk I/O /8 (From prescaler),
**						1 0 0: clk I/O /64 (From prescaler),
**						1 0 0: clkI/O/256 (From prescaler),
**						1 0 1: clk I/O /1024 (From prescaler),
**						1 1 0: External clock source on T1 pin. Clock on falling edge,
**						1 1 1: External clock source on T1 pin. Clock on rising edge. }.
** If external pin modes are used for the Timer/Counter1, transitions on the T1 pin will clock the counter even if the 
** pin is configured as an output. This feature allows software control of the counting.
*/
#define CS12	2
#define CS11	1
#define	CS10	0


/*
** TCNT1L – Timer/Counter1 Low byte.
** The two Timer/Counter I/O locations (TCNT1H and TCNT1L, combined TCNT1) give direct access, both for read and for write operations, 
** to the Timer/Counter unit 16-bit counter. To ensure that both the high and low bytes are read and written simultaneously when 
** the CPU accesses these registers, the access is performed using an 8-bit temporary High Byte Register (TEMP). 
** This temporary register is shared by all the other 16-bit registers.
** Modifying the counter (TCNT1) while the counter is running introduces a risk of missing a compare match between 
** TCNT1 and one of the OCR1x Registers. 
** Writing to the TCNT1 Register blocks (removes) the compare match on the following timer clock for all compare units.
*/
#define TCNT1L	*(volatile U8 *const)0x4C
/*
** TCNT1H – Timer/Counter1 High byte.
*/
#define TCNT1H	*(volatile U8 *const)0x4D
/*
** Assuming the CPU is little endian memory storing, TCNT1 can be written as:
*/
#define TCNT1	*(volatile U16 *const)0x4C

/*
** OCR1AL – Output Compare Register 1 A Low byte
** The Output Compare Registers contain a 16-bit value that is continuously compared with the counter value (TCNT1). 
** A match can be used to generate an Output Compare interrupt, or to generate a waveform output on the OC1x pin.
** The Output Compare Registers are 16-bit in size. To ensure that both the high and low bytes are written simultaneously when 
** the CPU writes to these registers, the access is performed using an 8-bit temporary High Byte Register (TEMP). 
** This temporary register is shared by all the other 16-bit registers.
*/
#define OCR1AL	*(volatile U8 *const)0x4A
/*
** OCR1AH – Output Compare Register 1 A High byte
*/
#define OCR1AH	*(volatile U8 *const)0x4B
/*
** Assuming the CPU is little endian memory storing, OCR1A can be written as:
*/
#define OCR1A	*(volatile U16 *const)0x4A
/*
** OCR1BL – Output Compare Register 1 B Low byte
*/
#define OCR1BL	*(volatile U8 *const)0x48
/*
** OCR1BH – Output Compare Register 1 B High byte
*/
#define OCR1BH	*(volatile U8 *const)0x49
/*
** Assuming the CPU is little endian memory storing, OCR1B can be written as:
*/
#define OCR1B	*(volatile U16 *const)0x48
/*
** ICR1L – Input Capture Register 1 Low byte
** The Input Capture is updated with the counter (TCNT1) value each time an event occurs on the ICP1 pin 
** (or optionally on the Analog Comparator output for Timer/Counter1). The Input Capture can be used for defining the counter TOP value.
** The Input Capture Register is 16-bit in size. To ensure that both the high and low bytes are read simultaneously when the CPU accesses 
** these registers, the access is performed using an 8-bit temporary High Byte Register (TEMP). 
** This temporary register is shared by all the other 16-bit registers.
*/
#define ICR1L	*(volatile U8 *const)0x46
/*
** ICR1H – Input Capture Register 1 High byte.
*/
#define ICR1H	*(volatile U8 *const)0x47
/*
** Assuming the CPU is little endian memory storing, ICR1 can be written as:
*/
#define ICR1	*(volatile U16 *const)0x46
/*
** TIMSK – Timer/Counter Interrupt Mask Register
** common for 3 timers, can't be defined because it defined in Timer0 before.
** This register contains interrupt control bits for several Timer/Counters, but only Timer1 bits are described in this section. 
** The remaining bits are described in their respective timer sections.
*/

/*
** TICIE1: Timer/Counter1, Input Capture Interrupt Enable.
** When this bit is written to one, and the I-flag in the Status Register is set (interrupts globally enabled), 
** the Timer/Counter1 Input Capture interrupt is enabled. The corresponding Interrupt Vector (see Interrupts on page 63) is executed when 
** the ICF1 Flag, located in TIFR, is set.
*/
#define TICIE1	5
/*
** OCIE1A: Timer/Counter1, Output Compare A Match Interrupt Enable.
** When this bit is written to one, and the I-flag in the Status Register is set (interrupts globally enabled), 
** the Timer/Counter1 Output Compare A match interrupt is enabled. The corresponding Interrupt Vector (see Interrupts on page 63) 
** is executed when the OCF1A Flag, located in TIFR, is set.
*/
#define OCIE1A	4
/*
** OCIE1B: Timer/Counter1, Output Compare B Match Interrupt Enable.
** When this bit is written to one, and the I-flag in the Status Register is set (interrupts globally enabled), 
** the Timer/Counter1 Output Compare B match interrupt is enabled. The corresponding Interrupt Vector (see Interrupts on page 63) is 
** executed when the OCF1B Flag, located in TIFR, is set.
*/
#define OCIE1B	3
/*
** TOIE1: Timer/Counter1, Overflow Interrupt Enable.
** When this bit is written to one, and the I-flag in the Status Register is set (interrupts globally enabled), 
** the Timer/Counter1 Overflow Interrupt is enabled. The corresponding Interrupt Vector (see Interrupts on page 63) is 
** executed when the TOV1 Flag, located in TIFR, is set.
*/
#define TOIE1	2

/*
** TIFR – Timer/Counter Interrupt Flag Register
** common for 3 timers, can't be defined because it defined in Timer0 before.
*/

/*
** ICF1: Timer/Counter1, Input Capture Flag
** This flag is set when a capture event occurs on the ICP1 pin. When the Input Capture Register (ICR1) is
** set by the WGM13:0 to be used as the TOP value, the ICF1 Flag is set when the counter reaches the TOP value.
** ICF1 is automatically cleared when the Input Capture Interrupt Vector is executed. Alternatively, ICF1 can be cleared by 
** writing a logic one to its bit location.
*/
#define ICF1	5
/*
** OCF1A: Timer/Counter1, Output Compare A Match Flag
** This flag is set in the timer clock cycle after the counter (TCNT1) value matches the Output Compare Register A (OCR1A).
** Note that a Forced Output Compare (FOC1A) strobe will not set the OCF1A Flag.
** OCF1A is automatically cleared when the Output Compare Match A Interrupt Vector is executed. Alternatively, OCF1A can be 
** cleared by writing a logic one to its bit location.
*/
#define OCF1A	4
/*
** OCF1B: Timer/Counter1, Output Compare B Match Flag
** This flag is set in the timer clock cycle after the counter (TCNT1) value matches the Output Compare Register B (OCR1B).
** Note that a Forced Output Compare (FOC1B) strobe will not set the OCF1B Flag.
** OCF1B is automatically cleared when the Output Compare Match B Interrupt Vector is executed. Alternatively, OCF1B can be 
** cleared by writing a logic one to its bit location.
*/
#define OCF1B	3
/*
** TOV1: Timer/Counter1, Overflow Flag.
** The setting of this flag is dependent of the WGM13:0 bits setting. In Normal and CTC modes, the TOV1 Flag is set when the timer overflows.
** TOV1 is automatically cleared when the Timer/Counter1 Overflow Interrupt Vector is executed. Alternatively, TOV1 can be 
** cleared by writing a logic one to its bit location.
*/
#define TOV1	2
/*
			       ********************************************
******************************** 8-bit Timer/Counter2, Asynchronous mode  ******************************
			       ********************************************
*/
/*
** TCCR2 – Timer/Counter Control Register
*/
#define TCCR2	*(volatile U8 *const)0x45
/*
** FOC2: Force Output Compare
** The FOC2 bit is only active when the WGM bits specify a non-PWM mode. However, for ensuring compatibility with future devices, 
** this bit must be set to zero when TCCR2 is written when operating in PWM mode. When writing a logical one to the FOC2 bit, 
** an immediate Compare Match is forced on the waveform generation unit. The OC2 output is changed according to its COM21:0 bits setting. 
** Note that the FOC2 bit is implemented as a strobe. Therefore it is the value present in the COM21:0 bits that
** determines the effect of the forced compare.
** A FOC2 strobe will not generate any interrupt, nor will it clear the timer in CTC mode using OCR2 as TOP.
** The FOC2 bit is always read as zero.
*/
#define FOC2 	7
/*
** WGM20: Waveform Generation Mode [n=0:1]
** These bits control the counting sequence of the counter, the source for the maximum (TOP) counter value, 
** and what type of waveform generation to be used. Modes of operation supported by the Timer/Counter unit are: Normal mode, 
** Clear Timer on Compare Match (CTC) mode, and two types of Pulse Width Modulation (PWM) modes.
** Waveform Generation Mode Bit Description:
** WGM21(CTC2), WGM20(PWM2) = { 0 0: Normal,			>> TOP= 0xFF, Update of OCR2= Immediate, TOV2 Flag Set= MAX,
**								0 1: PWM, Phase Correct,>> TOP= 0xFF, Update of OCR2= TOP,		 TOV2 Flag Set= BOTTOM,
**								1 0: CTC,				>> TOP= OCR2, Update of OCR2= Immediate, TOV2 Flag Set= MAX,
**								1 1: Fast PWM.			>> TOP=	0xFF, Update of OCR2= BOTTOM,	 TOV2 Flag Set= MAX. }.
** Note:  1. The CTC2 and PWM2 bit definition names are now obsolete. Use the WGM21:0 definitions.
** However, the functionality and location of these bits are compatible with previous versions of the timer.
*/
#define WGM20	6
#define WGM21	3
/*
** COM2n: Compare Match Output Mode [n = 1:0]
** These bits control the Output Compare Pin (OC2) behavior. If one or both of the COM21:0 bits are set,
** the OC2 output overrides the normal port functionality of the I/O pin it is connected to. However, 
** note that the Data Direction Register (DDR) bit corresponding to OC2 pin must be set in order to enable the output driver.
** When OC2 is connected to the pin, the function of the COM21:0 bits depends on the WGM21:0 bit setting. 
** The following table shows the COM21:0 bit functionality when the WGM21:0 bits are set to a normal or CTC mode (non-PWM).
** Compare Output Mode, Non-PWM Mode:
** COM21, COM20 = { 0 0: Normal port operation, OC2 disconnected.,
**					0 1: Toggle OC2 on Compare Match,
**					1 0: Clear OC2 on Compare Match,
**					1 1: Set OC2 on Compare Match.  }
** Compare Output Mode, Phase Correct PWM Mode:
** COM21, COM20 = { 0 0: Normal port operation, OC2 disconnected,
**					0 1: Reserved,
**					1 0: Clear OC2 on Compare Match when up-counting. Set OC2 on Compare Match when downcounting,
**					1 1: Set OC2 on Compare Match when up-counting. Clear OC2 on Compare Match when downcounting.  }
** A special case occurs when OCR2 equals TOP and COM21 is set. In this case, the Compare Match is ignored, but the set or clear is done at TOP.
** Compare Output Mode, Fast PWM Mode:
** COM21, COM20 = { 0 0: Normal port operation, OC2 disconnected,
**					0 1: Reserved,
**					1 0: Clear OC2 on Compare Match, set OC2 at BOTTOM, (non-inverting mode),
**					1 1: Set OC2 on Compare Match, clear OC2 at BOTTOM, (inverting mode).  }
** A special case occurs when OCR2 equals TOP and COM21 is set. In this case, the Compare Match is ignored, but the set or 
** clear is done at BOTTOM.
*/
#define COM21	5
#define COM20	4
/*
** CS2n: Clock Select [n = 2:0].
** The three Clock Select bits select the clock source to be used by the Timer/Counter.
** Clock Select Bit Description:
** CS12, CS11, CS10 = { 0 0 0: No clock source (Timer/Counter stopped),
**						0 0 1: clk I/O /1 (No prescaling),
**						0 1 0: clk I/O /8 (From prescaler),
**						1 0 0: clk I/O /64 (From prescaler),
**						1 0 0: clkI/O/256 (From prescaler),
**						1 0 1: clk I/O /1024 (From prescaler),
**						1 1 0: External clock source on T1 pin. Clock on falling edge,
**						1 1 1: External clock source on T1 pin. Clock on rising edge. }.
*/
#define CS22	2
#define CS21	1
#define CS20	0

/*
** TCNT0 – Timer/Counter Register
** The Timer/Counter Register gives direct access, both for read and write operations, to the Timer/Counter unit 8-bit counter. 
** Writing to the TCNT0 Register blocks (removes) the Compare Match on the following timer clock. 
** Modifying the counter (TCNT0) while the counter is running, introduces a risk of missing a Compare Match between TCNT0 and the OCR0 Register.
*/
#define TCNT0	*(volatile U8 *const)0x44
/*
** OCR0 – Output Compare Register
** The Output Compare Register contains an 8-bit value that is continuously compared with the counter value (TCNT0). 
** A match can be used to generate an Output Compare interrupt, or to generate a waveform output on the OC0 pin.
*/ 
#define OCR0	*(volatile U8 *const)0x43

/*
** ASSR – Asynchronous Status Register 
*/
#define ASSR	*(volatile U8 *const)0x42
/*
** AS2: Asynchronous Timer/Counter2
** When AS2 is written to zero, Timer/Counter 2 is clocked from the I/O clock, clk I/O . When AS2 is written to one, Timer/Counter 2 is 
** clocked from a crystal Oscillator connected to the Timer Oscillator 1 (TOSC1) pin.
** When the value of AS2 is changed, the contents of TCNT2, OCR2, and TCCR2 might be corrupted.
*/
#define AS2		3
/*
** TCN2UB: Timer/Counter2 Update Busy
** When Timer/Counter2 operates asynchronously and TCNT2 is written, this bit becomes set. When TCNT2 has been updated from 
** the temporary storage register, this bit is cleared by hardware. A logical zero in this bit indicates that TCNT2 is ready to be 
** updated with a new value.
*/
#define TCN2UB	2
/*
** OCR2UB: Output Compare Register2 Update Busy
** When Timer/Counter2 operates asynchronously and OCR2 is written, this bit becomes set. When OCR2 has been updated from the 
** temporary storage register, this bit is cleared by hardware. A logical zero in this bit indicates that OCR2 is ready to be 
** updated with a new value.
*/
#define OCR2UB	1
/*
** TCR2UB: Timer/Counter Control Register2 Update Busy
** When Timer/Counter2 operates asynchronously and TCCR2 is written, this bit becomes set. When TCCR2 has been updated from 
** the temporary storage register, this bit is cleared by hardware. A logical zero in this bit indicates that TCCR2 is ready to be 
** updated with a new value. If a write is performed to any of the three Timer/Counter2 Registers while its update busy flag is set, 
** the updated value might get corrupted and cause an unintentional interrupt to occur. The mechanisms for reading TCNT2, OCR2, 
** and TCCR2 are different. When reading TCNT2, the actual timer value is read. When reading OCR2 or TCCR2, 
** the value in the temporary storage register is read.
*/
#define TCR2UB	0
/*
** TIMSK – Timer/Counter Interrupt Mask Register
** common for 3 timers, can't be defined because it defined in Timer0 before.
*/
/*
** OCIE2: Timer/Counter2 Output Compare Match Interrupt Enable
** When the OCIE2 bit is written to one and the I-bit in the Status Register is set (one), the Timer/Counter2 Compare Match interrupt is enabled. ** The corresponding interrupt is executed if a Compare Match in Timer/Counter2 occurs 
** (i.e., when the OCF2 bit is set in the Timer/Counter Interrupt Flag Register – TIFR).
*/
#define OCIE2	7
/*
** TOIE2: Timer/Counter2 Overflow Interrupt Enable
** When the TOIE2 bit is written to one and the I-bit in the Status Register is set (one), the Timer/Counter2 Overflow interrupt is enabled. 
** The corresponding interrupt is executed if an overflow in Timer/Counter2 occurs 
** (i.e., when the TOV2 bit is set in the Timer/Counter Interrupt Flag Register – TIFR).
*/
#define TOIE2	6
/*
** TIFR – Timer/Counter Interrupt Flag Register.
** common for 3 timers, can't be defined because it defined in Timer0 before.
*/
/*
** OCF2: Output Compare Flag 2
** The OCF2 bit is set (one) when a Compare Match occurs between the Timer/Counter2 and the data in OCR2 – Output Compare Register2. 
** OCF2 is cleared by hardware when executing the corresponding interrupt Handling Vector. Alternatively, OCF2 is cleared by writing a 
** logic one to the flag. When the I-bit in SREG, OCIE2 (Timer/Counter2 Compare Match Interrupt Enable), and OCF2 are set (one), 
** the Timer/ Counter2 Compare Match Interrupt is executed.
*/
#define OCF2	7
/*
** TOV2: Timer/Counter2 Overflow Flag
** The TOV2 bit is set (one) when an overflow occurs in Timer/Counter2. TOV2 is cleared by hardware when executing the corresponding 
** interrupt Handling Vector. Alternatively, TOV2 is cleared by writing a logic one to the flag. When the SREG I-bit, 
** TOIE2 (Timer/Counter2 Overflow Interrupt Enable), and TOV2 are set (one), the Timer/Counter2 Overflow interrupt is executed. 
** In PWM mode, this bit is set when Timer/Counter2 changes counting direction at 0x00.
*/
#define TOV2	6
/*
			       **********************
******************************** Analog Comparator  ******************************
			       **********************
*/

/*
** ACSR – Analog Comparator Control and Status Register 
*/
#define ACSR	*(volatile U8 *const)0x28
/*
** ACD: Analog Comparator Disable
** When this bit is written logic one, the power to the Analog Comparator is switched off. This bit can be set at any time to turn off 
** the Analog Comparator. This will reduce power consumption in Active and Idle mode. When changing the ACD bit, the Analog Comparator 
** Interrupt must be disabled by clearing the ACIE bit in ACSR. Otherwise an interrupt can occur when the bit is changed.
*/
#define ACD 	7
/*
** ACBG: Analog Comparator Bandgap Select
** When this bit is set, a fixed bandgap reference voltage replaces the positive input to the Analog Comparator. When this bit is cleared, 
** AIN0 is applied to the positive input of the Analog Comparator.
*/
#define ACBG 	6
/*
** ACO: Analog Comparator Output
** The output of the Analog Comparator is synchronized and then directly connected to ACO. 
** The synchronization introduces a delay of 1 - 2 clock cycles.
*/
#define ACO 	5
/*
** ACI: Analog Comparator Interrupt Flag
** This bit is set by hardware when a comparator output event triggers the interrupt mode defined by ACIS1 and ACIS0. 
** The Analog Comparator interrupt routine is executed if the ACIE bit is set and the I-bit in SREG is set. 
** ACI is cleared by hardware when executing the corresponding interrupt handling vector. Alternatively, ACI is cleared by writing a 
** logic one to the flag.
*/
#define ACI 	4
/*
** ACIE: Analog Comparator Interrupt Enable
** When the ACIE bit is written logic one and the I-bit in the Status Register is set, 
** the Analog Comparator interrupt is activated. When written logic zero, the interrupt is disabled.
*/
#define ACIE 	3
/*
** ACIC: Analog Comparator Input Capture Enable
** When written logic one, this bit enables the input capture function in Timer/Counter1 to be triggered by the Analog Comparator. 
** The comparator output is in this case directly connected to the input capture front-end logic, making the comparator utilize the noise 
** canceler and edge select features of the Timer/ Counter1 Input Capture interrupt. 
** When written logic zero, no connection between the Analog Comparator and the input capture function exists. 
** To make the comparator trigger the Timer/Counter1 Input Capture interrupt, the ICIE1 bit in the Timer Interrupt 
** Mask Register (TIMSK1) must be set.
*/
#define ACIC 	2
/*
** ACISn: Analog Comparator Interrupt Mode Select [n = 1:0]
** These bits determine which comparator events that trigger the Analog Comparator interrupt.
** ACIS1, ACIS0 = { 0 0: Comparator Interrupt on Output Toggle,
					0 1: Reserved,
					1 0: Comparator Interrupt on Falling Output Edge,
					1 1: Comparator Interrupt on Rising Output Edge. }.
** When changing the ACIS1/ACIS0 bits, the Analog Comparator Interrupt must be disabled by clearing its Interrupt Enable bit in the 
** ACSR Register. Otherwise an interrupt can occur when the bits are changed.
*/
#define ACIS1 	1
#define ACIS0	0
/*
			       **************************************
******************************** ADC - Analog to Digital Converter  ******************************
			       **************************************
*/
/*
** ADMUX – ADC Multiplexer Selection Register
*/
#define ADMUX	*(volatile U8 *const)0x27
/*
** REFSn: Reference Selection [n = 1:0]
** These bits select the voltage reference for the ADC. If these bits are changed during a conversion, the change will not go in 
** effect until this conversion is complete (ADIF in ADCSRA is set). The internal voltage reference options may not be used if an external 
** reference voltage is being applied to the AREF pin. ADC Voltage Reference Selection:
** REFS1, REFS0 = { 0 0: AREF, Internal V ref turned off
					0 1: AV CC with external capacitor at AREF pin
					1 0: Reserved
					1 1: Internal 2.56V Voltage Reference with external capacitor at AREF pin }.
*/
#define REFS1	7
#define REFS0	6
/*
** ADLAR: ADC Left Adjust Result
** The ADLAR bit affects the presentation of the ADC conversion result in the ADC Data Register. Write one to ADLAR to left adjust the result. 
** Otherwise, the result is right adjusted. Changing the ADLAR bit will affect the ADC Data Register immediately, 
** regardless of any ongoing conversions.
*/
#define ADLAR	5
/*
** MUXn: Analog Channel Selection [n = 4:0]
** The value of these bits selects which combination of analog inputs are connected to the ADC. 
** These bits also select the gain for the differential channels. Refer to table below for details. If these bits are changed during a 
** conversion, the change will not go in effect until this conversion is complete (ADIF in ADCSRA on page 278 is set).
** Input Channel and Gain Selections: Read page 276.
*/
#define MUX4	4
#define MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0
/*
** ADCSRA – ADC Control and Status Register A
*/
#define ADCSRA	*(volatile U8 *const)0x26
/*
** ADEN: ADC Enable
** Writing this bit to one enables the ADC. By writing it to zero, the ADC is turned off. Turning the ADC off while a conversion is 
** in progress, will terminate this conversion.
*/
#define ADEN 	7
/*
** ADSC: ADC Start Conversion
** In Single Conversion mode, write this bit to one to start each conversion. In Free Running mode, write this bit to one to start the 
** first conversion. The first conversion after ADSC has been written after the ADC has been enabled, or if ADSC is written at 
** the same time as the ADC is enabled, will take 25 ADC clock cycles instead of the normal 13. This first conversion performs initialization of ** the ADC.  ADSC will read as one as long as a conversion is in progress. When the conversion is complete, it returns to zero. 
** Writing zero to this bit has no effect.
*/
#define ADSC 	6
/*
** ADATE: ADC Auto Trigger Enable
** When this bit is written to one, Auto Triggering of the ADC is enabled. The ADC will start a conversion on a positive edge of the 
** selected trigger signal. The trigger source is selected by setting the ADC Trigger Select bits, ADTS in SFIOR.
*/
#define ADATE 	5
/*
** ADC Interrupt Flag
** This bit is set when an ADC conversion completes and the Data Registers are updated. The ADC Conversion Complete Interrupt is executed if 
** the ADIE bit and the I-bit in SREG are set. ADIF is cleared by hardware when executing the corresponding interrupt Handling Vector. 
** Alternatively, ADIF is cleared by writing a logical one to the flag. Beware that if doing a Read-Modify-Write on ADCSRA, 
** a pending interrupt can be disabled. This also applies if the SBI and CBI instructions are used.
*/
#define ADIF 	4
/*
** ADIE: ADC Interrupt Enable
** When this bit is written to one and the I-bit in SREG is set, the ADC Conversion Complete Interrupt is activated.
*/
#define ADIE 	3
/*
** ADPSn: ADC Prescaler Select [n = 2:0]
** These bits determine the division factor between the XTAL frequency and the input clock to the ADC.
** ADC Prescaler Selections:
** ADPS2, ADPS1, ADPS0 = { 0 0 0: Division Factor= 2
						   0 0 1: Division Factor= 2
						   0 1 0: Division Factor= 4
						   0 1 1: Division Factor= 8
						   1 0 0: Division Factor= 16
						   1 0 1: Division Factor= 32
						   1 1 0: Division Factor= 64
						   1 1 1: Division Factor= 128 }.
*/
#define ADPS2 	2
#define ADPS1 	1
#define ADPS0	0
/*
** ADCL – ADC Data Register Low (ADLAR=0) 
** When an ADC conversion is complete, the result is found in these two registers. If differential channels are used, 
** the result is presented in two’s complement form. When ADCL is read, the ADC Data Register is not updated until ADCH is read. 
** Consequently, if the result is left adjusted and no more than 8-bit precision is required, it is sufficient to read ADCH. 
** Otherwise, ADCL must be read first, then ADCH. The ADLAR bit and the MUXn bits in ADMUX affect the way the result is read from the registers. ** If ADLAR is set, the result is left adjusted. If ADLAR is cleared (default), the result is right adjusted.
*/
#define ADCL	*(volatile const U8 *const)0x24
/*
** ADCn: ADC Conversion Result [n = 7:0]
** These bits represent the result from the conversion. Refer to ADC Conversion Result for details.
*/
#define ADC7 	7
#define ADC6 	6
#define ADC5 	5
#define ADC4 	4
#define ADC3 	3
#define ADC2 	2
#define ADC1 	1
#define ADC0	0
/*
** ADCH – ADC Data Register High (ADLAR=0).
*/
#define ADCH	*(volatile const U8 *const)0x25
#define ADC9 	1
#define ADC8	0
/*
** Assuming the CPU storing memory is little endian, ADC can used as:
*/
#define ADC	*(volatile const U16 *const)0x24
/*
			       **************************************
******************************** SPI – Serial Peripheral Interface  ******************************
			       **************************************
*/

/*
** SPCR – SPI Control Register
*/
#define SPCR	*(volatile U8 *const)0x2D
/*
** SPIE: SPI Interrupt Enable
** This bit causes the SPI interrupt to be executed if SPIF bit in the SPSR Register is set and if the Global Interrupt Enable bit in SREG is set.
*/
#define SPIE	7
/*
** SPE: SPI Enable
** When the SPE bit is written to one, the SPI is enabled. This bit must be set to enable any SPI operations.
*/
#define SPE		6
/*
** DORD: Data Order
** When the DORD bit is written to one, the LSB of the data word is transmitted first.
** When the DORD bit is written to zero, the MSB of the data word is transmitted first
*/
#define DORD	5
/*
** MSTR: Master/Slave Select
** This bit selects Master SPI mode when written to one, and Slave SPI mode when written logic zero. 
** If SS is configured as an input and is driven low while MSTR is set, MSTR will be cleared, and SPIF in SPSR
** will become set. The user will then have to set MSTR to re-enable SPI Master mode.
*/
#define MSTR	4
/*
** When this bit is written to one, SCK is high when idle. When CPOL is written to zero, SCK is low when idle. 
** The CPOL functionality is summarized below:
** CPOL= 0, Leading Edge= Rising, Trailing Edge= Falling.
** CPOL= 1, Leading Edge= Falling, Trailing Edge= Rising.
*/
#define CPOL	3
/*
** CPHA: Clock Phase
The settings of the Clock Phase bit (CPHA) determine if data is sampled on the leading (first) or trailing (last) edge of SCK. 
** The CPHA functionality is summarized below:
** CPHA= 0, Leading Edge= Sample, Trailing Edge= Setup.
** CPHA= 1, Leading Edge= Setup,  Trailing Edge= Sample.
*/
#define CPHA	2
/*
** SPRn: SPI Clock Rate Select [n = 1:0]
These two bits control the SCK rate of the device configured as a Master. SPR1 and SPR0 have no effect
on the Slave. The relationship between SCK and the Oscillator Clock frequency f osc is shown below. 
** Relationship between SCK and Oscillator Frequency:
** SPI2X, SPR1, SPR0 = { 0 0 0: f osc /4
				  		 0 0 1: f osc /16
				 		 0 1 0: f osc /64
				  		 0 1 1: f osc /128
				 		 1 0 0: f osc /2
				 		 1 0 1: f osc /8
				 		 1 1 0: f osc /32
				 		 1 1 1: f osc /64 }.
*/
#define SPR1	1
#define SPR0	0
/*
** SPSR – SPI Status Register
*/
#define SPSR	*(volatile U8 *const)0x2E
/*
** SPIF: SPI Interrupt Flag
** When a serial transfer is complete, the SPIF Flag is set. An interrupt is generated if SPIE in SPCR is set and global interrupts are enabled. ** If SS is an input and is driven low when the SPI is in Master mode, this will also set the SPIF Flag. SPIF is cleared by 
** hardware when executing the corresponding interrupt handling vector. Alternatively, the SPIF bit is cleared by first reading 
** the SPI Status Register with SPIF set, then accessing the SPI Data Register (SPDR).
*/
#define SPIF 	7
/*
** WCOL: Write Collision Flag
** The WCOL bit is set if the SPI Data Register (SPDR) is written during a data transfer. The WCOL bit (and the SPIF bit) are cleared by 
** first reading the SPI Status Register with WCOL set, and then accessing the SPI Data Register.
*/
#define WCOL	6
/*
** SPI2X: Double SPI Speed Bit
** When this bit is written logic one the SPI speed (SCK Frequency) will be doubled when the SPI is in Master mode.
** This means that the minimum SCK period will be two CPU clock periods. When the SPI is configured as Slave, the SPI is only 
** guaranteed to work at f osc /4 or lower.
** The SPI interface on the ATmega32A is also used for program memory and EEPROM downloading or uploading.
*/
#define SPI2X	0
/*
** SPDR – SPI Data Register is a read/write register
*/
#define SPDR	*(volatile U8 *const)0x2F
/*
** SPIDn: SPI Data
** The SPI Data Register is a read/write register used for data transfer between the Register File and the SPI Shift Register. 
** Writing to the register initiates data transmission. Reading the register causes the Shift Register Receive buffer to be read.
*/
#define SPID7 	7
#define SPID6 	6
#define SPID5 	5
#define SPID4 	4
#define SPID3 	3
#define SPID2 	2
#define SPID1 	1
#define SPID0	0

/*
			       ***********************************************************************************
******************************** USART - Universal Synchronous and Asynchronous serial Receiver and Transmitter  ******************************
			       ***********************************************************************************
*/
/*
** UDR – USART I/O Data Register
*/
#define UDR	  *(volatile U8 *const)0x2C
/*
** TXB/RXB[7:0]: USART Transmit / Receive Data Buffer.
** The USART Transmit Data Buffer Register and USART Receive Data Buffer Registers share the same I/O address referred to 
** as USART Data Register or UDR. The Transmit Data Buffer Register (TXB) will be the destination for data written to the UDR Register location. ** Reading the UDR Register location will return the contents of the Receive Data Buffer Register (RXB).
** For 5-, 6-, or 7-bit characters the upper unused bits will be ignored by the Transmitter and set to zero by the Receiver.
** The transmit buffer can only be written when the UDRE Flag in the UCSRA Register is set. Data written to UDR when the UDRE Flag is not set, 
** will be ignored by the USART Transmitter. When data is written to the transmit buffer, and the Transmitter is enabled, the Transmitter will 
** load the data into the Transmit Shift Register when the Shift Register is empty. Then the data will be serially transmitted on the TxD pin.
** The receive buffer consists of a two level FIFO. The FIFO will change its state whenever the receive buffer is accessed. 
** Due to this behavior of the receive buffer, do not use Read-Modify-Write instructions (SBI and CBI) on this location. 
** Be careful when using bit test instructions (SBIC and SBIS), since these also will change the state of the FIFO.
*/
/*
** UCSRA – USART Control and Status Register A
*/
#define UCSRA	*(volatile U8 *const)0x2B
/*
** RXC: USART Receive Complete
** This flag bit is set when there are unread data in the receive buffer and cleared when the receive buffer is empty 
** (i.e. does not contain any unread data). If the Receiver is disabled, the receive buffer will be flushed and consequently 
** the RXC bit will become zero. The RXC Flag can be used to generate a Receive Complete interrupt (see description of the RXCIE bit).
*/
#define RXC 	7
/*
** TXC: USART Transmit Complete
** This flag bit is set when the entire frame in the Transmit Shift Register has been shifted out and there are no new data currently 
** present in the transmit buffer (UDR). The TXC Flag bit is automatically cleared when a transmit complete interrupt is executed, 
** or it can be cleared by writing a one to its bit location. The TXC Flag can generate a Transmit Complete interrupt 
** (see description of the TXCIE bit).
*/
#define TXC 	6
/*
** UDRE: USART Data Register Empty
** The UDRE Flag indicates if the transmit buffer (UDR) is ready to receive new data. If UDRE is one, the buffer is empty, 
** and therefore ready to be written. The UDRE Flag can generate a Data Register Empty interrupt (see description of the UDRIE bit).
** UDRE is set after a reset to indicate that the Transmitter is ready.
*/
#define UDRE 	5
/*
** FE: Frame Error
** This bit is set if the next character in the receive buffer had a Frame Error when received 
** (i.e., when the first stop bit of the next character in the receive buffer is zero). 
** This bit is valid until the receive buffer (UDR) is read. The FE bit is zero when the stop bit of received data is one. 
** Always set this bit to zero when writing to UCSRA.
*/
#define FE 		4
/*
** DOR: Data OverRun
** This bit is set if a Data OverRun condition is detected. A Data OverRun occurs when the receive buffer is full (two characters), 
** it is a new character waiting in the Receive Shift Register, and a new start bit is detected. 
** This bit is valid until the receive buffer (UDR) is read. Always set this bit to zero when writing to UCSRA.
*/
#define DOR 	3
/*
** PE: Parity Error
** This bit is set if the next character in the receive buffer had a Parity Error when received and the parity checking was enabled at 
** that point (UPM1 = 1). This bit is valid until the receive buffer (UDR) is read. Always set this bit to zero when writing to UCSRA.
*/
#define PE 		2
/*
** U2X: Double the USART Transmission Speed
** This bit only has effect for the asynchronous operation. Write this bit to zero when using synchronous operation.
** Writing this bit to one will reduce the divisor of the baud rate divider from 16 to 8 effectively doubling the transfer rate for 
** asynchronous communication.
*/
#define U2X 	1
/*
** MPCM: Multi-processor Communication Mode
** This bit enables the Multi-processor Communication mode. When the MPCM bit is written to one, all the incoming frames received by 
** the USART Receiver that do not contain address information will be ignored. The Transmitter is unaffected by the MPCM setting.
*/
#define MPCM	0
/*
** UCSRB – USART Control and Status Register B
*/
#define UCSRB	*(volatile U8 *const)0x2A
/*
** RXCIE: RX Complete Interrupt Enable
** Writing this bit to one enables interrupt on the RXC Flag. A USART Receive Complete interrupt will be generated only if 
** the RXCIE bit is written to one, the Global Interrupt Flag in SREG is written to one and the RXC bit in UCSRA is set.
*/
#define RXCIE 	7
/*
** TXCIE: TX Complete Interrupt Enable
** Writing this bit to one enables interrupt on the TXC Flag. A USART Transmit Complete interrupt will be generated only if 
** the TXCIE bit is written to one, the Global Interrupt Flag in SREG is written to one and the TXC bit in UCSRA is set.
*/
#define TXCIE 	6
/*
** UDRIE: USART Data Register Empty Interrupt Enable
** Writing this bit to one enables interrupt on the UDRE Flag. A Data Register Empty interrupt will be generated only if the UDRIE 
** bit is written to one, the Global Interrupt Flag in SREG is written to one and the UDRE bit in UCSRA is set.
*/
#define UDRIE 	5
/*
** RXEN: Receiver Enable
** Writing this bit to one enables the USART Receiver. The Receiver will override normal port operation for the RxD pin when enabled. 
** Disabling the Receiver will flush the receive buffer invalidating the FE, DOR and PE Flags.
*/
#define RXEN 	4
/*
** TXEN: Transmitter Enable
** Writing this bit to one enables the USART Transmitter. The Transmitter will override normal port operation for the TxD pin when enabled. 
** The disabling of the Transmitter (writing TXEN to zero) will not become effective until ongoing and pending transmissions are completed 
** (i.e., when the Transmit Shift Register and Transmit Buffer Register do not contain data to be transmitted). 
** When disabled, the Transmitter will no longer override the TxD port.
*/
#define TXEN 	3
/*
** UCSZ2: Character Size
** The UCSZ2 bits combined with the UCSZ1:0 bit in UCSRC sets the number of data bits (Character Size) in a frame the Receiver and 
** Transmitter use.
*/
#define UCSZ2 	2
/*
** RXB8: Receive Data Bit 8
** RXB8 is the ninth data bit of the received character when operating with serial frames with nine data bits. Must be read before reading 
** the low bits from UDR.
*/
#define RXB8 	1
/*
** TXB8: Transmit Data Bit 8
** TXB8 is the ninth data bit in the character to be transmitted when operating with serial frames with nine data bits. 
** Must be written before writing the low bits to UDR.
*/
#define TXB8	0

/*
** UCSRC – USART Control and Status Register C
*/
#define UCSRC	*(volatile U8 *const)0x40
/*
** URSEL: Register Select
** This bit selects between accessing the UCSRC or the UBRRH Register. It is read as one when reading UCSRC. 
** The URSEL must be one when writing the UCSRC.
*/
#define URSEL 	7
/*
** UMSEL: Mode Select
** This bit selects between Asynchronous and Synchronous mode of operation.
** UMSEL Bit Settings: UMSEL= 0 >> Asynchronous Operation mode	, UMSEL= 1 >> Synchronous Operation.
*/
#define UMSEL 	6
/*
** UPMn: Parity Mode [n = 1:0]
** These bits enable and set type of Parity Generation and Check. If enabled, the Transmitter will automatically generate and 
** send the parity of the transmitted data bits within each frame. The Receiver will generate a parity value for the incoming data and 
** compare it to the UPM0 setting. If a mismatch is detected, the PE Flag in UCSRA will be set. UPM Bits Settings:
** UPM1, UPM0 = { 0 0: Disabled
				  0 1: Reserved
				  1 0: Enabled, Even Parity
				  1 1: Enabled, Odd Parity }.
*/
#define UPM1 	5
#define UPM0 	4
/*
** USBS: Stop Bit Select
** This bit selects the number of stop bits to be inserted by the Transmitter. The Receiver ignores this setting.
** USBS= 0 >> stop-bits= 1-bit, USBS= 1 >> stop-bits= 2-bit.
*/
#define USBS 	3
/*
** UCSZn: Character Size [n = 1:0]
** The UCSZ1:0 bits combined with the UCSZ2 bit in UCSRB sets the number of data bits (Character Size) in a frame the Receiver and 
** Transmitter use. UCSZ Bits Settings:
** UCSZ2, UCSZ1, UCSZ0 = { 0 0 0: 5-bit
				  		   0 0 1: 6-bit
				 		   0 1 0: 7-bit
				  		   0 1 1: 8-bit
				 		   1 0 0: Reserved
				 		   1 0 1: Reserved
				 		   1 1 0: Reserved
				 		   1 1 1: 9-bit }.
*/
#define UCSZ1 	2
#define UCSZ0 	1
/*
** UCPOL: Clock Polarity
** This bit is used for Synchronous mode only. Write this bit to zero when Asynchronous mode is used. 
** The UCPOL bit sets the relationship between data output change and data input sample, and the synchronous clock (XCK). UCPOL Bit Settings:
** UCPOL= 0 >> Transmitted Data Changed (Output of TxD Pin)= Rising XCK Edge,  Received Data Sampled (Input on RxD Pin)= Falling XCK Edge.
** UCPOL= 1 >> Transmitted Data Changed (Output of TxD Pin)= Falling XCK Edge, Received Data Sampled (Input on RxD Pin)= Rising XCK Edge.
*/
#define UCPOL	0
/*
** UBRRL – USART Baud Rate Register Low
*/
#define UBRRL	*(volatile U8 *const)0x29
/* 
** UBBR[7:0]: USART Baud Rate Register
** This is a 12-bit register which contains the USART baud rate. The UBRRH contains the four most significant bits, 
** and the UBRRL contains the eight least significant bits of the USART baud rate. Ongoing transmissions by the Transmitter and 
** Receiver will be corrupted if the baud rate is changed. Writing UBRRL will trigger an immediate update of the baud rate prescaler.
*/
/*
** UBBRH – USART Baud Rate Register High
** UBRR[3:0]: USART Baud Rate Register [n = 11:8].
*/
/*
			       ************************************
******************************** TWI - Two-wire Serial Interface  ******************************
			       ************************************
*/
/* 
** TWBR – TWI Bit Rate Register
*/
#define TWBR	*(volatile U8 *const)0x20
#define TWBR7 	7
#define TWBR6 	6
#define TWBR5 	5
#define TWBR4 	4
#define TWBR3 	3
#define TWBR2 	2
#define TWBR1 	1
#define TWBR0	0


/*
** TWCR – TWI Control Register
*/
#define TWCR	*(volatile U8 *const)0x56
#define TWINT 	7
#define TWEA 	6
#define TWSTA 	5
#define TWSTO 	4
#define TWWC 	3
#define TWEN 	2
#define TWIE	0


/*
** TWSR – TWI Status Register
*/
#define TWSR	*(volatile U8 *const)0x21
#define TWS4 	7
#define TWS3 	6
#define TWS2 	5
#define TWS1 	4
#define TWS0	3
#define TWPS1 	1
#define TWPS0	0


/*
** TWDR – TWI Data Register
*/
#define TWDR	*(volatile U8 *const)0x23
#define TWD7 	7
#define TWD6	6
#define TWD5 	5
#define TWD4 	4
#define TWD3 	3	
#define TWD2 	2
#define TWD1 	1
#define TWD0	0

/*
** TWAR – TWI (Slave) Address Register
*/
#define TWAR	*(volatile U8 *const)0x22
#define TWA6 	7
#define TWA5 	6
#define TWA4 	5
#define TWA3 	4
#define TWA2 	3
#define TWA1 	2
#define TWA0 	1
#define TWGCE	0


#endif
