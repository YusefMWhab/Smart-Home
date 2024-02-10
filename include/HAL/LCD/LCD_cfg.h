/*
 * LCD_cfg.h
 *
 *  Created on: Apr 29, 2023
 *      Author: dell
 */

#ifndef INCLUDE_HAL_LCD_LCD_CFG_H_
#define INCLUDE_HAL_LCD_LCD_CFG_H_

#define LCD_DATA_PORT PORTC
#define LCD_CONTROL_PORT PORTD

#define LCD_RS_PIN PIN5
#define LCD_RW_PIN PIN4
#define LCD_E_PIN  PIN3

// 1 -->8-bit mode
// 0 -->4-bit mode
#define DATA_LENGTH 1 // DL

// 0 -->one line
// 1 -->two line
#define NO_OF_LINES 1 //N

// 0 --> 5x7 px
// 0 --> 5x10 px
#define CHAR_FONT 0 //F

// 0 --> OFF
// 1 --> ON
#define DISPLAY_ON 1 //D

// 0 --> OFF
// 1 --> ON
#define CURSOR_DISPLAY 1 //C

// 0 --> OFF
// 1 --> ON
#define CURSOR_BLINK 1 //B

// 0 --> To the left
// 1 --> To The right
#define I_D 1 //ID

 // 0 --> Fixed
// 1 --> Shifted
#define SHIFT 0 //SH

// 0 --> Shift the cursor position
// 1 --> Shift the Entire Display
#define SC 0

// 0 --> To the Left
// 1 --> To the Right
#define RL 0


#endif /* INCLUDE_HAL_LCD_LCD_CFG_H_ */
