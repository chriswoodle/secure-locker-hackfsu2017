
#include <Wire.h>
#include "Adafruit_MPR121.h"

#include <Servo.h>

Servo myservo;

// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

const int doorClosedPin = 8;

const int doorClosedServoPosition = 103;
const int doorOpenServoPosition = 74;

int doorClosedState = 0;

int incomingByte = 0;

void setup() {
  //while (!Serial);        // needed to keep leonardo/micro from starting too fast!

  Serial.begin(115200);
  Serial.println("$HackFSU");

  myservo.attach(9);

  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap.begin(0x5A)) {
    Serial.println("!MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("$MPR121 found!");

  // initialize the door closed pin as an input:
  pinMode(doorClosedPin, INPUT);

  doorClosedState = digitalRead(doorClosedPin);
  if (doorClosedState == HIGH) {
    Serial.println("$Door closed at init");
    myservo.write(doorClosedServoPosition);
  } else {
    Serial.println("$Door opened at init");
    myservo.write(doorOpenServoPosition);
  }
}

void loop() {
  // check door is closed
  int currentDoorClosedState = digitalRead(doorClosedPin);
  if (doorClosedState != currentDoorClosedState) {
    doorClosedState = currentDoorClosedState;
    if (doorClosedState == HIGH) {
      Serial.println("#closed");
      delay(500);
      Serial.println("#locked");
      myservo.write(doorClosedServoPosition);
    }
    if (doorClosedState == LOW) {
      Serial.println("#open");
    }
  }

  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    //    Serial.print("I received: ");
    //    Serial.println(incomingByte, DEC);
    if (incomingByte == 'L') {
      Serial.println("#locked");
      myservo.write(doorClosedServoPosition);
    }
    if (incomingByte == 'U') {
      Serial.println("#unlocked");
      myservo.write(doorOpenServoPosition);
    }

  }

  // Get the currently touched pads
  currtouched = cap.touched();

  // it if *is* touched and *wasnt* touched before, alert!
  if ((currtouched & _BV(0)) && !(lasttouched & _BV(0)) ) {
    Serial.println("#touched");
  }
  // if it *was* touched and now *isnt*, alert!
  if (!(currtouched & _BV(0)) && (lasttouched & _BV(0)) ) {
    //Serial.println(" released");
  }

  // reset our state
  lasttouched = currtouched;
  // slow down
  delay(50);
}