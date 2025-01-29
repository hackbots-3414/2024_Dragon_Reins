// #include <Gamepad.h>
#include <Joystick.h>



int row_0 = 0;
int row_1 = 1;
int row_2 = 2;

int col_0 = 18;
int col_1 = 19;
int col_2 = 20;

int pins[6] = {row_0, row_1, row_2, col_0, col_1, col_2};
int rows[3] = {row_0, row_1, row_2};
int cols[3] = {col_0, col_1, col_2};

int ids[3][3] = {
  {1,2,3},
  {4,5,6},
  {7,8,9}
};


void init_pins(){
  for (int i = 0; i < 3; i++) {
    pinMode(cols[i], INPUT_PULLUP);
  }
  for (int i = 0; i < 3; i++) {
    pinMode(rows[i], INPUT);
  }
}

void setup() {
  // put your setup code here, to run once:
  init_pins();
  Joystick.begin();
  Serial.begin(115200);
}

void read_pins() {
  for (int rowid = 0; rowid < 3; rowid++){
    // char temp[3];
    pinMode(rows[rowid], OUTPUT);
    digitalWrite(rows[rowid], 0);
    // delay(10);
    // Serial.println("Running");
    for (int colid = 0; colid < 3; colid++){
      
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
