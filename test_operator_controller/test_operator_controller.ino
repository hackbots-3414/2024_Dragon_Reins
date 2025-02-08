// #include <Gamepad.h>
#include <Joystick.h>



int row_0 = 0;
int row_1 = 1;
int row_2 = 2;
int row_3 = 3;
int row_4 = 4;

int col_0 = 8;
int col_1 = 9;
int col_2 = 10;
int col_3 = 11;
int col_4 = 12;

// int pins[6] = {row_0, row_1, row_2, col_0, col_1, col_2};
int rows[5] = {row_0, row_1, row_2, row_3, row_4};
int cols[5] = {col_0, col_1, col_2, col_3, col_4};

int ids[5][5] = {
  {1, 2, 3, 4, 5},
  {5, 7, 8, 9, 10},
  {11,12,13,14,15},
  {16,17,18,19,20},
  {21,22,23,24,25}
};


void init_pins(){
  for (int i = 0; i < 5; i++) {
    pinMode(cols[i], INPUT_PULLUP);
  }
  for (int i = 0; i < 5; i++) {
    pinMode(rows[i], INPUT);
  }
}

void setup() {
  // put your setup code here, to run once:
  init_pins();
  Joystick.begin();
  // Serial.begin(115200);
}

void read_pins() {
  for (int rowid = 0; rowid < 5; rowid++){
    // char temp[3];
    pinMode(rows[rowid], OUTPUT);
    digitalWrite(rows[rowid], 0);
    // delay(10);
    // Serial.println("Running");
    for (int colid = 0; colid < 5; colid++){
      
      // if (!digitalRead(cols[colid])){
      //   // Serial.println("REAKKKK");
      //   // Serial.println(ids[colid][rowid]);
      // }
      Joystick.button(ids[colid][rowid], !digitalRead(cols[colid]));
      // while(!digitalRead(cols[colid]));
    }
    digitalWrite(rows[rowid], 1);
    pinMode(rows[rowid], INPUT);
    delay(10);
    // Serial.println(String(temp));
    // }
  }
  // Serial.println("\n\n\n\n\n\n\n\n\n\n\n");
  // delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(digitalRead(0));
  read_pins();
  // gp.setButtonState(0, !digitalRead(0));
}
