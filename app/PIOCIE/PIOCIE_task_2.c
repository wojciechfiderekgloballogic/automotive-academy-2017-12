/**
 * Responsible: Piotr Ciesielczyk
 *
 *
 * History log:
 * 2017.12.06   PioCie  Initial version that complete tests
 */

#include <stdio.h>
#include "PIOCIE_task_2.h"

/* Every public function in your module should start with   "MODULENAME_"   prefix */
/* Every private function in your module should start with  "MODULENAME__"  prefix */

eErr_t PIOCIE_setLampBit( eLamp_t bit, int* reg)
{
	eErr_t result;
	if(bit<LAMP_START||bit>=LAMP_COUNT)
	{
		result=E_INVALID_ARG_1;
	}
	else if(NULL==reg)
	{
		result=E_INVALID_ARG_2;
	}
	else
	{
		*reg|=(0x01<<bit);
		result=E_OK;
	}
	return result;
};
eErr_t PIOCIE_clearLampBit(     eLamp_t bit, int* reg    )
{
	eErr_t result;
	if(bit<LAMP_START||bit>=LAMP_COUNT)
	{
		result=E_INVALID_ARG_1;
	}
	else if(NULL==reg)
	{
		result=E_INVALID_ARG_2;
	}
	else
	{
		*reg&=~(0x01<<bit);
		result=E_OK;
	}
	return result;
};
eErr_t PIOCIE_invertLampBit(    eLamp_t bit, int* reg    )
{
	eErr_t result;
	if(bit<LAMP_START||bit>=LAMP_COUNT)
	{
		result=E_INVALID_ARG_1;
	}
	else if(NULL==reg)
	{
		result=E_INVALID_ARG_2;
	}
	else
	{
		*reg^=(0x01<<bit);
		result=E_OK;
	}
	return result;
};
eErr_t PIOCIE_getLampState(       eLamp_t bit, int reg, eLampState_t* state)
{
	eErr_t result;
	if(bit<LAMP_START||bit>=LAMP_COUNT)
	{
		result=E_INVALID_ARG_1;
	}
	else if(NULL==state)
	{
		result=E_INVALID_ARG_2;
	}
	else
	{
		if(((reg)&(0x01<<bit)))
		{
			*state=LAMP_STATE_ON;
		}
		else
		{
			*state=LAMP_STATE_OFF;
		}
		result=E_OK;
	}
	return result;
};