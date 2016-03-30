# -*- coding: utf-8 -*-
import numpy as np
import cv2
import matplotlib.pyplot as plt
'''
#产生随机数据
# 产生25到100之间的数，排列的形式是1行25列，即25个数
'''
x = np.random.randint(25, 100, 25)
y = np.random.randint(175, 210, 25)

z = np.hstack((x, y))
z = z.reshape((50, 1))
z = np.float32(z)

#plt.hist(z, 256, [0, 256] ) , plt.show()

# 现在，有了一个长度为50，取值范围0到255的向量z。

# define criteria = ( type, max_iter=10, epsilon = 1.0)
criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 10,1.0)

# set flags (Just to avoid line break in the code)
flags = cv2.KMEANS_RANDOM_CENTERS # 0

# apply KMeans
compactness, labels, centers = cv2.kmeans(z, 2, None, criteria, 10, 0)

A = z[labels ==0]
B = z[labels ==1]

print (centers)

plt.hist(A, 256, [0, 256], color='r')
plt.hist(B, 256, [0, 256], color='b')
plt.hist(centers, 32, [0, 256], color='g')
plt.show()

