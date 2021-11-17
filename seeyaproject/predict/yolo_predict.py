import os, sys
from pathlib import Path
from glob import glob
sys.path.append(os.path.dirname(os.path.abspath(os.path.dirname(__file__))))

from yolov5 import detect

BASE_DIR = Path(__file__).resolve().parent.parent
ImgPath1 = os.path.join(BASE_DIR, 'repository')
ImgPath2 = os.path.join(ImgPath1, 'predicted_pictures')
Img_list = glob(ImgPath2 + '/*')


os.environ.setdefault("DJANGO_SETTINGS_MODULE", "seeyaproject.settings")

from django.core.wsgi import get_wsgi_application
application = get_wsgi_application()

def predict():
    a = detect.run(
                weights='/home/seeya/yolo_env/yolo_project/best.pt',  # model.pt path(s)
                source='0',  # file/dir/URL/glob, 0 for webcam
                imgsz=416,  # inference size (pixels)
                conf_thres=0.25,  # confidence threshold
                iou_thres=0.45,
                save_txt=False,
                device=''
    )

    return a 

if __name__ == '__main__': 
    predict()

