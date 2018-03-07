# Overview

The dragonbaord served as both the bridge-to-RFID and host for REDIS (Since I could not configure AWS Lightsail to run Redis in time).

# TODO

Recover source code from board
# Dragonboard setup

## Install Debian os (Linaro)

https://www.96boards.org/documentation/consumer/dragonboard410c/installation/#sd-card-method---install-and-boot-from-emmc


## Install latest Nodejs, gedit and nano

```
# Update sources
sudo apt update -y
sudo apt upgrade -y
sudo apt remove nodejs -y
sudo apt autoremove -y
sudo apt install gedit nano -y
# install NodeJs
cd ~
wget https://nodejs.org/dist/v8.9.4/node-v8.9.4-linux-arm64.tar.gz
tar -xvf node-v8.9.4-linux-arm64.tar.gz
cd node-v8.9.4-linux-arm64
sudo cp -R * /usr/local/
node -v
npm -v
cd ~
rm -rf node-v8.9.4-linux-arm64*
# Setup npm global install directory
mkdir ~/.npm-global
echo "export PATH=~/.npm-global/bin:\$PATH" >> ~/.bashrc
npm config set prefix '~/.npm-global'
```

> For NodeJS setup reference, see the docs I wrote here: https://docs.droplit.io/docs/install-nodejs-on-linux

## Installing Boinc

Instructions derived from here: http://www.instructables.com/id/BOINC-SETIHOME-for-Raspberry-Pi/

TODO

## Installing Redis

https://redis.io/topics/quickstart

After fllowing instructions, install [redis.conf](http://download.redis.io/redis-stable/redis.conf) to `/etc/redis/redis.conf`

Then you may want to remove the binding to only localhost, disable `save`, and remove the password.

```
redis-server --protected-mode no
```

