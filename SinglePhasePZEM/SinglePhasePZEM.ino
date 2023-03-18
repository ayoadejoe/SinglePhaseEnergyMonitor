#include <Arduino.h>
#include <PZEM004Tv30.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;

const char* ssid     ="Nokia 2.4";
const char* password = "jojo1234";

PZEM004Tv30 pzem(D1, D2); // (RX,TX)connect to TX,RX of PZEM

void setup() {

  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");
  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
    delay(250);
  }
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.println("Connected to Network/SSID");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP

}

void loop() {
  // wait for WiFi connection
  //main energy meter
  float voltage = pzem.voltage();
  float current = pzem.current();
  float power = pzem.power();
  float energy = pzem.energy();
  float frequency = pzem.frequency();
  float pf = pzem.pf(); 
  Serial.print("voltage:");
  Serial.println(voltage);

  Serial.print("current:");
  Serial.println(current);

  Serial.print("power:");
  Serial.println(power);

  Serial.print("energy:");
  Serial.println(energy);

  Serial.print("frequency:");
  Serial.println(frequency);
  
  Serial.print("power factor:");
  Serial.println(pf);
  
  Serial.println("_____________"); 
   
  delay(4000);
}
