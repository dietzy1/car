#include "uart.h"
#include "sound.h"
#include <util/delay.h>

// constructor that takes in a uartDriver dependency
soundDriver::soundDriver(uartDriver *uart)
{
    // inject the uartdriver into the sounddriver as a private variabel
    this->uart = uart;
    // increase volume to 30
    char array[8] = {0x7E, 0x06, 0x00, 0x00, 0x1E, 0xFF, 0xDC, 0xEF};
    this->uart->sendCommand(array);
}

void soundDriver::playSound(int songNumber)
{
    switch (songNumber)
    {
    case 1:
    {

        // plays 1st track in the 1st folder on the SD card
        // char array[8] = {0x7E, 0x03, 0x00, 0x00, 0x02, 0xFF, 0xFB, 0xEF};
        char array[8] = {0x7E, 0x0D, 0x00, 0x00, 0x00, 0xFF, 0xF3, 0xEF};
        this->uart->sendCommand(array);
        _delay_ms(50);
        break;
    }
    case 2:
    {
        // TODO:: NOT TESTED YET NEED TO FIND OUT IF COMMAND IS VALID
        //  plays 2nd track in the 1st folder on the SD card
        char array[8] = {0x7E, 0x0F, 0x00, 0x01, 0x02, 0xFF, 0xEE, 0xEF};
        this->uart->sendCommand(array);
        _delay_ms(50);
        break;
    }
    case 3:
    {
        // TODO:: NOT TESTED YET NEED TO FIND OUT IF COMMAND IS VALID
        //  plays 2nd track in the 1st folder on the SD card
        char array[8] = {0x7E, 0x0F, 0x00, 0x01, 0x03, 0xFF, 0xED, 0xEF};
        this->uart->sendCommand(array);
        _delay_ms(50);
        break;
    }
    default:
        break;
    };
}
