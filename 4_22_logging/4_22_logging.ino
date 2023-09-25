/* 
Autore: Paolo Aliverti
Listato 2.22– Funzioni di logging in ESP32.
*/
void setup() {
  Serial.begin(115200);

  Serial.setDebugOutput(true);

  log_v("Verbose");
  log_d("Debug");
  log_i("Info");
  log_w("Warning");
  log_e("Error");
}

void loop() {}
