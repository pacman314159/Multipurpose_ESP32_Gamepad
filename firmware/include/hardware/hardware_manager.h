#ifndef HARDWARE_MANAGEMENT_H
#define HARDWARE_MANAGEMENT_H

#include "Arduino.h"
#include "Wire.h"

#include "lvgl.h"
#include "TFT_eSPI.h"
#include "Adafruit_LC709203F.h"
#include "Adafruit_ADS1X15.h"

#include "hardware_config.h"

class HardwareManager{
public:
  static TFT_eSPI lcd;
  static Adafruit_LC709203F fuel_gauge;
  static Adafruit_ADS1015 adc;

public:
  static void init();
  static TFT_eSPI& get_lcd();
  static Adafruit_LC709203F& get_fuel_gauge();
  static Adafruit_ADS1015& get_adc();
};

#endif
