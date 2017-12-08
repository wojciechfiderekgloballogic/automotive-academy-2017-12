/**
 * Responsible: Rafal Andrukajtis
 *
 *
 * History log:
 * 2017.12.05   RafAnd  My version
 */
#ifndef RAFAND_TASK_2_H
#define RAFAND_TASK_2_H

#include "../common/COMMON_interface.h"

/* every public function in your module should start with "MODULENAME_" prefix */

eErr_t RAFAND_setLampBit(eLamp_t bit, int* reg);

eErr_t RAFAND_clearLampBit(eLamp_t bit, int* reg);

eErr_t RAFAND_invertLampBit(eLamp_t bit, int* reg);

eErr_t RAFAND_getLampState(eLamp_t bit, int reg, eLampState_t* state);
#endif