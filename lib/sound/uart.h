#pragma once

class uartDriver
{
public:
    void sendString(char *string);
};

void sendChar(char Char);

uartDriver initUARTDriver();