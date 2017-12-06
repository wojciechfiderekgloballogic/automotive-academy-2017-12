/**
 * Responsible: Paweł Aziukiewicz
 *
 *
 * History log:
 * 2017.12.05   WojFid  clearBit fix
 * 2017.12.01   WojFid  Initial version that fails tests
 */

#include <stdio.h>
#include "PAWAZI_interface.h"


eErr_t PAWAZI_setLampBit(eLamp_t bit, int* reg){
	
	*reg |= 1<<bit;
	
}

eErr_t PAWAZI_clearLampBit(eLamp_t bit, int* reg){
	
	*reg &= ~(1<<bit);
	
}

eErr_t PAWAZI_invertLampBit(eLamp_t bit, int* reg){
	
	*reg ^= 1<<bit;
	
}

eErr_t PAWAZI_getLampState(eLamp_t bit, int reg, eLampState_t* state){
	
	
	
}
    