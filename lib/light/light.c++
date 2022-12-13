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
  // make pin 5 of PORTB an output
  DDRB = 0xFF;

  // PORTB = 0b10000000
  // PORTB = 0b10000000; // Brug pin OC0A til at teste med 100% duty cycle (ca. 50 mA) & brug pin OC1A, som består af en duty cycle på 20% (ca. 10 mA)
  // Mode = 3 (PWM, Phase Correct, 10 bit)
  // Set OC1A on match down counting / Clear OC1A on match up counting
  // Clock prescaler = 1

  /* Når bilen er ved tilstanden "alm. lys" --> Duty cycle = 20% */

  // Initalize timers with 8 bit resolution for timer 0
  TCCR0A = 0b10000001;
  TCCR0B = 0b00000101;

  // turn on the light by setting pin 5 of PORTB high

  return lightDriver();
}

void lightDriver::turnOnFrontlight()
{
  PORTB = 0b00010000;
}

void lightDriver::turnOffFrontlight()
{
  PORTB = 0b00000000;
}

void lightDriver::turnOnBrakeLight(int intensity)
{
  // PORTB = 0b10000000
  // PORTB = 0b10000000; // Brug pin OC0A til at teste med 100% duty cycle (ca. 50 mA) & brug pin OC1A, som består af en duty cycle på 20% (ca. 10 mA)
  // Mode = 3 (PWM, Phase Correct, 10 bit)
  // Set OC1A on match down counting / Clear OC1A on match up counting
  // Clock prescaler = 1

  /* Når bilen er ved tilstanden "alm. lys" --> Duty cycle = 20% */

  switch (intensity)
  {
  case 1:
    OCR0A = 1024 / 5;
    break;
  case 2:
    OCR0A = 1024 / 2.5;
    break;
  default:
    break;
  };
}

void lightDriver::turnOffBrakeLight()
{
  PORTB = 0b00000000;
}
