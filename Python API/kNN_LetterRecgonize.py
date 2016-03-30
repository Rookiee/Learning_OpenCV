import cv2
import numpy as np

data = np.loadtxt('/Users/Haoyang/Downloads/Pics/letter-recognition.data',
                  dtype = np.float32, delimiter = ',',
                  converters = {0: lambda ch: ord(ch)-ord('A')})

# split the date to Two, 10000 each for train and test
train,test = np.vsplit(data,2)

# split trainData and testData to features and responses
responses, trainData = np.hsplit(train,[1])
labels,testData = np.hsplit(test,[1])

# initiate the knn, classify , measure accuracy
knn = cv2.KNearest()
knn.train(trainData,responses)
ret,result,neighbours,dist = knn.find_nearest(testData,5)

correct = np.count_nonzero(result==labels)
accuracy = correct*100.0/10000
print accuracy
