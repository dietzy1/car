
#include "../light/light.h"
#include "../sound/sound.h"
#include "../sound/uart.h"
#include "../motor/motor.h"
#include "../controller/controller.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>

int main()
{
    // Initiate classes with constructors
    uartDriver uart;
    soundDriver sound(&uart);
    lightDriver light;
    motorDriver motor;

    // Initiate the controller class and inject the classes as dependencies
    controllerDriver controller(&light, &sound, &motor);

    // Stay stuck in the loop until the button if pressed
    while (!controller.ButtonPressed())
    {
    }

    char array[] = "EXITED THE LOOP";
    consoleLog(array);

    // Initiate start of the car
    controller.StartCar();

    // initiate loop that reacts to input
    while (1)
    {
        controller.ReactToInput();
    }
}

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
