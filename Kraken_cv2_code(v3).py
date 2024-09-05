import cv2
import os

# Manually set the path to the Haar Cascade file
cascades_dir = '/usr/local/share/opencv4/haarcascades/'  # Change this path if it's different on your setup
cascade_path = os.path.join(cascades_dir, 'haarcascade_frontalface_default.xml')

# Check if the file exists
if not os.path.exists(cascade_path):
    print(f"Error: Cascade file not found at {cascade_path}")
else:
    print(f"Cascade file found at {cascade_path}")

# Load the pre-trained Haar Cascade classifier for face detection
face_cascade = cv2.CascadeClassifier(cascade_path)

# Check if the cascade loaded correctly
if face_cascade.empty():
    print("Error: Failed to load cascade classifier")
    exit()

# Initialize the video capture object with the first USB camera
cap = cv2.VideoCapture(0)

while True:
    # Read a frame from the camera
    ret, frame = cap.read()
    
    if not ret:
        print("Error: Failed to capture image")
        break
    
    # Convert the frame to grayscale (Haar cascade works better on grayscale images)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    
    # Detect faces in the frame
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))
    
    # Draw rectangles around detected faces
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)
    
    # Display the resulting frame
    cv2.imshow('Live Feed with Object Detection', frame)
    
    # Check for key press to exit
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the video capture object and close the OpenCV window
cap.release()
cv2.destroyAllWindows()
