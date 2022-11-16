
#include <avr/io.h>
// using namespace std;

// Bilen skal have en variende acceleration baseret ud fra dens position på banen

class car
{
private:
    int counter;
    void initButtonDriver();
    void startCar();
};

void car::initButtonDriver()
{
    ddra = 0
    //
}

class lightDriver : public car

{
private:
    void initLightDriver();
    void turnOn(int);
    void turnOff(int);
};

class motorDriver : public car

{
private:
    void initMotorDriver();
    void stop();
    void forward(unsigned char);
    void backward(unsigned char);
};

class soundDriver : public car
{
public:
    void initSoundDriver();
    void playSound();
};

int main()
{

    // Need to wait for button input to start the run might need 2 nested while loops to do this

    // instantiate a class object
    car c;
    soundDriver s;
    lightDriver l;
    motorDriver m;

    switch (c.counter)
    {
    case 1:
        // turn on light 1
        l.turnOn(1);
        // play sound
        s.playSound(2);
        // start car
        m.forward(255);
        break;
    case 2:
        s.playSound(2);
        // start car
        m.forward(255);
        break;
    case 3:
        s.playSound(2);
        // start car
        m.forward(255);
        break;
    case 4:
        s.playSound(2);
        // start car
        m.forward(255);
        break;

    case 5:
        s.playSound(2);
        // start car
        m.forward(255);
        break;

    case 6:
        s.playSound(2);
        // start car
        m.forward(255);
        break;
    case 7:
        s.playSound(2);
        // start car
        m.forward(255);
        break;
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
