#include "vehecle.h"
char k = 0;

Vehecle tank;

void setup(){
//tank.setupMotor();
Serial.begin(9600);
}

void loop(){
if( Serial.available() > 0 )
    k = Serial.read();
  switch ( k ) {
    case 'r': tank.forward(); break;
    case 'f': tank.backward(); break;
    case 'd': tank.turnLeft(); break;
    case 'g': tank.turnRight(); break;
    case 'h': tank.halt(); break;
  }
  k = 0;
  
}

