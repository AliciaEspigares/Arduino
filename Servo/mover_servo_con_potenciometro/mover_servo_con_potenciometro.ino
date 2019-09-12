#include <Servo.h>
// Este programa mueve un servo con un potenciometro
Servo miServo;

  const int potenciometro = 0;
  const int servo = 4;
  const int pulsoMin = 650; //pulso minimo que le mandas al servo para girarlo a 0º = 650ms 
  const int pulsoMax = 2550; //pulso máximo que le mandas al servo para girarlo a 180º = 650ms 
  int valor; //valor potenciometro
  int angulo;

void setup() {
  miServo.attach(servo, pulsoMin, pulsoMax); //configuración de servo (pin, pulsomin, pulso max) si no pones el min y max se pone como predeterminado (1000,2000)
}


void loop() {
  
  valor = analogRead(potenciometro);  //leemos el valor del potenciometro (varia de 0 a 1023)
  
  angulo = map(valor, 0, 1023, 180, 0);  //(valor del pot., valor min entrada=pot, valor max pot, valor min salida=servo, valor max servo) 
  //como mi servo gira al sentido antihorario hay que invertir los valores de salida= (180,0)
  miServo.write(angulo); //para mover el servo
   delay(20); // para darle al servo tiempo para llegar a su posición

}
