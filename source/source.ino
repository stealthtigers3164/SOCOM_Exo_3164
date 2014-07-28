//Written by Brendan Gregos and Dominic Kynkor for Team 3164's US SOCOM Project TALOS Prototype
//Hardware: Code is designed to run on the Arduino Mega 2560 r3. The motor controllers used are VEX Victor 888's.
//Style Notice: All indents will be two spaces (Two spaces are inserted when TAB is pressed in the Ardunio IDE).

/*Compile Notices:
- Program is designed to be compiled in the Arduino IDE. Version in use is 1.0.5-r2.
- If you receive "'A8' was not declared in this scope", goto Tools > Board > Arduino Mega 2560.
- If you receive "joint.cpp:3:19: fatal error: Joint.h: No such file or directory" goto Sketch > Import Library > Add library... and find Joint.h in the source.
*/

  //Analog Ports -- Naming scheme: l= left, r=right, h=hip, k=knee, a=ankle.
int AccelerometerX=0;
int AccelerometerY=1;
int AccelerometerZ=2;
int GyroX=3;
int GyroY=4;
int GyroZ=5;
int PotLh=6;//left hip
int PotLk=7; //left knee
int PotLa=8; //left ankle
int PotRh=9; //right hip
int PotRk=10;
int PotRa=11;

//Digital Ports
//PWM
int VictorLh=2;
int VictorLk=3;
int VictorLa=4;
int VictorRh=5;
int VictorRk=6;
int VictorRa=7;
  
//Includes
#include "Arduino.h"
#include "Joint.h"
#include <Servo.h>




//Non-PWM
  Joint MotorLh;
  Joint MotorLk;
  Joint MotorLa;
  Joint MotorRh;
  Joint MotorRk;
  Joint MotorRa;

void attachPins(){
  MotorLh.attachPin(VictorLh);
  MotorLk.attachPin(VictorLk);
  MotorLa.attachPin(VictorLa);
  MotorRh.attachPin(VictorRh);
  MotorRk.attachPin(VictorRk);
  MotorRa.attachPin(VictorRa);
  
}

void setup() {
  // put your setup code here, to run once:
  pinMode(AccelerometerX, INPUT);
  pinMode(AccelerometerY, INPUT);
  pinMode(AccelerometerZ, INPUT);
  pinMode(GyroX, INPUT);
  pinMode(GyroY, INPUT);
  pinMode(GyroZ, INPUT);
  pinMode(PotLh, INPUT);
  pinMode(PotLk, INPUT);
  pinMode(PotLa, INPUT);
  pinMode(PotRh, INPUT);
  pinMode(PotRk, INPUT); 
  pinMode(PotRa, INPUT);
  Serial.begin(9600);
  //delay(5000);
  attachPins();
  
}
  
void loop() {
  // put your main code here, to run repeatedly: 
  MotorLh.writePin(179);
  MotorLk.writePin(6);
}
