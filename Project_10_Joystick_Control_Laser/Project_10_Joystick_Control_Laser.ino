// Used with kind permission from http://learn.explorelabs.com/
// Creative Commons 4.0 Share Alike (CC by SA 4.0) license

#include <Servo.h>

Servo tilt, pan; // create servo object

int joyX = A0; // analog pin for X – axis
int joyY = A1; // analog pin for Y – axis
int x, y; // variables to read the values

void setup(){
  tilt.attach(9); // attaches the tilt servo on pin 9 to the servo object
  pan.attach(10); // attaches the pan servo on pin 10 to the servo object
}
void loop()
{
  x = joyX;// reads the value of the X – axis (value between 0 and 1023)
  y = joyY;// reads the value of the Y – axis (value between 0 and 1023)
  x = map(analogRead(joyX), 0, 1023, 900, 2100); //
  y = map(analogRead(joyY), 0, 1023, 900, 2100);
  tilt.write(x); // sets the servo position according to the scaled value
  pan.write(y);
  delay(15); // waits for the servos to get there
}
