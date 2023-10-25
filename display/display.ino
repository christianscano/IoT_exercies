#include "LiquidCrystal_PCF8574.h"

// Address of the display
LiquidCrystal_PCF8574 display(0x27);
String message;


void setup() {
  Serial.begin(9600);
  
  display.begin(16, 2);
  display.setBacklight(255);

  display.print("Enter the text here");

  display.setCursor(0, 1);
  display.print("with SM");
}

void loop() {
  if (Serial.available()) {
    display.clear();
    
    String tmp = Serial.readString();
    display.setCursor(0, 1);
    display.print(message);


    message = tmp;
    display.setCursor(0, 0);
    display.print(message);
  }

}
