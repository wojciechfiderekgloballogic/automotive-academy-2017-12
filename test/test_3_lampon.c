/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.08   PioCie  Added test 3
 */
#include "test_3_lampon.h"


int isTheOnlyLampOn(eLamp_t bit,eErr_t (*getLamp) (eLamp_t, eLampState_t*)) {
    int result = 1;
    
    eLampState_t eVal;
    eLamp_t i = 0;
    
    for(i=LAMP_START; i<LAMP_COUNT; i++) {
        if( i == bit ) {
            continue;
        }
        getLamp(i, &eVal);
        if( LAMP_STATE_ON==eVal || LAMP_STATE_UNDEFINED==eVal ) {
            result = 0;
        }
    }

    return result;
}

int isEveryLampOff(eErr_t (*getLamp) (eLamp_t, eLampState_t*)) {
    int result = 1;
    eLamp_t i = 0;
    eLampState_t eVal;
    for(i=LAMP_START; i<LAMP_COUNT; i++) {
		getLamp(i, &eVal);
        if( LAMP_STATE_ON==eVal || LAMP_STATE_UNDEFINED==eVal ) {
            result = 0;
        }
    }

    return result;
}


int isEveryLampOn(eErr_t (*getLamp) (eLamp_t, eLampState_t*)) {
    int result = 1;
    eLamp_t i = 0;
    eLampState_t eVal;
	
    for(i=LAMP_START; i<LAMP_COUNT; i++) {
		getLamp(i, &eVal);
        if( LAMP_STATE_OFF==eVal || LAMP_STATE_UNDEFINED==eVal ) {
            result = 0;
        }
    }

    return result;
}
void TEST_3__lampOn(
    char* module_name,
    eErr_t (*lampOn)    (eLamp_t eLamp),
    eErr_t (*lampOff)  (eLamp_t eLamp),
    eErr_t (*getLamp) (eLamp_t eLamp, eLampState_t* eState)
    )
{
        START_TEST(3);
        int* null_ptr = 0;
        eLampState_t val = 0;
        eLamp_t eBit = LAMP_START;
        
        ASSERT( isEveryLampOff(getLamp),         1   );
        
        for(eBit=LAMP_START; eBit<LAMP_COUNT; eBit++) {
            // Set
            ASSERT( lampOn(eBit),       E_OK);
            ASSERT( getLamp(eBit, &val),E_OK);
            ASSERT( val,                        LAMP_STATE_ON);
            ASSERT( isTheOnlyLampOn(eBit,getLamp),   1   );
            
            // Clear
            ASSERT( lampOff(eBit),     E_OK);
            ASSERT( getLamp(eBit, &val),E_OK);
            ASSERT( val,                        LAMP_STATE_OFF);
            ASSERT( isEveryLampOff(getLamp),         1   );
            
        }
        // Set every lamp
        for(eBit=LAMP_START; eBit<LAMP_COUNT; eBit++) {
            ASSERT( lampOn(eBit),       E_OK);
        }
        ASSERT( isEveryLampOn(getLamp), 1 );
        
        // Clear every lamp
        for(eBit=LAMP_START; eBit<LAMP_COUNT; eBit++) {
            ASSERT( lampOff(eBit),       E_OK);
        }
        ASSERT( isEveryLampOff(getLamp), 1 );
        // Invalid arg 1
        ASSERT( lampOn( (eLamp_t)-1),  E_INVALID_ARG_1 )
        ASSERT( lampOn( (eLamp_t)LAMP_COUNT+1),  E_INVALID_ARG_1 )
        ASSERT( lampOff( (eLamp_t)-1),  E_INVALID_ARG_1 )
        ASSERT( lampOff( (eLamp_t)LAMP_COUNT+1),  E_INVALID_ARG_1 )
        ASSERT( getLamp( (eLamp_t)-1,           &val),  E_INVALID_ARG_1 )
		ASSERT( val,  LAMP_STATE_UNDEFINED )
        ASSERT( getLamp( (eLamp_t)LAMP_COUNT+1, &val),  E_INVALID_ARG_1 )
		ASSERT( val,  LAMP_STATE_UNDEFINED )
		
        STOP_TEST;
    }
