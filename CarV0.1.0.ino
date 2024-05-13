/*To-Do
Add servo for distance
*/


#include <Servo.h>
#include <AFMotor.h>

int light = 13;
int ind1 = 4; // right side
int ind0 = 3; // left side
int buz = 2;
int servoPin = 9;
int trig = 6;
int echo = 5;
int res = A0;
int spd = 255;

const int mindist = 20;

long dur, dist;
long d1, d2, d3;
int resVal;

Servo ms;

AF_DCMotor m1 (1);
AF_DCMotor m2 (2);
AF_DCMotor m3 (3);
AF_DCMotor m4 (4);

void setup(){
  pinMode(light, OUTPUT);
  pinMode(ind1, OUTPUT);
  pinMode(ind0, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(res, INPUT);
  ms.attach(servoPin);
  startup();
}

void loop(){
  // nothing yet
}

void startup(){
  digitalWrite(ind0, HIGH);
  digitalWrite(ind1, HIGH);
  digitalWrite(buz, HIGH);
  delay(1000);
  digitalWrite(ind0, LOW);
  digitalWrite(ind1, LOW);
  digitalWrite(buz, LOW);
  ms.write(90);
}

void c1(){
  
}

void light(){
  resVal = analogRead(res);
  if (resVal < 50){
    activ(); 
  }
  else{
    deactiv();
  }
}

void activ(){
  digitalWrite(light, HIGH);
}

void deactiv(){
  digitalWrite(light, LOW);
}

void disti(){
  pinMode(trig, HIGH);
  delayMicroseconds(10);
  pinMode(trig, LOW);
  dur = pulseIn(echo, HIGH);
  dist = (dur/2)/29.1;
  
}

void checkAndCompare(){
  ms.write(90);
  disti();
  d1 = dist;
  ms.write(45);
  disti();
  d2 = dist;
  ms.write(135);
  disti();
  d3 = dist;
  compare();
}

void compare(){
  if (d1 > d2 && d1 > d3){
    speedOrCont();
  }
  else if(d1 < d2 || d1 < d3){
    caut();
  }
  else if(d1 <= mindist){
    chgLn();
  }
  else{
    // do nothing
  }
}

void caut(){
  // caution
  m1.setSpeed(spd - 40);
  m2.setSpeed(spd - 40);
  m3.setSpeed(spd - 40);
  m4.setSpeed(spd - 40);
  delay(500);
  compare();
}

void chgLn(){
  // change Lane
  if (d2 > d3){
    leftind();
    // set motor instructions
  }
  else if (d2 < d3){
    rightind();
    // set motor instructions
  }
}

void speedOrCont(){
  //speed or continue
  if (spd == 255){
    //do nothing
  }
  else{
    spd = spd - 1;
    compare();
  }
  
}
