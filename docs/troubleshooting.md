Troubleshooting

BLE shows device but won’t connect (Windows):

    Remove old pairings, reboot PC and ESP32, pair immediately after reset.

    Update Bluetooth drivers.

    Try NimBLE variant if needed.

Port /dev/ttyUSB0 missing on Linux:

    Check cable/port

    Add user to dialout/uucp groups, re-login

MPU6050 not found:

    Check 3V3/GND

    ESP32 GPIO21 → SDA, GPIO22 → SCL

    Test with I2C scanner

    Replace breadboard/jumpers if intermittent

Connects but no motion:

    Print g.gyro.x/y/z to verify readings

    Increase sensitivity, lower deadzone

    Try different axis mapping

Random disconnect after calibration:

    Reduce calibration samples

    Send keep-alive bleMouse.move(0,0) during calibration
