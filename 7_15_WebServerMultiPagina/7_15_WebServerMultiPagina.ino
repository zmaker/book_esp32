/* 
Autore: Paolo Aliverti
Listato 7.15 – Server web multi pagina

Collegare un LED sul pin 25
*/
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WebServer.h>

//#define MY_WIFI_SSID "nome_rete"
//#define MY_WIFI_PASS "password"
#define MY_WIFI_SSID "www.zeppelinmaker.it"
#define MY_WIFI_PASS "*1000balene"

WebServer server(80);

void setup() {
  pinMode(25, OUTPUT);
  digitalWrite(25, LOW);
  
  Serial.begin(115200);
  delay(2000);
  Serial.println("Web Server");

  WiFi.begin(MY_WIFI_SSID, MY_WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.print("\n");
  
  if (MDNS.begin("myesp32")) {
    Serial.println("http://myesp32.local/");
  } else {
    Serial.println("Error DNS");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  }

  server.on("/", pageIndex);
  server.on("/home", pageIndex);
  server.on("/on", ledOn);
  server.on("/off", ledOff);
  server.onNotFound(pageError);

  server.begin();
}

void loop() {
  server.handleClient();
  delay(2);
}

void pageIndex() {
  String str = "Hello Web Server ESP32\n";
  str += "URI: ";
  str += server.uri();
  str += " ARGS: ";
  str += server.args();
  str += "\n";

  for (int i = 0; i < server.args(); i++) {
    str += server.argName(i);
    str += "=";
    str += server.arg(i);
    str += "\n";
  }
  
  server.send(200, "text/plain", str);  
}
void ledOn() {
  digitalWrite(25, HIGH);    
  server.send(200, "text/plain", "OK");  
}
void ledOff() {
  digitalWrite(25, LOW);  
  server.send(200, "text/plain", "OK");  
}

void pageError() {
  String str = "Pagina non trovata\n";  
  server.send(404, "text/plain", str);    
}
