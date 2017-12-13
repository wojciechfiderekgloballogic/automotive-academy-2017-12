/**
 * Responsible: Piotr Ciesielczyk
 *
 *
 * History log:
 * 2017.12.12   PioCie  Updated hungarian notation 
 * 2017.12.11   PioCie  Initial version 
 */

#include <stdio.h>
#include "PIOCIE_task_4.h"

/* Every public function in your module should start with   "MODULENAME_"   prefix */
/* Every private function in your module should start with  "MODULENAME__"  prefix */

typedef struct
{
	int iSize;
	eErr_t (**eArr) (eButton_t);
} sButtonListener;

static sButtonListener aButtonsPress[BUTTON_COUNT];
static sButtonListener aButtonsRelease[BUTTON_COUNT];
static int iaButtonStatus[BUTTON_COUNT];
	
sButtonListener alloc_sButtonListener(int len) 
{
	sButtonListener sA = {len, len > 0 ? malloc(sizeof(eErr_t (*) (eButton_t)) * len) : NULL}; // size=len; eArr=malloc. If len<0 NULL pointer
    return sA;
}

sButtonListener realloc_sButtonListener(void* ptr, int len) 
{
	sButtonListener sA = {len, len > 0 ? realloc(ptr,sizeof(eErr_t (*) (eButton_t)) * len) : NULL};
    return sA;
}

eErr_t fnAddListener(sButtonListener *sA, eErr_t (*onPressListener) (eButton_t))
{
					
	eErr_t eReturn=E_OK;
	if (NULL==onPressListener) 							//check pointer to function
	{
		eReturn=E_INVALID_ARG_2;
	}
	else												//check if listener alredy exists ont this button
	{
		int i;
		for(i=0;i<sA->iSize;i++)
		{
			if(onPressListener==sA->eArr[i])
			{
				eReturn=E_LISTENER_ALREADY_EXISTS;
			}
			
		}
	}
	if(E_OK==eReturn)									//add listener
	{
		if(NULL==(*sA=realloc_sButtonListener(sA->eArr, sA->iSize+1)).eArr)
		{
			eReturn=E_MALLOC;
		}
		else
		{
			sA->eArr[sA->iSize-1]=onPressListener;
		}
	}
	
	return eReturn;
}

/* you should change iButtonState function if added buttons - map proper pins to propper buttons*/
int iButtonState(eButton_t eButton)
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
		default:{break;}
	}
	return iReturn;
}


void PIOCIE_vInit(void)
{			
	int i;
	for(i=0;i<BUTTON_COUNT;i++)															//allocate adresses for all buttons
	{
		aButtonsPress[i]=alloc_sButtonListener(0);						//Press
		aButtonsRelease[i]=alloc_sButtonListener(0);						//Release
		iaButtonStatus[i]=iButtonState(i);													//Read button status
	}
}

void PIOCIE_vHandleButtons (void){															//Executes button functions
	int i;
	for(i=0;i<BUTTON_COUNT;i++)
	{
		if(iaButtonStatus[i]!=iButtonState(i))													//button status changed
		{
			iaButtonStatus[i]=iButtonState(i);
			if(0==iaButtonStatus[i])														//button release (zmienic too 0 na zmienna jakas)
			{
				int j;
				for(j=0;j<aButtonsRelease[i].iSize;j++)									//execute all functions attatched to button i
				{
					aButtonsRelease[i].eArr[j](i);
				}
			}
			else if(1==iaButtonStatus[i])													//button press
			{
				int j;
				for(j=0;j<aButtonsPress[i].iSize;j++)									//execute all functions attatched to button i
				{
					aButtonsPress[i].eArr[j](i);
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
