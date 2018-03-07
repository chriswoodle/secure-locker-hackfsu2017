# About

This is an electronic locker meant to store secure items, sucha as firearms and ammunition. The locker operates using facial recognition, which is activated by a touch sensitive handle that uses a capacitive sensor. Submitted to HackFSU 2018.

# Team and contributers

* Chris Woodle - Embedded + hardware/electronics + IPC
* Muntaser Syed - Computer Vision, Cloud Api's
* Chris Wille - Web ui and Electron app
* Skyler Knezevic - Android App

# Operation/Features

 When a person touches the handle of the locker, a small camera inconspicuously embedded in the door of the locker takes a picture of the person, and if the person is recognized as an authorized user of the locker, the locker unlocks and the user can then access the contents. When the user closes the locker door, the camera takes another picture and an object detection algorithm is run to determine whether the user has a firearm in his/her possession. If so, an alert is generated with an appropriate law enforcement agency/officer via text message, automated call and a mapping engine which shows the coordinates of the armed person. At every stage of this process, the pictures taken are logged and may be accessed by an android app, a web interface or a desktop interface. In cases of emergency, the locker can be opened with a special access NFC card, which also triggers alerts. 
 
 As an added feature, individual boards used in the system are configured to run BOINC projects such as Rosetta Stone, SETI@Home and LHC@home during idle time to utilize their computing power. 

# Software 

> For info about each component, see the readme in each `src` folder

## General overview

* NodeJs
* Python
* Arduino
* Web Development
* Android Native

## API's and tech

* Amazon Rekognition
* Redis
* BOINC
* Twilio

# Hardware

## Electronics
* Arduino Uno
* Arduino Micro
* Raspberry Pi 3
* DragonBoard 410c
* Raspberry Pi Camera V2.1
* [Adafruit 12-Key Capacitive Touch Sensor Breakout - MPR121](https://www.adafruit.com/product/1982)
* RFID-RC522 module
* Adafruit Neo Pixel Strip RGBW
* Standard 5V servo
* 5V 10A Power supply (less current may be acceptable, servo must be externally powered)
* [Mechanical limit switch](https://www.amazon.com/Cylewet-V-156-1C25-Momentary-Arduino-CYT1046/dp/B06WRN7FQB/ref=pd_sim_328_6?_encoding=UTF8&pd_rd_i=B06WRN7FQB&pd_rd_r=8K1SJ0T8BE8SWR0357ZS&pd_rd_w=7nupS&pd_rd_wg=myJ3e&psc=1&refRID=8K1SJ0T8BE8SWR0357ZS) + pull down resistor
* [Bread board powersupply](https://www.amazon.com/UCEC-Breadboard-Supply-Arduino-Solderless/dp/B01ELAGIO6/ref=sr_1_2_sspa?s=electronics&ie=UTF8&qid=1520400051&sr=1-2-spons&keywords=breadboard+power&psc=1) (Modified to operate to pass 5V through)
* Solderless breadboard
* Jumper cables

## Mechanical hardware

* Premanufactured unfinished cabinet with hinged door ($50 from The Home Depot)
* Barrel Bolt lock ($4 from The Home Depot)
* Small wood screws
* Metal door handle (conductive, uncoated)
* <1' Bare solid strand copper wire (Thick diameter, similar to coat hanger)
* Small angle brackts ($3 from Homedepot)
* Zipties

## Tools and supplies

* Leaded Solder + Soldering Iron (TS100)
* Misc wire and barrel jack connector
* Usb cables 
* Hdmi Cable
 * Drill with drill bits and forstner bits ($17 forstner bit kit from The Home Depot)
* Dremel with side cutter bit
* Hot glue and hot glue gun
* Label printer
* Scrap wood for exiting drill bits
* Safety glasses

### Optional

* Nerf Blaster
* Snacks and Redbull

# License

Apache License, Version 2.0