/**
 * Responsible: Jaroslaw Kurzynski
 *
 *
 * History log:
 * 2017.12.08   jarkur initial version
 */

#include <stdio.h>
#include "JARKUR_task3.h"
#include <stdint.h>
static uint8_t u8Lamps[LAMP_COUNT % 8 ? (int)(LAMP_COUNT/8 + 1) : LAMP_COUNT/8];

eErr_t JARKUR_lampOn(eLamp_t eLamp) {
		eErr_t flag = E_OK;
		if (eLamp < LAMP_START || eLamp >= LAMP_COUNT) {
				flag = E_INVALID_ARG_1;
		}else { 
				int iIndex = eLamp / 8;
				int iPos = eLamp % 8;
				int iMask = 1;
				iMask = iMask << iPos;
				u8Lamps[iIndex] |= iMask;
		}	
		return flag;
}
eErr_t JARKUR_lampOff(eLamp_t eLamp) {
		eErr_t flag = E_OK;
		if (eLamp < LAMP_START || eLamp >= LAMP_COUNT) {
				flag = E_INVALID_ARG_1;
		}else { 

				int iIndex = eLamp / 8;
				int iPos = eLamp % 8;
				int iMask = 1;
				iMask = iMask << iPos;
				u8Lamps[iIndex] &= ~iMask;
		}	
		return flag;
}
eErr_t JARKUR_getLamp(eLamp_t eLamp, eLampState_t* eState) {
			eErr_t eFlag = E_OK;
			int iIndex = eLamp/8;
			int iPos = eLamp % 8;
			int iMask = 1;
			iMask = iMask << iPos;
			if (eLamp < LAMP_START || eLamp >= LAMP_COUNT) {
				eFlag = E_INVALID_ARG_1;
			}else {
				u8Lamps[iIndex & iPos];
			}
		 return eFlag;
}

