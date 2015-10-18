#define RADIOPIN 13
#define DL1 10000
#define DL2 10150

#include<string.h>
//#include <util/crc16.h>

char datastring[80];

void setup(){
  pinMode(RADIOPIN, OUTPUT);
}

void loop(){
  
  sprintf(datastring, "RTTY TEST BEACON RTTY TEST BEACON");
  strcat(datastring, " \n");
  
  rtty_txstring(datastring);
  delay(2000);
}

