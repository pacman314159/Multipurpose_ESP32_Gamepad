#include "task_manager.h"

void rgb_led_task(void *pvParameters){
  Adafruit_NeoPixel& rgb = HardwareManager::get_led_rgb();

  while (true) {
    rgb.setPixelColor(0, rgb.Color(255, 0, 0));  // Red
    rgb.show();
    vTaskDelay(pdMS_TO_TICKS(100));

    rgb.setPixelColor(0, rgb.Color(0, 0, 255));  // Blue
    rgb.show();
    vTaskDelay(pdMS_TO_TICKS(100));

    rgb.setPixelColor(0, rgb.Color(0, 255, 0));  // Green
    rgb.show();
    vTaskDelay(pdMS_TO_TICKS(100));
  }
}
