/**
 * Responsible: Rafal Andrukajtis
 *
 *
 * History log:
 * 2017.12.07	RafAnd	Array implementation
 * 2017.12.01   RafAnd  My version
 */


#define OCTA 8

#include <stdio.h>
#include <stdint.h>

#include "RAFAND_task_3.h"

/* Every public function in your module should start with   "MODULENAME_"   prefix */
/* Every private function in your module should start with  "MODULENAME__"  prefix */

static uint8_t srgu8Arr[LAMP_COUNT%OCTA?LAMP_COUNT/OCTA+1:LAMP_COUNT];	//we allocate more memory if there LAMP_COUNT % 8 is true


//private func that check state of errors
eErr_t eNo__error(eLamp_t eLamp){
	eErr_t eRet=E_OK;
	if(eLamp<0 || eLamp >= LAMP_COUNT){					//if arg1 is between 0 and LAMP_COUNT then it is correct arg1 
		eRet = E_INVALID_ARG_1;
	}
	return eRet;											//else ret error
}

eErr_t RAFAND_lampOn(eLamp_t eLamp){
	eErr_t eRet;
	if((eRet=eNo__error(eLamp))==E_OK){					//if no error then true		
		srgu8Arr[eLamp/OCTA] ^= 1<<eLamp%OCTA;				//set on specific bit
	}
	return eRet;
}

eErr_t RAFAND_lampOff(eLamp_t eLamp){
	eErr_t eRet;
	if((eRet=eNo__error(eLamp))==E_OK){
		srgu8Arr[eLamp/OCTA] &= ~(1<<eLamp%OCTA);			//set off specific bit
	}
	return eRet;
}

eErr_t RAFAND_getLamp(eLamp_t eLamp, eLampState_t* peState){
	if(peState == NULL){
		*peState = LAMP_STATE_UNDEFINED;						//default value of in case of errors we don't know state of lamp						
		eErr_t eRet;
		if((eRet=eNo__error(eLamp))==E_OK){					//if no errors
			if(srgu8Arr[eLamp/OCTA] &= 1<<eLamp%OCTA){			//if bit is on
				*peState = LAMP_STATE_ON;						//change state ON
			}
			else			
			{
				*peState = LAMP_STATE_OFF;					//else change state OFF
			}
		}
	}
	return eRet;											
}
