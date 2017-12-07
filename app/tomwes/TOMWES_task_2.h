/**
 * Responsible: Tomasz Wesolowski
 *
 *
 * History log:
 * 2017.12.06 TOMWES Initial version
 */

#ifndef TOMWES_TASK_2_H
#define TOMWES_TASK_2_H
#include "../common/COMMON_interface.h"

eErr_t TOMWES_setLampBit(eLamp_t bit, int* reg);
eErr_t TOMWES_clearLampBit(eLamp_t bit, int* reg);
eErr_t TOMWES_invertLampBit(eLamp_t bit, int* reg);
eErr_t TOMWES_getLampState(eLamp_t bit, int reg, eLampState_t* state);

#endif
