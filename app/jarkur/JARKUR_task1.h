/**
 * Responsible: Jaroslaw Kurzynski
 *
 *
 * History log:
 * 2017.12.05   jarkur  Initial version
 */
 
#ifndef JARKUR_INTERFACE_H
#def JARKUR_INTERFACE_H

#include "JARKUR_interface.h"

/* every public function in your module should start with "MODULENAME_" prefix */

eErr_t JARKUR_setBit(int bit, int* reg);

eErr_t JARKUR_clearBit(int bit, int* reg);

eErr_t JARKUR_invertBit(int bit, int* reg);


#endif
