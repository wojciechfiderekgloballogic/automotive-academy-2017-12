/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.01   WojFid  Initial version
 */
#include <stdio.h>
#include "../app/common/COMMON_interface.h"
#include "../app/wojfid/WOJFID_interface.h"
#include "tests.h"
#include "test_setbit.h"


int main() {
    OUT_YELLOW();
    printf("Run tests\n");
    
    
    /* Add tests for your module when module interface ready */
    /* Below example should work in case if first task implemented due to requirements: */
    TEST__SET_BIT(WOJFID);
    

    OUT_WHITE();
    return 0;
}
