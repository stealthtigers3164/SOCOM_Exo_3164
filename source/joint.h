#ifndef Joint_h
#define Joint_h

#include "Arduino.h"

class Joint
{
  public:
    Joint(byte pwmPin);
    void UpdateSpeed(byte speed);
    byte speed;
    byte pwmPin;
  
  private:
    //signed int dutyCycle = 0; 
    unsigned int highus; //used by jag signal generator
    unsigned int lowus;

};

#endif
