#ifndef _HELPER_H
#define _HELPER_H

#endif

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "Arduino.h"

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
/*********************/

#define PACKET_SIZE 4

extern byte sendData[PACKET_SIZE];
