int SensorPin = A0;  
int LED1 = D2; 
int SensorValue = 0;  
void setup(){
Serial.begin(9600); 
pinMode(LED1,OUTPUT); }
void loop() {
SensorValue = analogRead(SensorPin);
Serial.println(SensorValue);
delay(100);
if(SensorValue<800){
    digitalWrite(LED1,LOW);
}
else{
digitalWrite(LED1,HIGH); }
}
