# coding: utf-8

import cv2
import numpy as np
import matplotlib.pyplot as plt

srcImage = cv2.imread('/Users/Haoyang/Downloads/Pics/boldt.jpg')
# 因为要在matplotlib中显示，进行颜色空间转换
srcImage = cv2.cvtColor(srcImage, cv2.COLOR_BGR2RGB)

# cv2.imshow('srcImage', srcImage)

# 图像腐蚀 1.5.2
element = cv2.getStructuringElement(cv2.MORPH_RECT, (15, 15))
erodeImage = np.zeros(srcImage.shape, np.uint8)
erodeImage = cv2.erode(srcImage, element)
# cv2.imshow('erode', erodeImage)

# 图像模糊 1.5.3
blurImage = np.ones(srcImage.shape, np.uint8)
blurImage = cv2.blur(srcImage, (7, 7))
# cv2.imshow('blur', blurImage)

# canny边缘检测 1.5.4
# 第一步：载入图像
# 第二步：灰度图像
# 第三步：用blur模糊降噪
# 第四步：canny边缘化
cannyImage = np.zeros(srcImage.shape, np.uint8)
grayImage = cv2.cvtColor(srcImage, cv2.COLOR_BGR2GRAY)
bluredImage = cv2.blur(grayImage, (3, 3))
# cannyImage = cv2.Canny(blurImage, 100, 200, 3)
cannyImage = cv2.Canny(bluredImage, 80, 200, 3)
# cv2.imshow('canny', cannyImage)

# 下面使用matplotlib显示上面的4福图像(包括原图)

plt.subplot(221), plt.imshow(srcImage), plt.title('srcImage')
plt.xticks([]), plt.yticks([])
plt.subplot(222), plt.imshow(erodeImage), plt.title('erode')
plt.xticks([]), plt.yticks([])
plt.subplot(223), plt.imshow(blurImage), plt.title('blur')
plt.xticks([]), plt.yticks([])
plt.subplot(224), plt.imshow(cannyImage), plt.title('canny')
plt.xticks([]), plt.yticks([])
plt.show()
'''
if cv2.waitKey() == ord('q'):
    cv2.closeAllWindows()
'''
