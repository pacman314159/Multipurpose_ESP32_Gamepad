#ifndef STORAGE_H
#define STORAGE_H

#include "joysticks.h"
#include "hardware_manager.h"
#include "hardware/storage.h"
#include "hardware/joysticks.h"

enum calib_data_addr{
  PITCH_RAW_MIN_ADDR = 0,
  PITCH_RAW_MAX_ADDR = 2,
  ROLL_RAW_MIN_ADDR = 4,
  ROLL_RAW_MAX_ADDR = 6,
  YAW_RAW_MIN_ADDR = 8,
  YAW_RAW_MAX_ADDR = 10,
  THROTTLE_RAW_MIN_ADDR = 12,
  THROTTLE_RAW_MAX_ADDR = 14
};

class Storage{
private:

public:
  static void load_joysticks_calib_data();
  static void save_joysticks_calib_data();
};


#endif
