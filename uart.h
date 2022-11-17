#pragma once

class uart
{
public:
    void InitUART();
    void SendInteger(int number);
};

void SendChar(char Char);

void SendString(char *String);