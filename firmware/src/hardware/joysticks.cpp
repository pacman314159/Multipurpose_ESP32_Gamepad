#include "hardware/joysticks.h"

int Joysticks::pitch_raw_min = 0, Joysticks::pitch_raw_max = 4095;
int Joysticks::roll_raw_min = 0, Joysticks::roll_raw_max = 4095;
int Joysticks::yaw_raw_min = 0, Joysticks::yaw_raw_max = 4095;
int Joysticks::throttle_raw_min = 0, Joysticks::throttle_raw_max = 4095;

int Joysticks::pitch_raw = 0, Joysticks::roll_raw = 0, Joysticks::yaw_raw = 0, Joysticks::throttle_raw = 0;
int Joysticks::pitch = 0, Joysticks::roll = 0, Joysticks::yaw = 0, Joysticks::throttle = 0;


//  RAW GETTERS (direct ADC value) 
int Joysticks::get_pitch_raw() {
  pitch_raw = HardwareManager::adc.readADC_SingleEnded(pitch_channel);
  return pitch_raw;
}

int Joysticks::get_roll_raw() {
  roll_raw = HardwareManager::adc.readADC_SingleEnded(roll_channel);
  return roll_raw;
}

int Joysticks::get_yaw_raw() {
  yaw_raw = HardwareManager::adc.readADC_SingleEnded(yaw_channel);
  return yaw_raw;
}

int Joysticks::get_throttle_raw() {
  throttle_raw = HardwareManager::adc.readADC_SingleEnded(throttle_channel);
  return throttle_raw;
}

void Joysticks::update_data_raw() {
  pitch_raw    = HardwareManager::adc.readADC_SingleEnded(pitch_channel);
  roll_raw     = HardwareManager::adc.readADC_SingleEnded(roll_channel);
  yaw_raw      = HardwareManager::adc.readADC_SingleEnded(yaw_channel);
  throttle_raw = HardwareManager::adc.readADC_SingleEnded(throttle_channel);
}

//  SCALED GETTERS (0–2000)
int Joysticks::get_pitch() {
  pitch_raw = constrain(HardwareManager::adc.readADC_SingleEnded(pitch_channel),
                              pitch_raw_min,
                              pitch_raw_max);
  pitch     = map(pitch_raw,
                        pitch_raw_min,
                        pitch_raw_max,
                        JOYSTICK_MIN,
                        JOYSTICK_MAX);
  return pitch;
}

int Joysticks::get_roll() {
  roll_raw = constrain(HardwareManager::adc.readADC_SingleEnded(roll_channel),
                             roll_raw_min,
                             roll_raw_max);
  roll     = map(roll_raw,
                       roll_raw_min,
                       roll_raw_max,
                       JOYSTICK_MIN,
                       JOYSTICK_MAX);
  return roll;
}

int Joysticks::get_yaw() {
  yaw_raw = constrain(HardwareManager::adc.readADC_SingleEnded(yaw_channel),
                            yaw_raw_min,
                            yaw_raw_max);
  yaw     = map(yaw_raw,
                      yaw_raw_min,
                      yaw_raw_max,
                      JOYSTICK_MIN,
                      JOYSTICK_MAX);
  return yaw;
}

int Joysticks::get_throttle() {
  throttle_raw = constrain(HardwareManager::adc.readADC_SingleEnded(throttle),
                                 throttle_raw_min,
                                 throttle_raw_max);
  throttle     = map(throttle_raw,
                           throttle_raw_min,
                           throttle_raw_max,
                           JOYSTICK_MIN,
                           JOYSTICK_MAX);
  return throttle;
}

void Joysticks::update_data_scaled() {
  update_data_raw();  // always update first
  pitch    = map(constrain(pitch_raw, pitch_raw_min, pitch_raw_max), pitch_raw_min, pitch_raw_max, JOYSTICK_MIN, JOYSTICK_MAX);
  roll     = map(constrain(roll_raw,  roll_raw_min,  roll_raw_max),  roll_raw_min,  roll_raw_max,  JOYSTICK_MIN, JOYSTICK_MAX);
  yaw      = map(constrain(yaw_raw,   yaw_raw_min,   yaw_raw_max),   yaw_raw_min,   yaw_raw_max,   JOYSTICK_MIN, JOYSTICK_MAX);
  throttle = map(constrain(throttle_raw, throttle_raw_min, throttle_raw_max), throttle_raw_min, throttle_raw_max, JOYSTICK_MIN, JOYSTICK_MAX);
}

