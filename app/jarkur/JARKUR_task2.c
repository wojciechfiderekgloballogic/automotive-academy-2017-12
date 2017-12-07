/**
 * Responsible: Jaroslaw Kurzynski
 *
 *
 * History log:
 * 2017.12.06   jarkur initial version
 */

#include <stdio.h>
#include "JARKUR_task2.h"

eErr_t JARKUR_setLampBit(eLamp_t bit, int* reg) {
    int mask = 1;
    mask = mask << bit;
    *reg |= mask;
    return E_OK;
}

eErr_t JARKUR_clearLampBit(eLamp_t bit, int* reg) {
    int mask = 1;
	mask = mask << bit;
	mask = ~mask;
	*reg &= mask;
    return E_OK;
}

eErr_t JARKUR_invertLampBit(eLamp_t bit, int* reg) {
    int mask = 1;
	mask = mask << bit;
	*reg ^= mask;
	return E_OK;
}

eErr_t JARKUR_getLampState( eLamp_t bit, int reg, eLampState_t* state) {
    return E_OK;
}
