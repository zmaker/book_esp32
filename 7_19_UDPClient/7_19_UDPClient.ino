/* 
Autore: Paolo Aliverti
Listato 7.x – UDP Client
*/

#include <WiFi.h>
#include <WiFiUdp.h>

WiFiUDP udp;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("UDP Client");

  WiFi.begin("reelco_2_4", "cardu450IX");
  Serial.println("mi connetto...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nconnesso");
  
  Serial.print("IP: "); Serial.println(WiFi.localIP());
  
  delay(1000);

  udp.begin(1234);  
}

void loop() {
  uint8_t buffer[50] = "hello UDP!";
  udp.beginPacket("192.168.1.111", 1234);
  udp.write(buffer, 10);
  udp.endPacket();
  
  delay(1000);
}
