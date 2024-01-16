# Infrared Temperature-Controlled AC System

## Overview

This repository comprises Arduino code for managing an air conditioner (AC) based on room temperature through infrared (IR) signals.

This code can be used in conjunction with an Arduino, IR Receiver/Emitter and DHT11 Temperature Sensor to control the state of any Air Conditioner. This brings practical value by efficiently managing energy consumption, reducing electricity costs, and enhancing user comfort. By automating the AC system based on temperature preferences, it ensures a consistent and comfortable environment without the need for constant manual adjustments. Suitable for both residential and commercial use, this project focuses on providing a straightforward and effective solution to optimise energy usage and improve overall convenience.

The project involves two components:

## IR Signal Receiver (Receive_IR_Signal.c)
Purpose: Captures unique IR signals from an AC remote using the IRLibRecvPCI library.

Dependencies: IRLibRecvPCI library (Included in Libraries Zip)

Setup: Connect the IR receiver to pin 2 on the Arduino.

Functionality: The Arduino continuously receives and outputs raw IR signals to the serial monitor, which can be stored for later use.

## IR Signal Sender (Send_IR_Signal.c)
Purpose: Monitors room temperature using a DHT11 sensor and sends IR signals to control the AC based on temperature conditions.

Dependencies: IRLib_HashRaw, IRLib_SendBase and DHT Sensor Library (All included in Libraries Zip)

Setup: Connect the DHT11 temperature sensor to analog pin A0 and the IR emitter to an appropriate pin on the Arduino.

Functionality: The Arduino continuously reads the temperature and sends ON or OFF signals to the AC, depending on temperature conditions. The raw IR signal codes must be manually entered into the code.

### Important Note: 
Replace placeholder comments in the sender code with actual raw IR signal codes obtained using the receiver. Adjust temperature conditions and signal lengths based on specific requirements. Handle hardware connections appropriately and refer to the AC remote specifications for accurate signal reproduction.






