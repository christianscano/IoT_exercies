#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define SSID "Christian’s iPhone"
#define PASSWORD "am4zicstzdy3j"

WiFiClient wifi_client;
HTTPClient http_client;

String NAME ="";
String SURNAME ="";

void setup() {
  Serial.begin(9600);
  
  Serial.print("Connecting");
  WiFi.begin(SSID, PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("."); 
   }
  
  Serial.println(" connected");
   
  Serial.print("My IP is: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  String url = "http://serverIP/findPeople?name=" + NAME + "&surname=" + SURNAME;

  http.begin(wifi_client, url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
   
  Serial.print("[HTTP] GET...\n");
  
  int httpCode = http.GET();
  if (httpCode > 0) {
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);

    String payload = http.getString();
    Serial.println(payload);

    if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
      Serial.println("I have received a OK response");
    } 
   } else {
    Serial.printf("[HTTP] GET,error: %s\n", http.errorToString(httpCode).c_str()); 
   }
  
  delay(20000);
}
