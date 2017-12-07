/**
 * Responsible: Pawel Aziukiewicz
 *
 *
 * History log:
 *  06.12.2017 initial version
 */

#include <stdio.h>
#include "PAWAZI_task_2.h"

static const enum eErr resErr[] = { E_OK, E_INVALID_ARG_1, E_INVALID_ARG_2, E_NOT_IMPLEMENTED, E_MALLOC };

eErr_t PAWAZI_setLampBit(eLamp_t bit, int* reg){

	int res = 0;
	
	if(bit<LAMP_START || bit>=LAMP_COUNT){
		res = 1;
	}else if(reg == NULL){
		res = 2;
	}else{
		*reg |= 1<<bit;
	}
	
	return resErr[res];
	
	
}

eErr_t PAWAZI_clearLampBit(eLamp_t bit, int* reg){
	
	int res = 0;
	
	if(bit<LAMP_START || bit>=LAMP_COUNT){
		res = 1;
	}else if(reg == NULL){
		res = 2;
	}else{
		*reg &= ~(1<<bit);
	}
	
	return resErr[res];
	
}

eErr_t PAWAZI_invertLampBit(eLamp_t bit, int* reg){
	
	
	int res = 0;
	
	if(bit<LAMP_START || bit>=LAMP_COUNT){
		res = 1;
	}else if(reg == NULL){
		res = 2;
	}else{
		*reg ^= 1<<bit;
	}
	
	return resErr[res];
	
}

eErr_t PAWAZI_getLampState(eLamp_t bit, int reg, eLampState_t* state){
	
	int res = 0;
	
	if(bit<LAMP_START || bit>=LAMP_COUNT){
		res = 1;
	}else if(state == NULL){
		res = 2;
	}
		
	if(((reg >> bit) & 0x01)){
		*state = LAMP_STATE_ON;
	}else *state = LAMP_STATE_OFF;	

		
	return resErr[res];
}
    