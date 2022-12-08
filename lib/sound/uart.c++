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

/* void sendString(uartDriver uart)
{
    sendChar(0x7E);
    sendChar(0x0D);
    sendChar(0x00);
    sendChar(0x00);
    sendChar(0x00);
    sendChar(0xFF);
    sendChar(0xF3);
    sendChar(0xEF);
} */

// TODO:
//  This command needs to be tested
void uartDriver::sendCommand(char *array)
{
    for (int i = 0; i < 8; i++)
    {
        char tmp = array[i]; // This here is nessecary for some shitty reason which is beyond my comprehension
        sendChar(tmp);
    }
}

// initialize the uart driver so the transmit is set as output
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
