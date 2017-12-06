/**
 * Responsible: Pawel Aziukiewicz
 *
 *
 * History log:
 */

#include <stdio.h>
#include "PAWAZI_interface.h"

eErr_t PAWAZI_setLampBit(eLamp_t bit, int* reg){
	
	if(bit<0&&bit>sizeof(int)*8){
		return E_INVALID_ARG_1;
	}
	
	*reg |= 1<<bit;
	
	return E_OK;
	
}

eErr_t PAWAZI_clearLampBit(eLamp_t bit, int* reg){
	
	if(bit<0&&sizeof(int)*8){
		return E_INVALID_ARG_1;
	}
	
	*reg &= ~(1<<bit);
	
	return E_OK;
	
}

eErr_t PAWAZI_invertLampBit(eLamp_t bit, int* reg){
	
	if(bit<0&&bit>sizeof(int)*8){
		return E_INVALID_ARG_1;
	}
	
	*reg ^= 1<<bit;
	
	return E_OK;
	
}

eErr_t PAWAZI_getLampState(eLamp_t bit, int reg, eLampState_t* state){
	
	if(((reg >> bit)  & 0x01)){
		*state = LAMP_STATE_ON;
	}else *state = LAMP_STATE_OFF;	
	
	
}
    