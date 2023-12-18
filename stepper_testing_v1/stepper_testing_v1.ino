#include <AccelStepper.h>

//DEFINITIONS FOR MOTX
#define STEPX 3
#define DIRX 6
#define EN 8

//DEFINITIONS FOR MOTY
#define STEPY 2
#define DIRY 5


//Create AccelStepper objects
AccelStepper MOTX(AccelStepper::DRIVER ,STEPX, DIRX);
AccelStepper MOTY(AccelStepper:: DRIVER ,STEPY,DIRY);


void setup() {

//Define pinout for enable
  pinMode(EN, OUTPUT);
  digitalWrite(EN,LOW);

  //Start Serial 
  Serial.begin(9600);

  //set max speed and accel
  MOTX.setMaxSpeed(1000);
  MOTY.setMaxSpeed(1000);
  MOTX.setAcceleration(500);
  MOTY.setAcceleration(500);

}

void loop() {

/*
if(Serial.available()>0){
  int step=Serial.parseInt();

  
 MOTX.moveTo(step);
 MOTX.runToPosition();

 Serial.println("Completed");
 
}
*/
MOTY.moveTo(500);
MOTY.runToPosition();
MOTX.moveTo(500);
MOTX.runToPosition();


delay(1000);
MOTY.moveTo(-500);
MOTY.runToPosition();
MOTX.moveTo(-500);
MOTX.runToPosition();
delay(1000);

}
