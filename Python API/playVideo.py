import numpy as np
import cv2

cap = cv2.VideoCapture ('/Users/Haoyang/Downloads/Pics/bike.avi')

while(True):
    ret,frame = cap.read()
    if(cap.isOpened()):
        print 'ok'

    cv2.imshow('frame',frame)
    if cv2.waitKey(25) == ord('q'):
        break;

cap.release()
cv2.destroyAllWindows ()
