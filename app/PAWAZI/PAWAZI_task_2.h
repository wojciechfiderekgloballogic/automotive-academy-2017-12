/**
 * Responsible: Pawel Aziukiewicz
 *
 *
 * History log:
 */
#ifndef __PAWAZI_TASK_2__
#define __PAWAZI_TASK_2__

#include "../common/COMMON_interface.h"

eErr_t PAWAZI_setLampBit(eLamp_t bit, int* reg);

eErr_t PAWAZI_clearLampBit(eLamp_t bit, int* reg);

eErr_t PAWAZI_invertLampBit(eLamp_t bit, int* reg);

eErr_t PAWAZI_getLampState(eLamp_t bit, int reg, eLampState_t* state);

#endif


