
#include <WiFi.h>
#include "esp_system.h"

const char* WIFI_SSID = "BroadBand_7353";
const char* WIFI_PASSWORD = "broadband7353";

void setup() {

  Serial.begin(115200);
  delay(2000);

  Serial.println("\n===== ESP32-CAM WIFI TEST =====");

  Serial.printf("Chip: %s\n", ESP.getChipModel());
  Serial.printf("Free Heap: %u\n", ESP.getFreeHeap());
  Serial.printf("Free PSRAM: %u\n", ESP.getFreePsram());

  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false);

  Serial.println("Starting WiFi...");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  int attempts = 0;

  while (WiFi.status() != WL_CONNECTED && attempts < 40) {

    delay(500);
    Serial.print(".");

    attempts++;

  }

  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {

    Serial.println("==============================");
    Serial.println("WIFI CONNECTED SUCCESSFULLY!");
    Serial.println("==============================");

    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    Serial.print("Signal Strength: ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");

  } else {

    Serial.println("WIFI CONNECTION FAILED");

    Serial.print("WiFi Status: ");
    Serial.println(WiFi.status());

  }
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi still connected");
  } else {
    Serial.println("WiFi disconnected");
  }

  delay(5000);
}
