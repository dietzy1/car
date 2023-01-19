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
