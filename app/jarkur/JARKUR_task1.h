/**
 * Responsible: Jaroslaw Kurzynski
 *
 *
 * History log:
 * 2017.12.05   jarkur  Initial version
 */
 
#ifndef JARKUR_TASK1_H
#define JARKUR_TASK1_H

#include "JARKUR_interface.h"
#include "../common/COMMON_interface.h"

/* every public function in your module should start with "MODULENAME_" prefix */

eErr_t JARKUR_setBit(int bit, int* reg);

eErr_t JARKUR_clearBit(int bit, int* reg);

eErr_t JARKUR_invertBit(int bit, int* reg);


#endif // JARKUR_TASK1_H
