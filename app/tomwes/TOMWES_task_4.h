/**
 * Responsible: Tomasz Wesolowski
 *
 *
 * History log:
 * 2017.12.11 TOMWES Initial version
 */

#ifndef TOMWES_TASK_4_H
#define TOMWES_TASK_4_H
#include "../common/COMMON_interface.h"
#include "../IO/IO_interface.h"
#include <stdint.h>

typedef eErr_t(*func_ptr_t)(eButton_t);

typedef struct sButtonQueue sButtonQueue;
struct sButtonQueue{
    func_ptr_t* pQueue; //= (func_ptr_t*) malloc(sizeof(func_ptr_t));
    int iSize ; //how much memory we have
    int iInside ; // how many functions in
    
};
 
//0            - BUTTON_COUNT-1   : On buttons
//BUTTON_COUNT - 2*BUTTON_COUNT   : off buttons 
sButtonQueue asButtonQueue[BUTTON_COUNT*2];
int iInitialize;
int aiPrevious[BUTTON_COUNT];

void   vHandleButtons(void);
eErr_t eAddOnPressListener(eButton_t eButton, eErr_t (*onPressListener) (eButton_t));
eErr_t eAddOnReleaseListener(eButton_t eButton, eErr_t (*onReleaseListener) (eButton_t));
void vInitializeStructs();

#endif
