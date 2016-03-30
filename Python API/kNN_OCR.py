import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread('/Users/Haoyang/Downloads/Pics/digits.png')
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

# we split the image to 5000 cells, each 20x20 size
cells = [np.hsplit(row,100) for row in np.vsplit(gray,50)]

# make it into a Numpy array. it size will be (50,100,20,20)
x = np.array(cells)

# Now prepare the train_data and test_data
train = x[:,:50].reshape(-1,400).astype(np.float32)
test = x[:,50:100].reshape(-1,400).astype(np.float32)

k = np.arange(10)
train_labels = np.repeat(k,250)[:,np.newaxis]
test_labesl = train_labels.copy()

# Initiate kNN, train the data, then test it with test data for k = 1
knn = cv2.KNearest()
knn.train(train,train_labels)
ret,result,neighbours,dist = knn.find_nearest(test,k=5)

# new we check the accuracy of classification
# for that, compare the result with test_labels and check with are wrong
matches = result==test_labesl
correct = np.count_nonzero(matches)
accuracy = correct*100.0/result.size
print accuracy
