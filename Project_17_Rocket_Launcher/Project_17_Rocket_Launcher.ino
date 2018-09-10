// Ardunaut, Arduining.com reproduced with kind permission
#define FuseTIME 1500 // Duration of fuse current in ms
#include <SoftwareSerial.h> // Call the SoftwareSerial library
#define Fuse 7 // Pin connected to fuse (your LED or igniter)
#define GoButt 6 // Pin connected to Launch button
#define ArmButt 5 // Pin connected to Arm button
#define BuzzPin 4 // Pin connected to piezo buzzer
#define TXdata 3 // Pin connected to RX of display
#define RXdata 2 // Not used
#define SetPot 0 // Analog pin connected to potentiometer
SoftwareSerial mySerialPort(RXdata, TXdata);
void setup() {
  pinMode(TXdata, OUTPUT);
  pinMode(RXdata, INPUT);
  pinMode(Fuse, OUTPUT);
  pinMode(ArmButt, INPUT); // Set Arm button pin to input
  pinMode(GoButt, INPUT); // Set Launch button pin to input
  digitalWrite(Fuse, LOW); // Open igniter circuit
  digitalWrite(ArmButt, HIGH); // Turn on resistor
  digitalWrite(GoButt, HIGH); // Turn on resistor
  mySerialPort.begin(9600);
  delay(10); // Wait for serial display startup
  mySerialPort.print("v"); // Reset the serial display
  mySerialPort.print("z"); // Brightness
  mySerialPort.write(0x40); // 3/4 intensity
  mySerialPort.print("w"); // Decimal point control
  mySerialPort.write(0x10); // Turn on colon in serial display
}
int DownCntr; // Countdown (1/10 seconds)
int Go = 0; // Stopped
void loop() {
  if (!digitalRead(GoButt) || !digitalRead(ArmButt)) {
    Go = 0; // Abort the countdown
    tone(BuzzPin, 440, 1500);
    delay(1500);
  }
  if (Go == 0) {
    WaitARM();
    WaitGO();
  }
  ShowTimer();
  if (DownCntr > 50) {
    if (DownCntr % 10 == 0)tone(BuzzPin, 1000, 50); // One beep/sec
  }
  else if (DownCntr % 2 == 0)tone(BuzzPin, 1000, 50); // Beep faster
  if (DownCntr == 0) {
    tone(BuzzPin, 440, FuseTIME); // Launch tone
    digitalWrite(Fuse, HIGH); // Close the fuse circuit
    delay(FuseTIME);
    digitalWrite(Fuse, LOW); // Open the fuse circuit
    Go = 0;
  }
  while (millis() % 100); // Wait 50 ms
  delay(50);
  DownCntr--;
}
void WaitGO() {
  ShowTimer();
  while (digitalRead(GoButt));
  Go = 1;
  delay(20);
  while (!digitalRead(GoButt)); // Debounce Launch button
}
void ReadTimer() {
  DownCntr = map(analogRead(SetPot), 0, 1023, 5, 60);
  DownCntr *= 10;
}
void ShowTimer() {
  String seconds = String (DownCntr, DEC);
  while (seconds.length() < 3)seconds = "0" + seconds; // Format to
  // 3 numbers
  mySerialPort.print(seconds); // Write to serial display
  mySerialPort.print(" "); // Last digit off
}
void WaitARM() {
  while (digitalRead(ArmButt) == 1) {
    ReadTimer();
    delay(50);
    ReadTimer();
    ShowTimer();
    delay(150);
  }
  Go = 0;
  ShowTimer();
  tone(BuzzPin, 2000, 150);
  delay(200);
  tone(BuzzPin, 2000, 150);
  delay(200);
  tone(BuzzPin, 2000, 150);
  delay(20);
  while (!digitalRead(ArmButt)); // Debounce Arm button
}
