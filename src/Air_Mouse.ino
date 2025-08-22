#include <BleMouse.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

BleMouse bleMouse;
Adafruit_MPU6050 mpu;

// --- Tuning ---
float Xsensitivity = 70.0; // Left/right
float Ysensitivity = 20.0;  // Up/down

float gyroXoffset = 0;
float gyroYoffset = 0;

// --- Smoothing ---
const int numReadings = 5;
float readingsY[numReadings]; 
float readingsX[numReadings];
int readIndex = 0;
float totalY = 0;
float totalX = 0;

void calibrateGyro() {
  const int numSamples = 1000;
  float sumX = 0, sumY = 0;

  Serial.println("Calibrating gyroscope... Keep still!");
  for (int i = 0; i < numSamples; i++) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    sumX += g.gyro.x;
    sumY += g.gyro.y;
    delay(2);
  }

  gyroXoffset = sumX / numSamples;
  gyroYoffset = sumY / numSamples;

  Serial.println("Calibration done!");
  Serial.print("X Offset: "); Serial.println(gyroXoffset);
  Serial.print("Y Offset: "); Serial.println(gyroYoffset);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting Air Mouse...");

  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1) delay(10);
  }
  Serial.println("MPU6050 ready.");

  calibrateGyro();

  for (int i = 0; i < numReadings; i++) {
    readingsY[i] = 0;
    readingsX[i] = 0;
  }

  bleMouse.begin();
}

void loop() {
  if (bleMouse.isConnected()) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    // --- Smoothing
    totalX -= readingsX[readIndex];
    totalY -= readingsY[readIndex];
    readingsX[readIndex] = g.gyro.y;
    readingsY[readIndex] = g.gyro.x;
    totalX += readingsX[readIndex];
    totalY += readingsY[readIndex];
    readIndex = (readIndex + 1) % numReadings;

    float avgX = totalX / numReadings;
    float avgY = totalY / numReadings;

    int mouseX = (int)((avgX - gyroYoffset) * (-1) * Xsensitivity);
    int mouseY = (int)((avgY - gyroXoffset) * (-1) * Ysensitivity);

    // --- Deadzone (smaller than before)
    int deadzone = 1;
    int effectiveMouseX = (abs(mouseX) > deadzone) ? mouseX : 0;
    int effectiveMouseY = (abs(mouseY) > deadzone) ? mouseY : 0;

    // Send movement
    if (effectiveMouseX != 0 || effectiveMouseY != 0) {
      bleMouse.move(effectiveMouseX, effectiveMouseY);
    }
  }

  delay(10); // For Bluetooth stability
}
