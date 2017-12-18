/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.11   WojFid  Initial version
 */
#pragma once

#include "../app/common/COMMON_interface.h"
#include "../app/IO/IO_interface.h"
#include "./tests.h"


#define TEST_4__BUTTON(MODULE_PREFIX) TEST_4_button( \
    #MODULE_PREFIX,                         \
    MODULE_PREFIX##_vInit,                  \
    MODULE_PREFIX##_vHandleButtons,         \
    MODULE_PREFIX##_eAddOnPressListener,    \
    MODULE_PREFIX##_eAddOnReleaseListener   \
    )


void TEST_4_button(
    char* module_name,
    void   (*vInit)                 (void),
    void   (*vHandleButtons)        (void),
    eErr_t (*eAddOnPressListener)   (eButton_t eButton, eErr_t (*onPressListener) (eButton_t)),
    eErr_t (*eAddOnReleaseListener) (eButton_t eButton, eErr_t (*onReleaseListener) (eButton_t))
    );

    
extern int IO__pin0;
extern int IO__pin1;
extern int IO__pin2;
    