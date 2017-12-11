/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.06   ADAKOR  Initial version
 */
#ifndef ADAKOR_TASK3_H
#define ADAKOR_TASK3_H

#include "../common/COMMON_interface.h"

/* every public function in your module should start with "MODULENAME_" prefix */

eErr_t ADAKOR_lampOn(eLamp_t eLamp);
eErr_t ADAKOR_lampOff(eLamp_t eLamp);
eErr_t ADAKOR_getLamp(eLamp_t eLamp, eLampState_t* eState);

#endif