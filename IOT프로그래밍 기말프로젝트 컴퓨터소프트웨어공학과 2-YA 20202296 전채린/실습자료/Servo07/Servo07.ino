/* Servo07 */
/* 바퀴 회전 테스트 */
#include <Servo.h> // Include servo library
Servo servoLeft; // Declare left servo

void setup() { // Built in initialization block
  servoLeft.attach(13); // Attach left signal to pin 13
  servoLeft.writeMicroseconds(1700); // left wheel counterclockwise
  delay(3000); // ...for 3 seconds
  servoLeft.writeMicroseconds(1500); // Stay still
  delay(1000); // ...for 1 seconds
  servoLeft.writeMicroseconds(1300); // left wheel clockwise
  delay(3000); // ...for 3 seconds
  servoLeft.writeMicroseconds(1500); // left wheel counterclockwise
}

void loop() { // Main loop auto-repeats
 // Empty, nothing needs repeating
}
