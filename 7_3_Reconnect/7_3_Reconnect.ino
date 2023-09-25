/* 
Autore: Paolo Aliverti
Listato 7.3 – Gestione disconnect
*/
#include <WiFi.h>
#define MY_WIFI_SSID "www.zeppelinmaker.it"
#define MY_WIFI_PASS "*1000balene"

unsigned long t1;

void setup() {
  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);

  WiFi.begin(MY_WIFI_SSID, MY_WIFI_PASS);  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");    
    delay(1000);    
  }

  Serial.print("\n");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  t1 = millis();
}

void loop() {
  if ((millis() - t1) > 10000){ 
    Serial.println("test rete?");
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("Mi riconnetto...");    
      WiFi.disconnect();
      WiFi.reconnect();
      delay(3000);    
    }
    t1 = millis();
  }
  
}
