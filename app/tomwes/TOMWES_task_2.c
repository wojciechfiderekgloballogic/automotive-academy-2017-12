/**
 * Responsible: Tomasz Wesolowski
 *
 *
 * History log:
 * 2017.12.07 TOMWES one result per function and check for nullptr 
 * 2017.12.06 TOMWES Initial version
 */
#include "TOMWES_task_2.h"
#include <stdio.h>

 
eErr_t TOMWES_setLampBit(eLamp_t bit, int* reg){
    eErr_t eResult = E_OK;
    int *null_ptr = 0;
    
    if( (bit < LAMP_START) || (bit >= LAMP_COUNT) ){
        eResult = E_INVALID_ARG_1;
    }  
    
    if(reg == null_ptr){
        eResult = E_INVALID_ARG_2;
    }
    
    if(eResult == E_OK){
        uint32_t u32Mask = 1 << bit;
        *reg |= u32Mask;
    }
    
    return eResult;
}

eErr_t TOMWES_clearLampBit(eLamp_t bit, int* reg){
    eErr_t eResult = E_OK;
    int *null_ptr = 0;
    
    if( (bit < LAMP_START) || (bit >= LAMP_COUNT) ){
        eResult = E_INVALID_ARG_1;
    }  
    
    if(reg == null_ptr){
        eResult = E_INVALID_ARG_2;
    }
    
    if(eResult == E_OK){
        uint32_t u32Mask = 1 << bit;
        *reg &=  ~(u32Mask);
    }
    return eResult;
}

eErr_t TOMWES_invertLampBit(eLamp_t bit, int* reg){
    eErr_t eResult = E_OK;
    int *null_ptr = 0;
    
    if( (bit < LAMP_START) || (bit >= LAMP_COUNT) ){
        eResult = E_INVALID_ARG_1;
    }  
    
    if(reg == null_ptr){
        eResult = E_INVALID_ARG_2;
    }
    
    if(eResult == E_OK){
        uint32_t u32Mask = 1 << bit;
        *reg ^= u32Mask;
    }

    return eResult;
}

eErr_t TOMWES_getLampState(eLamp_t bit, int reg, eLampState_t* state){
    eErr_t eResult = E_OK;
    if( (bit < LAMP_START) || (bit >= LAMP_COUNT)){
        eResult = E_INVALID_ARG_1;
    }    
    
    if(eResult == E_OK){
        uint32_t u32Mask = 1 << bit;
        uint32_t result = reg & u32Mask;
        
        if(result){
            *state = LAMP_STATE_ON;
        }else{
            *state = LAMP_STATE_OFF;
        }
    }
 
   return eResult; 
}
