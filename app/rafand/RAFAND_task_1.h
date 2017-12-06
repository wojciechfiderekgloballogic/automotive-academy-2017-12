/**
 * Responsible: Rafal Andrukajtis
 *
 *
 * History log:
 * 2017.12.05   RafAnd  My version
 */
#pragma once

#include "../common/COMMON_interface.h"

/* every public function in your module should start with "MODULENAME_" prefix */

eErr_t RAFAND_setBit(int bit, int* reg);

eErr_t RAFAND_clearBit(int bit, int* reg);

eErr_t RAFAND_invertBit(int bit, int* reg);

