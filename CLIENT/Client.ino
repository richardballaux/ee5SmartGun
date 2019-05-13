/*
  UDP_client

  The Arduino microcontroller collects data from its sensors and sends this data
  to the computer server through the UDP protocol.

  Author: Deuce, LeRoy, Si-Wan, notRich-ard
*/

#include "config.h"
#include "wirelessDataTransfer.h"
#ifdef rotaryEncoder
#include "rotaryEncoder.h"
#endif
#ifdef pushButton
#include "pushButtonMagazine.h"
#endif
#ifdef trigger
#include "hallEffectTrigger.h"
#endif
#ifdef magazineReader
#include "rfidReader.h"
#endif

void setup() {
  /***SETUP SERIAL MONITOR***/
  Serial.begin(115200);
  /***SETUP WIFI & UDP***/
  if (setupWifi()){
    printWifiInfo();
  }
  //Dit evt. weglaten, is niet nodig...
  setupUDP();
   /***SETUP SENSORS***/
  #ifdef pushButton
  setupMagazineButton();
  #endif
  #ifdef rotaryEncoder
  setupRotaryEncoder();
  #endif
  #ifdef trigger
  setupTrigger();
  #endif
  #ifdef magazineReader
  setupRFID();
  #endif
}

void loop() {
  /*newLoopTime = millis();
  oldLoopTime = newLoopTime;*/
  if(timeToSendUdp()){

  /***LOG GUN TYPE***/
  #ifdef gunType
  sendData[3] += gunType;
  #endif
  
  /***CHECK WIFI***/
  #ifdef DEBUGWIFI
  checkWifi();
  #endif
  
  /***POLLING OF SENSORS***/
  #ifdef pushButton           
  updateMagazineButton();
  #endif

  #ifdef rotaryEncoder
  updateRotaryMode();
  #endif

  #ifdef trigger
  updateTrigger();
  #endif

  #ifdef magazineReader
  readRFID();
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
