unsigned long oldLoopTime = 0;
unsigned long newLoopTime = 0;
unsigned long neededElapsedTime = 10;
unsigned long lastTimeSent = 0;
unsigned long nowSent = 0;
void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:

}

void loop() {
  
  if(timeToSendUdp){
    Serial.print("Time since last sending: ");
    nowSent = millis();
    Serial.print(nowSent - lastTimeSent);
    lastTimeSent = nowSent;
    Serial.println("\t I now send UDP");
  }

}


boolean timeToSendUdp(){
  newLoopTime = millis();
  if (newLoopTime-oldLoopTime>neededElapsedTime){
    oldLoopTime = newLoopTime;
    return true;
  }
  else{
    return false;
  }
  
}
