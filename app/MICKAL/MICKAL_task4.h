/**
 * Responsible: Michal Kaliszczyk
 *
 *
 * History log:
 * 2017.12.05   MICKAL  Initial version
 */

 



 #ifndef MICKAL_TASK4_H
 #define MICKAL_TASK4_H
 
 #include "../common/COMMON_interface.h"
 #include "../IO/IO_interface.h"
 
void   vHandleButton(eButton_t eButton);
void   MICKAL_vHandleButtons(void);
void   MICKAL_vInit();
eErr_t MICKAL_eAddOnPressListener(eButton_t eButton, eErr_t (*onPressListener) (eButton_t));
eErr_t MICKAL_eAddOnReleaseListener(eButton_t eButton, eErr_t (*onPressListener) (eButton_t));


#endif