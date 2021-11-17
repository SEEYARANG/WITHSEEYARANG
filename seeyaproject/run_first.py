import os
os.environ.setdefault("DJANGO_SETTINGS_MODULE", "seeyaproject.settings")

import django
django.setup()

from user.models import User
from pathlib import Path


username = '2021_0'#제품번호 
user = User.objects.create_user(
    username=username,
    password = str(int(username)+100)
)

BASE_DIR = Path(__file__).resolve().parent.parent
Path1 = os.path.join(BASE_DIR, 'seeyaproject/repository/user.txt')

with open(Path1,'w') as f:
    name = User.objects.values().filter(username=username)[0]
    f.write(str(name['id'])+'\n'+str(name['username']))
