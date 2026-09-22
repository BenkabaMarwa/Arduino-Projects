import serial
import pygame
import time

arduino = serial.Serial('COM8', 9600)
time.sleep(2)

pygame.mixer.init()

pygame.mixer.music.load("tn_tn_tn_tn_alarm.mp3")

while True:

    data = arduino.readline().decode().strip()

    if data:
        distance = float(data)

        print("Distance:", distance, "cm")

        if distance <= 10:
            if not pygame.mixer.music.get_busy():
                pygame.mixer.music.play()

        else:
            pygame.mixer.music.stop()
