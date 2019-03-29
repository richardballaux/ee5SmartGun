#include "rotaryEncoder.h"
#include "config.h"

//byte sendData[PACKET_SIZE];


void setupMagazineButton()
{
  pinMode(pushBtnMagazine, INPUT);
}
  
int updateMagazineButton()
{
  int value = 0;
  if(digitalRead(pushBtnMagazine) == LOW){
    value = 1;  // bitSafety bitSafety bitMagazine(32 or 0) bitFree bitFree bitFree bitFree bitFree
    //Serial.println("MAGAZIN INSERTED");
  }
  sendData[3] += value;
  return value;
}
