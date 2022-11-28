/*
1401 - 09 - 01
Building first srtucture
*/

#include "SRF05.h"
#define trigger 12
#define echo 13

SRF05 SRF(trigger, echo);


//Define part
#define l_motor 9  //ENA
#define l_motor_in1 7
#define l_motor_in2 6
#define r_motor 3  //ENB
#define r_motor_in3 4
#define r_motor_in4 5

int p, pot;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int p, pot;

  pinMode(A1, INPUT);
  SRF.setCorrectionFactor(1.035);
}

void loop() {
  // put your main code here, to run repeatedly:
  float distance;
  int Direction;
  distance = SRF.getCentimeter();

  while (distance > 30) {
    forward();
    delay(200);
    distance = SRF.getCentimeter();
  }

  stop();
  delay(120);
  Direction = random(1, 3);
  Serial.print(Direction);

  if (Direction==1) {
    CW();
  }

  if (Direction==2) {
    CCW();
  }

  delay(300);
}


//Functions
void forward() {
  digitalWrite(l_motor_in1, LOW);
  digitalWrite(l_motor_in2, HIGH);
  analogWrite(l_motor, 255);

  digitalWrite(r_motor_in3, LOW);
  digitalWrite(r_motor_in4, HIGH);
  analogWrite(r_motor, 255);
}

void stop() {
  digitalWrite(l_motor_in1, HIGH);
  digitalWrite(l_motor_in2, LOW);
  analogWrite(l_motor, 0);

  digitalWrite(r_motor_in3, HIGH);
  digitalWrite(r_motor_in4, LOW);
  analogWrite(r_motor, 0);
}

void backward() {
  digitalWrite(l_motor_in1, HIGH);
  digitalWrite(l_motor_in2, LOW);
  analogWrite(l_motor, 255);

  digitalWrite(r_motor_in3, HIGH);
  digitalWrite(r_motor_in4, LOW);
  analogWrite(r_motor, 255);
}

void CW() {
  digitalWrite(l_motor_in1, HIGH);
  digitalWrite(l_motor_in2, LOW);
  analogWrite(l_motor, 255);

  digitalWrite(r_motor_in3, LOW);
  digitalWrite(r_motor_in4, HIGH);
  analogWrite(r_motor, 255);
}

void CCW() {
  digitalWrite(l_motor_in1, LOW);
  digitalWrite(l_motor_in2, HIGH);
  analogWrite(l_motor, 255);

  digitalWrite(r_motor_in3, HIGH);
  digitalWrite(r_motor_in4, LOW);
  analogWrite(r_motor, 255);
}
