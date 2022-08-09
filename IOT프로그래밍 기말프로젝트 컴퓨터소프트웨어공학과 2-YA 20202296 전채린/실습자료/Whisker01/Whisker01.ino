/* Whisker01 */
/* 더듬이 테스트 스케치 */
void setup() { // Built-in initialization block
  tone(4,3000, 1000); // Play tone for 1 second
  delay(1000); // Delay to finish tone
  pinMode(7, INPUT); // Set right whisker pin to input
  pinMode(4, INPUT); // Set left whisker pin to input
  Serial.begin(9600);
}

void loop() { // Main loop auto-repeats
  Serial.print(digitalRead(5)); // Display wLeft
  Serial.println(digitalRead(7)); // Display wRight 
  delay(50); // Pause for 50 ms
}
