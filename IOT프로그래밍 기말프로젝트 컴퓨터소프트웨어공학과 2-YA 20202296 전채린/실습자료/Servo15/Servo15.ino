/* Servo15 */
/* 로봇이 시계 방향으로 원 주행을 하다가 
 *  바깥쪽 더듬이가 터치될 때마다 큰 원을 그리고
안쪽 더듬이가 터치될 떄마다 작은 원을 그리는데 
작은 원은 오른쪽 바퀴가 정지할 때까지,
큰 원은 직선이 될 때까지만 변하도록 */
#include <Servo.h> //Include servo library
Servo servoLeft; // Declare left and right servos
Servo servoRight;
byte counter; // For counting alternate corners
byte n=0;
 
void setup() { // Built-in initialization block
  pinMode(7, INPUT); // Set right whisker pin to input
  pinMode(5, INPUT); // Set left whisker pin to input
  
  tone(4, 3000, 1000); // Play tone for 1 second
  delay(1000); // Delay to finish tone

  servoLeft.attach(13); // Attach left signal to pin 13
  servoRight.attach(12); // Attach right signal to pin 12
  counter = 0; // Initialize counter to 0
}

void loop() { // Main loop auto-repeats
  byte wLeft = digitalRead(5); // Copy left result to wLeft
  byte wRight = digitalRead(7); // Copy right result to wRight

  // no whisker contact
  turnRight(2400); // Turn left about 360 degrees
  
  if(n <= counter) {
    // Whisker Navigation
    if(wLeft == 0) { // If only left whisker contact 
      for(int speed=0; speed<=200; speed+=2) { // Ramp up to full speed
        servoLeft.writeMicroseconds(1700); 
        servoRight.writeMicroseconds(1500-speed);// us = 1500, 1498,...1302, 1300
        delay(100); // 100 ms at each speed
      }
    }
    else if(wRight == 0) { // If only right whisker contact
      for(int speed=200; speed>=0; speed-=2) { // Ramp down to stop
        servoLeft.writeMicroseconds(1500+speed); // us = 1700, 1698,...1502, 1500
        servoRight.writeMicroseconds(1500); 
        delay(100); // 100 ms at each speed
      }
    }
    else {
      turnRight(2400); // Turn left about 360 degrees
    }
    counter++; // Increase count by one
    n++; // Increase n by one
      }
}
     
void turnRight(int time) // Right turn function
{
  servoLeft.writeMicroseconds(1700); // Left wheel counterclockwise
  servoRight.writeMicroseconds(1700); // Right wheel counterclockwise
  delay(time); // Maneuver for time ms
}
