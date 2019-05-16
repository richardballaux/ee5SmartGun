#include "cockingHandle.h"
#include "config.h"

int counterCocking = 0;

void setupCockingHandle()
{
  pinMode(cockingSensor1,INPUT);
  pinMode(cockingSensor2,INPUT);
  pinMode(pushBtnReset,INPUT);

  attachInterrupt(digitalPinToInterrupt(cockingSensor2), interruptCocking, CHANGE);
  
}

void readCockingHandle()
{
  if(digitalRead(pushBtnReset) == LOW){
    counterCocking = 0;
    #ifdef DEBUGCOCKINGHANDLE
    Serial.println("Reset cocking handle");
    #endif
  }
  #ifdef DEBUGCOCKINGHANDLE
  Serial.print("Cocking Handle value is ");
  Serial.println(abs(counterCocking));
  #endif
  sendData[1] = map(counterCocking, ENDHANDLE, BEGINHANDLE,255,0);  
  
}

void interruptCocking()
{  
  if(digitalRead(cockingSensor1) != digitalRead(cockingSensor2))
    if (counterCocking < 18)  counterCocking++;
  
  else
    if (counterCocking >= 0)  counterCocking--; 
}
