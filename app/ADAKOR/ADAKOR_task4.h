/**
 * Responsible: Adam Kordykiewicz
 *
 *
 * History log:
 * 2017.12.12   ADAKOR  Initial version
 */
#ifndef ADAKOR_TASK4_H
#define ADAKOR_TASK4_H

#include "../common/COMMON_interface.h"
#include "../IO/IO_interface.h"

void ADAKOR_vHandleButtons (void);
eErr_t ADAKOR_eAddOnPressListener (eButton_t eButton, eErr_t (*onPressListener) (eButton_t));
eErr_t ADAKOR_eAddOnReleaseListener (eButton_t eButton, eErr_t (*onReleaseListener) (eButton_t));
void ADAKOR_vInit();

static int mapButtonToPin(eButton_t eButton);

#endif