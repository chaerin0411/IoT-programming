/* Whisker03 */
/* 더듬이 주행 스케치 */
#include <Servo.h> // Include servo library
Servo servoLeft; // Declare left and right servos
Servo servoRight;
void setup() { // Built-in initialization block
  pinMode(7, INPUT); // Set right whisker pin to input
  pinMode(5, INPUT); // Set left whisker pin to input
  pinMode(8, OUTPUT); // Left LED indicator -> output
  pinMode(2, OUTPUT); // Right LED indicator -> output

  tone(4, 3000, 1000); // Play tone for 1 second
  delay(1000); // Delay to finish tone

  servoLeft.attach(13); // Attach left signal to pin 13
  servoRight.attach(12); // Attach right signal to pin 12

  Serial.begin(9600); // Set serial data rate to 9600
}

void loop() { // Main loop auto-repeats
  byte wLeft = digitalRead(5); // Copy left result to wLeft
  byte wRight = digitalRead(7); // Copy right result to wRight

  if(wLeft == 0) // If left whisker contact
    digitalWrite(8, HIGH); // Left LED on
   else // If no left whisker contact
    digitalWrite(8, LOW); // Left LED off
   if(wRight == 0) // If right whisker contact
    digitalWrite(2, HIGH); // Right LED on
   else // If no right whisker contact
    digitalWrite(2, LOW); // Left LED off
   if((wLeft == 0) && (wRight == 0)) { // if both whiskers contact
    backward(1000); // Back up 1 second
    turnLeft(800); // Turn left about 120 degrees
   }
   else if(wLeft == 0) { // If only left whisker contact
    backward(1000); // Back up 1 second
    turnRight(400); // Turn right about 60 degrees
   }
   else if(wRight == 0) { // If only right whisker contact
    backward(1000); // Back up 1 second
    turnLeft(400); // Turn left about 60 ms
   }
   else // Otherwise, no whisker contact
    forward(20); // Forward 1/50 of a second    
}

void forward(int time) // Forward function
{
  servoLeft.writeMicroseconds(1700); // Left wheel counterclockwise
  servoRight.writeMicroseconds(1300); // Right wheel clockwise
  delay(time); // Maneuver for time ms
}

void turnLeft(int time) // Left turn function
{
  servoLeft.writeMicroseconds(1300); // Left wheel clockwise
  servoRight.writeMicroseconds(1300); // Right wheel clockwise
  delay(time); // Maneuver for time ms
}

void turnRight(int time) // Right turn function
{
  servoLeft.writeMicroseconds(1700); // Left wheel counterclockwise
  servoRight.writeMicroseconds(1700); // Right wheel counterclockwise
  delay(time); // Maneuver for time ms
}

void backward(int time) // Backward function
{
  servoLeft.writeMicroseconds(1300); // Left wheel clockwise
  servoRight.writeMicroseconds(1700); // Right wheel counterclockwise
  delay(time); // Maneuver for time ms
}
