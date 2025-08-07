#ifndef JOYSTICKS_H
#define JOYSTICKS_H

#include <Arduino.h>
#include "hardware/hardware_manager.h"

#define JOYSTICK_MIN 0
#define JOYSTICK_MAX 2000

enum JoystickChannels {
  pitch_channel,
  roll_channel,
  yaw_channel,
  throttle_channel
};

class Joysticks {
private:
  // Calibration ranges
  static int pitch_raw_min, pitch_raw_max;
  static int roll_raw_min, roll_raw_max;
  static int yaw_raw_min, yaw_raw_max;
  static int throttle_raw_min, throttle_raw_max;

public:
  static int pitch_raw, roll_raw, yaw_raw, throttle_raw;
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
