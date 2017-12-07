/**
 * Responsible: Michal Kaliszczyk
 *
 *
 * History log:
 * 2017.12.05   MICKAL  Initial version
 */

 
 #include "MICKAL_task2.h"
 
 
 eErr_t MICKAL_setLampBit(eLamp_t bit, int* reg){
	 
	 eErr_t t = E_OK;
	 
	 if(bit < LAMP_START || bit > LAMP_COUNT)
		 t =  E_INVALID_ARG_1;
	 if(reg==NULL)
		 t = E_INVALID_ARG_2;
	 else
		*reg |= 1<<bit;
	
	return t;
}

eErr_t MICKAL_clearLampBit(eLamp_t bit, int* reg){
	 eErr_t t = E_OK;
	 
	if(bit < LAMP_START || bit > LAMP_COUNT)
		 t = E_INVALID_ARG_1;
	if(reg==NULL)
		 t = E_INVALID_ARG_2;
	 else
		*reg &=~(1<<bit);
	
	return t;
}

eErr_t MICKAL_invertLampBit(eLamp_t bit, int* reg){
	 eErr_t t = E_OK;
	if(bit < LAMP_START || bit > LAMP_COUNT)
		 t = E_INVALID_ARG_1;
	if(reg == NULL)
		 t = E_INVALID_ARG_2;
	else	 
		*reg ^=1<<bit;
	
	return t;
		
}

eErr_t MICKAL_getLampState(eLamp_t bit, int reg, eLampState_t* state){
	 eErr_t t = E_OK;
	 
	if(bit < LAMP_START || bit > LAMP_COUNT)
		 t = E_INVALID_ARG_1;
	
	
	
	if(reg &(1<<bit)){
		*state = LAMP_STATE_ON;
	}
	else
	{
		*state = LAMP_STATE_OFF;
	}
	
	return t;
}


