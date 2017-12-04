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


#define TEST__SET_BIT(MODULE_PREFIX) TEST_setBit( \
    #MODULE_PREFIX,        \
    MODULE_PREFIX##_setBit,  \
    MODULE_PREFIX##_clearBit,  \
    MODULE_PREFIX##_invertBit \
    )


void TEST_setBit(
    char* module_name,
    eErr_t (*setBit)(int bit, int* reg),
    eErr_t (*clearBit)(int bit, int* reg),
    eErr_t (*invertBit)(int bit, int* reg)
    );
