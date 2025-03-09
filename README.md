# ESP32 Parking Sensor IoT

Ultrasonic parking sensor with stoplight LEDs for user feedback.

## Current Schematic (03.09.2025)

![Circuit Diagram](https://github.com/user-attachments/assets/1654e837-2f33-42f5-99e8-047eb669a84d)

## TODO

1. Use a distance abstraction to remove outliers in distance calculation to prevent the lights from jumping
2. Make the `red_light_distance` configurable at runtime to allow users to set the stop distance.
3. **Maybe** enable zigbee or MQTT for smarthome connection in the form of a sensor

- Could all temp sensor and others to make more robust if desired.
