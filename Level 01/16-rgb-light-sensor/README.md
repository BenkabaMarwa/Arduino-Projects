RGB LED Light Sensor Control
Overview
This project uses a photoresistor (LDR) to measure ambient light levels and dynamically changes the color of an RGB LED based on how bright or dark the environment is. It also streams real-time light sensor telemetry to the Serial Monitor.

Components Used
Arduino board (Uno, Nano, or compatible)

Photoresistor (LDR)

1x RGB LED (Common Cathode or Anode, adjusted via digital logic)

Resistors (220Ω for RGB channels, 10kΩ for the LDR pull-down/divider)

Breadboard and jumper wires

Pin Configuration
LDR Pin: Analog Pin A0

Red LED Pin: Digital Pin 11 (PWM-capable)

Green LED Pin: Digital Pin 9 (PWM-capable)

Blue LED Pin: Digital Pin 10 (PWM-capable)

How It Works
Light Measurement: The Arduino reads the analog voltage across the LDR circuit via analog pin A0.

Threshold Evaluation:

Bright Environment (lightValue > 700): Turns on the Green channel to indicate high light.

Medium Light (300 < lightValue <= 700): Turns on the Blue channel for intermediate light levels.

Dark Environment (lightValue <= 300): Turns on the Red channel to signal low light/darkness.

Serial Telemetry: Outputs the raw light sensor reading to the Serial Monitor every 200 ms.