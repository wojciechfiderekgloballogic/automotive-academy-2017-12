/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.05   WojFid  New line fix
 * 2017.12.01   WojFid  Initial version
 */
#include <stdio.h>


#define _ASSERT(actual, expected) (actual == expected ? 1 : 0)


#define ASSERT(actual, expected)                                                    \
    ok &= _ASSERT(actual, expected);                                                \
    if( ! _ASSERT(actual, expected)){                                               \
        OUT_RED();                                                                  \
        printf("%s: fail (file:%s,  line:%d\n", module_name, __FILE__, __LINE__);   \
        OUT_WHITE();                                                                \
    }


#define START_TEST int ok = 1
    

#define STOP_TEST                       \
    if(ok == 1) {                       \
        OUT_GREEN();                    \
        printf("%s: ok\n", module_name);\
        OUT_WHITE();                    \
    }
