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
  setupMagazineButton();
  setupRotaryEncoder();
  setupTrigger();
  setupRFID();
}

void loop() {
  /*newLoopTime = millis();
  oldLoopTime = newLoopTime;*/

  /***CHECK WIFI***/
  checkWifi();
  
  /***POLLING OF SENSORS***/ 
           
  updateMagazineButton();
  
  /*CHECK ROTARY MODE*/
  updateRotaryMode();

  /*CHECK TRIGGER*/
  updateTrigger();

  readRFID();

  /***UDP PROTOCOL***/
  
  /*SEND DATA IF APPLICABLE*/
  if(timeToSendUdp()){

    updateTimer();
    sendUDP();
    #ifdef DEBUG
    printData();
    #endif
    
  }
  
  /*RESET DATA AFTER SENDING*/
  resetData();

}
