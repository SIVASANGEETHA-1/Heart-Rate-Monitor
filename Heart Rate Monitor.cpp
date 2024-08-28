#include <PulseOximeter.h>
#include <LiquidCrystal.h>

PulseOximeter pulseOx;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  pulseOx.begin();
  lcd.begin(16, 2);
}

void loop() {
  unsigned int bpm = pulseOx.getBPM();
  float spo2 = pulseOx.getSpO2();

  lcd.setCursor(0, 0);
  lcd.print("BPM: ");
  lcd.print(bpm);

  lcd.setCursor(0, 1);
  lcd.print("SpO2: ");
  lcd.print(spo2);
  lcd.print("%");

  delay(1000); // Update readings every second
}