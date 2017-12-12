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

 struct sListeners{
	int icounter : 16;
	int iarr_size : 16;
	pListener_func* afListeners;
	
} sListener_default = {0, 0, 0};

typedef struct sButtonListeners{
	struct sListeners sOnPress;
	struct sListeners sOnRelease;
	
} sButtonListeners_t;

sButtonListeners_t sListener[BUTTON_COUNT];

void callOnPressButtons(eButton_t eButton)
{
	for (int i=0; i < sListener[eButton].sOnPress.icounter;++i)
	{
		sListener[eButton].sOnPress.afListeners[i](eButton);
	}		
}

void callOnReleaseButtons(eButton_t eButton)
{
	for (int i=0; i < sListener[eButton].sOnRelease.icounter;++i)
	{
		sListener[eButton].sOnRelease.afListeners[i](eButton);
	}		
}

void GRZMAK_vInit()
{
	for(eButton_t i = BUTTON_START ;i< BUTTON_COUNT;++i)
	{
		sListener[i].sOnPress = sListener_default;
		sListener[i].sOnRelease = sListener_default;
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
		int iCount = sListener[eButton].sOnPress.icounter;
		int iArr_size = sListener[eButton].sOnPress.iarr_size;
		int iNewSize = 0;
		/* 	Check if function in listener */
		for(int i = 0; i < iCount; ++i)
		{
			if(sListener[eButton].sOnPress.afListeners[i] == onPressListener)
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
				sListener[eButton].sOnPress.iarr_size = sListener[eButton].sOnPress.iarr_size + 1;
				iNewSize = sListener[eButton].sOnPress.iarr_size;
				sListener[eButton].sOnPress.afListeners = realloc(sListener[eButton].sOnPress.afListeners,sizeof(sListener[eButton].sOnPress.afListeners) * iNewSize);
		
			}
			if(sListener[eButton].sOnPress.afListeners == 0)
			{	
				eResult = E_MALLOC;
			}
			else
			{
				sListener[eButton].sOnPress.icounter++;
				iCount = sListener[eButton].sOnPress.icounter;
				sListener[eButton].sOnPress.afListeners[iCount - 1] = onPressListener;
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
		int iCount = sListener[eButton].sOnRelease.icounter;
		int iArr_size = sListener[eButton].sOnRelease.iarr_size;
		int iNewSize = 0;
		/* 	Check if function in listener */
		for(int i = 0; i < iCount; ++i)
		{
			if(sListener[eButton].sOnRelease.afListeners[i] == onReleaseListener)
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
				sListener[eButton].sOnRelease.iarr_size++;
				iNewSize = sListener[eButton].sOnRelease.iarr_size;
				sListener[eButton].sOnRelease.afListeners = realloc(sListener[eButton].sOnRelease.afListeners,sizeof(sListener[eButton].sOnRelease.afListeners)* iNewSize);
		
			}
			if(sListener[eButton].sOnRelease.afListeners == 0)
			{	
				eResult = E_MALLOC;
			}
			else
			{
				sListener[eButton].sOnRelease.icounter++;
				iCount = sListener[eButton].sOnRelease.icounter;
				sListener[eButton].sOnRelease.afListeners[iCount - 1] = onReleaseListener;
			}
		
		}
	}
	else
	{
		eResult = E_INVALID_ARG_1;
	}
	return eResult;
}

