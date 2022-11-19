#pragma once

//#include "sound/uart/uart.h"

#include "uart/uart.h"

class soundDriver
{
public:
    void initSoundDriver();
    void playSound(uartDriver, int);
};