import os
import sys
import urllib.request

client_id = "8uslyxxg10"
client_secret = "wMkCtzbit01E0MKRdYZWqJK1MqVcX4mahuHeWAeq"

encText = urllib.parse.quote("말씀해주세요!")
data = "speaker=nara&volume=0&speed=0&pitch=0&format=mp3&text=" + encText;
url = "https://naveropenapi.apigw.ntruss.com/tts-premium/v1/tts"
request = urllib.request.Request(url)
request.add_header("X-NCP-APIGW-API-KEY-ID",client_id)
request.add_header("X-NCP-APIGW-API-KEY",client_secret)
response = urllib.request.urlopen(request, data=data.encode('utf-8'))
rescode = response.getcode()
if(rescode==200):
    print("csr init 저장")
    response_body = response.read()
    with open('csr_init.mp3', 'wb') as f:
        f.write(response_body)
else:
    print("Error Code:" + rescode)