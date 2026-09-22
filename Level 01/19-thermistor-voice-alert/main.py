import serial
import pygame
import time
import os

# =========================
# Settings
# =========================
SERIAL_PORT = "COM8"
BAUD_RATE = 9600

# =========================
# Arduino
# =========================
arduino = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)

time.sleep(2)

# =========================
# Pygame
# =========================
pygame.mixer.init()

sound_file = os.path.join(
    os.path.dirname(os.path.abspath(__file__)),
    "alarm.mp3"
)

print("Sound file:", sound_file)

alarm = pygame.mixer.Sound(sound_file)

print("System started...")
print("Waiting for HOT...")

alarm_playing = False

try:

    while True:

        data = arduino.readline().decode(
            "utf-8",
            errors="ignore"
        ).strip()

        if data:
            print("Arduino:", data)

        if data == "HOT":

            if not alarm_playing:

                print("🔥 HOT detected → ALARM!")

                alarm.play(-1)

                alarm_playing = True

        elif data == "NORMAL":

            if alarm_playing:

                print("Temperature normal → STOP ALARM")

                alarm.stop()

                alarm_playing = False

except KeyboardInterrupt:

    print("Program stopped.")

finally:

    if alarm_playing:
        alarm.stop()

    arduino.close()
    pygame.mixer.quit()
