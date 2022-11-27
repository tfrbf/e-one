/*
1401 - 09 - 06
Setting up ULTRA SONIC

*/

#include "SRF05.h"
#define trigger 12
#define echo 13

SRF05 SRF(trigger, rcho);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SRF.setCorrectionFactor(1.035);
}

void loop() {
  // put your main code here, to run repeatedly:
  float Distance = 0;
  float Distance_mil = 0;
  Serial.print("Distance (Centi)= \n");
  Distance = SRF.getCentimeter();
  Serial.print(Distance);
  //Serial.print("Centimeters "\n);
  Serial.print("Distance (mili) =");
  Distance_mil = SRF.getmilimeter();
  Serial.print(Distance_mil);
  Serial.print("\n");

  delay(500);
}

//Functions