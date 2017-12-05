/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.05   TomWes  Added another interface
 * 2017.12.01   WojFid  Initial version
 */
#include <stdio.h>
#include "../app/common/COMMON_interface.h"
#include "../app/wojfid/WOJFID_interface.h"
#include "../app/tomwes/TOMWES_interface.h"
#include "tests.h"
#include "test_1_setbitinterface.h"


int main() {
    OUT_YELLOW();
    printf("Run tests\n");
    
    
    /* Add tests for your module when module interface ready */
    /* Below example should work in case if first task implemented due to requirements: */
    TEST_1__SET_BIT_INTERFACE(WOJFID);
    TEST_1__SET_BIT_INTERFACE(TOMWES);
    

    OUT_WHITE();
    return 0;
}
