#pragma once

class motorDriver

{
public:
    void initMotorDriver();
    void stop();
    void forward(unsigned char);
    void backward(unsigned char);
};