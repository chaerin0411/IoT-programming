/* IRLED02 */
void setup() { // Built-in initialization block
  tone(4, 3000, 1000); // Play tone for 1 second
  delay(1000); // Delay to finish tone
  pinMode(10, INPUT); // Left IR LED & Receiver
  pinMode(9, OUTPUT);
  pinMode(3, INPUT); // Right IR LED & Receiver
  pinMode(2, OUTPUT);
  Serial.begin(9600); // Set data rate to 9600 bps
}

void loop() { // Main loop auto-repeats
  int irLeft = irDetect(9, 10, 38000); // Check for object on left
  int irRight = irDetect(2, 3, 38000); // Check for object on right
  Serial.print(irLeft); // Display 1/0 no detect/detect
  Serial.println(irRight); // Display 1/0 no detect/detect
  delay(100); // 0.1 second delay
}

// IR Object Detection Function
int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, 8); // IRLED 38 kHz for at least 1 ms
  delay(1); // Wait 1 ms
  int ir = digitalRead(irReceiverPin); // IR receiver -> ir variable
  delay(1); // Down time before recheck
  return ir; // Return 1 no detect, 0 detect
}
