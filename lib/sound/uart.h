#pragma once

class uartDriver
{
public:
    uartDriver();
    void SendCommand(char *array);
};

// Exported error logging functions
void consoleLog(char *array);
void consoleLogInteger(int integer);
