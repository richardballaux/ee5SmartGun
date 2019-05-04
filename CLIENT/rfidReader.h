#ifndef _RFIDREADER_H
#define _RFIDREADER_H

#include <SoftwareSerial.h>
#define BUFFERSIZE 14

void setupRFID();
void readRFID();
void clearBufferArray();
int searchRfidTag(String tag);

#endif
