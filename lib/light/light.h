#pragma once

class lightDriver

{
public:
    void turnOnFrontlight();
    void turnOffFrontlight();
    void turnOnBrakeLight(int);
    void turnOffBrakeLight();
};

lightDriver initLightDriver();
