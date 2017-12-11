/**
 * Responsible: Piotr Ciesielczyk
 *
 *
 * History log:
 * 2017.12.07   PioCie  Initial version that complete tests
 */

#include <stdio.h>
#include "PIOCIE_task_3.h"
#define uint8_t unsigned char
/* Every public function in your module should start with   "MODULENAME_"   prefix */
/* Every private function in your module should start with  "MODULENAME__"  prefix */

static uint8_t au8Storage[LAMP_COUNT%8?LAMP_COUNT/8+1:LAMP_COUNT/8];

eErr_t PIOCIE_lampOn(eLamp_t eLamp)
{
	eErr_t eResult;
	if(eLamp<LAMP_START||eLamp>=LAMP_COUNT)
	{
		eResult=E_INVALID_ARG_1;
	}
	else if(NULL==au8Storage)
	{
		eResult=E_INVALID_ARG_2;
	}
	else
	{
		au8Storage[eLamp/8]|=(0x01<<(eLamp%8));
		eResult=E_OK;
	}
	return eResult;
}

eErr_t PIOCIE_lampOff(eLamp_t eLamp)
{
	eErr_t eResult;
	if(eLamp<LAMP_START||eLamp>=LAMP_COUNT)
	{
		eResult=E_INVALID_ARG_1;
	}
	else if(NULL==au8Storage)
	{
		eResult=E_INVALID_ARG_2;
	}
	else
	{
		au8Storage[eLamp/8]&=~(0x01<<(eLamp%8));
		eResult=E_OK;
	}
	return eResult;
}

eErr_t PIOCIE_getLamp(eLamp_t eLamp, eLampState_t* eState)
{
	eErr_t eResult;
	if(eLamp<LAMP_START||eLamp>=LAMP_COUNT)
	{
		eResult=E_INVALID_ARG_1;
		*eState=LAMP_STATE_UNDEFINED;
	}
	else if(NULL==eState)
	{
		eResult=E_INVALID_ARG_2;
	}
	else
	{
		if(((au8Storage[eLamp/8])&(0x01<<(eLamp%8))))
		{
			*eState=LAMP_STATE_ON;
		}
		else
		{
			*eState=LAMP_STATE_OFF;
		}
		eResult=E_OK;
	}
	return eResult;
}
