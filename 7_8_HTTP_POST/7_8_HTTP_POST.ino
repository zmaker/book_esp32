/* 
Autore: Paolo Aliverti
Listato 7.8 – HTTP POST
*/
#include <WiFi.h>
#define MY_WIFI_SSID "nome_wifi"
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
    
      String addr = "http://yourserver.address/post";  
      http.begin(client, addr);
      //http.setAuthorization("SERVER_LOGIN", "SERVER_PASSWORD");
      
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      String dati = "temp=23.4&hum=45&colr=red";                 
      int code = http.POST(dati);
      Serial.println(code);
                    
      http.end();
    }
    t1 = millis();
  }
}



