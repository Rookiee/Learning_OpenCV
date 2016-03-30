# -*- coding: utf-8 -*-

# import numpy as np
# import numpy
import cv2

facePath =( "/Users/Haoyang/Downloads/opencv-3.1.0/data/haarcascades"
            "/haarcascade_frontalface_default.xml")
eyePath = ( "/Users/Haoyang/Downloads/opencv-3.1.0/data/haarcascades"
           "/haarcascade_eye.xml")
face_cascade = cv2.CascadeClassifier(facePath)
eye_cascade = cv2.CascadeClassifier(eyePath)
fileName = raw_input("Enter the file name: ")
img = cv2.imread('/Users/Haoyang/Downloads/Pics/' + fileName);
# img = cv2.imread('/Users/Haoyang/Downloads/Pics/face1.jpg')
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# cv2.imshow("gray", gray)


# Detects objects of different sizes in the input image.
# The deteced objects are returned as a list of rectangles.
# cv2.CascadeClassifier.detectMultiScale(image,scaleFactor,minNeighbors,
#                                        flags, minSize, maxSize)
# scaleFactor -- Parameter specifying how much the image size is reduced at each
#                scale.
# minNeighbours -- Parameter specifying how many neighbours each candidate
#                  should have to retain.
# minSize -- Minimum possible object size. Objects smaller than that are ignored
# maxSize -- Maximum possible object size. Objects bigger than that are ignored.

faces = face_cascade.detectMultiScale(gray, 1.3, 5)
for (x, y, w, h) in faces:
    img = cv2.rectangle(img, (x, y), (x+w, y+h), (255, 0, 0), 2)
    roi_gray = gray[y:y+h, x:x+w]
    roi_color = img[y:y+h, x:x+w]
    eyes = eye_cascade.detectMultiScale(roi_gray)
    for (ex, ey, ew, eh) in eyes:
        cv2.rectangle(roi_color, (ex, ey), (ex+ew, ey+eh), (0, 255, 0), 2)

cv2.imshow('Face and Eyes', img)

if cv2.waitKey() == ord('q'):
    cv2.destroyAllWindows()

