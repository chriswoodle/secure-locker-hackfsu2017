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