# Overview

The Raspberry Pi serves as the center of the project. 
* It communicates to the Arduino Micro to control and read sensors.
* It communicates to cloud apis. 

## Code

The Pi acomplishes the following:

* Main process in NodeJS

* Capture picture -> upload to AWS S3 Bucket -> initiate AWS Rekognition via Python scripts

* Trigger SMS and Phone calls through TWILIO via python scripts

* Communicate to Arduino via NodeJS

# RPI Setup
```
# Enable ssh
sudo raspi-config nonint do_ssh 0
# Setup pi and remove junk I dont want
sudo apt update
sudo apt remove --purge libreoffice* wolfram-engine scratch minecraft-pi sonic-pi dillo gpicview oracle-java8-jdk openjdk-7-jre oracle-java7-jdk openjdk-8-jre -y
sudo apt clean -y
sudo apt autoremove -y
sudo apt upgrade -y

# remove folders
rm -rf ~/Music ~/Pictures ~/python_games ~/Videos ~/Documents ~/Public ~/Templates

# Install nodejs
cd ~
wget https://nodejs.org/dist/v8.9.4/node-v8.9.4-linux-armv7l.tar.xz
tar -xvf node*
cd node*/
sudo cp -R * /usr/local/
cd ~
rm -rf node*

* Fix npm global
mkdir ~/.npm-global
npm config set prefix '~/.npm-global'
echo "export PATH=~/.npm-global/bin:\$PATH" >> ~/.bashrc
```

> For NodeJS setup reference, see the docs I wrote here: https://docs.droplit.io/docs/install-nodejs-on-linux

## Code setup
1. Clone
2. Configure AWS api keys
3. From `app/`, `npm install`
4. From `app/` `node index.js`

> Note: Make sure your time is correct on your device. AWS will reject requests if your time is incorrect.