import boto3
import json
import os
import time
import sys
import numpy as np
import time

time.sleep(2)
os.system("sudo raspistill -w 2448 -h 1848 -rot 180 -o capture.jpg")
time.sleep(2)
os.system("sudo cp capture.jpg lastlockerattempt.jpg")

s3 = boto3.resource('s3')

bucket2='lastaccesshero'
sF1="lastlockerattempt.jpg"
d1 = open(sF1, 'rb')
s3.Bucket('lastaccesshero').put_object(ACL='public-read', Key=sF1, Body=d1)

##for bucket in s3.buckets.all():
##    print(bucket.name)

##name of the source file	
sourceFile='capture.jpg'

data = open(sourceFile, 'rb')
s3.Bucket('hackfsu5').put_object(Key=sourceFile, Body=data)

bucket='hackfsu5'

targetFiles = ['chris.jpg', 'muntaser.jpg', 'woodle.jpg']

client=boto3.client('rekognition')

found = 0
for target in targetFiles:

    response=client.compare_faces(SimilarityThreshold=85, SourceImage={'S3Object':{'Bucket':bucket,'Name':sourceFile}}, TargetImage={'S3Object':{'Bucket':bucket,'Name':target}})

    for faceMatch in response['FaceMatches']:
            position = faceMatch['Face']['BoundingBox']
            confidence = str(faceMatch['Face']['Confidence'])
##            print('The face at ' +
##                       str(position['Left']) + ' ' +
##                       str(position['Top']) +
##                       ' matches with ' + confidence + '% confidence')
##            print('\n recognized file is ' + target)
            ##print(json.dumps({"match": target, "confidence": confidence}, sort_keys=False))
            print(target[:-4])
            os.system("sudo cp capture.jpg lastlockeropen.jpg")
            found = 1
            sF2="lastlockeropen.jpg"
            d2 = open(sF2, 'rb')
            s3.Bucket('lastaccesshero').put_object(ACL='public-read', Key=sF2, Body=d2)
            break
    if found==1:
        break


if found==0:
    ##print(json.dumps({"match": "none", "confidence": 0}, sort_keys=False))
    print('none')
  
		   
obj = s3.Object("hackfsu5", sourceFile)
obj.delete()
