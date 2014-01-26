int notes[] = {262, 294, 330, 349};
int piezzoPin = 8;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(A0));
  if(getButtonValue() != 0) {
    tone(piezzoPin, notes[getPressedKeyIndex()]);
  } else {
    noTone(piezzoPin);
  }
}

int getPressedKeyIndex() {
  int value = getButtonValue();

  if(value < 10) { return 0; }
  if(value < 515) { return 1; }
  if(value < 1010) { return 2; }
  return 3;
}

int getButtonValue() {
  return analogRead(A0);
}
