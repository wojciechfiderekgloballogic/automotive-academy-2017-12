/**
 * Responsible: Michal Kaliszczyk
 *
 *
 * History log:
 * 2017.12.05   MICKAL  Initial version
 */

 
 #include "MICKAL_task2.h"
 
 
 eErr_t MICKAL_setLampBit(eLamp_t bit, int* reg){
	 if(bit < LAMP_START || bit > LAMP_COUNT)
		 return E_INVALID_ARG_1;
	 
    *reg |= 1<<bit;
	return E_OK;
}

eErr_t MICKAL_clearLampBit(eLamp_t bit, int* reg){
	if(bit < LAMP_START || bit > LAMP_COUNT)
		 return E_INVALID_ARG_1;
	 
    *reg &=~(1<<bit);
	
	return E_OK;
}

eErr_t MICKAL_invertLampBit(eLamp_t bit, int* reg){
	if(bit < LAMP_START || bit > LAMP_COUNT)
		 return E_INVALID_ARG_1;

	 
    *reg ^=1<<bit;
	
	return E_OK;
		
}

eErr_t MICKAL_getLampState(eLamp_t bit, int reg, eLampState_t* state){
	if(bit < LAMP_START || bit > LAMP_COUNT)
		 return E_INVALID_ARG_1;
	
	
	if(reg &(1<<bit)){
		*state = LAMP_STATE_ON;
		return E_OK;
	}
	else
	{
		*state = LAMP_STATE_OFF;
		return E_OK;
	}
}

