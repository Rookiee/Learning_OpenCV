import cv2
import numpy as np
from matplotlib import pyplot as plt
img = cv2.imread('/Users/Haoyang/Downloads/Pics/building.jpg',0)

orb = cv2.ORB()

kp = orb.detect(img,None)
kp,des = orb.compute(img,kp)

img2 = cv2.drawKeypoints(img,kp,color = [255,255,0],flags = 0)

plt.imshow(img2);plt.show()
