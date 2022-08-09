/* Multiple_LED */
int ledPins[]={2,3,4,5,6,7,8,9};
void setup() {
  for(int i=0; i<8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  oneAfterAnotherNoLoop();
}
void oneAfterAnotherNoLoop() {
  int delayTime=100;
  digitalWrite(ledPins[0],HIGH);
  delay(500);
  digitalWrite(ledPins[1],HIGH);
  delay(500);
  digitalWrite(ledPins[2],HIGH);
  delay(500);
  digitalWrite(ledPins[3],HIGH);
  delay(500);
  digitalWrite(ledPins[4],HIGH);
  delay(500);
  digitalWrite(ledPins[5],HIGH);
  delay(500);
  digitalWrite(ledPins[6],HIGH);
  delay(500);
  digitalWrite(ledPins[7],HIGH);
  delay(500);
  digitalWrite(ledPins[0],LOW);
  delay(500);
  digitalWrite(ledPins[1],LOW);
  delay(500);
  digitalWrite(ledPins[2],LOW);
  delay(500);
  digitalWrite(ledPins[3],LOW);
  delay(500);
  digitalWrite(ledPins[4],LOW);
  delay(500);
  digitalWrite(ledPins[5],LOW);
  delay(500);
  digitalWrite(ledPins[6],LOW);
  delay(500);
  digitalWrite(ledPins[7],LOW);
  delay(500);
}
