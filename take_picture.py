
from cv2 import *
import time
# initialize the camera
cam = VideoCapture(0)   # 0 -> index of camera
time.sleep(0.15)
s, img = cam.read()
if s:    # frame captured without any errors
    imwrite("filename.jpg",img) #save image



"""
from SimpleCV import Image, Camera

cam = Camera()
img = cam.getImage()
img.save("capture.jpg")
"""
