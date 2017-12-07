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
	this_test_ok =  _ASSERT(actual, expected);\
    ok &= this_test_ok;                                                \
    if( ! this_test_ok){                                               \
        OUT_RED();                                                                  \
        printf("%s: fail (file:%s,  line:%d\n", module_name, __FILE__, __LINE__);   \
        OUT_WHITE();                                                                \
    }


#define START_TEST(TEST_NO) \
    int ok = 1; \
    int test_number = TEST_NO; \
	int this_test_ok;
    

#define STOP_TEST                       \
    if(ok == 1) {                       \
        OUT_GREEN();                    \
        printf("%s - test %d: ok\n", module_name, test_number);\
        OUT_WHITE();                    \
    }\
	else{\
		OUT_GREEN();                    \
        printf("%s - test %d: failed\n", module_name, test_number);\
        OUT_WHITE();\
	}
	
