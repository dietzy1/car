#pragma once

class uartDriver
{
public:
    // void sendInteger(int number);
    void sendString(char *string);
};

void sendChar(char Char);

/* void sendString(char *String); */

uartDriver initUARTDriver();