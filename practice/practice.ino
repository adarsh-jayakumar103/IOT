#include<DHTesp.h>
int LED1=D1;
int LED2=D2;
#define dht_apin D0
DHTesp dht;

void setup()
{
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  Serial.begin(9600);
  delay(500);
  Serial.print("DHT11 Humidity and Temperature Sensor");
  delay(500);
  dht.setup(dht_apin,DHTesp::DHT11);
}
void loop()
{
  float hum=dht.getHumidity();
  float temp=dht.getTemperature();
  Serial.print("Current Humidity= ");
  Serial.print(hum);
  Serial.print("%");
  Serial.print("Current Temperature= ");
  Serial.print(temp);
  Serial.print(" C");
  delay(1000);
  
}
