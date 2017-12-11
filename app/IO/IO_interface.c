/**
 * Responsible: Wojciech Fiderek
 *
 *
 * History log:
 * 2017.12.05   WojFid  Initial
 */
#include "./IO_interface.h"


/**
 * This is simulation of input/output interface.
 * Double underscore means that this variable is private
 * It is not marked as static but you should not modify it in your module
 */
int IO__pin0 = 0;
int IO__pin1 = 0;
int IO__pin2 = 0;


/**
 * No hungarian notation because apis provided by board manufacturers usually do not uses it.
 * However if it is required by coding rules of your project then you are still obligated to use it in your code.
 */
int IO_get(int id) {
    int result = 0;
    
    switch(id) {
        case IO_PIN_0:
            result = IO__pin0;
            break;
        case IO_PIN_1:
            result = IO__pin1;
            break;
        case IO_PIN_2:
            result = IO__pin2;
            break;
        default:
            result = 0;
    }
    
    return result;
}

