#include "IRLremote.h"
const int interruptIR = 0;

uint8_t IRProtocol = 0;  // Variables para recibir los datos
uint16_t IRAddress = 0;
uint32_t IRCommand = 0;

#include <Servo.h>

Servo servo;
void setup() 
   {    Serial.begin(115200);          // Fijate en la velocidad
        for (int i = 8 ; i<12 ; i++)
        pinMode(i, OUTPUT);

        IRLbegin<IR_ALL>(interruptIR);
        
        servo.attach(4, 650, 2550);
   }
  void loop()
   {    uint8_t oldSREG = SREG;  // Parar las interrupciones
        cli();
        if (IRProtocol)
          {  
             switch (IRCommand) // Aqui tenemos la clausula switch con sus case:
                  { case 0x2FD:

                       servo.write(80);
                       delay(40);
                        break;
                    case 0xC23D:

                        servo.write(20);
                        delay(40);
                        break;
                    
                  }
              IRProtocol = 0;
          }
       SREG = oldSREG; 
    }
void IREvent(uint8_t protocol, uint16_t address, uint32_t command)
   {
        IRProtocol = protocol;  // Recogemos los valores
        IRAddress = address;
        IRCommand = command;
   }
