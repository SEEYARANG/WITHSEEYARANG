from gtts import gTTS
from pygame import mixer
import time

def detect_gTTS(real_name):
              print('{0}입니다'.format(real_name))
              tts = gTTS(text = '{0}입니다'.format(real_name), lang = 'ko', slow = False)
              tts.save('detectTTS.mp3') 
              mixer.init()
              mixer.music.load('detectTTS.mp3')
              mixer.music.play()
              time.sleep(3)
              mixer.music.stop()
              mixer.quit()
