#include <LiquidCrystal_PCF8574.h>
#include <SoftwareSerial.h>

#define RX_PIN 2
#define TX_PIN 3

LiquidCrystal_PCF8574 lcd(0x27);
SoftwareSerial commSerial(TX_PIN, RX_PIN);

String command;

void setup() {
  lcd.begin(16, 2); // initialize the lcd
  lcd.setBacklight(255);
  Serial.begin(9600); //Serial Comm (Serial Monitor)
  
  commSerial.begin(9600); //NodeMCU comm
}

void loop() {
  //if the nodeMCU is sendig data
  if (commSerial.available()) {
    //Save the received string in the variable command
    command = commSerial.readString();

    //Show the received string on the Arduino Serial
    Serial.println(command);
    //Send to the nodeMCU through the commSerial an ACK
    commSerial.write("The message has been sent!\n");
    
    //Print the message received on the LCD
    lcd.clear();
    lcd.print(command); 
  }
}
