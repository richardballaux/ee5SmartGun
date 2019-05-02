#include "rfidReader.h"
#include "config.h"

char buffer[BUFFERSIZE];       // buffer array for data receive over serial port
int count = 0;                    // counter for buffer array
String rfidtag; 
String rfidTags[] = {
  "25051484853555668505468703",
  "25051484853556570655255703",
  "25052484853535068704865673",
  "25051484853664851676966533"  };
  
SoftwareSerial SoftSerial(rfidPinRx,D2);

void setupRFID()
{
  SoftSerial.begin(9600);
}

void readRFID()
{
    if (SoftSerial.available() > 0)              
    {
        while(SoftSerial.available())               // reading data into char array
        {
            buffer[count] = SoftSerial.read();      // writing data into array
            if(count == BUFFERSIZE)break;
            count++;
        }
        if(count == BUFFERSIZE){     
          for(int i = 0; i < BUFFERSIZE; i++){
            rfidtag += buffer[i];
          }
          clearBufferArray();             // call clearBufferArray function to clear the stored data from the array
          count = 0;  
          #ifdef DEBUG
          Serial.println(rfidtag);
          #endif
          sendData[2] = searchRfidTag(rfidtag);                    
          rfidtag = "";
        }
    } 
}

void clearBufferArray()                 // function to clear buffer array
{
    // clear all index of array with command NULL
    for (int i=0; i<count; i++)
    {
        buffer[i]=NULL;
    }                  
}

char searchRfidTag(String tag)
{
  char result = 0;
  for(int i = 0; i < 4; i++){
    if(tag.equals(rfidTags[i]))
    {
      result = (i+1)*10;
    }
  }
   #ifdef DEBUG
   Serial.println("RFID TAG IS: ");
   Serial.println(result);
   #endif
  return result;
}
