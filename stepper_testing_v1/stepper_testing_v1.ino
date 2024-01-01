/************************************************
NAME: SPARSH BHARATI PRINTER
AUTHOR: DIVYARATNA JOSHI
EMAIL: 1724akul@gmail.com
************************************************

!!!IMPORTANT NOTE!!!
FOR EVERY X MOVEMENT OF MOTX THERE MUST BE -X MOVEMENT OF MOTY TO ACCOUNT
FOR TIMING BELT DRIFT

************************************************/



#include <AccelStepper.h>
#include <Servo.h>



//DEFINITIONS FOR MOTX
#define STEPX 3
#define DIRX 6
#define EN 8

//DEFINITIONS FOR SERVO ACTUATION
#define servA 11
#define servB 12
#define servC 13

//DEFINITIONS FOR MOTY
#define STEPY 2
#define DIRY 5

//GLOBAL VARIABLES FOR X AND Y MOVEMENT
int mmToSteps=10;


//Create AccelStepper and servo objects
AccelStepper MOTX(AccelStepper::DRIVER ,STEPX, DIRX);
AccelStepper MOTY(AccelStepper:: DRIVER ,STEPY,DIRY);
Servo MOTA;
Servo MOTB;
Servo MOTC;


void setup() {


// Attatch Servo
  MOTA.attach(servA);
  MOTB.attach(servB);
  MOTC.attach(servC);

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


serialInput();

}




//TAKE SERIAL INPUT AND DO MOTION
void serialInput()
{
  if(Serial.available()>0)
  {
    String inputString = Serial.readString(); 
    Serial.println(inputString);

    // Extract x, y, and motor motion values from the string
    int xMotion =  mmToStep*inputString.substring(0, 3).toInt();
    int yMotion =  mmToStep*inputString.substring(3, 6).toInt();
    int aMotion =  inputString.charAt(6) - '0';
    int bMotion =  inputString.charAt(7) - '0';
    int cMotion =  inputString.charAt(8) - '0';

    Serial.println(xMotion);
    Serial.println(yMotion);
    aMove(aMotion);
    bMove(bMotion);
    cMove(cMotion);
    xMove(xMotion);
    yMove(yMotion);
  
  } 
}


//SERVO ACTUATION
void aMove(int a)
{
  if(a==1){
  MOTA.write(30);
  MOTA.write(0);
  delay(200);
  MOTA.write(30);
  }
}


void bMove(int b)
{
  if(b==1){
  MOTB.write(30);
  MOTB.write(0);
  delay(200);
  MOTB.write(30);
  }
}

void cMove(int c)
{
  if(c==1){
  MOTC.write(30);
  MOTC.write(0);
  delay(200);
  MOTC.write(30);
  }
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
