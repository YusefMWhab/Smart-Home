/*
 * Timers_Private.h
 *
 *  Created on: Jul 2, 2023
 *      Author: dell
 */

#ifndef INCLUDE_MCAL_TIMERS_TIMERS_PRIVATE_H_
#define INCLUDE_MCAL_TIMERS_TIMERS_PRIVATE_H_

//Define Registers

#define TIMSK   (*(volatile u8 *) 0x59)
#define TIFR   (*(volatile u8 *) 0x58)

//Timer 0 Registers
#define OCR0   (*(volatile u8 *) 0x5C)
#define TCCR0   (*(volatile u8 *) 0x53)
#define TCNT0   (*(volatile u8 *) 0x52)

//Timer 1 Registers
#define TCCR1A   (*(volatile u8 *) 0x4F)
#define TCCR1B   (*(volatile u8 *) 0x4E)
#define TCNT1H   (*(volatile u8 *) 0x4D)
#define TCNT1L   (*(volatile u8 *) 0x4C)
#define TCNT1    (*(volatile u16 *) 0x4C)
#define OCR1AH   (*(volatile u8 *) 0x4B)
#define OCR1AL   (*(volatile u8 *) 0x4A)
#define OCR1A    (*(volatile u16 *) 0x4A)
#define OCR1BH   (*(volatile u8 *) 0x49)
#define OCR1BL   (*(volatile u8 *) 0x48)
#define OCR1B    (*(volatile u16 *) 0x48)
#define ICR1H    (*(volatile u8 *) 0x47)
#define ICR1L    (*(volatile u8 *) 0x46)
#define ICR1     (*(volatile u16 *) 0x46)

//Timer 2 Registers
#define OCR2   (*(volatile u8 *) 0x43)
#define TCCR2   (*(volatile u8 *) 0x45)
#define TCNT2   (*(volatile u8 *) 0x44)



#define TIMER0_CLK_MASK			 0b11111000
#define TIMER0_CO0_MODE_MASK	 0b11001111
#define TIMER1_CLK_MASK 		 0b11111000
#define TIMER1_CO1_MODE_MASK	 0b00001111
#define TIMER2_CLK_MASK			 0b11111000
#define TIMER2_CO2_MODE_MASK	 0b11001111

#endif /* INCLUDE_MCAL_TIMERS_TIMERS_PRIVATE_H_ */
