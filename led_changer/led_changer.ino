/*
  Led Changer

  Press the button to light up next LED
*/

int switchState = 0;
int currentLED = 3;
int buttonActive = 1;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  switchState = digitalRead(2);

  if(switchState == HIGH) {
    if(buttonActive == 1) {
      buttonActive = 0;
      resetLEDs();
      nextLED();
    }
  }
  else {
    buttonActive = 1;
  }

  ligthUpCurrentLED();
}

void resetLEDs(){
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void ligthUpCurrentLED() {
  digitalWrite(currentLED, HIGH);
}

int nextLED() {
  if(currentLED >= 5) {
    currentLED = 3;
  } else {
    currentLED += 1;
  }
  return currentLED;
}
