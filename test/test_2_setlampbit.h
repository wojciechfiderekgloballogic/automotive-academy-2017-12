/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.06   PioCie  Edited in line 30: eLampState_t* state
 * 2017.12.05   WojFid  Initial version
 */
#pragma once

#include "../app/common/COMMON_interface.h"
#include "./tests.h"


#define TEST_2__SET_LAMP_BIT(MODULE_PREFIX) \
    TEST_2__setLampBit(                     \
        #MODULE_PREFIX,                     \
        MODULE_PREFIX##_setLampBit,         \
        MODULE_PREFIX##_clearLampBit,       \
        MODULE_PREFIX##_invertLampBit,      \
        MODULE_PREFIX##_getLampState        \
    )


void TEST_2__setLampBit(
    char* module_name,
    eErr_t (*setLampBit)    (eLamp_t bit, int* reg),
    eErr_t (*clearLampBit)  (eLamp_t bit, int* reg),
    eErr_t (*invertLampBit) (eLamp_t bit, int* reg),
    eErr_t (*getLampState)  (eLamp_t bit, int reg, eLampState_t* state)
    );
