import cv2
import mediapipe as mp
import serial  # For Bluetooth communication
import time

# Initialize MediaPipe Hands
mp_hands = mp.solutions.hands
hands = mp_hands.Hands(min_detection_confidence=0.7, min_tracking_confidence=0.7)
mp_draw = mp.solutions.drawing_utils

# Initialize Bluetooth communication
bluetooth = serial.Serial('COM5', 9600)  # Change 'COM5' to your Bluetooth port
bluetooth.flush()

# Start video capture
cap = cv2.VideoCapture(0)

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break
    
    frame = cv2.flip(frame, 1)
    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    result = hands.process(rgb_frame)
    
    if result.multi_hand_landmarks:
        for hand_landmarks in result.multi_hand_landmarks:
            mp_draw.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)
            
            # Extract key points (tip of thumb & index finger)
            thumb_tip = hand_landmarks.landmark[mp_hands.HandLandmark.THUMB_TIP]
            index_tip = hand_landmarks.landmark[mp_hands.HandLandmark.INDEX_FINGER_TIP]
            
            # Gesture recognition (e.g., Open palm for 'Forward')
            if thumb_tip.y < index_tip.y:
                command = 'F'  # Forward
            else:
                command = 'S'  # Stop
                
            bluetooth.write(command.encode())
            time.sleep(0.1)  # Delay to avoid spamming commands
    
    cv2.imshow('Hand Gesture Control', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
bluetooth.close()
