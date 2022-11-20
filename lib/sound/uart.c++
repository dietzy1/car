#include <avr/io.h>
#include <stdlib.h>
#include "uart.h"

// Target CPU frequency
#define XTAL 16000000

// Define maximum size of array to prevent buffer overflow
#define SIZE 7

void SendInteger(int number)
{
    char array[SIZE];
    // Convert the integer to an ASCII string (array), radix = 10

    // integer to array of chars from base 10
    itoa(number, array, 10);

    SendString(array);
}

void SendString(char *String)
{
    // Send the recieved string
    while (*String != 0)
    {
        SendChar(*String);
        String++;
    }
}

void SendChar(char Char)
{
    // await transmitter register ready
    while ((UCSR0A & (1 << 5)) == 0)
    {
    }
    // if transmitter is ready then send the char
    UDR0 = Char;
}

uartDriver initUARTDriver()
{
    // Enable RX and TX
    UCSR0B = 0b00011000;

    // Asynchronous mode, 1 stop bit, no parity, 8 data bits
    UCSR0C = 0b00000110;
    // Set baud rate
    UBRR0 = XTAL / 16 / 9600 - 1;

    return uartDriver();
}
