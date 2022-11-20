#include "light.h"

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
    // initiate light driver
    return lightDriver();
}

void lightDriver::turnOn(int lightNumber)
{
}

void lightDriver::turnOff(int lightNumber)
{
}
