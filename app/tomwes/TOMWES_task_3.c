/**
 * Responsible: Tomasz Wesolowski
 *
 *
 * History log:
 * 2017.12.07 TOMWES Initial version
 */
#include "TOMWES_task_3.h"
#include <stdio.h>


eErr_t TOMWES_lampOn(eLamp_t eLamp){
    eErr_t eResult = E_OK;
    if( (eLamp < LAMP_START) || (eLamp >= LAMP_COUNT) ){
        eResult = E_INVALID_ARG_1;
    }  
    
    if(eResult == E_OK){
        
        rgu8InternalStorage[eLamp/8] |= 1 << eLamp%8 ;
        
    }
    
    return eResult;
}

eErr_t TOMWES_lampOff(eLamp_t eLamp){
    eErr_t eResult = E_OK;
    if( (eLamp < LAMP_START) || (eLamp >= LAMP_COUNT) ){
        eResult = E_INVALID_ARG_1;
    }  
    
    if(eResult == E_OK){
        
        rgu8InternalStorage[eLamp/8] &= ~(1 << eLamp%8);
        
    }
    
    return eResult;

}

eErr_t TOMWES_getLamp(eLamp_t eLamp, eLampState_t* eState){
    
    eErr_t eResult = E_OK;
    if( (eLamp < LAMP_START) || (eLamp >= LAMP_COUNT) ){
        eResult = E_INVALID_ARG_1;
    }  
    
    if (eState == 0){
        eResult = E_INVALID_ARG_2;
    }
    
    if(eResult == E_OK){
        
        if (rgu8InternalStorage[eLamp/8] & 1 << eLamp%8){
            *eState = LAMP_STATE_ON;
        }else{
            *eState = LAMP_STATE_OFF;
        }
        
    }
    
    return eResult;
    
}
