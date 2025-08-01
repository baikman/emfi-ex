"""
Please add to/edit the host tool in order to communicate properly with picos

TODO:
calculate a list with ranges of delay times that work
graph over time with installed libraries

consider power traces to graph loop repetitions
"""

import serial
import time
import struct

ser = serial.Serial("/dev/tty.usbmodem0E23BBD21", 115200) #replace with Tiva address

ser.write(b'A') #start byte

while(1):
    #communication pico will send valid delay times

    len = ser.read(8) #unsigned 64 bit integer - could make shorter
    ticks = int.from_bytes(len,byteorder="little")
    print(f"Ticks:{ticks}")
