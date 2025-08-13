#include "Arduino.h"
#include "projdefs.h"
#include "tasks/task_manager.h"
#include "hardware/button_matrix.h"

void shift_in_reading_tasks(void *pvParameters){
  while(true){
    ButtonMatrix::scan();
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}
