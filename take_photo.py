import cv2

def take_photo(file_path):
    cap = cv2.VideoCapture(0)

    if not cap.isOpened():
        print("Error: Unable to open camera")
        return

    ret, frame = cap.read()

    if not ret:
        print("Error: Unable to capture frame")
        cap.release()
        return

    cv2.imwrite(file_path, frame)

    print(f"Photo captured and saved to {file_path}")

    cap.release()

if __name__ == "__main__":
    file_path = "/home/jeries/Desktop/Project/py-c--interface/photo.jpg"
    take_photo(file_path)
