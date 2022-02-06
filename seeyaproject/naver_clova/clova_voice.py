import os
import sys
import urllib.request
import pygame
import time

freq = 24000    # sampling rate 16000(Naver TTS), 24000(google TTS)
bitsize = -16   # signed 16 bit. support 8, -8, 16, -16
channels = 1    # 1 is mono, 2 is stereo
buffer = 2048   # number of samples (experiment to get right sound)

def ClovaTTS(real_name):
    client_id = "8uslyxxg10"
    client_secret = "wMkCtzbit01E0MKRdYZWqJK1MqVcX4mahuHeWAeq"

    print('{0}입니다'.format(real_name))
    encText = urllib.parse.quote('{0}입니다'.format(real_name))
    data = "speaker=nara&volume=0&speed=0&pitch=0&format=mp3&text=" + encText;
    url = "https://naveropenapi.apigw.ntruss.com/tts-premium/v1/tts"
    request = urllib.request.Request(url)
    request.add_header("X-NCP-APIGW-API-KEY-ID",client_id)
    request.add_header("X-NCP-APIGW-API-KEY",client_secret)
    response = urllib.request.urlopen(request, data=data.encode('utf-8'))
    rescode = response.getcode()

    if(rescode==200):
        response_body = response.read()
        with open('tts.mp3', 'wb') as f:
            f.write(response_body)
    else:
        print("Error Code:" + rescode)

    pygame.mixer.init(freq, bitsize, channels, buffer)
    pygame.mixer.music.load("tts.mp3")
    pygame.mixer.music.play()

    clock = pygame.time.Clock()
    while pygame.mixer.music.get_busy():
        clock.tick(30)
    pygame.mixer.quit()  



def Clova_info(information):
    client_id = "8uslyxxg10"
    client_secret = "wMkCtzbit01E0MKRdYZWqJK1MqVcX4mahuHeWAeq"

    encText = urllib.parse.quote('{0}'.format(information))
    data = "speaker=nara&volume=0&speed=0&pitch=0&format=mp3&text=" + encText;
    url = "https://naveropenapi.apigw.ntruss.com/tts-premium/v1/tts"
    request = urllib.request.Request(url)
    request.add_header("X-NCP-APIGW-API-KEY-ID",client_id)
    request.add_header("X-NCP-APIGW-API-KEY",client_secret)
    response = urllib.request.urlopen(request, data=data.encode('utf-8'))
    rescode = response.getcode()

    if(rescode==200):
        response_body = response.read()
        with open('info.mp3', 'wb') as f:
            f.write(response_body)
    else:
        print("Error Code:" + rescode)

    pygame.mixer.init(freq, bitsize, channels, buffer)
    pygame.mixer.music.load("info.mp3")
    pygame.mixer.music.play()

    clock = pygame.time.Clock()
    while pygame.mixer.music.get_busy():
        clock.tick(30)
    pygame.mixer.quit() 



def Clova_ocrread(user_read):
    client_id = "8uslyxxg10"
    client_secret = "wMkCtzbit01E0MKRdYZWqJK1MqVcX4mahuHeWAeq"
    s=''
    for i in user_read:
       s=s + i+' '

    encText = urllib.parse.quote('{0}입니다'.format(s))
    data = "speaker=nara&volume=0&speed=0&pitch=0&format=mp3&text=" + encText;
    url = "https://naveropenapi.apigw.ntruss.com/tts-premium/v1/tts"
    request = urllib.request.Request(url)
    request.add_header("X-NCP-APIGW-API-KEY-ID",client_id)
    request.add_header("X-NCP-APIGW-API-KEY",client_secret)
    response = urllib.request.urlopen(request, data=data.encode('utf-8'))
    rescode = response.getcode()

    if(rescode==200):
        response_body = response.read()
        with open('user_read.mp3', 'wb') as f:
            f.write(response_body)
    else:
        print("Error Code:" + rescode)

    pygame.mixer.init(freq, bitsize, channels, buffer)
    pygame.mixer.music.load("user_read.mp3")
    pygame.mixer.music.play()

    clock = pygame.time.Clock()
    while pygame.mixer.music.get_busy():
        clock.tick(30)
    pygame.mixer.quit() 



def TTS_mp3(object):
    pygame.mixer.init(freq, bitsize, channels, buffer)
    mp3_file = object + '_TTS.mp3'
    pygame.mixer.music.load(mp3_file)
    pygame.mixer.music.play()

    clock = pygame.time.Clock()
    while pygame.mixer.music.get_busy():
        clock.tick(30)
    pygame.mixer.quit() 



def Info_mp3(object):
    pygame.mixer.init(freq, bitsize, channels, buffer)
    mp3_file = object + '_info.mp3'
    pygame.mixer.music.load(mp3_file)
    pygame.mixer.music.play()

    clock = pygame.time.Clock()
    while pygame.mixer.music.get_busy():
        clock.tick(30)
    pygame.mixer.quit()



def csr_init(): # -> 말씀해주세요
    pygame.mixer.init(freq, bitsize, channels, buffer)
    pygame.mixer.music.load('csr_init.mp3')
    pygame.mixer.music.play()

    clock = pygame.time.Clock()
    while pygame.mixer.music.get_busy():
        clock.tick(30)
    pygame.mixer.quit() 
