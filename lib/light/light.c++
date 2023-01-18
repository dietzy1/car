#include "light.h"

#include <avr/io.h>

// Constructor that initiates the light driver
lightDriver::lightDriver()
{
  DDRH = 0xFF;
}

void lightDriver::TurnOnFrontlight()
{
  PORTH = 0b00010000; // Turn on PH4, equivalent to LED4
}

void lightDriver::TurnOffFrontlight()
{
  PORTH = 0b00000000;
}

void lightDriver::TurnOnBrakeLight(int intensity)
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

void lightDriver::TurnOffBrakeLight()
{
  TCCR4B = 0b00000000;
  PORTH = 0b00000000;
}
