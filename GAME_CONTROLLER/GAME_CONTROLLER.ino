#include <Gamepad.h>
#define default_deadband 5

int deadbandLY = default_deadband;
int deadbandRX = default_deadband;
int deadbandRY = default_deadband;
int deadbandLX = default_deadband;

int rightXcenter = 500;
int rightYcenter = 500;
int leftXcenter = 500;
int leftYcenter = 500;
double multiplierRX = 0.254; //127 / 500
double multiplierRY = 0.254;
double multiplierLX = 0.254;
double multiplierLY = 0.254;

Gamepad gp;

void setup() {

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(8,  INPUT); //Y
  pinMode(9,  INPUT); //X
  
  calibrate();
}

void loop() {
  int lx, ly, rx, ry;
  lx = analogRead(A0);
  ly = analogRead(A1);
  rx = analogRead(A2);
  ry = analogRead(A3);
  //we need to convert a 0-1000 to -127 - 127
  lx = floor((lx - leftXcenter) * multiplierLX);
  ly = floor((ly - leftYcenter) * multiplierLX);
  rx = floor((rx - rightXcenter) * multiplierRX);
  ry = floor((ry - rightYcenter) * multiplierRY);
  if(lx > 127) lx = 127;
  if(ly > 127) ly = 127;
  if(rx > 127) rx = 127;
  if(ry > 127) ry = 127;
  if(lx < deadbandLX && lx > -deadbandLX) lx = 0;
  if(ly < deadbandLY && ly > -deadbandLY) ly = 0;
  if(rx < deadbandRX && rx > -deadbandRX) rx = 0;
  if(ry < deadbandRY && ry > -deadbandRY) ry = 0;
  gp.setLeftXaxis(lx);
  gp.setRightXaxis(rx);
  gp.setLeftYaxis(-ly);
  gp.setRightYaxis(-ry);
  
  int X, Y;
  X = digitalRead(8);
  Y = digitalRead(9);
  
  if(X == LOW)
    gp.setButtonState(8, true);
  else
    gp.setButtonState(8, false);

  if(Y == LOW)
    gp.setButtonState(9, true);
  else
    gp.setButtonState(9, false);

  delay(20);
}

void calibrate()
{
  int lx, ly, rx, ry;
  int i = 0;
  while(i < 13)
  {
    lx = analogRead(A3);
    ly = analogRead(A2);
    rx = analogRead(A1);
    ry = analogRead(A0);
    bool validLX = lx > (leftXcenter - 100) && lx < (leftXcenter + 100);
    bool validLY = ly > (leftYcenter - 100) && ly < (leftYcenter + 100);
    bool validRX = rx > (rightXcenter - 100) && rx < (rightXcenter + 100);
    bool validRY = ry > (rightYcenter - 100) && ry < (rightYcenter + 100);
    if(validLX && validLY && validRX && validRY)
    {
      i++;
      //nothing to do here!
    }
    else i = 0;
    delay(20);
  }
  leftXcenter = lx;
  leftYcenter = ly;
  rightXcenter = rx;
  rightYcenter = ry;
  multiplierLX = (double)127 / (double)lx;
  multiplierLY = (double)127 / (double)ly;
  multiplierRX = (double)127 / (double)rx;
  multiplierRY = (double)127 / (double)ry;
}
