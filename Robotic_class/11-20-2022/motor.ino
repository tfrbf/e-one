//#define ENA 9
#define motor 9
#define mi1 1
#define mi2 3
void setup() {
  // put your setup code here, to run once:
  pinMode(motor, OUTPUT);
  pinMode(mi1, OUTPUT);
  pinMode(mi2, OUTPUT);
  pinMode(8, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  
Serial.print("Motor has started");
analogWrite(motor,255); //control motor speed
digitalWrite(mi1,LOW);  //control direction
digitalWrite(mi2,HIGH); //control direction
Serial.print("Motor has stopped");
delay(3000);

analogWrite(motor,0); //control motor speed
digitalWrite(mi1,LOW);  //control direction
digitalWrite(mi2,HIGH); //control direction
delay(2000);

Serial.print("Changing direction...")
analogWrite(motor,255); //control motor speed
digitalWrite(mi1,HIGH);  //control direction
digitalWrite(mi2,LOW); //control direction
delay(4000);


}
