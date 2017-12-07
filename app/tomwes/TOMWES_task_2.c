/**
 * Responsible: Tomasz Wesolowski
 *
 *
 * History log:
 * 2017.12.06 TOMWES Initial version
 */
#include "TOMWES_task_2.h"
#include <stdio.h>

 
eErr_t TOMWES_setLampBit(eLamp_t bit, int* reg){
    if( (bit < LAMP_START) || (bit >= LAMP_COUNT)){
        return E_INVALID_ARG_1;
    }
    int *null_ptr = 0;
    
    if(reg == null_ptr){
        return E_INVALID_ARG_2;
    }
    
    uint32_t ui32Mask = 1 << bit;
    *reg |= ui32Mask;

    return E_OK;
}

eErr_t TOMWES_clearLampBit(eLamp_t bit, int* reg){
    if( (bit < LAMP_START) || (bit >= LAMP_COUNT)){
        return E_INVALID_ARG_1;
    }  
    int *null_ptr = 0;
    if(reg == null_ptr){
        return E_INVALID_ARG_2;
    }
    
    uint32_t ui32Mask = 1 << bit;
    *reg &=  ~(ui32Mask);
    
    return E_OK;
}

eErr_t TOMWES_invertLampBit(eLamp_t bit, int* reg){
    if( (bit < LAMP_START) || (bit >= LAMP_COUNT)){
        return E_INVALID_ARG_1;
    }
    int *null_ptr = 0;
    if(reg == null_ptr){
        return E_INVALID_ARG_2;
    }
    uint32_t ui32Mask = 1 << bit;
    *reg ^= ui32Mask;

    return E_OK;
}

eErr_t TOMWES_getLampState(eLamp_t bit, int reg, eLampState_t* state){
    if( (bit < LAMP_START) || (bit >= LAMP_COUNT)){
        return E_INVALID_ARG_1;
    }    
    
    uint32_t ui32Mask = 1 << bit;
    uint32_t result = reg & ui32Mask;
    
    if(result){
        *state = LAMP_STATE_ON;
    }else{
        *state = LAMP_STATE_OFF;
    }
    
 
   return E_OK; 
}
