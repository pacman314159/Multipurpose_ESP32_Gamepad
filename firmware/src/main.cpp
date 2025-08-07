#include <Arduino.h>
#include "tasks/task_manager.h"
#include "hardware/hardware_manager.h"
#include "ui/ui_manager.h"

void setup() {
  HardwareManager::init();
  UIManager::init();

  xTaskCreatePinnedToCore(lvgl_background_task, "LVGL LOOP TASK", 4096, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(joystick_raw_reading_task, "JOYSTICK RAW READING", 4096, NULL, 1, NULL, 0);
}

void loop() {
  // Serial.println("helloworld");
  // delay(250);
}
