//Written by Brendan Gregos and Dominic Kynkor for Team 3164's US SOCOM Project TALOS Prototype
//Hardware: Code is designed to run on the Arduino Due. The motor controllers used are VEX Victor 888's.
//Style Notice: All indents will be two spaces (Two spaces are inserted when TAB is pressed in the Ardunio IDE).

/*Compile Notices:
- Program is designed to be compiled in the Arduino IDE. Version in use is 1.0.5-r2.
- If you receive "'A8' was not declared in this scope", goto Tools > Board > Arduino Due. You must be running Arduino IDE 1.5+ for this.
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
//  MotorLh.writePin(MotorLh.doPID(map(analogRead(PotLh),0,1023,0,179), map(analogRead(0),0,1023,0,179)));
  MotorRa.writePin(MotorRa.doPID(map(analogRead(PotRa),0,1023,0,179), map(analogRead(0),0,1023,0,179)));
  MotorRk.writePin(MotorRk.doPID(map(analogRead(PotRk),0,1023,0,179), map(analogRead(1),0,1023,0,179)));
  MotorRh.writePin(MotorRh.doPID(map(analogRead(PotRh),0,1023,0,179), map(analogRead(2),0,1023,0,179)));
  MotorLa.writePin(MotorLa.doPID(map(analogRead(PotLa),0,1023,0,179), map(analogRead(3),0,1023,0,179)));
  MotorLk.writePin(MotorLk.doPID(map(analogRead(PotLk),0,1023,0,179), map(analogRead(4),0,1023,0,179)));
  MotorLh.writePin(MotorLh.doPID(map(analogRead(PotLh),0,1023,0,179), map(analogRead(5),0,1023,0,179)));
}


///The following code is no longer used but kept around. Instead of using a master-slave hardware config, voltage converters were used instead, making this code uneeded.

/*String inString = ""; //holds input from Serial Port
int pots[6];
int potnumber=0;
bool ReadNetworkVars(){ 
  //Serial.println("Reading Network Variables.");
   //the slave continuously sends values.
   while(Serial.available()>0){ //continue processing until no more serial data is left in buffer
     Serial.print("Recieved ");
     int inChar = (char)Serial.read();
     Serial.println(inChar);
     if(inChar == 'i'){ //format is i(integer)numbers\n Example: i53\n = 53
       Serial.println("Reading integer...");
     }else if((char)inChar=='n'){ //reads the stream into a string until newline is seen
         //don't send a newline into the output
         pots[potnumber]=inString.toInt();
          potnumber++;
          inString = "";
       }else{      
           inString += (char)inChar; //adds current character to string
           Serial.println(inString);
       }
     }
   if(potnumber>=6){potnumber=0;}
   if(!pots[0]==0){
     for(int i=0; i<6; i++){
       Serial.println(pots[i]);
     }
   }
  return 0; 
}

bool SendNetworkVar(int toSend){
   Serial.print("i");
   Serial.print(toSend);
   Serial.print("n");
   return 0;
}
*/
