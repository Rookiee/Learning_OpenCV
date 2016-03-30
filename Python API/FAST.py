import cv2
import numpy as np
from matplotlib import pyplot as plt

str = "/Users/Haoyang/Downloads/Pics/"
fileName = raw_input("Enter the photo: ")

imgSrc = cv2.imread(str + fileName)
imgCopy = imgSrc.copy()

imgGray = cv2.cvtColor(imgCopy,cv2.COLOR_BGR2GRAY)

fast = cv2.FastFeatureDetector()

#find and draw the keypoints

kp = fast.detect(imgGray)
#imgKey = cv2.drawKeyPoints(imgCopy,kp,color = [0,255,255])
imgKey = cv2.drawKeypoints(imgCopy,kp,None,[0,255,255])
         
#print all default parameters
print 'THreshold: ',fast.getInt('threshold')
print 'nonmaxSuppression: ',fast.getBool('nonmaxSuppression')
#print 'neighborhood: ',fast.getInt('type')
print 'Total Keypoints with nonmaxSuppression: ',len(kp)

cv2.imshow('fastTure',imgKey)

#Disable nonmaxSuppression
fast.setBool('nonmaxSuppression',0)
kp = fast.detect(imgCopy,None)
print 'Total keypoint without nonmaxSuppression: ',len(kp)
imgWithoutNon = cv2.drawKeypoints(imgCopy,kp,color = [255,0,0])
cv2.imshow('without nonmax',imgWithoutNon)

if cv2.waitKey() == ord('q'):
    cv2.destroyAllWindows()
