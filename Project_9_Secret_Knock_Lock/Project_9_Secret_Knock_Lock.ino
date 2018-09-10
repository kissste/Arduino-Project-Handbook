/*Created 18 September 2012
  by Scott Fitzgerald Thanks to Federico Vanzati for improvements
  http://arduino.cc/starterKit
  This example code is part of the public domain.
*/
#include <Servo.h>
Servo servo9; // Pin connected to servo mpo
const int piezo = A0; // Pin connected to piezo
const int switchPin = 2; // Pin connected to servo
const int yellowLed = 3; // Pin connected to yellow LED
const int greenLed = 4; // Pin connected to green LED
const int redLed = 5; // Pin connected to red LED
int knockVal; // Value for the knock strength
int switchVal;
const int quietKnock = 10; // Set min value that will be accepted
const int loudKnock = 100; // Set max value that will be accepted
boolean locked = false; // A true or false variable
int numberOfKnocks = 0; // Value for number of knocks
void setup() {
  servo9.attach(9);
  pinMode(yellowLed, OUTPUT); // Set LED pins as outputs
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(switchPin, INPUT); // Set servo pin as input
  Serial.begin(9600);
  digitalWrite(greenLed, HIGH); // Green LED is lit when the
  // sequence is correct
  servo9.write(0);
  Serial.println("The box is unlocked!");
}
void loop() {
  if (locked == false) {
    switchVal = digitalRead(switchPin);
    if (switchVal == HIGH) {
      locked = true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      servo9.write(90);
      Serial.println("The box is locked!");
      delay(1000);
    }
  }
  if (locked == true) {
    knockVal = analogRead(piezo); // Knock value is read by analog pin
    if (numberOfKnocks < 3 && knockVal > 0) {
      if (checkForKnock(knockVal) == true) { // Check for correct
        // number of knocks
        numberOfKnocks++;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println(" more knocks to go");
    }
    if (numberOfKnocks >= 3) { // If 3 valid knocks are detected,
      // the servo moves
      locked = false;
      servo9.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("The box is unlocked!");
    }
  }
}
boolean checkForKnock(int value) { // Checks knock value
  if (value > quietKnock && value < loudKnock) { // Value needs to be
    // between these
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true;
  }
  else { // If value is false then send this to the IDE serial
    Serial.print("Bad knock value ");
    Serial.println(value);
    return false;
  }
}
