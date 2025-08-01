#ifndef HARDWARE_MANAGEMENT_H
#define HARDWARE_MANAGEMENT_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <lvgl.h>
#include <TFT_eSPI.h>

#include "hardware_config.h"

class HardwareManager{
public:
  static void init();
  static Adafruit_NeoPixel& get_led_rgb();
  static TFT_eSPI& getLCD();

private:
  static Adafruit_NeoPixel led_rgb;
  static TFT_eSPI lcd;
};

#endif
