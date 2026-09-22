# Push Button Controls LED

## 🎯 Objective

Learn how to use a push button as a digital input to control an LED with Arduino Uno.

When the button is pressed, the LED turns ON.
When the button is released, the LED turns OFF.

## 🧰 Components

- Arduino Uno
- Breadboard
- Push button
- LED
- Resistor
- Jumper wires

## 🔌 Connections

### Push Button

| Component | Arduino       |
| --------- | ------------- |
| Button    | Digital Pin 7 |
| Button    | 5V            |

### LED

| Component       | Arduino       |
| --------------- | ------------- |
| LED Anode (+)   | Digital Pin 8 |
| LED Cathode (-) | GND           |

> Use a resistor with the LED to limit the current.

## ⚙️ How It Works

The push button is connected to **Digital Pin 7**.

Arduino reads the button state using a digital input:

- **Button pressed → HIGH → LED ON**
- **Button released → LOW → LED OFF**

The LED is connected to **Digital Pin 8**, which is configured as an output.

## 📚 What Students Learn

- Digital input and output
- `digitalRead()`
- `digitalWrite()`
- `pinMode()`
- Using a push button
- Controlling an LED
- Understanding HIGH and LOW states

## 🧠 Key Concepts

### Digital Input

A digital input can have two main states:

- `HIGH`
- `LOW`

The Arduino uses these states to determine whether the button is pressed or released.

### Digital Output

The Arduino controls the LED by sending:

- `HIGH` → LED ON
- `LOW` → LED OFF

## 🚀 Student Challenge

Try modifying the project so that:

1. The LED is normally ON.
2. Pressing the button turns the LED OFF.
3. Add a second LED and control it with the same button.

## 📌 Project Level

**Level 01 — Arduino Basics**

## 👩‍🏫 Learning by Building

This project introduces students to one of the most important Arduino concepts:

**Input → Processing → Output**

Button → Arduino → LED
