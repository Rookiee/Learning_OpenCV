import numpy as np
import cv2

cap = cv2.VideoCapture(0)

# Define the codec and create VidwoWriter object
fourcc = cv2.VideoWriter_fourcc(-1)
out = cv2.VideoWriter('output.avi',fourcc,20.0,(640,480))

while(cap.isOpened()):
    ret, frame = cap.read()
    if ret == True:
    	fliped = cv2.flip(frame,0)

        # Write the flipped frame
        out.write(fliped)

        cv2.imshow('frame',fliped)
        if cv2.waitKey(1) == ord('q'):
            break
    else:
        break;

cap.release()
out.release()
cv2.destroyAllWindows ()
    
