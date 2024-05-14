#include <Servo.h>
#include <AFMotor.h>

int i = 0; // motor speed
int pos = 0; //servo position

int trig = 13;
int trig1 = 11;
int echo = 12;
int echo1 = 10;

long dur, dur1, dur2, dis1, dis2, dis3;
long disM;

//motor setup
AF_DCMotor m(1);
AF_DCMotor m1(2);
AF_DCMotor m2(3);
AF_DCMotor m3(4);

//Servo Setup
Servo dis;

void setup(){
  //motor setup
  m.setSpeed(i);
  m.run(RELEASE);

  //servo setup
  dis.attach(10);

  //ultrasonic sensor setup
  pinMode(trig,OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trig, LOW);
}

void acc(){
  // code for acceleration
}

void check(){
  //check distance
  dis.write(0);
  
}

void distance(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur1 = pulseIn(echo, HIGH);
}
