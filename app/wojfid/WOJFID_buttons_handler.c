/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.11   WojFid  Initial version
 */
#include "./WOJFID_buttons_handler.h"

#include <stdio.h>
 
// This notation forces every pin to be mapped at compilation time.
// If you will use switch as mapper you should handle exceptions at runtaime in switch's default case.
static const int aiB2P[BUTTON_COUNT] = {
    IO_PIN_2, /* BUTTON_0 */
    IO_PIN_0, /* BUTTON_1 */    
    IO_PIN_1  /* BUTTON_2 */
};

static int mapButtonToPin(eButton_t eButton) {
    // Use switch or lookup table if possible
    return aiB2P[eButton];
}



// -----------------------------------------

typedef eErr_t (*fListener_t) (eButton_t);

struct sListeners {
    int iCount;
    int iArraySize;
    fListener_t* afListeners;
} sListeners_t_default = {0, 0, 0};

typedef struct sListeners sListeners_t;

typedef struct sButtonListeners {
    sListeners_t sOnPress;
    sListeners_t sOnRelease;
} sButtonListeners_t;

static sButtonListeners_t asListeners[BUTTON_COUNT];

static void onButtonPress(eButton_t eButton) {
    int i = 0;
    int iCount = asListeners[eButton].sOnPress.iCount;
    
    for(i=0; i<iCount; i++) {
        asListeners[eButton].sOnPress.afListeners[i](eButton);
    }
}

static void onButtonRelease(eButton_t eButton) {
    int i = 0;
    int iCount = asListeners[eButton].sOnRelease.iCount;
    
    for(i=0; i<iCount; i++) {
        asListeners[eButton].sOnRelease.afListeners[i](eButton);
    }
}




// -----------------------------------------

void WOJFID_vInit() {
    eButton_t eButton = BUTTON_START;
    
    // Initialize listeners array
    for(eButton=BUTTON_START; eButton<BUTTON_COUNT; eButton++) {
        asListeners[eButton].sOnPress = sListeners_t_default;
        asListeners[eButton].sOnRelease = sListeners_t_default;
    }
}

// -----------------------------------------

static int aiPrevPinStates[BUTTON_COUNT] = {
    0,
    0,
    0
};


void vHandleButtons(eButton_t eButton) {    
    int iPin = mapButtonToPin(eButton);
    
    int iPrevPinState = aiPrevPinStates[eButton];
    int iCurrentPinState = IO_get(iPin);
    
    if(iPrevPinState == 0 && iCurrentPinState == 1) {
        onButtonPress(eButton);
    }
    
    if(iPrevPinState == 1 && iCurrentPinState == 0) {
        onButtonRelease(eButton);
    }
    
    aiPrevPinStates[eButton] = iCurrentPinState;
}

// -----------------------------------------

void WOJFID_vHandleButtons (void) {
    eButton_t eButton = BUTTON_START;
    
    for(eButton = BUTTON_START; eButton < BUTTON_COUNT; eButton++) {
        vHandleButtons(eButton);
    }
}



eErr_t WOJFID_eAddOnPressListener(eButton_t eButton, eErr_t (*onPressListener)   (eButton_t)) {
    
    eErr_t eResult = E_OK;
    
    if(eButton>=BUTTON_START && eButton<BUTTON_COUNT) {
        int iCount = asListeners[eButton].sOnPress.iCount;
        int iArraySize = asListeners[eButton].sOnPress.iArraySize;
        int i = 0;
        int iNewSize = 0;
        
        // find if already exists    
        for(i=0; i<iCount; i++) {        
            
            if(asListeners[eButton].sOnPress.afListeners[i] == onPressListener) {
                eResult = E_LISTENER_ALREADY_EXISTS;
                break;
            }        
        }
        
        
        if( eResult == E_OK ) {
            // Resize container if necessary
            if( iCount == iArraySize ) {
               asListeners[eButton].sOnPress.iArraySize = asListeners[eButton].sOnPress.iArraySize + 1;
               iNewSize = asListeners[eButton].sOnPress.iArraySize;
               
               asListeners[eButton].sOnPress.afListeners = realloc(
                    asListeners[eButton].sOnPress.afListeners,
                    sizeof(asListeners[eButton].sOnPress.afListeners) * iNewSize);
            }
            
            if(asListeners[eButton].sOnPress.afListeners == 0) {
                eResult = E_MALLOC;
            
            } else {
                // Add new listener
                asListeners[eButton].sOnPress.iCount++;
                iCount = asListeners[eButton].sOnPress.iCount;
                asListeners[eButton].sOnPress.afListeners[iCount-1] = onPressListener;
            }
        }
        
        

    } else {
        eResult = E_INVALID_ARG_1;
    }
    
    
    
    
    return eResult;
}



eErr_t WOJFID_eAddOnReleaseListener(eButton_t eButton, eErr_t (*onReleaseListener) (eButton_t)) {
    
    eErr_t eResult = E_OK;
    
    if(eButton>=BUTTON_START && eButton<BUTTON_COUNT) {
        int iCount = asListeners[eButton].sOnRelease.iCount;
        int iArraySize = asListeners[eButton].sOnRelease.iArraySize;
        int i = 0;
        int iNewSize = 0;
        
        // find if already exists    
        for(i=0; i<iCount; i++) {        
            
            if(asListeners[eButton].sOnRelease.afListeners[i] == onReleaseListener) {
                eResult = E_LISTENER_ALREADY_EXISTS;
                break;
            }        
        }
        
        
        if( eResult == E_OK ) {
            // Resize container if necessary
            if( iCount == iArraySize ) {
               asListeners[eButton].sOnRelease.iArraySize = asListeners[eButton].sOnRelease.iArraySize + 1;
               iNewSize = asListeners[eButton].sOnRelease.iArraySize;
               
               asListeners[eButton].sOnRelease.afListeners = realloc(
                    asListeners[eButton].sOnRelease.afListeners,
                    sizeof(asListeners[eButton].sOnRelease.afListeners) * iNewSize);
            }
            
            if(asListeners[eButton].sOnRelease.afListeners == 0) {
                eResult = E_MALLOC;
            
            } else {
                // Add new listener
                asListeners[eButton].sOnRelease.iCount++;
                iCount = asListeners[eButton].sOnRelease.iCount;
                asListeners[eButton].sOnRelease.afListeners[iCount-1] = onReleaseListener;
            }
        }

        
    } else {
        eResult = E_INVALID_ARG_1;
    }
    
    return eResult;
}