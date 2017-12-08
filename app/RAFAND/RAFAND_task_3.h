/**
 * Responsible: Rafal Andrukajtis
 *
 *
 * History log:
 * 2017.12.07   RafAnd  Array implementation
 * 2017.12.05   RafAnd  My version
 */
#ifndef RAFAND_TASK_3_H
#define RAFAND_TASK_3_H

#include "../common/COMMON_interface.h"

/* every public function in your module should start with "MODULENAME_" prefix */

//in private array of uint8_t will be set bit in eLamp (it's index) place
eErr_t RAFAND_lampOn(eLamp_t eLamp);

//in private array of uint8_t will be unset bit in eLamp (it's index) place
eErr_t RAFAND_lampOff(eLamp_t eLamp);

//check state of specific bit in array (where eLamp is index) 
eErr_t RAFAND_getLamp(eLamp_t eLamp, eLampState_t* peState);
#endif