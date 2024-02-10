/*
 * Timers_Interface.h
 *
 *  Created on: Jul 2, 2023
 *      Author: dell
 */

#ifndef INCLUDE_MCAL_TIMERS_TIMERS_INTERFACE_H_
#define INCLUDE_MCAL_TIMERS_TIMERS_INTERFACE_H_




#define NORMAL_MODE          0
#define PHASE_CORRECT_MODE   1
#define CTC_MODE             2
#define FAST_PWM_MODE        3

//Output Mode
#define NORMAL_DIO_PIN    0
#define TOGGLE_CTC	      1
#define CLEAR_CTC	      2
#define SET_CTC	          3
#define INVERTING_PWM     3
#define NONINVERTING_PWM  2

typedef enum
{
	ICU_FALLING_EDGE=0,
	ICU_RISING_EDGE,
}TRIGGER_SOURCE;






void MTIMER0_voidInit();
void MTIMER0_voidSetPreloadValue (u8 A_u8NoOfTicks);
void MTIMER0_voidSetOCR0Value (u8 A_u8OCR0Value);
u8  MTIMER0_u8ReadTimer0Value(void);
void MTIMER0_voidStopTimer (void);
void MTIMER0_voidSetOVFCallback (void (*A_PtrToFunc) (void));
void MTIMER0_voidSetCTCCallback (void (*A_PtrToFunc) (void));


void MTIMER1_voidInit();
void MTIMER1_voidSetPreloadValue (u16 A_u8NoOfTicks);
void MTIMER1_voidSetOCR1AValue (u16 A_u16Value);
void MTIMER1_voidSetICR1Value (u16 A_u16Value);
void MTIMER1_voidSetOCR1BValue (u16 A_u16Value);
u16  MTIMER1_u16ReadTimer1Value(void);
u16  MTIMER1_u16ReadICR1Value(void);
void TIMER1_voidICUSetTrigger(TRIGGER_SOURCE A_TRIGGER_SOURCE);
void MTIMER1_voidStopTimer (void);
void MTIMER1_voidSetOVFCallback (void (*A_PtrToFunc) (void));
void MTIMER1_voidSetCTCACallback (void (*A_PtrToFunc) (void));
void MTIMER1_voidSetCTCBCallback (void (*A_PtrToFunc) (void));
void MTIMER1_voidSetCAPTCallback (void (*A_PtrToFunc) (void));

void MTIMER2_voidInit();
void MTIMER2_voidSetPreloadValue (u8 A_u8NoOfTicks);
void MTIMER2_voidSetOCR2Value (u8 A_u8OCR0Value);
u8   MTIMER2_u8ReadTimer2Value(void);
void MTIMER2_voidStopTimer (void);
void MTIMER2_voidSetOVFCallback (void (*A_PtrToFunc) (void));
void MTIMER2_voidSetCTCCallback (void (*A_PtrToFunc) (void));

void MICUHW_voidInit();
void MICUHW_voidDisable();









#endif /* INCLUDE_MCAL_TIMERS_TIMERS_INTERFACE_H_ */
