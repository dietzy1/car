#pragma once

class uartDriver
{
public:
    void SendInteger(int number);
};

void SendChar(char Char);

void SendString(char *String);

uartDriver initUARTDriver();