int ledPin = 13; // Pin connected to LED
int inputPin = 2; // Pin connected to PIR sensor
int pirState = LOW; // Start PIR state LOW with no motion
int val = 0; // Variable for reading the pin status
int pinSpeaker = 10; // Pin connected to piezo
void setup() {
  pinMode(ledPin, OUTPUT); // Set LED as output
  pinMode(inputPin, INPUT); // Set sensor as input
  pinMode(pinSpeaker, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  val = digitalRead(inputPin); // Read PIR input value
  if (val == HIGH) { // Check if input is HIGH
    digitalWrite(ledPin, HIGH); // If it is, turn ON LED
    playTone(300, 160);
    delay(150);
    if (pirState == LOW) {
      // Print to the Serial Monitor if motion detected
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // If input is not HIGH,
    // turn OFF LED
    playTone(0, 0);
    delay(300);
    if (pirState == HIGH) {
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}
void playTone(long duration, int freq) { // Duration in ms,
  // frequency in Hz
  duration *= 1000;
  int period = (1.0 / freq) * 1000000;
  long elapsed_time = 0;
  while (elapsed_time < duration) {
    digitalWrite(pinSpeaker, HIGH);
    delayMicroseconds(period / 2);
    digitalWrite(pinSpeaker, LOW);
    delayMicroseconds(period / 2);
    elapsed_time += (period);
  }
}
