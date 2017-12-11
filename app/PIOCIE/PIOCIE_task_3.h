/**
 * Responsible: Piotr Ciesielczyk
 *
 *
 * History log:
 * 2017.12.05   PioCie  Initial version
 */
#ifndef PIOCIE_TASK_3_H
#define PIOCIE_TASK_3_H


#include "../common/COMMON_interface.h"

/* every public function in your module should start with "MODULENAME_" prefix */

eErr_t PIOCIE_lampOn(eLamp_t eLamp);
eErr_t PIOCIE_lampOff(eLamp_t eLamp);
eErr_t PIOCIE_getLamp(eLamp_t eLamp, eLampState_t* eState);

#endif