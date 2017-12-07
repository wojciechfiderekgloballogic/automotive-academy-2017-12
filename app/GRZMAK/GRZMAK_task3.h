/**
* Responsible: Grzegorz Makowski
*
*
*History Log:
* 2017.12.07 GRZMAK initial version
*
**/



#ifndef GRZMAK_TASK3_H

#define GRZMAK_TASK3_H
#include "../common/COMMON_interface.h"

eErr_t GRZMAK_lampOn(eLamp_t eLamp);
eErr_t GRZMAK_lampOff(eLamp_t eLamp);
eErr_t GRZMAK_getLamp(eLamp_t eLamp,eLampState_t* eState);
#endif