#pragma once

class motorDriver

{
public:
    void stop();
    void forward(unsigned char);
    void backward(unsigned char);
};

motorDriver initMotorDriver();