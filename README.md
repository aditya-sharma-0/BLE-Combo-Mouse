# BLE Combo Mouse  

An **ESP32-BLE based wireless air mouse** with **motion sensing, joystick, and button controls**, designed as a complete replacement for a PC mouse.  

## 🚀 Features  
- **Motion Control**: MPU6050 gyroscope/accelerometer for air-mouse movement.  
- **Joystick Input**: For smooth directional control and scrolling.  
- **Button Support**: Configurable clicks and additional functions.  
- **BLE HID Profile**: Seamless wireless communication with PCs/laptops.  
- **Calibration & Deadzone Logic**: Enhanced accuracy and reduced drift.  

---

## 🛠️ Hardware & Tools  
- ESP32 Dev Board (Lolin D32)  
- MPU6050 (Gyroscope + Accelerometer)  
- Joystick Module  
- Tactile Push Buttons  
- Arduino IDE / PlatformIO  
- BLE HID Library  

---

## 📂 Repository Structure  
BLE-Combo-Mouse/
- ├── src/ # Firmware code (ESP32, Arduino framework)
- ├── hardware/ # Circuit diagrams, wiring connections
- ├── docs/ # Notes, design decisions, calibration methods
- ├── images/ # Photos, wiring images, schematics
- └── README.md # Project overview (this file)

  ---

## ⚙️ Setup & Usage  
1. Clone the repo:  
   ```bash
   git clone https://github.com/aditya-sharma0/BLE-Combo-Mouse.git
   cd BLE-Combo-Mouse
2. Open project in Arduino IDE.
3. Install required libraries:
- ESP32 BLE
- MPU6050
- Upload code to ESP32.
- Pair ESP32 with your PC via Bluetooth.
4. Move the controller like an air mouse and use joystick/buttons for control.

   ---

## 📊 Results

- Achieved smooth cursor tracking with motion-based control.

- Stable BLE connection with low latency.

- Works as a standalone mouse replacement.

  ---
## 🔍 Research Angle / Future Work

- Explore sensor fusion (Kalman filter) for better accuracy.

- Add gesture recognition (e.g., hand tilt = specific action).

- Extend to robot/wheelchair control for accessibility.

  ---
## 📜 License

- Released under the MIT License – free for educational and research use.  
