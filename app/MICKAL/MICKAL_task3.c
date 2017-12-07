/**
 * Responsible: Michal Kaliszczyk
 *
 *
 * History log:
 * 2017.12.05   MICKAL  Initial version
 */

 
 #include "MICKAL_task3.h"
 
 
static uint8_t storage[(LAMP_COUNT % 8 == 0) ? (LAMP_COUNT/8) : (LAMP_COUNT/8)+1];
 
 eErr_t MICKAL_lampOn(eLamp_t eLamp){
	 
	 eErr_t t = E_OK;
	 
	 if(eLamp >= LAMP_START && eLamp < LAMP_COUNT)
	 {
		storage[eLamp/8] |= 1 <<eLamp%8;
	 }
	 else
	 {
		 t = E_INVALID_ARG_1;
	 }
	 
	 return t; 
 }
 
 eErr_t MICKAL_lampOff(eLamp_t eLamp)
 {
	 
	 eErr_t t = E_OK;
	 
	 if(eLamp >= LAMP_START && eLamp < LAMP_COUNT)
	 {
		storage[eLamp/8] &=~(1<<eLamp%8);
	 }
	 else
	 {
		 t = E_INVALID_ARG_1;
	 }
	 
	 return t;  
 }
 
 eErr_t MICKAL_getLamp(eLamp_t eLamp, eLampState_t* eState)
 {
	 
	 eErr_t t = E_OK;
	 
	 if(eLamp >= LAMP_START && eLamp < LAMP_COUNT)
	 {
		if(storage[eLamp/8]&(1<<eLamp%8))
		{
			*state = LAMP_STATE_ON;
		}
		else
		{
			*state = LAMP_STATE_OFF;
		}
	 }
	 else
	 {
		 t = E_INVALID_ARG_1;
	 }
	 
	 
	 return t; 
	 
 }
 
 