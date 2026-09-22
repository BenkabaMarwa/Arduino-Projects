Multi-Sensor Project
Overview
This project combines multiple sensors—an ultrasonic distance sensor, a thermistor, and a photoresistor (LDR)—into a single integrated Arduino system. Each sensor monitors its physical environment and independently controls a designated LED while streaming real-time diagnostic data to the Serial Monitor.

Components Used
Arduino board (Uno, Nano, or compatible)

Ultrasonic Sensor (HC-SR04)

Thermistor

Photoresistor (LDR)

3x LEDs

3x Resistors (220Ω for LEDs)

1x Resistor (10kΩ for sensor pull-downs/dividers)

Breadboard and jumper wires

Pin Configuration
LED 1 (Ultrasonic Indicator): Digital Pin 8

LED 2 (Thermistor Indicator): Digital Pin 9

LED 3 (Light Sensor Indicator): Digital Pin 10

Ultrasonic Trig Pin: Digital Pin 6

Ultrasonic Echo Pin: Digital Pin 7

Thermistor Pin: Analog Pin A0

LDR (Light Sensor) Pin: Analog Pin A1

How It Works
Ultrasonic Monitoring: Measures distance via sound wave reflection. If an object is within 10 cm, LED 1 turns on; otherwise, it stays off.

Temperature Monitoring: Reads analog voltage changes across the thermistor. If the reading crosses the threshold of 340, LED 2 turns on.

Light Level Monitoring: Reads ambient light intensity via the LDR. If the light drops below 300 (indicating a dark environment), LED 3 turns on.

Serial Telemetry: Outputs distance, thermistor raw value, and light sensor value to the Serial Monitor every 200 ms.
