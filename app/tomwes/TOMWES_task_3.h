/**
 * Responsible: Tomasz Wesolowski
 *
 *
 * History log:
 * 2017.12.07 TOMWES Initial version
 */

#ifndef TOMWES_TASK_3_H
#define TOMWES_TASK_3_H
#include "../common/COMMON_interface.h"
#include <stdint.h>

uint8_t rgu8InternalStorage[(LAMP_COUNT % 8 == 0) ? LAMP_COUNT/8 : LAMP_COUNT/8+1 ];

eErr_t TOMWES_lampOn(eLamp_t eLamp);
eErr_t TOMWES_lampOff(eLamp_t eLamp);
eErr_t TOMWES_getLamp(eLamp_t eLamp, eLampState_t* eState);

#endif
