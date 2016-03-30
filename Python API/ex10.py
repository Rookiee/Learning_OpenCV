import cv2
import numpy as np

str = '/Users/Haoyang/Downloads/Pics/'
img1 = cv2.imread(str + 'boldt.jpg')
img2 = cv2.imread(str + 'rain.jpg')

i = 0
cv2.namedWindow('a')
while (i <= 1):
    dst = cv2.addWeighted(img1,i,img2,1-i,0)
    
    cv2.imshow('a',dst)
    if cv2.waitKey (150) == ord('q'):
        break
    i = i+0.1

cv2.destroyAllWindows ()
    
