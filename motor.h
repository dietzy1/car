#pragma once

class motorDriver

{
private:
    void initMotorDriver();
    void stop();
    void forward(unsigned char);
    void backward(unsigned char);
};