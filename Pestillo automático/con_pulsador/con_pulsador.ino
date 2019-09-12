#include <Servo.h>
Servo servo;
void setup() {
  
  
  int pulsador=2;
  servo.attach(4, 650, 2550);
  int estado = digitalRead(pulsador);

}

void loop() {
  int pulsador=2;
  servo.attach(4, 650, 2550);
  int estado = digitalRead(pulsador);

  switch (estado) // Aqui tenemos la clausula switch con sus case:
                  { case LOW:

                       servo.write(80);
                       delay(40);
                        break;
                    case HIGH:

                        servo.write(20);
                        delay(40);
                        break;
                    
                  }

}
