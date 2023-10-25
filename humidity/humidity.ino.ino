#include "DHT.h"

#define DHT_PIN 2
#define DHT_TYPE DHT11


// DHT constructor
DHT dht(DHT_PIN, DHT_TYPE);


void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\n");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("˚C\n");
  delay(5000);
}
