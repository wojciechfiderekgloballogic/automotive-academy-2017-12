/**
* Responsible: Grzegorz Makowski
*
*
*History Log:
* 2017.12.05 GRZMAK initial version
*
**/

#ifndef GRZMAK_TASK1_H

#define GRZMAK_TASK1_H

#include "../common/COMMON_interface.h"

eErr_t GRZMAK_setBit(int bit, int* reg);

eErr_t GRZMAK_clearBit(int bit, int* reg);

eErr_t GRZMAK_invertBit(int bit, int* reg);

#endif // 

