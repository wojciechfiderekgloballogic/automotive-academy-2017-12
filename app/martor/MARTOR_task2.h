/**
 * Responsible: Marcin Torchala
 *
 *
 * History log:
 * 2017.12.07	MarTor	Initial version
 */
#ifndef MARTOR_TASK2_H
#define MARTOR_TASK2_H

#include "../common/COMMON_interface.h"

/* every public function in your module should start with "MODULENAME_" prefix */

eErr_t MARTOR_setLampBit(eLamp_t bit, int* reg);
eErr_t MARTOR_clearLampBit(eLamp_t bit, int* reg);
eErr_t MARTOR_invertLampBit(eLamp_t bit, int* reg);
eErr_t MARTOR_getLampState(eLamp_t bit, int reg, eLampState_t* state);

#endif