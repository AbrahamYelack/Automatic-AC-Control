/* 
   This file is used in the process of capturing the unique 
   IR signals for a given device. Data will be output which can
   then be stored for use in replicating the signals action using
   an IR emitter.
*/

#include <IRremote.h>

// Specify PIN number of IR receiver and create IRecvPCI struct
const int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;

// Setup receiver in preperation to receive incoming signals
void setup() {
    // Tell Arduino to prepare for message exchanges
    Serial.begin(9600);
    // Delay for Arduino
    while(!Serial.available()){};
    delay(5000);
    // Allow incoming signals to be processed
    irrecv.enableIRIn();
    
    Serial.print("Ready to Receive IR Signals");

}

// Continuous loop to receive IR Signals and Print
void loop() {

    //Once a signal is received, it is decoded and stored in the results variable
    if (irrecv.decode(&results)){
        //Output code in Hexadecimal
        Serial.println(results.value, HEX);
        // Start receiving new signals
        irrecv.resume();
    }

    delay(1000);

}
