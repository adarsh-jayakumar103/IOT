int sensorPin=D0;
int LED=D0;
int sensorValue=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorValue=digitalRead(sensorPin);
Serial.println(sensorValue);
if(sensorValue>200)
{ 
    digitalWrite(LED,HIGH); 
}
else{
  digitalWrite(LED,LOW); 
}
}
