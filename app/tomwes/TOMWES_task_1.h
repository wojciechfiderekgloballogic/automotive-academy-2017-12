/**
 * Responsible: Tomasz Wesolowski
 *
 *
 * History log:
 * 2017.12.01 TOMWES Empty setBit function
 */

#ifndef TOMWES_TASK_1_H
#define TOMWES_TASK_1_H
#include "../common/COMMON_interface.h"

eErr_t TOMWES_setBit(int bit, int* reg);
eErr_t TOMWES_clearBit(int bit, int* reg);
eErr_t TOMWES_invertBit(int bit, int* reg);

#endif