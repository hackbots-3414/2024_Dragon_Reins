// #include <Gamepad.h>
#include <Joystick.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  Joystick.begin();
  // Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(digitalRead(0));
  Joystick.button(1, !digitalRead(0));
  Joystick.button(2, !digitalRead(1));
  Joystick.button(3, !digitalRead(2));
  Joystick.button(4, !digitalRead(3));
  // gp.setButtonState(0, !digitalRead(0));
}
