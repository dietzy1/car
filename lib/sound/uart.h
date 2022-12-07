#pragma once

class uartDriver
{
public:
    void sendCommand(char *array);
};

uartDriver initUARTDriver();

void sendString(uartDriver);
// void sendCommand(char *array);
