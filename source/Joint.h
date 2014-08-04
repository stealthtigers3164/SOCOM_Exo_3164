#ifndef Joint_h
#define Joint_h

#include "Arduino.h"
#include <Servo.h>

/*class Joint
{
  private:
    //signed int dutyCycle = 0; 
 //creates a servo object
    int _pwmPin;
    int _potPin;
    int potvalue;
    unsigned int highus; //used by jag signal generator
    unsigned int lowus;
    
  public:
    Servo victor;
    Joint(int _pwmPin, int _potPin);
    void UpdateSpeed();
  

};
*/
class Joint{
  protected:
  Servo victor;
  double error;
  int setpoint;
  double output;
  double integral;
  double derivative;
  double preError;
  unsigned long period;
  unsigned long oldperiod;
  
  double Kp;
  double Ki;
  double Kd;

  public:
  Joint();
  void attachPin(int pin);
  void writePin(int value);
  int doPID(int input, int setpoint);
};
#endif
