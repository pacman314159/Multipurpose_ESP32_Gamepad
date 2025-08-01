#ifndef TASKS_COMMON_H
#define TASKS_COMMON_H

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "../hardware/hardware_manager.h"

void rgb_led_task(void *pvParameters);
void lvgl_background_task(void *pvParameters);

#endif

