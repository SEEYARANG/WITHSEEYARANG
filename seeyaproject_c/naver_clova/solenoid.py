# $pip install jamo
# 자모음마다 dic 만들기 -> 호출

import serial
import time
from jamo import h2j, j2hcj

# Arduino 0 = 스위치 + 초음파 거리 센서 + 진동 모듈
port = '/dev/ttyACM0' # 시리얼 포트
baud = 9600 # 시리얼 보드레이트(통신속도)
arduino = serial.Serial(port,baud)


HangeulDic = {'ㄱ':1, 'ㄴ':2, 'ㄷ':3, 'ㄹ':4, 'ㅁ':5, 'ㅂ':6, 'ㅅ':7, 'ㅇ':8, 'ㅈ':9, 'ㅊ':10, 'ㅋ':11, 'ㅌ':12, 
'ㅍ':13, 'ㅎ':14, 'ㄲ':15, 'ㄸ':16, 'ㅉ':17, 'ㅃ':18, 'ㅆ':19, 'ㅏ':20, 'ㅑ':21, 'ㅓ':22, 'ㅕ':23, 'ㅗ':24, 
'ㅛ':25, 'ㅜ':26, 'ㅠ':27, 'ㅡ':28, 'ㅣ':29, 'ㅘ':30, 'ㅙ':31, 'ㅚ':32, 'ㅟ':33, 'ㅝ':34, 'ㅞ':35, 'ㅖ':36, 'ㅒ':37}

# 자모음 분리 후 아두이노로 전송
def HangeulSep(HangeulName):
    HangeulResult = j2hcj(h2j(HangeulName)) # 자모음 분리, type = str
    print(HangeulResult)
    for i in range(len(HangeulResult)):
        time.sleep(2)
        HangeulNum = HangeulDic[HangeulResult[i]]
        print(HangeulNum)
        arduino.write([HangeulNum]) # Arduino 0에 자모음 데이터 전송
        time.sleep(2.5)
    print("solenoid finish")

