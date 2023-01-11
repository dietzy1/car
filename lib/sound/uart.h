#pragma once

class uartDriver
{
public:
    uartDriver();
    void sendCommand(char *array);
};

void consoleLog(char *array);
