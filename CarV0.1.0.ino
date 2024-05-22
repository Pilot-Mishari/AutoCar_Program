#include <Servo.h>
#include <AFMotor.h>

int i = 0; // motor speed
int pos = 0; //servo position

int trig = 13;
int trig1 = 11;
int echo = 12;
int echo1 = 9;

int normBright = 180; // normal working brightness for back light
int ind = 255; // indicator use for back light
int indZ = 0;

long dur, dur1, dis1, dis2, dis3; // for front
long dur0, dur11, dis11, dis22, dis33; //for back
long disM, disY;

// light connections see doc for full pins
backLeft = 6;
backRight = 5;
white = 4;
indicL = 8;
indiR = 7;

//motor setup
AF_DCMotor m(1);
AF_DCMotor m1(2);
AF_DCMotor m2(3);
AF_DCMotor m3(4);

//Servo Setup
Servo dis;
Servo dis0;

void setup(){
  //motor setup
  m.setSpeed(i);
  m1.setSpeed(i);
  m2.setSpeed(i);
  m3.setSpeed(i);
  m3.run(RELEASE);
  m.run(RELEASE);
  m1.run(RELEASE);
  m2.run(RELEASE);
  
  //servo setup
  dis.attach(10);
  dis0.attach(9);

  //ultrasonic sensor setup
  pinMode(trig,OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trig, LOW);
}

void acc(){
  // code for acceleration
  
}

void checkFront(){
  //check distance in front
  dis.write(45);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur1 = pulseIn(echo, HIGH);
  dis1 = (dur1*0.039)/2;

  // distance at 90 deg
  dis.write(90);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur1 = pulseIn(echo, HIGH);
  dis2 = (dur1*0.039)/2;

  // distance at 135
  dis.write(90);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur1 = pulseIn(echo, HIGH);
  dis3 = (dur1*0.039)/2;

  if(dis2 >= 20){
    compareFront();
  }
  else if (dis2 >= 80){
    accelerate();
  }
}

void checkBack(){
  // distance at 90 deg
  dis0.write(90);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur11 = pulseIn(echo, HIGH);
  dis22 = (dur1*0.039)/2;

  if(dis22 <= 4){
    backAction();
  }
  else{
    // do nothing...
  }
}

void compareFront(){
  // compare distances and code exe.
  if (dis2 > 12){
    //check weather left is larger or right
    if(dis1 > dis3){
      // turn left code
    }
    else if(dis1 < dis3){
      // turn right code
    }
    else{
      // do nothing
    }
  }
  else{
    //do nothing
  }
}

void accelerate(){
  // acceleration
  if(dis2 >= 16){
    i++;
    checkFront();
  }
  else{
    // do nothing yet!
  }
}

void backAction(){
  // action to exe. when back is too close

  // back red indicator
  for(int irun = 0; irun < 10; irun++){
    analogWrite(backLeft, ind);
    analogWrite(backRight, ind);
    delay(75);
    analogWrite(backLeft, indZ);
    analogWrite(backRight, indZ);
  }
  
}

void save(){
  // code here will be put on standby with info

  // for checking lane before turning. will check back
  // check distance in back
  dis0.write(45);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur11 = pulseIn(echo, HIGH);
  dis11 = (dur1*0.039)/2;

  // distance at 135
  dis0.write(90);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur11 = pulseIn(echo, HIGH);
  dis33 = (dur1*0.039)/2;

  // must also add for 90
}
