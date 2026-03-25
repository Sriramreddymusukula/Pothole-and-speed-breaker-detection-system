#include<BluetoothSerial.h>
BluetoothSerial bt;
String data=" ";

#define trig 18
#define echo 19
long distance,duration;

#define buzzer 5

#define m1 33
#define m2 32
#define m3 25
#define m4 26

void setup() 
{
  Serial.begin(9600);
  bt.begin("PATH HOLE DETECTION ROBOT");

  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);

  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

  pinMode(buzzer,OUTPUT);
  digitalWrite(buzzer,LOW);

  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);

  digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
}
void loop()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance=duration*0.0342/2;
  Serial.print("DISTANCE : ");Serial.println(distance);
  bt.print("DISTANCE : ");bt.print(distance);bt.println("   ");
  delay(100);

  if(distance >= 1195 && distance <= 1205)
  {
    digitalWrite(buzzer,LOW);
  }
  else
  {
    digitalWrite(buzzer,HIGH);
  }
  
  if(bt.available()>0)
  {
    data=" ";
    data=bt.readString();
    Serial.print("data : ");Serial.println(data);
  }

  if(data=="FORWARD" || data=="Forward" || data=="forward")
  {
    forward();
  }
  else if(data=="BACKWARD" || data=="Backward" || data=="backward")
  {
    backward();
  }
  else if(data=="LEFT" || data=="Left" || data=="left")
  {
    left();
  }
  else if(data=="RIGHT" || data=="Right" || data=="right")
  {
    right();
  }
  else if(data=="STOP" || data=="Stop" || data=="stop")
  {
    stop();
  }
  
  digitalWrite(2,HIGH);delay(100);digitalWrite(2,LOW);delay(100);
}
void forward()
{
  digitalWrite(m1,HIGH);
  digitalWrite(m2,LOW);
  digitalWrite(m3,HIGH);
  digitalWrite(m4,LOW);
}
void backward()
{
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,HIGH);
}
void right()
{
  digitalWrite(m1,HIGH);
  digitalWrite(m2,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
}
void left()
{
  digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
  digitalWrite(m3,HIGH);
  digitalWrite(m4,LOW);
}
void stop()
{
  digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
}
