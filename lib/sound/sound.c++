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
    // 7E 09 00 00 02 FF F5 EF -play source to play from sd card
    /*   uart.sendString("7E 09 00 00 02 FF F5 EF");
      _delay_ms(50); */

    // 7E 06 00 00 1E FF DC EF - set volume to max
    /*   uart.sendString("0x7E0x060x000x000x1E0xFF0xDC0xEF");
      _delay_ms(50);

      uart.sendString("0x7E0x030x000x000x010xFF0xFC0xEF");
      _delay_ms(50); */
    sendString(uart);
    // initiate sound driver
    return soundDriver();
}

void soundDriver::playSound(uartDriver uart, int songNumber)
{
    switch (songNumber)
    {
    case 1:
        // 7E 03 00 00 01 FF FC EF play 1st track
        uart.sendString("0x7E0x030x000x000x010xFF0xFC0xEF");
        _delay_ms(50);
        break;
    case 2:
        // 7E 03 00 00 02 FF FB EF play 2nd track
        uart.sendString("7E 03 00 00 02 FF FB EF");
        _delay_ms(50);
        break;
    case 3:
        // 7E 03 00 00 03 FF FA EF play 3rd track
        uart.sendString("7E 03 00 00 03 FF FA EF");
        _delay_ms(50);
        break;
    default:
        break;
    };
}
