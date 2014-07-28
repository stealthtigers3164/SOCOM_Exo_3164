#include "Joint.h"

/*Joint::Joint(int _pwmPin, int _potPin)
  {

    this->_potPin=_potPin;
    this->_pwmPin=_pwmPin;
    int potValue; //used to read the value from the potentiometer
    Serial.println("Constructor");
    //this->victor.attach(2);
    
    
  }

void Joint::UpdateSpeed()
  {
    this->victor.attach(2);
    Serial.println("I promise I am working");
    
    //Serial.println(_potPin);
    potvalue = analogRead(_potPin);
    potvalue = map(potvalue, 0, 1023, 0, 179);
    this->victor.write(potvalue);
    delay(15);
    //if program acts erratically, add a delay() here.
    //servo update must be done every 500 ms.
  }
  
  */
  
  void Joint::attachPin(int pin)
  {
    this->victor.attach(pin);
  }
 
  void Joint::writePin(int value)
  {
    this->victor.write(value);
  }
 
  

  

