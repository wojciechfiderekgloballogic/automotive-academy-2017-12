/**
 * Responsible: Tomasz Wesolowski
 *
 *
 * History log:
 * 2017.12.07 TOMWES Initial version
 */
#include "TOMWES_task_4.h"

void TOMWES_vInit(){
    
    int i;
    for(i=0; i<BUTTON_COUNT*2; i++){
        asButtonQueue[i].iSize = 1;
        asButtonQueue[i].iInside = 0;
        asButtonQueue[i].pQueue = (func_ptr_t*) malloc(sizeof(func_ptr_t));
    }
    memset(aiPrevious,-1, BUTTON_COUNT * sizeof(aiPrevious[0]));

}

int iButtonNumber(int i){
    int iRetVal;
    switch(i){
        case 0:
            iRetVal = 1;
            break;
        case 1:
            iRetVal = 2;
            break;
        case 2:
            iRetVal = 0;
            break;
    }
    return iRetVal;
}

void TOMWES_vHandleButtons(void){
    

    int i,j,iCurrentPin, iButton;
    for(i=0; i<BUTTON_COUNT; ++i){
        iCurrentPin = IO_get(i);
        iButton = iButtonNumber(i);
        if(aiPrevious[i]==0 && iCurrentPin == 1){ //on press
            
            //execute functions array on press
            if( asButtonQueue[iButton].iInside > 0){
                for(j = 0; j < asButtonQueue[iButton].iInside; j++){
                    
                    
                    asButtonQueue[iButton].pQueue[j](iButton);
                    
                }
            }
        }
        if(aiPrevious[i]==1 && iCurrentPin == 0){ //on release
            //execute functions array on release
            
            if( asButtonQueue[iButton+BUTTON_COUNT].iInside > 0){
                for(j = 0; j < asButtonQueue[iButton+BUTTON_COUNT].iInside; j++){
                    
                    
                    asButtonQueue[iButton+BUTTON_COUNT].pQueue[j](iButton);
                    
                }
            }
        }
                
        aiPrevious[i] = iCurrentPin;
    }
    
}

eErr_t TOMWES_eAddOnPressListener(eButton_t eButton, eErr_t (*onPressListener) (eButton_t)){
    
    eErr_t eRetVal = E_OK;
    if(eButton < BUTTON_START || eButton >= BUTTON_COUNT){
        eRetVal = E_INVALID_ARG_1;
    }else{
        int i;
        int iAddPointer = 1;
        for(i=0; i < asButtonQueue[eButton].iInside; ++i){ // check if listener already in
            
           if(asButtonQueue[eButton].pQueue[i] == onPressListener){
               iAddPointer = 0;
               eRetVal = E_LISTENER_ALREADY_EXISTS;
               break;
           }
            
        }
        if(iAddPointer){
         
            if(asButtonQueue[eButton].iInside == asButtonQueue[eButton].iSize){ // check if need to resize
                asButtonQueue[eButton].pQueue = realloc(asButtonQueue[eButton].pQueue, sizeof(func_ptr_t)*(asButtonQueue[eButton].iSize+1));
                asButtonQueue[eButton].iSize += 1;
            }    
            asButtonQueue[eButton].pQueue[asButtonQueue[eButton].iInside] = onPressListener;
            asButtonQueue[eButton].iInside += 1;
        }
    }

    return eRetVal;
}


eErr_t TOMWES_eAddOnReleaseListener(eButton_t eButton, eErr_t (*onReleaseListener) (eButton_t)){

    eErr_t eRetVal = E_OK;
    if(eButton < BUTTON_START || eButton >= BUTTON_COUNT){
        eRetVal = E_INVALID_ARG_1;
    }else{
        int i;
        int iAddPointer = 1;
        for(i=0; i < asButtonQueue[eButton+BUTTON_COUNT].iInside; ++i){ // check if listener already in
            
           if(asButtonQueue[eButton+BUTTON_COUNT].pQueue[i] == onReleaseListener){
               iAddPointer = 0;
               eRetVal = E_LISTENER_ALREADY_EXISTS;
               break;
           }
            
        }
        if(iAddPointer){
            if(asButtonQueue[eButton+BUTTON_COUNT].iInside == asButtonQueue[eButton+BUTTON_COUNT].iSize){ // check if need to resize
                asButtonQueue[eButton+BUTTON_COUNT].pQueue = realloc(asButtonQueue[eButton+BUTTON_COUNT].pQueue, sizeof(func_ptr_t)*(asButtonQueue[eButton+BUTTON_COUNT].iSize+1));
                asButtonQueue[eButton+BUTTON_COUNT].iSize += 1;
            }    
            asButtonQueue[eButton+BUTTON_COUNT].pQueue[asButtonQueue[eButton+BUTTON_COUNT].iInside] = onReleaseListener;
            asButtonQueue[eButton+BUTTON_COUNT].iInside += 1;
        }
    }

    return eRetVal;
}

