import serial
import pygame
import time

# Arduino port
arduino = serial.Serial("COM8", 9600)

# Initialize sound
pygame.mixer.init()

alarm_playing = False

while True:

    if arduino.in_waiting > 0:

        message = arduino.readline().decode().strip()

        print(message)

        if message == "HOT":

            if not alarm_playing:
                pygame.mixer.music.load("alarm.mp3")
                pygame.mixer.music.play(-1)  # repeat alarm
                alarm_playing = True

        else:

            if alarm_playing:
                pygame.mixer.music.stop()
                alarm_playing = False

        time.sleep(0.1)
