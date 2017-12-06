/**
 * Responsible: Pawel Aziukiewicz
 *
 *
 * History log:
 */

#include <stdio.h>
#include "wojfid_example.h"

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
    