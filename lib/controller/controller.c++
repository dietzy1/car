#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "uart.h"
#include "controller.h"

// Prototypes are declared in the .c++ file to prevent other files from calling them
void initInterrupts();
void initButtonDriver();

// Global variable holding the counter
volatile int counter = 0;

// Global variable to project the counter against multiple interrupts incrementing the counter
volatile bool boolio = false;

// Recieve signal from the button on PORTA
// Should prolly be INT0_vect because its PD ben 0
/* controllerDriver initControllerDriver()
{
    initInterrupts();
    initButtonDriver();
    return controllerDriver();
} */

// Constructor
controllerDriver::controllerDriver(lightDriver *light, soundDriver *sound, motorDriver *motor)
{
    this->light = light;
    this->sound = sound;

    this->motor = motor;
    this->verifyCounter = 0;

    initInterrupts();
    initButtonDriver();
}

// Function that enabled interupts for the left and right sensor on the car
void initInterrupts()
{
    // Rising edge interupt is enabled for INT0 and INT1
    EICRA |= 0b00001111;
    // Enables INT0 and INT1
    EIMSK |= 0b00000011;
    // call sei to enable interrupts
    sei();
}

void initButtonDriver()
{
    // 75AD3 which is the same as port 25 on the arduino
    DDRA &= ~(1 << 3);
}

char controllerDriver::buttonPressed()
{
    if (PORTA == 0b00010000)
    {
        return 1;
    };
    return 0;
    ;
}
// void controllerDriver::StartCar(lightDriver *light, soundDriver *sound, uartDriver *uart, motorDriver *motor)
void controllerDriver::StartCar()
{
    this->sound->playSound(1);
    this->light->turnOnFrontlight();
    // Wait for a set amount (of time // figure out how much time the song needs
    _delay_ms(5000);
    this->motor->forward(255);
}

// void controllerDriver::ReactToInput(lightDriver *light, soundDriver *sound, uartDriver *uart, motorDriver *motor, int *verifyCounter)
void controllerDriver::ReactToInput()
{
    switch (counter)
    {

    case 1:

        if (this->verifyCounter == counter)
        {

            this->sound->playSound(2);
            this->verifyCounter += 1;
        }
        break;

    case 2:

        if (this->verifyCounter == counter)
        {
            this->sound->playSound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->forward(255);
        }
        break;

    case 3:

        if (this->verifyCounter == counter)
        {
            this->sound->playSound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->forward(255);
        }
        break;

    case 4:

        if (this->verifyCounter == counter)
        {
            this->sound->playSound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->forward(255);
        }
        break;

    case 5:

        if (this->verifyCounter == counter)
        {
            this->sound->playSound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->forward(255);
        }

        break;

    case 6:

        if (this->verifyCounter == counter)
        {
            this->sound->playSound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->forward(255);
        }
        break;
    case 7:

        if (this->verifyCounter == counter)
        {
            this->sound->playSound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->forward(255);
        }
        break;

    default:
        break;
    }
}

// pd ben 0
ISR(INT0_vect)
{
    if (boolio == false)
    {
        boolio = true;
        counter++;
        _delay_ms(2000);
        boolio = false;
    };
    return;
}

// TODO: //should prolly be INT1_vect because its PD ben 1
ISR(INT1_vect) // Right sensor
{
    if (boolio == false)
    {
        boolio = true;
        counter++;
        _delay_ms(2000);
        boolio = false;
    };
}