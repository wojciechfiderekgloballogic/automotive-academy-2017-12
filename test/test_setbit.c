/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.01   WojFid  Initial version - interface test
 */
#include "test_setbit.h"

void TEST_setBit(
    char* module_name,
    eErr_t (*setBit)(int bit, int* reg),
    eErr_t (*clearBit)(int bit, int* reg),
    eErr_t (*invertBit)(int bit, int* reg)
    ) {
        START_TEST;
        int v = 0;
        
        
        
        ASSERT( setBit(0, &v),     E_NOT_IMPLEMENTED );
        ASSERT( clearBit(0, &v),   E_NOT_IMPLEMENTED );
        ASSERT( invertBit(0, &v),  E_NOT_IMPLEMENTED );       
        
        
        STOP_TEST;
    }
