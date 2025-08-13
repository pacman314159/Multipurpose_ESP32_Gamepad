#include "tasks/task_manager.h"

void lvgl_background_task(void *pvParameters) {
  const TickType_t delay = pdMS_TO_TICKS(5);
  while (true) {
    lv_timer_handler();
    vTaskDelay(delay);
  }
}
