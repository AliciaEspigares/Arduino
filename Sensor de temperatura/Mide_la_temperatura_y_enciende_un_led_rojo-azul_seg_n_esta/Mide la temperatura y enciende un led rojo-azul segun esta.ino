const int sensor = 0;
  const int rojo = 5;
  const int azul = 6 ;
  int brillo; 
  long miliVolts; // porque las multiplicaciones que haremos tendrán muchos números que no cabran en int
  long temperatura;

  void setup() {
  Serial.begin(9600); // para empezar la comunicación tú-arduino 
  pinMode(rojo, OUTPUT);
  pinMode(azul, OUTPUT);
  }

  void loop() {
 
  miliVolts = (analogRead(sensor) * 5000L) / 1023; //lee el sensor y convierte la señal analógica(0-1023) a miliVoltios(0-5000). Se pone L para que arduino sepa que es una variable Long
  temperatura = miliVolts/10; //Pasamos de miliVolts a ºC
  
  Serial.print("La temperatura es: ");
  Serial.print(temperatura);
  Serial.print(" grados.\n");
  delay(200);
  
  brillo = map(temperatura, 10,40,0,255);  //Cambia la escala de los datos (0,255) el rango de señal de analog write para encender un led
  brillo = constrain(brillo, 0,255); //limita los valores a 0 y 255, porque si temperatura =0 => brillo<0
  
  analogWrite(rojo, brillo);
  analogWrite(azul, 255-brillo);
  
  
}