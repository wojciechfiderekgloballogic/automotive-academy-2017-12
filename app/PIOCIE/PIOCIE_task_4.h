/**
 * Responsible: Piotr Ciesielczyk
 *
 *
 * History log:
 * 2017.12.11   PioCie  Initial version
 */
#ifndef PIOCIE_TASK_4_H
#define PIOCIE_TASK_4_H


#include "../common/COMMON_interface.h"
#include "../IO/IO_interface.h"

/* every public function in your module should start with "MODULENAME_" prefix */
/* you should change buttonState function if added buttons - map proper pins to propper buttons*/

eErr_t PIOCIE_eInitButtons(void);
void   PIOCIE_vHandleButtons        (void);
eErr_t PIOCIE_eAddOnPressListener   (eButton_t eButton, eErr_t (*onPressListener) (eButton_t));
eErr_t PIOCIE_eAddOnReleaseListener (eButton_t eButton, eErr_t (*onPressListener) (eButton_t));



#endif