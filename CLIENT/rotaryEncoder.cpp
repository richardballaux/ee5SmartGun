#include "rotaryEncoder.h"
#include "config.h"

//byte sendData[PACKET_SIZE];
int counterRotary = 0;
int modeBitValue = 0;


void setupRotaryEncoder()
{
  pinMode(rotaryPin1,INPUT);
  pinMode(rotaryPin2,INPUT);
  attachInterrupt(digitalPinToInterrupt(rotaryPin2), countRotaryMode, CHANGE);
}
  
int updateRotaryMode()
{
  if(counterRotary < -2)                               value = 0;                             //mode: SAFETY
  else if(-2 <= counterRotary && counterRotary <= 2)   value = 2;                             //mode: SEMI
  else if(counterRotary > 2)                           value = 4;                             //mode: AUTO
  sendData[3] += modeBitValue;
  return modeBitValue;
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
