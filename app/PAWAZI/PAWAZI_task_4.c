/**
 * Responsible: Paw Azi
 *
 *
 * History log:
 *  06.12.2017 initial version
 */

#include <stdio.h>
#include "PAWAZI_task_4.h"

/*

	albo lepiej do struktury????
	
	struct stru{
		
		eErr_t (*)
		
		
	}
	
	[ B1 onPress ] [ B1 onReleased ] [ B2 onPress ] [ B2 onRelease] [ B3 onPresse] [ B3 onRelease ]
		onPress			onPress				onPress			onPress
		.					.
		.					.		
		.					.
		.					.	
		.					.
		.					.		
		.					.
		.					.	


		
		przechowywac stan poprzedni przycisku.....
		
		
		
		prev = current
		
		
		
		patent
		
		


*/

static eErr_t (*eFunCont[1][6])(eButton_t);

void   vHandleButtons(void){

	if(IO_PIN_0){
		
				
		
	}
	
	
}

eErr_t eAddOnPressListener(eButton_t eButton, eErr_t (*onPressListener) (eButton_t)){
	
	/*
		np:
		if(eButton == BUTTON_1)
			eFunCont[0][0] = onPressListener;
		if(eButton == BUTTON_2)
			eFunCont[0][2] = onPressListener;
		if(eButton == BUTTON_3)
			eFunCont[0][4] = onPressListener;
		
		...moze byc wiecej przyciskow.....
		
	*/
	
	eFunCont[0] = onPressListener;
	
	return E_NOT_IMPLEMENTED;
	
}


eErr_t eAddOnReleaseListener(eButton_t eButton, eErr_t (*onPressListener) (eButton_t)){
	
	
	return E_NOT_IMPLEMENTED;
	
}