/**
 * Responsible: Paw Azi
 *
 *
 * History log:
 */
#ifndef __PAWAZI_TASK_4__
#define __PAWAZI_TASK_4__

#include <stdint.h>
#include "../common/COMMON_interface.h"
#include "../IO/IO_interface.h"

void   PAWAZI_vHandleButtons        (void);
eErr_t PAWAZI_eAddOnPressListener   (eButton_t eButton, eErr_t (*onPressListener) (eButton_t));
eErr_t PAWAZI_eAddOnReleaseListener (eButton_t eButton, eErr_t (*onReleaseListener) (eButton_t));

#endif


