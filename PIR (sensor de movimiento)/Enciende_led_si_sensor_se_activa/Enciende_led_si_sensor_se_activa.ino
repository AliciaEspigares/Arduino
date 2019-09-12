
const int pir = 4;
const int led = 13;

void setup() {
 
  pinMode(pir,INPUT);
  pinMode(led,OUTPUT);

}

void loop() {
 
  if(digitalRead(pir) == HIGH){
    digitalWrite(led,HIGH);
    }
    else{
      digitalWrite(led,LOW);
  }
  
}
