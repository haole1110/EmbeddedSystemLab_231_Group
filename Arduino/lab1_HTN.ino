#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Hello world!");

  // Print chip information
  esp_chip_info_t chip_info;
  uint32_t flash_size;

  esp_chip_info(&chip_info);
  Serial.printf("This is %s chip with %d CPU core(s), WiFi%s%s, ",
                CONFIG_IDF_TARGET,
                chip_info.cores,
                (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
                (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

  unsigned major_rev = chip_info.revision / 100;
  unsigned minor_rev = chip_info.revision % 100;
  Serial.printf("silicon revision v%d.%d, ", major_rev, minor_rev);

  if (esp_flash_get_size(NULL, &flash_size) != ESP_OK) {
    Serial.println("Get flash size failed");
    return;
  }

  Serial.printf("%uMB %s flash\n", flash_size / (uint32_t)(1024 * 1024),
                (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

  Serial.printf("Minimum free heap size: %u bytes\n", ESP.getFreeHeap());

  // Print countdown time
  for (int i = 10; i >= 0; i--) {
    Serial.printf("Restarting in %d seconds...\n", i);
    delay(1000);
  }
  Serial.println("Restarting now.");
  esp_restart();
}

void loop() {
  // Empty loop
}
