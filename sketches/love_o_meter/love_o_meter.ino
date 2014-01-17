float baselineTemp = 20.0;
float currentDiff = 0.0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  baselineTemp = getTemperature();
}

void loop() {
  currentDiff = getTemperatureDifference();

  if(currentDiff >= 6.0) {
    setLEDsState(3, HIGH);
  }
  else if(currentDiff >= 4.0) {
    setLEDsState(2, HIGH);
  }
  else if(currentDiff >= 2.0) {
    setLEDsState(1, HIGH);
  }
  else {
    setLEDsState(3, LOW);
  }
  delay(1);
}

float getTemperatureDifference() {
  return getTemperature() - baselineTemp;
}

float getTemperature() {
  int sensorVal = analogRead(A0);
  float voltage = (sensorVal/1024.0) * 5.0;
  return (voltage - 0.5) * 100.0;
}

void setLEDsState(int count, int state){
  for(int i = 3; i <= i + count; i++) {
    digitalWrite(i, state);
  }
}
