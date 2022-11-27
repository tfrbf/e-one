/*
1401 - 09 - 06
Setting up ULTRA SONIC

*/

#include "SRF05.h"
#define trigger 12
#define echo 13

SRF05 SRF(trigger, echo);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SRF.setCorrectionFactor(1.035);
}

void loop() {
  // put your main code here, to run repeatedly:
  float Distance;
  float Distance_mil;

  Serial.print("Distance (Centi) =");
  Distance = SRF.getCentimeter();
  Serial.print(Distance);
  Serial.print("\n");
  //Serial.print("Centimeters "\n);
  Serial.print("Distance (mili) =");
  Distance_mil = SRF.getMillimeter();
  Serial.print(Distance_mil);
  Serial.print("\n");

  delay(800);
}

//Functions
