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
    if( ! ok){                                               \
        OUT_RED();                                                                  \
        printf("%s: fail (file:%s,  line:%d\n", module_name, __FILE__, __LINE__);   \
        OUT_WHITE();                                                                \
    }


#define START_TEST(TEST_NO) \
	unsigned int globalTestState; \
    int ok = 1; \
    int test_number = TEST_NO;
    

#define STOP_TEST                       \
    if(ok == 1) {                       \
        OUT_GREEN();                    \
        printf("%s - test %d: ok\n", module_name, test_number);\
        OUT_WHITE();                    \
    }
