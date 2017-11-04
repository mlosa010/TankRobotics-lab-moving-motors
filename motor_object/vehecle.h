#ifndef VEHECLE_H
#define VEHECLE_H
#include "Arduino.h"

class Vehecle {
  public:
    Vehecle (int pwm1 = 10, int pwm2 = 11,
             int dir1 = 13, int dir2 = 4 );
    void setupMotor();
    void setPwmFrequency(int pin, int divisor);
    void changePwms(int pin1, int pin2 , int w1, int w2);
    void forward();
    void backward();
    void turnLeft();
    void turnRight();
    void halt();
    int Vehecle::speedMotors( bool d1, bool d2,int ww);
    
  private:
    int w =0;
    int v = 161;
    int m_pwm1;
    int m_pwm2;
    int m_dir1;
    int m_dir2;
};

#endif




