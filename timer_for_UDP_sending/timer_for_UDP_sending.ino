unsigned long oldLoopTime = 0;
unsigned long newLoopTime = 0;
unsigned long neededElapsedTime = 10;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  
  if(timeToSendUdp){
    Serial.println("I now send UDP");
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
