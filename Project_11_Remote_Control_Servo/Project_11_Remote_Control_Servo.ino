// IR Library Copyright Ken Shirriff
// Used with kind permission, http://arcfn.com
#include <Servo.h> // Include the Servo library
#include <IRremote.h> // Include the IRremote library
unsigned long Value1 = 0xFFA05F; // Change this to your value
unsigned long Value2 = 0xFF50AF; // Change this to your value
unsigned long value3 = 0xFF807F; // Change this to your value
unsigned long value4 = 0xFF609F; // Change this to your value
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servo1;
Servo servo2;
void setup() { // Set up routine
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the IR receiver
  servo1.attach(10); // Pin connected to servo 1
  servo2.attach(9); // Pin connected to servo 2
}
void loop() { // Loop routine runs forever
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  if (results.value == Value1) { // If remote code matches value 1,
    // then move the servo
    servo1.write(160);
  }
  else if (results.value == Value2) { // If remote code matches
    // value 2, then move the
    // servo, etc.
    servo1.write(70);
  }
  else if (results.value == value3) {
    servo2.write(70);
  }
  else if (results.value == value4) {
    servo2.write(160);
  }
}
