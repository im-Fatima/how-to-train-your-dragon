import cv2

# Open webcam (0 = default camera; change to 1 if using an external USB/DSLR)
cap = cv2.VideoCapture(1)

# Check if webcam is opened successfully
if not cap.isOpened():
    print("Cannot access webcam")
    exit()

# Optional: Set resolution (you can modify as needed)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1920)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 1080)

print("Streaming started. Press 'q' in the video window to quit.")

while True:
    # Capture frame-by-frame
    ret, frame = cap.read()
    if not ret:
        print("Failed to grab frame")
        break

    # Display the resulting frame
    cv2.imshow("Live Webcam Stream", frame)

    # Exit on pressing 'q'
    if cv2.waitKey(1) & 0xFF == ord('q'):
        print("Streaming stopped by user.")
        break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()
