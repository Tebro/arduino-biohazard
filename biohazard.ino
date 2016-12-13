#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;

void setAllClear(){
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print("ALL");
    lcd.setCursor(6, 1);
    lcd.print("CLEAR");
}

void setBioHazard(){
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("WARNING!");
  lcd.setCursor(3, 1);
  lcd.print("BIOHAZARD!");
}

void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  setAllClear();
}

void loop() {
  switchState = digitalRead(switchPin);
  if( switchState == HIGH) {
    setBioHazard();
    delay(5000);
    setAllClear();
  }
}
