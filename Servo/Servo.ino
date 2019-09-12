#include <Servo.h>

Servo servo;
void setup() {
  
  servo.attach(4, 650, 2550);

}

void loop() {
  servo.write(10);
  delay(40);

}
