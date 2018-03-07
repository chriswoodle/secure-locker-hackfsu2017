from twilio.rest import Client
import time

# Your Account SID from twilio.com/console
account_sid = "xxxxxxxx"
# Your Auth Token from twilio.com/console
auth_token  = "xxxxxxxx"

client = Client(account_sid, auth_token)

message = client.messages.create(
    to="+123456789", 
    from_="+123456789",
    body="An attempt was made to open your secure locker by this person https://s3.amazonaws.com/lastaccesshero/lastlockerattempt.jpg")

print(message.sid)
