/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.06   ADAKOR  Initial version
 */
#ifndef ADAKOR_TASK1_H
#define ADAKOR_TASK1_H

#include "../common/COMMON_interface.h"

/* every public function in your module should start with "MODULENAME_" prefix */

eErr_t ADAKOR_setLampBit(eLamp_t bit, int* reg);
eErr_t ADAKOR_clearLampBit(eLamp_t bit, int* reg);
eErr_t ADAKOR_invertLampBit(eLamp_t bit, int* reg);
eErr_t ADAKOR_getLampState(eLamp_t bit, int reg, eLampState_t* state);

#endif