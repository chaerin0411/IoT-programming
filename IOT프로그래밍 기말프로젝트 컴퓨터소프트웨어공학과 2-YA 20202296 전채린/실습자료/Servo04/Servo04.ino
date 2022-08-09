/* Servo04 */
/* 서보모터 속도 제어 */
#include <Servo.h> // Include servo library
Servo servoLeft; // Declare left servo
Servo servoRight; // Declare right servo

void setup() // Built in initialization block
{
  servoLeft.attach(13); // Attach left signal to pin 13
  servoLeft.writeMicroseconds(1520); // 1.7 ms full speed counterclockwise
  servoRight.attach(12); // Attach right signal to pin 12
  servoRight.writeMicroseconds(1480); // 1.3 ms full speed clockwise
}

void loop() // Main loop auto-repeats
{ // Empty, nothing needs repeating
}
