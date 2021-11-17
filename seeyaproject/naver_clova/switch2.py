import Jetson.GPIO as GPIO 
import time

but1= 12
but2= 13
but3= 16
but4= 18
but5= 22

GPIO.setmode(GPIO.BOARD)
GPIO.setup(but1, GPIO.IN)   #버튼1, GPIO PIN 12                 
GPIO.setup(but2, GPIO.IN)   #버튼2, GPIO PIN 13    
GPIO.setup(but3, GPIO.IN)   #버튼3, GPIO PIN 16    
GPIO.setup(but4, GPIO.IN)   #버튼4, GPIO PIN 18    
GPIO.setup(but5, GPIO.IN)   #버튼5, GPIO PIN 22    

try:
    while True:
        but1_value = GPIO.input(but1)
        if but1_value == 0:
            print("but1 press")

        but2_value = GPIO.input(but2)
        if but2_value == 0:
            print("but2 press")

        but3_value = GPIO.input(but3)
        if but3_value == 0:
            print("but3 press")

        but4_value = GPIO.input(but4)
        if but4_value == 0:
            print("but4 press")

        but5_value = GPIO.input(but5)
        if but5_value == 0:
            print("but5 press")


except KeyboardInterrupt:                  # Ctrl-C 입력 시
    GPIO.cleanup()                         # GPIO 관련설정 Clear
    print("gpio bye~")
