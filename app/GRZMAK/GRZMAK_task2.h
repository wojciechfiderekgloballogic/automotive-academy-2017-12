/**
* Responsible: Grzegorz Makowski
*
*
*History Log:
* 2017.12.06 GRZMAK initial version
*
**/

#ifndef GRZMAK_TASK_2_H

#define GRZMAK_TASK_2_H
#include "../common/COMMON_interface.h"



eErr_t GRZMAK_setLampBit( eLamp_t eBit, int* piReg);
eErr_t GRZMAK_clearLampBit( eLamp_t eBit, int* piReg);
eErr_t GRZMAK_invertLampBit( eLamp_t eBit, int* piReg);
eErr_t GRZMAK_getLampState( eLamp_t eBit, int iReg, eLampState_t* eState);
#endif