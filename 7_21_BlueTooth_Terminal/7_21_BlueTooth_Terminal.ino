/* 
Autore: Paolo Aliverti
Listato 7.19 – BlueTooth Terminal
*/
#include "BluetoothSerial.h"

BluetoothSerial bt;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("BT terminal");

  bt.begin("ESP32-Bt");

}

void loop() {
  if (Serial.available()) {
    bt.write(Serial.read());
  }
  if (bt.available()) {
    Serial.write(bt.read());
  }
  delay(20);
}
