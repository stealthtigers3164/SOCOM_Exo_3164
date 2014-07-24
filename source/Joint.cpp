#include "Arduino.h"
#include "Joint.h"

Joint::Joint(int pwmPin, int potPin)
  {

    int potValue; //used to read the value from the potentiometer
    victor.attach(pwmPin);
    
    
  }

void Joint::UpdateSpeed()
  {
    /*digitalWrite(pwmPin, HIGH);
    delayMicroseconds(highus);
    digitalWrite(pwmPin, LOW);
    delayMicroseconds(lowus);
  
    highus = 5 * speed + 1500;
    lowus = 1000;
    */
    
    potvalue = analogRead(potPin);
    potvalue = map(potvalue, 0, 1023, 0, 179);
    victor.write(potvalue);
    //if program acts erratically, add a delay() here.
    //servo update must be done every 500 ms.
  }
