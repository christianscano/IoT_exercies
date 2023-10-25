#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define SSID "Christian’s iPhone"
#define PASSWORD "am4zicstzdy3j"
#define PORT 80

ESP8266WebServer server(PORT);

void handle_root() {
  server.send(200, "text/html", "<script>window.location='https://google.com'</script>");
}

void handle_not_found() {
  String message = "File not found\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for(uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
}


void setup() {
  Serial.begin(9600);
  
  WiFi.mode(WIFI_STA); // Station mode
  WiFi.begin(SSID, PASSWORD);

  Serial.println("");

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);

    Serial.print(".");
  }

  Serial.print("\nConnected to ");
  Serial.println(SSID);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handle_root);
  server.on("/test", [](){ server.send(200, "text/plain", "Testing page"); });
  server.onNotFound(handle_not_found);

  server.begin();
  Serial.printf("HTTP Server started on port %d...\n", PORT);
}

void loop() {
  server.handleClient();
}
