import serial
import pygame
import time

# =========================
# Arduino
# =========================
arduino = serial.Serial("COM8", 9600, timeout=0.1)

time.sleep(2)

# =========================
# Sound
# =========================
pygame.mixer.init()

tn = pygame.mixer.Sound("tn.mp3")

print("TN speed controller started!")
print("Turn the potentiometer...")
print("Press CTRL+C to stop.")

# Time of next TN
next_tn = time.time()

try:

    while True:

        # Read Arduino
        data = arduino.readline().decode().strip()

        if data:

            try:
                potValue = int(data)

                # Convert 0-1023 to speed
                interval = 0.8 - (potValue / 1023.0) * 0.7

                # Play TN when the time arrives
                current_time = time.time()

                if current_time >= next_tn:

                    tn.play()

                    # Schedule next TN
                    next_tn = current_time + interval

                print(
                    "Pot:",
                    potValue,
                    " | Interval:",
                    round(interval, 2),
                    "sec"
                )

            except ValueError:
                pass

        # Don't freeze the program
        time.sleep(0.01)

except KeyboardInterrupt:

    print("\nStopped.")

finally:

    arduino.close()
    pygame.mixer.quit()
