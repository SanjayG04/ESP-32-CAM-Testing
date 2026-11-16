
#include <WiFi.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

const char* WIFI_SSID = "BroadBand_7353";
const char* WIFI_PASSWORD = "broadband7353";

void setup() {

  Serial.begin(115200);
  delay(2000);

  Serial.println("\n===== ESP32-CAM WIFI TEST =====");

  // TEMPORARY DIAGNOSTIC ONLY:
  // Disable brownout detection on classic ESP32
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);

  Serial.println("Brownout detector disabled temporarily");

  Serial.printf("Chip: %s\n", ESP.getChipModel());
  Serial.printf("CPU: %d MHz\n", ESP.getCpuFreqMHz());

  Serial.println("Starting WiFi...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  int attempts = 0;

  while (WiFi.status() != WL_CONNECTED && attempts < 30) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {

    Serial.println("WIFI CONNECTED!");

    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    Serial.print("Signal Strength: ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");

  } else {

    Serial.println("WIFI CONNECTION FAILED");

  }
}

void loop() {
  delay(5000);
}
