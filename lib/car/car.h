#pragma once

#include "uart.h"

#include "../light/light.h"
#include "../motor/motor.h"
#include "../sound/sound.h"

class carDriver
{
public:
    char buttonPressed();
    void controller(lightDriver, soundDriver, uartDriver, motorDriver, int);
};

carDriver initCarDriver();
