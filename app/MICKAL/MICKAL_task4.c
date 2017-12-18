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

//Table 
int aiOnPressCount[BUTTON_COUNT]={0};
int aiOnPressArraySize[BUTTON_COUNT]={0};
peFunction* apOnPressListeners[BUTTON_COUNT]={0};

int aiOnReleaseCount[BUTTON_COUNT]={0};
int aiOnReleaseArraySize[BUTTON_COUNT]={0};
peFunction* apOnReleaseListeners[BUTTON_COUNT]={0};
//end 


static void onButtonPress(eButton_t eButton) {
    int i = 0;
    int iCount = aiOnPressCount[eButton];
    
    for(i=0; i<iCount; i++) {
        apOnPressListeners[eButton][i](eButton);
    }
}

static void onButtonRelease(eButton_t eButton) {
    int i = 0;
    int iCount = aiOnReleaseCount[eButton];
    
    for(i=0; i<iCount; i++) {
        apOnReleaseListeners[eButton][i](eButton);
    }
}

void MICKAL_vInit() {
	for (eButton_t i = BUTTON_START;i<BUTTON_COUNT;++i)
	{
		apOnPressListeners[i] = malloc(sizeof(peFunction*));
		apOnReleaseListeners[i] = malloc(sizeof(peFunction*));
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
		int iCount = aiOnPressCount[eButton];
		int iArraySize = aiOnPressArraySize[eButton];
		int iNewSize = 0;
		
		for(int i = 0;i<iCount;++i)
		{
			if(apOnPressListeners[eButton][i] == onPressListener)
			{
				eResult = E_LISTENER_ALREADY_EXISTS;
				break;
			}
		}
		
		if(eResult == E_OK)
		{
			if(iCount == iArraySize)
			{
				aiOnPressArraySize[eButton]++;
				iNewSize = aiOnPressArraySize[eButton];
				
				apOnPressListeners[eButton] = realloc(
				apOnPressListeners[eButton],
				sizeof(apOnPressListeners[eButton])* iNewSize);
			}
			
			if(apOnPressListeners[eButton] == NULL)
			{
				eResult = E_MALLOC;
			}
			else
			{
				aiOnPressCount[eButton]++;
				iCount = aiOnPressCount[eButton];
				apOnPressListeners[eButton][iCount-1] = onPressListener;
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
		int iCount = aiOnReleaseCount[eButton];
		int iArraySize = aiOnReleaseArraySize[eButton];
		int iNewSize = 0;
		
		for(int i = 0;i<iCount;++i)
		{
			if(apOnReleaseListeners[eButton][i] == onReleaseListener)
			{
				eResult = E_LISTENER_ALREADY_EXISTS;
				break;
			}
		}
		
		if(eResult == E_OK)
		{
			if(iCount == iArraySize)
			{
				aiOnReleaseArraySize[eButton]++;
				iNewSize = aiOnReleaseArraySize[eButton];
				
				apOnReleaseListeners[eButton] = realloc(
				apOnReleaseListeners[eButton],
				sizeof(apOnReleaseListeners[eButton])* iNewSize);
			}
			
			if(apOnReleaseListeners[eButton] == NULL)
			{
				eResult = E_MALLOC;
			}
			else
			{
				aiOnReleaseCount[eButton]++;
				iCount = aiOnReleaseCount[eButton];
				apOnReleaseListeners[eButton][iCount-1] = onReleaseListener;
			}
		}
		
	}else{
		eResult = E_INVALID_ARG_1;
	}
		
		return eResult;
	
}
 
 