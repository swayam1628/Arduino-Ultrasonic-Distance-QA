# Quality Assurance (QA) Report
## Ultrasonic Distance Measurement Using Arduino Uno and HC-SR04

**Repository:** [Arduino-Ultrasonic-Distance-QA](https://github.com/swayam1628/Arduino-Ultrasonic-Distance-QA)  
**Project type:** Embedded systems / Arduino  
**Status:** QA issues documented; improved implementation prepared; simulation and hardware test evidence still to be completed.

---

## 1. Project Overview

This project measures the distance of an object using an Arduino Uno and an HC-SR04 ultrasonic distance sensor. The sensor emits an ultrasonic pulse and measures the time taken for its echo to return. The Arduino converts the measured echo duration into distance in centimetres and displays the result through the Serial Monitor.

### Components
- Arduino Uno
- HC-SR04 ultrasonic distance sensor (or the equivalent Ultrasonic Distance Sensor component in Tinkercad Circuits)
- Jumper wires
- USB connection / Tinkercad simulation

### Pin connections
| Sensor pin | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | Digital pin 9 |
| ECHO | Digital pin 10 |

## 2. Initial Implementation

The initial program is stored at [src/ultrasonic_v1.ino](../src/ultrasonic_v1.ino).

The program triggers the sensor with a 10-microsecond pulse, reads the echo duration using `pulseIn()`, calculates distance using the approximate speed of sound (0.0343 cm/µs), and prints the result every 500 ms.

## 3. QA Objectives

The QA activity focuses on:
1. Identifying edge cases in ultrasonic echo measurement.
2. Making timeout handling explicit.
3. Handling invalid or zero-duration readings.
4. Reviewing fluctuation in repeated readings.
5. Improving readability through named constants.
6. Defining repeatable test procedures and recording evidence.

## 4. QA Issues Logged

The following issues were created in the repository's GitHub Issues section.

| Issue | Description | Type | Current status |
|---|---|---|---|
| [#1](../issues/1) | Add an explicit timeout for ultrasonic echo measurement | Bug / robustness | Open |
| [#2](../issues/2) | Handle zero-duration echo readings as invalid measurements | Bug / robustness | Open |
| [#3](../issues/3) | Reduce fluctuation in repeated distance readings | Enhancement / investigation | Open |
| [#4](../issues/4) | Replace hard-coded measurement values with named constants | Enhancement | Open |
| [#5](../issues/5) | Add a dedicated test procedure and actual test evidence | Documentation | Open |

**Important:** Issue #3 is an improvement to investigate, not a confirmed defect. Also, `pulseIn()` has a default timeout; Issue #1 asks for an explicit project-defined timeout so the behaviour is clear and controlled.

## 5. Improved Implementation

An improved version is available at [src/ultrasonic_v2.ino](../src/ultrasonic_v2.ino) on the `qa/fix-ultrasonic-issues` branch.

The revised program:
- Uses named constants for trigger pin, echo pin, timeout, and sound speed.
- Passes an explicit timeout to `pulseIn()`.
- Treats a zero-duration echo as an invalid reading.
- Rejects readings outside the nominal operating range configured in the code.
- Takes up to three valid readings and averages them to reduce short-term fluctuation.

The improved code is a proposed revision. It must still be compiled and exercised in Tinkercad and, if available, on physical hardware before the fixes can be marked verified.

## 6. Test Plan and Results

The detailed procedure is maintained in [docs/TESTING.md](TESTING.md).

| Test ID | Test scenario | Expected result | Actual result |
|---|---|---|---|
| T01 | Object at a measurable distance | Serial Monitor displays a distance in cm | Pending |
| T02 | Change the target distance | Displayed distance changes accordingly | Pending |
| T03 | No echo / target outside detectable range | Program reports an invalid or unavailable echo | Pending |
| T04 | Repeat measurements at a fixed distance | Readings are reasonably stable; any variation is recorded | Pending |
| T05 | Compile the revised sketch | Sketch compiles without errors | Pending |

No test is marked as passed because actual simulation or hardware evidence has not yet been recorded. Add measured values, observations, and screenshots to this report after running the tests.

## 7. Collaboration and Issue Tracking

GitHub is used to organize the QA workflow:
- Issues #1–#5 record identified concerns and proposed improvements.
- The `qa/fix-ultrasonic-issues` branch keeps the revised sketch and test procedure separate from the initial implementation.
- The initial and revised versions can be reviewed side by side.
- Issues should be closed only after the corresponding change has been reviewed and the relevant test evidence has been added.

**Collaboration record:** Add the actual names/usernames of reviewers, comments exchanged, and issue-resolution decisions here. Do not claim peer review or issue closure unless it has taken place.

## 8. Project Planning and Tracking

| Work item | GitHub location | Progress |
|---|---|---|
| Store initial Arduino sketch | `src/ultrasonic_v1.ino` | Completed |
| Document project and setup | `README.md` | Completed |
| Record QA observations | Issues #1–#5 | Logged |
| Prepare improved sketch | `qa/fix-ultrasonic-issues` branch | Prepared; verification pending |
| Define test procedure | `docs/TESTING.md` | Prepared; execution pending |
| Capture Tinkercad simulation evidence | To be added | Pending |
| Review changes and close verified issues | Pull request / Issues | Pending |

## 9. Tinkercad Simulation Evidence

**Status: Pending upload.**

After creating and running the circuit in Tinkercad:
1. Capture a screenshot showing the complete Arduino and ultrasonic sensor wiring.
2. Capture the code and Serial Monitor output.
3. Record at least two different target-distance observations.
4. Add the screenshot(s) to the repository, preferably under `docs/images/`.
5. Replace this section with the image links and a short description of the observed results.

Do not treat a circuit screenshot alone as proof that all test cases passed.

## 10. Learning Outcomes

This activity provides practical experience with:
- Organizing embedded-system source code in GitHub.
- Reporting bugs and enhancement requests using GitHub Issues.
- Separating initial and revised implementations with branches.
- Thinking about timeouts, invalid sensor readings, and measurement variation.
- Writing repeatable test cases and maintaining evidence.
- Tracking work transparently without marking unverified fixes as complete.

## 11. Conclusion

The repository contains the initial ultrasonic distance measurement program, five documented QA issues, an improved candidate implementation on a separate branch, and a test procedure. The next required step is to run the simulation, record actual results, upload the Tinkercad screenshots, and review the proposed changes. Only verified issues should then be closed.

---

**Submission note:** Before submitting this report, fill in the actual test results, collaboration details, and Tinkercad evidence.
