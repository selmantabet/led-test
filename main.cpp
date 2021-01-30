/* Selman Tabet (@selmantabet - https://selman.io/) - UIN 724009859
Assignment 1 - Question 2

This function switches certain LEDs upon pressing (and holding) a button on
an LPC4088 board.

Tested on an EA LPC4088 QuickStart Board and a PC
running Windows 10 Pro x64 19042.746 (20H2).
*/
#include "mbed.h"
// Initialize Digital I/O
DigitalIn a(p23); //Initialize pushbutton
DigitalOut myled1(LED1); //Initialize LEDs 1-4
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);

int main() {
    a.mode(PullUp); //Enable the pullup resistor on input
    int b = 0; //b fixed to zero.
    while(1){ /*The definition outlined in the handout was misleading
    as it did not result in the output behavior described. The given
    definition would have held true if all LED lights were Active High AND 
    input a was inverted (no press = 0 // more intuitive imho).
    
    To solve this, the Active Low LEDs (1 and 2) were switched to Active
    High by inverting their output, while the input value of a was inverted and
    put in place of the original a value in the LED definitions.
    
    The result would then match the aforementioned condition and the
    desired output is obtained.
    */
        int not_a = !a; //Inverted input *for ALL* (press = 1, no press = 0)
        myled1 = !(!not_a); //Inverted to Active High mode
        myled2 = !(not_a && b); //Inverted to Active High mode
        myled3 = (not_a || b);
        myled4 = (not_a ^ b);
        }  
}
