/* 
Autore: Paolo Aliverti
Listato 6.20 – EEPROM

Led su pin 25 
button con pull down su pin 23
*/

#include <EEPROM.h>

#define EEPROM_SIZE 10

int stato_led;
int bt, pv_bt;
u_int8_t val = 0;

void setup() {  
  Serial.begin(115200);
  EEPROM.begin(EEPROM_SIZE);

  pinMode(23, INPUT);
  pinMode(25, OUTPUT);

  stato_led = EEPROM.read(0);
  digitalWrite(25, stato_led);
}

void loop() {
  bt = digitalRead(23);
  
  if (pv_bt && !bt) { //FDD
    Serial.println("BT");
    stato_led = !stato_led;
    digitalWrite(25, stato_led); 
    EEPROM.write(0, stato_led);
    EEPROM.commit(); 
  }  
  pv_bt = bt;
}
