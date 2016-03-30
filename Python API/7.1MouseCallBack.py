# -*- coding:utf-8 -*-

import cv2
import numpy as np
# Mouse call back function
def draw_circle(event, x, y, flags, param):
    if event == cv2.EVENT_LBUTTONDOWN:
        cv2.circle(img, (x, y), 100, (255, 0, 0), 3)
    elif event == cv2.EVENT_LBUTTONUP:
        cv2.rectangle(img, (x, y), (x+50, y+50), (255, 255, 0), 2)

# 创建图像与窗口，并将窗口与回调函数绑定
img = 255*np.ones((512, 512, 3), np.uint8)
cv2.namedWindow('image')
cv2.setMouseCallback('image', draw_circle)

while(1):
    cv2.imshow('image', img)
    if cv2.waitKey(20) == 27:
        break
cv2.destroyAllWindows()
