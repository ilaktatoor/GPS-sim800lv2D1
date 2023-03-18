#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>


const char* ssid="trueno 86";
const char* password = "rootatkali";
IPAddress ip (192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

static const int RXPin = 5, TXPin = 4;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);


void setup() {
  Serial.begin(9600);
  ss.begin(GPSBaud);
  WiFi.softAP(ssid, password);

}
void loop() {
  // This sketch displays information every time a new sentence is correctly encoded.
  getCords();
  server.handleClient();

  
}

