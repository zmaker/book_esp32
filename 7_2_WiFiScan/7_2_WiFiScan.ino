/* 
Autore: Paolo Aliverti
Listato 7.2 – Scan delle reti WiFi
*/
#include "WiFi.h"

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);  
}

void loop() {
  int reti_trovate = WiFi.scanNetworks();
  if (reti_trovate == 0) {
      Serial.println("nessuna rete disponibile");
  } else {
    Serial.printf("trovate %d reti\n", reti_trovate);
    for (int i = 0; i < reti_trovate; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(WiFi.SSID(i));
      Serial.print(" p: ");
      Serial.print(WiFi.RSSI(i));
      Serial.println("[dB] ");
      delay(10);
    }
  }
  delay(5000);
}
