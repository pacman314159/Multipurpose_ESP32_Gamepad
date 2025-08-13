#include <Arduino.h>
#include "tasks/task_manager.h"
#include "hardware/hardware_manager.h"
#include "ui/ui_manager.h"

void setup() {
  HardwareManager::init();
  UIManager::init();

  xTaskCreatePinnedToCore(lvgl_background_task, "LVGL LOOP TASK", 4096, NULL, 1, NULL, 0);
  // xTaskCreatePinnedToCore(joysticks_calib_task, "JOYSTICKS CALIBRATION TASK", 4096, NULL, 1, NULL, 0);
  // xTaskCreatePinnedToCore(joysticks_reading_task, "JOYSTICKS READING TASK", 4096, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(shift_in_reading_tasks, "SHIFT IN READING TASK", 4096, NULL, 1, NULL, 0);
}

void loop() {
}
