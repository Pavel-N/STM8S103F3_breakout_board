/*
 *  Example:     Turning on on-board led based on input without interupt
 *  Description: Led tied to pin B5 will be turned on if pin D1 is high.
 *  Author:      Pavel Novák
 *  Date:        13.10.2021
 *  
 *  Note:        On-board pin is wired in such way that the led is ON
 *               when the pin is set to LOW and OF when set to HIGH.
 *
 *  Warning:     Flashing will fail if you short D1 with GND! // TODO Add datasheet reference 
 */

#include "../../include/stm8s103f3.h"


int main() 
{
    // Set clock ti 16MHZ, set all pins low
    init();
    
    // Initialize pin B5 to push-pull output
    setPinMode(B5, PUSHPULL_OUTPUT);
    // Initialize pin D1 to pullup input without interupt
    setPinMode(D1, PULLUP_INPUT_NO_INT);

    
	while (1)
	{
        // If pin D1 is high, set B5 to high
        // and turn off on-board led - see "Note:" above
        if (getPinState(D1))
            setPinState(B5, HIGH);       
        else // If pin D1 is low , set B5 to low
            setPinState(B5, LOW);       

        Delay_ms(100, DELAY_MUL_16);
	}    
}
