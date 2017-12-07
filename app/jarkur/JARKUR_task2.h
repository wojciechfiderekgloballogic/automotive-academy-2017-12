/**
 * Responsible: Jaroslaw Kurzynski
 *
 *
 * History log:
 * 2017.12.05   jarkur  Initial version
 */
 
#ifndef JARKUR_TASK2_H
#define JARKUR_TASK2_H

#include "JARKUR_interface.h"
#include "../common/COMMON_interface.h"

/* every public function in your module should start with "MODULENAME_" prefix */

eErr_t JARKUR_setLampBit(eLamp_t bit, int* reg);

eErr_t JARKUR_clearLampBit(eLamp_t bit, int* reg);

eErr_t JARKUR_invertLampBit(eLamp_t bit, int* reg);

eErr_t JARKUR_getLampState( eLamp_t bit, int reg, eLampState_t* state);

#endif // JARKUR_TASK2_H
