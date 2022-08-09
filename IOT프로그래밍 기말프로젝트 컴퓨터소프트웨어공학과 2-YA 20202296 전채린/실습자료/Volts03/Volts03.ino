/* Volts03 */
/* 밝은 빛에서 주행 멈추기 */
/* 1. 시리얼모니터로 전압값이 출력되도록 수정
 * 2. 어둔 광선과 밝은 광선에서의 전압을 측정
 * 3. 스케치에서, if(volts(A3) >3.5) 문장중 3.5 대신 중간값으로 대체
 * 4. 수정본을 아두이노로 업로드
 * 5. ABOT을 조명에서 떨어진 곳에 위치
 * 6. ABOT이 전진하도록 전원 스위치를 2의 위치로
 * 7. 불빛 아래 얼마나 가까이에서 멈추는지?
 * 8. ABOT이 밝은 불빛 바로 아래에서 멈추도록
 *    if(volts(A3) >…)문장에서 문턱(threshold)값을 조정
 */
#include <Servo.h> // Include servo library
Servo servoLeft; // Declare left and right servos
Servo servoRight;
void setup() { // Built-in initialization block
  Serial.begin(9600); // Set data rate 9600 bps
  tone(4, 3000, 1000); // Play tone for 1 second
  delay(1000); // Delay to finish tone
  servoLeft.attach(13); // Attach left signal to pin 13
  servoRight.attach(12); // Attach right signal to pin 12
  servoLeft.writeMicroseconds(1700); // Full speed forward
  servoRight.writeMicroseconds(1300);
}

void loop() { //Main loop auto-repeats
  Serial.print("A3 = "); // Display "A3 = "
  Serial.print(volts(A3)); // Display measured A3 volts
  Serial.println(" volts"); // Display " volts" & newline
  delay(1000); // Delay for 1 second
  
  if(volts(A3) > 1.5) { // If A3 voltage greater than 3.5
    servoLeft.detach(); // Stop servo signals
    servoRight.detach();
  }
}

float volts(int adPin) { // Measure volts at adPin, Returns floating voltage
  return float(analogRead(adPin)) * 5.0 / 1023.0;
}
