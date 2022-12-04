/*
1401 - 09 - 01
Building first srtucture
*/

#include "SRF05.h"
#define trigger 12
#define echo 13

SRF05 SRF(trigger, echo);
int LED;

//Define part
#define l_motor 9  //ENA
#define l_motor_in1 7
#define l_motor_in2 6
#define r_motor 3  //ENB
#define r_motor_in3 4
#define r_motor_in4 5
#define R_light 10
#define L_light 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  pinMode(A1, INPUT);
  SRF.setCorrectionFactor(1.035);

  int LED;
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

  if (Direction == 1) {
    CW();
    blink(R_light);
  }

  if (Direction == 2) {
    CCW();
    blink(L_light);
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



void blink(int LED) {
  while (1) {
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  }
}
