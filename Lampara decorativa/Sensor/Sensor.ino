

/*
 * http://www.geekfactory.mx
 * 
 * Ejemplo de medidor de luz con Arduino utilizando una fotoresistencia LDR y
 * un grupo de leds para mostrar el resultado de las lecturas. Este sketch puede
 * servir como base para otros proyectos que requieren medicion de la intensidad
 * de luz con una fotoresistencia.
 *
 * Mas detalles y la conexion completa para este sketch en:
 * http://www.geekfactory.mx/tutoriales/tutoriales-arduino/tutorial-arduino-con-fotoresistencia-ldr/
 *
 */

// Pin donde se conectan los leds
int pinLed = 2;

// Pin analogico de entrada para el LDR
int pinLDR = 0;

// Variable donde se almacena el valor del LDR
int valorLDR = 0;  

void setup()
{
  // Configuramos como salidas los pines donde se conectan los led
  pinMode(pinLed, OUTPUT);
 
  
  //  Configurar el puerto serial
  Serial.begin(9600);
}

void loop()
{
  // Apagar todos los leds siempre que se inicia el ciclo
  digitalWrite(pinLed, LOW);
 

  // Guardamos el valor leido del ADC en una variable
  // El valor leido por el ADC (voltaje) aumenta de manera directamente proporcional
  // con respecto a la luz percibida por el LDR
  valorLDR= analogRead(pinLDR);
  
  // Devolver el valor leido a nuestro monitor serial en el IDE de Arduino
  Serial.println(valorLDR);

  // Encender los leds apropiados de acuerdo al valor de ADC
  
  if(valorLDR > 100)
  {
    digitalWrite(pinLed, LOW);
  }
  if(valorLDR < 100)
  {
    digitalWrite(pinLed, HIGH);
  }
  // Esperar unos milisegundos antes de actualizar
  delay(200);
}

