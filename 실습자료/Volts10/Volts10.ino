/* Volts10 */
/* ABOT 유도 스케치 실습과제3 */
/*
 * 1) ABOT이 밝은쪽을 쫓아가서 빛에서 멈추도록
 */
#include <Servo.h> // Include servo library

Servo servoLeft; // Declare left and right servos
Servo servoRight;

void setup() { // Built-in initialization block
  tone(4, 3000, 1000); // Play tone for 1 second
  delay(1000); // Delay to finish tone
  servoLeft.attach(13); // Attach left signal to pin 13
  servoRight.attach(12); // Attach right signal to pin 12
  Serial.begin(9600); // Set data rate to 9600 bps
}

void loop() { // Main loop auto-repeats
  float tLeft = float(rcTime(8)); // Get left light & make float
  float tRight = float(rcTime(6)); // Get right light & make float
  float ndShade; // Normalized differential shade 
  ndShade = tRight/(tLeft+tRight)-0.5; // Calculate it and subtract 0.5
  int speedLeft, speedRight; // Declare speed variables
  
  if(ndShade > 0.0) // Shade on right?
  { // Slow down left wheel
     speedLeft = int(200.0 - (ndShade * 1000.0));
     speedLeft = constrain(speedLeft, -200, 200);
     speedRight = 200; // Full speed right wheel

     if(tLeft < 100) {
      servoLeft.detach(); // Stop servo signals
      servoRight.detach();
     }
  }
  else // Shade on left?
  { // Slow down right wheel
    speedRight =  int(200.0 + (ndShade * 10000.0));
    speedRight = constrain(speedRight, -200, 200);
    speedLeft = 200; // Full speed left wheel

    if(tRight < 100) {
      servoLeft.detach(); // Stop servo signals
      servoRight.detach();
     }
  }
  maneuver(speedLeft, speedRight, 20); // Set wheel speeds
  
  // Display heading
  Serial.println("tLeft  ndShade  tRight");
  Serial.print(tLeft); // Display tLeft value
  Serial.print("  "); // Display spaces
  Serial.print(ndShade); // Display ndShade value
  Serial.print("  "); // Display more spaces
  Serial.print(tRight); // Display tRight value
  Serial.println("  "); // Add an extra newline
  delay(1000); // 1 second delay
}

long rcTime(int pin) // returns decay time
{
  pinMode(pin, OUTPUT); // Charge capacitor
  digitalWrite(pin, HIGH); // by setting pin output-high
  delay(5); // for 5 ms
  pinMode(pin, INPUT); // Set pin to input
  digitalWrite(pin, LOW); // with no pullup
  long time = micros(); // Mark the time
  while(digitalRead(pin)); // Wait for voltage < threshold
  time = micros() - time; // Calculate decay time
  return time; // Return decay time
}

// maneuver function
void maneuver(int speedLeft, int speedRight, int msTime)
{
  servoLeft.writeMicroseconds(1500 + speedLeft); // Set left servo speed
  servoRight.writeMicroseconds(1500 - speedRight); // Set right servo speed
  if(msTime == -1) // if msTime = -1
  {
    servoLeft.detach(); // Stop servo signals
    servoRight.detach();
  }
  delay(msTime); // Delay for msTime
}
