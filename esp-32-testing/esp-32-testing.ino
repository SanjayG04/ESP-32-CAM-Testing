
#include "esp_camera.h"

// AI Thinker ESP32-CAM pin configuration

#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5

#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

void setup() {

  Serial.begin(115200);
  delay(2000);

  Serial.println("\n===== CAMERA DIAGNOSTIC =====");

  // Camera configuration
  camera_config_t config;

  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;

  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;

  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;

  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;

  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;

  config.xclk_freq_hz = 20000000;

  // Start with RGB565
  config.pixel_format = PIXFORMAT_RGB565;
  config.frame_size = FRAMESIZE_VGA;
  config.jpeg_quality = 12;

  config.fb_count = 1;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;

  // Initialize camera
  Serial.println("Initializing camera...");

  esp_err_t err = esp_camera_init(&config);

  if (err != ESP_OK) {
    Serial.printf("Camera initialization FAILED: 0x%x\n", err);
    return;
  }

  Serial.println("Camera initialized successfully!");

  // Read camera sensor identification
  sensor_t *sensor = esp_camera_sensor_get();

  if (sensor == NULL) {
    Serial.println("Sensor information unavailable!");
    return;
  }

  Serial.println("\n===== SENSOR INFORMATION =====");

  Serial.printf("PID: 0x%04X\n", sensor->id.PID);
  Serial.printf("Version: 0x%02X\n", sensor->id.VER);
  Serial.printf("Manufacturer High: 0x%02X\n", sensor->id.MIDH);
  Serial.printf("Manufacturer Low: 0x%02X\n", sensor->id.MIDL);

  // Capture image
  Serial.println("\nCapturing image...");

  camera_fb_t *fb = esp_camera_fb_get();

  if (!fb) {
    Serial.println("Image capture FAILED!");
    return;
  }

  Serial.println("Image captured successfully!");

  Serial.printf("Width: %d\n", fb->width);
  Serial.printf("Height: %d\n", fb->height);
  Serial.printf("Format: %d\n", fb->format);
  Serial.printf("Image size: %u bytes\n", fb->len);

  esp_camera_fb_return(fb);

  Serial.println("\n===== CAMERA TEST COMPLETED =====");
}

void loop() {
  delay(5000);
}
