/* 
Autore: Paolo Aliverti
Listato 6.3 – Controllo servo-motore 
*/
#include <ESP32Servo.h>

Servo servo;

void setup() {
  //servomotore collegato al pin 4
  // Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
  // Possible PWM GPIO pins on the ESP32-S2: 0(used by on-board button),1-17,18(used by on-board LED),19-21,26,33-42
  // Possible PWM GPIO pins on the ESP32-S3: 0(used by on-board button),1-21,35-45,47,48(used by on-board LED)
  // Possible PWM GPIO pins on the ESP32-C3: 0(used by on-board button),1-7,8(used by on-board LED),9-10,18-21
  servo.attach(4);
  /*
  // Allow allocation of all timers
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	myservo.setPeriodHertz(50);    // standard 50 hz servo
	myservo.attach(4, 1000, 2000); // attaches the servo on pin 18 to the servo object
	// using default min/max of 1000us and 2000us
	// different servos may require different min/max settings
	// for an accurate 0 to 180 sweep
  */
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1) {    
    servo.write(pos);
    delay(15); 
  }

  for (int pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);
    delay(15); 
  }
}
