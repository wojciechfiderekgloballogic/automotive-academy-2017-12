/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.05   WojFid  Initial version - set lamp bit test
 */
#include "test_2_setlampbit.h"


int isTheOnlyBitSet(eLamp_t bit, int reg) {
    int result = 1;
    eLamp_t i = 0;
    
    for(i=LAMP_START; i<LAMP_COUNT; i++) {
        if( i == bit ) {
            continue;
        }

        if( (reg >> i) & 1 ) {
            result = 0;
        }
    }

    return result;
}

int isEveryBitClear(int reg) {
    int result = 1;
    eLamp_t i = 0;
    
    for(i=LAMP_START; i<LAMP_COUNT; i++) {
        if( (reg >> i) & 1 ) {
            result = 0;
        }
    }

    return result;
}


int isEveryBitSet(int reg) {
    int result = 1;
    eLamp_t i = 0;
    
    for(i=LAMP_START; i<LAMP_COUNT; i++) {
        if( ((reg >> i) & 1) == 0 ) {
            result = 0;
        }
    }

    return result;
}

void TEST_2__setLampBit(
    char* module_name,
    eErr_t (*setLampBit)    (eLamp_t bit, int* reg),
    eErr_t (*clearLampBit)  (eLamp_t bit, int* reg),
    eErr_t (*invertLampBit) (eLamp_t bit, int* reg),
    eErr_t (*getLampState)  (eLamp_t bit, int reg, eLampState_t* state)
    ) {
        START_TEST(2);
        int* null_ptr = 0;
        int r = 0;
        eLampState_t val = 0;
        eLamp_t eBit = LAMP_START;
        
        
        ASSERT( isEveryBitClear(r),         1   );
        
        
        for(eBit=LAMP_START; eBit<LAMP_COUNT; eBit++) {
            // Set
            ASSERT( setLampBit(eBit, &r),       E_OK);
            ASSERT( getLampState(eBit, r, &val),E_OK);
            ASSERT( val,                        LAMP_STATE_ON);
            ASSERT( isTheOnlyBitSet(eBit, r),   1   );
            
            // Clear
            ASSERT( clearLampBit(eBit, &r),     E_OK);
            ASSERT( getLampState(eBit, r, &val),E_OK);
            ASSERT( val,                        LAMP_STATE_OFF);
            ASSERT( isEveryBitClear(r),         1   );
            
            // Invert 1
            ASSERT( invertLampBit(eBit, &r),    E_OK);
            ASSERT( getLampState(eBit, r, &val),E_OK);
            ASSERT( val,                        LAMP_STATE_ON);
            ASSERT( isTheOnlyBitSet(eBit, r),   1   );
            
            // Invert 2
            ASSERT( invertLampBit(eBit, &r),    E_OK);
            ASSERT( getLampState(eBit, r, &val),E_OK);
            ASSERT( val,                        LAMP_STATE_OFF);
            ASSERT( isEveryBitClear(r),         1   );
        }
        
        // Set every lamp
        for(eBit=LAMP_START; eBit<LAMP_COUNT; eBit++) {
            ASSERT( setLampBit(eBit, &r),       E_OK);
        }
        ASSERT( isEveryBitSet(r), 1 );
        
        // Clear every lamp
        for(eBit=LAMP_START; eBit<LAMP_COUNT; eBit++) {
            ASSERT( clearLampBit(eBit, &r),       E_OK);
        }
        ASSERT( isEveryBitClear(r), 1 );
        
        // Invalid arg 1
        ASSERT( setLampBit( (eLamp_t)-1,           &r),  E_INVALID_ARG_1 )
        ASSERT( setLampBit( (eLamp_t)LAMP_COUNT+1, &r),  E_INVALID_ARG_1 )
        ASSERT( clearLampBit( (eLamp_t)-1,           &r),  E_INVALID_ARG_1 )
        ASSERT( clearLampBit( (eLamp_t)LAMP_COUNT+1, &r),  E_INVALID_ARG_1 )
        ASSERT( invertLampBit( (eLamp_t)-1,           &r),  E_INVALID_ARG_1 )
        ASSERT( invertLampBit( (eLamp_t)LAMP_COUNT+1, &r),  E_INVALID_ARG_1 )
        ASSERT( getLampState( (eLamp_t)-1,           r, &val),  E_INVALID_ARG_1 )
        ASSERT( getLampState( (eLamp_t)LAMP_COUNT+1, r, &val),  E_INVALID_ARG_1 )
        
        // Invalid arg 2
        ASSERT( setLampBit( LAMP_START,    null_ptr),  E_INVALID_ARG_2 )
        ASSERT( clearLampBit( LAMP_START,  null_ptr),  E_INVALID_ARG_2 )
        ASSERT( invertLampBit( LAMP_START, null_ptr),  E_INVALID_ARG_2 )
        
        
        STOP_TEST;
    }
