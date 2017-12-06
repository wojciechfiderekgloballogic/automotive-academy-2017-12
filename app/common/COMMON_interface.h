/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.05   WojFid  eLampState_t introduced
 * 2017.12.01   WojFid  Initial version
 */
#pragma once

#include <windows.h>


/* Change console window output text color */
#define OUT_YELLOW()    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN)
#define OUT_RED()       SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED)
#define OUT_GREEN()     SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN)
#define OUT_WHITE()     SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)




/**
 * Common error return type definition
 */
typedef enum eErr {
    E_OK = 0,           /* Ok, no error */
    E_INVALID_ARG_1,    /* First  input argument invalid */
    E_INVALID_ARG_2,    /* Second -||- */
    
    E_NOT_IMPLEMENTED,  /* Functionality not yet implemented (so should not be used) */
    E_MALLOC            /* Memory allocation error */
    
} eErr_t;



/**
 * Lamps
 */
typedef enum eLamp {
    LAMP_START = 0,
    
    LAMP_1 = LAMP_START,           /* Ok, no error */
    LAMP_2,    /* First  input argument invalid */
    LAMP_3,    /* Second -||- */    
    LAMP_4,    /* Functionality not yet implemented (so should not be used) */
    
    LAMP_5,
    LAMP_6,
    LAMP_7,
    LAMP_8,
    
    
    LAMP_9,
    LAMP_10,
    LAMP_11,
    LAMP_12,
    
    LAMP_13,
    LAMP_14,
    LAMP_15,
    LAMP_16,
    
    
    LAMP_17,
    LAMP_18,
    LAMP_19,
    
    
    LAMP_COUNT  /* Number of lamps - this should be always the last one !! */
    
} eLamp_t;


/**
 * Lamp state
 */
typedef enum eLampState {
    LAMP_STATE_UNDEFINED,
    LAMP_STATE_OFF,
    LAMP_STATE_ON
} eLampState_t;