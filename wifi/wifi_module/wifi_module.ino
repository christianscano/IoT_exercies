#include <SoftwareSerial.h>

#define RX_PIN D2
#define TX_PIN D3

SoftwareSerial commSerial(TX_PIN, RX_PIN);

void setup() {
  //Serial Comm (Serial Monitor)
  Serial.begin(9600);
  //New Serial Comm (Arduino)
  commSerial.begin(9600);
}

void loop() {
  if (Serial.available())
  //Data coming from the serial monitor
  commSerial.write(Serial.read());
  if (commSerial.available())
  // Data coming from Arduino UNO
  Serial.write(commSerial.read());
}
