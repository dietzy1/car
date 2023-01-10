#include "light.h"

#include <avr/io.h>

/* Use case 3: ”Styr forlys”
Mål
Denne use case beskriver styringen af bilens indbyggede forlys.
Forlyset kan være slukket eller tændt.
Initieres af: Use case 1 ”Kør banen”.
Normalt scenarie
Forlyset skal være tændt, når bilens motor påtrykkes en spænding, for at bringe den til at køre.
Ellers skal forlyset være slukket.


Use case 4: ”Styr baglys”
Mål
Denne use case beskriver styringen af bilens indbyggede baglys.
Baglyset kan være slukket, lyse med mellemstyrke (”almindeligt baglys”) eller lyse med kraftig styrke (”bremselys”).
Initieres af: Use case 1 ”Kør banen”.
Normalt scenarie
* Baglyset skal lyse med mellemstyrke (”almindeligt baglys”), når bilens motor påtrykkes en spænding, for at bringe den til at køre. Ellers skal baglyset være slukket.

* Baglyset skal lyse med kraftig styrke (”bremselys”), mens spændingens til bilens motor mindskes.
Bremselyset skal herefter forblive tændt i 0,5 sekund +/- 0,1 sekund.
 */

lightDriver initLightDriver()
{
  // PB outputs and turn on LED4 to pin OC0A (pin 10)
  DDRH = 0xFF; // Initiate PORTB as output

  DDRH = 0xFF;

  return lightDriver();
}

void lightDriver::turnOnFrontlight()
{
  PORTH = 0b00010000; // Turn on PH4, equivalent to LED4
}

void lightDriver::turnOffFrontlight()
{
  PORTH = 0b00000000;
}

void lightDriver::turnOnBrakeLight(int intensity)
{
  // PORTB = 0b10000000
  // PORTB = 0b10000000; // Brug pin OC0A til at teste med 100% duty cycle (ca. 50 mA) & brug pin OC1A, som består af en duty cycle på 20% (ca. 10 mA)
  // Mode = 3 (PWM, Phase Correct, 10 bit)
  // Set OC1A on match down counting / Clear OC1A on match up counting
  // Clock prescaler = 1

  /* Når bilen er ved tilstanden "alm. lys" --> Duty cycle = 20% */
  TCCR4A = 0b00001011;
  TCCR4B = 0b00000001;

  switch (intensity)
  {
  case 1:
    OCR4C = 1024 / 5;
    break;
  case 2:
    TCCR4A = 0b00000000; // Normal port operation
    TCCR4B = 0b00000000; // Clock source deactivated (Timer/Counter stopped)
    PORTH = 0b00110000;  // Turn on OC4C, as digital high (pin 8)
    break;
  default:
    break;
  };
}

void lightDriver::turnOffBrakeLight()
{
  PORTB = 0b00000000;
}

int main(void)
{
  // PH outputs and turn on PH4 connected to pin OC4B (pin 7)
  DDRH = 0xFF;
  PORTH = 0b00010000; // Brug pin PH4 (OC4B/pin 10) til at teste med 100% duty cycle (ca. 50 mA) & brug pin OC4B (pin 8), som består af en duty cycle på 20% (ca. 10 mA)

  //****TEST MED TIMER 4 in C-system

  // Mode = 3 (PWM, Phase Correct, 10-bit, TOP = 0x03FF) - Best quality for lights, since you can't visually see the duty cycle
  // INVERTING MODE: "Set OC0A on Compare Match, when up counting / Clear OC0A on Compare Match, when down counting"
  // Clock prescaler = 1

  TCCR4A = 0b00001011; // Mode 3, "PWM "IKKE fast", Phase Correct 10-bit, TOP = 0x03FF"
  // (NON INVERTING MODE in C-system: "Clear OC1B (pin 12 on Compare Match, when up counting / Set OC1B on Compare Match, when down counting) - Can't figure out why that works, and why inverting mode doesn't work
  // Initerer dog KUN systemet for baglys, fordi det kan godt afbryde motorens PWM-signaler
  TCCR4B = 0b00000001; // Clock prescaler = 1

  // Switch-statement:
  /* Når bilen er ved tilstanden "alm. lys" --> Duty cycle = 20% (pin 12) */
  OCR4C = 1024 / 5; // TOP-værdien for mode 3 er nemlig: TOP = 1024 = (1023 + 1)

  /* Når bilen er ved tilstanden "bremse lys" --> Duty cycle = 100 % (pin 13)*/
  // TCCR4A = 0b00000000; //Normal port operation
  // TCCR4B = 0b00000000; //Clock source deactivated (Timer/Counter stopped)
  // PORTH = 0b00100000; //Turn on OC4C, as digital high (pin 8)

  // OCR4C = 1024 - SKRIV OM HVORFOR DET IKKE VIRKER ! ! ! !

  //****SLUT MED TEST PÅ TIMER 4
}
