#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVO_FREQ 50  // 50 Hz for standard servos
#define SERVOMIN  150  // Min pulse length out of 4096
#define SERVOMAX  600  // Max pulse length out of 4096

// Convert degrees to PCA9685 pulse length
int angleToPulse(int ang) {
  return map(ang, 0, 180, SERVOMIN, SERVOMAX);
}

void setup() {
  Serial.begin(115200);
  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);

  delay(10);
}

void loop() {
  // Sweep from 0° → 180° on channel 0
  // Sweep from 180° → 0° on channel 1 (opposite direction)
  for (int angle = 0; angle <= 180; angle++) {
    pwm.setPWM(0, 0, angleToPulse(angle));       // channel 0 goes forward
    pwm.setPWM(1, 0, angleToPulse(180 - angle)); // channel 1 goes reverse
    delay(40); // adjust speed (higher = slower)
  }

  // Sweep back: 180° → 0° on channel 0, 0° → 180° on channel 1
  for (int angle = 180; angle >= 0; angle--) {
    pwm.setPWM(0, 0, angleToPulse(angle));       
    pwm.setPWM(1, 0, angleToPulse(180 - angle)); 
    delay(40); 
  }
}
