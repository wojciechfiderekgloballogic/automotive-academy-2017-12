/**
 * Responsible: Adam Kordykiewicz
 *
 *
 * History log:
 * 2017.12.12   ADAKOR  Initial version
 */
 
#include "./ADAKOR_task4.h"
#include <stdio.h>

//Storage of functions
typedef eErr_t (*fListener) (eButton_t);

typedef struct
{
	unsigned uCount;
	unsigned uArraySize;
	fListener* arrfListeners;
} sListener;

typedef struct
{
	sListener sOnPress;
	sListener sOnRelease;
} sButton;

sButton arrsFunctions[BUTTON_COUNT];
//---

//Mapping pins to buttons
unsigned arruPinsToButtons[BUTTON_COUNT] = { IO_PIN_2, IO_PIN_0, IO_PIN_1 };
//---

//Previous states of pins
unsigned arruPreviousStatesOfPins[BUTTON_COUNT] = { 0, 0, 0 };
//---

void ADAKOR_vHandleButtons (void)
{
	for (eButton_t eButton = BUTTON_START; eButton < BUTTON_COUNT; eButton++)
	{
		unsigned uWhichPin = arruPinsToButtons[eButton];
		unsigned uPreviousState = arruPreviousStatesOfPins[eButton];
		unsigned uCurrentState = IO_get(uWhichPin);
		
		if (uPreviousState == 0 && uCurrentState == 1)
		{
			unsigned uCurrentCount = arrsFunctions[eButton].sOnPress.uCount;
			unsigned uIndex = 0;
			
			for(uIndex = 0; uIndex < uCurrentCount; uIndex++)
			{
				arrsFunctions[eButton].sOnPress.arrfListeners[uIndex](eButton);
			}
		}
		
		if (uPreviousState == 1 && uCurrentState == 0)
		{
			unsigned uCurrentCount = arrsFunctions[eButton].sOnRelease.uCount;
			unsigned uIndex = 0;
			
			for(uIndex = 0; uIndex < uCurrentCount; uIndex++)
			{
				arrsFunctions[eButton].sOnRelease.arrfListeners[uIndex](eButton);
			}
		}
		
		arruPreviousStatesOfPins[eButton] = uCurrentState;
	}
}

eErr_t ADAKOR_eAddOnPressListener (eButton_t eButton, eErr_t (*onPressListener) (eButton_t))
{
	eErr_t eResult = E_OK;
	
	if (eButton >= BUTTON_START && eButton < BUTTON_COUNT)
	{
		unsigned uCurrentCount = arrsFunctions[eButton].sOnPress.uCount;
		unsigned uCurrentArraySize = arrsFunctions[eButton].sOnPress.uArraySize;
		unsigned uNewSize = 0;
		unsigned uIndex = 0;
		for (uIndex = 0; uIndex < uCurrentCount; uIndex++)
		{
			if (arrsFunctions[eButton].sOnPress.arrfListeners[uIndex] == onPressListener)
			{
				eResult = E_LISTENER_ALREADY_EXISTS;
				break;
			}
		}
		
		//Check if the arrfListeners is full and resize if necessary
		if (eResult == E_OK)
		{
			if (uCurrentCount == uCurrentArraySize)
			{
				arrsFunctions[eButton].sOnPress.uArraySize = arrsFunctions[eButton].sOnPress.uArraySize + 1;
				uNewSize = arrsFunctions[eButton].sOnPress.uArraySize;
				arrsFunctions[eButton].sOnPress.arrfListeners = realloc(arrsFunctions[eButton].sOnPress.arrfListeners,
																		sizeof(arrsFunctions[eButton].sOnPress.arrfListeners)
																		* uNewSize);
			}
			
			//Check if the array is in 0 address
			if (arrsFunctions[eButton].sOnPress.arrfListeners == 0)
			{
				eResult = E_MALLOC;
			}
			else
			{
				//Add new function
				arrsFunctions[eButton].sOnPress.uCount++;
				uCurrentCount = arrsFunctions[eButton].sOnPress.uCount;
				arrsFunctions[eButton].sOnPress.arrfListeners[uCurrentCount - 1] = onPressListener;
			}
		}
	}
	else
	{
		eResult = E_INVALID_ARG_1;
	}
	
	return eResult;
}

eErr_t ADAKOR_eAddOnReleaseListener (eButton_t eButton, eErr_t (*onReleaseListener) (eButton_t))
{
	eErr_t eResult = E_OK;
	
	if (eButton >= BUTTON_START && eButton < BUTTON_COUNT)
	{
		unsigned uCurrentCount = arrsFunctions[eButton].sOnRelease.uCount;
		unsigned uCurrentArraySize = arrsFunctions[eButton].sOnRelease.uArraySize;
		unsigned uNewSize = 0;
		unsigned uIndex = 0;
		for (uIndex = 0; uIndex < uCurrentCount; uIndex++)
		{
			if (arrsFunctions[eButton].sOnRelease.arrfListeners[uIndex] == onReleaseListener)
			{
				eResult = E_LISTENER_ALREADY_EXISTS;
				break;
			}
		}
		
		//Check if the arrfListeners is full and resize if necessary
		if (eResult == E_OK)
		{
			if (uCurrentCount == uCurrentArraySize)
			{
				arrsFunctions[eButton].sOnRelease.uArraySize = arrsFunctions[eButton].sOnRelease.uArraySize + 1;
				uNewSize = arrsFunctions[eButton].sOnRelease.uArraySize;
				arrsFunctions[eButton].sOnRelease.arrfListeners = realloc(arrsFunctions[eButton].sOnRelease.arrfListeners,
																		sizeof(arrsFunctions[eButton].sOnRelease.arrfListeners)
																		* uNewSize);
			}
			
			//Check if the array is in 0 address
			if (arrsFunctions[eButton].sOnRelease.arrfListeners == 0)
			{
				eResult = E_MALLOC;
			}
			else
			{
				//Add new function
				arrsFunctions[eButton].sOnRelease.uCount++;
				uCurrentCount = arrsFunctions[eButton].sOnRelease.uCount;
				arrsFunctions[eButton].sOnRelease.arrfListeners[uCurrentCount - 1] = onReleaseListener;
			}
		}
	}
	else
	{
		eResult = E_INVALID_ARG_1;
	}
	
	return eResult;
}

void ADAKOR_vInit()
{
	for (eButton_t eButton = BUTTON_START; eButton < BUTTON_COUNT; eButton++)
	{
		//Reset sOnPress
		arrsFunctions[eButton].sOnPress.uCount = 0;
		arrsFunctions[eButton].sOnPress.uArraySize = 0;
		arrsFunctions[eButton].sOnPress.arrfListeners = 0;
		
		//Reset sOnRelease
		arrsFunctions[eButton].sOnRelease.uCount = 0;
		arrsFunctions[eButton].sOnRelease.uArraySize = 0;
		arrsFunctions[eButton].sOnRelease.arrfListeners = 0;
	}
}