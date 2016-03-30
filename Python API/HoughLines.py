import cv2
import numpy as np

str = '/Users/Haoyang/Downloads/Pics/'

img = cv2.imread(str +'road.jpg')
imgGray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
edges = cv2.Canny(imgGray,128,350,apertureSize = 3)
cv2.imshow('canny',edges)

rec,imgEdges = cv2.threshold(edges,127,255,cv2.THRESH_BINARY_INV)
cv2.imshow('imgEdges',imgEdges)


lines = cv2.HoughLines(imgEdges,1,3.1415926/180,80)
print (lines)
print lines.shape
print lines[0]
for rho,theta in lines[0]:
	a = np.cos(theta)
	b = np.sin(theta)
	x0 = int(a*rho)
	y0 = int(b*rho)
	
	
	x1 = int(x0 + 1000*(-b))
	y1 = int(y0 + 1000*a)
	
	x2 = int(x0 -1000*(-b))
	y2 = int(x0 -1000*a)
	cv2.line(img,(x1,y1),(x2,y2),(0,255,255),2)

cv2.imshow('lines',img)
