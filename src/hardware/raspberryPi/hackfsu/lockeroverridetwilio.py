from twilio.rest import Client
import time

# Your Account SID from twilio.com/console
account_sid = "xxxxxx"
# Your Auth Token from twilio.com/console
auth_token  = "xxxxxx"

client = Client(account_sid, auth_token)

call = client.calls.create(to="+123456789",    # to your cell phone
                           from_="+123456789", # from your Twilio phone number
                           url="http://fit-x-lab.com/hackathonfiles/lockeropenoverride.xml")

print(call.sid)
time.sleep(4)

message = client.messages.create(
    to="+123456789", 
    from_="+123456789",
    body="Your secure locker was successfully opened using an override command by this person https://s3.amazonaws.com/lastaccesshero/lastlockeropen.jpg")

print(message.sid)
