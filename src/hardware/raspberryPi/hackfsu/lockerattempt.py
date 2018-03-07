#import picamera
##import RPi.GPIO as GPIO
import time
import os
import boto3

owner = "munta"
bucket='lastaccesshero'
s3 = boto3.resource('s3')

time.sleep(1)
os.system("sudo raspistill -w 2448 -h 1848 -rot 180 -o capture.jpg")
#camera.capture("capture.jpg")
print("Picture taken")
time.sleep(2)
os.system("sudo cp capture.jpg lastlockerattempt.jpg")

sourceFile="lastlockerattempt.jpg"
data = open(sourceFile, 'rb')
s3.Bucket('lastaccesshero').put_object(ACL='public-read', Key=sourceFile, Body=data)