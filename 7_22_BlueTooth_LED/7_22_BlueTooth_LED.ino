/* 
Autore: Paolo Aliverti
Listato 7.20 – Controllo LED via BlueTooth 

Collegare un LED sul pin 25 con Resistenza da 100 ohm
*/
#include "BluetoothSerial.h"

BluetoothSerial bt;
String line = "";

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("BT LED");
  bt.begin("ESP32-Bt");

  pinMode(25, OUTPUT);
  digitalWrite(25, LOW);
}

void loop() {
  if (bt.available()) {
    char ch = bt.read();
    if (ch == '\n') {
      Serial.print("cmd: ");
      Serial.println(line);
      if (line == "on"){
        digitalWrite(25, HIGH);
        Serial.println("LED ON");  
      } else if (line == "off"){
        digitalWrite(25, LOW);  
        Serial.println("LED OFF");  
      }
      line = "";  
    } else if (ch != '\r') {
      line += ch;
    } 
  }
}
