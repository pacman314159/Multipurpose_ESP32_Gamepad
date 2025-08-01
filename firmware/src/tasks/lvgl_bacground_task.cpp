#include "task_manager.h"
#include <lvgl.h>

#include <vector>
#include <string>

void lvgl_background_task(void *pvParameters) {
  const TickType_t delay = pdMS_TO_TICKS(5);
  while (true) {
    lv_timer_handler();
    vTaskDelay(delay);
  }
}
