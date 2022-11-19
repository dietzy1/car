#include "../lib/light/light.h"
#include "../lib/sound/sound.h"
#include "../lib/motor/motor.h"
#include "../lib/sound/uart/uart.h"
#include "main.h"

#include "avr/io.h"
#include "avr/interrupt.h"
#include "util/delay.h"

#include <mutex>

// Bilen skal have en variende acceleration baseret ud fra dens position på banen

// I need to setup an interrupt that takes in input from left and right that increments the car counter when either of them are triggered
// After trigger a timer is started that turns off input from the sensor after 0.5 seconds

// global variable holding the counter
volatile int counter = 0;
// Global mutex to protect the counter
std::mutex m;

int main()
{
    // Need to wait for button input to start the run might need 2 nested while loops to do this
    // instantiate a class object
    car car;
    soundDriver sound;
    lightDriver light;
    motorDriver motor;
    uartDriver uart;

    sei();
    initInterrupts();

    car.initButtonDriver();
    sound.initSoundDriver();
    light.initLightDriver();
    motor.initMotorDriver();
    uart.InitUART();

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
    //
}

// TODO:

ISR(INT2_vect) // Left sensor
{
    m.lock();
    counter++;
    _delay_ms(250);
    m.unlock();
}

// TODO:
ISR(INT3_vect) // Right sensor
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
