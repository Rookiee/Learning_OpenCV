import cv2
import numpy as np
from matplotlib import pyplot as plt

str = '/Users/Haoyang/Downloads/Pics/'
imgSrc = cv2.imread(str + 'church01.jpg',0)
imgTar = cv2.imread(str + 'church02.jpg',0)


# initiate SIFT detector
orb = cv2.ORB()

# find the keypoints and descriptors with SIFT
kp1,des1 = orb.detectAndCompute(imgSrc,None)
kp2,des2 = orb.detectAndCompute(imgTar,None)

# create BFMatcher object
bf = cv2.BFMatcher(cv2.NORM_HAMMING,crossCheck=True)

# match descriptors
matches = bf.match(des1,des2)

# sort them in the order of their distances
matches = sorted(matches,key=lambda x:x.distance)

out = cv2.darwMatches(imgSrc,kp1,imgTar,kp2,matches[:10])
