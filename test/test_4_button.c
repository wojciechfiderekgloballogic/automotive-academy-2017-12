/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.11   WojFid  Initial version
 */
#include "./test_4_button.h"

#define MAIN(COUNT) iMainStub(COUNT, vHandleButtons)
static void iMainStub(int iLoops, void (*vHandleButtons)(void)) {
    while(iLoops > 0) {
        vHandleButtons();
        iLoops--;
    }
}

#define SET_B0(STATE) IO__pin2 = STATE
#define SET_B1(STATE) IO__pin0 = STATE
#define SET_B2(STATE) IO__pin1 = STATE

#define PRESS_B0()    MAIN(7); SET_B0(1); MAIN(6);
#define RELEASE_B0()  MAIN(3); SET_B0(0); MAIN(8);

#define PRESS_B1()    MAIN(11);SET_B1(1); MAIN(1);
#define RELEASE_B1()  MAIN(1); SET_B1(0); MAIN(9);

#define PRESS_B2()    MAIN(1); SET_B2(1); MAIN(3);
#define RELEASE_B2()  MAIN(17);SET_B2(0); MAIN(19);


// ------------- Listeners A ----------------- 
static int press_counter_A = 0;
static int release_counter_A = 0;

static eErr_t B0_vOnPressListenerA(eButton_t eButton) {
    press_counter_A++;
}

static eErr_t B0_vOnReleaseListenerA(eButton_t eButton) {
    release_counter_A++;
}


// ------------- Listeners B ----------------- 
static int press_counter_B = 0;
static int release_counter_B = 0;

static eErr_t B0_vOnPressListenerB(eButton_t eButton) {
    press_counter_B++;
}

static eErr_t B0_vOnReleaseListenerB(eButton_t eButton) {
    release_counter_B++;
}


// ------------- B1 A ----------------- 


// ------------- B2 A -----------------


void TEST_4_button(
    char* module_name,
    void   (*vHandleButtons)        (void),
    eErr_t (*eAddOnPressListener)   (eButton_t eButton, eErr_t (*onPressListener) (eButton_t)),
    eErr_t (*eAddOnReleaseListener) (eButton_t eButton, eErr_t (*onReleaseListener) (eButton_t))
    ) {
        START_TEST(4);
        
        //===============================================================================================================
        // BUTTON_0 - first handler
        
        //---------------------------------------------------------------------------------------------------------------
        // Invalid button onPress
        ASSERT( eAddOnPressListener(BUTTON_START-1, B0_vOnPressListenerA), E_INVALID_ARG_1, "Invalid button not handled" );
        
        // Invalid button onPress
        ASSERT( eAddOnPressListener(BUTTON_COUNT, B0_vOnPressListenerA),   E_INVALID_ARG_1, "Invalid button not handled" );
        
        
        // Invalid button onRelease
        ASSERT( eAddOnReleaseListener(BUTTON_START-1, B0_vOnReleaseListenerA), E_INVALID_ARG_1, "Invalid button not handled" );
        
        // Invalid button onRelease
        ASSERT( eAddOnReleaseListener(BUTTON_COUNT, B0_vOnReleaseListenerA),   E_INVALID_ARG_1, "Invalid button not handled" );
        
        
        
        //---------------------------------------------------------------------------------------------------------------
        // Ok
        ASSERT( eAddOnPressListener(BUTTON_0, B0_vOnPressListenerA), E_OK, "Invalid button" );
        // Ok
        ASSERT( eAddOnReleaseListener(BUTTON_0, B0_vOnReleaseListenerA), E_OK, "Invalid button" );
        
        
        //---------------------------------------------------------------------------------------------------------------
        // Already exists
        ASSERT( eAddOnPressListener(BUTTON_0, B0_vOnPressListenerA),   E_LISTENER_ALREADY_EXISTS, "Do not allow doubled listeners" );
        // Already exists
        ASSERT( eAddOnReleaseListener(BUTTON_0, B0_vOnReleaseListenerA), E_LISTENER_ALREADY_EXISTS, "Do not allow doubled listeners" );
        
        
        //---------------------------------------------------------------------------------------------------------------
        // On press and release test
        ASSERT( press_counter_A,   0, "Nope !");
        ASSERT( release_counter_A, 0, "Nope !");
        
        PRESS_B0();
        ASSERT( press_counter_A,   1, "Nope !");
        ASSERT( release_counter_A, 0, "Nope !");
        ASSERT( press_counter_B,   0, "Nope !");
        ASSERT( release_counter_B, 0, "Nope !");
        
        RELEASE_B0();
        ASSERT( press_counter_A,   1, "Nope !");
        ASSERT( release_counter_A, 1, "Nope !");
        ASSERT( press_counter_B,   0, "Nope !");
        ASSERT( release_counter_B, 0, "Nope !");
        
        PRESS_B0();
        ASSERT( press_counter_A,   2, "Nope !");
        ASSERT( release_counter_A, 1, "Nope !");
        ASSERT( press_counter_B,   0, "Nope !");
        ASSERT( release_counter_B, 0, "Nope !");
        
        RELEASE_B0();
        ASSERT( press_counter_A,   2, "Nope !");
        ASSERT( release_counter_A, 2, "Nope !");
        ASSERT( press_counter_B,   0, "Nope !");
        ASSERT( release_counter_B, 0, "Nope !");
        
        
        
        
        //===============================================================================================================
        // BUTTON_0 - second handler
        
        //---------------------------------------------------------------------------------------------------------------
        // Invalid button onPress
        ASSERT( eAddOnPressListener(BUTTON_START-1, B0_vOnPressListenerB), E_INVALID_ARG_1, "Invalid button not handled" );
        
        // Invalid button onPress
        ASSERT( eAddOnPressListener(BUTTON_COUNT, B0_vOnPressListenerB),   E_INVALID_ARG_1, "Invalid button not handled" );
        
        
        // Invalid button onRelease
        ASSERT( eAddOnReleaseListener(BUTTON_START-1, B0_vOnReleaseListenerB), E_INVALID_ARG_1, "Invalid button not handled" );
        
        // Invalid button onRelease
        ASSERT( eAddOnReleaseListener(BUTTON_COUNT, B0_vOnReleaseListenerB),   E_INVALID_ARG_1, "Invalid button not handled" );
        
        
        
        //---------------------------------------------------------------------------------------------------------------
        // Ok
        ASSERT( eAddOnPressListener(BUTTON_0, B0_vOnPressListenerB), E_OK, "Invalid button" );
        // Ok
        ASSERT( eAddOnReleaseListener(BUTTON_0, B0_vOnReleaseListenerB), E_OK, "Invalid button" );
        
        
        //---------------------------------------------------------------------------------------------------------------
        // Already exists
        ASSERT( eAddOnPressListener(BUTTON_0, B0_vOnPressListenerB),   E_LISTENER_ALREADY_EXISTS, "Do not allow doubled listeners" );
        // Already exists
        ASSERT( eAddOnReleaseListener(BUTTON_0, B0_vOnReleaseListenerB), E_LISTENER_ALREADY_EXISTS, "Do not allow doubled listeners" );
        
        
        //---------------------------------------------------------------------------------------------------------------
        // On press and release test
        ASSERT( press_counter_A,   2, "Nope !");
        ASSERT( release_counter_A, 2, "Nope !");
        ASSERT( press_counter_B,   0, "Nope !");
        ASSERT( release_counter_B, 0, "Nope !");
        
        PRESS_B0();
        ASSERT( press_counter_A,   3, "Nope !");
        ASSERT( release_counter_A, 2, "Nope !");
        ASSERT( press_counter_B,   1, "Nope !");
        ASSERT( release_counter_B, 0, "Nope !");
        
        RELEASE_B0();
        ASSERT( press_counter_A,   3, "Nope !");
        ASSERT( release_counter_A, 3, "Nope !");
        ASSERT( press_counter_B,   1, "Nope !");
        ASSERT( release_counter_B, 1, "Nope !");
        
        PRESS_B0();
        ASSERT( press_counter_A,   4, "Nope !");
        ASSERT( release_counter_A, 3, "Nope !");
        ASSERT( press_counter_B,   2, "Nope !");
        ASSERT( release_counter_B, 1, "Nope !");
        
        RELEASE_B0();
        ASSERT( press_counter_A,   4, "Nope !");
        ASSERT( release_counter_A, 4, "Nope !");
        ASSERT( press_counter_B,   2, "Nope !");
        ASSERT( release_counter_B, 2, "Nope !");
        
        
        
        //===============================================================================================================
        // BUTTON_1
        
        
        //---------------------------------------------------------------------------------------------------------------
        // Ok
        ASSERT( eAddOnPressListener(BUTTON_1, B0_vOnPressListenerB), E_OK, "Should be E_OK" );
        // Ok
        ASSERT( eAddOnReleaseListener(BUTTON_1, B0_vOnReleaseListenerB), E_OK, "Should be E_OK" );
        
        
        //---------------------------------------------------------------------------------------------------------------
        // Already exists
        ASSERT( eAddOnPressListener(BUTTON_1, B0_vOnPressListenerB),   E_LISTENER_ALREADY_EXISTS, "Do not allow doubled listeners" );
        // Already exists
        ASSERT( eAddOnReleaseListener(BUTTON_1, B0_vOnReleaseListenerB), E_LISTENER_ALREADY_EXISTS, "Do not allow doubled listeners" );
        
        
        //---------------------------------------------------------------------------------------------------------------
        // On press and release test
        // ASSERT( press_counter_A,   4, "Nope !");
        // ASSERT( release_counter_A, 4, "Nope !");
        // ASSERT( press_counter_B,   2, "Nope !");
        // ASSERT( release_counter_B, 2, "Nope !");
        
        // PRESS_B1();
        // ASSERT( press_counter_A,   4, "Nope !");
        // ASSERT( release_counter_A, 4, "Nope !");
        // ASSERT( press_counter_B,   3, "Nope !");
        // ASSERT( release_counter_B, 2, "Nope !");
        
        // RELEASE_B1();
        // ASSERT( press_counter_A,   4, "Nope !");
        // ASSERT( release_counter_A, 4, "Nope !");
        // ASSERT( press_counter_B,   3, "Nope !");
        // ASSERT( release_counter_B, 3, "Nope !");
        
        // PRESS_B1();
        // ASSERT( press_counter_A,   4, "Nope !");
        // ASSERT( release_counter_A, 4, "Nope !");
        // ASSERT( press_counter_B,   4, "Nope !");
        // ASSERT( release_counter_B, 3, "Nope !");
        
        // RELEASE_B1();
        // ASSERT( press_counter_A,   4, "Nope !");
        // ASSERT( release_counter_A, 4, "Nope !");
        // ASSERT( press_counter_B,   4, "Nope !");
        // ASSERT( release_counter_B, 4, "Nope !");
        
        
        
        //===============================================================================================================
        // BUTTON_2
        
        //---------------------------------------------------------------------------------------------------------------
        // Ok
        ASSERT( eAddOnPressListener(BUTTON_2, B0_vOnPressListenerA), E_OK, "Should be E_OK" );
        // Ok
        ASSERT( eAddOnReleaseListener(BUTTON_2, B0_vOnReleaseListenerA), E_OK, "Should be E_OK" );
        
        
        //---------------------------------------------------------------------------------------------------------------
        // Already exists
        ASSERT( eAddOnPressListener(BUTTON_2, B0_vOnPressListenerA),   E_LISTENER_ALREADY_EXISTS, "Do not allow doubled listeners" );
        // Already exists
        ASSERT( eAddOnReleaseListener(BUTTON_2, B0_vOnReleaseListenerA), E_LISTENER_ALREADY_EXISTS, "Do not allow doubled listeners" );
        
        
        //---------------------------------------------------------------------------------------------------------------
        // On press and release test
        // ASSERT( press_counter_A,   4, "Nope !");
        // ASSERT( release_counter_A, 4, "Nope !");
        // ASSERT( press_counter_B,   4, "Nope !");
        // ASSERT( release_counter_B, 4, "Nope !");
        
        // PRESS_B2();
        // ASSERT( press_counter_A,   5, "Nope !");
        // ASSERT( release_counter_A, 4, "Nope !");
        // ASSERT( press_counter_B,   4, "Nope !");
        // ASSERT( release_counter_B, 4, "Nope !");
        
        // RELEASE_B2();
        // ASSERT( press_counter_A,   5, "Nope !");
        // ASSERT( release_counter_A, 5, "Nope !");
        // ASSERT( press_counter_B,   4, "Nope !");
        // ASSERT( release_counter_B, 4, "Nope !");
        
        // PRESS_B2();
        // ASSERT( press_counter_A,   6, "Nope !");
        // ASSERT( release_counter_A, 5, "Nope !");
        // ASSERT( press_counter_B,   4, "Nope !");
        // ASSERT( release_counter_B, 4, "Nope !");
        
        // RELEASE_B2();
        // ASSERT( press_counter_A,   6, "Nope !");
        // ASSERT( release_counter_A, 6, "Nope !");
        // ASSERT( press_counter_B,   4, "Nope !");
        // ASSERT( release_counter_B, 4, "Nope !");
        
        
        
        //---------------------------------------------------------------------------------------------------------------
        // PRESS_B0();
        // ASSERT( press_counter_A,   7, "Nope !");
        // ASSERT( release_counter_A, 6, "Nope !");
        // ASSERT( press_counter_B,   5, "Nope !");
        // ASSERT( release_counter_B, 4, "Nope !");
        
        // RELEASE_B0();
        // ASSERT( press_counter_A,   7, "Nope !");
        // ASSERT( release_counter_A, 7, "Nope !");
        // ASSERT( press_counter_B,   5, "Nope !");
        // ASSERT( release_counter_B, 5, "Nope !");
        STOP_TEST;
        
        
    }