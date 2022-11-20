void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int M;
  M = analogRead(A1);

  if (0 <= M & M <= 250) {
    digitalWrite(7, HIGH);
    //delay(500);
    //digitalWrite(9, LOW);
    //delay(500);
  }
  if (250 < M & M <= 500) {
    digitalWrite(8, HIGH);
    //delay(500);
    //d/igitalWrite(10, LOW);
    //delay(500);
  }
  if (500 < M & M <= 750)
    ;
  {
    digitalWrite(4, HIGH);
    //delay(500);
    //digitalWrite(11, LOW);
    //delay(500);
  }
  //
  //delay(80);
  //
  //delay(80);
}
