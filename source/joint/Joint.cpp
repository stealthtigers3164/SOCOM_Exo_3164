#include "Arduino.h"
#include "Joint.h"

Joint::Joint(byte pwmPin)
  {
    pinMode(pwmPin, OUTPUT); 
    digitalWrite(pwmPin, LOW);
  }

void Joint::UpdateSpeed(byte speed)
  {
    digitalWrite(pwmPin, HIGH);
    delayMicroseconds(highus);
    digitalWrite(pwmPin, LOW);
    delayMicroseconds(lowus);
  
    highus = 5 * speed + 1500;
    lowus = 1000;

  }
