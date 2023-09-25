/* 
Autore: Paolo Aliverti
Listato 7.10 – JSON Parser
*/
#include <ArduinoJson.h>
#include <WiFi.h>
#define MY_WIFI_SSID "nome_rete"
#define MY_WIFI_PASS "password"

#include <HTTPClient.h>

unsigned long t1;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Simple WiFi Client");

  WiFi.begin(MY_WIFI_SSID, MY_WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nconnesso");
  Serial.print("IP: ");Serial.println(WiFi.localIP());

  t1 = millis();
}

void loop() {
  if ((millis() - t1) > 10000) {
    if (WiFi.status()== WL_CONNECTED) {
      WiFiClient client;
      HTTPClient http;

      String addr = "http://api.openweathermap.org/data/2.5/weather?q=Milan,IT&APPID=0c0514a00000000000000008da321";      
      
      http.begin(client, addr);
      int code = http.GET();
      String json = "{}"; 
  
      Serial.print("HTTP Response code: ");
      Serial.println(code);

      if (code > 0) {        
        json = http.getString();
        Serial.println(json);
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, json);
        JsonObject obj = doc.as<JsonObject>();

        double t = (double)obj["main"]["temp"];  
        Serial.print("Temperature: ");
        Serial.println((t - 273.15));

      }
  
      http.end();
    }
    t1 = millis();
  }
}
