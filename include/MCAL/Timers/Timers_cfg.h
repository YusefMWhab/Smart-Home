/*
 * Timers_cfg.h
 *
 *  Created on: Jul 2, 2023
 *      Author: dell
 */

#ifndef INCLUDE_MCAL_TIMERS_TIMERS_CFG_H_
#define INCLUDE_MCAL_TIMERS_TIMERS_CFG_H_


//Timer n Mode Selection
/*
 * Options :
 * 			 NORMAL_MODE
 *	 	 	 PHASE_CORRECT_MODE
 *	 	 	 CTC_MODE
 *	 	 	 FAST_PWM_MODE
 */
#define Timer0_Mode  NORMAL_MODE
#define Timer2_Mode  CTC_MODE


//Timer n Clk Selection
/*
 *
0b000 No clock source (Timer/Counter stopped).
0b001 clkI/O/(No prescaling)
0b010 clkI/O/8 (From prescaler)
0b011 clkI/O/64 (From prescaler)
0b100 clkI/O/256 (From prescaler)
0b101 clkI/O/1024 (From prescaler)
0b110 External clock source on T0 pin. Clock on falling edge.
0b111 External clock source on T0 pin. Clock on rising edge
*/
#define TIMER0_CLK_CONFIGURATION 0b010
#define TIMER1_CLK_CONFIGURATION 0b010
#define TIMER2_CLK_CONFIGURATION 0b010

//Compare Match Value
#define OCR0_VALUE	199
#define OCR1A_VALUE	0
#define OCR1B_VALUE	0
#define OCR2_VALUE	199


// ICR1 Value
#define ICR1_VALUE 19999

/*
*	 	Options:
* 				NORMAL_DIO_PIN
* 				TOGGLE_CTC
* 				CLEAR_CTC
* 				SET_CTC
* 				INVERTING_PWM
* 				NONINVERTING_PWM
*/
#define TIMER0_OC0_PIN_MODE   NORMAL_DIO_PIN
#define TIMER1_OC1A_PIN_MODE  TOGGLE_CTC
#define TIMER1_OC1B_PIN_MODE  TOGGLE_CTC
#define TIMER2_OC2_PIN_MODE   NORMAL_DIO_PIN




#endif /* INCLUDE_MCAL_TIMERS_TIMERS_CFG_H_ */
