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
byte sendData[PACKET_SIZE] = { 0,0,0,0 };
/*unsigned long oldLoopTime = 0;
unsigned long newLoopTime = 0;
unsigned long cycleTime = 0;*/

/***INITIALIZE SENSORS***/



/***INITIALIZE HELP VARIABLES***/

int timeCounter = 0;

void setup() {
  /***SETUP SERIAL MONITOR***/
  Serial.begin(115200);
  /***SETUP WIFI & UDP***/
  if (setUpWifi()){
    Serial.print("Connected! IP address: ");
    Serial.println(WiFi.localIP());
    Serial.printf("UDP server on port %d\n", localPort);
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
  if (timeCounter = 100){

    sendUDP();
    timeCounter = 0;
  }
  
  /*RESET DATA AFTER SENDING*/
  //sensorActivated = false;
  for (int i = 0; i < 4; i++)
    sendData[i] = 0;

  
  //delay(100);
  timeCounter += 1;
  /*cycleTime = millis() - newLoopTime;
  Serial.print("Cycletime: ");
  Serial.println(cycleTime);*/
}
