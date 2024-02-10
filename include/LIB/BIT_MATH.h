/*
 * BIT_MATH.h
 *
 *  Created on: Apr 28, 2023
 *      Author: dell
 */

#ifndef INCLUDE_LIB_BIT_MATH_H_
#define INCLUDE_LIB_BIT_MATH_H_

#define SET_BIT(REG,BITNo) (REG |=(1<<BITNo))
#define CLEAR_BIT(REG,BITNo) (REG &=(~(1<<BITNo)))
#define TOGGLE_BIT(REG,BITNo) (REG ^=(1<<BITNo))
#define GET_BIT(REG,BITNo) ((REG>>BITNo)&1)
/*0b0111001
  CONC_BIT(0,1,1,1,0,0,1); */
#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) CONC_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0


#endif /* INCLUDE_LIB_BIT_MATH_H_ */
