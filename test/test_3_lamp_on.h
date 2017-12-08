/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.07   WojFid  Initial version
 */
#pragma once

#include "../app/common/COMMON_interface.h"
#include "./tests.h"


#define TEST_3__LAMP_ON(MODULE_PREFIX) TEST_3_lampOn( \
    #MODULE_PREFIX,             \
    MODULE_PREFIX##_lampOn,     \
    MODULE_PREFIX##_lampOff,    \
    MODULE_PREFIX##_getLamp     \
    )


void TEST_3_lampOn(
    char* module_name,
    eErr_t (*lampOn)(eLamp_t eLamp),
    eErr_t (*lampOff)(eLamp_t eLamp),
    eErr_t (*getLamp)(eLamp_t eLamp, eLampState_t* eState)
    );
