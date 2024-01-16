/* 
  This file is responsible for monitoring the room temperature 
  and sending out the unique IR ON/OFF signal to control the AC. The raw 
  IR signal code should be manually entered as specified below, 
  and can be sourced from the use of Receive_IR_Signal.c
*/

#include <IRLibSendBase.h>
#include <IRLib_HashRaw.h>
#include <dht11.h>
#define DHT11PIN A0

// The DHT11 has temperature error of +/- 2
char err = 2;
dht11 DHT11;
IRsendRaw irsend;

// Replace these variable values with your unique 
// on and off signal codes
#define RAW_DATA_LENGTH_ON 350
uint16_t rawDataOn[RAW_DATA_LENGTH] = { /*Paste Raw Data Here (ON) */ }
#define RAW_DATA_LENGTH_OFF 350
uint16_t rawDataOff[RAW_DATA_LENGTH] = { /*Paste Raw Data Here (OFF) */ }

void setup() {

  Serial.begin(9600);
  // We will be sending at frequency 28KHz
  irsend.begin(38);
}

// This loop will continuously read in the temperature and send on and off signals 
// to the AC based on the temperature.
void loop() {

  //Read and store the Temperature
  DHT11.read(DHT11PIN); 
  float temp = DHT11.temperature + err;
  Serial.print("Temp = ");
  Serial.print(temp);
  Serial.println(" C")

  delay(500);
  // When the temperature is below or equal to 25 Degrees we send the OFF signal
  if ( temp <= 25 )
  {
    Serial.print("Sending IR OFF code");
    irsend.send(rawDataOff, RAW_DATA_LENGTH_OFF, 32);
    delay(5000); // Delay for 5 seconds before sending the next code to avoid AC damage from repition
  }
  // When the temperature is above 25 Degrees we send the ON signal
  if ( temp > 29 )
  {
    Serial.print("Sending IR ON code");
    irsend.send(rawDataOn, RAW_DATA_LENGTH_ON, 32);
    delay(5000); // Delay for 5 seconds before sending the next code to avoid AC damage from repition
  }


}


  
