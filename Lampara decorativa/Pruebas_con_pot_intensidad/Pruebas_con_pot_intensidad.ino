const int ledR =2;  // led Rojo conectado al pin D2
const int ledG =3;  // led verde conectado al pin D3
const int ledB =4;  // led azul conectado al pin D4
const int potI =5; // el pot que controla la intensidad esta conectado al pin A5

const int LDR =0; // sensor LDR conectado a A0


int intensidad; //variable para la intensidad 

void setup ()  {
Serial.begin(9600);    // abre el Puerto serie
  pinMode (ledR, OUTPUT);  // declaramos el led rojo como salida 
  pinMode (ledB, OUTPUT);  // declaramos el led  azul como salida 
  pinMode (ledG, OUTPUT);  // declaramos el led verde como salida 
  /* los pin analogicos se declaran como entrada automaticamente */
}

void loop (){

Serial.println(intensidad); // envía valor analógico
delay(1000);     // espera 1 segundo
 //leemos el valor del sensor LDR
 // valorLDR= analogRead(LDR);


/*if(valorLDR > 700){
//Si hay luz (LDR>700) se apagan los leds
     digitalWrite(ledG, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledR, LOW);  
    delay(300000); //Espera 5 minutos
}

else{
  /*leemos el valor del potenciometro divididos entre 4 ya que
   solo se pueden usar valores entre 0 y 255 en analog Write  */ 

  /*analogWrite recibe dos valores,el pin a usar y la intensidad del voltaje
   los valores de voltaje van de 0 a 255*/
intensidad = analogRead (potI) /4; 
  
  //LED ROJO

   analogWrite(ledR, 0); //131

  //LED AZUL
   
   analogWrite(ledB, 125); //133

  //LED VERDE
  
   analogWrite(ledG, 0); //255 = 2.81V

  delay(100);
}
