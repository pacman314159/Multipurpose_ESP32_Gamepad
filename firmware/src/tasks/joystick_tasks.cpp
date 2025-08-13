#include "Arduino.h"
#include "tasks/task_manager.h"
#include "hardware/joysticks.h"
#include "hardware/storage.h"

void joysticks_reading_task(void *pvParameters){
  Storage::load_joysticks_calib_data();

  while(true){
    Joysticks::update_data_scaled();  
    Serial.print("Pitch: ");
    Serial.print(Joysticks::pitch);
    Serial.print(" Roll: ");
    Serial.print(Joysticks::roll);
    Serial.print(" Yaw: ");
    Serial.print(Joysticks::yaw);
    Serial.print(" Throttle: ");
    Serial.print(Joysticks::throttle);
    Serial.println(" ");

    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

void joysticks_raw_reading_task(void *pvParameters){
  while(true){
    Joysticks::update_data_raw();  
    Serial.print("Pitch: ");
    Serial.print(Joysticks::pitch_raw);
    Serial.print(" Roll: ");
    Serial.print(Joysticks::roll_raw);
    Serial.print(" Yaw: ");
    Serial.print(Joysticks::yaw_raw);
    Serial.print(" Throttle: ");
    Serial.print(Joysticks::throttle_raw);
    Serial.println(" ");

    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

void joysticks_calib_task(void *pvParameters){
  const uint32_t CALIB_TIME_MS = 2000;
  uint32_t start_time;

  //-------- INITIATION ------------

  Serial.println("START CALIBRATING JOYSTICKS IN 5");
  vTaskDelay(pdMS_TO_TICKS(1000));
  Serial.println("START CALIBRATING JOYSTICKS IN 4");
  vTaskDelay(pdMS_TO_TICKS(1000));
  Serial.println("START CALIBRATING JOYSTICKS IN 3");
  vTaskDelay(pdMS_TO_TICKS(1000));
  Serial.println("START CALIBRATING JOYSTICKS IN 2");
  vTaskDelay(pdMS_TO_TICKS(1000));
  Serial.println("START CALIBRATING JOYSTICKS IN 1");
  vTaskDelay(pdMS_TO_TICKS(1000));

  //-------- THROTTLE ------------
  Serial.println("Pull throttle up to physical max");
  start_time = millis();
  while(millis() - start_time < CALIB_TIME_MS)
    Joysticks::throttle_raw_max = Joysticks::get_throttle_raw();

  Serial.println("Pull throttle down to physical min");
  start_time = millis();
  while(millis() - start_time < CALIB_TIME_MS)
    Joysticks::throttle_raw_min = Joysticks::get_throttle_raw();

  //-------- YAW ------------
  Serial.println("Pull yaw right to physical max");
  start_time = millis();
  while(millis() - start_time < CALIB_TIME_MS)
    Joysticks::yaw_raw_max = Joysticks::get_yaw_raw();

  Serial.println("Pull yaw left to physical min");
  start_time = millis();
  while(millis() - start_time < CALIB_TIME_MS)
    Joysticks::yaw_raw_min = Joysticks::get_yaw_raw();

  //-------- PITCH ------------
  Serial.println("Pull pitch up to physical max");
  start_time = millis();
  while(millis() - start_time < CALIB_TIME_MS)
    Joysticks::pitch_raw_max = Joysticks::get_pitch_raw();

  Serial.println("Pull pitch down to physical min");
  start_time = millis();
  while(millis() - start_time < CALIB_TIME_MS)
    Joysticks::pitch_raw_min = Joysticks::get_pitch_raw();

  //-------- ROLL ------------
  Serial.println("Pull roll right to physical max");
  start_time = millis();
  while(millis() - start_time < CALIB_TIME_MS)
    Joysticks::roll_raw_max = Joysticks::get_roll_raw();

  Serial.println("Pull roll left to physical min");
  start_time = millis();
  while(millis() - start_time < CALIB_TIME_MS)
    Joysticks::roll_raw_min = Joysticks::get_roll_raw();

  //-------- COMPLETE ------------
  Storage::save_joysticks_calib_data();
  Serial.print("pitch: ");
  Serial.print(Joysticks::pitch_raw_min);
  Serial.print("---");
  Serial.println(Joysticks::pitch_raw_max);

  Serial.print("roll: ");
  Serial.print(Joysticks::roll_raw_min);
  Serial.print("---");
  Serial.println(Joysticks::roll_raw_max);

  Serial.print("yaw: ");
  Serial.print(Joysticks::yaw_raw_min);
  Serial.print("---");
  Serial.println(Joysticks::yaw_raw_max);

  Serial.print("throttle: ");
  Serial.print(Joysticks::throttle_raw_min);
  Serial.print("---");
  Serial.println(Joysticks::throttle_raw_max);

  Serial.println("Calibration complete!");
  vTaskDelete(NULL);
}
