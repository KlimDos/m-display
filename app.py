#!/usr/bin/env python3
import serial
import time

ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
ser.flush()

while True:
    inpt = input("Input:\n")
    ser.write(bytes(inpt+"\n", 'utf-8'))
