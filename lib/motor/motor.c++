#include "motor.h"

#include <avr/io.h>
#include <util/delay.h>
// Brug OC1B til hastigheden af motor (ben 12)
// Brug PB5 til at ændre spolens retning (ben 11)
// Brug PB4 til at give 5V til spolen (ben 10)
motorDriver::motorDriver()
{
    // Sætter PB'er til udgange
    DDRB = 0xFF;
    // Sætter Timer 1 til fast hvor TOP er 8 -bit og prescaler på 64
    TCCR1A = 0b00000001;
    TCCR1B = 0b00001011;
    // Følgende vil aktivere PWM signalerne
}
void motorDriver::MotorSpeed(int refleks)
{
    switch (refleks)
    {
    case 1:
        // 10% dutycycle
        OCR1B = 229.5;
        break;
    case 2:
        // 20% dutycycle
        OCR1B = 204;
        break;
    case 3:
        // 30% dutycycle
        OCR1B = 179;
        break;

    case 4:
        // 40% dutycycle
        OCR1B = 153;
        break;

    case 5:
        // 50% dutycycle
        OCR1B = 128;
        break;
    case 6:
        // 60% dutycycle
        OCR1B = 102;
        break;

    case 7:
        // 70% dutycycle
        OCR1B = 77;
        break;

    case 8:
        // 80% dutycycle
        OCR1B = 51;
        break;

    case 9:
        // 90% dutycycle
        OCR1B = 26;
        break;

    case 10:
        // 100% dutycycle
        OCR1B = 0;
        break;
    }
}

void motorDriver::Stop()
{
    // Slukker motoren
    TCCR1A &= 0b11001111;
    // Slukker for spolen
    PORTB &= 0b11011111;
}

void motorDriver::Direction(char dir)
{
    // Forward direction
    if (dir == 1)
    {
        TCCR1A |= 0b00110000;
        PORTB &= 0b11011111;
    }

    // Backwards direction
    else if (dir == 0)
    {
        // Sender 5V ud til spolen
        PORTB |= 0b00100000;
        // Tænder for OC1B
        TCCR1A |= 0b00110000;
    }
}
