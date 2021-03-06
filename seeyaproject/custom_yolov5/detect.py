"""Run inference with a YOLOv5 model on images, videos, directories, streams

Usage:
    $ python3 detect.py --source /home/seeya/download (1).jpeg --weights yolov5s.pt --img 416 --device cpu
"""

import argparse
import os
import sys
import time
from pathlib import Path
import os
import cv2
import torch
import torch.backends.cudnn as cudnn
import django
os.environ.setdefault("DJANGO_SETTINGS_MODULE", "seeyaproject.settings")
django.setup()

#################################### save image path ####################################
FILE = Path(__file__).absolute()
sys.path.append(FILE.parents[0].as_posix())  # add yolov5/ to path

BASE_DIR = Path(__file__).resolve().parent.parent
Path1 = os.path.join(BASE_DIR, 'repository')
Path2 = os.path.join(Path1,'predicted_pictures')

Path_for_web0 = os.path.join(BASE_DIR, 'foruser')
Path_for_web1 = os.path.join(Path_for_web0, 'static')
Path_for_web2 = os.path.join(Path_for_web1, 'repository')
Path_for_web3 = os.path.join(Path_for_web2, 'predicted')

'''from naver_clova import reset_folder
reset_folder.reset_folder(Path2, '.jpg')'''

from models.experimental import attempt_load
from utils.datasets import LoadStreams, LoadImages
from utils.general import check_img_size, check_requirements, check_imshow, colorstr, non_max_suppression, \
    apply_classifier, scale_coords, xyxy2xywh, strip_optimizer, set_logging, increment_path, save_one_box
from utils.plots import colors
from utils.torch_utils import select_device, load_classifier, time_sync

#################################### tts, ocr, csr ####################################
from naver_clova import Gtts
from naver_clova import clova_voice
from naver_clova import clova_ocr
from naver_clova import clova_csr
from yolo_app import models
from naver_clova import solenoid

class_value = models.TTSname.objects.values()
class_info = models.Info.objects.values()

#################################### GPIO ####################################
import Jetson.GPIO as GPIO 
import time

but1 = 12
but2 = 13
but3 = 16
but4 = 18
but5 = 22

GPIO.setmode(GPIO.BOARD)
GPIO.setup(but1, GPIO.IN)   #??????1, GPIO PIN 12                 
GPIO.setup(but2, GPIO.IN)   #??????2, GPIO PIN 13    
GPIO.setup(but3, GPIO.IN)   #??????3, GPIO PIN 16    
GPIO.setup(but4, GPIO.IN)   #??????4, GPIO PIN 18    
GPIO.setup(but5, GPIO.IN)   #??????5, GPIO PIN 22

#################################### Arduino ####################################
import serial
import time

port = '/dev/ttyACM0' # serial port
baud = 9600 # serial boardrate
arduino = serial.Serial(port,baud)

#################################### user ####################################
from user.get_user import user_name
from user.models import User
now_user = User.objects.get(id = user_name())

@torch.no_grad()
def run(weights='best.pt',  # model.pt path(s)
        source='',  # file/dir/URL/glob, 0 for webcam
        imgsz=416,  # inference size (pixels)
        conf_thres=0.25,  # confidence threshold
        iou_thres=0.45,  # NMS IOU threshold
        max_det=1000,  # maximum detections per image
        device='',  # cuda device, i.e. 0 or 0,1,2,3 or cpu
        view_img=False,  # show results
        save_txt=False,  # save results to *.txt
        save_conf=False,  # save confidences in --save-txt labels
        save_crop=False,  # save cropped prediction boxes
        nosave=False,  # do not save images/videos
        classes=None,  # filter by class: --class 0, or --class 0 2 3
        agnostic_nms=False,  # class-agnostic NMS
        augment=False,  # augmented inference
        visualize=False,  # visualize features
        update=False,  # update all models
        project='runs/detect',  # save results to project/name
        name='exp',  # save results to project/name
        exist_ok=False,  # existing project/name ok, do not increment
        line_thickness=3,  # bounding box thickness (pixels)
        hide_labels=False,  # hide labels
        hide_conf=False,  # hide confidences
        half=False,  # use FP16 half-precision inference
        ):
    save_img = not nosave and not source.endswith('.txt')  # save inference images
    webcam = source.isnumeric() or source.endswith('.txt') or source.lower().startswith(
        ('rtsp://', 'rtmp://', 'http://', 'https://'))
    

    # Directories
    save_dir = increment_path(Path(project) / name, exist_ok=exist_ok)  # increment run
    (save_dir / 'labels' if save_txt else save_dir).mkdir(parents=True, exist_ok=True)  # make dir

    # Initialize
    set_logging()
    device = select_device(device)
    half &= device.type != 'cpu'  # half precision only supported on CUDA

    # Load model
    w = weights[0] if isinstance(weights, list) else weights
    classify, pt, onnx = False, w.endswith('.pt'), w.endswith('.onnx')  # inference type
    stride, names = 64, [f'class{i}' for i in range(1000)]  # assign defaults
    if pt:
        model = attempt_load(weights, map_location=device)  # load FP32 model
        stride = int(model.stride.max())  # model stride
        names = model.module.names if hasattr(model, 'module') else model.names  # get class names
        if half:
            model.half()  # to FP16
        if classify:  # second-stage classifier
            modelc = load_classifier(name='resnet50', n=2)  # initialize
            modelc.load_state_dict(torch.load('resnet50.pt', map_location=device)['model']).to(device).eval()
    elif onnx:
        check_requirements(('onnx', 'onnxruntime'))
        import onnxruntime
        session = onnxruntime.InferenceSession(w, None)
    imgsz = check_img_size(imgsz, s=stride)  # check image size

    # Dataloader
    if webcam:
        view_img = check_imshow()
        cudnn.benchmark = True  # set True to speed up constant image size inference
        dataset = LoadStreams(source, img_size=imgsz, stride=stride)
        bs = len(dataset)  # batch_size
    else:
        dataset = LoadImages(source, img_size=imgsz, stride=stride)
        bs = 1  # batch_size
    vid_path, vid_writer = [None] * bs, [None] * bs

    # Run inference
    if pt and device.type != 'cpu':
        model(torch.zeros(1, 3, imgsz, imgsz).to(device).type_as(next(model.parameters())))  # run once
    t0 = time.time()
    for path, img, im0s, vid_cap in dataset:
        if pt:
            img = torch.from_numpy(img).to(device)
            img = img.half() if half else img.float()  # uint8 to fp16/32
        elif onnx:
            img = img.astype('float32')
        img /= 255.0  # 0 - 255 to 0.0 - 1.0
        if len(img.shape) == 3:
            img = img[None]  # expand for batch dim

        # Inference
        t1 = time_sync()
        if pt:
            visualize = increment_path(save_dir / Path(path).stem, mkdir=True) if visualize else False
            pred = model(img, augment=augment, visualize=visualize)[0]
        elif onnx:
            pred = torch.tensor(session.run([session.get_outputs()[0].name], {session.get_inputs()[0].name: img}))

        # NMS
        pred = non_max_suppression(pred, conf_thres, iou_thres, classes, agnostic_nms, max_det=max_det)
        t2 = time_sync()

        # Second-stage classifier (optional)
        if classify:
            pred = apply_classifier(pred, modelc, img, im0s)
        
        # Process predictions
        for i, det in enumerate(pred):  # detections per image
            if webcam:  # batch_size >= 1
                p, s, im0, frame = path[i], f'{i}: ', im0s[i].copy(), dataset.count
            else:
                p, s, im0, frame = path, '', im0s.copy(), getattr(dataset, 'frame', 0)

#################################### 1. clova_csr ####################################
            result_csr = ''  
            but1_value = GPIO.input(but1)          
            if but1_value == 0: # clova csr 
                print("but1 press")
                print('start csr')
                clova_csr.csr_init() # csr init ??????
                clova_csr.get_audio() # audio file ??????
                result_csr = clova_csr.audio_csr("CSR.wav") # Naver Clova CSR
                print(result_csr)
            
#################################### 3. clova_ocr ####################################
            time_stamp2 = str(int(time.time()))
            Path3 = os.path.join(Path2, time_stamp2 + '.jpg')
            Path_for_web = os.path.join(Path_for_web3, time_stamp2 + '.jpg')
            cv2.imwrite(Path3, im0)

            but3_value = GPIO.input(but3)
            if (but3_value == 0) or (result_csr == '{"text":"?????? ?????????"}'): # ???????????? ocr ??????
                print("but3 press")
                user_read, for_voice = clova_ocr.OcrResult(time_stamp2)

                if user_read == []:
                    clova_voice.Clova_info("????????? ???????????? ???????????????.")
                    ocr_name = []
                    result_csr = ''
                else:
                    clova_voice.Clova_ocrread(user_read) #clova_voice
                    ocr_name = for_voice
                               
                    cv2.imwrite(Path_for_web, im0)
                            
                    post = models.PredictedResult.objects.all()
                    img_path = 'repository/predicted/' + time_stamp2 + '.jpg'
                    post.create(user= now_user, type = 'OCR', prediction = ocr_name, img_path = img_path)
                    result_csr = ''; save_ob_name = ''
        
#################################### 5. info ####################################
            but5_value = GPIO.input(but5)
            if (but5_value == 0) or (result_csr == '{"text":"?????? ?????????"}'): # info ??????
                print("but5 press")
                if len(ocr_name) != 0: # ocr??? ?????? info ??????
                    for i in ocr_name:
                        info = class_info.filter(name = i)[0]["information"]
                        clova_voice.Clova_info(info)
                        print(info)
                    ocr_name = []; result_csr = ''; save_ob_name = ''
                    

            p = Path(p)  # to Path
            save_path = str(save_dir / p.name)  # img.jpg
            txt_path = str(save_dir / 'labels' / p.stem) + ('' if dataset.mode == 'image' else f'_{frame}')  # img.txt
            s += '%gx%g ' % img.shape[2:]  # print string
            gn = torch.tensor(im0.shape)[[1, 0, 1, 0]]  # normalization gain whwh
            imc = im0.copy() if save_crop else im0  # for save_crop

            if len(det):
                # Rescale boxes from img_size to im0 size
                det[:, :4] = scale_coords(img.shape[2:], det[:, :4], im0.shape).round()

                # Print results
                for c in det[:, -1].unique():
                    n = (det[:, -1] == c).sum()  # detections per class
                    s += f"{n} {names[int(c)]}{'s' * (n > 1)}, "  # add to string
                


                # Write results
                for *xyxy, conf, cls in reversed(det):


                    if save_txt:  # Write to file
                        xywh = (xyxy2xywh(torch.tensor(xyxy).view(1, 4)) / gn).view(-1).tolist()  # normalized xywh
                        line = (cls, *xywh, conf) if save_conf else (cls, *xywh)  # label format
                        with open(txt_path + '.txt', 'a') as f:
                            f.write(('%g ' * len(line)).rstrip() % line + '\n')

                    if save_img or save_crop or view_img:  # Add bbox to image
                        c = int(cls)  # integer class
                        label = None if hide_labels else (names[c] if hide_conf else f'{names[c]} {conf:.2f}')
                        #plot_one_box(xyxy, im0, label=label, color=colors(c, True))#, line_thickness=line_thickness)

#################################### add code ###########################################################################
                        
                        object_name = names[int(cls)] # list?????? ????????? ?????? ?????? 
                        original_img = im0 # original image
                        
                        x1 = int(xyxy[0].item())
                        y1 = int(xyxy[1].item())
                        x2 = int(xyxy[2].item())
                        y2 = int(xyxy[3].item())
                     
                        if (x1 <= 640/2 <= x2) and (y1 <= 480/2 <= y2) : # central object ??? ?????? 

                            print('detected object name = ', object_name)

#################################### 2. object name ####################################
                            but2_value = GPIO.input(but2)
                            if (but2_value == 0) or (result_csr == '{"text":"?????? ??????"}') or (result_csr == '{"text":"?????? ??????"}'): # yolo ????????? ??????
                                print("but2 press")
                                save_ob_name = object_name
                                clova_voice.TTS_mp3(object_name) # clova_voice
                                cv2.imwrite(Path_for_web, im0)
                                TTS_name = class_value.filter(class_name = object_name)[0]["TTS_name"]
                                print(TTS_name)
                                post = models.PredictedResult.objects.all()
                                img_path = 'repository/predicted/'+time_stamp2 + '.jpg'
                                post.create(user= now_user, type = 'YOLO', prediction = TTS_name, img_path = img_path)
                                ocr_name = []; result_csr = ''

#################################### 5. info ####################################
                            if (but5_value == 0) or (result_csr == '{"text":"?????? ?????????"}'): # info ??????
                                print("but5 press")
                                clova_voice.Info_mp3(save_ob_name) #clova_voice
                                ocr_name = []; result_csr = ''
                                save_ob_name = ''

#################################### 4. solenoid ####################################
                            but4_value = GPIO.input(but4)
                            if (but4_value == 0) or (result_csr == '{"text":"?????? ????????? ?????????"}'): # ???????????????
                                print("but4 press")
                                TTS_name = class_value.filter(class_name = object_name)[0]["TTS_name"]
                                print(TTS_name) # object name ??????
                                solenoid.HangeulSep(TTS_name) # ????????? ??????????????? ??????
                                ocr_name = []; result_csr = ''

############################################## end ##############################################################
                        

            # Print time (inference + NMS)
            print(f'{s}Done. ({t2 - t1:.3f}s)')

            # Stream results
            if view_img:
                cv2.imshow(str(p), im0) # ???(Window)??? ????????? image ??????
                if cv2.waitKey(1) == ord('q'):  # q to quit, 0.001????????? ????????? ?????? ?????????
                        raise StopIteration

    if update:
        strip_optimizer(weights)  # update model (to fix SourceChangeWarning)

    print(f'Done. ({time.time() - t0:.3f}s)')
