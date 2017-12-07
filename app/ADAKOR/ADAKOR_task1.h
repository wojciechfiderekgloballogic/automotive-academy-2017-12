/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.05   ADAKOR  Initial version
 */
#ifndef ADAKOR_TASK1_H
#define ADAKOR_TASK1_H

#include "../common/COMMON_interface.h"

/* every public function in your module should start with "MODULENAME_" prefix */

eErr_t ADAKOR_setBit(int bit, int* reg);

eErr_t ADAKOR_clearBit(int bit, int* reg);

eErr_t ADAKOR_invertBit(int bit, int* reg);

#endif