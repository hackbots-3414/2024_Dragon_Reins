// #include <Gamepad.h>
#include <Joystick.h>



int row_0 = 0;
int row_1 = 1;
int row_2 = 2;

int col_0 = 3;
int col_1 = 4;
int col_2 = 5;

int pins[6] = {row_0, row_1, row_2, col_0, col_1, col_2};
int rows[3] = {row_0, row_1, row_2};
int cols[3] = {col_0, col_1, col_2};

void init_pins(){
  for (int i = 0; i < 6; i++) {
    pinMode(pins[i, INPUT_PULLUP]);
  }
}

void setup() {
  // put your setup code here, to run once:
  init_pins();
  Joystick.begin();
  // Serial.begin(9600);
}

void read_pins() {
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      
    }
  }
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
