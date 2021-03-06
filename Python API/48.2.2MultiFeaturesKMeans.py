# -*-coding: utf-8 -*-

import numpy as np
import cv2
import matplotlib.pyplot as plt

X = np.random.randint(25, 50, (25, 2))
Y = np.random.randint(60, 80, (25, 2))
# 上面50到60之间隔开，不产生这指尖的数，为了明显显示两个分类
Z = np.vstack((X, Y))

Z = np.float32(Z)

# defint criteria and apply kmean()
criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER,10,1.0)
ret, label, center = cv2.kmeans(Z, 2, None, criteria, 10, cv2.KMEANS_RANDOM_CENTERS)

# Now separate the data, Note the flatten()
A = Z[label.ravel()==0]
B = Z[label.ravel()==1]


# Plot the data
plt.scatter( A[:,0], A[:,1])
plt.scatter( B[:,0], B[:,1], c = 'r')
plt.scatter( center[:,0], center[:,1], s = 80, c = 'y', marker = 's')
plt.xlabel("Height"), plt.ylabel("Weight")
plt.show()



