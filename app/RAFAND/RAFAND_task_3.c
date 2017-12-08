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

static uint8_t arr[LAMP_COUNT%OCTA?LAMP_COUNT/OCTA+1:LAMP_COUNT];	//we allocate more memory if there LAMP_COUNT % 8 is true


//private func that check state of errors
eErr_t no__error(eLamp_t eLamp){
	eErr_t ret=E_OK;
	if(eLamp<0 || eLamp >= LAMP_COUNT){					//if arg1 is between 0 and LAMP_COUNT then it is correct arg1 
		ret E_INVALID_ARG_1;
	}
	return ret;											//else ret error
}

eErr_t RAFAND_lampOn(eLamp_t eLamp){
	eErr_t ret;
	if((ret=no__error(eLamp))==E_OK){					//if no error then true		
		arr[eLamp/OCTA] ^= 1<<eLamp%OCTA;				//set on specific bit
	}
	return ret;
}

eErr_t RAFAND_lampOff(eLamp_t eLamp){
	eErr_t ret;
	if((ret=no__error(eLamp))==E_OK){
		arr[eLamp/OCTA] &= ~(1<<eLamp%OCTA);			//set off specific bit
	}
	return ret;
}

eErr_t RAFAND_getLamp(eLamp_t eLamp, eLampState_t* state){
	*state = LAMP_STATE_UNDEFINED;						//default value of in case of errors we don't know state of lamp						
	eErr_t ret;
	if((ret=no__error(eLamp))==E_OK){					//if no errors
		if(arr[eLamp/OCTA] &= 1<<eLamp%OCTA){			//if bit is on
			*state = LAMP_STATE_ON;						//change state ON
		}
		else			
		{
			*state = LAMP_STATE_OFF;					//else change state OFF
		}
	}
	return ret;											
}
