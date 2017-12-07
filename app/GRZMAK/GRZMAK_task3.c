/**
* Responsible: Grzegorz Makowski
*
*
*History Log:
* 2017.12.07 GRZMAK initial version
*
**/

#include "GRZMAK_task3.h"
#include <stdint.h>

static uint8_t u8LampArr[(LAMP_COUNT % 8 == 0) ? (LAMP_COUNT / 8) : (LAMP_COUNT / 8) + 1];

eErr_t GRZMAK_lampOn(eLamp_t eLamp)
{
	eErr_t retval;
	if(eLamp >= LAMP_START && eLamp < LAMP_COUNT)
	{	
		u8LampArr[eLamp/8] |= 1 << (eLamp % 8); 
		retval = E_OK; 
	}
	else
	{
		retval = E_INVALID_ARG_1;
	}
	return retval;
}

eErr_t GRZMAK_lampOff(eLamp_t eLamp)
{
	eErr_t retval;
	if(eLamp >= LAMP_START && eLamp < LAMP_COUNT)
	{	
		u8LampArr[eLamp/8] &= ~(1 << (eLamp % 8)); 
		retval = E_OK; 
	}
	else
	{
		retval = E_INVALID_ARG_1;
	}
	
	return retval;	
}

eErr_t GRZMAK_getLamp(eLamp_t eLamp,eLampState_t* eState)
{
	eErr_t retval;
	if(eLamp >= LAMP_START < LAMP_COUNT)
	{
		if(u8LampArr[eLamp/8] &= 1<<eLamp)
		{
			*eState = LAMP_STATE_ON;
			retval = E_OK;
		}
		else
		{
			*eState = LAMP_STATE_OFF;
			retval = E_OK;
		}
	}
	else
	{
			retval = E_INVALID_ARG_1;
	}
	return retval;
}