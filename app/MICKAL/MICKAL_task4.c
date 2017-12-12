/**
 * Responsible: Michal Kaliszczyk
 *
 *
 * History log:
 * 2017.12.05   MICKAL  Initial version
 */

 
 #include "MICKAL_task4.h"
 #include "stdint.h"
 
 //realoc
 
 typedef eErr_t (*ePointer)(eButton_t eButton, eErr_t (*onPressListener) (eButton_t));
 
 ePointer *pFunction = malloc(sizeof(ePointer));
 
 void vHandleButtons(void)
 {
	 IO_get(IO_PIN_X)
	 
 }

 
eErr_t eAddOnPressListener(eButton_t eButton, eErr_t (*onPressListener) (eButton_t))
{
	
}

eErr_t eAddOnReleaseListene(eButton_t eButton, eErr_t (*onPressListener) (eButton_t))
{
	
}
 
 
 