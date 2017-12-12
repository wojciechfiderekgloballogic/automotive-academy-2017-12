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
void TOMWES_vInit(){
    
    int i;
    for(i=0; i<BUTTON_COUNT*2; i++){
        asButtonQueue[i].iSize = 1;
        asButtonQueue[i].iInside = 0;
        asButtonQueue[i].pQueue = (func_ptr_t*) malloc(sizeof(func_ptr_t));
    }
       
    iInitialize = 0;
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
    // if(iInitialize)vInitializeStructs();
    int i,j,iCurrentPin, iButton;
    for(i=0; i<BUTTON_COUNT; ++i){
        iCurrentPin = IO_get(i);
        iButton = iButtonNumber(i);
        if(aiPrevious[i]==0 && iCurrentPin == 1){ //on press`
            //execute functions array on press
            if( asButtonQueue[iButton].iInside > 0){
                for(j = 0;j<asButtonQueue[iButton].iInside; j++){
                    // TO DO: why core dump? check iButton, fix hungarian where missing
                    printf("inside: %d, ibutton: %d \n", asButtonQueue[iButton].iInside, iButton);
                    asButtonQueue[iButton].pQueue[0](iButton);
                }
            }
        }
        if(aiPrevious[i]==1 && iCurrentPin == 0){ //on release
            //execute functions array on release
            for(j = 0;j<asButtonQueue[iButton+BUTTON_COUNT].iInside; j++){
                // asButtonQueue[iButton+BUTTON_COUNT].pQueue[j](iButton);
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
            
           if(&asButtonQueue[eButton].pQueue[i] == &onPressListener){
               iAddPointer = 0;
               eRetVal = E_LISTENER_ALREADY_EXISTS;
               break;
           }
            
        }
        if(iAddPointer){
            // printf("added\n");
            if(asButtonQueue[eButton].iInside == asButtonQueue[eButton].iSize){ // check if need to resize
                asButtonQueue[eButton].pQueue = realloc(asButtonQueue[eButton].pQueue, sizeof(func_ptr_t)*(asButtonQueue[eButton].iSize+1));
                asButtonQueue[eButton].iSize += 1;
            }    
            asButtonQueue[eButton].pQueue = &onPressListener;
            asButtonQueue[eButton].iInside += 1;
        }
    }
    // printf("val %d button %d\n", eRetVal, eButton);
    return eRetVal;
}


eErr_t TOMWES_eAddOnReleaseListener(eButton_t eButton, eErr_t (*onReleaseListener) (eButton_t)){
    // printf("inside release\n");
    eErr_t eRetVal = E_OK;
    if(eButton < BUTTON_START || eButton >= BUTTON_COUNT){
        eRetVal = E_INVALID_ARG_1;
    }else{
        int i;
        int iAddPointer = 1;
        for(i=0; i < asButtonQueue[eButton+BUTTON_COUNT].iInside; ++i){ // check if listener already in
            
           if(&asButtonQueue[eButton+BUTTON_COUNT].pQueue[i] == &onReleaseListener){
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
            asButtonQueue[eButton+BUTTON_COUNT].pQueue = &onReleaseListener;
            asButtonQueue[eButton+BUTTON_COUNT].iInside += 1;
        }
    }
    // printf("val %d button %d\n", eRetVal, eButton);

    return eRetVal;
}

