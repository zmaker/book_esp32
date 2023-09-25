/* 
Autore: Paolo Aliverti
Listato 7.18 – Server Web con Access Point
*/

#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

IPAddress local_ip(192,168,1,20);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("AP Server");

  WiFi.mode(WIFI_AP);
  WiFi.softAP("esp32wifi", "123Stella");
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(1000);

  server.on("/", pageIndex);
  server.onNotFound(pageError);

  server.begin();
}

void loop() {
  server.handleClient();
  delay(2);
}

void pageIndex() {
  String str = "Hello Web Server ESP32\n";  
  server.send(200, "text/plain", str);  
}

void pageError() {
  String str = "Pagina non trovata\n";  
  server.send(404, "text/plain", str);    
}
