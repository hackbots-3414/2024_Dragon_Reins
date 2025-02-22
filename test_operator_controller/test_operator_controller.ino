// #include <Gamepad.h>
#include <Joystick.h>
// #include <Adafruit_NeoPixel.h>



int col_0 = 0;
int col_1 = 1;
int col_2 = 2;
int col_3 = 3;
int col_4 = 4;

int row_0 = 6;
int row_1 = 7;
int row_2 = 8;
int row_3 = 9;
int row_4 = 10;

int SW_Pin = 12;

// int pins[6] = {row_0, row_1, row_2, col_0, col_1, col_2};
int rows[5] = {row_0, row_1, row_2, row_3, row_4};
int cols[5] = {col_0, col_1, col_2, col_3, col_4};

int buttons[5][5] = {};
int sw = 0;

int ids[5][5] = {
  {1, 2, 3, 4, 5},
  {6, 7, 8, 9, 10},
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
  pinMode(SW_Pin, INPUT_PULLUP);
}

void setup() {
  // put your setup code here, to run once:
  init_pins();
  Joystick.begin();
  // Serial.begin(115200);
  // for (int i = 0; i < 25; i++){
  //   buttons[i] = 0;
  // }
}

void read_pins() {
  for (int rowid = 0; rowid < 5; rowid++){
    // char temp[3];
    pinMode(rows[rowid], OUTPUT);
    digitalWrite(rows[rowid], 0);
    delay(1);
    // Serial.println("Running");
    for (int colid = 0; colid < 5; colid++){
      
      // if (!digitalRead(cols[colid])){
      //   // Serial.println("REAKKKK");
      //   // Serial.println(ids[colid][rowid]);
      // }
      if(ids[colid][rowid] != 0) {
        if (buttons[colid][rowid] != !digitalRead(cols[colid])){
          Joystick.button(ids[colid][rowid], !digitalRead(cols[colid]));
        }
        buttons[colid][rowid] = !digitalRead(cols[colid]);
        // if (!digitalRead(cols[colid])){
        //   Serial.println(ids[colid][rowid]);
        // }
      }
      // while(!digitalRead(cols[colid]));
    }
    // digitalWrite(rows[rowid], 1);
    pinMode(rows[rowid], INPUT);
    //delay(2);
    // Serial.println(String(temp));
    // }
  }
  if(sw != !digitalRead(SW_Pin)){
    Joystick.button(26, !digitalRead(SW_Pin));
  }
  sw = !digitalRead(SW_Pin);
  // Serial.println("\n\n\n\n\n\n\n\n\n\n\n");
  // delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(digitalRead(0));
  read_pins();
  // gp.setButtonState(0, !digitalRead(0));
}
