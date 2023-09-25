/* 
Autore: Paolo Aliverti
Listato 7.6 – Simple WiFi Client
*/
#include <WiFi.h>
#define MY_WIFI_SSID "nomerete"
#define MY_WIFI_PASS "password"

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

  delay(1000);

  WiFiClient client;
  if (!client.connect("www.zeppelinmaker.it", 80)) {
    Serial.println("non connesso");
    while(true);
  } else {
    
    client.println("GET /helloworld.txt HTTP/1.1");
    client.println("Host: www.zeppelinmaker.it");
    client.println("Connection: close");
    client.println("");

    unsigned long t1 = millis();
    while (client.available() == 0) {
      if ((millis() - t1) > 5000) {
         Serial.println("timeout");
         client.stop();
         while(true);
      }
    }
    
    //ricezione dati 
    while (client.available()) {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }
    
    client.stop(); 
  }
  WiFi.disconnect();
}

void loop() {}
