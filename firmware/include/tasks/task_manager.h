#ifndef TASKS_COMMON_H
#define TASKS_COMMON_H

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "hardware/hardware_manager.h"

void lvgl_background_task(void *pvParameters);

void joysticks_reading_task(void *pvParameters);
void joysticks_raw_reading_task(void *pvParameters);
void joysticks_calib_task(void *pvParameters);

void shift_in_reading_tasks(void *pvParameters);

#endif

