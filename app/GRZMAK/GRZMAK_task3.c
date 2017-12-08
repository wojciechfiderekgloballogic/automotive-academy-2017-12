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
	eErr_t eRetval;
	if(eLamp >= LAMP_START && eLamp < LAMP_COUNT)
	{	
		u8LampArr[eLamp/8] |= 1 << (eLamp % 8); 
		eRetval = E_OK; 
	}
	else
	{
		eRetval = E_INVALID_ARG_1;
	}
	return eRetval;
}

eErr_t GRZMAK_lampOff(eLamp_t eLamp)
{
	eErr_t eRetval;
	if(eLamp >= LAMP_START && eLamp < LAMP_COUNT)
	{	
		u8LampArr[eLamp/8] &= ~(1 << (eLamp % 8)); 
		eRetval = E_OK; 
	}
	else
	{
		eRetval = E_INVALID_ARG_1;
	}
	
	return eRetval;	
}

eErr_t GRZMAK_getLamp(eLamp_t eLamp,eLampState_t* eState)
{
	eErr_t eRetval;
	if(eLamp >= LAMP_START < LAMP_COUNT)
	{
		if(u8LampArr[eLamp/8] & 1<<eLamp)
		{
			*eState = LAMP_STATE_ON;
			eRetval = E_OK;
		}
		else
		{
			*eState = LAMP_STATE_OFF;
			eRetval = E_OK;
		}
	}
	else
	{
			eRetval = E_INVALID_ARG_1;
	}
	return eRetval;
}