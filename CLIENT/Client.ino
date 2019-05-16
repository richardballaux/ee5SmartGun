/*
  UDP_client

  The Arduino microcontroller collects data from its sensors and sends this data
  to the computer server through the UDP protocol.

  Author: Deuce, LeRoy, Si-Wan, notRich-ard
*/

#include "config.h"
#include "wirelessDataTransfer.h"
#include "rotaryEncoder.h"
#include "pushButtonMagazine.h"
#include "hallEffectTrigger.h"
#include "rfidReader.h"
#include "cockingHandle.h"

void setup() {
  /***SETUP SERIAL MONITOR***/
  Serial.begin(115200);
  
  /***SETUP WIFI & UDP***/
  if (setupWifi()){
    printWifiInfo();
  }
  setupUDP();
  
   /***SETUP SENSORS***/
  #ifdef PUSHBUTTON
  setupMagazineButton();
  #endif
  #ifdef ROTARYENCODER
  setupRotaryEncoder();
  #endif
  #ifdef TRIGGER
  setupTrigger();
  #endif
  #ifdef magazineReader
  setupRFID();
  #endif
  #ifdef COCKINGHANDLE
  setupCockingHandle();
  #endif
}

void loop() {
  /*newLoopTime = millis();
  oldLoopTime = newLoopTime;*/
  if(timeToSendUdp()){

  /***LOG GUN TYPE***/
  #ifdef gunType
  sendData[3] += GUNTYPE;
  #endif
  
  /***CHECK WIFI***/
  #ifdef DEBUGWIFI
  checkWifi();
  #endif
  
  /***POLLING OF SENSORS***/
  #ifdef PUSHBUTTON           
  updateMagazineButton();
  #endif

  #ifdef ROTARYENCODER
  updateRotaryMode();
  #endif

  #ifdef TRIGGER
  updateTrigger();
  #endif

  #ifdef MAGAZINEREADER
  readRFID();
  #endif

  #ifdef COCKINGHANDLE
  readCockingHandle();
  #endif

  /***UDP PROTOCOL***/
  
  /*SEND DATA IF APPLICABLE*/
  
   updateTimer();
   sendUDP();
   #ifdef DEBUGDATA
   printData();
   #endif
    
  
  
  /*RESET DATA AFTER SENDING*/
  resetData();

  }
}
