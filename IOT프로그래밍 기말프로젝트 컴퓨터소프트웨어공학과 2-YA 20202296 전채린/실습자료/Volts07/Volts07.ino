/* Volts07 */
/* ABOT 유도 스케치 */
/*
 * (1) 로봇의 우측 측면으로 그림자가 감지
 * (2) ABOT이 어둠으로부터 멀어지게 회전하도록 왼쪽 바퀴 속도를 낮춤
 * (3) ndShade * 1000.0는 200으로부터 차감
 * (4) int(200.0 - (ndShade x 1000.0)는 유동 소수점 해답을 정수형으로 바꿈
 * (5) speedLeft가 제한구역을 벗어나지 않도록 constrain 함수를 사용
 */
#include <Servo.h> // Include servo library

Servo servoLeft; // Declare left and right servos
Servo servoRight;

void setup() { // Built-in initialization block
  tone(4, 3000, 1000); // Play tone for 1 second
  delay(1000); // Delay to finish tone
  servoLeft.attach(13); // Attach left signal to pin 13
  servoRight.attach(12); // Attach right signal to pin 12
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
  }
  else // Shade on left?
  { // Slow down right wheel
    speedRight =  int(200.0 + (ndShade * 10000.0));
    speedRight = constrain(speedRight, -200, 200);
    speedLeft = 200; // Full speed left wheel
  }
  maneuver(speedLeft, speedRight, 20); // Set wheel speeds
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
