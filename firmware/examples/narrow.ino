// This #include statement was automatically added by the Particle IDE.
#include "firmware/phaulon.h"



// EXAMPLE USAGE
UDP Udp;

unsigned long int TickCountPush = 0UL;
unsigned long int DelayPush = 10000UL;

int port = 1024;
IPAddress multicastAddress(224,0,0,0);
unsigned char NodeAdr = 9;
char publishString[] = "";


void setup() {
  Serial.begin(9600);
  Udp.begin(port);
  Udp.joinMulticast(multicastAddress);
}

char data = 0;

void loop() {
  if (fhRXcmp) {
    sprintf(publishString, "%s %u %u %d", "OK", RXNod, RXCmd, RXArg);
    // sprintf(publishString, "%s %u %u %d", "OK", RXNod, RXCmd, RXArg);
    Serial.println(publishString);
    Udp.sendPacket(publishString, sizeof(publishString), multicastAddress, port);
    if (fhRXnod == NodeAdr) {
      // Message is for this controller
    }
    fhrst();
  }
  if (Udp.parsePacket() > 0) {
    while(Udp.available()) {
      fhrcv(Udp.read());
    }
  }

  if (Serial.available() > 0) {
    data = Serial.read();
    fhrcv((unsigned char)data);
    Serial.println(data);
  }

  if (millis() >= TickCountPush + DelayPush) {
	TickCountPush = millis();
// 	sprintf(publishString, "%u", TickCountPush);
    // Serial.println(publishString);
    // Udp.sendPacket(publishString, sizeof(publishString), multicastAddress, port);
  }
}
