/**
 * Responsible: Michal Kaliszczyk
 *
 *
 * History log:
 * 2017.12.05   MICKAL  Initial version
 */

 
 #include "MICKAL_task2.h"
 
 
 eErr_t MICKAL_setLampeBit(eLamp_t eBit, int* piReg){
	 if(eBit < LAMP_START || eBit > LAMP_COUNT)
		 return E_INVALID_ARG_1;
	 if(piReg==NULL)
		 return E_INVALID_ARG_2;
	 
    *piReg |= 1<<eBit;
	return E_OK;
}

eErr_t MICKAL_clearLampeBit(eLamp_t eBit, int* piReg){
	if(eBit < LAMP_START || eBit > LAMP_COUNT)
		 return E_INVALID_ARG_1;
	if(piReg==NULL)
		 return E_INVALID_ARG_2;
	 
    *piReg &=~(1<<eBit);
	
	return E_OK;
}

eErr_t MICKAL_invertLampeBit(eLamp_t eBit, int* piReg){
	if(eBit < LAMP_START || eBit > LAMP_COUNT)
		 return E_INVALID_ARG_1;
	if(piReg==NULL)
		 return E_INVALID_ARG_2;

	 
    *piReg ^=1<<eBit;
	
	return E_OK;
		
}

eErr_t MICKAL_getLampState(eLamp_t eBit, int iReg, eLampState_t* peState){
	if(eBit < LAMP_START || eBit > LAMP_COUNT)
		 return E_INVALID_ARG_1;
	
	
	
	if(iReg &(1<<eBit)){
		*peState = LAMP_STATE_ON;
	}
	else
	{
		*peState = LAMP_STATE_OFF;
	}
	
	return E_OK;
}

