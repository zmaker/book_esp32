/* 
Autore: Paolo Aliverti
Listato 6.15 – Hibernation
*/

const uint32_t SLEEP_DURATION = 4 * 1000000; // 4s

void setup() {
  Serial.begin(115200);
  Serial.println("hibernate");

  delay(4000);
  Serial.println("hibernate now");
  delay(100);

  esp_sleep_enable_timer_wakeup(SLEEP_DURATION);

  esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH,   ESP_PD_OPTION_OFF);
  esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_SLOW_MEM, ESP_PD_OPTION_OFF);
  esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_FAST_MEM, ESP_PD_OPTION_OFF);
  esp_sleep_pd_config(ESP_PD_DOMAIN_XTAL,         ESP_PD_OPTION_OFF);
      
  esp_deep_sleep_start();

  //qui non arriverà mai
  Serial.println("Wakeup");
}

void loop() {}
