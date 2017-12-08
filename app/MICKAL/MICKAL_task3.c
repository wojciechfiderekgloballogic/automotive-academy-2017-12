/**
 * Responsible: Michal Kaliszczyk
 *
 *
 * History log:
 * 2017.12.05   MICKAL  Initial version
 */

 
 #include "MICKAL_task3.h"
 #include "stdint.h"
 
 
static uint8_t srgu8Storage[(LAMP_COUNT % 8 == 0) ? (LAMP_COUNT/8) : (LAMP_COUNT/8)+1];
 
 eErr_t MICKAL_lampOn(eLamp_t eLamp){
	 
	 eErr_t eValue = E_OK;
	 
	 if(eLamp >= LAMP_START && eLamp < LAMP_COUNT)
	 {
		srgu8Storage[eLamp/8] |= 1 <<eLamp%8;
	 }
	 else
	 {
		 eValue = E_INVALID_ARG_1;
	 }
	 
	 return eValue; 
 }
 
 eErr_t MICKAL_lampOff(eLamp_t eLamp)
 {
	 
	 eErr_t eValue = E_OK;
	 
	 if(eLamp >= LAMP_START && eLamp < LAMP_COUNT)
	 {
		srgu8Storage[eLamp/8] &=~(1<<eLamp%8);
	 }
	 else
	 {
		 eValue = E_INVALID_ARG_1;
	 }
	 
	 return eValue;  
 }
 
 eErr_t MICKAL_getLamp(eLamp_t eLamp, eLampState_t* peState)
 {
	 
	 eErr_t eValue = E_OK;
	 
	 if(eLamp >= LAMP_START && eLamp < LAMP_COUNT && peState!=NULL)
	 {
			if(srgu8Storage[eLamp/8]&(1<<eLamp%8))
			{
				*peState = LAMP_STATE_ON;
			}
			else
			{
				*peState = LAMP_STATE_OFF;
			}
	 }
	 else if(peState == NULL)
	 {
		 eValue = E_INVALID_ARG_2;
		 *peState = LAMP_STATE_UNDEFINED;
	 }
	 else
	 {
		 eValue = E_INVALID_ARG_1;
	 }
	 
	 
	 return eValue; 
	 
 }
 
 