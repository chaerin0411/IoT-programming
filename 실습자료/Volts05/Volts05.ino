/* Volts05 */
/* 커패시터 이용 빛 감지 */
/* 좌우를 같이 측정하도록 스케치를 변경 */
void setup() { // Built-in initialization block
  tone(4, 3000, 1000); // Play tone for 1 second
  delay(1000); // Delay to finish tone
  Serial.begin(9600); // Set data rate to 9600 bps
}

void loop() { // Main loop auto-repeats
  long tLeft = rcTime(8); // Left rcTime -> tLeft
  long tRight = rcTime(6); // Right rcTime -> tRight
  Serial.print("tLeft = "); // Display tLeft label
  Serial.print(tLeft); // Display tLeft value
  Serial.println(" us"); // Display tLeft units + newline
  Serial.print("tRight = "); // Display tRight label
  Serial.print(tRight); // Display tRight value
  Serial.println(" us"); // Display tLeft units + newline
  delay(1000); // 1 second delay
}

long rcTime(int pin) // returns decay time
{
  pinMode(pin, OUTPUT); // Charge capacitor
  digitalWrite(pin, HIGH); // by setting pin output-high
  delay(1); // for 5 ms
  pinMode(pin, INPUT); // Set pin to input
  digitalWrite(pin, LOW); // with no pullup
  long time = micros(); // Mark the time
  while(digitalRead(pin)); // Wait for voltage < threshold
  time = micros() - time; // Calculate decay time
  return time; // Return decay time
}
