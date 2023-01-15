#pragma once

#include "uart.h"

class soundDriver
{
public:
    soundDriver(uartDriver *);

    void PlaySound(int);

private:
    uartDriver *uart;
};
