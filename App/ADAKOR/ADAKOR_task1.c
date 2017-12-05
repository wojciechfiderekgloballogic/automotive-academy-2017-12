/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.05   ADAKOR  Initial version that fails tests
 */

#ifndef ADAKOR_TASK1_C
#define ADAKOR_TASK1_C
#include "ADAKOR_task1.h"

/* Every public function in your module should start with   "MODULENAME_"   prefix */
/* Every private function in your module should start with  "MODULENAME__"  prefix */

eErr_t ADAKOR_setBit(int bit, int* reg) {
	*reg = (1 << bit) | *reg;
    return E_NOT_IMPLEMENTED;
}

eErr_t ADAKOR_clearBit(int bit, int* reg) {
	*reg &= ~(1 << bit);
    return E_NOT_IMPLEMENTED;
}

eErr_t ADAKOR_invertBit(int bit, int* reg) {
	*reg ^= (1 << bit);
    return E_NOT_IMPLEMENTED;
}

#endif