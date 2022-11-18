void setup()
{
  pinMode(10, OUTPUT);
  pinMode(A1,INPUT);
  Serial.begin(1200); //define bound rate
}

void loop()
{
  int potentiometerValue = analogRead(A1);
  int brightness = potentiometerValue / 4; //1024 is 255 multiplied by 4 
  analogWrite(10, brightness); 
  Serial.print(potentiometerValue/10); //Convert brightness to percentage 
  Serial.print("\n");
}