/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.06   PioCie  Edited in line16: eLampState_t* state
 * 2017.12.06   WojFid  Initial version - set lamp bit test
 */
#include "test_2_setlampbit.h"

void TEST_2__setLampBit(
    char* module_name,
    eErr_t (*setLampBit)    (eLamp_t bit, int* reg),
    eErr_t (*clearLampBit)  (eLamp_t bit, int* reg),
    eErr_t (*invertLampBit) (eLamp_t bit, int* reg),
    eErr_t (*getLampState)  (eLamp_t bit, int reg, eLampState_t* state)
    ) {
        START_TEST;
        int v = 0;
        
        
        
        //ASSERT( setBit(0, &v),     E_NOT_IMPLEMENTED );
        //ASSERT( clearBit(0, &v),   E_NOT_IMPLEMENTED );
        //ASSERT( invertBit(0, &v),  E_NOT_IMPLEMENTED );       
        
        
        STOP_TEST;
    }
