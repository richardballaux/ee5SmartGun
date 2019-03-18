/*
  UDP_client

  The Arduino microcontroller collects data from its sensors and sends this data
  to the computer server through the UDP protocol.

  Author: Olivier
*/

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#ifndef STASSID
#define STASSID "LAPTOP_Olivier"
#define STAPSK  "valencia"
#endif

#define PACKET_SIZE 4

/***INITIALIZE CONNECTION VARIABLES***/

unsigned int localPort = 9877;      // local port to listen on
IPAddress IPaddr(192,168,137,1);

// buffers for receiving and sending data
//char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
//char  ReplyBuffer[] = "I am sending through UDP... I am a G\r\n";       // a string to send back
byte sendData[PACKET_SIZE] = {0,0,0,0};

WiFiUDP Udp;

/***INITIALIZE SENSORS***/
int pushBtnMagazine = 2;   // digital pin 4 has a pushbutton attached to it

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(STASSID, STAPSK);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
  Serial.printf("UDP server on port %d\n", localPort);
  Udp.begin(localPort);

  /***SETUP SENSORS***/
    pinMode(pushBtnMagazine, INPUT); // make the pushbutton's pin an input
}

void loop() {

  boolean sensorActivated = false;
  
  /***POLLING OF SENSORS***/             
  if(digitalRead(pushBtnMagazine)){
    sensorActivated = true;
    sendData[3] = 32;  // bitSafety bitSafety bitMagazine(32 or 0) bitFree bitFree bitFree bitFree bitFree
  }
  // print out the state of the button:
  //Serial.println(digitalRead(pushBtnMagazine));

  /*sendData[0] = 0x01;
  sendData[1] = 0x10;
  sendData[2] = 0x00;
  sendData[3] = 0x05;*/

  /***UDP PROTOCOL***/
  
  /*SEND DATA IF APPLICABLE*/
  if (sensorActivated){
  
    Udp.beginPacket(IPaddr, localPort);   //create packet
    for(int i=0;i<PACKET_SIZE;i++){
      Udp.write(sendData[i]);             //put data in packet
    }
    
    Udp.endPacket();                      //(s)end packet
    
    /*RESET DATA AFTER SENDING*/
    sensorActivated = false;
    for (int i = 0; i < 3; i++)
      sendData[i] = 0;

  }
  delay(500); 
}
