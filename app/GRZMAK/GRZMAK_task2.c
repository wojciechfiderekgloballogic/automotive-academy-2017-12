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
	eErr_t retval = E_OK;
	
	if(bit < LAMP_START || bit > LAMP_COUNT)
	{
		retval = E_INVALID_ARG_1;
	}
	if(reg == NULL)
	{
		retval = E_INVALID_ARG_2;
	}
	else
	{
		*reg = (1 << bit) | *reg;
	}
	return retval;
	
}
eErr_t GRZMAK_clearLampBit( eLamp_t bit, int* reg)
{
	eErr_t retval = E_OK;
	if(bit < LAMP_START || bit > LAMP_COUNT)
	{
		retval = E_INVALID_ARG_1;
	}
	if(reg == NULL)
	{
		retval = E_INVALID_ARG_2;
	}		
	else
	{
		*reg = ~(1<<bit) & *reg;
	}	
	return retval;
}

eErr_t GRZMAK_invertLampBit( eLamp_t bit, int* reg)
{
	eErr_t retval = E_OK;
	if(bit < LAMP_START || bit > LAMP_COUNT)
	{
		retval = E_INVALID_ARG_1;
	}
	if(reg == NULL)
	{
		retval = E_INVALID_ARG_2;
	}
	else
	{
		*reg = (1 << bit) ^ *reg;
	}
	return retval;
	
}

eErr_t GRZMAK_getLampState(eLamp_t bit, int reg, eLampState_t* state)
{
	
	eErr_t retval = E_OK;
	
	if(bit < LAMP_START || bit > LAMP_COUNT)
	{
		retval = E_INVALID_ARG_1;
	}

	
	
	if(reg & (1<<bit))
	{
		*state = LAMP_STATE_ON;
	}
	else
	{
		*state = LAMP_STATE_OFF;
	}
	
	return retval;
}