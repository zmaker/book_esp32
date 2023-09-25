/* 
Autore: Paolo Aliverti
Listato 7.5 – Eventi WiFi
*/
#include <WiFi.h>

void onConnect(WiFiEvent_t e, WiFiEventInfo_t einfo){
  Serial.println("connesso");
}

void onIP(WiFiEvent_t e, WiFiEventInfo_t einfo){
  Serial.print("ip:");
  Serial.println(einfo.got_ip.ip_info.ip.addr);
}

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("WiFi test");

  WiFi.disconnect(true);

  WiFi.onEvent(onConnect, WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_CONNECTED);
  WiFi.onEvent(onIP, WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_GOT_IP);

  WiFi.mode(WIFI_STA);

  WiFi.begin("nome rete wifi", "password");  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");    
    delay(1000);    
  }

  Serial.print("\n");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  WiFi.removeEvent(WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_CONNECTED);

}

void loop() {
  
}

