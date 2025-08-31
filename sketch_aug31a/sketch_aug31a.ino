#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Tweak these if needed depending on your servo
#define SERVOMIN  125 // Min pulse length out of 4096
#define SERVOMAX  575 // Max pulse length out of 4096

int currentAngle = 90;  // start at middle
int targetAngle = 95;   // move +5 degrees
int steps = 50;         // how many small steps
int delayTime = 60;     // delay per step (ms) → 50 * 60 = ~3000 ms (3 sec)

void setup() {
  Serial.begin(115200);
  pwm.begin();
  pwm.setPWMFreq(50);  // Standard analog servo frequency

  // Move to start position
  moveServo(0, currentAngle);
  delay(500);
}

void loop() {
  // Slowly move from currentAngle to targetAngle
  for (int i = 1; i <= steps; i++) {
    int angle = currentAngle + ( (targetAngle - currentAngle) * i / steps );
    moveServo(0, angle);
    delay(delayTime);
  }

  // Update currentAngle
  currentAngle = targetAngle;

  // Stop moving after finishing
  while (true) {
    delay(1000); // do nothing forever
  }
}

// Helper: convert angle → pulse length
void moveServo(uint8_t n, int angle) {
  int pulselen = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(n, 0, pulselen);
}

