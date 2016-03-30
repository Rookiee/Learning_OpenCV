# coding: utf-8

import cv2
import numpy as np

cap = cv2.VideoCapture(0)
# 直接显示采集后的图像 1.6.2
'''
while(1):
    ret, frame = cap.read()
    cv2.imshow('video', frame)
    if cv2.waitKey(24) == ord('q'):
        cv2.destroyAllWindows()
'''
# 1.6.3
# 摄像头，配合canny边缘检测，得到canny边缘检测
# 并高斯模糊后的摄像头采集视频
ret, frame = cap.read()
blurImage = np.ones(frame.shape, np.uint8)
cannyImage = blurImage.copy()
while(1):
    ret, frame = cap.read()
    frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    # 使用3x3内核降噪
    blurImage = cv2.blur(frame, (3, 3))
    cannyImage = cv2.Canny(blurImage, 30, 200, 3)
    cv2.imshow('blur', cannyImage)
    # 延迟25ms
    if cv2.waitKey(25) > 0:
        break
