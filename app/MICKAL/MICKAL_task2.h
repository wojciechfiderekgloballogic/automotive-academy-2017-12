/**
 * Responsible: Michal Kaliszczyk
 *
 *
 * History log:
 * 2017.12.05   MICKAL  Initial version
 */

 



 #ifndef MICKAL_TASK2_H
 #define MICKAL_TASK2_H
 
 #include "../common/COMMON_interface.h"
 

eErr_t MICKAL_setLampBit(eLamp_t bit, int* reg);

eErr_t MICKAL_clearLampBit(eLamp_t bit, int* reg);

eErr_t MICKAL_invertLampBit(eLamp_t bit, int* reg);

eErr_t MICKAL_getLampState(eLamp_t bit, int reg, eLampState_t* state);


#endif