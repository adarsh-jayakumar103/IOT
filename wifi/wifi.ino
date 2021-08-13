#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>

#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>
#include<DHTesp.h>
#define FIREBASE_HOST "hidden-cosmos-245914.firebaseio.com"
#define FIREBASE_AUTH "1GjFDiNgdGWERd0aHIDMBDjiILWJNQGlKzpLEFYa"
#define WIFI_SSID "Adarsh"
#define WIFI_PASSWORD "adarshjk"
#define dht_apin A0
DHTesp dht;

void setup()
{
Serial.begin(9600);
// connect to wifi.
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED)
{
Serial.print(".");
delay(500);
}
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST);
dht.setup(dht_apin, DHTesp::DHT11);
}

void loop() {
 float h= dht.getHumidity();
float t= dht.getTemperature();

Firebase.setFloat("temp",t);


}
