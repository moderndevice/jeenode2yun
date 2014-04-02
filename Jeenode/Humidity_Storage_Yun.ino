/// @dir Ports/lcd_demo
/// Demo sketch for an LCD connected to I2C port via MCP23008 I/O expander.
// 2009-10-31 <jc@wippler.nl> http://opensource.org/licenses/mit-license.php

#include <PortsLCD.h>
#include <Wire.h>
#include <LibHumidity.h>
#include <RF12.h>
#include <Ports.h>

PortI2C myI2C (1 );
LiquidCrystalI2C lcd (myI2C);
LibHumidity humidity = LibHumidity(0);

#define screen_width 16
#define screen_height 2
int Fan = 7;

void setup() {
  Serial.begin(9600);
  
  pinMode(Fan, OUTPUT);
  digitalWrite(Fan, LOW); //LOW is on

  lcd.begin(screen_width, screen_height);

  lcd.print("HUMIDITY STORAGE");
  delay(2000);
  lcd.clear();
  rf12_initialize(20, RF12_915MHZ, 68);
}

void loop() {
//  if (humidity.GetHumidity() < 10) {
//    digitalWrite(Fan, HIGH);
//  }
//  if (humidity.GetHumidity() > 10) {
//    digitalWrite(Fan, LOW);
//  }
  int data[3];
   
  lcd.setCursor(0,0);
  lcd.print("HUMIDIY: ");
  float h = humidity.GetHumidity();
  lcd.print(h);
  data[0] = (int)(h*100);
  
  lcd.setCursor(0,1);
  lcd.print("TmpC");
  float t = humidity.GetTemperatureC();
  lcd.print(t);
  data[1] = (int)(t*100);
  
  lcd.setCursor(9,1);
  lcd.print(" F");
  t = humidity.GetTemperatureF();
  lcd.print(t);
  data[2] = (int)(t*100);
  
  while (!rf12_canSend())
    rf12_recvDone();
  
  rf12_sendStart(0, data, 6);
  
  delay(1000);
}
