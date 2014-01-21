#include <Servo.h>

Servo servo;

void setup() {
  pinMode(9, OUTPUT);
  servo.attach(9);
}

void loop() {
  servo.write(getPotAngle());
  delay(15);
}

int getPotAngle() {
  return  map(analogRead(A0), 0, 1023, 0, 179);
}
