#include "hardware/joysticks.h"
#include "task_manager.h"

void joystick_raw_reading_task(void *pvParameters){
  Joysticks::update_data_raw();  
  Serial.print("Pitch: ");
  Serial.print(Joysticks::pitch);
  Serial.print(" Roll: ");
  Serial.print(Joysticks::roll);
  Serial.print(" Yaw: ");
  Serial.print(Joysticks::yaw);
  Serial.print(" Throttle: ");
  Serial.print(Joysticks::throttle);
  Serial.println(" ");
}
