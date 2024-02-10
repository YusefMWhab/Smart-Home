/*
 * Timers_Program.c
 *
 *  Created on: Jul 2, 2023
 *      Author: dell
 */
#include <util/delay.h>
#include "..\include\LIB\BIT_MATH.h"
#include "..\include\LIB\STD_TYPES.h"

#include "..\include\MCAL\Timers\Timers_Interface.h"
#include "..\include\MCAL\Timers\Timers_Private.h"
#include "..\include\MCAL\Timers\Timers_cfg.h"


void (*TIMER0_OVF_CALLBACK)(void) = NULL;
void (*TIMER0_CTC_CALLBACK)(void) = NULL;

void (*TIMER1_CAPT_CALLBACK)(void)  = NULL;
void (*TIMER1_OVF_CALLBACK)(void)  = NULL;
void (*TIMER1_CTCA_CALLBACK)(void) = NULL;
void (*TIMER1_CTCB_CALLBACK)(void) = NULL;

void (*TIMER2_OVF_CALLBACK)(void)  = NULL;
void (*TIMER2_CTC_CALLBACK)(void)  = NULL;



//Initialization
void MTIMER0_voidInit()
{

//Mode Selection
#if Timer0_Mode == NORMAL_MODE
	CLEAR_BIT(TCCR0,3);
	CLEAR_BIT(TCCR0,6);

	// Turn on Overflow Interrupt & Turn off CTC Interrupt
	SET_BIT(TIMSK,0);
	CLEAR_BIT(TIMSK,1);
	//Clock Selection
	TCCR0 &= TIMER0_CLK_MASK;
	TCCR0 |= TIMER0_CLK_CONFIGURATION;


#elif Timer0_Mode == PHASE_CORRECT_MODE
	CLEAR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);

	// Disable all interrupts
	CLEAR_BIT(TIMSK,1);
	CLEAR_BIT(TIMSK,0);

	// Set Compare Match unit Value
	OCR0 = OCR0_VALUE;
	//Configuration Output Mode

	TCCR0 &= TIMER0_CO0_MODE_MASK;
	TCCR0 &= TIMER0_CLK_MASK;
	TCCR0 |= (TIMER0_CLK_CONFIGURATION | (TIMER0_OC0_PIN_MODE << 4));


#elif Timer0_Mode == CTC_MODE
	CLEAR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

	// Turn on CTC Interrupt & Turn off OF Interrupt
	SET_BIT(TIMSK,1);
	CLEAR_BIT(TIMSK,0);

	// Set Compare Match unit Value
	OCR0 = OCR0_VALUE;
	//Configuration Output Mode
	TCCR0 &= TIMER0_CO0_MODE_MASK;
	TCCR0 &= TIMER0_CLK_MASK;
	TCCR0 |= (TIMER0_CLK_CONFIGURATION | (TIMER0_OC0_PIN_MODE << 4));


#elif Timer0_Mode == FAST_PWM_MODE
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);

	// Disable all interrupts
	CLEAR_BIT(TIMSK,1);
	CLEAR_BIT(TIMSK,0);

	// Set Compare Match unit Value
	OCR0 = OCR0_VALUE;
	//Configuration Output Mode

	TCCR0 &= TIMER0_CO0_MODE_MASK;
	TCCR0 &= TIMER0_CLK_MASK;
	TCCR0 |= (TIMER0_CLK_CONFIGURATION | (TIMER0_OC0_PIN_MODE << 4));
#else
#error "Wrong Mode Selection Configuration"
#endif

}




void MTIMER0_voidSetPreloadValue (u8 A_u8NoOfTicks)
{
	TCNT0 = A_u8NoOfTicks;
}

void MTIMER0_voidSetOCR0Value (u8 A_u8OCR0Value)
{
	OCR0 = A_u8OCR0Value;
}

u8 MTIMER0_u8ReadTimer0Value(void)
{
	return TCNT0;
}

void MTIMER0_voidStopTimer (void)
{
	TCCR0 &= 0b11111000;
}

void MTIMER0_voidSetOVFCallback (void (*A_PtrToFunc) (void))
{
	if (A_PtrToFunc != NULL)
	{
	TIMER0_OVF_CALLBACK = A_PtrToFunc;
	}
}

void MTIMER0_voidSetCTCCallback (void (*A_PtrToFunc) (void))
{
	if (A_PtrToFunc != NULL)
	{
	TIMER0_CTC_CALLBACK = A_PtrToFunc;
	}
}

//ISR




/*_____________________________________________________________________________*/

void MTIMER1_voidInit()
{
	//Select Mode 0
	CLEAR_BIT(TCCR1A,0);
	CLEAR_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1B,3);
	CLEAR_BIT(TCCR1B,4);

	//Configuration Output Mode

	TCCR1A &= TIMER1_CO1_MODE_MASK;
	TCCR1A |= (TIMER1_OC1A_PIN_MODE<<6);
	TCCR1A |= (TIMER1_OC1B_PIN_MODE<<4);

	//Set Compare Match Value

	OCR1A = OCR1A_VALUE;
	OCR1B = OCR1B_VALUE;

	//Set ICR1 value

	//ICR1 = ICR1_VALUE;



	//Configuration Clock

	TCCR1B &= TIMER1_CLK_MASK;
	TCCR1B |= TIMER1_CLK_CONFIGURATION;

}

void MTIMER1_voidSetPreloadValue (u16 A_u8NoOfTicks)
{
	TCNT1 = A_u8NoOfTicks;
}

void MTIMER1_voidSetOCR1AValue (u16 A_u16Value)
{
	OCR1A = A_u16Value;
}

void MTIMER1_voidSetICR1Value (u16 A_u16Value)
{
	ICR1 = A_u16Value;
}

void MTIMER1_voidSetOCR1BValue (u16 A_u16Value)
{
	OCR1B = A_u16Value;
}
u16 MTIMER1_u16ReadTimer1Value(void)
{
	return TCNT1;
}
u16  MTIMER1_u16ReadICR1Value(void)
{
	return ICR1;
}
void TIMER1_voidICUSetTrigger(TRIGGER_SOURCE A_TRIGGER_SOURCE)
{
	CLEAR_BIT(TCCR1B,6);
	TCCR1B |= (A_TRIGGER_SOURCE<<6);
}

void MTIMER1_voidStopTimer (void)
{
	TCCR1B &= 0b11111000;
}



void MTIMER1_voidSetOVFCallback (void (*A_PtrToFunc) (void))
{
	if (A_PtrToFunc != NULL)
	{
	TIMER1_OVF_CALLBACK = A_PtrToFunc;
	}
}

void MTIMER1_voidSetCTCACallback (void (*A_PtrToFunc) (void))
{
	if (A_PtrToFunc != NULL)
	{
	TIMER1_CTCA_CALLBACK = A_PtrToFunc;
	}
}
void MTIMER1_voidSetCTCBCallback (void (*A_PtrToFunc) (void))
{
	if (A_PtrToFunc != NULL)
	{
	TIMER1_CTCB_CALLBACK = A_PtrToFunc;
	}
}
void MTIMER1_voidSetCAPTCallback (void (*A_PtrToFunc) (void))
{
	if (A_PtrToFunc != NULL)
	{
		TIMER1_CAPT_CALLBACK = A_PtrToFunc;
	}
}


/*________________________________________________________________________________*/

void MTIMER2_voidInit()
{

//Mode Selection
#if Timer2_Mode == NORMAL_MODE
	CLEAR_BIT(TCCR2,3);
	CLEAR_BIT(TCCR2,6);

	// Turn on Overflow Interrupt & Turn off CTC Interrupt
	SET_BIT(TIMSK,6);
	CLEAR_BIT(TIMSK,7);
	//Clock Selection
	TCCR2 &= TIMER2_CLK_MASK;
	TCCR2 |= TIMER2_CLK_CONFIGURATION;


#elif Timer2_Mode == PHASE_CORRECT_MODE
	CLEAR_BIT(TCCR2,3);
	SET_BIT(TCCR2,6);

	// Disable all interrupts
	CLEAR_BIT(TIMSK,6);
	CLEAR_BIT(TIMSK,7);

	// Set Compare Match unit Value
	OCR2 = OCR2_VALUE;
	//Configuration Output Mode

	TCCR2 &= TIMER2_CO2_MODE_MASK;
	TCCR2 &= TIMER2_CLK_MASK;
	TCCR2 |= (TIMER2_CLK_CONFIGURATION | (TIMER2_OC2_PIN_MODE << 4));


#elif Timer2_Mode == CTC_MODE
	CLEAR_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);

	// Turn on CTC Interrupt & Turn off OF Interrupt
	SET_BIT(TIMSK,7);
	CLEAR_BIT(TIMSK,6);

	// Set Compare Match unit Value
	OCR2 = OCR2_VALUE;
	//Configuration Output Mode
	TCCR2 &= TIMER2_CO2_MODE_MASK;
	TCCR2 &= TIMER2_CLK_MASK;
	TCCR2 |= (TIMER2_CLK_CONFIGURATION | (TIMER2_OC2_PIN_MODE << 4));


#elif Timer2_Mode == FAST_PWM_MODE
	SET_BIT(TCCR2,3);
	SET_BIT(TCCR2,6);

	// Disable all interrupts
	CLEAR_BIT(TIMSK,6);
	CLEAR_BIT(TIMSK,7);

	// Set Compare Match unit Value
	OCR2 = OCR2_VALUE;
	//Configuration Output Mode

	TCCR2 &= TIMER2_CO2_MODE_MASK;
	TCCR2 &= TIMER2_CLK_MASK;
	TCCR2 |= (TIMER2_CLK_CONFIGURATION | (TIMER2_OC2_PIN_MODE << 4));
#else
#error "Wrong Mode Selection Configuration"
#endif

}




void MTIMER2_voidSetPreloadValue (u8 A_u8NoOfTicks)
{
	TCNT2 = A_u8NoOfTicks;
}

void MTIMER2_voidSetOCR2Value (u8 A_u8OCR0Value)
{
	OCR2 = A_u8OCR0Value;
}

u8 MTIMER2_u8ReadTimer2Value(void)
{
	return TCNT2;
}

void MTIMER2_voidStopTimer (void)
{
	TCCR2 &= 0b11111000;
}

void MTIMER2_voidSetOVFCallback (void (*A_PtrToFunc) (void))
{
	if (A_PtrToFunc != NULL)
	{
	TIMER2_OVF_CALLBACK = A_PtrToFunc;
	}
}

void MTIMER2_voidSetCTCCallback (void (*A_PtrToFunc) (void))
{
	if (A_PtrToFunc != NULL)
	{
	TIMER2_CTC_CALLBACK = A_PtrToFunc;
	}
}



/*________________________________________________________________________________________________________________*/

//Input Capture Unit HW

void MICUHW_voidInit()
{
	//Select Trigger Edge
	//Rising Edge
	TIMER1_voidICUSetTrigger(ICU_RISING_EDGE);
	//Enable Interrupt
	SET_BIT(TIMSK,5);

}


void MICUHW_voidDisable()
{
	//Disable Interrupt
	CLEAR_BIT(TIMSK,5);

}



/*______________________________________________________________________________*/


//ISR

void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	if (TIMER2_CTC_CALLBACK != NULL)
	{
		TIMER2_CTC_CALLBACK();
	}
}


void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	if (TIMER2_OVF_CALLBACK != NULL)
	{
		TIMER2_OVF_CALLBACK();
	}
}

// ISR Of ICU
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{

	if (TIMER1_CAPT_CALLBACK != NULL)
	{
		TIMER1_CAPT_CALLBACK();
	}
}

void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	if (TIMER1_CTCA_CALLBACK != NULL)
	{
		TIMER1_CTCA_CALLBACK();
	}
}

void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{
	if (TIMER1_CTCB_CALLBACK != NULL)
	{
		TIMER1_CTCB_CALLBACK();
	}
}

void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	if (TIMER1_OVF_CALLBACK != NULL)
	{
		TIMER1_OVF_CALLBACK();
	}
}
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if (TIMER0_CTC_CALLBACK != NULL)
	{
		TIMER0_CTC_CALLBACK();
	}
}
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if (TIMER0_OVF_CALLBACK != NULL)
	{
		TIMER0_OVF_CALLBACK();
	}
}





