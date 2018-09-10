const int analogInPin = A0; // Analog input pin connected to the
// potentiometer
int sensorValue = 0; // Value read from the potentiometer
int timer = 0; // Delay value
// Set digital pins 12 and 11 as outputs
void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}
// Start a loop to turn LEDs on and off with a delay in between
void loop() {
  sensorValue = analogRead(analogInPin); // Read value from the
  // potentiometer
  timer = map(sensorValue, 0, 1023, 10, 500); // Delay 10ms to 500ms
  digitalWrite(12, HIGH); // LED turns on
  delay(timer); // Delay depending on potentiometer value
  digitalWrite(12, LOW); // LED turns off
  delay(timer);
  digitalWrite(12, HIGH);
  delay(timer);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(timer);
  digitalWrite(11, LOW);
  delay(timer);
  digitalWrite(11, HIGH);
  delay(timer);
  digitalWrite(11, LOW);
}
