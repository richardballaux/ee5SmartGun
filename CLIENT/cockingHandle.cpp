#include "cockingHandle.h"
#include "config.h"

int counterCocking = 0;

void setupCockingHandle()
{
  pinMode(cockingSensor1,INPUT);
  pinMode(cockingSensor2,INPUT);
  pinMode(pushBtnReset,INPUT);

  attachInterrupt(digitalPinToInterrupt(cockingSensor2), interruptCocking, FALLING);
  
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
  sendData[1] = map(abs(counterCocking), ENDHANDLE, BEGINHANDLE,255,0);  
  
}

void interruptCocking()
{  
  if(digitalRead(cockingSensor2) != digitalRead(cockingSensor1)){
    counterCocking++;
  }
  
  else{
    counterCocking--; 
  }
  #ifdef DEBUGCOCKINGHANDLE
  Serial.print("position = ");
  Serial.println(abs(counterCocking));
  #endif
}
