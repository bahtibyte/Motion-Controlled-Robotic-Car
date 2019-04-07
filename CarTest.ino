#include <Servo.h>

/*Left Top Wheels*/
int leftTopForward   = A0;
int leftTopBackward  = A1;

/*Left Bot Wheels*/
int leftBotForward   =  6;
int leftBotBackward  =  5;

/*Right Top Wheels*/
int rightTopForward  = A2;
int rightTopBackward = A3;

/*Right Bot Wheels*/
int rightBotForward  = A4;
int rightBotBackward = A5;

/*Enabler for top wheels*/
int topEnabler = 4;

/*Enabler for bottom wheels*/
int botEnabler = 2;

/*Servo controllers*/
Servo yAxis; /*180 is fully down. 50 min*/
Servo left; /* < 90 :  left*/
Servo right;

void loop() {

  if (Serial.available()) {

    int input = Serial.read();

    int p1 = bitRead(input, 0);
    int p2 = bitRead(input, 1);
    int p3 = bitRead(input, 2);
    int p4 = bitRead(input, 3);
    int p5 = bitRead(input, 4);
    int p6 = bitRead(input, 5);
    int p7 = bitRead(input, 6);

    if (p7 == 1){
      goForward();
    }
    else if (p6 == 1){
      goBackward();
    }
    else if (p5 == 1){
      rotateLeft();
    }
    else if (p4 == 1){
      rotateRight();
    }else{
      stopCar();
    }

    if (p1 == 1) {
      armClose();
    } else {
      armOpen();
    }

    if (p2 == 1){
      yAxisUp();
    }else{
      if (p3 == 1){
        yAxisDown();
      }else{
        yAxisStraight();
      }
    }
  }

}

void armOpen() {
  left.write(60);
  right.write(120);
}

void armClose() {
  left.write(103);
  right.write(85);
}

void yAxisUp() {
  yAxis.write(90);
}

void yAxisDown() {
  yAxis.write(180);
}

void yAxisStraight() {
  yAxis.write(150);
}

void loop2() {
  if (Serial.available()) {

    int v = Serial.read();

    if (v == 1) {
      goForward();
    } else if (v == 2) {
      goBackward();
    } else if (v == 3) {
      rotateRight();
    } else if (v == 4) {
      rotateLeft();
    } else {
      stopCar();
    }

  }
}


void stopCar() {

  digitalWrite(leftTopForward, LOW);
  digitalWrite(leftTopBackward, LOW);

  digitalWrite(leftBotForward, LOW);
  digitalWrite(leftBotBackward, LOW);

  digitalWrite(rightTopForward, LOW);
  digitalWrite(rightTopBackward, LOW);

  digitalWrite(rightBotForward, LOW);
  digitalWrite(rightBotBackward, LOW);
}


void rotateRight() {

  digitalWrite(leftTopForward, HIGH);
  digitalWrite(leftTopBackward, LOW);

  digitalWrite(leftBotForward, LOW);
  digitalWrite(leftBotBackward, HIGH);

  digitalWrite(rightTopForward, LOW);
  digitalWrite(rightTopBackward, HIGH);

  digitalWrite(rightBotForward, HIGH);
  digitalWrite(rightBotBackward, LOW);
}

void rotateLeft() {

  digitalWrite(leftTopForward, LOW);
  digitalWrite(leftTopBackward, HIGH);

  digitalWrite(leftBotForward, HIGH);
  digitalWrite(leftBotBackward, LOW);

  digitalWrite(rightTopForward, HIGH);
  digitalWrite(rightTopBackward, LOW);

  digitalWrite(rightBotForward, LOW);
  digitalWrite(rightBotBackward, HIGH);
}

void goForward() {

  digitalWrite(leftTopForward, HIGH);
  digitalWrite(leftTopBackward, LOW);

  digitalWrite(leftBotForward, HIGH);
  digitalWrite(leftBotBackward, LOW);

  digitalWrite(rightTopForward, HIGH);
  digitalWrite(rightTopBackward, LOW);

  digitalWrite(rightBotForward, HIGH);
  digitalWrite(rightBotBackward, LOW);
}

void goBackward() {


  digitalWrite(leftTopForward, LOW);
  digitalWrite(leftTopBackward, HIGH);

  digitalWrite(leftBotForward, LOW);
  digitalWrite(leftBotBackward, HIGH);

  digitalWrite(rightTopForward, LOW);
  digitalWrite(rightTopBackward, HIGH);

  digitalWrite(rightBotForward, LOW);
  digitalWrite(rightBotBackward, HIGH);
}

/*
  int getDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  return (int )distance;
  }
*/
void setup() {
  pinMode(leftTopForward, OUTPUT);
  pinMode(leftTopBackward, OUTPUT);

  pinMode(leftBotForward, OUTPUT);
  pinMode(leftBotBackward, OUTPUT);

  pinMode(rightTopForward, OUTPUT);
  pinMode(rightTopBackward, OUTPUT);

  pinMode(rightBotForward, OUTPUT);
  pinMode(rightBotBackward, OUTPUT);

  pinMode(topEnabler, OUTPUT);
  pinMode(botEnabler, OUTPUT);

  yAxis.attach(11);
  left.attach(9);
  right.attach(10);

  digitalWrite(topEnabler, HIGH);
  digitalWrite(botEnabler, HIGH);

  Serial.begin(9600);
}
