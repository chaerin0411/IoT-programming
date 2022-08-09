/* Volts01 */
/* 포토Tr. 수신 광을 전압으로 */
/* 포토트랜지스터로 수신되는 광의 세기를 전압의 크기로 하이퍼터미널 화면에 표시할 수 있다. */
void setup() { // Built-in initialization block
  Serial.begin(9600); // Set data rate 9600 bps
}

void loop() { // Main loop auto-repeats
  Serial.print("A3 = "); // Display "A3 = "
  Serial.print(volts(A3)); // Display measured A3 volts
  Serial.println(" volts"); // Display " volts" & newline
  delay(1000); // Delay for 1 second
}

float volts(int adPin) // Measures volts at adPin, Returns floating point voltage
{
  return float(analogRead(adPin)) * 5.0 / 1023.0;
}
