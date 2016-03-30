import cv2
import numpy as np
from matplotlib import pyplot as plt

str = '/Users/Haoyang/Downloads/Pics/'

img = cv2.imread(str + 'mario.png')
imgGray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
template = cv2.imread(str + 'marioCoin.png',0)

w,h = template.shape[::-1]

res = cv2.matchTemplate(imgGray,template,cv2.TM_CCOEFF_NORMED)
threshold = 0.8

# numpy.where(condition[,x,y])
# return elements, either from x or y, depending on condition.
# if only condition is given is given, return condition.nonzero()

loc = np.where( res >= threshold)
for pt in zip(*loc[::-1]):
    cv2.rectangle(img,pt,(pt[0]+w,pt[1]+h),(255,0,0),1)

cv2.imshow('a',img)
