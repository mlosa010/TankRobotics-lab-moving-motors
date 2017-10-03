#include "Arduino.h"
#include"vehecle.h"

Vehecle::Vehecle(int pwm1,int pwm2, int dir1, int dir2){
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  this->m_pwm1 = pwm1;
  m_dir1 = dir1;
  m_pwm2 = pwm2;
  m_dir2 = dir2;
  setupMotor();
}
void Vehecle::setupMotor(){
  setPwmFrequency(m_pwm1,1);
  setPwmFrequency(m_pwm2,1);
}

int Vehecle::speedMotors( bool d1, bool d2,int ww){
  digitalWrite(m_pwm1,d1);
  digitalWrite(m_pwm2,d2);
  changePwms(m_pwm1,m_pwm2,w,ww);
  w=ww;
}

void Vehecle::changePwms(int pin1, int pin2 , int w1, int w2){
  if ( w1 == w2 )
    return;
  int s = w1 > w2 ? -1:1;
  int w = w1;
  while ( w != w2 ) {
    analogWrite(m_pwm1,w);
    analogWrite(m_pwm2,w);
    w += s*1;
    delayMicroseconds(100000);
  }
  
}
void Vehecle::setPwmFrequency(int pin, int divisor){
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
void Vehecle::forward(){
    speedMotors(HIGH,HIGH,v);
  }
  void Vehecle::backward(){
    speedMotors(LOW,LOW,v);
  }
  void Vehecle::turnLeft(){
    speedMotors(HIGH,LOW,v);
  }
  void Vehecle::turnRight(){
    speedMotors(LOW,HIGH,v);
  }
  void Vehecle::halt(){
    speedMotors(HIGH,HIGH,0);
  }

