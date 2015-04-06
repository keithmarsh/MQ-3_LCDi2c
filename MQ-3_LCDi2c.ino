// Keith Marsh 2015
// My experiments :^) indicate
// Sober 90 - 110
// Having one 500mL 5% lager per hour yields half hourly readings from sober of
// [ 110, 162, 281, 324, 363, 345, 394, 453, 469 ]
// Rinsing with a mouthful of Becherovka gives a reading over 600 (max of 1023)
// Allow the sensor to cool and settle down when it first turns on - 30 seconds or so.
// I have never seen the digital pin read anything other than 1.

#include <Wire.h>
// https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
const int sensorPin = A0;              // Plug the MQ-3 analog out into A0
const int digitalPin = 2;              // Plug the MQ-3 digital out into D2
const unsigned long hiHoldMs = 8000;   // Hold the high reading for 8 seconds
const unsigned long refreshMs = 500;   // Update the LCD every half a second

int sensorVal = 0;                     // The current analog sensor reading           
int sensorHi = 0;                      // The highest reading for 8 seconds
int sensorMax = 0;                     // The maximum reading ever
unsigned long hiStartMs = millis();    // Time that the high hold starts

// My LCD i2c is a YwRobot
// https://arduino-info.wikispaces.com/LCD-Blue-I2C#v1
LiquidCrystal_I2C lcdi2c(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
LCD *lcd = &lcdi2c;

void setup()
{
  pinMode(digitalPin, INPUT);      // MQ-3 digital in
  lcd->begin(16,2);                // initialize the lcd 
  lcd->clear();
}

void loop()
{
  sensorVal = analogRead(sensorPin);
  if (sensorVal > sensorHi) {
    sensorHi = sensorVal;
    hiStartMs = millis();
    if (sensorHi > sensorMax) {
      sensorMax = sensorHi;
    }
  } else {
    if (millis() > hiStartMs + hiHoldMs) {
      sensorHi = sensorVal;
    }
  }
  lcd->home();
  lcd->print(sensorVal);  
  lcd->print("  ");
  lcd->setCursor(15,0);
  lcd->print(digitalRead(digitalPin));
  lcd->setCursor(0,1);
  lcd->print(sensorHi);  
  lcd->print(" high  ");
  lcd->setCursor(9,1);
  lcd->print(sensorMax);  
  lcd->print(" max  ");
  delay ( refreshMs );
}

