import requests
import uuid
import time
import json
import os, sys
from pathlib import Path
from glob import glob
# from yolo_app import models
sys.path.append(os.path.dirname(os.path.abspath(os.path.dirname(__file__))))


import django
os.environ.setdefault("DJANGO_SETTINGS_MODULE", "seeyaproject.settings")
django.setup()
from yolo_app import models

api_url = 'https://b62167be92724f4cb5926fd2078ec880.apigw.ntruss.com/custom/v1/9935/0fdfe36acb19b35a0d18771064ccc16a45cc4d60884c16863c30723adb3380ec/general'
secret_key = 'WXBjb09lVVVVZ1l5bUhsWElTTFFwY3N3Z1VsWHdGYVk='

menu_lotte = []
Lo_c = models.Lotte_class.objects.values()
for i in range(len(Lo_c)):
  menu_lotte.append(Lo_c.filter()[i]["menu"])

def OcrResult(time_stamp):
      image_file ='/home/seeya/yolo_env/seeyaproject/repository/predicted_pictures/'+ time_stamp +'.jpg'
      
      user_read = [] 
      for_voice = []

      request_json = {
        'images': [
            {
                'format': 'jpg',
                'name': 'demo'
            }
        ],
        'requestId': str(uuid.uuid4()),
        'version': 'V2',
        'timestamp': int(round(time.time() * 1000))
      }

      payload = {'message': json.dumps(request_json).encode('UTF-8')}
      files = [
        ('file', open(image_file,'rb'))
      ]
      headers = {
        'X-OCR-SECRET': secret_key
      }

      response = requests.request("POST", api_url, headers=headers, data = payload, files = files)
      
      a = response.json()['images'][0]['fields']

      for i in range(len(a)): 
         b = a[i]['inferText']
         print(b)
         if b in menu_lotte:
            print(b)
            price = Lo_c.filter(menu = b)[0]["price"]
            for_voice.append(b)
            user_read.append(b + ' ' + price + '원')
      print(user_read,for_voice)
     
      return user_read, for_voice
