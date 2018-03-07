
# Overview
This Arduino Micro was connected to the Raspberry Pi 3 through USB. The Raspberry Pi then could communicate to the Arduino over serial, `/dev/ttyACM0` `115200` buad.

The Arduino served 3 functions:

* Detect if the locker door was opened or closed
* Actuate the servo to lock and unlock the door
* Detect if the handle was being touched


# Wiring

* Switch into pin `8`, high -> Door Closed, low -> Door Opened
* Adafruit MPR121 connected to I2C, pins `2` and `3` (SDA, SCL)
* Servo connected to pin `9` (pwm)

# Serial events

Each event change would send a string over serial as follows:

#### `#closed`

Door was closed.

#### `#open`

Door was open

#### `#locked`

Lock moved to "locked" position.

#### `#unlocked`

Lock moved to "unlocked" position.

#### `#touched`

Door handle was touched.

# Serial Command

The device can recieve the following commands:

#### `'L'`

Sets lock to "locked" position;

#### `'U'`

Sets lock to "unlocked" position;


# Dependencies/Libraries
* Adafruit_MPR121 (capacitive sensor)

# Notes

* Servo 5V MUST be supplied through an external source. Standard USB ports cannot supply enough current and if powered from the board, will cause the Arduino to endlessly reboot.

* Servo position was determined through trial and error.

* The capacitive sensor seemed to missfire every few minutes.

# Refrences

* https://www.arduino.cc/en/Serial/Read
* Examples > Servo > Sweep
* Examples > Adafruit MPR121 > MPR121test