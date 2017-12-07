/**
 * Responsible: Marcin Torchala
 *
 *
 * History log:
 * 2017.12.06	MarTor	Initial Edit
 */
#pragma once

#include "../common/COMMON_interface.h"

/* every public function in your module should start with "MODULENAME_" prefix */

eErr_t MARTOR_setBit(int bit, int* reg);

eErr_t MARTOR_clearBit(int bit, int* reg);

eErr_t MARTOR_invertBit(int bit, int* reg);

