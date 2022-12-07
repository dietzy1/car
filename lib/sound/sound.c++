#include "uart.h"
#include "sound.h"
#include <util/delay.h>

/* Use case 2: ”Afspil lyd”
Mål
Denne use case beskriver styring af en i systemet indbygget lydgiver.
Initieres af: Use case 1 ”Kør banen”.
Normalt scenarie
1. Når bilen tændes for at køre ind på banen, afspilles en specifik ”startlyd” eller ”startmelodi”.
2. Hver gang en refleksbrik passeres, afspilles en specifik ”refleksbriklyd”.
3. Når refleksbrik nummer 7 passeres, afspilles en specifik ”slutlyd” eller ”slutmelodi”.
 */

soundDriver initSoundDriver(uartDriver uart)
{

    // initiate sound driver
    return soundDriver();
}

void soundDriver::playSound(uartDriver uart, int songNumber)
{
    switch (songNumber)
    {
    case 1:

        // plays 1st track in the 1st folder on the SD card
        char array[8] = {0x7E, 0x03, 0x00, 0x00, 0x02, 0xFF, 0xFB, 0xEF};
        uart.sendCommand(array);
        _delay_ms(50);
        break;
    case 2:
        // TODO:: NOT TESTED YET NEED TO FIND OUT IF COMMAND IS VALID
        //  plays 2nd track in the 1st folder on the SD card
        char array[8] = {0x7E, 0x0F, 0x00, 0x01, 0x02, 0xFF, 0xEE, 0xEF};
        uart.sendCommand(array);
        _delay_ms(50);
        break;
    case 3:
        // TODO:: NOT TESTED YET NEED TO FIND OUT IF COMMAND IS VALID
        //  plays 2nd track in the 1st folder on the SD card
        char array[8] = {0x7E, 0x0f, 0x00, 0x01, 0x03, 0xff, 0xee, 0xEF};
        uart.sendCommand(array);

        _delay_ms(50);
        break;
    default:
        break;
    };
}
