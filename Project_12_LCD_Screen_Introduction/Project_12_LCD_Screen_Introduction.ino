/*Library originally added 18 Apr 2008 by David A. Mellis
  library modified 5 Jul 2009
  by Limor Fried (http://www.ladyada.net)
  example added 9 Jul 2009 by Tom Igoe
  modified 22 Nov 2010 by Tom Igoe
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/LiquidCrystal
*/
// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  // Print a message to the LCD
  lcd.print("Arduino Sketch");
  delay(1000);
}
void loop() {
  // Scroll 13 positions (string length) to the left
  // to move it offscreen left
  for (int positionCounter = 0; positionCounter < 13;
       positionCounter++) {
    // Scroll one position left
    lcd.scrollDisplayLeft();
    // Wait a bit
    delay(150);
  }
  // Scroll 29 positions (string length + display length) to the right
  // to move it offscreen right
  for (int positionCounter = 0; positionCounter < 29;
       positionCounter++) {
    // Scroll one position right
    lcd.scrollDisplayRight();
    // Wait a bit
    delay(150);
  }
  // Scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  for (int positionCounter = 0; positionCounter < 16;
       positionCounter++) {
    // Scroll one position left
    lcd.scrollDisplayLeft();
    // Wait a bit
    delay(150);
  }
  // Delay at the end of the full loop
  delay(1000);
}
