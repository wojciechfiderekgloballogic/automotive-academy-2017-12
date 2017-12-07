/**
* Responsible: Grzegorz Makowski
*
*
*History Log:
* 2017.12.06 GRZMAK initial version
*
**/


#include "GRZMAK_task2.h"



eErr_t GRZMAK_setLampBit( eLamp_t bit, int* reg)
{
	if(bit < LAMP_START || bit >= LAMP_COUNT)
	{
		return E_INVALID_ARG_1;
	}
	if(reg == NULL)
	{
		return E_INVALID_ARG_2;
	}
	
	*reg = (1 << bit) | *reg;	
	return E_OK;
	
}
eErr_t GRZMAK_clearLampBit( eLamp_t bit, int* reg)
{
	if(bit < LAMP_START || bit >= LAMP_COUNT)
	{
		return E_INVALID_ARG_1;
	}
	if(reg == NULL)
	{
		return E_INVALID_ARG_2;
	}
	
	*reg = ~(1<<bit) & *reg;
	return E_OK;
	
}

eErr_t GRZMAK_invertLampBit( eLamp_t bit, int* reg)
{
	if(bit < LAMP_START || bit >= LAMP_COUNT)
	{
		return E_INVALID_ARG_1;
	}
	if(reg == NULL)
	{
		return E_INVALID_ARG_2;
	}
	
	*reg = (1 << bit) ^ *reg;
	return E_OK;
	
}

eErr_t GRZMAK_getLampState(eLamp_t bit, int reg, eLampState_t* state)
{
	if(bit < LAMP_START || bit >= LAMP_COUNT)
	{
		return E_INVALID_ARG_1;
	}

	
	
	if(reg & (1<<bit))
	{
		*state = LAMP_STATE_ON;
		return E_OK;
	}
	else
	{
		*state = LAMP_STATE_OFF;
		return E_OK;
	}
}