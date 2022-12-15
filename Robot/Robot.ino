//Include part
#include "string.h"
#include "SRF05.h"

//Global Variebels
int LED;
int Speed;
bool Status;
String Direction;
int distance;
int led_rate;
char blth;


//Define part
#define led 2
#define alarm
#define trigger 12
#define echo 13
#define l_motor 9  //ENA
#define l_motor_in1 7
#define l_motor_in2 6
#define r_motor 3  //ENB
#define r_motor_in3 4
#define r_motor_in4 5
#define lights 10
#define back_lights 11

//Import libraries
SRF05 SRF(trigger, echo);


void setup() {
  // put your setup code here, to run once:
  SRF.setCorrectionFactor(1.035);
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(led, OUTPUT);
  pinMode(A5, INPUT);
  int Speed;
}


void loop() {

  while (Serial.available() > 0) {
    blth = Serial.read();  //checking the bluetooth module status
    Serial.println(blth);

    if (blth == 'F')
      forward();

    if (blth == 'B')
      backward();

    if (blth == 'L')
      CW();

    if (blth == 'R')
      CCW();
  }
  // distance = SRF.getCentimeter();
  // Direction = random(1, 3);
  // Serial.print(Direction);
}


//Functions
void forward() {
  /*distance = SRF.getCentimeter();
  led_rate = map(distance, 0, 2000, 80, 4000);
  Blink();
  Status = true;
  Direction = "Forward";
  speed_control();*/
  digitalWrite(l_motor_in1, LOW);
  digitalWrite(l_motor_in2, HIGH);
  analogWrite(l_motor, Speed);

  digitalWrite(r_motor_in3, LOW);
  digitalWrite(r_motor_in4, HIGH);
  analogWrite(r_motor, Speed);
}

void Stop() {
 /* distance = SRF.getCentimeter();
  led_rate = map(distance, 0, 2000, 80, 4000);
  Blink();
  Status = false;
  Direction = "Stop";
  speed_control();*/
  digitalWrite(l_motor_in1, HIGH);
  digitalWrite(l_motor_in2, LOW);
  analogWrite(l_motor, 0);

  digitalWrite(r_motor_in3, HIGH);
  digitalWrite(r_motor_in4, LOW);
  analogWrite(r_motor, 0);
}

void backward() {
  /*distance = SRF.getCentimeter();
  Serial.print("/t/t distance:");
  Serial.print(distance);
  led_rate = map(distance, 0, 2000, 80, 1500);
  Blink();
  Status = true;
  Direction = "Backward";
  speed_control();*/
  digitalWrite(l_motor_in1, HIGH);
  digitalWrite(l_motor_in2, LOW);
  analogWrite(l_motor, Speed);

  digitalWrite(r_motor_in3, HIGH);
  digitalWrite(r_motor_in4, LOW);
  analogWrite(r_motor, Speed);
}

void CW() {
  digitalWrite(l_motor_in1, HIGH);
  digitalWrite(l_motor_in2, LOW);
  analogWrite(l_motor, Speed);

  digitalWrite(r_motor_in3, LOW);
  digitalWrite(r_motor_in4, HIGH);
  analogWrite(r_motor, Speed);
}

void CCW() {
  digitalWrite(l_motor_in1, LOW);
  digitalWrite(l_motor_in2, HIGH);
  analogWrite(l_motor, Speed);

  digitalWrite(r_motor_in3, HIGH);
  digitalWrite(r_motor_in4, LOW);
  analogWrite(r_motor, Speed);
}

void speed_control() {

  if (Status) {
    while (Speed < 250) {
      Speed += 10;
      Serial.print(Direction);
      Serial.print("\t Speed: ");
      Serial.println(Speed);
      delay(200);
    }

    Speed = 255;
    Serial.print("\t Speed: ");
    Serial.println(Speed);
    delay(200);
  }
  if (!Status) {
    for (Speed; Speed >= 0; Speed -= 10) {
      Serial.print(Direction);
      Serial.print("\t Speed: ");
      Serial.println(Speed);
      delay(250);
    }

    Speed = 0;
    Serial.print("\t Speed: ");
    Serial.println(Speed);
    delay(250);
  }
}

/*void Blink() {

  Serial.print(distance);
  digitalWrite(2, HIGH);
  delay(led_rate);
  digitalWrite(2, LOW);
  delay(led_rate);
}*/

/*void Smoke() {
  int thres=250;
  smoke = analogread(alarm, A5);
  Serial.print("Gas level: ");
  Serial.println(smoke);
  Serial.print("\n");
  if (smoke > thres) {
    digitalwrite(led, HIGH);
    led_status = true;
  } else {
    digitalWrite(led, LOW);
    led_status = false;
  }

  if (led_status)
    Serial.print("\t LED : On");
  else
    Serial.print("\t LED : OFF");
}*/
