/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.01   WojFid  Initial version
 */
#pragma once

#include "../app/common/COMMON_interface.h"
#include "./tests.h"


#define TEST_1__SET_BIT_INTERFACE(MODULE_PREFIX) TEST_1_setBitInterface( \
    #MODULE_PREFIX,        \
    MODULE_PREFIX##_setBit,  \
    MODULE_PREFIX##_clearBit,  \
    MODULE_PREFIX##_invertBit \
    )


void TEST_1_setBitInterface(
    char* module_name,
    eErr_t (*setBit)(int bit, int* reg),
    eErr_t (*clearBit)(int bit, int* reg),
    eErr_t (*invertBit)(int bit, int* reg)
    );
