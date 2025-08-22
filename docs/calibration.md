Calibration

On first connect, the firmware calibrates gyro offsets:

    Keep the device still during “Calibrating gyroscope... Keep still!”

    Offsets are printed to Serial.

Tips:

    If drift is noticeable, increase numSamples in calibrateGyro() or re-run calibration after a short settle time.

    You can recalibrate on demand by adding a long-press action to a button (future enhancement).

    Adjust:

        Xsensitivity, Ysensitivity for speed

        deadzone to reduce jitter

    Try different axis mappings (g.gyro.x/y/z) depending on how the device is held.
