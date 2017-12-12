/**
 * Responsible: Paw Azi
 *
 *
 * History log:
 *  06.12.2017 initial version
 */

#include <stdio.h>
#include <stdlib.h>
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

/*
	Attention!!
	Update eMappedBtns after adding or removing buttons.
*/
static eButton_t eMappedBtns [BUTTON_COUNT] = {BUTTON_1,BUTTON_2,BUTTON_0};


static eErr_t (**eFunPtrArr[BUTTON_COUNT*2])(eButton_t);
static uint8_t auiStateBtn[BUTTON_COUNT];
static uint8_t uiEachColumnSize[BUTTON_COUNT*2];


void  PAWAZI_vInit(void){

	for( int i = 0 ; i < 6 ; i++){
		if( (eFunPtrArr[i] = malloc( (10) * sizeof (eFunPtrArr))) == NULL){
			printf("error - cant allocate 2d array\n");
		}
	}		
}



void   PAWAZI_vHandleButtons(void){
	
	
		for(eButton_t i = BUTTON_START ; i < BUTTON_COUNT ; i++){
			
			if(IO_get(i) && !auiStateBtn[i]){
				
				for(int j = 0 ; j < uiEachColumnSize[i*2] ; j++){
					eFunPtrArr[i*2][j](eMappedBtns[i]);
				}
				
				auiStateBtn[i] = 1;
				
			}else if(!IO_get(i) && auiStateBtn[i]){
				
				for(int j = 0 ; j < uiEachColumnSize[i*2+1] ; j++){
					eFunPtrArr[i*2+1][j](eMappedBtns[i]);
				}
				
				auiStateBtn[i] = 0;
			}
			
		}
	
	

	// if(IO_get(IO_PIN_0) && !auiStateBtn[0]){
		
		// for(int i = 0 ; i < uiEachColumnSize[0] ; i++){
			// eFunPtrArr[0][i](BUTTON_1);
		// }
		
		// auiStateBtn[0] = 1;
		
	// }else if(!IO_get(IO_PIN_0) && auiStateBtn[0]){
		
		// for(int i = 0 ; i < uiEachColumnSize[1] ; i++){
			// eFunPtrArr[1][i](BUTTON_1);
		// }
		
		// auiStateBtn[0] = 0;
		
	// }

	// if(IO_get(IO_PIN_1) && !auiStateBtn[1]){
		
		// for(int i = 0 ; i < uiEachColumnSize[2] ; i++){
			// eFunPtrArr[2][i](BUTTON_2);
		// }
		
		// auiStateBtn[1] = 1;
		
	// }else if(!IO_get(IO_PIN_1) && auiStateBtn[1]){
		
		// for(int i = 0 ; i < uiEachColumnSize[3] ; i++){
			// eFunPtrArr[3][i](BUTTON_2);
		// }
		
		// auiStateBtn[1] = 0;
		
	// }
	
	
	// if(IO_get(IO_PIN_2) && !auiStateBtn[2]){
		
		// for(int i = 0 ; i < uiEachColumnSize[4] ; i++){
			// eFunPtrArr[4][i](BUTTON_0);
		// }

		// auiStateBtn[2] = 1;
		
	// }else if( !IO_get(IO_PIN_2) && auiStateBtn[2]){
		
		// for(int i = 0 ; i < uiEachColumnSize[5] ; i++){
			// eFunPtrArr[5][i](BUTTON_0);
		// }
		
		// auiStateBtn[2] = 0;
		
	// }

	

}

eErr_t PAWAZI_eAddOnPressListener(eButton_t eButton, eErr_t (*onPressListener) (eButton_t)){
	
	eErr_t eResult = E_OK;
	
	if(eButton < BUTTON_START || eButton >= BUTTON_COUNT){
		
		eResult = E_INVALID_ARG_1;
		
	}else if(onPressListener == NULL){
		
		eResult = E_INVALID_ARG_2;
		
	}else{

		switch(eButton){
			
			case BUTTON_1 : {
				
				for(int i = 0 ; i < uiEachColumnSize[0] ; i++){
					if(onPressListener == eFunPtrArr[0][i]){
						eResult = E_LISTENER_ALREADY_EXISTS;
						break;
					}
				}
				
				if(eResult != E_LISTENER_ALREADY_EXISTS){
					eFunPtrArr[0][uiEachColumnSize[0]] = onPressListener;
					uiEachColumnSize[0]++;			
				}
				
				break;
			}
			
			case BUTTON_2 : {
				
				for(int i = 0 ; i < uiEachColumnSize[2] ; i++){
					if(onPressListener == eFunPtrArr[2][i]){
						eResult = E_LISTENER_ALREADY_EXISTS;
						break;
					}
				}
				
				if(eResult != E_LISTENER_ALREADY_EXISTS){
					eFunPtrArr[2][uiEachColumnSize[2]] = onPressListener;
					uiEachColumnSize[2]++;
					
				}
				
				break;
	
			}
			
			case BUTTON_0 : {
				
				for(int i = 0 ; i < uiEachColumnSize[4] + 1; i++){
					
					if(onPressListener == eFunPtrArr[4][i]){
						eResult = E_LISTENER_ALREADY_EXISTS;
						break;
					}						
					
				}
				
				if(eResult != E_LISTENER_ALREADY_EXISTS){
				
					eFunPtrArr[4][uiEachColumnSize[4]] = onPressListener;
					uiEachColumnSize[4] ++;
									
				}
				
				break;
			}
			
			default:
				break;
			
			
		}
	}
		
	return eResult;
	
}


eErr_t PAWAZI_eAddOnReleaseListener(eButton_t eButton, eErr_t (*onReleaseListener) (eButton_t)){
	
	eErr_t eResult = E_OK;

	if(eButton < BUTTON_START || eButton >= BUTTON_COUNT){
		
		eResult = E_INVALID_ARG_1;
			
	}else if(onReleaseListener == NULL){
		
		eResult = E_INVALID_ARG_2;
		
	}else{
	
		switch(eButton){
			
			case BUTTON_1 : {
				
				for(int i = 0 ; i < uiEachColumnSize[1] ; i++){
					if(onReleaseListener == eFunPtrArr[1][i]){
						eResult = E_LISTENER_ALREADY_EXISTS;
						break;
					}
				}
				
				if(eResult != E_LISTENER_ALREADY_EXISTS){
					eFunPtrArr[1][uiEachColumnSize[1]] = onReleaseListener;
					uiEachColumnSize[1]++;		
				}
				
				break;
			}
			
			case BUTTON_2 : {
				
				for(int i = 0 ; i < uiEachColumnSize[3] ; i++){
					if(onReleaseListener == eFunPtrArr[3][i]){
						eResult = E_LISTENER_ALREADY_EXISTS;
						break;
					}
				}
				
				if(eResult != E_LISTENER_ALREADY_EXISTS){
					eFunPtrArr[3][uiEachColumnSize[3]] = onReleaseListener;
					uiEachColumnSize[3]++;		
				}
				
				break;
			}
			
			case BUTTON_0 : {
			
				
				for(int i = 0 ; i < uiEachColumnSize[5]; i++){		
					if(onReleaseListener == eFunPtrArr[5][i]){			
						eResult = E_LISTENER_ALREADY_EXISTS;
						break;
					}						
				}
				
				if(eResult != E_LISTENER_ALREADY_EXISTS){				
					eFunPtrArr[5][uiEachColumnSize[5]] = onReleaseListener;
					uiEachColumnSize[5]++;		
				}
				
				break;
			}
			
			default:
				break;		
			
		}
	}
	
	
	return eResult;
	
}