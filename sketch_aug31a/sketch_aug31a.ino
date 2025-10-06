#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Servo settings
#define STEP_DELAY 100  // milliseconds per step (slower = super slow)
#define STEP_SIZE 1     // small increment for smooth movement
#define OSC_RANGE 2     // tiny angle for subtle movement

// Starting positions
int pos0 = 375;
int pos1 = 375;

void setup() {
  Serial.begin(115200);
  pwm.begin();
  pwm.setPWMFreq(50);  // standard servo frequency
  Wire.setClock(400000);

  // Initialize servos at starting positions
  pwm.setPWM(0, 0, pos0);
  pwm.setPWM(1, 0, pos1);
  delay(500);
  Serial.println("Synchronized tiny servo oscillation starting...");
}

void loop() {
  // Slowly move forward
  for (int offset = -OSC_RANGE; offset <= OSC_RANGE; offset += STEP_SIZE) {
    pwm.setPWM(0, 0, pos0 + offset); // Servo 0
    pwm.setPWM(1, 0, pos1 + offset); // Servo 1, same direction
    delay(STEP_DELAY);
  }

  // Slowly move backward
  for (int offset = OSC_RANGE; offset >= -OSC_RANGE; offset -= STEP_SIZE) {
    pwm.setPWM(0, 0, pos0 + offset); // Servo 0
    pwm.setPWM(1, 0, pos1 + offset); // Servo 1, same direction
    delay(STEP_DELAY);
  }
}
