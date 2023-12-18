/************************************************
NAME: SPARSH BHARATI PRINTER
AUTHOR: DIVYARATNA JOSHI
EMAIL: 1724akul@gmail.com
************************************************

!!!IMPORTANT NOTE!!!
FOR EVERY X MOVEMENT OF MOTX THERE MUST BE X/1.5 MOVEMENT OF MOTY TO ACCOUNT
FOR TIMING BELT DRIFT

************************************************/



#include <AccelStepper.h>
#include <Servo.h>



//DEFINITIONS FOR MOTX
#define STEPX 3
#define DIRX 6
#define EN 8
#define servo 11

//DEFINITIONS FOR MOTY
#define STEPY 2
#define DIRY 5

//GLOBAL VARIABLES FOR X AND Y MOVEMENT
//int x,y;


//Create AccelStepper and servo objects
AccelStepper MOTX(AccelStepper::DRIVER ,STEPX, DIRX);
AccelStepper MOTY(AccelStepper:: DRIVER ,STEPY,DIRY);
Servo MOTZ;


void setup() {


// Attatch Servo
  MOTZ.attach(servo);

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
  int x=Serial.parseInt();

  xMove(x);
 Serial.println("Completed");
 
}
*/

yMove(100);






}


//SERVO ACTUATION
void servAct()
{
  MOTZ.write(30);
  MOTZ.write(0);
  delay(200);
  MOTZ.write(30);
}


//MOVEMENT IN X
void xMove(int x)
{
  MOTX.move(x);
  MOTY.move(x);
  MOTX.run();
  MOTY.run();
}


//MOVEMENT IN Y
void yMove(int y)
{
  MOTY.move(y);
  MOTX.move(-y);
  MOTX.run();
  MOTY.run();
}
