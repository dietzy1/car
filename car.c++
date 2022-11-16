#include "car.h"
#include "avr/io.h"
#include "avr/interrupt.h"

// TODO:
void car::initButtonDriver()
{
    ddra = 0;
    //
}

// TODO:
<ISR(INT2_VECTOR)> // Left sensor
    {
        // Increment car counter
        // Start timer
    }

// TODO:
<ISR(INT3_VECTOR)> // Right sensor
{
    // Increment car counter
    // Start timer
}

void enableInterrupts()
{
    // Enable interrupts
    sei();

    // TODO: This part I need to double check it is potentially incorrect
    //  rising edge is set for bit 7 and 6 which is int 3 - falling edge is set for bit 5 and 4 which is int 2
    EICRA = 0b11100000;

    // Enables INT2 and INT3
    EIMSK = 0b00001100;
}