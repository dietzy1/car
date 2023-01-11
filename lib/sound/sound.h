#pragma once

#include "uart.h"

class soundDriver
{
public:
    soundDriver(uartDriver *);

    void playSound(int);

private:
    uartDriver *uart;
};
