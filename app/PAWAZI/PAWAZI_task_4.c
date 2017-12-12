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

//hardcoded for 6 buttons
static eErr_t (**eFunPtrArr[6])(eButton_t);
static uint8_t auiStateBtn[3];
static uint8_t uiOnlyOnce = 1;
static uint8_t uiEachColumnSize[] = {1,1,1,1,1,1};

void   PAWAZI_vHandleButtons(void){
	
	if(uiOnlyOnce){

		for( int i = 0 ; i < 6 ; i++){
			if( (eFunPtrArr[i] = malloc( (100) * sizeof (eFunPtrArr))) == NULL){
				printf("error - cant allocate 2d array\n");
			}
		}
					
		uiOnlyOnce = 0;
	}
	
	
	if(IO_get(IO_PIN_0) && !auiStateBtn[0]){
		
		for(int i = 0 ; i < uiEachColumnSize[0] ; i++){
			eFunPtrArr[0][i](BUTTON_1);
		}
		
		auiStateBtn[0] = 1;
		
	}else if(!IO_get(IO_PIN_0) && auiStateBtn[0]){
		
		for(int i = 0 ; i < uiEachColumnSize[1] ; i++){
			eFunPtrArr[1][i](BUTTON_1);
		}
		
		auiStateBtn[0] = 0;
		
	}

	if(IO_get(IO_PIN_1) && !auiStateBtn[1]){
		
		for(int i = 0 ; i < uiEachColumnSize[2] ; i++){
			eFunPtrArr[2][i](BUTTON_2);
		}
		
		auiStateBtn[1] = 1;
		
	}else if(!IO_get(IO_PIN_1) && auiStateBtn[1]){
		
		for(int i = 0 ; i < uiEachColumnSize[3] ; i++){
			eFunPtrArr[3][i](BUTTON_2);
		}
		
		auiStateBtn[1] = 0;
		
	}
	
	if(IO_get(IO_PIN_2) && !auiStateBtn[3]){
		
		for(int i = 0 ; i < uiEachColumnSize[4] ; i++){
			eFunPtrArr[4][i](BUTTON_0);
		}
		
		auiStateBtn[3] = 1;
		
	}else if(!IO_get(IO_PIN_2) && auiStateBtn[3]){
		
		for(int i = 0 ; i < uiEachColumnSize[5] ; i++){
			eFunPtrArr[5][i](BUTTON_0);
		}
		
		auiStateBtn[3] = 0;
		
	}

	
	
}

eErr_t PAWAZI_eAddOnPressListener(eButton_t eButton, eErr_t (*onPressListener) (eButton_t)){
	
	/*
		cos takiego
		
		if( !(uiEachColumnSize[0] % 11) || uiEachColumnSize[0] == 1)
			realloc....
			uiEachColumnSize[0]+=10;
	*/

	switch(eButton){
		
		case BUTTON_1 : {
			
			eFunPtrArr[0][uiEachColumnSize[0] - 1] = onPressListener;
			uiEachColumnSize[0]++;
			// if( !(uiEachColumnSize[0] % 11) || uiEachColumnSize[0] == 1){
				// eFunPtrArr[0] = realloc( eFunPtrArr[0] ,uiEachColumnSize[0] + 10 * sizeof(eFunPtrArr));
				// uiEachColumnSize[0]+=10;
			// }
			// else{
				// uiEachColumnSize[0]++;
			// }
			
			break;
		}
		
		case BUTTON_2 : {
			eFunPtrArr[2][uiEachColumnSize[2] - 1] = onPressListener;
			uiEachColumnSize[2]++;
			break;
		}
		
		case BUTTON_0 : {
			eFunPtrArr[4][uiEachColumnSize[4] - 1] = onPressListener;
			uiEachColumnSize[4]++;
			break;
		}
		
		default:
			break;
		
		
	}
	
	return E_OK;
	
}


eErr_t PAWAZI_eAddOnReleaseListener(eButton_t eButton, eErr_t (*onReleaseListener) (eButton_t)){
	
	
	
		switch(eButton){
		
		case BUTTON_1 : {
			eFunPtrArr[1][uiEachColumnSize[1] - 1] = onReleaseListener;
			break;
		}
		
		case BUTTON_2 : {
			eFunPtrArr[3][uiEachColumnSize[3] - 1] = onReleaseListener;
			break;
		}
		
		case BUTTON_0 : {
			eFunPtrArr[5][uiEachColumnSize[5] - 1] = onReleaseListener;
			break;
		}
		
		default:
			break;		
		
	}
	
	
	return E_OK;
	
}