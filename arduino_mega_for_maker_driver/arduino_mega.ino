#include <Arduino.h>

/*
  Continuous low-PWM control: Arduino Mega ADK + Cytron Maker Drive.
  Small control header: M1A -> 8, M1B -> 9, M2A -> 10, M2B -> 11.
  Driver GND -> Arduino GND. Power the Arduino through USB-B.
  Battery + -> VB+, battery - -> VB-. Leave the driver's 5VO unconnected.
  One motor winding must span the M1A/M1B OUTPUT terminals;
  the other winding must span the M2A/M2B OUTPUT terminals.

  Disconnect motor power while uploading or changing wiring.
  Serial Monitor: 115200 baud. t runs forward; r runs in reverse;
  s switches all outputs off. Send t or r again to restart after stopping.
  The motor starts OFF after every reset. No external library is needed.
  Keep Serial Monitor connected so the Stop command can reach the board.
  There is no automatic timeout. Disconnect motor power if control is lost.

  IMPORTANT: 20/255 PWM reduces applied power; it does NOT regulate
  coil current or guarantee protection for an unidentified motor.
  Continuous operation can overheat the motor, driver, or battery pack.
  Do not raise PWM to overcome a stalled or incorrectly wired motor.
*/

const uint8_t CONTROL_PINS[] = {8, 9, 10, 11};
// Wave stepping: winding 1 +, winding 2 +, winding 1 -, winding 2 -.
// Only one input receives PWM in each phase.
const uint8_t PHASE_PINS[] = {8, 10, 9, 11};
const uint8_t DRIVE_PWM = 20;            // About 8% duty cycle, NOT 8% current.
const unsigned long STEP_INTERVAL_MS = 10;

bool running = false;
int8_t direction = 1;
uint8_t phaseIndex = 0;
unsigned long lastStepAt = 0;

void outputsOff() {
  for (uint8_t i = 0; i < 4; ++i) {
    analogWrite(CONTROL_PINS[i], 0);
  }
}

void applyPhase() {
  outputsOff();
  delayMicroseconds(100);
  analogWrite(PHASE_PINS[phaseIndex], DRIVE_PWM);
}

void stopMotor() {
  outputsOff();
  const bool wasRunning = running;
  running = false;
  if (wasRunning) {
    Serial.println(F("Stopped. Outputs off. Send t or r to run again."));
  }
}

void startMotor(int8_t requestedDirection) {
  if (running && direction == requestedDirection) {
    return;
  }
  direction = requestedDirection;
  if (!running) {
    lastStepAt = millis();
    running = true;
    applyPhase();
  }
  // Preserve the current phase when reversing; the next step changes direction.
  if (direction > 0) {
    Serial.println(F("Running forward until s. Send r to reverse."));
  } else {
    Serial.println(F("Running in reverse until s. Send t to go forward."));
  }
}

void setup() {
  for (uint8_t i = 0; i < 4; ++i) {
    digitalWrite(CONTROL_PINS[i], LOW);
    pinMode(CONTROL_PINS[i], OUTPUT);
  }
  outputsOff();
  Serial.begin(115200);
  Serial.println(F("Motor OFF. t = run forward, r = run reverse, s = stop."));
  Serial.println(F("No automatic timeout. Keep Serial Monitor connected."));
}

void loop() {
  if (Serial.available() > 0) {
    const char command = Serial.read();
    if (command == 's' || command == 'S') {
      stopMotor();
    } else if (command == 't' || command == 'T') {
      startMotor(1);
    } else if (command == 'r' || command == 'R') {
      startMotor(-1);
    }
  }

  if (!running) {
    return;
  }

  const unsigned long now = millis();
  // Unsigned subtraction keeps step timing valid across millis() wrap.
  if (now - lastStepAt >= STEP_INTERVAL_MS) {
    lastStepAt = now;
    phaseIndex = (phaseIndex + (direction > 0 ? 1 : 3)) % 4;
    applyPhase();
  }
}
