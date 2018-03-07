
# Overview
This Arduino UNO was connected to the Dragonboard 410c through USB. The Dragonboard then could communicate to the Arduino over serial, `/dev/ttyACM0` `115200` buad.

The Arduino served 2 functions:

* Detect an RFID Device
* Indicate visually if device is authenticated (Hardcoded ID matches)


# Wiring

* See source code for MFRC522 wiring
* Adafruit NeoPixel connected to pin 6

# Serial events

Each event change would send a string over serial as follows:

#### `pass`

RFID-like device detected and ID matches hardcoded ID. NeoPixel would blink green.

#### `fail`

RFID-like device detected, however, the ID is not correct. NeoPixel would blink red.


# Dependencies/Libraries
* MFRC522 (RFID Sensor)
* Adafruit_NeoPixel

# Notes

* NeoPixel blinking code is blocking and will hold the thread untill the animation is over. RFID cards cannot be scanned during the animation given this implementation.

* There is a 2000 ms delay after reading a RFID card to prevent reading cards multiple times. 

# Refrences

* Examples > Adafruit NeoPixel > RGBWstrandtest
* Examples > MFRC522 > ReadNUID