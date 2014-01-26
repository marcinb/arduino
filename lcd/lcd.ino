#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello");
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(getPotValue());
  delay(250);
}

int getPotValue() {
  return map(analogRead(A0), 0, 1023, 0, 10);
}
