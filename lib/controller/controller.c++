#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "uart.h"
#include "controller.h"
#include <stdlib.h>

// Prototypes are declared in the .c++ file to prevent other files from calling them
void initInterrupts();
void initButtonDriver();

// Global variable holding the counter
volatile int counter = 0;

// Constructor
controllerDriver::controllerDriver(lightDriver *light, soundDriver *sound, motorDriver *motor)
{
    this->light = light;
    this->sound = sound;

    this->motor = motor;
    this->verifyCounter = 1;

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
    // DDRA &= ~(1 << 3);
    DDRA = 0;
}

char controllerDriver::ButtonPressed()
{
    if ((PINA & 0b10000000) == 0)
    {
        return 1;
    };
    return 0;
}
// void controllerDriver::StartCar(lightDriver *light, soundDriver *sound, uartDriver *uart, motorDriver *motor)
void controllerDriver::StartCar()
{
    /*    this->sound->playSound(1); */
    this->light->turnOnFrontlight();
    // Wait for a set amount (of time // figure out how much time the song needs
    _delay_ms(1000);
    // set in forward mode
    /*  this->motor->direction(1);

     this->motor->motorSpeed(2); */
}

// void controllerDriver::ReactToInput(lightDriver *light, soundDriver *sound, uartDriver *uart, motorDriver *motor, int *verifyCounter)
void controllerDriver::ReactToInput()
{
    char array[] = " COUNTER=";
    consoleLog(array);
    SendInteger(counter);
    char array1[] = " VERIFYCOUNTER=";

    consoleLog(array1);
    SendInteger(this->verifyCounter);

    switch (counter)
    {
    case 1:

        if (this->verifyCounter == counter)
        {

            /*   this->sound->playSound(2); */
            this->verifyCounter += 1;
            /* this->motor->motorSpeed(1); */
            /*   this->motor->motorSpeed(3);
              _delay_ms(100);
              this->motor->motorSpeed(5);
              _delay_ms(100);
              this->motor->motorSpeed(7); */
        }
        break;

    case 2:

        if (this->verifyCounter == counter)
        {
            /*  this->sound->playSound(2); */
            this->verifyCounter += 1;
            // start car
            this->motor->motorSpeed(2);
            // this->motor->motorSpeed(10);
        }
        break;

    case 3:

        if (this->verifyCounter == counter)
        {

            this->sound->playSound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->motorSpeed(5);
        }
        break;

    case 4:

        if (this->verifyCounter == counter)
        {

            this->sound->playSound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->motorSpeed(8);
        }
        break;

    case 5:

        if (this->verifyCounter == counter)
        {
            this->sound->playSound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->motorSpeed(3);
        }

        break;

    case 6:

        if (this->verifyCounter == counter)
        {
            this->sound->playSound(2);
            this->verifyCounter += 1;
            // start car
            this->light->turnOnBrakeLight(2);

            this->motor->stop();
            _delay_ms(2000);
            // backwards direction
            this->motor->direction(0);
            this->motor->motorSpeed(3);
            _delay_ms(100);
            this->motor->motorSpeed(5);
        }
        break;
    case 7:

        if (this->verifyCounter == counter)
        {
            this->sound->playSound(2);
            this->verifyCounter += 1;

            this->motor->motorSpeed(3);
        }
        break;

    case 8:

        if (this->verifyCounter == counter)
        {
            this->sound->playSound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->stop();
            _delay_ms(2000);
            this->motor->direction(1);
            this->motor->motorSpeed(10);
        }
        break;

    case 9:

        if (this->verifyCounter == counter)
        {
            this->sound->playSound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->motorSpeed(10);
        }
        break;

    case 10:

        if (this->verifyCounter == counter)
        {
            this->sound->playSound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->motorSpeed(7);
        }
        break;

    case 11:

        if (this->verifyCounter == counter)
        {
            this->sound->playSound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->motorSpeed(3);
            this->motor->stop();
        }
        break;
    default:
        break;
    }
}

// TODO: this is probaly incorrect code it seems to increment twice

// pd ben 0
ISR(INT0_vect)
{
    // disable interrupt 0
    EIMSK &= ~(1 << INT0);
    // disable interrupt 1
    EIMSK &= ~(1 << INT1);
    counter++;
    _delay_ms(1000);

    // reset interrupt 0 flag
    EIFR |= (1 << INTF0);
    // reset interrupt 1 flag
    EIFR |= (1 << INTF1);

    // enable interrupt 0
    EIMSK |= (1 << INT0);
    // enable interrupt 1
    EIMSK |= (1 << INT1);
}

// TODO: //should prolly be INT1_vect because its PD ben 1
ISR(INT1_vect) // Right sensor
{
    // disable interrupt 0
    EIMSK &= ~(1 << INT0);
    // disable interrupt 1
    EIMSK &= ~(1 << INT1);
    counter++;
    _delay_ms(1000);

    // reset interrupt 0 flag
    EIFR |= (1 << INTF0);
    // reset interrupt 1 flag
    EIFR |= (1 << INTF1);

    // enable interrupt 0
    EIMSK |= (1 << INT0);
    // enable interrupt 1
    EIMSK |= (1 << INT1);
}