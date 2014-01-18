int RVal;
int GVal;
int BVal;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  RVal = map(analogRead(A0), 0, 1023, 0, 255);
  GVal = map(analogRead(A1), 0, 1023, 0, 255);
  BVal = map(analogRead(A2), 0, 1023, 0, 255);

  analogWrite(11, RVal);
  analogWrite(9, GVal);
  analogWrite(10, BVal);

  Serial.print("R: ");
  Serial.print(RVal);
  Serial.print(" G: ");
  Serial.print(GVal);
  Serial.print(" B: ");
  Serial.println(BVal);
}
