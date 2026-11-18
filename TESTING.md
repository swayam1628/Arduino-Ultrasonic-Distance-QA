# Ultrasonic Distance Measurement – Testing Results

## Test Case 1: Sensor Pin Configuration
- **Status:** PASS (visual wiring inspection)
- **Expected Result:** The HC-SR04 sensor should be connected with VCC to 5V, GND to GND, TRIG to digital pin 9, and ECHO to digital pin 10.
- **Actual Result:** The submitted Tinkercad circuit screenshot shows these four connections. The Arduino code uses TRIG_PIN = 9 and ECHO_PIN = 10.

## Test Case 2: Ultrasonic Distance Measurement Output
- **Status:** PASS (simulation output observed)
- **Expected Result:** The Serial Monitor should display distance values in centimetres at a baud rate of 9600.
- **Actual Result:** The supplied Tinkercad Serial Monitor screenshot displays continuously updating distance values. Visible examples include 185.29 cm, 254.33 cm, 291.81 cm, 64.67 cm, 45.57 cm, 187.91 cm, and 226.05 cm.

## Test Case 3: Echo Timeout Handling
- **Status:** NOT VERIFIED
- **Expected Result:** The improved program should stop waiting for an echo after the configured 30,000 microsecond timeout and proceed to the next measurement cycle.
- **Actual Result:** Version 2 contains `pulseIn(ECHO_PIN, HIGH, ECHO_TIMEOUT_US)` with `ECHO_TIMEOUT_US = 30000UL`. A no-echo simulation or hardware test has not yet been recorded.

## Test Case 4: Invalid / Zero-Duration Echo Handling
- **Status:** NOT VERIFIED
- **Expected Result:** If no echo pulse is received, the program should report an invalid/no-echo condition instead of displaying 0 cm as a valid distance.
- **Actual Result:** Version 2 checks whether `duration == 0` and returns an invalid marker. The no-echo behaviour has not yet been demonstrated in captured test evidence.

## Test Case 5: Repeated Reading Averaging
- **Status:** NOT VERIFIED
- **Expected Result:** The improved program should average up to three valid readings and ignore invalid samples.
- **Actual Result:** Version 2 implements a three-sample collection and averaging routine. No controlled before-and-after dataset has been recorded yet.

## Test Case 6: Named Constants and Pin Configuration
- **Status:** PASS (source-code inspection only)
- **Expected Result:** Pin numbers, timeout, baud rate, speed-of-sound factor, range limits, and sample count should be defined using descriptive constants.
- **Actual Result:** Version 2 defines `TRIG_PIN`, `ECHO_PIN`, `ECHO_TIMEOUT_US`, `SERIAL_BAUD_RATE`, `SOUND_SPEED_CM_PER_US`, `MIN_DISTANCE_CM`, `MAX_DISTANCE_CM`, and `SAMPLE_COUNT`. Compilation has not yet been evidenced.

## Testing Environment
- **Platform:** Tinkercad Circuits
- **Microcontroller:** Arduino Uno R3
- **Ultrasonic Sensor:** HC-SR04 / Tinkercad Ultrasonic Distance Sensor component
- **TRIG Pin:** Digital Pin 9
- **ECHO Pin:** Digital Pin 10
- **VCC:** 5V
- **GND:** GND
- **Baud Rate:** 9600
- **Initial program:** `src/ultrasonic_v1.ino`
- **QA-improved program:** `src/ultrasonic_v2.ino`

## Overall Result
The Tinkercad simulation output and circuit wiring have been visually observed. Source-code inspection confirms that Version 2 includes explicit timeout handling, invalid-reading checks, named constants, and sample averaging. However, the improved program's compilation, no-echo handling, averaging performance, and controlled distance response have not yet been verified with recorded test runs. Therefore, the overall project is **PARTIALLY VERIFIED**, not fully passed.

## Pending Verification
1. Compile Version 2 in the Arduino/Tinkercad environment and capture the successful compile/run result.
2. Record a controlled target-distance test at known positions, where the simulator permits it.
3. Demonstrate the no-echo condition and record the Serial Monitor output.
4. Collect repeated readings for a stationary target and compare raw and averaged values.
5. Update each GitHub Issue only after the related correction and test evidence are reviewed.
