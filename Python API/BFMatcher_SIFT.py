import cv2
import numpy as np
from matplotlib import pyplot as plt

imgSrc = cv2.imread('/Users/Haoyang/Downloads/Pics/church01.jpg',0)
imgTar = cv2.imread('/Users/Haoyang/Downloads/Pics/church02.jpg',0)

sift = cv2.SIFT()

kp1,des1 = sift.detectAndCompute(imgSrc,None)
kp2,des2 = sift.detectAndCompute(imgTar,None)

bf = cv2.BFMatcher()
matches = bf.knnMatch(des1,des2,k=2)

#
#

good = []
for m,n in matches:
    if m.distance <0.75*n.distance:
        good.append([m])

img3 = cv2.drawMatchesKnn(imgSrc,pk1,imgTar,kp2,good[:10],flags = 2)

plt.imshow(img3),plt.show()
