import cv2
import numpy as np
from matplotlib import pyplot as plt

str = '/Users/Haoyang/Downloads/Pics/'
fileName = raw_input("Enter the file name: ")

imgSrc = cv2.imread(str + fileName);

imgGray = cv2.cvtColor(imgSrc,cv2.COLOR_BGR2GRAY)

imgGray = np.float32(imgGray)

# 
corners = cv2.goodFeaturesToTrack(imgGray,25,0.01,40)

corners = np.int0(corners)

for i in corners:
    x,y = i.ravel()
    cv2.circle(imgSrc,(x,y),3,[0,255,255],-1)

cv2.imshow('a',imgSrc)
if cv2.waitKey(0) == ord('q'):
    cv2.destroyAllWindows()

