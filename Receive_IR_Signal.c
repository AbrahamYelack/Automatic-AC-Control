/* 
   This file is used in the process of capturing the unique 
   IR signals for a given device. Data will be output which can
   then be stored for use in replicating the signals action using
   an IR emitter. The IRLib was used for this process as the 
   intended use for this file was to receive IR signals from AC
   remotes which have much larger sized signals than e.g. a TV remote.
   If you don't require IR signals for an AC remote, you can also use
   the IRremote library.
*/

#include <IRLibRecvPCI.h>

// Initialise object to receive IR signal
IRrecvPCI myReceiver(2);

void setup() {
  //change BAUD rate in accordance with the Arduino used
  Serial.begin(9600);
  delay(2000); 
  while(!Serial){}
  myReceiver.enableIRIn();
}

// This function continuously receives and outputs RAW IR signals to the monitor
void loop() {
  
  if(myReceiver.getResults()){
    Serial.println(recvGlobal.recvLength, DEC);
    for(bufIndex_t i = 1; i < recvGlobal.recvLength; i++){
      Serial.print(recvGlobal.recvBuffer[i], DEC);
      Serial.print(F(", "));
      if(i%8==0) Serial.print(F("\n\t"));
    }
    Serial.println(F("1000};"));
    myReceiver.enableIRIn();
  }

}
