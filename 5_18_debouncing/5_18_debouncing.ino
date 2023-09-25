/**
 * 5.18 - Debouncing
 */

unsigned long t = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Debouncing");

  pinMode(4, OUTPUT);
  pinMode(16, INPUT);
}

void loop() {  
  if (digitalRead(16)) {    
    if ((millis()-t) > 1000) {      
      digitalWrite(4, !digitalRead(4));
      t = millis();
    }
  }
}


