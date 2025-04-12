#include <Gamepad.h>
// #include <Button.h>
#define default_deadband 3

int deadbandLY = default_deadband;
int deadbandRX = default_deadband;
int deadbandRY = default_deadband;
int deadbandLX = default_deadband;

double rightXcenter = 512;
double rightYcenter = 512;
double leftXcenter = 512;
double leftYcenter = 512;
double multiplierRX = 127/rightXcenter; //127 / 500
double multiplierRY = 127/rightYcenter;
double multiplierLX = 127/leftXcenter;
double multiplierLY = 127/leftYcenter;

// Button button0(16);
// Button button1(14);
// Button button2(15);
// Button button3(2);
// Button button4(3);
// Button button5(4);


Gamepad gp;

void setup()  {
  pinMode(5, INPUT_PULLUP); // Left Trigger
  pinMode(3, INPUT_PULLUP); // Right Trigger
  pinMode(6, INPUT_PULLUP); // left joystick button
  pinMode(16, INPUT_PULLUP); //button right joystick
  // pinMode(3, INPUT_PULLUP);
  // pinMode(4, INPUT_PULLUP);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(8,  INPUT); //Y
  pinMode(9,  INPUT); //X
  
  // calibrate();

}

int state = 1;

void handle_buttons() {
  state ++;
  gp.setButtonState(2, !digitalRead(3)); // Right Trigger
  gp.setButtonState(3, !digitalRead(5)); //  Left Trigger
  gp.setButtonState(1, !digitalRead(6)); //remapping to better match driver preference
  gp.setButtonState(0, !digitalRead(16));
  // gp.setButtonState(4, !digitalRead(3));
  // gp.setButtonState(5, !digitalRead(4));
  // gp.setButtonState(8, !digitalRead(8));
  // gp.setButtonState(9, !digitalRead(9));
}

void loop() {
  handle_buttons();
  int lx, ly, rx, ry;
  lx = analogRead(A1);
  ly = analogRead(A0);//-leftYcenter;
  rx = analogRead(A3);//-rightXcenter;
  ry = analogRead(A2);//-rightYcenter;
  // Serial.println(ly);
  // we need to convert a 0-1000 to -127 - 127
  
  // Serial.println(multiplierLX);
  lx = floor((lx - leftXcenter) * multiplierLX);
  ly = floor((ly - leftYcenter) * multiplierLX);
  rx = floor((rx - rightXcenter) * multiplierRX);
  ry = floor((ry - rightYcenter) * multiplierRY);

  // Serial.println(ly);
  // Serial.println(rx);
  // Serial.println(ry);

  if(lx > 127) lx = 127;
  if(ly > 127) ly = 127;
  if(rx > 127) rx = 127;
  if(ry > 127) ry = 127;
  if(lx < deadbandLX && lx > -deadbandLX) lx = 0;
  if(ly < deadbandLY && ly > -deadbandLY) ly = 0;
  if(rx < deadbandRX && rx > -deadbandRX) rx = 0;
  if(ry < deadbandRY && ry > -deadbandRY) ry = 0;

  gp.setRightXaxis(-rx);
  gp.setLeftXaxis(-ly);
  gp.setRightYaxis(ry);
  gp.setLeftYaxis(lx);
  // delay(20);
}

// void calibrate()
// {
//   int lx, ly, rx, ry;
//   int i = 0;
//   while(i < 13)
//   {
//     lx = analogRead(A3);
//     ly = analogRead(A2);
//     rx = analogRead(A1);
//     ry = analogRead(A0);
//     bool validLX = lx > (leftXcenter - 100) && lx < (leftXcenter + 100);
//     bool validLY = ly > (leftYcenter - 100) && ly < (leftYcenter + 100);
//     bool validRX = rx > (rightXcenter - 100) && rx < (rightXcenter + 100);
//     bool validRY = ry > (rightYcenter - 100) && ry < (rightYcenter + 100);
//     if(validLX && validLY && validRX && validRY)
//     {
//       i++;
//       //nothing to do here!
//     }
//     else i = 0;
//     delay(20);
//   }
//   leftXcenter = lx;
//   leftYcenter = ly;
//   rightXcenter = rx;
//   rightYcenter = ry;
//   multiplierLX = (double)127 / (double)lx;
//   multiplierLY = (double)127 / (double)ly;
//   multiplierRX = (double)127 / (double)rx;
//   multiplierRY = (double)127 / (double)ry;
// }
