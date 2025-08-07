#include "hardware/hardware_manager.h"

TFT_eSPI HardwareManager::lcd = TFT_eSPI();
Adafruit_LC709203F HardwareManager::fuel_gauge = Adafruit_LC709203F();
Adafruit_ADS1015 HardwareManager::adc = Adafruit_ADS1015();

void HardwareManager::init() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN, I2C_TRANSMISSION_FREQUENCY);

  lcd.init();
  lcd.setRotation(2); //0: portrait, 1 landscape (CW), 2 portrait (down), 3 lanscape (CCW)

  fuel_gauge.begin();

  //init adc
  adc.begin();
  adc.setGain(GAIN_ONE);
}

TFT_eSPI& HardwareManager::get_lcd() {
  return lcd;
}

Adafruit_LC709203F& HardwareManager::get_fuel_gauge() {
  return fuel_gauge;
}

Adafruit_ADS1015& HardwareManager::get_adc(){
  return adc;
}
