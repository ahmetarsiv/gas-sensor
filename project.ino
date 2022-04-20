#include <Servo.h>
int led=2;
int buzzer=3;
Servo servo;  

void setup()
{
Serial.begin(9600); // serial ekran açma
  servo.attach(9);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);  
}

void loop()
{
  int val;//tam sayı değişken 
  val=analogRead(0);//sensörden okunan değeri değişkene 
  Serial.println(val,DEC);//serial ekrana değeri yazdırma  
  if(val<500)
  {
  Serial.println("DUMAN YOK");
  digitalWrite(led,LOW);
  digitalWrite(buzzer,LOW); 
  servo.write(0);
  }
  if(val>700)
  {
  Serial.println("DUMAN VAR");
  digitalWrite(led,HIGH);
  digitalWrite(buzzer,HIGH); 
  servo.write(90);
  }   
delay(100);
}
