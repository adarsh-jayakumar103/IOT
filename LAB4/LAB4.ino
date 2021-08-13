int sensor=A0;
int red=D2;
int green=D1;
int blue=D0;
void setup() {
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(sensor,INPUT);

}

void loop() {
  float val = analogRead(sensor);
  float mv = ( val/1024.0)*3000; 
  float cel = mv/10;
  float farh = (cel*9)/5 + 32;
  
  Serial.println(cel);
  if (farh>34.0)
  {
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,HIGH);   
  }
  if (farh<34.0)
  {
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(blue,HIGH);    
  }
  delay(1000);

}
