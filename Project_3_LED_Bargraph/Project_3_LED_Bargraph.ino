// by Tom Igoe
// This example code is in the public domain.
// http://www.arduino.cc/en/Tutorial/BarGraph

const int analogPin = A0; // Pin connected to the potentiometer
const int ledCount = 9; // Number of LEDs
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10}; // Pins connected to the LEDs
void setup() {
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT); // Set the LED pins as output
  }
}
// Start a loop
void loop() {
  int sensorReading = analogRead(analogPin); // Analog input
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    if (thisLed < ledLevel) { // Turn on LEDs in sequence
      digitalWrite(ledPins[thisLed], HIGH);
    }
    else { // Turn off LEDs in sequence
      digitalWrite(ledPins[thisLed], LOW);
    }
  }
}
