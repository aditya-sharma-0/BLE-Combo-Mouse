Wiring Guide (ESP32 BLE Air Mouse)

Components:

    ESP32 DevKit v1 / Wemos Lolin D32

    MPU6050 (GY-521)

    2x tactile push buttons

    Jumper wires

Power:

    ESP32 3V3 → MPU6050 VCC

    ESP32 GND → MPU6050 GND

I2C (default ESP32 pins):

    ESP32 GPIO21 (SDA) → MPU6050 SDA

    ESP32 GPIO22 (SCL) → MPU6050 SCL

Buttons (INPUT_PULLUP):

    Left Button:

        One leg → ESP32 GPIO19

        Other leg → GND

    Right Button:

        One leg → ESP32 GPIO18

        Other leg → GND

    Ensure you’re using opposite diagonal legs of the button.

Notes:

    Use short, good-quality wires—especially for I2C. Avoid flaky breadboards.

    If MPU6050 isn’t detected, test with an I2C scanner and re-check SDA/SCL and power.

    If BLE disconnects during calibration, enable “sleep until BLE connected” in code or shorten calibration sample count.

See: esp32_ble_mouse_schematic.png for a visual.
