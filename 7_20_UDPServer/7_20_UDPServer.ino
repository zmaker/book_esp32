/* 
Autore: Paolo Aliverti
Listato 7.x – UDP Client
*/

#include <WiFi.h>
#include <WiFiUdp.h>

IPAddress ip_scheda(192, 168, 1, 111);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 0, 0);
IPAddress DNS1(8, 8, 8, 8);
IPAddress DNS2(8, 8, 4, 4);

WiFiUDP udp;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("UDP Server");

  WiFi.config(ip_scheda, gateway, subnet, DNS1, DNS2);

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

uint8_t buffer[50];
void loop() {
  udp.parsePacket();
  if(udp.read(buffer, 50) > 0){
    Serial.print("UDP: ");
    Serial.println((char *)buffer);
  }
  memset(buffer, 0, 50);
}
