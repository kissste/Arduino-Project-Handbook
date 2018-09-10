int buzzPin = 11; // Pin connected to the buzzer
int LED = 13; // Pin connected to the LED
void setup() {
  pinMode(buzzPin, OUTPUT); // Set pin as output
  pinMode(LED, OUTPUT); // Set pin as output
}
void loop() {
  if (analogRead(0) > 850) { // Set this value depending on the
    // values of your photoresistor
    digitalWrite(buzzPin, HIGH); // If value is above 850,
    // turn the buzzer ON
    digitalWrite(LED, LOW); // If value is above 850,
    // turn the LED OFF
    delay(1000); // Wait for 1 second
    digitalWrite(buzzPin, LOW);
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(buzzPin, LOW); // If value is 850 or below (light
    // shining on photoresistor), the
    // buzzer is off
    digitalWrite(LED, HIGH); // If value is 850 or below (light
    // shining on photoresistor), the
    // LED is on
  }
}
