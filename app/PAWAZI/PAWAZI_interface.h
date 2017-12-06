/**
 * Responsible: Pawe³ Aziukiewicz
 *
 *
 * History log:
 * 2017.12.01   Pawe³ Aziukiewicz  Initial version
 */
#ifndef __PAWAZI_INTERFACE__
#define __PAWAZI_INTERFACE__

#include "../common/COMMON_interface.h"

eErr_t PAWAZI_setBit(int bit, int* reg);

eErr_t PAWAZI_clearBit(int bit, int* reg);

eErr_t PAWAZI_invertBit(int bit, int* reg);

#endif

