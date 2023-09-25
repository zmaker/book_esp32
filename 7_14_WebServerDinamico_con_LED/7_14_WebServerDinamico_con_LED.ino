/* 
Autore: Paolo Aliverti
Listato 7.14 – Semplice server web con pagina dinamica per accendere un LED

Collegare un LED sul pin 25
*/
#include <WiFi.h>
#define MY_WIFI_SSID "nome_rete"
#define MY_WIFI_PASS "password"

WiFiServer server(80);

void setup() {
  pinMode(25, OUTPUT);
  
  Serial.begin(115200);
  delay(2000);
  Serial.println("HTTP LED");

  WiFi.disconnect(true);  
  WiFi.mode(WIFI_STA);
  WiFi.begin(MY_WIFI_SSID, MY_WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\n");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {    
    String line = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        //Serial.print(c);  
        if (c == '\n') {

          if (line.indexOf("GET /ledon") >= 0) {
            digitalWrite(25, HIGH);  
          }
          if (line.indexOf("GET /ledoff") >= 0) {
            digitalWrite(25, LOW);  
          }
          
          if (line.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("");
            client.println("<html>");
            client.println("<head><title>Hello LED ESP32</title>");
            client.println("</head>");            
            client.println("<body>");
            client.println("<h1>Hello ESP32</h1>");
            client.println("<p>Stato LED:");            
            client.println(digitalRead(25));
            client.println("</p>");
            if (digitalRead(25)) {              
              client.print("<a href='http://");
              client.print(WiFi.localIP());
              client.println("/ledoff'>OFF</a>");
            } else {              
              client.print("<a href='http://");
              client.print(WiFi.localIP());
              client.println("/ledon'>ON</a>");
            }            
            client.println("</body>");
            client.println("</body>");
            client.println("</html>");
            break;
          }
          line = "";
          
        } else if (c != '\r') {          
          line += c;
        }
        
      }
    }
    client.stop();
    Serial.println("client scollegato");
  }
}

