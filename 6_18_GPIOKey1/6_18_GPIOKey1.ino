/* 
Autore: Paolo Aliverti
Listato 6.18 – GPIO Sleep con key 1

Collegare un pulsante con resistore di pull-down sul pin 14
*/

#define BUTTON_PIN_BITMASK 0x0000004014

RTC_DATA_ATTR int count = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  count++;
  Serial.print("\ncount: ");
  Serial.println(count);

  esp_sleep_wakeup_cause_t causa;
  causa = esp_sleep_get_wakeup_cause();
  switch (causa){
    case ESP_SLEEP_WAKEUP_EXT0:
      Serial.println("Button ext0");
      break;
    case ESP_SLEEP_WAKEUP_EXT1:
      Serial.println("Button ext1");
      break;
    case ESP_SLEEP_WAKEUP_TIMER:
      Serial.println("timer");
      break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD:
      Serial.println("Touch");
      break;
    default:
      Serial.println("??");
  }

  esp_sleep_enable_ext1_wakeup(BUTTON_PIN_BITMASK,ESP_EXT1_WAKEUP_ANY_HIGH);

  Serial.println("Sto per andare in sleep...");
  delay(1000);
  esp_deep_sleep_start();
  
}

void loop() {}
