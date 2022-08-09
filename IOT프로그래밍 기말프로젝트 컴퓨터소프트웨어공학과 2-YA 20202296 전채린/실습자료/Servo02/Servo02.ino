/* Servo02 */
/* 서보모터 동일 시계방향 회전 */
#include <Servo.h> // Include servo library
Servo servoLeft; // Declare left servo
Servo servoRight; // Declare right servo

void setup() // Built in initialization block
{
  servoLeft.attach(13); // Attach left signal to pin 13
  servoLeft.writeMicroseconds(1300); // 1.3 ms full speed clockwise
  servoRight.attach(12); // Attach right signal to pin 12
  servoRight.writeMicroseconds(1300); // 1.3 ms full speed clockwise
}

void loop() // Main loop auto-repeats
{ // Empty, nothing needs repeating
}
