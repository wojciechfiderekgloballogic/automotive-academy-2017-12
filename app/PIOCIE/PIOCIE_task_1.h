/**
 * Responsible: Piotr Ciesielczyk
 *
 *
 * History log:
 * 2017.12.05   PioCie  Initial version
 */
#ifndef PIOCIE_TASK_1_H
#define PIOCIE_TASK_1_H


#include "../common/COMMON_interface.h"

/* every public function in your module should start with "MODULENAME_" prefix */

eErr_t PIOCIE_setBit(int bit, int* reg);

eErr_t PIOCIE_clearBit(int bit, int* reg);

eErr_t PIOCIE_invertBit(int bit, int* reg);

#endif