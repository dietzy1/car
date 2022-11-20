#pragma once

#include "uart.h"

class soundDriver
{
public:
    void playSound(uartDriver, int);
};

soundDriver initSoundDriver();