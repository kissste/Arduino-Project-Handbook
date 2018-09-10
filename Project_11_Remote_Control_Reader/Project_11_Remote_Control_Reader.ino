// IR Library Copyright Ken Shirriff
// Used with kind permission, http://arcfn.com
#include <IRremote.h> // Use library
int receiver = 11; // Pin connected to receiver
IRrecv irrecv(receiver);
decode_results results;
void setup() {
  Serial.begin(9600); // Show keypresses in IDE
  irrecv.enableIRIn(); // Start up receiver
}
void loop() {
  if (irrecv.decode(&results)) { // If there's an input, decode value
    Serial.println(results.value, HEX); // Display button value on
    // Serial Monitor in
    // hexadecimal format
    irrecv.resume(); // Receive next value
  }
}
