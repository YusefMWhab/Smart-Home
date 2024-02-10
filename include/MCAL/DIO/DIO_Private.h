/*
 * DIO_Private.h
 *
 *  Created on: Apr 28, 2023
 *      Author: dell
 */

#ifndef INCLUDE_MCAL_DIO_DIO_PRIVATE_H_
#define INCLUDE_MCAL_DIO_DIO_PRIVATE_H_

#define PORTA_REG ( * (volatile u8 *) 0x3B ) //PORTA (0x3B)
#define DDRA_REG ( * (volatile u8 *) 0x3A ) //DDRA (0x3A)
#define PINA_REG ( * (volatile u8 *) 0x39 ) //PINA (0x39)


#define PORTB_REG ( * (volatile u8 *) 0x38 ) //PORTB (0x38)
#define DDRB_REG ( * (volatile u8 *) 0x37 ) //DDRB (0x37)
#define PINB_REG ( * (volatile u8 *) 0x36 ) //PINB (0x36)


#define PORTC_REG ( * (volatile u8 *) 0x35 ) //PORTC (0x35)
#define DDRC_REG ( * (volatile u8 *) 0x34 ) //DDRC (0x34)
#define PINC_REG ( * (volatile u8 *) 0x33 ) //PINC (0x33)


#define PORTD_REG ( * (volatile u8 *) 0x32 ) //PORTD (0x32)
#define DDRD_REG ( * (volatile u8 *) 0x31 ) //DDRD (0x31)
#define PIND_REG ( * (volatile u8 *) 0x30 ) //PIND (0x30)



#endif /* INCLUDE_MCAL_DIO_DIO_PRIVATE_H_ */
