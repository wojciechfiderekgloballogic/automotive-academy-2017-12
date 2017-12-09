/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.05   WojFid  Task 2 tests introduced (set lamp bit)
 * 2017.12.05   TomWes  Added another interface
 * 2017.12.01   WojFid  Initial version
 */
#include <stdio.h>
#include "../app/common/COMMON_interface.h"
#include "../app/wojfid/WOJFID_interface.h"
#include "../app/grzmak/GRZMAK_interface.h"
#include "../app/martor/MARTOR_interface.h"
#include "../app/pawazi/PAWAZI_interface.h"
#include "../app/mickal/MICKAL_interface.h"
#include "../app/piocie/PIOCIE_interface.h"
#include "../app/rafand/RAFAND_interface.h"
#include "../app/tomwes/TOMWES_interface.h"
#include "../app/jarkur/JARKUR_interface.h"
#include "../app/adakor/ADAKOR_interface.h"
#include "../app/tomwes/TOMWES_interface.h"
#include "../app/adakor/ADAKOR_interface.h"
#include "tests.h"
#include "test_1_setbitinterface.h"
#include "test_2_setlampbit.h"
#include "test_3_lamp_on.h"


int main() {
    OUT_YELLOW();
    printf("Run tests\n");
    
         
    /* Add tests for your module when module interface ready */
    /* Below example should work in case if first task implemented due to requirements: */
    printf("\n--------- TASK 1 ---------\n");
    TEST_1__SET_BIT_INTERFACE(WOJFID);
    TEST_1__SET_BIT_INTERFACE(TOMWES);
    TEST_1__SET_BIT_INTERFACE(GRZMAK);
    TEST_1__SET_BIT_INTERFACE(MARTOR);
    TEST_1__SET_BIT_INTERFACE(PAWAZI);
    TEST_1__SET_BIT_INTERFACE(MICKAL);
    TEST_1__SET_BIT_INTERFACE(PIOCIE);
    TEST_1__SET_BIT_INTERFACE(RAFAND);
    TEST_1__SET_BIT_INTERFACE(JARKUR);
    TEST_1__SET_BIT_INTERFACE(ADAKOR);

    
    printf("\n--------- TASK 2 ---------\n");    
    TEST_2__SET_LAMP_BIT(GRZMAK);
    //TEST_2__SET_LAMP_BIT(MARTOR);
    TEST_2__SET_LAMP_BIT(MICKAL);
    TEST_2__SET_LAMP_BIT(PAWAZI);
    TEST_2__SET_LAMP_BIT(PIOCIE);
    TEST_2__SET_LAMP_BIT(RAFAND);
    TEST_2__SET_LAMP_BIT(TOMWES);
    TEST_2__SET_LAMP_BIT(JARKUR);
    TEST_2__SET_LAMP_BIT(ADAKOR);

    
    
    printf("\n--------- TASK 3 ---------\n");    
    // TEST_3__LAMP_ON(WOJFID);
    // TEST_3__LAMP_ON(TOMWES);
    // TEST_3__LAMP_ON(GRZMAK);
    // TEST_3__LAMP_ON(MARTOR);
    // TEST_3__LAMP_ON(PAWAZI);
    // TEST_3__LAMP_ON(MICKAL);
    // TEST_3__LAMP_ON(PIOCIE);
    // TEST_3__LAMP_ON(RAFAND);
    // TEST_3__LAMP_ON(JARKUR);
    // TEST_3__LAMP_ON(ADAKOR);

    OUT_WHITE();
    return 0;
}
