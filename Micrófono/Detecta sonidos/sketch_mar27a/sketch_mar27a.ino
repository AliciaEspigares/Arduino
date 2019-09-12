// VU METER

int soundPin = A0;

void setup()
{ 
Serial.begin(9600); 
} 

void loop()
{ 
 int value = analogRead(soundPin);
 int topLED = 1 + abs(value) / 10;
 for (int i =0; i < topLED; i++)
 {
  Serial.print("*");
 }
 Serial.println();
 Serial.println(value); // print value for checking purposes
 delay(100);

   
 if(value>=800){
   digitalWrite(13, HIGH);
   delay(250);
   }
   else{
     digitalWrite(13,LOW);
     delay(100);
     }
     
} 
