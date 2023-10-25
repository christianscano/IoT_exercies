#include <DHT.h>
#include <MFRC522.h>
#include <SPI.h>
#include <LiquidCrystal_PCF8574.h>

/// PINS
// Humidity/Temp Sensor
#define DHT_PIN 2
#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

// REFID sensor
#define RST_PIN         9          
#define SS_PIN          10
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

// Display
LiquidCrystal_PCF8574 display(0x27);


/*
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 */
 
void setup() {
  Serial.begin(9600);
  
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)

  // Display initialization
  display.begin(16, 2);
  display.setBacklight(255);
  display.setCursor(0, 1);
  display.print("Display setup");
  
  // RIFID initialization
  SPI.begin();          // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  delay(4);             // Optional delay. Some board do need more time after init to be ready, see Readme
  display.print("RFID setup");

  // Humidity/Temp sensor
  dht.begin();
  display.print("Sens setup");
}

bool authenticated = false;
byte tags[];

void loop() {
  if (!authenticate) {
      // Reset the loop if no new card present on the sensor/reader.
      if (!mfrc522.PICC_IsNewCardPresent()) {
        return;
      }
       
      // Select one of the cards
      if (!mfrc522.PICC_ReadCardSerial()) {
        return;
      }

   
  }

  // Dump debug info about the card; PICC_HaltA() is automatically called
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
