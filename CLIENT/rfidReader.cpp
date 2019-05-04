#include "rfidReader.h"
#include "config.h"

int buffer[BUFFERSIZE];       // buffer array for data receive over serial port
int count = 0;                    // counter for buffer array
String rfidtag; 
String rfidTags[] = {
  "25051484853555668505468703",
  "25051484853556570655255703",
  "25052484853535068704865673",
  "25051484853664851676966533"/*,
  String(2, HEX) + "23005B03CEB5" + String(3, HEX),
  String(2, HEX) + "230057AFA47F" + String(3, HEX),
  String(2, HEX) + "2400552DF0AC" + String(3, HEX),
  String(2, HEX) + "2300578D26DF" + String(3, HEX)*/
  };
  
SoftwareSerial SoftSerial(rfidPinRx,D2);

void setupRFID()
{
  SoftSerial.begin(9600);
}

void readRFID()
{   //Serial.println("Check if softserial available");
    if (SoftSerial.available() > 0)              
    {   //Serial.println("rfid available");
        while(SoftSerial.available())               // reading data into char array
        {
            buffer[count] = SoftSerial.read();      // writing data into array
            count++;
            if(count == BUFFERSIZE)break;
            
        }
        if(count == BUFFERSIZE){     
          for(int i = 0; i < BUFFERSIZE; i++){
            #ifdef DEBUGRFID
            Serial.println(int(buffer[i]), HEX);
            #endif
            rfidtag += buffer[i];
          }
          
          sendData[2] = searchRfidTag(rfidtag);                    
          clearBufferArray();             // call clearBufferArray function to clear the stored data from the array
          count = 0;  
          rfidtag = "";
        }
    } 
    yield();
}

void clearBufferArray()                 // function to clear buffer array
{
    // clear all index of array with command NULL
    for (int i=0; i<BUFFERSIZE; i++)
    {
        buffer[i]=NULL;
    }                  
}

int searchRfidTag(String tag)
{
  int result = 0;
 
  for(int i = 0; i < 4; i++){
    if(tag.equals(rfidTags[i])){
      result = (i+1)*10;
    }
  }
  
   #ifdef DEBUGRFID
   Serial.println("RFID TAG IS: ");
   Serial.println(tag);
   Serial.println("So the unique id over udp is ");
   Serial.println(result);
   Serial.println("++++++++");
   #endif
  return result;
}
