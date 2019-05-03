#ifndef _RFIDREADER_H
#define _RFIDREADER_H

#include <SoftwareSerial.h>
#define BUFFERSIZE 14

void setupRFID();
void readRFID();
void clearBufferArray();
char searchRfidTag(String tag);

#endif
