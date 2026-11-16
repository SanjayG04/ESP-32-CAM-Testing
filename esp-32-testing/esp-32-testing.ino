
#include <WiFi.h>

const char* WIFI_SSID = "BroadBand_7353";
const char* WIFI_PASSWORD = "broadband7353";

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("\n===== ESP32-CAM WIFI TEST =====");

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to WiFi");

  int attempts = 0;

  while (WiFi.status() != WL_CONNECTED && attempts < 30) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWIFI CONNECTED!");

    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    Serial.print("Signal Strength: ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");
  } else {
    Serial.println("\nWIFI CONNECTION FAILED!");
  }
}

void loop() {
  delay(5000);
}
