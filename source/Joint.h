#ifndef Joint_h
#define Joint_h

#include "Arduino.h"
#include <Servo.h>

class Joint
{
;
  public:
    Joint(int pwmPin, int potPin);
  private:
    //signed int dutyCycle = 0; 
    Servo victor; //creates a servo object
    void UpdateSpeed();
    int pwmPin;
    int potPin;
    int potvalue;
    unsigned int highus; //used by jag signal generator
    unsigned int lowus;

};

#endif
