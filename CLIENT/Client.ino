/*
  UDP_client

  The Arduino microcontroller collects data from its sensors and sends this data
  to the computer server through the UDP protocol.

  Author: Olivier
*/

#include "config.h"
#include "wirelessDataTransfer.h"
#include "rotaryEncoder.h"
#include "pushButtonMagazine.h"
#include "hallEffectTrigger.h"


/***INITIALIZE CONNECTION VARIABLES***/
/*unsigned long oldLoopTime = 0;
unsigned long newLoopTime = 0;
unsigned long cycleTime = 0;*/

/***INITIALIZE SENSORS***/



/***INITIALIZE HELP VARIABLES***/


void setup() {
  /***SETUP SERIAL MONITOR***/
  Serial.begin(115200);
  /***SETUP WIFI & UDP***/
  if (setUpWifi()){
    printWifiInfo();
  }
   /***SETUP SENSORS***/
  setupMagazineButton();
  setupRotaryEncoder();
  setupTrigger();
  
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

  /***UDP PROTOCOL***/
  
  /*SEND DATA IF APPLICABLE*/
  if(timeToSendUdp()){

    updateTimer();
    sendUDP();
    
  }
  
  /*RESET DATA AFTER SENDING*/
  resetData();

}
