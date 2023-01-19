
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
