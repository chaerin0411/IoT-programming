/* IOT프로그래밍 기말프로젝트 청소로봇 스케치코드 컴퓨터소프트웨어공학과 2-YA 20202296 전채린 */
/* CleanUpRobot */

#include <Servo.h> // Include servo library
#include <Wire.h> // Include wire library
#include <LiquidCrystal_I2C.h> // lcd 1602 i2c library
Servo servoLeft; // Declare left and right servos                            
Servo servoRight;
#define trigPin 13 // Declare trigPin 13 and echoPin 12
#define echoPin 12
LiquidCrystal_I2C lcd(0x27, 16, 2);  

int irDetect(int irLedPin, int irReceiverPin, long frequency);
void maneuver(int speedLeft, int speedRight, int msTime);
long rcTime(int pin);
float volts(int adPin);

long microsecondsToCentimeters(long microseconds)
{
    // The speed of sound is 340 m/s or 29 microseconds per centimeter.
    // The ping travels out and back, so to find the distance of the
    // object we take half of the distance travelled.
    
    return microseconds / 29 / 2;
}

void setup() {            // Built-in initialization block
  pinMode(10, INPUT); pinMode(9, OUTPUT);//Left IR LED & Receiver
  pinMode(3, INPUT); pinMode(2, OUTPUT);//Right IR LED & Receiver
  pinMode(8, OUTPUT); pinMode(7, OUTPUT);// Indicator LEDs
  pinMode(trigPin, OUTPUT); // trigPin OUTPUT
  pinMode(echoPin, INPUT); // echoPin INPUT
  tone(4, 3000, 1000);      // Play tone for 1 second
  delay(1000);               // Delay to finish tone
  servoLeft.attach(13);      // Attach left signal to pin 13
  servoRight.attach(12);       // Attach right signal to pin 12
  lcd.begin(); // lcd start
  lcd.backlight(); // backlight on
  lcd.noCursor(); // no cursor
  lcd.noBlink(); // no blink cursor
}
 
void loop() {                 // Main loop auto-repeats
  long cm, duration;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  
  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  
  int irLeft = irDetect(9, 10, 38000);  // Check for object on left
  int irRight = irDetect(2, 3, 38000);// Check for object on right
  digitalWrite(8, !irLeft);      // LED states opposite of IR   
  digitalWrite(7, !irRight);
  
  if((irLeft == 0) && (irRight == 0)) { // If both sides detect
    maneuver(-100, -100, 20);      // Backward 20 milliseconds
    lcd.clear();
    lcd.print("Backward"); 
    if(cm < 10) {
      maneuver(100, 100, 20);      // Forward 20 ms
      lcd.clear();
      lcd.print("Forward");
    }
  }
  else if(irLeft == 0) {         // If only left side detects
      maneuver(100, -100, 20);        // Right for 20 ms
      lcd.clear();
      lcd.print("Right"); 
  }
  else if(irRight == 0) {       // If only right side detects
     maneuver(-100, 100, 20);         // Left for 20 ms
     lcd.clear();
     lcd.print("Left");
  }
  else {                         // Otherwise, no IR detects
    maneuver(100, 100, 20);          // Forward 20 ms
    lcd.clear();
    lcd.print("Forward");
  }

  if(volts(A3) > 3.5)           // If A3 voltage greater than 3.5
  { 
    servoLeft.detach();          // Stop servo signals
    servoRight.detach();    
    lcd.clear();
    lcd.print("Stop");
  }
  delay(50); // delay 50ms
}

int irDetect(int irLedPin, int irReceiverPin, long frequency)
{ 
  tone(irLedPin, frequency, 8);   // IRLED 38 kHz for at least 1 ms
  delay(1);                       // Wait 1 ms
  int ir = digitalRead(irReceiverPin); // IR receiver -> ir variable
  delay(1);                 // Down time before recheck
  return ir;                  // Return 1 no detect, 0 detect
}

void maneuver(int speedLeft, int speedRight, int msTime)
{ // speedLeft, speedRight ranges: Backward  Linear  
  // Stop  Linear   Forward
  //     -100......0......100
  // Set Left servo speed
  servoLeft.writeMicroseconds(1500 + speedLeft);
  // Set right servo speed
  servoRight.writeMicroseconds(1500 - speedRight);
  if(msTime==-1)               // if msTime = -1
  { 
    servoLeft.detach();         // Stop servo signals
    servoRight.detach();   
  }
  delay(msTime);               // Delay for msTime
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

float volts(int adPin) //Measures volts at adPin, Returns floating point voltage
{
  return float(analogRead(adPin)) * 5.0 / 1023.0;
}
