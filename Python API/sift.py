import cv2
import numpy as np

str = '/Users/Haoyang/Downloads/Pics/'

fileName = raw_input("Enter the name: ")


imgSrc = cv2.imread(str + fileName)
#imgSrc = cv2.imread('/Users/Haoyang/Downloads/Pics/building.jpg')
imgGray = cv2.cvtColor(imgSrc,cv2.COLOR_BGR2GRAY)

sift = cv2.SIFT()
# type of isft is "CV2.SIFT"

# detect the key points
kp = sift.detect(imgGray,None)

bp = kp
# get the key points and keypoint descirber
kp,des = sift.compute(imgGray,kp)

if bp!=kp:
    print 'Attention, now bp!=kp'


imgSrc = cv2.drawKeypoints(imgSrc,kp,flags = cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)

cv2.imshow('result',imgSrc)

if cv2.waitKey() == ord('q'):
    cv2.destroyAllWindows()

