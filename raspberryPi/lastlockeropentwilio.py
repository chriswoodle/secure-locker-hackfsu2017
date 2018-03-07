from twilio.rest import Client
import time

# Your Account SID from twilio.com/console
account_sid = "xxxxxx"
# Your Auth Token from twilio.com/console
auth_token  = "xxxxxx"

client = Client(account_sid, auth_token)

message = client.messages.create(
    to="+123456789", 
    from_="+123456789",
    body="Your secure locker was successfully opened by this person https://s3.amazonaws.com/lastaccesshero/lastlockeropen.jpg")

print(message.sid)
