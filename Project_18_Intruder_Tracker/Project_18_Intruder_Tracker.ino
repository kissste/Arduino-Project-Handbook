/* NewPing Library created by Tim Eckel teckel@leethost.com.
  Copyright 2012 License: GNU GPL v3
  http://www.gnu.org/licenses/gpl-3.0.html
*/
#include <NewPing.h>    //  This calls the NewPing library
#include <Servo.h>      //  Calls the Servo library
#define trigPin 12	//  Trig pin attached to Arduino 12
#define echoPin 13	//  Echo pin attached to Arduino 13
#define MAX_DISTANCE 500

NewPing sonar(trigPin, echoPin, MAX_DISTANCE);

int greenLed = 3, redLed = 2; // Green LED to 3, Red to 2

int pos = 20;
Servo myservo;

void setup() {
  Serial.begin (115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  myservo.attach(9);          // Servo attached to pin 9

}
void loop() {
  int duration, distance, pos = 0, i;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  // Trig sends a ping
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  // Echo receives the ping
  distance = (duration / 2) / 29.1;
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 15) 			//  If distance is less than 15
  {
    digitalWrite(greenLed, LOW);  // Green LED goes off
    digitalWrite(redLed, HIGH);   // Red LED on
    myservo.write(180);		   // Move servo
    delay(450);
    digitalWrite(redLed, LOW);
    myservo.write(90);
    delay(450);
    digitalWrite(redLed, HIGH);
    myservo.write(0);
    delay(450);
    digitalWrite(redLed, LOW);
    myservo.write(90);
  }
  else { 				  //  Otherwise do this
    digitalWrite(redLed, LOW);    // Red LED off
    digitalWrite(greenLed, HIGH); // Green LED on
    myservo.write(90);
  }

  delay(450);
}

