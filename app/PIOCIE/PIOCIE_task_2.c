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
	if(bit<LAMP_START||bit>=LAMP_COUNT)
	{
		return E_INVALID_ARG_1;
	}
	if(NULL==reg)
	{
		return E_INVALID_ARG_2;
	}
	*reg|=(0x01<<bit);
	return E_OK;
};
eErr_t PIOCIE_clearLampBit(     eLamp_t bit, int* reg    )
{
	if(bit<LAMP_START||bit>=LAMP_COUNT)
		return E_INVALID_ARG_1;
	if(NULL==reg)
		return E_INVALID_ARG_2;
	
	*reg&=~(0x01<<bit);
	return E_OK;
};
eErr_t PIOCIE_invertLampBit(    eLamp_t bit, int* reg    )
{
	if(bit<LAMP_START||bit>=LAMP_COUNT)
		return E_INVALID_ARG_1;
	if(NULL==reg)
		return E_INVALID_ARG_2;
	
	*reg^=(0x01<<bit);
	
	return E_OK;
};
eErr_t PIOCIE_getLampState(       eLamp_t bit, int reg, eLampState_t* state)
{
	if(bit<LAMP_START||bit>=LAMP_COUNT)
		return E_INVALID_ARG_1;
	if(NULL==state)
		return E_INVALID_ARG_2;
	
	if(((reg)&(0x01<<bit)))
		*state=LAMP_STATE_ON;
	else
		*state=LAMP_STATE_OFF;
	return E_OK;
};