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
delay(1000);
Serial.println("DHT11 Humidity and Temperature Sensor");
delay(1000);
dht.setup(dht_apin, DHTesp::DHT11);
}
void loop()
{
float hum=dht.getHumidity();
float temp=dht.getTemperature();
delay(1000);
Serial.print("Current Humidity = ");
Serial.print(hum);
Serial.println("%");
if(temp>26)
{
  digitalWrite(LED1,HIGH);
Serial.print("Current Temperature = ");
Serial.print(temp);
Serial.println(" C");}
else if(temp<=26)
{
 digitalWrite(LED2,HIGH); 
}
if(hum>65)
{
  digitalWrite(LED3,HIGH);
}
 delay(1000);
 digitalWrite(LED1,LOW);
 digitalWrite(LED2,LOW);
 digitalWrite(LED3,LOW);
 

}
