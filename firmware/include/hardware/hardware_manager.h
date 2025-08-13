#ifndef HARDWARE_MANAGER_H
#define HARDWARE_MANAGER_H

#include "Arduino.h"
#include "Wire.h"
#include "EEPROM.h"

#include "hardware_config.h"

#include "lvgl.h"
#include "TFT_eSPI.h"
#include "Adafruit_LC709203F.h"
#include "Adafruit_ADS1X15.h"
#include "HC165D.h"
#include "HC4051.h"


class HardwareManager{
public:
  static TFT_eSPI lcd;
  static Adafruit_LC709203F fuel_gauge;
  static Adafruit_ADS1015 adc;
  static EEPROMClass& flash_mem;
  static HC165D shift_reg;
  static HC4051 mux;

public:
  static void init();
  static TFT_eSPI& get_lcd();
  static Adafruit_LC709203F& get_fuel_gauge();
  static Adafruit_ADS1015& get_adc();
  static HC165D& get_shift_reg();
  static HC4051& get_mux();
};

#endif
