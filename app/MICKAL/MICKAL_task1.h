/**
 * Responsible: Michal Kaliszczyk
 *
 *
 * History log:
 * 2017.12.05   MICKAL  Initial version
 */

 



 #ifndef MICKAL_TASK1_H
 #define MICKAL_TASK1_H
 
 #include "../common/COMMON_interface.h"
 
 


eErr_t MICKAL_setBit(int bit, int* reg);

eErr_t MICKAL_clearBit(int bit, int* reg);

eErr_t MICKAL_invertBit(int bit, int* reg);


#endif