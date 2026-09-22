import serial
import time
import pygame

# =========================
# Settings
# =========================
SERIAL_PORT = "COM8"       # Change this if your Arduino uses another COM port
BAUD_RATE = 9600

SOUND_FILE = "ambulance.mp3"

# =========================
# Start sound system
# =========================
pygame.mixer.init()
sound = pygame.mixer.Sound(SOUND_FILE)

# Arduino serial connection
arduino = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
time.sleep(2)

print("Ambulance sound controller started!")
print("Turn the potentiometer to change the speed.")
print("Press Ctrl+C to stop.")

try:
    while True:

        if arduino.in_waiting:
            line = arduino.readline().decode("utf-8", errors="ignore").strip()

            if line.isdigit():
                delay_time = int(line)

                # Keep the value safe
                delay_time = max(100, min(1000, delay_time))

                # Convert milliseconds to seconds
                delay_seconds = delay_time / 1000.0

                # Play the short "WEE-OO" sound.
                sound.play()

                print(
                    f"delayTime = {delay_time} ms  ->  "
                    f"ambulance speed = {1000 / delay_time:.2f} repeats/sec"
                )

                # Wait according to Arduino's delay time.
                time.sleep(delay_seconds)

except KeyboardInterrupt:
    print("\nStopped.")

finally:
    arduino.close()
    pygame.mixer.quit()
