/**
* Responsible: Grzegorz Makowski
*
*
*History Log:
* 2017.12.11 GRZMAK initial version
*
**/

#ifndef GRZMAK_TASK4_H

#define GRZMAK_TASK4_H
#include "../common/COMMON_interface.h"
#include "../IO/IO_interface.h"

void vHandleButton(eButton_t eButton);
void GRZMAK_vHandleButtons(void);
eErr_t GRZMAK_eAddOnPressListener(eButton_t eButton, eErr_t (*onPressListener) (eButton_t));
eErr_t GRZMAK_eAddOnReleaseListener(eButton_t eButton, eErr_t (*onPressListener) (eButton_t));
void GRZMAK_vInit(void);
#endif