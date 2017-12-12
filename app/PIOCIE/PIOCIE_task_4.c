/**
 * Responsible: Piotr Ciesielczyk
 *
 *
 * History log:
 * 2017.12.11   PioCie  Initial version 
 */

#include <stdio.h>
#include "PIOCIE_task_4.h"
#define uint8_t unsigned char
/* Every public function in your module should start with   "MODULENAME_"   prefix */
/* Every private function in your module should start with  "MODULENAME__"  prefix */

typedef struct
{
	int size;
	eErr_t (**arr) (eButton_t);
} buttonListener;


	
buttonListener alloc_buttonListener(int len) 
{
	buttonListener a = {len, len > 0 ? malloc(sizeof(eErr_t (*) (eButton_t)) * len) : NULL}; // size=len; arr=malloc. If len<0 NULL pointer
    return a;
}

buttonListener realloc_buttonListener(void* ptr, int len) 
{
	buttonListener a = {len, len > 0 ? realloc(ptr,sizeof(eErr_t (*) (eButton_t)) * len) : NULL};
    return a;
}

eErr_t fnAddListener(buttonListener *a, eErr_t (*onPressListener) (eButton_t))
{
					
	eErr_t eReturn=E_OK;
	if (NULL==onPressListener) 							//check pointer to function
	{
		eReturn=E_INVALID_ARG_2;
	}
	else												//check if listener alredy exists ont this button
	{
		int i=0;
		for(i=0;i<a->size;i++)
		{
			if(onPressListener==a->arr[i])
			{
				eReturn=E_LISTENER_ALREADY_EXISTS;
			}
			
		}
	}
	if(E_OK==eReturn)									//add listener
	{
		if(NULL==(*a=realloc_buttonListener(a->arr, a->size+1)).arr)
		{
			eReturn=E_MALLOC;
		}
		else
		{
			a->arr[a->size-1]=onPressListener;
		}
	}
	
	return eReturn;
}

static buttonListener aButtonsPress[BUTTON_COUNT];
static buttonListener aButtonsRelease[BUTTON_COUNT];
static int buttonStatus[BUTTON_COUNT];

/* you should change buttonState function if added buttons - map proper pins to propper buttons*/
int buttonState(eButton_t eButton)
{
	int iReturn;
	switch(eButton)
	{
		case BUTTON_1:
		{
			iReturn=IO_get(IO_PIN_0);//Button 1
			break;
		}
		case BUTTON_2:
		{
			iReturn=IO_get(IO_PIN_1);//Button 2
			break;
		}
		case BUTTON_0:
		{
			iReturn=IO_get(IO_PIN_2);//Button 0
			break;
		}
		default:
		{
			iReturn=-1; 							//dunno
		}
	}
	return iReturn;
}


void PIOCIE_vInit(void)
{			
	int i=0;
	for(i=0;i<BUTTON_COUNT;i++)															//allocate adresses for all buttons
	{
		aButtonsPress[i]=alloc_buttonListener(0);						//Press
		aButtonsRelease[i]=alloc_buttonListener(0);						//Release
		buttonStatus[i]=buttonState(i);													//Read button status
	}
}

/*
eErr_t PIOCIE_vInit(void)
{			
	eErr_t eReturn=E_OK;
	int i=0;
	for(i=0;i<BUTTON_COUNT;i++)															//allocate adresses for all buttons
	{
		if(NULL==(aButtonsPress[i]=alloc_buttonListener(0)).arr)						//Press
		{
			eReturn=E_MALLOC;
		}
		if(NULL==(aButtonsRelease[i]=alloc_buttonListener(0)).arr)						//Release
		{
			eReturn=E_MALLOC;
		}
		buttonStatus[i]=buttonState(i);													//Read button status
	}
	return eReturn;
}
*/
void PIOCIE_vHandleButtons (void){															//Executes button functions
	int i=0;
	for(i=0;i<BUTTON_COUNT;i++)
	{
		if(buttonStatus[i]!=buttonState(i))													//button status changed
		{
			buttonStatus[i]=buttonState(i);
			if(0==buttonStatus[i])														//putton pressed (zmienic too 0 na zmienna jakas)
			{
				int j=0;
				for(j=0;j<aButtonsRelease[i].size;j++)									//execute all functions attatched to button i
				{
					aButtonsRelease[i].arr[j](i);
				}
			}
			else if(1==buttonStatus[i])													//button released
			{
				int j=0;
				for(j=0;j<aButtonsPress[i].size;j++)									//execute all functions attatched to button i
				{
					aButtonsRelease[i].arr[j](i);
				}
			}
		}
	}
}

eErr_t PIOCIE_eAddOnPressListener   (eButton_t eButton, eErr_t (*onPressListener) (eButton_t)){
	eErr_t eReturn;
	if(NULL==onPressListener)
	{
		eReturn=E_INVALID_ARG_2;
	}
	else if(eButton<BUTTON_START||eButton>=BUTTON_COUNT)
	{
		eReturn=E_INVALID_ARG_1;
	}
	else 
	{	
		eReturn=fnAddListener(&aButtonsPress[eButton],onPressListener);
	}
	return eReturn;
}

eErr_t PIOCIE_eAddOnReleaseListener (eButton_t eButton, eErr_t (*onPressListener) (eButton_t)){
	eErr_t eReturn;
	if(NULL==onPressListener)
	{
		eReturn=E_INVALID_ARG_2;
	}
	else if(eButton<BUTTON_START||eButton>=BUTTON_COUNT)
	{
		eReturn=E_INVALID_ARG_1;
	}
	else 
	{	
		eReturn=fnAddListener(&aButtonsRelease[eButton],onPressListener);
	}
	return eReturn;
}
