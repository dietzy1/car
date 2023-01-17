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
    // EICRA |= 0b00001111;
    // Enables INT0 and INT1
    // EIMSK |= 0b00000011;
    // call sei to enable interrupts

    // enable rising edge interupt for INT2 and INT3
    EICRA |= 0b11110000;
    // Enables INT2 and INT3
    EIMSK |= 0b00001100;
    sei();
}

void initButtonDriver()
{
    // 75AD3 which is the same as port 25 on the arduino
    // DDRA &= ~(1 << 3);
    DDRA = 0;
}

// This functions  checks for the input from the button 7 on the arduino shield
// If the button is pressed 1(true) is returned and the main function should break out of the while loop.
char controllerDriver::ButtonPressed()
{
    if ((PINA & 0b10000000) == 0)
    {
        return 1;
    };
    return 0;
}

void controllerDriver::StartCar()
{
    this->sound->PlaySound(1);
    this->light->TurnOnFrontlight();

    // Wait for a set amount (of time // figure out how much time the song needs
    _delay_ms(1000);
    // set in forward mode
    this->motor->Direction(1);

    this->motor->MotorSpeed(6);
}

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
            this->sound->PlaySound(2);
            this->verifyCounter += 1;
            this->motor->MotorSpeed(6);
        }
        break;

    case 2:

        if (this->verifyCounter == counter)
        {
            /*  this->sound->playSound(2); */
            this->verifyCounter += 1;
            // start car
            this->motor->MotorSpeed(7);
            // this->motor->motorSpeed(10);
        }
        break;

    case 3:

        if (this->verifyCounter == counter)
        {

            this->sound->PlaySound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->MotorSpeed(1);
        }
        break;

    case 4:

        if (this->verifyCounter == counter)
        {

            this->sound->PlaySound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->MotorSpeed(4);
        }
        break;

    case 5:

        if (this->verifyCounter == counter)
        {
            this->sound->PlaySound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->MotorSpeed(3);
        }

        break;

    case 6:

        if (this->verifyCounter == counter)
        {
            this->sound->PlaySound(2);
            this->verifyCounter += 1;
            // start car
            this->light->TurnOnBrakeLight(2);

            this->motor->Stop();
            _delay_ms(1000);
            // backwards direction
            this->motor->Direction(0);
            this->motor->MotorSpeed(4);
        }
        break;
    case 7:

        if (this->verifyCounter == counter)
        {
            this->sound->PlaySound(2);
            this->verifyCounter += 1;

            this->motor->MotorSpeed(5);
        }
        break;

    case 8:

        if (this->verifyCounter == counter)
        {
            this->sound->PlaySound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->MotorSpeed(5);
            this->motor->Stop();
            this->light->TurnOnBrakeLight(1);
            _delay_ms(300);
            this->motor->Direction(1);
            this->motor->MotorSpeed(5);
        }
        break;

    case 9:

        if (this->verifyCounter == counter)
        {
            this->sound->PlaySound(2);
            this->verifyCounter += 1;
            // start car
        }
        break;

    case 10:

        if (this->verifyCounter == counter)
        {
            this->sound->PlaySound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->MotorSpeed(5);
        }
        break;
    case 11:
        if (this->verifyCounter == counter)
        {
            this->sound->PlaySound(2);
            this->verifyCounter += 1;
            // start car
            this->motor->Stop();
            this->light->TurnOffBrakeLight();
        }
        break;

    default:
        break;
    }
}

// TODO: this is probaly incorrect code it seems to increment twice

// pd ben 0
ISR(INT2_vect)
{
    // disable interrupt 2
    EIMSK &= ~(1 << INT2);

    // disable interrupt 3
    EIMSK &= ~(1 << INT3);

    counter++;
    _delay_ms(700);

    // reset interrupt 2 flag
    EIFR |= (1 << INTF2);

    // reset interrupt 3 flag
    EIFR |= (1 << INTF3);

    // enable interrupt 2
    EIMSK |= (1 << INT2);

    // enable interrupt 3
    EIMSK |= (1 << INT3);
}

// TODO: //should prolly be INT1_vect because its PD ben 1
ISR(INT3_vect) // Right sensor
{
    // disable interrupt 0
    EIMSK &= ~(1 << INT3);

    // disable interrupt 1
    EIMSK &= ~(1 << INT2);

    counter++;
    _delay_ms(700);

    // reset interrupt 0 flag
    EIFR |= (1 << INTF3);

    // reset interrupt 1 flag
    EIFR |= (1 << INTF2);

    // enable interrupt 0
    EIMSK |= (1 << INT3);

    // enable interrupt 1
    EIMSK |= (1 << INT2);
}
