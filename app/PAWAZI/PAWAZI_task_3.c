/**
 * Responsible: Pawel Aziukiewicz
 *
 *
 * History log:
 *  06.12.2017 initial version
 */

#include <stdio.h>
#include "PAWAZI_task_3.h"

static const enum eErr resErr[] = { E_OK, E_INVALID_ARG_1, E_INVALID_ARG_2, E_NOT_IMPLEMENTED, E_MALLOC };

static uint8_t _uiStorage[(LAMP_COUNT/8)+1];

eErr_t PAWAZI_lampOn(eLamp_t eLamp){
	
	int res = 0;
	
	if(eLamp<LAMP_START || eLamp>=LAMP_COUNT){
		res = 1;
	}else{
		_uiStorage[eLamp/8] = 1<<(eLamp%8);
	}
	
	return resErr[res];
	
}


eErr_t PAWAZI_lampOff(eLamp_t eLamp){
	
	int res = 0;
	
	if(eLamp<LAMP_START || eLamp>=LAMP_COUNT){
		res = 1;
	}else{
		_uiStorage[eLamp/8] = ~(1<<(eLamp%8));
	}
	
	return resErr[res];
	
}


eErr_t PAWAZI_getLamp(eLamp_t eLamp, eLampState_t* eState){

	int res = 0;
	
	if(eLamp<LAMP_START || eLamp>=LAMP_COUNT){
		res = 1;
	}else{
		if((_uiStorage[eLamp/8]>>(eLamp%8)) & 0x1){
			*eState = LAMP_STATE_ON;
		}else{
			*eState = LAMP_STATE_OFF;
		}
	}
	
	return resErr[res];
	
}