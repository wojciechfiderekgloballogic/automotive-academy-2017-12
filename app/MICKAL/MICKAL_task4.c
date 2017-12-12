/**
 * Responsible: Michal Kaliszczyk
 *
 *
 * History log:
 * 2017.12.05   MICKAL  Initial version
 */

 
 #include "MICKAL_task4.h"
 #include "stdint.h"
 #include "stdio.h"
 
 
typedef eErr_t (*peFunction) (eButton_t);

struct sListeners {
    int iCount;
    int iArraySize;
    peFunction* afListeners;
} sListeners_t_defaulte = {0, 0, 0};

typedef struct sListeners sListeners_t;

typedef struct sButtonListeners {
    sListeners_t sOnPress;
    sListeners_t sOnRelease;
} sButtonListeners_t;

static sButtonListeners_t asListeners[BUTTON_COUNT];


static void onButtonPress(eButton_t eButton) {
    int i = 0;
    int iCount = asListeners[eButton].sOnPress.iCount;
    
    for(i=0; i<iCount; i++) {
        asListeners[eButton].sOnPress.afListeners[i](eButton);
    }
}

static void onButtonRelease(eButton_t eButton) {
    int i = 0;
    int iCount = asListeners[eButton].sOnRelease.iCount;
    
    for(i=0; i<iCount; i++) {
        asListeners[eButton].sOnRelease.afListeners[i](eButton);
    }
}

void MICKAL_vInit() {
    eButton_t eButton = BUTTON_START;
    
    for(eButton=BUTTON_START; eButton<BUTTON_COUNT; eButton++) {
        asListeners[eButton].sOnPress = sListeners_t_defaulte;
        asListeners[eButton].sOnRelease = sListeners_t_defaulte;
    }
}

static int aiPrevPinStates[BUTTON_COUNT] = {
    0,
    0,
    0
};

static int iCurr,iPrev;
 
 void vHandleButton(eButton_t eButton) {   
 
	
	switch(eButton)
	{
		case BUTTON_0:
		{
			iCurr = IO_get(IO_PIN_2);
			iPrev = aiPrevPinStates[eButton];
			break;
		}
		case BUTTON_1:
		{
			iCurr = IO_get(IO_PIN_0);
			iPrev = aiPrevPinStates[eButton];
			break;
		}
		case BUTTON_2:
		{
			iCurr = IO_get(IO_PIN_1);
			iPrev = aiPrevPinStates[eButton];
			break;
		}
		default:
			printf("Exceptions");
	}
	
	if(iPrev == 0 && iCurr ==1)
	{
		onButtonPress(eButton);
	}
	if(iPrev == 1 && iCurr ==0)
	{
		onButtonRelease(eButton);
	}
	
	aiPrevPinStates[eButton] = iCurr;
 }
	
	
			
		
 
 
 void MICKAL_vHandleButtons(void)
 {
	eButton_t eButton = BUTTON_START;
    
    for(eButton = BUTTON_START; eButton < BUTTON_COUNT; eButton++) {
        vHandleButton(eButton);
    }
	 
 }

 
eErr_t MICKAL_eAddOnPressListener(eButton_t eButton, eErr_t (*onPressListener) (eButton_t))
{
	eErr_t eResult = E_OK;
	
	if(eButton>=BUTTON_START && eButton < BUTTON_COUNT)
	{
		int iCount = asListeners[eButton].sOnPress.iCount;
		int iArraySize = asListeners[eButton].sOnPress.iArraySize;
		int iNewSize = 0;
		
		for(int i = 0;i<iCount;++i)
		{
			if(asListeners[eButton].sOnPress.afListeners[i] == onPressListener)
			{
				eResult = E_LISTENER_ALREADY_EXISTS;
				break;
			}
		}
		
		if(eResult == E_OK)
		{
			if(iCount == iArraySize)
			{
				asListeners[eButton].sOnPress.iArraySize++;
				iNewSize = asListeners[eButton].sOnPress.iArraySize;
				
				asListeners[eButton].sOnPress.afListeners = realloc(
				asListeners[eButton].sOnPress.afListeners,
				sizeof(asListeners[eButton].sOnPress.afListeners)* iNewSize);
			}
			
			if(asListeners[eButton].sOnPress.afListeners == NULL)
			{
				eResult = E_MALLOC;
			}
			else
			{
				asListeners[eButton].sOnPress.iCount++;
				iCount = asListeners[eButton].sOnPress.iCount;
				asListeners[eButton].sOnPress.afListeners[iCount-1] = onPressListener;
			}
		}
		
	}else{
		eResult = E_INVALID_ARG_1;
	}
		
		return eResult;
			
}

eErr_t MICKAL_eAddOnReleaseListener(eButton_t eButton, eErr_t (*onReleaseListener) (eButton_t))
{
	eErr_t eResult = E_OK;
	
	if(eButton>=BUTTON_START && eButton < BUTTON_COUNT)
	{
		int iCount = asListeners[eButton].sOnRelease.iCount;
		int iArraySize = asListeners[eButton].sOnRelease.iArraySize;
		int iNewSize = 0;
		
		for(int i = 0;i<iCount;++i)
		{
			if(asListeners[eButton].sOnRelease.afListeners[i] == onReleaseListener)
			{
				eResult = E_LISTENER_ALREADY_EXISTS;
				break;
			}
		}
		
		if(eResult == E_OK)
		{
			if(iCount == iArraySize)
			{
				asListeners[eButton].sOnRelease.iArraySize++;
				iNewSize = asListeners[eButton].sOnRelease.iArraySize;
				
				asListeners[eButton].sOnRelease.afListeners = realloc(
				asListeners[eButton].sOnRelease.afListeners,
				sizeof(asListeners[eButton].sOnRelease.afListeners)* iNewSize);
			}
			
			if(asListeners[eButton].sOnRelease.afListeners == NULL)
			{
				eResult = E_MALLOC;
			}
			else
			{
				asListeners[eButton].sOnRelease.iCount++;
				iCount = asListeners[eButton].sOnRelease.iCount;
				asListeners[eButton].sOnRelease.afListeners[iCount-1] = onReleaseListener;
			}
		}
		
	}else{
		eResult = E_INVALID_ARG_1;
	}
		
		return eResult;
	
}
 
 
 