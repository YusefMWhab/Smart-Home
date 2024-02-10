/*
 * GI_Program.c
 *
 *  Created on: May 30, 2023
 *      Author: dell
 */
#include "..\include\LIB\BIT_MATH.h"
#include "..\include\LIB\STD_TYPES.h"

#include "..\include\MCAL\GI\GI_Interface.h"
#include "..\include\MCAL\GI\GI_Private.h"
#include "..\include\MCAL\GI\GI_cfg.h"

void MGI_voidEnable(void)
{
	SET_BIT(SREG,GLOBAL_INTERRUPT_ENABLE_BIT);
}



void MGI_voidDisable(void)
{
	CLEAR_BIT(SREG,GLOBAL_INTERRUPT_ENABLE_BIT);
}

