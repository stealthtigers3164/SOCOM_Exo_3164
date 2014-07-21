//Written by Brendan Gregos and Dominic Kynkor for Team 3164's CTEF SOCOM Project TALOS Submission
//Analog Ports
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
#define SoftwareDisableSwitch 22

//The following functions are used in void setup() and void loop().



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
  Joint Motorlh(Victorlh);
  
  
}

void loop() {
  // put your main code here, to run repeatedly: 
  
}
