#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266WebServerSecure.h>
#include<DHTesp.h>

DHTesp dht;
#define dht_apin D0
float Temperature;
float Humidity;

ESP8266WebServer server(80);

/*Put your SSID & Password*/
const char* ssid = "Adarsh";  // Enter SSID here
const char* password = "adarshjk";  //Enter Password here

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.setup(dht_apin, DHTesp::DHT11);
  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");


}

void loop() {
  // put your main code here, to run repeatedly:
server.handleClient();
Serial.println(dht.getTemperature());
Serial.println(dht.getHumidity());
delay(1000);
}
void handle_OnConnect() {

 Temperature = dht.getTemperature(); // Gets the values of the temperature
  Humidity = dht.getHumidity(); // Gets the values of the humidity
  server.send(200, "text/html", SendHTML(Temperature,Humidity));
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}
String SendHTML(float Temperaturestat,float Humiditystat){
  String ptr = "<!DOCTYPE html> <html>\n";
  
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<meta http-equiv=\"refresh\" content=\"1\">\n";
  ptr +="<title>ESP8266 Weather Report</title>\n";

  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;}\n";
  ptr +="p {font-size: 24px;color: #444444;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<div id=\"webpage\">\n";
  ptr +="<h1> <font  color= #002A5C font-family=Monotype Corsiva size=35px padding= 4%,0%,1%,0% width=100%><u>ESP8266 NodeMCU Weather Report</u></h1>\n";
 
  ptr +="<p><font color=red face=Calibri> Temperature: </font> ";
  ptr +=(int)Temperaturestat;
  ptr +="°C</p>";
  ptr +="<p><font color=red face=Calibri>Humidity:</font> ";
  ptr +=(int)Humiditystat;
  ptr +="%</p>";
 
  ptr +="</div>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
