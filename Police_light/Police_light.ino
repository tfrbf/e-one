//Variables 
float c = 12; //define coefficient to control i
int i = 50; // delay time
int count = 0; //counter to control program in mode2 & mode3

void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (i > 0) {
    mode_1();
    if (c * i <= 30)
      break;
  }
  
  int i = 50; //Restoring i

  while (i > 0) {
    mode_2();
    count += 1;
    if (count >= 10)
      break;
  }
  
  count = 0;
  
  while (i > 0) {
    mode_3();
    count += 1;
    if (count >= 10)
      break;
  }
}

//Functions
void mode_1() {
  digitalWrite(8, HIGH);
  delay(2 * i);
  digitalWrite(8, LOW);
  delay(2 * i);
  digitalWrite(8, HIGH);
  delay(2 * i);
  digitalWrite(8, LOW);

  delay(c * i);

  digitalWrite(10, HIGH);
  delay(2 * i);
  digitalWrite(10, LOW);
  delay(2 * i);
  digitalWrite(10, HIGH);
  delay(2 * i);
  digitalWrite(10, LOW);
  c -= 0.6;
}

void mode_2() {
  digitalWrite(8, HIGH);
  delay(1.5 * i);
  digitalWrite(8, LOW);
  delay(i);

  digitalWrite(10, HIGH);
  delay(1.5 * i);
  digitalWrite(10, LOW);
  delay(i);
}

void mode_3() {
  digitalWrite(8, HIGH);
  delay(13*i);
  digitalWrite(8, LOW);
  delay(i);


  digitalWrite(10, HIGH);
  delay(13*i);
  digitalWrite(10, LOW);
  delay(i);
}
