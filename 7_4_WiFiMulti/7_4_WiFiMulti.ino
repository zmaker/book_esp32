/* 
Autore: Paolo Aliverti
Listato 7.4 – WiFiMulti
*/
#include <WiFi.h>
#include <WiFiMulti.h>

WiFiMulti wifimulti;

#define WIFI1_SSID "nome_rete_principale"
#define WIFI1_PASS "password_principale"
#define WIFI2_SSID "nome_rete_secondaria"
#define WIFI2_PASS "password_secondaria"
#define WIFI3_SSID "nome_rete_3"
#define WIFI3_PASS "password_3"

unsigned long t1;

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("WiFi Multi test");
  
  wifimulti.addAP(WIFI1_SSID, WIFI1_PASS);
  wifimulti.addAP(WIFI2_SSID, WIFI2_PASS);
  wifimulti.addAP(WIFI3_SSID, WIFI3_PASS);

  WiFi.mode(WIFI_STA);

  while (wifimulti.run() != WL_CONNECTED) {
    Serial.print(".");    
    delay(1000);    
  }

  Serial.print("\n");
  Serial.print("connesso con IP: ");
  Serial.println(WiFi.localIP());

  t1 = millis();
}

void loop() {
  if ((millis()-t1) > 5000) {
    Serial.println("verifico connessione...");  
    while (wifimulti.run() != WL_CONNECTED) {
      Serial.print(".");    
      delay(1000);    
    }
    
    t1 = millis();
  }

}
