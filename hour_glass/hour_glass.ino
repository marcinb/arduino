int lowestLED = 2;
int highestLED = 7;
int interval = 1000;
unsigned long lastTick = 0;
unsigned long lastReset = 0;

void setup() {
  for(int pinNum = lowestLED; pinNum <= highestLED; pinNum++) {
    pinMode(pinNum, OUTPUT);
  }
}

void loop() {
  tick();
  lightUpLEDs(currentIntervalNumber());
}

int currentIntervalNumber() {
  int currentInterval = 0;
  unsigned long currentTime = millis() - lastReset;

  for(int i = 0; i <= 6; i++) {
    if(currentTime >= interval * (i + 1)) {
      currentInterval = i;
    }
  }

  return currentInterval;
}

void tick() {
  lastTick = millis();
  if(lastTick - lastReset > 8000) {
    resetTimer();
  }
}

void resetTimer() {
  lastReset = millis();
}

void lightUpLEDs(int num) {
  for(int pinNum = lowestLED; pinNum <= highestLED; pinNum++) {
    if(pinNum < lowestLED + num) {
      digitalWrite(pinNum, HIGH);
    } else {
      digitalWrite(pinNum, LOW);
    }
  }
}
