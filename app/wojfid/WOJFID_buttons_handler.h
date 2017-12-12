/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.11   WojFid  Initial version
 */
#pragma once

#include "../common/COMMON_interface.h"
#include "../IO/IO_interface.h"


void   WOJFID_vInit();

void   WOJFID_vHandleButtons        (void);

eErr_t WOJFID_eAddOnPressListener   (eButton_t eButton, eErr_t (*onPressListener)   (eButton_t));

eErr_t WOJFID_eAddOnReleaseListener (eButton_t eButton, eErr_t (*onReleaseListener) (eButton_t));




static int mapButtonToPin(eButton_t eButton);

