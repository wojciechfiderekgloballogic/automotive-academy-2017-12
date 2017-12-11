/**
 * Responsible: Tomasz Wesolowski
 *
 *
 * History log:
 * 2017.12.07 TOMWES Initial version
 */
#include "TOMWES_task_4.h"

// iInitialize =1;
// aiPrevious = {-1};
void vInitializeStructs(){
    
    int i;
    for(i=0; i<6; i++){
        asButtonQueue[i].iSize = 1;
        asButtonQueue[i].iInside = 0;
        asButtonQueue[i].pQueue = (func_ptr_t*) malloc(sizeof(func_ptr_t));
    }
       
    iInitialize = 0;
}

void vHandleButtons(void){
    if(iInitialize)vInitializeStructs();
    int i,currentPin;
    for(i=0; i<BUTTON_COUNT; ++i){
        currentPin = IO_get(i);
        if(aiPrevious[i]==0 && currentPin == 1){ //on press`
            //execute functions array on press
        }
        if(aiPrevious[i]==1 && currentPin == 0){ //on release
            //execute functions array on release
        }
                
        aiPrevious[i] = currentPin;
    }
    
}

eErr_t eAddOnPressListener(eButton_t eButton, eErr_t (*onPressListener) (eButton_t)){
    
    eErr_t eRetVal = E_OK;
    
    asButtonQueue[eButton].pQueue = onPressListener;
    
    
    return eRetVal;
}

eErr_t eAddOnReleaseListener(eButton_t eButton, eErr_t (*onReleaseListener) (eButton_t)){
    eErr_t eRetVal = E_OK;
    
    asButtonQueue[eButton+BUTTON_COUNT].pQueue = onReleaseListener;
    
    return eRetVal;
}

