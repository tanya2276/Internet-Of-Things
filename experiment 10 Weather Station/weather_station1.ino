#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int wLED = 9;
int lightLevel = 0;
int LDR = A0;
int TMP = A1;
int rLED = 6;
int bLED = 7;
int gLED = 8;
int sensorPin = A1;
void setup() {
  Serial.begin(9600);
  lcd.begin (16, 2);
  pinMode(wLED, OUTPUT);
  pinMode(rLED, OUTPUT);
  pinMode(bLED, OUTPUT);
  pinMode(gLED, OUTPUT);}
void loop() {
  int reading = analogRead(sensorPin);
   float voltage = reading * 5.0;
  voltage /= 1024.0; 
  Serial.print(voltage); Serial.println(" volts");
  float temperatureC = (voltage - 0.5) * 100 ;  
  lightLevel = analogRead(LDR);  
  Serial.println(lightLevel); 
   if (lightLevel < 10) {
    digitalWrite(wLED, HIGH);
  } else {
    digitalWrite(wLED, LOW);}
 lcd.clear();
  lcd.setCursor(0, 0);
  
  if (temperatureC < 2) {
    digitalWrite(bLED, HIGH);
    digitalWrite(rLED, LOW);
    lcd.print("Cold Weather");
    lcd.setCursor(0, 1);
    lcd.print(temperatureC);
    tone(10, 260);
  } else if (temperatureC >= 2 && temperatureC < 45){
    digitalWrite(bLED, LOW);
    digitalWrite(rLED, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Normal Weather");
    noTone(10);
  } else {
    digitalWrite(rLED, HIGH);
    digitalWrite(bLED, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Hot Weather");
    lcd.setCursor(0, 1);
    lcd.print(temperatureC);
    tone(10, 260);}
  delay (500);}