# -*- coding: utf-8 -*-
import numpy as np
import cv2

str = '/Users/Haoyang/Downloads/Pics/'
img = cv2.imread(str + 'boldt.jpg')
Z = img.reshape((-1,3))

# convert to np.float32
Z = np.float32(Z)

# define criteria, number of clusters(K) adn apply kmeans()
criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER,10,1.0)
K = 8
#ret, label, center = cv2.kmeans(Z, K, None,criteria, 0)
#ret, label, center = cv2.kmeans(Z, K, None, criteria,cv2.KMEANS_RANDOM_CENTERS)
ret, label, center = cv2.kmeans(Z, K, None,criteria,10, cv2.KMEANS_RANDOM_CENTERS)
# now convert back into uint8, and make original image

center = np.uint8(center)
res = center[label.ravel()]
res2 = res.reshape((img.shape))

cv2.imshow('res2',res2)
if cv2.waitKey() == ord('q'):
    cv2.destroyAllWindows()


