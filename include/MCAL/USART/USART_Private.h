/*
 * USART_Private.h
 *
 *  Created on: Aug 1, 2023
 *      Author: dell
 */

#ifndef INCLUDE_MCAL_USART_USART_PRIVATE_H_
#define INCLUDE_MCAL_USART_USART_PRIVATE_H_

//Registers:
#define UDR   ( * (volatile u8 *) 0x2C )

#define UCSRA ( * (volatile u8 *) 0x2B )
#define UCSRB ( * (volatile u8 *) 0x2A )
#define UCSRC ( * (volatile u8 *) 0x40 )

#define UBRRH ( * (volatile u8 *) 0x40 )
#define UBRRL ( * (volatile u8 *) 0x29 )

// Bits:
// UCSRA Bits:
#define UCSRA_RXC     7
#define UCSRA_TXC     6
#define UCSRA_UDRE    5
#define UCSRA_FE      4
#define UCSRA_DOR     3
#define UCSRA_PE      2
#define UCSRA_U2X     1
#define UCSRA_MPCM    0

// UCSRB Bits:
#define UCSRB_RXCIE   7
#define UCSRB_TXCIE   6
#define UCSRB_UDRIE   5
#define UCSRB_RXEN    4
#define UCSRB_TXEN    3
#define UCSRB_UCSZ2   2
#define UCSRB_RXB8    1
#define UCSRB_TXB8    0


// UCSRC Bits:
#define UCSRC_URSEL   7
#define UCSRC_UMSEL   6
#define UCSRC_UPM1    5
#define UCSRC_UPM0    4
#define UCSRC_USBS    3
#define UCSRC_UCSZ1   2
#define UCSRC_UCSZ0   1
#define UCSRC_UCPOL   0

#define Asynchronous_Operation 0
#define Synchronous_Operation  1

#define Parity_Disable 0
#define Parity_Even    2
#define Parity_Odd     3

#define USBS1   0
#define USBS2   1




#endif /* INCLUDE_MCAL_USART_USART_PRIVATE_H_ */
