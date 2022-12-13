
#include "../light/light.h"
#include "../sound/sound.h"
#include "../sound/uart.h"
#include "../motor/motor.h"
#include "../controller/controller.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main()
{
    controllerDriver controller = initControllerDriver();
    uartDriver uart = initUARTDriver();
    soundDriver sound = initSoundDriver(uart);
    lightDriver light = initLightDriver();
    motorDriver motor = initMotorDriver();

    // While button is not pressed simply loop around for infinity
    /*  char array[8] = {0x7E, 0x0D, 0x00, 0x00, 0x00, 0xFF, 0xF3, 0xEF};
     uart.sendCommand(array); */

    /*  char array[8] = {0x7E, 0x0D, 0x00, 0x00, 0x00, 0xFF, 0xF3, 0xEF};
 uart.sendCommand(array); */

    /*     sendString(uart); */

    light.turnOnFrontlight();

    /* sendCommand(uart, 1); */
    while (!controller.buttonPressed())
    {
    }
    // Initiate start of the car
    // light.turnOnFrontlight();
    light.turnOnBrakeLight(1);
    /* sound.playSound(uart, 1); */
    motor.forward(255);

    // variable to ensure the cases in the while loop do not constantly run
    int verifyCounter = 0;
    // Start the loop that reacts to counter interrupts

    while (1)
    {
        controller.ReactToInput(light, sound, uart, motor, &verifyCounter);
    }
}

// For now all should be public //unsure if private would work //protected might work since they are inherited from the class

// Start position bilen skal accelerere i et tempo så den ikke giver udsving
// Ved 1 skal bilen forberede sig på at sænke farten - potentielt skal farten allerede være lavere
// Ved 2 skal bilens hastighed sænkes så den er klar til at køre op ad bakken
// Ved 3 er bilen på toppen af bakken og dens hastighed skal sænkes betydeligt
// Ved 4 Kan hastigheden øges igen
// Ved 5 springer bilen refleksen over og skal efterfølgende sænke farten
// Ved 6 Skal bilen være i fuld stop hvorefter bilen skal skifte køreretning til bagud
// Ved 5 Skal bilen være i fuld stop og køreretningen skiftes til fremad
// Ved 6 springes refleksen over
// Ved 7 skal bilen i fuld stop relativt hurtigt for at bilen ikke kører længere end hvad banen har.

// TODO:
/* void car::initButtonDriver()
{
    // 75AD3 which is the same as port 25 on the arduino
    DDRA &= ~(1 << 3);
}

// Recieve signal from the button on PORTA
char ButtonPressed()
{
    if (PORTA == 0b00010000)
    {
        return 1;
    };
} */

// TODO:
// Should prolly be INT0_vect because its PD ben 0

/* volatile bool boolio = false;

ISR(INT0_vect) // Left sensor
{
    if (boolio == false)
    {
        boolio = true;
        counter++;
        _delay_ms(250);
        boolio = false;
    };
    return;
} */

// TODO: //should prolly be INT1_vect because its PD ben 1
/* ISR(INT1_vect) // Right sensor
{
    if (boolio == false)
    {
        boolio = true;
        counter++;
        _delay_ms(250);
        boolio = false;
    };
    return;
} */

// Function that enabled interupts for the left and right sensor on the car
/* void car::initInterrupts()
{
    // TODO: This part I need to double check it is potentially incorrect

    // Rising edge interupt is enabled for INT0 and INT1
    EICRA |= 0b00001111;
    // Enables INT0 and INT1
    EIMSK |= 0b00000011;
    // call sei to enable interrupts
    sei();
} */
