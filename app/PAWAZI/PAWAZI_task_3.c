/**
 * Responsible: Paw Azi
 *
 *
 * History log:
 *  06.12.2017 initial version
 */

#include <stdio.h>
#include "PAWAZI_task_3.h"

static uint8_t _uiStorage[ (LAMP_COUNT%2) ? ((int)(LAMP_COUNT/8)+1) : (LAMP_COUNT/8) ];

eErr_t PAWAZI_lampOn(eLamp_t eLamp){
	
	eErr_t eRes = E_OK;
	
	if(eLamp<LAMP_START || eLamp>=LAMP_COUNT){
		eRes = E_INVALID_ARG_1;
	}else {
		_uiStorage[eLamp/8] |= 1<<(eLamp%8);
	}
	
	return eRes;
	
}


eErr_t PAWAZI_lampOff(eLamp_t eLamp){
	
	eErr_t eRes = E_OK;
	
	if(eLamp<LAMP_START || eLamp>=LAMP_COUNT){
		eRes = E_INVALID_ARG_1;
	}else {
		_uiStorage[eLamp/8] &= ~(1<<(eLamp%8));
	}
	
	return eRes;
	
}


eErr_t PAWAZI_getLamp(eLamp_t eLamp, eLampState_t* eState){

	eErr_t eRes = E_OK;
	
	if(eLamp<LAMP_START || eLamp>=LAMP_COUNT){
		eRes = E_INVALID_ARG_1;
	}else if(eState == NULL){
		eRes = E_INVALID_ARG_2;
	}else if((_uiStorage[eLamp/8]>>(eLamp%8)) & 0x1){
		*eState = LAMP_STATE_ON;
	}else{
		*eState = LAMP_STATE_OFF;
	}

	return eRes;
	
}