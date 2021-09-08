#include <Servo.h>
#define trigPin 5
#define echoPin 6
Servo servo;
int sound = 250;
char t;
void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
servo.attach(7);
pinMode(9,OUTPUT);   

pinMode(10,OUTPUT);   

pinMode(11,OUTPUT);   

pinMode(12,OUTPUT); 
pinMode(13,OUTPUT); 
pinMode(4,OUTPUT); 
}
void loop(){
  s();
  m();
}
void s() {
 
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance < 10)
{
Serial.println("the distance is less than 10");
servo.write(90);
delay(1500);
}
else {
servo.write(0);
}
if (distance > 60 || distance <= 0){
Serial.println("The distance is more than 60");
}
else {
Serial.print(distance);
Serial.println(" cm");
}
delay(100);

}
void m() {
   digitalWrite(4, HIGH);
   
  digitalWrite(13,HIGH);
  
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
if(t == '1'){
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
}
else if(t == '2'){
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);}
  else if(t == '3'){
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
}
else if(t == '4'){
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
}
else if(t == '5'){
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
}

delay(50);

}
