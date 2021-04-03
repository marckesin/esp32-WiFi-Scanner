#include <Arduino.h>
#include <WiFi.h>

char prBuffer[32];

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_MODE_STA);
}

void loop() {

  byte scanSsid = WiFi.scanNetworks();

  for (int i = 0; i < scanSsid; i++) {
    //sprintf(prBuffer, "ESSID:%2s ENC:%2d", WiFi.SSID(i), WiFi.encryptionType(i));
    //Serial.println(prBuffer);
    Serial.print(i);
    Serial.print(")");
    Serial.print(" BSSID: ");
    Serial.print(WiFi.BSSIDstr(i));
    Serial.print(" - ENC: ");
    Serial.print(WiFi.encryptionType(i), HEX);
    Serial.print(" - PWR: ");
    Serial.print(WiFi.RSSI(i));
    Serial.print(" - CH: ");
    Serial.print(WiFi.channel(i));
    Serial.print(" ");
    Serial.println(WiFi.SSID(i));
  }

  delay(10000);
  Serial.println();
}