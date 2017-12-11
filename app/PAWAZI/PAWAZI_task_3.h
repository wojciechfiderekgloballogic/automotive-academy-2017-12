/**
 * Responsible: Paw Azi
 *
 *
 * History log:
 */
#ifndef __PAWAZI_TASK_3__
#define __PAWAZI_TASK_3__

#include <stdint.h>
#include "../common/COMMON_interface.h"

eErr_t PAWAZI_lampOn(eLamp_t eLamp);
eErr_t PAWAZI_lampOff(eLamp_t eLamp);
eErr_t PAWAZI_getLamp(eLamp_t eLamp, eLampState_t* eState);

#endif


