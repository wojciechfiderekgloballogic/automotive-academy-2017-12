/**
 * Responsible: Paw Azi
 *
 *
 * History log:
 *  06.12.2017 initial version
 */

#include <stdio.h>
#include "PAWAZI_task_2.h"


eErr_t PAWAZI_setLampBit(eLamp_t bit, int* reg){

	eErr_t res = E_OK;
	
	if(bit<LAMP_START || bit>=LAMP_COUNT){
		res = E_INVALID_ARG_1;
	}else if(reg == NULL){
		res = E_INVALID_ARG_2;
	}
	
	if(!res){
		*reg |= 1<<bit;
	}
	
	return res;
	
	
}

eErr_t PAWAZI_clearLampBit(eLamp_t bit, int* reg){
	
	eErr_t res = E_OK;
	
	if(bit<LAMP_START || bit>=LAMP_COUNT){
		res = E_INVALID_ARG_1;
	}else if(reg == NULL){
		res = E_INVALID_ARG_2;
	}
	
	if(!res){
		*reg &= ~(1<<bit);
	}
	
	return res;
	
}

eErr_t PAWAZI_invertLampBit(eLamp_t bit, int* reg){
	
	
	eErr_t res = E_OK;
	
	if(bit<LAMP_START || bit>=LAMP_COUNT){
		res = E_INVALID_ARG_1;
	}else if(reg == NULL){
		res = E_INVALID_ARG_2;
	}
	
	if(!res){
		*reg ^= 1<<bit;
	}
	
	return res;
	
}

eErr_t PAWAZI_getLampState(eLamp_t bit, int reg, eLampState_t* state){
	
	eErr_t res = E_OK;
	
	if(bit<LAMP_START || bit>=LAMP_COUNT){
		res = E_INVALID_ARG_1;
	}else if(state == NULL){
		res = E_INVALID_ARG_2;
	}

	if(!res){
		if(((reg >> bit) & 0x01)){
			*state = LAMP_STATE_ON;
		}else *state = LAMP_STATE_OFF;	
	}

	return res;
}
    