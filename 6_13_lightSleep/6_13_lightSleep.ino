/* 
Autore: Paolo Aliverti
Listato 6.13 – light sleep
*/

const uint32_t SLEEP_DURATION = 4 * 1000000; // 4s

void setup() {
  Serial.begin(115200);
  Serial.println("light sleep");

  delay(4000);
  Serial.println("sleep now");
  delay(100);

  esp_sleep_enable_timer_wakeup(SLEEP_DURATION);
  esp_light_sleep_start();

  Serial.println("Wakeup");
}

void loop() {}
