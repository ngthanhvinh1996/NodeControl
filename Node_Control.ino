#include "Node_COntrol.h"

Servo gservo;
byte localAddress = 0xA2;
byte destination = 0xFF;
byte recipient;
byte recipient1;
byte sender;
int sr602;
int value_gas;
int Light;
int tem;
int hum;
char control;
char control1;
unsigned long lastSend;
void setup() {
  
  Serial.begin(BAUD_RATE);
  setupRelay();
  setupLoRa();
  gservo.attach(SERVO_PIN);
}

void loop() {
//  if(millis() - lastSend > 1000){
    receiveGWMessage();
    if(control == 'A'){
      Manual();
    }else if(control == 'G'){   
      Auto();
    }
    lastSend = millis();
//}
  
  
}
