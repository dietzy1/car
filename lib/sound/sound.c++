#include "sound.h"
#include "uart/uart.h"

/* Use case 2: ”Afspil lyd”
Mål
Denne use case beskriver styring af en i systemet indbygget lydgiver.
Initieres af: Use case 1 ”Kør banen”.
Normalt scenarie
1. Når bilen tændes for at køre ind på banen, afspilles en specifik ”startlyd” eller ”startmelodi”.
2. Hver gang en refleksbrik passeres, afspilles en specifik ”refleksbriklyd”.
3. Når refleksbrik nummer 7 passeres, afspilles en specifik ”slutlyd” eller ”slutmelodi”.
 */

void initSoundDriver()
{

    // 7E 09 00 00 02 FF F5 EF -play source to play from sd card
    // 7E 06 00 00 1E FF DC EF - set volume

    // initiate sound driver
}
void playSound(uartDriver uart, int songNumber)
{
    // 7E 03 00 00 01 FF FC EF play 1st track
    // 7E 03 00 00 02 FF FB EF play 2nd track
}

// Checksum (2 bytes) = 0xFFFF – (CMD + Feedback + Para1 + Para2) + 1