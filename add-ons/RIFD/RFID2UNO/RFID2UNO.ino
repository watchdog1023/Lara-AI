#include <SoftwareSerial.h>

SoftwareSerial RFID(2, 3); // RX and TX

int i;
int rfidarray[25];

void setup()
{
  RFID.begin(9600);    // start serial to RFID reader
  Serial.begin(9600);  // start serial to PC 
}

void loop()
{
  if (RFID.available() > 0) 
    {
        for(int t = 0;t < 14;t++)
           {
             i = RFID.read();
             rfidarray[t] = i;
             Serial.print(rfidarray[t]);
           }
        delay(5000);
        RFID.flush();
        RFID.end();
        delay(5000);
    }
  else
    {
        RFID.begin(9600);
    }
  }
