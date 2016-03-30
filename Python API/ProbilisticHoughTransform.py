import cv2
import numpy as np

str = "/Users/Haoyang/Downloads/Pics/"

imgSrc = cv2.imread(str+'road.jpg')
imgGray = cv2.cvtColor(imgSrc,cv2.COLOR_BGR2GRAY)
contours = cv2.Canny(imgGray,128,300,apertureSize = 3)
#rec,contours = cv2.threshold(contours,127,255,cv2.THRESH_BINARY_INV)

minLineLength = 80
maxLineGap = 10

lines = cv2.HoughLinesP(contours,1,np.pi/180,80,minLineLength,maxLineGap)

for x1,y1,x2,y2 in lines[0]:
    cv2.line(imgSrc,(x1,y1),(x2,y2),(255,255,0),1)

cv2.imshow('a',imgSrc)
