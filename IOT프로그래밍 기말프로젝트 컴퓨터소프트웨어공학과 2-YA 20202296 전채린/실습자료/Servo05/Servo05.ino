/* Servo05 */
/* 최대 속도로 13번 서보는 3초동안 시계방향 회전 후 1초 정지 후 
 *  2초동안 반시계방향으로 회전 후 정지하며, 
 12번 서보는 동시에 13번 서보와 반대 방향으로 회전하도록 구현. */
#include <Servo.h> // Include servo library
Servo servoLeft; // Declare left servor
Servo servoRight; // Declare right servo

void setup() // Built in initialization block
{
  servoLeft.attach(13); // Attach left signal to pin 13
  servoRight.attach(12); // Attach right signal to pin 12
  servoLeft.writeMicroseconds(1700); // 1.7 ms full speed counterclockwise
  servoRight.writeMicroseconds(1700); // 1.7 ms full speed counterclockwise
  delay(3000);
  servoLeft.writeMicroseconds(1500); // 1.5 ms stay still sig, pin 13
  servoRight.writeMicroseconds(1500); // 1.5 ms stay still sig, pin 13
  delay(1000);
  servoLeft.writeMicroseconds(1300); // 1.3 ms full speed clockwise
  servoRight.writeMicroseconds(1300); // 1.3 ms full speed clockwise
  delay(2000);
  servoLeft.writeMicroseconds(1500); // 1.5 ms stay still sig, pin 13
  servoRight.writeMicroseconds(1500); // 1.5 ms stay still sig, pin 13
}

void loop() // Main loop auto-repeats
{ // Empty, nothing needs repeating
}
