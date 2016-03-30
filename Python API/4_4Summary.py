import numpy as np
import cv2

img = cv2.imread("/Users/Haoyang/Downloads/Pics/boldt.jpg",0)
cv2.namedWindow('Image')
cv2.imshow("Image",img)

k = cv2.waitKey(0)

if k == 27:
    cv2.destroyAllWindows()
elif k == ord('s'):
    cv2.imwrite("/Users/Haoyang/Downloads/Pics/BoldPython.jpg",img)
    
