/**
* Responsible: Grzegorz Makowski
*
*
*History Log:
* 2017.12.11 GRZMAK initial version
*
**/



#include "GRZMAK_task4.h"

static const int aiButtonToPin[BUTTON_COUNT] = {
	IO_PIN_2,
	IO_PIN_0,
	IO_PIN_1
};
static int iMapButtonToPin(eButton_t eButton)
{
	return aiButtonToPin[eButton];
}

typedef eErr_t (*pListener_func)(eButton_t);

 
int aiOnPressCount[BUTTON_COUNT];
int aiOnPressArraySize[BUTTON_COUNT];
pListener_func* apOnPressListeners[BUTTON_COUNT];


int aiOnReleaseCount[BUTTON_COUNT];
int aiOnReleaseArraySize[BUTTON_COUNT];
pListener_func* apOnReleaseListeners[BUTTON_COUNT];

void callOnPressButtons(eButton_t eButton)
{
	for (int i=0; i < aiOnPressCount[eButton];++i)
	{
		apOnPressListeners[eButton][i](eButton);
	}		
}

void callOnReleaseButtons(eButton_t eButton)
{
	for (int i=0; i < aiOnReleaseCount[eButton];++i)
	{
		apOnReleaseListeners[eButton][i](eButton);		
	}		
}

void GRZMAK_vInit()
{
	for(eButton_t i = BUTTON_START ;i< BUTTON_COUNT;++i)
	{
		apOnPressListeners[i] = malloc(sizeof(pListener_func*));
		apOnReleaseListeners[i] = malloc(sizeof(pListener_func*));
	}

}
	static int aiPrevStates[BUTTON_COUNT] = {0, 0, 0};	
	
void vHandleButton(eButton_t eButton)
{
		int iButton = iMapButtonToPin(eButton);
		int iPrevPinState = aiPrevStates[eButton];
		int iCurrState = IO_get(iButton);
		
		
		if(iPrevPinState == 0 && iCurrState == 1) 
		{
			callOnPressButtons(eButton);
		}
		if(iPrevPinState == 1 && iCurrState == 0 )
		{
			callOnReleaseButtons(eButton);
		}
		
		aiPrevStates[eButton] = iCurrState;
	
}
void GRZMAK_vHandleButtons()
{
	for(eButton_t i = BUTTON_START;i< BUTTON_COUNT;++i)
		vHandleButton(i);
}

eErr_t GRZMAK_eAddOnPressListener(eButton_t eButton, eErr_t (*onPressListener) (eButton_t))
{
	eErr_t eResult = E_OK;
	if(eButton >= BUTTON_START && eButton < BUTTON_COUNT)
	{
		int iCount = aiOnPressCount[eButton];
		int iArr_size = aiOnPressArraySize[eButton];
		int iNewSize = 0;
		/* 	Check if function in listener */
		for(int i = 0; i < iCount; ++i)
		{
			if(apOnPressListeners[eButton][i] == onPressListener)
			{	
				eResult = E_LISTENER_ALREADY_EXISTS;
				break;
			}
		}
		if(eResult == E_OK)
		{
			/* check if enough space */
			if(iCount == iArr_size)
			{
				aiOnPressArraySize[eButton] = aiOnPressArraySize[eButton] + 1;
				iNewSize = aiOnPressArraySize[eButton];
				apOnPressListeners[eButton] = realloc(apOnPressListeners[eButton],sizeof(apOnPressListeners[eButton]) * iNewSize);
		
			}
			if(apOnPressListeners[eButton] == 0)
			{	
				eResult = E_MALLOC;
			}
			else
			{
				aiOnPressCount[eButton] = aiOnPressCount[eButton] + 1;
				iCount = aiOnPressCount[eButton];
				apOnPressListeners[eButton][iCount - 1] = onPressListener;
			}
		
		}
	}
	else
	{
		eResult = E_INVALID_ARG_1;
	}
	return eResult;
}


eErr_t GRZMAK_eAddOnReleaseListener(eButton_t eButton, eErr_t (*onReleaseListener) (eButton_t))
{
	eErr_t eResult = E_OK;
	if(eButton >= BUTTON_START && eButton < BUTTON_COUNT)
	{
		int iCount = aiOnReleaseCount[eButton];
		int iArr_size = aiOnReleaseArraySize[eButton];
		int iNewSize = 0;
		/* 	Check if function in listener */
		for(int i = 0; i < iCount; ++i)
		{
			if(apOnReleaseListeners[eButton][i] == onReleaseListener)
			{	
				eResult = E_LISTENER_ALREADY_EXISTS;
				break;
			}
		}
		if(eResult == E_OK)
		{
			/* check if enough space */
			if(iCount == iArr_size)
			{
				aiOnReleaseArraySize[eButton] = aiOnReleaseArraySize[eButton] + 1;
				iNewSize = aiOnReleaseArraySize[eButton];
				apOnReleaseListeners[eButton] = realloc(apOnReleaseListeners[eButton],sizeof(apOnReleaseListeners[eButton]) * iNewSize);
		
			}
			if(apOnReleaseListeners[eButton] == 0)
			{	
				eResult = E_MALLOC;
			}
			else
			{
				aiOnReleaseCount[eButton] = aiOnReleaseCount[eButton] + 1;
				iCount = aiOnReleaseCount[eButton];
				apOnReleaseListeners[eButton][iCount - 1] = onReleaseListener;
			}
		
		}
	}
	else
	{
		eResult = E_INVALID_ARG_1;
	}
	return eResult;
}

