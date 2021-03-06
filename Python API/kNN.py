import cv2
import numpy as np
import matplotlib.pyplot as plt

# Feature set containing (x,y) values of 25 known/training data
trainData = np.random.randint(0,100,(25,2)).astype(np.float32)

# Labels each one either Red or Blue with number 0 or 1
responses = np.random.randint(0,2,(25,1)).astype(np.float32)

# Take Red families and plot them
red = trainData[responses.ravel() ==0]
plt.scatter(red[:,0],red[:,1],80,'r','^')

# Take blue families and plot them
blue = trainData[responses.ravel() ==1]
plt.scatter(blue[:,0],blue[:,1],80,'b','s')

#newcomer = np.random.randint(0,100,(1,2)).astype(np.float32)
#plt.scatter(newcomer[:,0],newcomer[:,1],80,'g','o')

# 10 newcomers
newcomers = np.random.randint(0,100,(10,2)).astype(np.float32)
plt.scatter(newcomers[:,0],newcomers[:,1],80,'g','o')

knn = cv2.KNearest()
knn.train(trainData,responses)
#ret,results,neighbours,dist = knn.find_nearest(newcomer,3)
ret,results,neighbours,dist = knn.find_nearest(newcomers,3)
print 'result: ',results,'\n'
print 'neighbours: ',neighbours,'\n'
print 'distance: ',dist,'\n'

plt.show()

