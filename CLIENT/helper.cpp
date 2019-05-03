#include "helper.h"

//10ms = frequency of 100Hz
#define NEEDEDTIME 10

unsigned long oldLoopTime = 0;
unsigned long newLoopTime = 0;
unsigned long lastTimeSent = 0;
unsigned long nowSent = 0;

byte sendData[PACKET_SIZE] = { 0,0,0,0 };

int counter = 0;

boolean timeToSendUdp()
{
  newLoopTime = millis();
  if (newLoopTime-oldLoopTime > NEEDEDTIME){
    oldLoopTime = newLoopTime;
    return true;
  }
  else{
    return false;
  } 
}

void updateTimer()
{
  //Serial.print("Time since last sending: ");
  nowSent = millis();
  //Serial.print(nowSent - lastTimeSent);
  lastTimeSent = nowSent;
  //Serial.println("\t I now send UDP");
  
}

void resetData()
{
  for (int i = 0; i < 4; i++)
    sendData[i] = 0;
}

void printData()
{
  counter++;
  if (counter > 100)
  {
  counter = 0;
  Serial.println("This is the data: ");
  for (int i = 0; i < 4; i++)
     Serial.println(sendData[i]); 

  Serial.println("----------");
  }
}
