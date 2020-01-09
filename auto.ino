void Auto(){
  if(Light == 3){
    digitalWrite(RELAY2,HIGH);
    digitalWrite(RELAY3,HIGH);
  }else if(Light == 4){
    digitalWrite(RELAY2,LOW);
    digitalWrite(RELAY3,LOW);
  }

  if(tem > 30){
    digitalWrite(RELAY1,HIGH);
  }else{
    digitalWrite(RELAY1,LOW);
  }

  if(sr602 == 1){
    digitalWrite(RELAY4,HIGH);
  }else if(sr602 == 0){
    digitalWrite(RELAY4,LOW);
  }
}
