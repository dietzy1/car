#pragma once

#include "uart.h"

#include "../light/light.h"
#include "../motor/motor.h"
#include "../sound/sound.h"

class controllerDriver
{
public:
    controllerDriver(lightDriver *, soundDriver *, motorDriver *);

    char ButtonPressed();
    // void StartCar(lightDriver *, soundDriver *, uartDriver *, motorDriver *);
    void StartCar();
    // void ReactToInput(lightDriver *, soundDriver *, uartDriver *, motorDriver *, int *);
    void ReactToInput();
    void ReactToPsycho();

private:
    int verifyCounter;
    lightDriver *light;
    soundDriver *sound;
    motorDriver *motor;
};
