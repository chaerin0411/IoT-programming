/* Whisker02 */
/* 더듬이 필드 테스트 스케치(1) */
void setup() { // Built-in initialization block
  pinMode(7, INPUT); // Set right whisker pin to input
  pinMode(5, INPUT); // Set left whisker pin to input
  pinMode(8, OUTPUT); // Left LED indicator -> output
  pinMode(2, OUTPUT); // Right LED indicator -> output
  tone(4, 3000, 1000); // Play tone for 1 second
  delay(1000);
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
    digitalWrite(2, LOW); // Right LED off
  Serial.print(wLeft); // Display wLeft
  Serial.println(wRight); // Display wRight
  delay(50); // Pause for 50 ms
}
