/*
 *  Example:     Blinking on-board led
 *  Description: Led tied to pin B5 will blink be toggled every second.
 *  Author:      Pavel Novák
 *  Date:        12.10.2021
 *  
 *  Note:        On-board pin is wired in such way that the led is ON
 *               when the pin is set to LOW and OF when set to HIGH.
 */

#include "../../include/stm8s103f3.h"


int main() 
{
    // Set clock ti 16MHZ, set all pins low
    init();
    
    // Initialize pin B5 to push-pull output
    setPinMode(B5, PUSHPULL_OUTPUT);


	while (1)
	{
        if (getPinState(D1) == 0)
        {
            setPinState(B5, HIGH);       
            setPinState(A1, HIGH); 
        }
        else 
        {
            setPinState(B5, LOW);       
            setPinState(A1, LOW); 
        }   

        Delay_ms(100, DELAY_MUL_16);    
	}   
}
