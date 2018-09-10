// Created by Steven De Lannoy and reproduced with kind permission
// http://www.wingbike.nl
// Used a RGB LED with a common anode (3 cathodes: R, G, B)
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int LEDR = 8; // Pin connected to red LED
int LEDB = 7; // Pin connected to blue LED
int LEDGr = 6; // Pin connected to green LED
int Button = 9; // Pin connected to pushbutton
int COLOR; // Variable color
int Beep;
int PSE; // Variable pause
int TME; // Time
int RTME = 0; // Reaction time
void setup() {
  lcd.begin(16, 2);
  pinMode(LEDR, OUTPUT); // Set LED pins as output
  pinMode(LEDB, OUTPUT);
  pinMode(LEDGr, OUTPUT);
  pinMode(Button, INPUT); // Set pushbutton as input
  digitalWrite(LEDR, LOW); // Switch on all LED colors
  digitalWrite(LEDB, LOW);
  digitalWrite(LEDGr, LOW);
}
void loop() {
  lcd.clear(); // Clear screen
  lcd.print("Hold Button to"); // Display message on LCD screen
  lcd.setCursor(0, 1); // Move to second line
  lcd.print("start.");
  while (digitalRead(Button) == LOW) { // Test does not start until
    // button is pushed (and held)
    tone(13, 1200, 30);
    delay(1400);
    noTone(13);
  }
  lcd.clear();
  digitalWrite(LEDR, HIGH); // Switch off start light
  digitalWrite(LEDB, HIGH);
  digitalWrite(LEDGr, HIGH);
  randomSeed(analogRead(0)); // Random noise from pin 0
  COLOR = random(1, 4); // Generate random color
  PSE = random(500, 1200); // Set random pause duration between lights
  // Repeat this loop while color is green or blue AND pushbutton
  // is held
  while (COLOR != 1 && digitalRead(Button) == HIGH) {
    digitalWrite(LEDGr, HIGH);
    digitalWrite(LEDB, HIGH);
    delay(PSE);
    randomSeed(analogRead(0));
    Beep = random(1, 4); // Select random beep from buzzer
    // (buzzer beeps 1 in 3 times)
    PSE = random(750, 1200); // Select random pause duration between
    // lights (to increase surprise effect)
    if (Beep == 1) {
      tone(13, 1600, 350);
      delay(750);
      noTone(13);
    }
    if (COLOR == 2) {
      digitalWrite(LEDGr, LOW);
    }
    if (COLOR == 3) {
      digitalWrite(LEDB, LOW);
    }
    delay(PSE);
    randomSeed(analogRead(0));
    COLOR = random(1, 4); // Select random color
  }
  // Execute this loop if color is red
  if (COLOR == 1 && digitalRead(Button) == HIGH) {
    digitalWrite(LEDGr, HIGH);
    digitalWrite(LEDB, HIGH);
    delay(PSE);
    TME = millis(); // Record time since program has started
    digitalWrite(LEDR, LOW);
    while (digitalRead(Button) == HIGH) { // Runs until button is
      // released, recording the
      // reaction time
      delay(1);
    }
    lcd.display();
    RTME = millis() - TME; // Reaction time in milliseconds
    lcd.print("Reaction Time:"); // Display on LCD screen
    lcd.setCursor(0, 1);
    lcd.print(RTME);
  }
  // Execute if color is NOT red but the pushbutton is released
  if (COLOR != 1) {
    lcd.print("Released too");
    lcd.setCursor(0, 1); // Move to second line
    lcd.print("soon!!!");
    tone(13, 3000, 1500);
    delay(500);
    noTone(13);
  }
  // Test does not restart until the button is pushed once
  while (digitalRead(Button) == LOW) {
    delay(10);
  }
  digitalWrite(LEDR, LOW); // Reset all lights to begin again
  digitalWrite(LEDB, LOW);
  digitalWrite(LEDGr, LOW);
  lcd.clear();
  lcd.print("Hold Button to");
  lcd.setCursor(0, 1);
  lcd.print("start.");
  int Time = 0;
  delay(1000);
}
