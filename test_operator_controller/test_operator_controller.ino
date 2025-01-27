// #include <Gamepad.h>
#include <Joystick.h>



int row_0 = 0;
int row_1 = 1;
int row_2 = 2;

int col_0 = 20;
int col_1 = 19;
int col_2 = 18;

int pins[6] = {row_0, row_1, row_2, col_0, col_1, col_2};
int rows[3] = {row_0, row_1, row_2};
int cols[3] = {col_0, col_1, col_2};

int ids[3][3] = {
  {1,2,3},
  {4,5,6},
  {7,8,9}
};

void init_pins(){
  for (int i = 0; i < 6; i++) {
    pinMode(pins[i], INPUT_PULLUP);
  }
}

void setup() {
  // put your setup code here, to run once:
  init_pins();
  Joystick.begin();
  Serial.begin(115200);
}

void read_pins() {
  // for (int i = 0; i < 3; i++){
  //   // Serial.print("i ");
  //   // Serial.println(!digitalRead(rows[i]));
  //   // if (!digitalRead(cols[i])) {
  //   char temp[3];
  //   int index = 0;
  //   for (int j = 0; j < 3; j++){

  //     // if (!digitalRead(rows[j])){
  //     //   // Serial.print(i);
  //     //   Serial.println(j);
  //     //   Serial.println(ids[i][j]);
  //     // }
  //       // Serial.println(digitalRead(rows[j]));
  //     // temp[i][j] = (!digitalRead(cols[i]) && !digitalRead(rows[j]));
  //     temp[index] = '0' + (!digitalRead(rows[i]) && !digitalRead(cols[j]));
  //     index ++;
  //     // if (!digitalRead(cols[i]) && !digitalRead(rows[j])){
  //     //   // Serial.println("REAKKKK");
  //     //   Serial.println(ids[i][j]);
  //     // }
  //   }
  //   Serial.println(String(temp));
  //   // }
  // }
  // Serial.println("\n\n\n\n\n\n\n\n\n\n\n");

  Serial.print(!digitalRead(cols[0]));
  Serial.print(!digitalRead(cols[1]));
  Serial.println(!digitalRead(cols[2]));
  Serial.println(!digitalRead(rows[0]));
  Serial.println(!digitalRead(rows[1]));
  Serial.println(!digitalRead(rows[2]));
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(digitalRead(0));
  read_pins();
  // gp.setButtonState(0, !digitalRead(0));
}
