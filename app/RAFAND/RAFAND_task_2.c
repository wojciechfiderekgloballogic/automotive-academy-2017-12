/**
 * Responsible: Rafal Andrukajtis
 *
 *
 * History log:
 * 2017.12.01   RafAnd  My version
 */

#include <stdio.h>
#include "RAFAND_task_2.h"

/* Every public function in your module should start with   "MODULENAME_"   prefix */
/* Every private function in your module should start with  "MODULENAME__"  prefix */

eErr_t RAFAND_setLampBit(eLamp_t bit, int* reg) {
	if(bit >= LAMP_COUNT || bit < 0) {
		return E_INVALID_ARG_1;
	}
	*reg |= 1<<bit;
    return E_OK;
}

eErr_t RAFAND_clearLampBit(eLamp_t bit, int* reg) {
	if(bit >= LAMP_COUNT || bit < 0) {
		return E_INVALID_ARG_1;
	}
	*reg &= ~(1<<bit);
    return E_OK;
}

eErr_t RAFAND_invertLampBit(eLamp_t bit, int* reg) {
	if(bit >= LAMP_COUNT || bit < 0) {
		return E_INVALID_ARG_1;
	}
	*reg ^= 1<<bit;
    return E_OK;
}

eErr_t RAFAND_getLampState(eLamp_t bit, int reg, eLampState_t* state) {
	if(bit >= LAMP_COUNT || bit < 0) {
		return E_INVALID_ARG_1;
	}
	if(reg & 1<<bit) {
		*state = LAMP_STATE_ON;
	}
	else {
		*state = LAMP_STATE_OFF;
	}
    return E_OK;
}

    