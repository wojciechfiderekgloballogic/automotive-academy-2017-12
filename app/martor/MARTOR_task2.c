/**
 * Responsible: Marcin Torchala
 *
 *
 * History log:
 * 2017.12.06	MarTor	Initial Edit
 */
 
 #include "../app/common/COMMON_interface.h"
 #include "MARTOR_example.h"
 #include "MARTOR_task2.h"
 
eErr_t MARTOR_setLampBit(eLamp_t bit, int* reg)
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

eErr_t MARTOR_clearLampBit(eLamp_t bit, int* reg)
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

eErr_t MARTOR_invertLampBit(eLamp_t bit, int* reg)
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

eErr_t MARTOR_getLampState(eLamp_t bit, int reg, eLampState_t* state)
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