/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.07   WojFid  Initial version - interface test
 */
#include "test_3_lamp_on.h"

// eEachLamp must be used because eLamp already used by outer loop that calls this macro
#define IS_EACH_LAMP_OFF() \
    for(eEachLamp=LAMP_START; eEachLamp<LAMP_COUNT; eEachLamp++) {              \
        ASSERT( getLamp(eEachLamp, &eLampState), E_OK, "Incorrect return value")   \
        ASSERT( eLampState, LAMP_STATE_OFF, "Incorrect lamp state")                         \
    } \
    
#define IS_EACH_LAMP_ON() \
    for(eEachLamp=LAMP_START; eEachLamp<LAMP_COUNT; eEachLamp++) {              \
        ASSERT( getLamp(eEachLamp, &eLampState), E_OK, "Incorrect return value")   \
        ASSERT( eLampState, LAMP_STATE_ON, "Incorrect lamp state")                         \
    }
    
static int isTheOnlyLampOn(eLamp_t eLamp,
                    eErr_t (*getLamp)(eLamp_t eLamp, eLampState_t* eState)) {
    eLamp_t eIterator = LAMP_START;
    eLampState_t eState = LAMP_STATE_UNDEFINED;
    int iResult = 1;
    
    for(eIterator=LAMP_START; eIterator<LAMP_COUNT; eIterator++) {
        // UNABLE TO ASSERT - it requires `ok` variable to be in scope
        // ASSERT( getLamp(eIterator, &eState), E_OK, "Unexpected error code." );
        getLamp(eIterator, &eState);
        
        if(eIterator == eLamp) {
            if(eState != LAMP_STATE_ON) {
                iResult = 0;
                break;
            }
            
        } else {
            if(eState != LAMP_STATE_OFF) {
                iResult = 0;
                break;
            }                    
        }        
    }
    
    return iResult;
}

// Is inline worth of use in tests?
inline static int isTheOnlyLampOff(eLamp_t eLamp,
                    eErr_t (*getLamp)(eLamp_t eLamp, eLampState_t* eState)) {
    eLamp_t eIterator = LAMP_START;
    eLampState_t eState = LAMP_STATE_UNDEFINED;
    int iResult = 1;
    
    for(eIterator=LAMP_START; eIterator<LAMP_COUNT; eIterator++) {
        // UNABLE TO ASSERT - it requires `ok` variable to be in scope
        // ASSERT( getLamp(eIterator, &eState), E_OK, "Unexpected error code." );
        getLamp(eIterator, &eState);
        
        if(eIterator == eLamp) {
            if(eState != LAMP_STATE_OFF) {
                iResult = 0;
                break;
            }
            
        } else {
            if(eState != LAMP_STATE_ON) {
                iResult = 0;
                break;
            }                    
        }        
    }
    
    return iResult;
}

void TEST_3_lampOn(
    char* module_name,
    eErr_t (*lampOn)(eLamp_t eLamp),
    eErr_t (*lampOff)(eLamp_t eLamp),
    eErr_t (*getLamp)(eLamp_t eLamp, eLampState_t* eState)
    ) {

    START_TEST(3);
    eLampState_t eLampState = LAMP_STATE_UNDEFINED;
    eLamp_t eLamp = LAMP_START;
    eLamp_t eEachLamp = LAMP_START;
    int iRet = 0;
    
    // Is every lamp OFF (reset variable to undefined state)
    IS_EACH_LAMP_OFF()
    
    for(eLamp=LAMP_START; eLamp<LAMP_COUNT; eLamp++) {
        ASSERT(lampOn(eLamp), E_OK, "");
        ASSERT(isTheOnlyLampOn(eLamp, getLamp), 1, "Incorrect lamp state");
        ASSERT(lampOff(eLamp), E_OK, "");
        IS_EACH_LAMP_OFF()
    }
    
    for(eLamp=LAMP_START; eLamp<LAMP_COUNT; eLamp++) {
        lampOn(eLamp);
    }
    IS_EACH_LAMP_ON()
    
    for(eLamp=LAMP_START; eLamp<LAMP_COUNT; eLamp++) {
        ASSERT( lampOff(eLamp), E_OK, "");
        
        iRet = isTheOnlyLampOff(eLamp, getLamp);
        ASSERT( iRet, 1, "");
        
        // Example of different approach
        if( iRet != 1 ) {
            // log exactly which lamp fails
        }
        
        lampOn(eLamp);
        IS_EACH_LAMP_ON()
    }
    
    STOP_TEST;
}
