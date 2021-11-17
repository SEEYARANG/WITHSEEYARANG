import Jetson.GPIO as GPIO 

GPIO.setmode(GPIO.BCM)                     # GPIO 이름은 BCM 명칭 사용
      
but1= 18
but2= 27
but3= 23
but4= 24
but5= 25

GPIO.setup(but1, GPIO.IN)   #버튼1, GPIO PIN 12                 
GPIO.setup(but2, GPIO.IN)   #버튼2, GPIO PIN 13    
GPIO.setup(but3, GPIO.IN)   #버튼3, GPIO PIN 16    
GPIO.setup(but4, GPIO.IN)   #버튼4, GPIO PIN 18    
GPIO.setup(but5, GPIO.IN)   #버튼5, GPIO PIN 22    

prev_value = 0

try:
   while True:
      but1_value = GPIO.input(but1)
      print(GPIO.input(but1))
      #if but1_value != prev_value:
         #for i in range(100):
            #print(i)

      #but2_value = GPIO.input(but2)
      #print(but2_value)
      #if but2_value != prev_value:
        # print(2)

      #but3_value = GPIO.input(but3)
      #print(but3_value)
      #if but3_value != prev_value:
        # print(3)

      #but4_value = GPIO.input(but4)
      #print(but4_value)
      #if but4_value != prev_value:
        # print(4)

      #but5_value = GPIO.input(but5)
      #print(but5_value)
      #if but5_value != prev_value:
        # print(5)


except KeyboardInterrupt:                  # Ctrl-C 입력 시
    GPIO.cleanup()                         # GPIO 관련설정 Clear
    print("bye~")
