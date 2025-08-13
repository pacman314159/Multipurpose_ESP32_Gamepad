#include "hardware/storage.h"

void Storage::load_joysticks_calib_data(){
  HardwareManager::flash_mem.get(PITCH_RAW_MIN_ADDR, Joysticks::pitch_raw_min);
  HardwareManager::flash_mem.get(PITCH_RAW_MAX_ADDR, Joysticks::pitch_raw_max);

  HardwareManager::flash_mem.get(ROLL_RAW_MIN_ADDR, Joysticks::roll_raw_min);
  HardwareManager::flash_mem.get(ROLL_RAW_MAX_ADDR, Joysticks::roll_raw_max);

  HardwareManager::flash_mem.get(YAW_RAW_MIN_ADDR, Joysticks::yaw_raw_min);
  HardwareManager::flash_mem.get(YAW_RAW_MAX_ADDR, Joysticks::yaw_raw_max);

  HardwareManager::flash_mem.get(THROTTLE_RAW_MIN_ADDR, Joysticks::throttle_raw_min);
  HardwareManager::flash_mem.get(THROTTLE_RAW_MAX_ADDR, Joysticks::throttle_raw_max);

  Joysticks::calibrated = true;
}

void Storage::save_joysticks_calib_data(){
  HardwareManager::flash_mem.put(PITCH_RAW_MIN_ADDR, Joysticks::pitch_raw_min);
  HardwareManager::flash_mem.put(PITCH_RAW_MAX_ADDR, Joysticks::pitch_raw_max);

  HardwareManager::flash_mem.put(ROLL_RAW_MIN_ADDR, Joysticks::roll_raw_min);
  HardwareManager::flash_mem.put(ROLL_RAW_MAX_ADDR, Joysticks::roll_raw_max);

  HardwareManager::flash_mem.put(YAW_RAW_MIN_ADDR, Joysticks::yaw_raw_min);
  HardwareManager::flash_mem.put(YAW_RAW_MAX_ADDR, Joysticks::yaw_raw_max);

  HardwareManager::flash_mem.put(THROTTLE_RAW_MIN_ADDR, Joysticks::throttle_raw_min);
  HardwareManager::flash_mem.put(THROTTLE_RAW_MAX_ADDR, Joysticks::throttle_raw_max);

  Joysticks::calibrated = true;
  HardwareManager::flash_mem.commit();
}

