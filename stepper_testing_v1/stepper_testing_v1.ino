************************************************
NAME: SPARSH BHARATI PRINTER
AUTHOR: DIVYARATNA JOSHI
EMAIL: 1724akul@gmail.com
************************************************


!!!IMPORTANT NOTE!!!
FOR EVERY X MOVEMENT OF MOTX THERE MUST BE -X/2 MOVEMENT OF MOTY TO ACCOUNT
FOR TIMING BELT DRIFT

************************************************



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
MOTX.move(1500);

MOTY.move(750);
MOTX.run();
MOTY.run();


}
