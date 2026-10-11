#include <Adafruit_LiquidCrystal.h>

const int TRIG = 3;
const int ECHO = 2;

Adafruit_LiquidCrystal lcd(0);

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
}
void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long t = pulseIn(ECHO, HIGH);
  float cm = t * 0.0343 / 2;

  lcd.setCursor(0, 1);
  lcd.print(cm, 1);
  lcd.print(" cm    ");
  delay(300);
}