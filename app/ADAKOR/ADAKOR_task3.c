/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.06   ADAKOR  Initial version
 */

#include "ADAKOR_task3.h"
#include "stdint.h"

/* Every public function in your module should start with   "MODULENAME_"   prefix */
/* Every private function in your module should start with  "MODULENAME__"  prefix */

static uint8_t arru8Storage [(LAMP_COUNT % 8) ? LAMP_COUNT / 8 + 1 : LAMP_COUNT / 8];

eErr_t ADAKOR_lampOn(eLamp_t eLamp)
{
	eErr_t eResult;
	if (eLamp >= LAMP_START && eLamp <= LAMP_COUNT)
	{
		arru8Storage[eLamp / 8] |= (1 << eLamp % 8);
		eResult = E_OK;
	}
	else
	{
		eResult = E_INVALID_ARG_1;
	}
	return eResult;
}

eErr_t ADAKOR_lampOff(eLamp_t eLamp)
{
	eErr_t eResult;
	if (eLamp >= LAMP_START && eLamp <= LAMP_COUNT)
	{
		arru8Storage[eLamp / 8] &= ~(1 << eLamp % 8);
		eResult = E_OK;
	}
	else
	{
		eResult = E_INVALID_ARG_1;
	}
	return eResult;
}

eErr_t ADAKOR_getLamp(eLamp_t eLamp, eLampState_t* eState)
{
	eErr_t eResult;
	if (eState == 0)
	{
		eResult = E_INVALID_ARG_2;
	}
	else
	{
		if (eLamp >= LAMP_START && eLamp <= LAMP_COUNT)
		{
			if ((arru8Storage[eLamp / 8]) & (1 << eLamp % 8))
			{
				*eState = LAMP_STATE_ON;
			}
			else
			{
				*eState = LAMP_STATE_OFF;
			}
			eResult = E_OK;
		}
		else
		{
			*eState = LAMP_STATE_UNDEFINED;
			eResult = E_INVALID_ARG_1;
		}
	}
	return eResult;
}