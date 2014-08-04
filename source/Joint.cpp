#include "Joint.h"

Joint::Joint()
  {
  error=0;
  setpoint=50;
  output=0;
  integral=0;
  derivative=0;
  preError=0;
  period=0;
  oldperiod=0;
  
  Kp=.4;
  Ki=.0005;
  Kd=2;
    
    
  }

/*void Joint::UpdateSpeed()
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
  
  int Joint::doPID(int input, int setpoint){ //3-4ms
    period = millis()-oldperiod;
    oldperiod=millis();
   Serial.println(period);
    // calculate the difference between
   // the desired value and the actual value
  error = setpoint - input; 
   // track error over time, scaled to the timer interval
  integral = integral + (error * period);

   // determine the amount of change from the last time checked
  derivative = (error - preError) / period; 
 
   // calculate how much to drive the output in order to get to the 
   // desired setpoint. 
  output = ((Kp * error) + (Ki * integral) + (Kd * derivative));
   // remember the error for the next time around.
  preError = error;  
  
  output=output+89; //89 is the stop value for the victors
  
  if (output>179) output=179;
  else if (output<0) output=0;
  

  
  return (int)output;
  }
  

  

