#include <DHTesp.h>
int LED1=D5;
int LED2=D6;
int LED3=D7;
#define dht_apin D0
DHTesp dht;
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
Serial.begin(9600);
delay(500);
Serial.println("DHT11 Humidity and Temperature Sensor");
delay(1000);
dht.setup(dht_apin, DHTesp::DHT11);
}
void loop()
{
float hum=dht.getHumidity();
float temp=dht.getTemperature();
Serial.print("Current Humidity = ");
Serial.print(hum);
Serial.println("%");
Serial.print("Current Temperature = ");
Serial.print(temp);
Serial.println(" C");
if(temp>27)
{
  for(int i=0;i<3;i++){
  digitalWrite(LED1,HIGH);
  delay(100);
  digitalWrite(LED1,LOW);}
}
if(temp<=27)
{
  for(int i=0;i<3;i++){
  digitalWrite(LED2,HIGH);
  delay(100);
  digitalWrite(LED2,LOW);}
}
 if(hum>60)
{
  for(int i=0;i<3;i++){
  digitalWrite(LED3,HIGH);
  delay(1000);
  digitalWrite(LED3,LOW);}
}
Serial.println();
delay(1000);
}
