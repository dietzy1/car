#pragma once

class motorDriver

{
public:
    motorDriver();

    void stop();
    void forward(unsigned char);
    void backward(unsigned char);
};
