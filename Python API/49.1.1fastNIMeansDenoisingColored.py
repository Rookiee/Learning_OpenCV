# -*- coding: utf-8 -*-

import numpy as np
import cv2
import matplotlib.pyplot as plt

img = cv2.imread('/Users/Haoyang/Downloads/Pics/die.png')

dst = cv2.fastNlMeansDenoisingColored(img,None,10,10,7,21)

img = cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
dst = cv2.cvtColor(dst,cv2.COLOR_BGR2RGB)

plt.subplot(121), plt.imshow(img)
plt.subplot(122), plt.imshow(dst)

plt.show()
