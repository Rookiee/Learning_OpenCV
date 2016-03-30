import cv2
import numpy as np
from matplotlib import pyplot as plt

fileName = raw_input("Input the fileName: ")
str = "/Users/Haoyang/Downloads/Pics/"

imgSrc = cv2.imread(str + fileName)
mask = np.zeros(imgSrc.shape[:2],np.uint8)

bgdModel = np.zeros((1,65),np.float64)
fgdModel = np.zeros((1,65),np.float64)

rect = (50,50,450,290)
'''
cv2.grabCut(imgSrc,mask,rect,bgdModel,fgdModel,5,cv2.GC_INIT_WITH_RECT)

mask2 = np.where((mask==2)|(mask==0),0,1).astype('uint8')

imgSrc = imgSrc*mask2[:,:,np.newaxis]
'''


newmask = cv2.imread(str+'newmask1.jpg',0)
mask[newmask==0] = 0
mask[newmask==255] = 1
cv2.grabCut(imgSrc,mask,None,bgdModel,fgdModel,cv2.GC_INIT_WITH_MASK)
mask = np.where((mask==2)|(mask==0),0,1).astype('uint8')
imgSrc = imgSrc*mask[:,:,np.newaxis]
imgSrc = cv2.cvtColor(imgSrc,cv2.COLOR_BGR2RGB)
plt.imshow(imgSrc),plt.colorbar(),plt.show()
