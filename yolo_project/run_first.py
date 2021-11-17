import os

from pathlib import Path


username = '2021s0' # 제품번호 

BASE_DIR = Path(__file__).resolve().parent.parent
Path1 = os.path.join(BASE_DIR, 'yolo_project/repository/user.txt')

with open(Path1,'w') as f:
    f.write(username)


os.environ.setdefault("DJANGO_SETTINGS_MODULE", "yolo_project.settings")

import django
django.setup()

from user.models import User
user = User.objects.create_user(
    username=username
)