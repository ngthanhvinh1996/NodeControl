void setupLoRa(){
  Serial.println("[LoRa] Setting up LoRa");

  SPI.begin();
  LoRa.setPins();
  while(!LoRa.begin(LORA_FREQ)){
    Serial.println("[LoRa] Starting LoRa failed.");
    delay(1000);
  }

  LoRa.setSpreadingFactor(LORA_SF);
  LoRa.setCodingRate4(LORA_CR);
  LoRa.setSignalBandwidth(LORA_BW);
  LoRa.setPreambleLength(LORA_PREAMBLE_LENGTH);

  LoRa.enableCrc();
}
void receiveNodeMessage(){
  int packetSize = LoRa.parsePacket();
  if(packetSize == 0){
    return "";
  }

  recipient = LoRa.read();
  sender = LoRa.read();

   if(recipient != localAddress){
      Serial.println("This not message.");
      return "";
  }
  if(sender == 0xA1){
    tem = LoRa.read();
    hum = LoRa.read();
    Light = LoRa.read();
  
    Serial.println("Received from: 0x" + String(recipient,HEX));
    Serial.println("Send to: 0x" + String(sender,HEX));
    Serial.println("RSSI: " + String(LoRa.packetRssi()));
    Serial.println("SNR: " + String(LoRa.packetSnr()));
  }else{
    Serial.println("Not sender Node");
  }
}

void receiveGWMessage(){
  int packetSize = LoRa.parsePacket();
  if(packetSize == 0) return "";

  recipient = LoRa.read();
  sender = LoRa.read();
  if(recipient != localAddress){
    Serial.println("This message not for me.");
    return "";
  }
  if(sender == 0xFF){
    control = LoRa.read();
    control1 = LoRa.read();

    Serial.println("Recived from: 0x" + String(sender,HEX));
    Serial.println("Send to: 0x" + String(recipient,HEX));
    Serial.println("RSSI: " + String(LoRa.packetRssi()));
    Serial.println("SNR: " + String(LoRa.packetSnr()));
  }else {
    tem = LoRa.read();
    hum = LoRa.read();
    Light = LoRa.read();
    sr602 = LoRa.read();
  
    Serial.println("Received from: 0x" + String(recipient,HEX));
    Serial.println("Send to: 0x" + String(sender,HEX));
    Serial.println("RSSI: " + String(LoRa.packetRssi()));
    Serial.println("SNR: " + String(LoRa.packetSnr()));
  }
}
