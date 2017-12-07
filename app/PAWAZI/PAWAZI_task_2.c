/**
 * Responsible: Pawel Aziukiewicz
 *
 *
 * History log:
 *  06.12.2017 initial version
 */

#include <stdio.h>
#include "PAWAZI_task_2.h"

eErr_t PAWAZI_setLampBit(eLamp_t bit, int* reg){
	
	if(bit<LAMP_START || bit>=LAMP_COUNT){
		return E_INVALID_ARG_1;
	}else if(reg == NULL){
		return E_INVALID_ARG_2;
	}
	
	
	*reg |= 1<<bit;
	
	return E_OK;
	
	
}

eErr_t PAWAZI_clearLampBit(eLamp_t bit, int* reg){
	
	
	
	if(bit<LAMP_START || bit>=LAMP_COUNT){
		return E_INVALID_ARG_1;
	}else if(reg == NULL){
		return E_INVALID_ARG_2;
	}
	
	*reg &= ~(1<<bit);
	
	return E_OK;
	
}

eErr_t PAWAZI_invertLampBit(eLamp_t bit, int* reg){
	
	
	if(bit<LAMP_START || bit>=LAMP_COUNT){
		return E_INVALID_ARG_1;
	}else if(reg == NULL){
		return E_INVALID_ARG_2;
	}
	
	*reg ^= 1<<bit;
	
	return E_OK;
	
}

eErr_t PAWAZI_getLampState(eLamp_t bit, int reg, eLampState_t* state){
	
	if(state == NULL){
		return E_INVALID_ARG_2;
	}else if(bit<LAMP_START || bit>=LAMP_COUNT){
		return E_INVALID_ARG_1;
	} 
	
	if(((reg >> bit) & 0x01)){
		*state = LAMP_STATE_ON;
	}else *state = LAMP_STATE_OFF;	
		
	return E_OK;
}
    