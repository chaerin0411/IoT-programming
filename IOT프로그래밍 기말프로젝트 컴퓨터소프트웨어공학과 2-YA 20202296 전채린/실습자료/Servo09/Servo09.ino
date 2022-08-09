/* Servo09 */
/* 3초간 전진 테스트 */
#include <Servo.h> // Include servo library
Servo servoLeft; // Declare left and right servos
Servo servoRight;
void setup() { // Built-in initialization block
  tone(4, 3000, 1000); // Play tone for 1 second
  delay(1000); // Delay to finish tone
  servoLeft.attach(13); // Attach left signal to pin 13
  servoRight.attach(12); // Attach right signal to pin 12
  // Full speed forward
  servoLeft.writeMicroseconds(1700); // Left wheel counterclockwise
  servoRight.writeMicroseconds(1300); // Right wheel clockwise
  delay(3000); // ...for 3 seconds
  servoLeft.detach(); // Stop sending servo signals
  servoRight.detach();
}

void loop() { /// Main loop auto-repeats
  // Empty, nothing needs repeating
}
