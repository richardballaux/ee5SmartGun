#include "rotaryEncoder.h"
#include "config.h"

//byte sendData[PACKET_SIZE];
int counterRotary = 0;


void setupRotaryEncoder()
{
  pinMode(rotaryPin1,INPUT);
  pinMode(rotaryPin2,INPUT);
  attachInterrupt(digitalPinToInterrupt(rotaryPin2), countRotaryMode, CHANGE);
}
  
int updateRotaryMode()
{
  int value = 0;
  if(counterRotary <= -4)                               value = 2;                             //mode: SEMI
  else if(-1 <= counterRotary && counterRotary <= 1)    value = 0;                             //mode: SAFETY
  else if(counterRotary >= 4)                           value = 4;                             //mode: AUTO
  sendData[3] += value;
  return value;
}

void countRotaryMode(){
  
  if(digitalRead(rotaryPin1) != digitalRead(rotaryPin2)){
    counterRotary++;
  }
  else{
    counterRotary--;
  }
  Serial.print("position = ");
  Serial.println(counterRotary);
  
}
