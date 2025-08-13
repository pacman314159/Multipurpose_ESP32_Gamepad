#ifndef JOYSTICKS_H
#define JOYSTICKS_H

#include <Arduino.h>
#include "hardware_manager.h"

#define JOYSTICK_MIN 0
#define JOYSTICK_MAX 1000

enum joystick_channels{
  yaw_channel,
  throttle_channel,
  pitch_channel,
  roll_channel
};

class Joysticks {
public:
  static bool calibrated;

  // Calibration ranges
  static int16_t pitch_raw_min, pitch_raw_max;
  static int16_t roll_raw_min, roll_raw_max;
  static int16_t yaw_raw_min, yaw_raw_max;
  static int16_t throttle_raw_min, throttle_raw_max;

public:
  static int16_t pitch_raw, roll_raw, yaw_raw, throttle_raw;
  static int pitch, roll, yaw, throttle;

public:
  // Raw getters
  static int get_pitch_raw();
  static int get_roll_raw();
  static int get_yaw_raw();
  static int get_throttle_raw();
  static void update_data_raw();

  // Scaled getters
  static int get_pitch();
  static int get_roll();
  static int get_yaw();
  static int get_throttle();
  static void update_data_scaled();
};

#endif
