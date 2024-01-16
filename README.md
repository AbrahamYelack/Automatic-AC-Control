# Infrared Temperature-Controlled AC System

This repository comprises Arduino code for managing an air conditioner (AC) based on room temperature through infrared (IR) signals. The project involves two components:

## IR Signal Receiver (Receive_IR_Signal.c)
Purpose: Captures unique IR signals from an AC remote using the IRLibRecvPCI library.
Dependencies: IRLibRecvPCI library (Included in Libraries Zip)
Setup: Connect the IR receiver to pin 2 on the Arduino.
Functionality: The Arduino continuously receives and outputs raw IR signals to the serial monitor, which can be stored for later use.

## IR Signal Sender (Send_IR_Signal.c)
Purpose: Monitors room temperature using a DHT11 sensor and sends IR signals to control the AC based on temperature conditions.
Dependencies: IRremote and DHT Sensor Library
Setup: Connect the DHT11 temperature sensor to analog pin A0 and the IR emitter to an appropriate pin on the Arduino.
Functionality: The Arduino continuously reads the temperature and sends ON or OFF signals to the AC, depending on temperature conditions. The raw IR signal codes must be manually entered into the code.

### Important Note: Replace placeholder comments in the sender code with actual raw IR signal codes obtained using the receiver. Adjust temperature conditions and signal lengths based on specific requirements. Handle hardware connections appropriately and refer to the AC remote specifications for accurate signal reproduction.






