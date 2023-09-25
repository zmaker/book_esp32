/* 
Autore: Paolo Aliverti
Listato 7.1 – Semplice connessione WiFi
*/

#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Simple WiFi Connection");

  WiFi.begin("reelco_2_4", "cardu450IX");
  Serial.println("mi connetto...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nconnesso");
  
  Serial.print("IP: "); Serial.println(WiFi.localIP());
  Serial.print("Segnale (RRSI): "); Serial.println(WiFi.RSSI());
  
  delay(5000);

  //mi scollego
  WiFi.disconnect();
  Serial.println("disconnesso");
}

void loop() {}
