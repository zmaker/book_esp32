/* 
Autore: Paolo Aliverti
Listato 6.12 – Internal RTC

Libreria: ESP32Time by fbiego
*/

#include <ESP32Time.h>

ESP32Time rtc(3600*2);  // GMT+2 (Roma) 
 
void setup() {
  Serial.begin(115200);
  rtc.setTime(00, 30, 16, 30, 8, 2023);  // 16:30:00 del 30/08/2023
}

void loop() {
  Serial.println(rtc.getTime("%F %H:%M:%S"));
  delay(1000);
}
