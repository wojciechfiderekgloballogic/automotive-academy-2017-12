/**
 * Responsible: Michal Kaliszczyk
 *
 *
 * History log:
 * 2017.12.05   MICKAL  Initial version
 */

 



 #ifndef MICKAL_TASK3_H
 #define MICKAL_TASK3_H
 
 #include "../common/COMMON_interface.h"
 

eErr_t MICKAL_lampOn(eLamp_t eLamp);
eErr_t MICKAL_lampOff(eLamp_t eLamp);
eErr_t MICKAL_getLamp(eLamp_t eLamp, eLampState_t* eState);


#endif