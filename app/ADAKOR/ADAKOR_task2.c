/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.06   ADAKOR  Initial version
 */

#include "ADAKOR_task2.h"

/* Every public function in your module should start with   "MODULENAME_"   prefix */
/* Every private function in your module should start with  "MODULENAME__"  prefix */

eErr_t ADAKOR_setLampBit(eLamp_t bit, int* reg)
{
	if (bit >= LAMP_START && bit <= LAMP_COUNT)
	{
		*reg = (1 << bit) | *reg;
		return E_OK;
	}
	else
	{
		return E_INVALID_ARG_1;
	}
}

eErr_t ADAKOR_clearLampBit(eLamp_t bit, int* reg)
{
	if (bit >= LAMP_START && bit <= LAMP_COUNT)
	{
		*reg &= ~(1 << bit);
		return E_OK;
	}
	else
	{
		return E_INVALID_ARG_1;
	}
}

eErr_t ADAKOR_invertLampBit(eLamp_t bit, int* reg)
{
	if (bit >= LAMP_START && bit <= LAMP_COUNT)
	{
		*reg ^= (1 << bit);
		return E_OK;
	}
	else
	{
		return E_INVALID_ARG_1;
	}
}

eErr_t ADAKOR_getLampState(eLamp_t bit, int reg, eLampState_t* state)
{
	if (bit >= LAMP_START && bit < LAMP_COUNT)
	{
		if ((reg & (1 << bit)) != 0)
		{
			*state = LAMP_STATE_ON;
		}
		else
		{
			*state = LAMP_STATE_OFF;
		}
		return E_OK;
	}
	else
	{
		return E_INVALID_ARG_1;
	}
}