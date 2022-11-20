void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int M = analogRead(A1);
  if(M >= 850) {
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);
    delay(500);
  }
  //digitalWrite(7, HIGH);
  //delay(80);
  //digitalWrite(7, LOW);
  //delay(80);
}
