#include <Arduino.h>
#include <WiFi.h>
#include "centr.h"

const char* ssid = "CentrHub";
const char* password = "centrhub";


void setup() {
  // serial setup
  Serial.begin(921600);

  // setup soft-ap
  WiFi.softAP(ssid, password);
  IPAddress ip = WiFi.softAPIP();
  Serial.println(ip);
}

void loop() {
  Centr::print_stations();
  delay(1000);
}