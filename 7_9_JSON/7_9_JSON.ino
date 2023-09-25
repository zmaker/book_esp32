/* 
Autore: Paolo Aliverti
Listato 7.9 – Generazione JSON
*/
#include <ArduinoJson.h>

void setup() {
  Serial.begin(115200);
  
  DynamicJsonDocument doc(1024);
  JsonObject sensor  = doc.createNestedObject("sensor");
  sensor["temp"] = 24.8;
  sensor["hum"] = 40;
  sensor["color"] = "red";

  JsonArray coords = sensor.createNestedArray("coords");
  coords.add(45.12340);
  coords.add(7.34456);

  serializeJson(doc, Serial);
  Serial.println();

  serializeJsonPretty(doc, Serial);  
  Serial.println();

  String output;
  serializeJson(doc, output);
  Serial.println(output);
}

void loop() {}



