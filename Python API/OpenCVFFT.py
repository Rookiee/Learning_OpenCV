import cv2
import numpy as np
from matplotlib import pyplot as plt

fileName = raw_input('Enter the file name: ')

path = '/Users/Haoyang/Downloads/Pics/'

img = cv2.imread(path + fileName,0)
img = np.float32(img)
dft = cv2.dft(img,flags = cv2.DFT_COMPLEX_OUTPUT)
dft_shift = np.fft.fftshift(dft)

mag_spec = 20*np.log(cv2.magnitude(dft_shift[:,:,0],dft_shift[0:,:,1]))

plt.subplot(221); plt.imshow(img,cmap = 'gray');plt.title('Original')
plt.subplot(223); plt.imshow(mag_spec,cmap = 'gray');plt.title('After FFT');
plt.show()
