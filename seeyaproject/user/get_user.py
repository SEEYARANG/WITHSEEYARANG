import os
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent.parent
Path1 = os.path.join(BASE_DIR, 'repository/user.txt')

def user_name():
    with open(Path1,'r') as f:
        user = f.readline()

    return user