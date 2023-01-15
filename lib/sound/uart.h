#pragma once

class uartDriver
{
public:
    uartDriver();
    void SendCommand(char *array);
};

void consoleLog(char *array);
void SendString(char *Streng);
void SendInteger(int Tal);
