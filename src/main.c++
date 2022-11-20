//#include "../lib/light/light.h"
//#include "../lib/sound/sound.h"
#include "../light/light.h"
#include "../sound/sound.h"
#include "../sound/uart.h"
#include "../motor/motor.h"

//#include "../lib/motor/motor.h"

//#include "../lib/sound/uart/uart.h"
#include "main.h"

#include "avr/io.h"
#include "avr/interrupt.h"
#include "util/delay.h"

// Global variable holding the counter
volatile int counter = 0;
// Global variable to project the counter against multiple interrupts incrementing the counter
volatile bool boolio = false;

int main()
{
    // Initiate all drivers and their dependencies
    car car;
    soundDriver sound = initSoundDriver();
    lightDriver light = initLightDriver();
    motorDriver motor = initMotorDriver();
    uartDriver uart = initUARTDriver();
    sei();

    car.initButtonDriver();

    car.initInterrupts();
    while (boolio == true)
    {
        light.turnOn(1);
        sound.playSound(uart, 1);
        motor.forward(255);

        switch (counter)
        {
        case 1:
            // turn on light 1
            light.turnOn(1);
            // play sound
            sound.playSound(uart, 2);
            // start car
            motor.forward(255);
            break;
        case 2:
            sound.playSound(uart, 2);
            // start car
            motor.forward(255);
            break;
        case 3:
            sound.playSound(uart, 2);
            // start car
            motor.forward(255);
            break;
        case 4:
            sound.playSound(uart, 2);
            // start car
            motor.forward(255);
            break;
        case 5:
            sound.playSound(uart, 2);
            // start car
            motor.forward(255);
            break;
        case 6:
            sound.playSound(uart, 2);
            // start car
            motor.forward(255);
            break;
        case 7:
            sound.playSound(uart, 2);
            // start car
            motor.forward(255);
            break;
        }
    }
    while (1)
    {
        // do nothing
    }
}

// For now all should be public //unsure if private would work //protected might work since they are inherited from the class

// Start position bilen skal accelerere i et tempo så den ikke giver udsving
// Ved 1 skal bilen forberede sig på at sænke farten - potentielt skal farten allerede være lavere
// Ved 2 skal bilens hastighed sænkes så den er klar til at køre op ad bakken
// Ved 3 er bilen på toppen af bakken og dens hastighed skal sænkes betydeligt
// Ved 4 Kan hastigheden øges igen
// Ved 5 springer bilen refleksen over og skal efterfølgende sænke farten
// Ved 6 Skal bilen være i fuld stop hvorefter bilen skal skifte køreretning til bagud
// Ved 5 Skal bilen være i fuld stop og køreretningen skiftes til fremad
// Ved 6 springes refleksen over
// Ved 7 skal bilen i fuld stop relativt hurtigt for at bilen ikke kører længere end hvad banen har.

// TODO:
void car::initButtonDriver()
{
    DDRA = 0;
}

// TODO:

ISR(INT2_vect) // Left sensor
{
    if (boolio == false)
    {
        boolio = true;
        counter++;
        _delay_ms(250);
        boolio = false;
    };
    return;
}

// TODO:
ISR(INT3_vect) // Right sensor
{
    if (boolio == false)
    {
        boolio = true;
        counter++;
        _delay_ms(250);
        boolio = false;
    };
    return;
}

void car::initInterrupts()
{
    // TODO: This part I need to double check it is potentially incorrect
    //  rising edge is set for bit 7 and 6 which is int 3 - falling edge is set for bit 5 and 4 which is int 2
    EICRA = 0b11100000;

    // Enables INT2 and INT3
    EIMSK |= 0b00001100;
}
