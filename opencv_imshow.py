import cv2

cap = cv2.VideoCapture("rtsp://admin:admin@IP地址:端口号/live0")
ret,frame = cap.read()
while ret:
    ret,frame = cap.read()
    cv2.imshow("frame",frame)
    if cv2.waitKey(25) & 0xFF == ord('q'):
        break
cv2.destroyAllWindows()
cap.release()
