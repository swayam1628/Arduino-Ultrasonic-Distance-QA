// Ultrasonic Distance Measurement System - QA Improved Version
// Board: Arduino Uno
// Sensor: HC-SR04
// TRIG -> D9, ECHO -> D10

const byte TRIG_PIN = 9;
const byte ECHO_PIN = 10;

const unsigned long ECHO_TIMEOUT_US = 30000UL;
const unsigned long SERIAL_BAUD_RATE = 9600UL;
const float SOUND_SPEED_CM_PER_US = 0.0343f;

const float MIN_DISTANCE_CM = 2.0f;
const float MAX_DISTANCE_CM = 400.0f;
const byte SAMPLE_COUNT = 3;

float readDistanceCm() {
  // Generate the 10 microsecond trigger pulse.
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Limit how long the program waits for an echo pulse.
  unsigned long duration =
      pulseIn(ECHO_PIN, HIGH, ECHO_TIMEOUT_US);

  // pulseIn() returns zero when no pulse is received before timeout.
  if (duration == 0) {
    return -1.0f;
  }

  // Echo duration includes the outgoing and return journey.
  float distance =
      (duration * SOUND_SPEED_CM_PER_US) / 2.0f;

  // Reject readings outside the nominal HC-SR04 operating range.
  if (distance < MIN_DISTANCE_CM || distance > MAX_DISTANCE_CM) {
    return -1.0f;
  }

  return distance;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW);

  Serial.begin(SERIAL_BAUD_RATE);
  Serial.println("Ultrasonic Distance Measurement Started");
}

void loop() {
  float totalDistance = 0.0f;
  byte validSamples = 0;

  // Collect a small set of readings and average only valid samples.
  for (byte i = 0; i < SAMPLE_COUNT; i++) {
    float distance = readDistanceCm();

    if (distance >= 0.0f) {
      totalDistance += distance;
      validSamples++;
    }

    delay(60);
  }

  if (validSamples > 0) {
    float averageDistance = totalDistance / validSamples;

    Serial.print("Average Distance: ");
    Serial.print(averageDistance, 2);
    Serial.println(" cm");
  } else {
    Serial.println("No valid echo received / object out of range");
  }

  delay(300);
}
