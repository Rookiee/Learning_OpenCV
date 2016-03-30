# -*- coding: utf-8
import cv2
import numpy as np

# 当鼠标按下时如True
drawing =False
# 如果mode为true，绘制矩形，按下‘m’ 变成绘制曲线
mode = True
ix, iy = -1, -1

# 创建回调函数
def draw_circle(event, x, y, flags, param):
    global ix, iy, drawing, mode
# 当按下左键时，返回起始位置坐标
    if event == cv2.EVENT_LBUTTONDOWN:
        drawing = True
        ix, iy, = x, y
# 当鼠标左键按下并移动时绘制矩形。event可以查看移动，flags查看是否按下
    elif event ==cv2.EVENT_MOUSEMOVE and flags == cv2.EVENT_FLAG_LBUTTON:
        if drawing==True:
            if mode==True:
                cv2.rectangle(img, (ix, iy), (x, y), (255,255,0), -1)
            else:
# 绘制圆形，小圆点连在一起就成了线，3是圆的半径，在这里也可以看成线的粗细
                cv2.circle(img, (x, y), 1, (0,255,255), 1)
# 下面注释掉得代码是起始点为圆心，起始点到终点为半径的园
#               r = int(np.sqrt((x-ix)**2 + (y-iy)**2))
#               cv2.circle(img, (x, y), r, (0, 0, 255) , -1)
# 当鼠标松开时停止绘图
    elif event == cv2.EVENT_LBUTTONUP:
        drawing == False



img = 255 *np.ones((512,512,3), np.uint8)
cv2.namedWindow('image')
cv2.setMouseCallback('image',draw_circle)
while(1):
    cv2.imshow('image',img)
    k = cv2.waitKey(1)
    if k == ord('m'):
        mode = not mode
    elif k == 27:
        break;
