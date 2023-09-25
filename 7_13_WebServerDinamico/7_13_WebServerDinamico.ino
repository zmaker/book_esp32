/* 
Autore: Paolo Aliverti
Listato 7.13 – Semplice server web con pagina dinamica

Collegare un trimmer da 10k sul pin 34
*/
#include <WiFi.h>
#define MY_WIFI_SSID "nome_rete"
#define MY_WIFI_PASS "password"

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Simple Server");

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
    Serial.println("new req");
    String line = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        //Serial.print(c);  
        if (c == '\n') {
          if (line.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("");
            client.println("<html>");
            client.println("<head><title>ESP32</title>");
            client.println("<meta http-equiv=\"refresh\" content='2;url=http://");
            client.print(WiFi.localIP());
            client.print("/'>");            
            client.println("</head>");            
            client.println("<body>");
            client.println("<h1>ESP32</h1>");
            client.println("<p>ANALOG in:");
            int v = analogRead(34);
            client.println(v);
            client.println("</p>");
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

