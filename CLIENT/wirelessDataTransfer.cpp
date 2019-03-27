#include "wirelessDataTransfer.h"
#include "config.h"

IPAddress IPaddr(IP_Address);
WiFiUDP Udp;

int setUpWifi()
{
	WiFi.mode(WIFI_STA);
	WiFi.begin(STASSID, STAPSK);
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
	}

	return 1;
}

void setUpUDP()
{
	Udp.begin(localPort);
}

int sendUDP()
{
	Udp.beginPacket(IPaddr, localPort);   
	for (int i = 0; i < PACKET_SIZE; i++) {
		Udp.write(sendData[i]);           
	}

	Udp.endPacket();                      
}

void checkWifi()
{
  if (WiFi.status() != WL_CONNECTED)
        {
            Serial.println("WIFI HAS BEEN DISCONNECTED... RESETTING NOW");
            setUpWifi();
        } 
}
