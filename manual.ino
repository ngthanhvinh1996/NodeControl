void Manual(){
  if(control1 == 'B'){
      digitalWrite(RELAY1, HIGH);
    }
    else if(control1 == 'b'){
      digitalWrite(RELAY1, LOW);
    }
    else if(control1 == 'C'){
      digitalWrite(RELAY2, HIGH);
    }
    else if(control1 == 'c'){
      digitalWrite(RELAY2, LOW);
    }
    else if(control1 == 'D'){
      digitalWrite(RELAY3, HIGH);
    }
    else if(control1 == 'd'){
      digitalWrite(RELAY3, LOW);
    }
    else if(control1 == 'E'){
      digitalWrite(RELAY4, HIGH);
    }
    else if(control1 == 'e'){
      digitalWrite(RELAY4, LOW);
    }
    else if(control1 == 'F'){
      digitalWrite(RELAY5,HIGH);
      gservo.write(90);
    }
    else if(control1 == 'f'){
      gservo.write(0);
      delay(1000);
      digitalWrite(RELAY5,LOW);
      
    }
}
