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

/***RESET KUT BOARD***/
#define D0 16
#define D1 5 // I2C Bus SCL (clock)
#define D2 4 // I2C Bus SDA (data)
#define D3 0
#define D4 2 // Same as "LED_BUILTIN", but inverted logic
#define D5 14 // SPI Bus SCK (clock)
#define D6 12 // SPI Bus MISO 
#define D7 13 // SPI Bus MOSI
#define D8 15 // SPI Bus SS (CS)
#define D9 3 // RX0 (Serial console)
#define D10 1 // TX0 (Serial console)

/***INITIALIZE CONNECTION VARIABLES***/

unsigned int localPort = 4210;      // local port to listen on
//IPAddress IPaddr(192,168,137,1);
IPAddress IPaddr(192,168,137,165);

// buffers for receiving and sending data
//char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
//char  ReplyBuffer[] = "I am sending through UDP... I am a G\r\n";       // a string to send back
byte sendData[PACKET_SIZE] = {0,0,0,0};

WiFiUDP Udp;

/***INITIALIZE SENSORS***/
int pushBtnMagazine = D5;   // digital pin 2 has a pushbutton attached to it
int rotaryPin1 = D6;
int rotaryPin2 = D7;

/***INITIALIZE HELP VARIABLES***/
int counterRotary = 0;
int timeCounter = 0;

void setup() {
  /***SETUP SERIAL MONITOR***/
  Serial.begin(9600);
  /***SETUP WIFI & UDP***/
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
  pinMode(rotaryPin1,INPUT);
  pinMode(rotaryPin2,INPUT);
  attachInterrupt(digitalPinToInterrupt(rotaryPin2), countGunMode, CHANGE);
}

void loop() {

  //boolean sensorActivated = false;
  
  /***POLLING OF SENSORS***/ 
  //Serial.println("Value read: ");
  //Serial.println(digitalRead(pushBtnMagazine));            
  if(digitalRead(pushBtnMagazine) == LOW){
    //sensorActivated = true;
    sendData[3] = 1;  // bitSafety bitSafety bitMagazine(32 or 0) bitFree bitFree bitFree bitFree bitFree
    //Serial.println("MAGAZIN INSERTED");
  }
  // print out the state of the button:
  //Serial.println(digitalRead(pushBtnMagazine));

  /*CHECK ROTARY MODE*/
  if(counterRotary <= -4)                               sendData[3] += 2;                             //mode: SEMI
  else if(-1 <= counterRotary && counterRotary <= 1)    sendData[3] += 0;                             //mode: SAFETY
  else if(counterRotary >= 4)                           sendData[3] += 4;                             //mode: AUTO

  /***UDP PROTOCOL***/
  
  /*SEND DATA IF APPLICABLE*/
  if (timeCounter = 100){
  
    Udp.beginPacket(IPaddr, localPort);   //create packet
    for(int i=0;i<PACKET_SIZE;i++){
      Udp.write(sendData[i]);             //put data in packet
    }
    
    Udp.endPacket();                      //(s)end packet

    timeCounter = 0;
  }
  
  /*RESET DATA AFTER SENDING*/
  //sensorActivated = false;
  for (int i = 0; i < 4; i++)
    sendData[i] = 0;

  
  delay(100);
  timeCounter += 1;
}

void countGunMode(){
  
  if(digitalRead(rotaryPin1) != digitalRead(rotaryPin2)){
    counterRotary++;
  }
  else{
    counterRotary--;
  }
  Serial.print("position = ");
  Serial.println(counterRotary);
  
}
