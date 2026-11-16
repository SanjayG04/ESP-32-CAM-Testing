
#include <WiFi.h>

const char* ssid = "BroadBand_7353";
const char* password = "broadband7353";

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("\n===== WIFI DIAGNOSTIC =====");

  Serial.printf("Reset reason: %d\n", (int)esp_reset_reason());

  Serial.printf("Free heap: %u\n", ESP.getFreeHeap());
  Serial.printf("Free PSRAM: %u\n", ESP.getFreePsram());

  WiFi.mode(WIFI_STA);

  Serial.println("Starting WiFi...");
  WiFi.begin(ssid, password);

  for (int i = 0; i < 20; i++) {
    delay(500);

    Serial.printf(
      "WiFi status: %d | Free heap: %u\n",
      WiFi.status(),
      ESP.getFreeHeap()
    );

    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("WIFI CONNECTED!");
      Serial.println(WiFi.localIP());
      return;
    }
  }

  Serial.println("WiFi connection timeout");
}

void loop() {
  delay(1000);
}
