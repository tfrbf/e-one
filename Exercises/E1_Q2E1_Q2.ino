void LED(int frequency);  //define function to turn on LES with different frequency

void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(750);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potentiometerValue = analogRead(A1);  // Read analog value of potentiometer

  Serial.print(potentiometerValue);  //optional
  Serial.print("\n");                //optional

  int frequency = map(potentiometerValue, 0, 1023, 80, 800);  //change value range from (0,1023) to (80,800)

  LED(frequency);
}

void LED(int frequency) {
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  delay(frequency);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(frequency);
}
