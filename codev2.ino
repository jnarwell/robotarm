#include <Servo.h>

int rdel = 25;
int sdel = 25;
int edel = 25;
int ydel = 25;
int wdel = 25;
int gdel = 25;

Servo rservo;
Servo sservo;
Servo eservo;
Servo yservo;
Servo wservo;
Servo gripper;

int rppos;
int sppos;
int eppos;
int yppos;
int wppos;

int gripperPosition = 0;

int ppos_list[] = {rppos, sppos, eppos, yppos, wppos};
Servo servo_list[5];
int del_list[] = {rdel, sdel, edel, ydel, wdel};
int pos_list[5][3][3];

void setup() {

  //center row

  servo_list[0] = rservo;
  servo_list[1] = sservo;
  servo_list[2] = eservo;
  servo_list[3] = yservo;
  servo_list[4] = wservo;

  pos_list[0][0][0] = 57;
  pos_list[1][0][0] = 120;
  pos_list[2][0][0] = 150;
  pos_list[3][0][0] = 100;
  pos_list[4][0][0] = 50;

  pos_list[0][1][0] = 75;
  pos_list[1][1][0] = 120;
  pos_list[2][1][0] = 150;
  pos_list[3][1][0] = 100;
  pos_list[4][1][0] = 20;

  pos_list[0][2][0] = 40;
  pos_list[1][2][0] = 120;
  pos_list[2][2][0] = 150;
  pos_list[3][2][0] = 100;
  pos_list[4][2][0] = 20;

  //bottom row

  pos_list[0][0][1] = 60;
  pos_list[1][0][1] = 145;
  pos_list[2][0][1] = 175;
  pos_list[3][0][1] = 100;
  pos_list[4][0][1] = 45;

  pos_list[0][1][1] = 85;
  pos_list[1][1][1] = 134;
  pos_list[2][1][1] = 165;
  pos_list[3][1][1] = 100;
  pos_list[4][1][1] = 47;

  pos_list[0][2][1] = 38;
  pos_list[1][2][1] = 135;
  pos_list[2][2][1] = 165;
  pos_list[3][2][1] = 100;
  pos_list[4][2][1] = 43;

  //top row

  pos_list[0][0][2] = 66;
  pos_list[1][0][2] = 110;
  pos_list[2][0][2] = 120;
  pos_list[3][0][2] = 100;
  pos_list[4][0][2] = 30;

  pos_list[0][1][2] = 78;
  pos_list[1][1][2] = 110;
  pos_list[2][1][2] = 120;
  pos_list[3][1][2] = 100;
  pos_list[4][1][2] = 30;

  pos_list[0][2][2] = 45;
  pos_list[1][2][2] = 110;
  pos_list[2][2][2] = 120;
  pos_list[3][2][2] = 100;
  pos_list[4][2][2] = 30;

  ppos_list[0] = 60;
  ppos_list[1] = 130;
  ppos_list[2] = 80;
  ppos_list[3] = 100;
  ppos_list[4] = 60;

  servo_list[0].attach(5);
  servo_list[1].attach(6);
  servo_list[2].attach(7);
  servo_list[3].attach(11);
  servo_list[4].attach(9);
  gripper.attach(10);

  servo_list[0].write(60);
  servo_list[1].write(130);
  servo_list[2].write(80);
  servo_list[3].write(100);
  servo_list[4].write(60);
  gripper.write(0);

  Serial.begin(9600);

//  openUp(gripperPosition);
//  totalMove(2, 1);
//  closeTime(gripperPosition);
//  totalMove(0, 1);
//  openUp(gripperPosition);
//  closeTime(gripperPosition);
//  totalMove(1, 1);
//  openUp(gripperPosition);
//  closeTime(gripperPosition);
//  totalMove(1, 0);
//  closeTime(gripperPosition);
//  totalMove(0, 0);
//  openUp(gripperPosition);
//  closeTime(gripperPosition);
//  totalMove(2, 0);
//  openUp(gripperPosition);
//  closeTime(gripperPosition);
//  totalMove(2, 2);
//  openUp(gripperPosition);
//  closeTime(gripperPosition);
//  totalMove(0, 2);
//  openUp(gripperPosition);
//  closeTime(gripperPosition);
//  totalMove(1, 2);
//  openUp(gripperPosition);

//turn 1
  pickup();
  totalMove(0, 0);
  openUp(gripperPosition);
  // turn 2
//  pickup();
//  totalMove(2, 2);
//  openUp(gripperPosition);
}

void loop() {
}


void pickup() {
    openUp(gripperPosition);
    for (int i = ppos_list[1]; i < (ppos_list[1] + 30); i++) {
      sservo.write(i);
      delay(sdel);
    } delay(1000);
    for (int i = ppos_list[2]; i < (ppos_list[2] + 30); i++) {
      eservo.write(i);
      delay(edel);
    }delay(1000);
    for (int i = ppos_list[0]; i < 105; i++) {
      rservo.write(i);
      delay(rdel);
    }delay(1000);
    for (int i = ppos_list[1]; i > 105; i--) {
      sservo.write(i);
      delay(sdel);
    }delay(1000);
    for (int i = ppos_list[2]; i < 75; i++) {
      eservo.write(i);
      delay(edel);
    }delay(1000);
    for (int i = ppos_list[4]; i > 20; i--) {
      wservo.write(i);
      delay(wdel);
    }delay(1000);
    closeTime(gripperPosition);
    for (int i = ppos_list[1]; i < (ppos_list[1] + 30); i++) {
      sservo.write(i);
      delay(sdel);
    } delay(1000);
    for (int i = ppos_list[2]; i < (ppos_list[2] + 30); i++) {
      eservo.write(i);
      delay(edel);
    }delay(1000);
}

void openUp(int& gripperPosition) {
  for (int i = gripperPosition; i < 100; i++) {
    gripper.write(i);
    delay(gdel);
  }
  gripperPosition = 100;
}
void closeTime(int& gripperPosition) {
  for (int i = gripperPosition; i > 0; i--) {
    gripper.write(i);
    delay(gdel);
  }
  gripperPosition = 0;
}

void preciseMove(int& PrecisePosition, Servo servo, int del, int newPosition) {
  Serial.print("newPosition: ");
  Serial.println(newPosition);
  Serial.print("PrecisePosition: ");
  Serial.println(PrecisePosition);
  if (newPosition < PrecisePosition) {
    for (int i = PrecisePosition; i > newPosition; i--) {
      Serial.println(i);
      servo.write(i);
      delay(del);
    }
  }
  else if (newPosition > PrecisePosition) {
    for (int i = PrecisePosition; i < newPosition; i++) {
      Serial.println(i);
      servo.write(i);
      delay(del);
    }
  }
  PrecisePosition = newPosition;
}

void totalMove( int file, int rank) {
  for (int i = 0; i < 5; i++) {
    Serial.print("i = ");
    Serial.println(i);
    Serial.println(pos_list[i][file][rank]);
    preciseMove(ppos_list[i], servo_list[i], del_list[i], pos_list[i][file][rank]);
    delay(1000);
  }
}
