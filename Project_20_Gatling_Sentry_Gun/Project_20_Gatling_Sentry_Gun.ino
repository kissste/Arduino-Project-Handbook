
#include <NewPing.h> // Call NewPing library
#include <Servo.h> // Call Servo library
#define trigPin 12 // Pin connected to ultrasonic sensor Trig
#define echoPin 13 // Pin connected the ultrasonic sensor Echo
#define MAX_DISTANCE 500
NewPing sonar(trigPin, echoPin, MAX_DISTANCE);
int blaster = 3; // Pin connected to the blaster
int angle = 0; // Set servo position in degrees
Servo servo;
void setup() {
  Serial.begin (115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(blaster, OUTPUT);
  servo.attach(9); // Pin connected to servo
}
void loop() {
  int duration, distance, pos = 0, i;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // trigPin sends a ping
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // echoPin receives the ping
  distance = (duration / 2) / 29.1;
  Serial.print(distance);
  Serial.println(" cm");
  if (distance <= 15) { // If distance is less than 15
    digitalWrite(blaster, HIGH); // Blaster will fire
    servo.write(90);
  }
  else {
    digitalWrite(blaster, LOW); // Otherwise blaster won't activate
    for (angle = 0; angle < 180; angle++) { // Sweep the servo
      servo.write(angle);
      delay(15);
    }
    for (angle = 180; angle > 0; angle--) {
      servo.write(angle);
    }
    delay(450);
  }
}
