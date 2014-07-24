//Written by Brendan Gregos and Dominic Kynkor for Team 3164's US SOCOM Project TALOS Prototype
//Hardware: Code is designed to run on the Arduino Mega 2560 r3. The motor controllers used are VEX Victor 888's.
//Style Notice: All indents will be two spaces (Two spaces are inserted when TAB is pressed in the Ardunio IDE).

/*Compile Notices:
- Program is designed to be compiled in the Arduino IDE. Version in use is 1.0.5-r2.
- If you receive "'A8' was not declared in this scope", goto Tools > Board > Arduino Mega 2560.
- If you receive "joint.cpp:3:19: fatal error: Joint.h: No such file or directory" goto Sketch > Import Library > Add library... and find Joint.h in the source.
*/


//Includes
#include "Arduino.h"
#include "Joint.h"
#include <Servo.h>


//Analog Ports -- Naming scheme: l= left, r=right, h=hip, k=knee, a=ankle.
#define AccelerometerX A0
#define AccelerometerY A1
#define AccelerometerZ A2
#define GyroX A3
#define GyroY A4
#define GyroZ A5
#define Potlh A6 //left hip
#define Potlk A7 //left knee
#define Potla A8 //left ankle
#define Potrh A9 //right hip
#define Potrk A10
#define Potra A11

//Digital Ports
//PWM
#define Victorlh 2
#define Victorlk 3
#define Victorla 4
#define Victorrh 5
#define Victorrk 6
#define Victorra 7

//Non-PWM

void setup() {
  // put your setup code here, to run once:
  pinMode(AccelerometerX, INPUT);
  pinMode(AccelerometerY, INPUT);
  pinMode(AccelerometerZ, INPUT);
  pinMode(GyroX, INPUT);
  pinMode(GyroY, INPUT);
  pinMode(GyroZ, INPUT);
  pinMode(Potlh, INPUT);
  pinMode(Potlk, INPUT);
  pinMode(Potla, INPUT);
  pinMode(Potrh, INPUT);
  pinMode(Potrk, INPUT); 
  pinMode(Potra, INPUT);
  
  //victor pinmodes are defined inside the class.
  Joint Motorlh(Victorlh, Potlh);
  Joint Motorlk(Victorlk, Potlk);
  Joint Motorla(Victorla, Potla);
  Joint Motorrh(Victorrh, Potrh);
  Joint Motorrk(Victorrk, Potrk);
  Joint Motorra(Victorra, Potra);
  
  
}

void loop() {
  // put your main code here, to run repeatedly: 
  Motorlh.UpdateSpeed();
}
