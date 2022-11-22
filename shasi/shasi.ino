/*
1401 - 09 - 01
Building first srtucture
*/

//Define part
#define l_motor 9 //ENA
#define l_motor_in1 7
#define l_motor_in2 6
#define r_motor 3 //ENB
#define r_motor_in3 4
#define r_motor_in4 5

int p,pot;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int p,pot;
  
pinMode(A1,INPUT);


  
}

void loop() {
  // put your main code here, to run repeatedly:
  int p;
  int pot;
p = analogRead(A1);
pot = map(p,0,1023,0,255);
  CCW();
  
}


//Functions
void move_forward(){
  digitalWrite(l_motor_in1, HIGH);
  digitalWrite(l_motor_in2, LOW);
  analogWrite(l_motor,pot);

  digitalWrite(r_motor_in3, HIGH);
  digitalWrite(r_motor_in4, LOW);
  analogWrite(r_motor, pot);
  
}

void stop(){
  digitalWrite(l_motor_in1, HIGH);
  digitalWrite(l_motor_in2, LOW);
  analogWrite(l_motor,0);

  digitalWrite(r_motor_in3, HIGH);
  digitalWrite(r_motor_in4, LOW);
  analogWrite(r_motor, 0);
  
}

void move_backward(){
  digitalWrite(l_motor_in1, LOW);
  digitalWrite(l_motor_in2, HIGH);
  analogWrite(l_motor,255);

  digitalWrite(r_motor_in3, LOW);
  digitalWrite(r_motor_in4, HIGH);
  analogWrite(r_motor, 255);
}

void CW(){
  digitalWrite(l_motor_in1, HIGH);
  digitalWrite(l_motor_in2, LOW);
  analogWrite(l_motor,255);

  digitalWrite(r_motor_in3, LOW);
  digitalWrite(r_motor_in4, HIGH);
  analogWrite(r_motor, 255);
  
}

void CCW(){
  digitalWrite(l_motor_in1, LOW);
  digitalWrite(l_motor_in2, HIGH);
  analogWrite(l_motor,255);

  digitalWrite(r_motor_in3, HIGH);
  digitalWrite(r_motor_in4, LOW);
  analogWrite(r_motor, 255);
}