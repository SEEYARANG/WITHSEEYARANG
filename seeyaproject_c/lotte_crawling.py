import requests
from bs4 import BeautifulSoup as bs
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time
import os
import urllib.request
import requests
import os
BASE_DIR = os.path.dirname(os.path.abspath(__file__))

import django
os.environ.setdefault("DJANGO_SETTINGS_MODULE", "yolo_project.settings")
django.setup()

from yolo_app import models
from user.get_user import user_name
from user.models import User
now_user = User.objects.get(username=user_name())

LOTTE_MENU_ALL = "http://www.lotteria.com/menu/Menu_All.asp"
driver = webdriver.Chrome('./chromedriver.exe')

Lo_i = models.Info.objects.all()
Lo_c = models.Lotte_class.objects.all()

def sleep(factor=1):
    pause_time = 1 * factor
    time.sleep(pause_time)

def lotte():
    driver.get(LOTTE_MENU_ALL)
    a=[10,12,14,16,18]
    for i in a:
        print(i)
        for j in range(1,25):
            print(j)
            try:
                name = driver.find_element_by_css_selector('#frmNavi > div:nth-child('+ str(i)+') > ul > li:nth-child('+ str(j)+') > div.bx_flex.menuRoundWrap > div > a')
                menu_name = name.text
                name.send_keys(Keys.ENTER)
                sleep(2)
                price = driver.find_element_by_css_selector('#frmNavi > div.bx_flex.bx_detail > div.cont.detail.roundArea > div.info > div > strong')
                menu_price = price.text
                print(price.text)
                item = driver.find_element_by_css_selector('#frmNavi > div.bx_flex.bx_detail > div.cont.detail.roundArea > div.info > p')
                menu_info = item.text.split('\n')[0]
                cal = driver.find_element_by_css_selector('#frmNavi > div.bx_flex.bx_detail > div.cont.detail.roundArea > div.info > div > span')
                menu_cal = cal.text 
                information = menu_name + ' 은 ' + menu_info + '이고 ' + menu_cal + ' 입니다'
                print(information)
                Lo_c.create(menu = menu_name, price = menu_price)
                Lo_i.create(user= now_user, ype = '롯데리아', name = menu_name, information = information)
                driver.back()
                sleep(2)
            except:
                break
        sleep(5)


if __name__ == '__main__':
    lotte()