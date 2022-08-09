/* Servo13 */
/* 사용자 함수로 주행하기 */
/* 30cm 전진, 90도 우회전 반복하여 제자리로 돌아오기 */
#include <Servo.h> // Include servo library
Servo servoLeft; // Declare left and right servos
Servo servoRight;
void setup() { // Built-in initialization block
  tone(4, 3000, 1000); // Play tone for 1 seconds
  delay(1000); // Delay to finish tone
  servoLeft.attach(13); // Attach left signal to pin 13
  servoRight.attach(12); // Attach right signal to pin 12
  for(int i=0; i<4; i++) {
    maneuver(200, 200, 2000); // Forward 2 seconds
    maneuver(200, -200, 600); // Right 0.6 seconds
  }
  maneuver(0, 0, -1); // Disable servors
}

void loop() { // Main loop auto-repeats
  // Empty, nothing needs repeating
}
void maneuver(int speedLeft, int speedRight, int msTime)
{ // speedLeft, speedRight ranges: Backward Linear Stop Linear Forward
  // -200 -100...0...100 200
  servoLeft.writeMicroseconds(1500+speedLeft); // Set left servo speed
  servoRight.writeMicroseconds(1500-speedRight); // Set right servo speed
  if(msTime == -1) // if msTime = -1
  {
    servoLeft.detach(); // Stop servo signals
    servoRight.detach();
  }
  delay(msTime); // Delay for msTime
}
