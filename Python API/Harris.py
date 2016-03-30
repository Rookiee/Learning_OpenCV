import cv2
import numpy as np

str = "/Users/Haoyang/Downloads/Pics/"
fileName = raw_input("Enter the file name: ")

imgSrc = cv2.imread(str + fileName)
imgGray = cv2.cvtColor(imgSrc,cv2.COLOR_BGR2GRAY)
imgGray = np.float32(imgGray)

# the imput image must be float32,
# and the last parameter must be between 0.04 and 0.06
dst = cv2.cornerHarris(imgGray,2,3,0.04)

#result is dilated for marking the corners, not important
dst = cv2.dilate(dst,None)

# Threshold for an optimal value, it may vary depending on the image
imgSrc[dst > 0.01*dst.max()] = [255,255,0]

cv2.imshow('dst',imgSrc)

if cv2.waitKey() ==ord('q'):
    cv2.destroyAllWindows()
    




