#include "hardware/joysticks.h"

int16_t Joysticks::pitch_raw_min = INT16_MAX, Joysticks::pitch_raw_max = INT16_MIN;
int16_t Joysticks::roll_raw_min = INT16_MAX, Joysticks::roll_raw_max = INT16_MIN;
int16_t Joysticks::yaw_raw_min = INT16_MAX, Joysticks::yaw_raw_max = INT16_MIN;
int16_t Joysticks::throttle_raw_min = INT16_MAX, Joysticks::throttle_raw_max = INT16_MIN;

int16_t Joysticks::pitch_raw = 0, Joysticks::roll_raw = 0, Joysticks::yaw_raw = 0, Joysticks::throttle_raw = 0;
int Joysticks::pitch = 0, Joysticks::roll = 0, Joysticks::yaw = 0, Joysticks::throttle = 0;

bool Joysticks::calibrated = false;

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
  if(not calibrated) return -1;
  pitch_raw = pitch_raw_min > pitch_raw_max ?
    constrain(HardwareManager::adc.readADC_SingleEnded(pitch_channel), pitch_raw_max, pitch_raw_min):
    constrain(HardwareManager::adc.readADC_SingleEnded(pitch_channel), pitch_raw_min, pitch_raw_max);
  pitch = map(pitch_raw, pitch_raw_min, pitch_raw_max, JOYSTICK_MIN, JOYSTICK_MAX);
  return pitch;
}

int Joysticks::get_roll() {
  if(not calibrated) return -1;
  roll_raw = roll_raw_min > roll_raw_max ?
    constrain(HardwareManager::adc.readADC_SingleEnded(roll_channel), roll_raw_max, roll_raw_min):
    constrain(HardwareManager::adc.readADC_SingleEnded(roll_channel), roll_raw_min, roll_raw_max);
  roll = map(roll_raw, roll_raw_min, roll_raw_max, JOYSTICK_MIN, JOYSTICK_MAX);
  return roll;
}

int Joysticks::get_yaw() {
  if(not calibrated) return -1;
  yaw_raw = yaw_raw_min > yaw_raw_max ?
    constrain(HardwareManager::adc.readADC_SingleEnded(yaw_channel), yaw_raw_max, yaw_raw_min):
    constrain(HardwareManager::adc.readADC_SingleEnded(yaw_channel), yaw_raw_min, yaw_raw_max);
  yaw = map(yaw_raw, yaw_raw_min, yaw_raw_max, JOYSTICK_MIN, JOYSTICK_MAX);
  return yaw;
}

int Joysticks::get_throttle() {
  if(not calibrated) return -1;
  throttle_raw = throttle_raw_min > throttle_raw_max ?
    constrain(HardwareManager::adc.readADC_SingleEnded(throttle_channel), throttle_raw_max, throttle_raw_min):
    constrain(HardwareManager::adc.readADC_SingleEnded(throttle_channel), throttle_raw_min, throttle_raw_max);
  throttle = map(throttle_raw, throttle_raw_min, throttle_raw_max, JOYSTICK_MIN, JOYSTICK_MAX);
  return throttle;
}

void Joysticks::update_data_scaled() {
  if(not calibrated) return;
  get_pitch();
  get_roll();
  get_yaw();
  get_throttle();
}

