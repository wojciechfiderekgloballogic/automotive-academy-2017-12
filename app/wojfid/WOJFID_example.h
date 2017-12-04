/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.01   WojFid  Initial version
 */
#pragma once

#include "../common/COMMON_interface.h"

/* every public function in your module should start with "MODULENAME_" prefix */

eErr_t WOJFID_setBit(int bit, int* reg);

eErr_t WOJFID_clearBit(int bit, int* reg);

eErr_t WOJFID_invertBit(int bit, int* reg);

