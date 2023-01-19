#include <avr/io.h>
#include <stdlib.h>
#include "uart.h"

// Target CPU frequency
#define XTAL 16000000
// Define maximum size of array to prevent buffer overflow
#define SIZE 7

void sendChar(char Char);

void sendChar(char Char)
{
    // await transmitter register ready
    while ((UCSR0A & (1 << 5)) == 0)
    {
    }
    // if transmitter is ready then send the char
    UDR0 = Char;
}

// send an array of 8 hex bytes to the uart
void uartDriver::SendCommand(char *array)
{
    for (int i = 0; i < 8; i++)
    {
        char tmp = array[i];
        sendChar(tmp);
    }
}

uartDriver::uartDriver()
{
    // Enable RX and TX
    UCSR0B = 0b00011000;
    // Asynchronous mode, 1 stop bit, no parity, 8 data bits
    UCSR0C = 0b00000110;
    // Set baud rate
    UBRR0 = XTAL / 16 / 9600 - 1;
}

void consoleLog(char *array)
{
    // Repeat until zero-termination
    while (*array != 0)
    {
        // Send the character pointed to
        sendChar(*array);
        // Advance the pointer one step
        array++;
    }
}

// exported function used for errorlogging numbers
void consoleLogInteger(int integer)
{
    char array[7];
    // Convert the integer to an ASCII string (array), radix = 10
    itoa(integer, array, 10);
    // - then send the string
    consoleLog(array);
}
