#include "car.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include <util/delay.h>
#include "mutex"

// TODO:
void car::initButtonDriver()
{
    ddra = 0;
    //
}

// global variable holding the counter
volatile int counter = 0;
// Global mutex to protect the counter
std::mutex m;

// TODO:
<ISR(INT2_vect)> // Left sensor
{
    m.lock();
    counter++;
    _delay_ms(250);
    m.unlock();
}

// TODO:
<ISR(INT3_vect)> // Right sensor
{
    m.lock();
    counter++;
    _delay_ms(250);
    m.unlock();
}

void initInterrupts()
{
    // TODO: This part I need to double check it is potentially incorrect
    //  rising edge is set for bit 7 and 6 which is int 3 - falling edge is set for bit 5 and 4 which is int 2
    EICRA = 0b11100000;

    // Enables INT2 and INT3
    EIMSK |= 0b00001100;
}

void startCar()
{
}