

const int ledR =2;  // led Rojo conectado al pin 2
const int potR =2; // el pot rojo esta conectado al pin A2

const int ledG =3;  // led verde conectado al pin 3
const int potG =3; // el pot verde esta conectado al pin A3

const int ledB =4;  // led azul conectado al pin 4
const int potB =4; // el pot azul esta conectado al pin A4

const int LDR =0; // sensor LDR


int brilloR;  //variable para el brillo
int brilloG;  //variable para el brillo
int brilloB;  //variable para el brillo

void setup ()  {

  pinMode (ledR, OUTPUT);  // declaramos el led rojo como salida 
  pinMode (ledB, OUTPUT);  // declaramos el led  azul como salida 
  pinMode (ledG, OUTPUT);  // declaramos el led verde como salida 
  /* los pin analogicos se declaran como entrada automaticamente */
}

void loop (){

 //leemos el valor del sensor LDR
  valorLDR= analogRead(LDR);


if(valorLDR > 700){
//Si hay luz (LDR>700) se apagan los leds
 		digitalWrite(ledG, LOW);
		digitalWrite(ledB, LOW);
		digitalWrite(ledR, LOW);	
		delay(300000); //Espera 5 minutos
}

else{
  /*leemos el valor del potenciometro divididos entre 4 ya que
   solo se pueden usar valores entre 0 y 255 en analog Write  */.  

  /*analogWrite recibe dos valores,el pin a usar y la intensidad del voltaje
   los valores de voltaje van de 0 a 255*/

  //LED ROJO
   brilloR = analogRead (potR) /4; 
   analogWrite(ledR, brilloR);

  //LED AZUL
	 brilloB = analogRead (potB) /4; 
   analogWrite(ledB, brilloB);

  //LED VERDE
	 brilloG = analogRead (potG) /4; 
   analogWrite(ledG, brilloG);

  delay(100);
}