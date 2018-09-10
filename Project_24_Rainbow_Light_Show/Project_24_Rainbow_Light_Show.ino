/*
  Example 18.1 - experimenting with RGB LED matrix
  CC by-sa 3.0
  http://tronixstuff.wordpress.com/tutorials
*/
int latchpin = 10; // Connect to pin 12 on all shift registers
int clockpin = 13; // Connect to pin 11 on all shift registers
int datapin = 11; // Connect to pin 14 on shift register 2
int zz = 500; // Delay variable
int va[] = {
  1, 2, 4, 8, 16, 32, 64, 128, 255
};
int va2[] = {
  1, 3, 7, 15, 31, 63, 127, 255
};
void setup() {
  pinMode(latchpin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(datapin, OUTPUT);
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 0);
  shiftOut(datapin, clockpin, MSBFIRST, 0);
  shiftOut(datapin, clockpin, MSBFIRST, 0);
  shiftOut(datapin, clockpin, MSBFIRST, 0);
  digitalWrite(latchpin, HIGH);
  randomSeed(analogRead(0));
}
void allRed() { // Turn on all red LEDs
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Turn cathodes to full
  shiftOut(datapin, clockpin, MSBFIRST, 0); // Turn green to 0
  shiftOut(datapin, clockpin, MSBFIRST, 0); // Turn blue to 0
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Turn red to full
  digitalWrite(latchpin, HIGH);
}
void allBlue() { // Turn on all blue LEDs
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Turn cathodes to full
  shiftOut(datapin, clockpin, MSBFIRST, 0); // Turn green to 0
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Turn blue to full
  shiftOut(datapin, clockpin, MSBFIRST, 0); // Turn red to 0
  digitalWrite(latchpin, HIGH);
}
void allGreen() { // Turn on all green LEDs
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Cathodes
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Green
  shiftOut(datapin, clockpin, MSBFIRST, 0); // Blue
  shiftOut(datapin, clockpin, MSBFIRST, 0); // Red
  digitalWrite(latchpin, HIGH);
}
void allOn() { // Turn on all LEDs
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Cathodes
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Green
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Blue
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Red
  digitalWrite(latchpin, HIGH);
}
void allYellow() { // Turn on green and red LEDs (yellow)
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Cathodes
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Green
  shiftOut(datapin, clockpin, MSBFIRST, 0); // Blue
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Red
  digitalWrite(latchpin, HIGH);
}
void allAqua() { // Turn on green and blue LEDs (aqua)
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Cathodes
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Green
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Blue
  shiftOut(datapin, clockpin, MSBFIRST, 0); // Red
  digitalWrite(latchpin, HIGH);
}
void allPurple() { // Turn on blue and red LEDs (purple)
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Cathodes
  shiftOut(datapin, clockpin, MSBFIRST, 0); // Green
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Blue
  shiftOut(datapin, clockpin, MSBFIRST, 255); // Red
  digitalWrite(latchpin, HIGH);
}
void clearMatrix() { // Turn off all LEDs
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 0); // Cathodes
  shiftOut(datapin, clockpin, MSBFIRST, 0); // Green
  shiftOut(datapin, clockpin, MSBFIRST, 0); // Blue
  shiftOut(datapin, clockpin, MSBFIRST, 0); // Red
  digitalWrite(latchpin, HIGH);
}
void lostinspace() {
  for (int z = 0; z < 100; z++) {
    digitalWrite(latchpin, LOW);
    shiftOut(datapin, clockpin, MSBFIRST, va[random(8)]); // Cathodes
    shiftOut(datapin, clockpin, MSBFIRST, va[random(8)]); // Green
    shiftOut(datapin, clockpin, MSBFIRST, va[random(8)]); // Blue
    shiftOut(datapin, clockpin, MSBFIRST, va[random(8)]); // Red
    digitalWrite(latchpin, HIGH);
    delay(100);
  }
}
void displayLEDs(int rr, int gg, int bb, int cc, int dd) {
  // Insert the base-10 values into the shiftOut functions
  // and hold the display for dd milliseconds
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, cc); // Cathodes
  shiftOut(datapin, clockpin, MSBFIRST, gg); // Green
  shiftOut(datapin, clockpin, MSBFIRST, bb); // Blue
  shiftOut(datapin, clockpin, MSBFIRST, rr); // Red
  digitalWrite(latchpin, HIGH);
  delay(dd);
}
void loop() { // Light up the whole display in solid colors
  allOn();
  delay(zz);
  delay(zz);
  allRed();
  delay(zz);
  delay(zz);
  allGreen();
  delay(zz);
  delay(zz);
  allBlue();
  delay(zz);
  delay(zz);
  allPurple();
  delay(zz);
  delay(zz);
  allYellow();
  delay(zz);
  delay(zz);
  allAqua();
  delay(1000);
  // Light some individual LEDs using random values
  lostinspace(); // Scroll some horizontal and vertical lines
  for (int z = 0; z < 5; z++) {
    for (int q = 1; q < 129; q *= 2) {
      displayLEDs(255, 0, 0, q, 200);
    }
  }
  clearMatrix();
  delay(1000);
  for (int z = 0; z < 5; z++) {
    for (int q = 1; q < 129; q *= 2) {
      displayLEDs(0, 255, 0, q, 200);
      displayLEDs(q, 0, 0, 255, 200);
    }
  }
  clearMatrix();
  delay(1000);
  for (int z = 0; z < 5; z++) {
    for (int q = 1; q < 9; q++) {
      displayLEDs(0, 0, 255, va2[q], 200);
    }
  }
  clearMatrix();
  delay(1000);
}
