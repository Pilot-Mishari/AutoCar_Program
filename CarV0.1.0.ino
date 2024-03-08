#include <Servo.h>
#include <AFMotor.h>

int red0 = 13;
int red1 = 12;
int whi0 = 8;
int whi1 = 7;
int ind0 = 4;
int ind1 = 3;
int buz = 2;
int servoPin = 9;

long duration, dist;

#define trig 6;
#define echo 5;

Servo ms;

AF_DCMotor m1 (1);
AF_DCMotor m2 (2);
AF_DCMotor m3 (3);
AF_DCMotor m4 (4);

void setup(){
  pinMode(red0, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(whi0, OUTPUT);
  pinMode(whi1, OUTPUT);
  pinMode(ind1, OUTPUT);
  pinMode(ind0, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(echo, INPUT);
  ms.attach(servoPin);
  startup()
}

void loop(){
  // nothing yet
}

void startup(){
  digitalWrite(red0, HIGH);
  digitalWrite(red1, HIGH);
  digitalWrite(whi0, HIGH);
  digitalWrite(whi1, HIGH);
  digitalWrite(ind0, HIGH);
  digitalWrite(ind1, HIGH);
  delay(1000)
  digitalWrite(red0, LOW);
  digitalWrite(red1, LOW);
  digitalWrite(whi0, LOW);
  digitalWrite(whi1, LOW);
  digitalWrite(ind0, LOW);
  digitalWrite(ind1, LOW);
  ms.write(90);
}
