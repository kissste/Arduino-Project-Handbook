// Code by Warrick A Smith and reproduced with kind permission,
// http://startingelectronics.com 26 April 2012
const int latchPin = 8; // Pins connected to 74HC595
const int clockPin = 12;
const int dataPin = 11;
const int buttonPin = 2; // Pin connected to switch wire
// 1 to 6 and DP (decimal point) on 7-seg display
unsigned char lookup_7seg[] = {0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x80};
// Shaking die pattern on 7-seg display
unsigned char shake_dice[] = {0x63, 0x5C};
// Rolling die on 7-seg display
unsigned char roll_dice[] = {0x1C, 0x58, 0x54, 0x4C};
// Vary duration of time before die number is received
int rand_seed;
int rand_num = 0; // Generate random number
unsigned char shake_toggle = 0; // For shaking dice animation
int index = 0; // For rolling dice animation
int shake_speed; // Accelerates dice shake speed
void setup() {
  pinMode(latchPin, OUTPUT); // Output pins for controlling the
  // 74HC595
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(buttonPin, INPUT); // Read switch wire state
  digitalWrite(latchPin, LOW); // Display DP on 7-seg display
  // at startup
  shiftOut(dataPin, clockPin, MSBFIRST, lookup_7seg[6]);
  digitalWrite(latchPin, HIGH);
  randomSeed(analogRead(0)); // Generate random seed
}
void loop() {
  if (digitalRead(buttonPin)) {
    shake_speed = 150; // Reset die shaking speed
    delay(30);
    // Generate number for random speed and show shaking animation
    while (digitalRead(buttonPin)) {
      rand_seed++; // Generate random number
      // Animate shaking die
      if (shake_toggle) {
        AnimateDice(0, shake_dice);
        shake_toggle = 0;
      }
      else {
        AnimateDice(1, shake_dice);
        shake_toggle = 1;
      }
      delay(80 + shake_speed); // Accelerate animation speed
      if (shake_speed > 0) {
        shake_speed -= 10;
      }
    }
    // Animate rolling die
    for (int rolls = 0; rolls < (rand_seed % 10 + 14); rolls++) {
      AnimateDice(index, roll_dice);
      delay((1 + rolls) * 20);
      index++;
      if (index > 3) {
        index = 0;
      }
    }
    rand_num = random(0, 6); // Generate number thrown on die
    DiceNumber(rand_num);
  }
}
// Display the die number on 7-seg display
void DiceNumber(unsigned char num) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, lookup_7seg[num]);
  digitalWrite(latchPin, HIGH);
}
// Display one frame of the shaking or rolling dice
void AnimateDice(int seg, unsigned char *table) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, table[seg]);
  digitalWrite(latchPin, HIGH);
}
