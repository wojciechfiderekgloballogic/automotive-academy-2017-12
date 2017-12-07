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

static uint8_t g_u8rgStorage[LAMP_COUNT%8?LAMP_COUNT/8+1:LAMP_COUNT/8];

eErr_t PIOCIE_lampOn(eLamp_t eLamp)
{
	eErr_t result;
	if(eLamp<LAMP_START||eLamp>=LAMP_COUNT)
	{
		result=E_INVALID_ARG_1;
	}
	else if(NULL==g_u8rgStorage)
	{
		result=E_INVALID_ARG_2;
	}
	else
	{
		g_u8rgStorage[eLamp/8]|=(0x01<<(eLamp%8));
		printf("\nset ON %d:%d",eLamp,g_u8rgStorage[eLamp/8]);
		result=E_OK;
	}
	return result;
};

eErr_t PIOCIE_lampOff(eLamp_t eLamp)
{
	eErr_t result;
	if(eLamp<LAMP_START||eLamp>=LAMP_COUNT)
	{
		result=E_INVALID_ARG_1;
	}
	else if(NULL==g_u8rgStorage)
	{
		result=E_INVALID_ARG_2;
	}
	else
	{
		g_u8rgStorage[eLamp/8]&=~(0x01<<(eLamp%8));
		printf("\nset OFF %d:%d",eLamp,g_u8rgStorage[eLamp/8]);
		result=E_OK;
	}
	return result;
};

eErr_t PIOCIE_getLamp(eLamp_t eLamp, eLampState_t* eState)
{
	eErr_t result;
	if(eLamp<LAMP_START||eLamp>=LAMP_COUNT)
	{
		result=E_INVALID_ARG_1;
		*eState=LAMP_STATE_UNDEFINED;
	}
	else if(NULL==eState)
	{
		result=E_INVALID_ARG_2;
		*eState=LAMP_STATE_UNDEFINED;
	}
	else
	{
		if(((g_u8rgStorage[eLamp/8])&(0x01<<(eLamp%8))))
		{
			printf("\n2:");
			*eState=LAMP_STATE_ON;
		}
		else
		{
			printf("\n1:");
			*eState=LAMP_STATE_OFF;
		}
		result=E_OK;
	}
	return result;
};
