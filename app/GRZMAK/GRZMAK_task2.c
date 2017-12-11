/**
* Responsible: Grzegorz Makowski
*
*
*History Log:
* 2017.12.06 GRZMAK initial version
*
**/


#include "GRZMAK_task2.h"



eErr_t GRZMAK_setLampBit( eLamp_t eBit, int* piReg)
{
	eErr_t eRetval = E_OK;
	
	if(eBit < LAMP_START || eBit > LAMP_COUNT)
	{
		eRetval = E_INVALID_ARG_1;
	}
	if(piReg == NULL)
	{
		eRetval = E_INVALID_ARG_2;
	}
	else
	{
		*piReg = (1 << eBit) | *piReg;
	}
	return eRetval;
	
}
eErr_t GRZMAK_clearLampBit( eLamp_t eBit, int* piReg)
{
	eErr_t eRetval = E_OK;
	if(eBit < LAMP_START || eBit > LAMP_COUNT)
	{
		eRetval = E_INVALID_ARG_1;
	}
	if(piReg == NULL)
	{
		eRetval = E_INVALID_ARG_2;
	}		
	else
	{
		*piReg = ~(1<<eBit) & *piReg;
	}	
	return eRetval;
}

eErr_t GRZMAK_invertLampBit( eLamp_t eBit, int* piReg)
{
	eErr_t eRetval = E_OK;
	if(eBit < LAMP_START || eBit > LAMP_COUNT)
	{
		eRetval = E_INVALID_ARG_1;
	}
	if(piReg == NULL)
	{
		eRetval = E_INVALID_ARG_2;
	}
	else
	{
		*piReg = (1 << eBit) ^ *piReg;
	}
	return eRetval;
	
}

eErr_t GRZMAK_getLampState(eLamp_t eBit, int iReg, eLampState_t* eState)
{
	
	eErr_t eRetval = E_OK;
	
	if(eBit < LAMP_START || eBit > LAMP_COUNT)
	{
		eRetval = E_INVALID_ARG_1;
	}

	
	
	if(iReg & (1<<eBit))
	{
		*eState = LAMP_STATE_ON;
	}
	else
	{
		*eState = LAMP_STATE_OFF;
	}
	
	return eRetval;
}