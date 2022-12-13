#pragma once

#include "uart.h"

#include "../light/light.h"
#include "../motor/motor.h"
#include "../sound/sound.h"

class controllerDriver
{
public:
    char buttonPressed();
    void ReactToInput(lightDriver, soundDriver, uartDriver, motorDriver, int *);
};

controllerDriver initControllerDriver();
