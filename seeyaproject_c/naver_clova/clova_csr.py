# -*- coding: utf-8 -*- 
# $pip install SpeechRecognition
# $pip install pipwin
# $pipwin install PyAudio

import speech_recognition as sr
import sys
import os
import requests
import urllib.request
import pygame
import time

freq = 24000    # sampling rate 16000(Naver TTS), 24000(google TTS)
bitsize = -16   # signed 16 bit. support 8, -8, 16, -16
channels = 1    # 1 is mono, 2 is stereo
buffer = 2048   # number of samples (experiment to get right sound)

# Naver Clova CSR API
# 요청 = 음성 파일
# 응답 = 음성에 대한 text (type -> string)
def audio_csr(audio_file):
    client_id = "8uslyxxg10"
    client_secret = "wMkCtzbit01E0MKRdYZWqJK1MqVcX4mahuHeWAeq"
    lang = "Kor" # 언어 코드 ( Kor, Jpn, Eng, Chn )
    url = "https://naveropenapi.apigw.ntruss.com/recog/v1/stt?lang=" + lang
    data = open(audio_file, 'rb')
    headers = {
        "X-NCP-APIGW-API-KEY-ID": client_id, # 앱 등록 시 발급받은 Client ID
        "X-NCP-APIGW-API-KEY": client_secret, # 앱 등록 시 발급 받은 Client Secret
        "Content-Type": "application/octet-stream" # application/octet-stream으로 고정
    }
    response = requests.post(url, data=data, headers=headers)
    rescode = response.status_code
    if (rescode == 200):
        csr = response.text
    else:
        print("Error : " + response.text)
    
    return csr # type = str

# Speech Recognition
def get_audio():
    r = sr.Recognizer() # Recognizer()를 통해 음성인식 기술 이용 가능
    mic = sr.Microphone()
    with mic as source:
        print('say something')
        audio = r.listen(source, timeout=2)
        said = " "

    # audio file 저장
    with open('CSR.wav', 'wb') as file:
        wav_data = audio.get_wav_data()
        file.write(wav_data)

        try:
            said = r.recognize_google(audio)
            #print(said)
        except Exception as e:
            print('Exception: ' + str(e))
    
    return said

# csr init
def csr_init():
    pygame.mixer.init(freq, bitsize, channels, buffer)
    pygame.mixer.music.load("csr_init.mp3")
    pygame.mixer.music.play()

    clock = pygame.time.Clock()
    while pygame.mixer.music.get_busy():
        clock.tick(30)
    pygame.mixer.quit()


