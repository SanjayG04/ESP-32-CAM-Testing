
#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("\n===== ESP32 HARDWARE DIAGNOSTICS =====");

  // Chip information
  Serial.printf("Chip Model: %s\n", ESP.getChipModel());
  Serial.printf("Chip Revision: %d\n", ESP.getChipRevision());
  Serial.printf("CPU Frequency: %d MHz\n", ESP.getCpuFreqMHz());

  // Flash information
  Serial.printf("Flash Size: %u bytes\n", ESP.getFlashChipSize());
  Serial.printf("Flash Speed: %u Hz\n", ESP.getFlashChipSpeed());

  // PSRAM information
  if (psramFound()) {
    Serial.println("PSRAM: DETECTED");
    Serial.printf("PSRAM Size: %u bytes\n", ESP.getPsramSize());
    Serial.printf("Free PSRAM: %u bytes\n", ESP.getFreePsram());
  } else {
    Serial.println("PSRAM: NOT DETECTED");
  }

  Serial.println("===== DIAGNOSTICS COMPLETED =====");
}

void loop() {
  delay(1000);
}
