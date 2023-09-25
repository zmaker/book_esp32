/* 
Autore: Paolo Aliverti
Listato 7.7 – HTTP Get
*/
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
      HTTPClient http;

      String addr = "https://httpbin.org/get?temp=23.4&hum=45&colr=red&";      
      http.begin(addr.c_str());
      //http.setAuthorization("SERVER_LOGIN", "SERVER_PASSWORD");
            
      int code = http.GET();
      Serial.println(code);
              
      if (code == 200) {
        String risposta = http.getString();
        Serial.println(risposta);
      } else {
        Serial.print("Errore HTTP: ");
        Serial.println(code);
      }      
      http.end();
    }
    t1 = millis();
  }
}
