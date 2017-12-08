
/**
 * Responsible: Jaroslaw Kurzynski
 *
 *
 * History log:
 * 2017.12.08   jarkur  Initial version
 */
 
#ifndef JARKUR_TASK3_H
#define JARKUR_TASK3_H

#include "JARKUR_interface.h"
#include "../common/COMMON_interface.h"

/* every public function in your module should start with "MODULENAME_" prefix */
eErr_t JARKUR_lampOn(eLamp_t ELamp);
eErr_t JARKUR_lampOff(eLamp_t eLamp);
eErr_t JARKUR_getLamp(eLamp_t eLamp, eLampState_t* peState);


#endif // JARKUR_TASK3_H
