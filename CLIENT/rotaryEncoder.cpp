#include "rotaryEncoder.h"
#include "config.h"

//byte sendData[PACKET_SIZE];
int counterRotary = -4;
boolean haveChanged2 = false;
boolean haveChanged1 = false;
int val = 0;

void setupRotaryEncoder()
{
  pinMode(rotaryPin1,INPUT);
  pinMode(rotaryPin2,INPUT);
  attachInterrupt(digitalPinToInterrupt(rotaryPin2), interruptRotary2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(rotaryPin1), interruptRotary1, CHANGE);
}
  
int updateRotaryMode()
{
  int value = 0;

  if (haveChanged1 && haveChanged2)
  {
    
    counterRotary += val;
    haveChanged1 = false;
    haveChanged2 = false;
    #ifdef DEBUGROTARY
    Serial.print("position rotary = ");
    Serial.println(counterRotary);
    #endif
  }
  if(counterRotary < -1)                               value = 0;                             
  //mode: SAFETY
  else if(-1 <= counterRotary && counterRotary <= 1)    value = 2;                             
  //mode: SEMI
  else if(counterRotary > 1)                           value = 4;                             
  //mode: AUTO
  sendData[3] += value;
  return value;
}

void interruptRotary2(){
  haveChanged2 = true;
  if (!haveChanged1) val = 1;
  /*if(haveChanged){
    counterRotary++;
  }
  else{
    counterRotary--;
  }
  haveChanged = false;
  #ifdef DEBUGROTARY
  Serial.print("position rotary = ");
  Serial.println(counterRotary);
  #endif
  */
}
void interruptRotary1(){
  haveChanged1 = true;
  if (!haveChanged2) val = -1;
  /*#ifdef DEBUGROTARY
  Serial.println("interrupt 1");
  #endif
*/
}
