/**
 * Responsible: Jaroslaw Kurzynski
 *
 *
 * History log:
 * 2017.12.06   jarkur initial version
 */

#include <stdio.h>
#include "JARKUR_interface.h"

eErr_t JARKUR_setLampBit(eLamp_t bit, int* reg) {
		eErr_t flag = E_OK;
		if (bit < LAMP_START || bit >= LAMP_COUNT) {
				flag = E_INVALID_ARG_1;
		} else {

				if (reg == NULL) {
						flag = E_INVALID_ARG_2;
				} else {
						int mask = 1;
						mask = mask << bit;
						*reg |= mask;
						return E_OK;
				}
		}
		return flag;
}

eErr_t JARKUR_clearLampBit(eLamp_t bit, int* reg) {
		eErr_t flag = E_OK;
		if (bit < LAMP_START || bit >= LAMP_COUNT) {
				flag = E_INVALID_ARG_1;
		} else {

				if (reg == NULL) {
						flag = E_INVALID_ARG_2;
				} else {
						int mask = 1;
						mask = mask << bit;
						mask = ~mask;
						*reg &= mask;
				}
		}
		return flag;
}

eErr_t JARKUR_invertLampBit(eLamp_t bit, int* reg) {
		eErr_t flag = E_OK;
		if (bit < LAMP_START || bit >= LAMP_COUNT) {
				flag = E_INVALID_ARG_1;
		} else {

				if (reg == NULL) {
						flag = E_INVALID_ARG_2;
				} else {
						int mask = 1;
						mask = mask << bit;
						*reg ^= mask;
				}
		}
		return flag;
}

eErr_t JARKUR_getLampState( eLamp_t bit, int reg, eLampState_t* state) {
		eErr_t flag = E_OK;
		if (bit < LAMP_START || bit >= LAMP_COUNT) {
				flag = E_INVALID_ARG_1;
		}else {
				int mask = 1;
				mask = mask << bit;
				if (reg & mask) {
						*state = LAMP_STATE_ON;
				} else {
						*state = LAMP_STATE_OFF;
				}
		}
		return flag;
}
