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
	array that holds pointers for handlers (press and release)
	
	[ B1 onPress ] [ B1 onReleased ] [ B2 onPress ] [ B2 onRelease] [ B0 onPresse] [ B0 onRelease ] ...
	  OnPress            OnRelease          OnPress       OnRelease     	OnPress       OnRelease
		  |				   |				|				|			   |				|
		 \ / 			  \ /			   \ /			   \ /	          \ /			   \ /	
*/

/*
	Attention!!
	Update eMappedBtns after added or removed buttons.
*/
static eButton_t eMappedBtns [BUTTON_COUNT] = {BUTTON_1,BUTTON_2,BUTTON_0};

/*
	Attention!!
	Update eMappedArr after added or removed buttons.
*/
typedef enum eMappedArr{
	
	EMB_1 = 4,
	EMB_2 = 0,
	EMB_3 = 2	
	
}eMappedArr_t;

static eMappedArr_t eMappedArrBtns [BUTTON_COUNT] = {EMB_1,EMB_2,EMB_3};

static eErr_t (**eFunPtrArr[BUTTON_COUNT*2])(eButton_t);
static eErr_t (**eFunPtrArrTemp)(eButton_t);
static unsigned int auiStateBtn[BUTTON_COUNT];
static unsigned int uiEachColumnSize[BUTTON_COUNT*2] = {1,1,1,1,1,1};


void  PAWAZI_vInit(void){

	for( int i = 0 ; i < 6 ; i++){
		if( (eFunPtrArr[i] = malloc( (1) * sizeof (eFunPtrArr))) == NULL){
			printf("error - cant allocate 2d array\n");
		}else{
			eFunPtrArr[i][0] = NULL;
		}
	}
	
}

void   PAWAZI_vHandleButtons(void){
	
	
	for(eButton_t i = BUTTON_START ; i < BUTTON_COUNT ; i++){
		
		if(IO_get(i) && !auiStateBtn[i]){
			
			for(int j = 0 ; j < uiEachColumnSize[i*2] ; j++){
				if( eFunPtrArr[i*2][j] !=  NULL){
					eFunPtrArr[i*2][j](eMappedBtns[i]);
				}
			}
			
			auiStateBtn[i] = 1;
			
		}else if(!IO_get(i) && auiStateBtn[i]){
			
			for(int j = 0 ; j < uiEachColumnSize[i*2+1] ; j++){
				if(eFunPtrArr[i*2+1][j] != NULL){	
					eFunPtrArr[i*2+1][j](eMappedBtns[i]);
				}
			}
			
			auiStateBtn[i] = 0;
		}
		
	}

}

eErr_t PAWAZI_eAddOnPressListener(eButton_t eButton, eErr_t (*onPressListener) (eButton_t)){
	
	eErr_t eResult = E_OK;
	
	if(eButton < BUTTON_START || eButton >= BUTTON_COUNT){
		
		eResult = E_INVALID_ARG_1;
		
	}else if(onPressListener == NULL){
		
		eResult = E_INVALID_ARG_2;
		
	}else{
		
		unsigned int uiIndexBtnPress = eMappedArrBtns[eButton];
		
	
		if ( uiEachColumnSize[uiIndexBtnPress] == 2 || (!uiEachColumnSize[uiIndexBtnPress] % 10)){
			
			eFunPtrArrTemp = realloc(eFunPtrArr[uiIndexBtnPress], sizeof(eFunPtrArr) * 10);
			eFunPtrArr[uiIndexBtnPress] = eFunPtrArrTemp;
			
		}
	

		for ( int i = 0 ; i < uiEachColumnSize[uiIndexBtnPress] ; i++ ){
			
			if(onPressListener == eFunPtrArr[uiIndexBtnPress][i]){
					eResult = E_LISTENER_ALREADY_EXISTS;
					break;
			}
		}

		if(eResult != E_LISTENER_ALREADY_EXISTS){
			
			eFunPtrArr[uiIndexBtnPress][uiEachColumnSize[uiIndexBtnPress]] = onPressListener;
			uiEachColumnSize[uiIndexBtnPress]++;
			
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

		unsigned int uiIndexBtnRel = eMappedArrBtns[eButton]+1;
		
		if ( uiEachColumnSize[uiIndexBtnRel] == 2 || (!uiEachColumnSize[uiIndexBtnRel] % 10)){
		
			eFunPtrArrTemp = realloc(eFunPtrArr[uiIndexBtnRel], sizeof(eFunPtrArr) * 10);
			eFunPtrArr[uiIndexBtnRel] = eFunPtrArrTemp;
		
		}
		
	
		for ( int i = 0 ; i < uiEachColumnSize[uiIndexBtnRel] ; i++ ){
			
			if(onReleaseListener == eFunPtrArr[uiIndexBtnRel][i]){
				eResult = E_LISTENER_ALREADY_EXISTS;
				break;
			}
		}

		if(eResult != E_LISTENER_ALREADY_EXISTS){
			
			eFunPtrArr[uiIndexBtnRel][uiEachColumnSize[uiIndexBtnRel]] = onReleaseListener;
			uiEachColumnSize[uiIndexBtnRel]++;
			
		}			
	
	}
	
	
	return eResult;
	
}