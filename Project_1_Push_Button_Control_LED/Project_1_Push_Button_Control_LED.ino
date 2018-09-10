// by DojoDave <http://www.0j0.org> modified 30 Aug 2011 by Tom Igoe
// This example code is in the public domain.
// http://www.arduino.cc/en/Tutorial/Button

const int buttonPin = 2; // Pin connected to button
const int ledPin = 13; // Pin connected to LED
int buttonState = 0; // Give button a value
void setup() { // Setup function
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  pinMode(buttonPin, INPUT); // Set button pin as input
}
// Loop function
void loop() {
  buttonState = digitalRead(buttonPin); // Read input from pin 2
  if (buttonState == HIGH) { // If button is pressed, set as HIGH
    digitalWrite(ledPin, HIGH); // Turn on LED
  }
  else {
    digitalWrite(ledPin, LOW); // Otherwise turn off LED
  }
}
