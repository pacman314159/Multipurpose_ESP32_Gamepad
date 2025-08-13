#include "hardware/hardware_manager.h"
#include "hardware_config.h"

TFT_eSPI HardwareManager::lcd = TFT_eSPI();
Adafruit_LC709203F HardwareManager::fuel_gauge = Adafruit_LC709203F();
Adafruit_ADS1015 HardwareManager::adc = Adafruit_ADS1015();
EEPROMClass& HardwareManager::flash_mem = EEPROM;
HC165D HardwareManager::shift_reg = HC165D();
HC4051 HardwareManager::mux = HC4051(MUX_S0_PIN, MUX_S1_PIN, 16);
// HC4051 HardwareManager::mux = HC4051(16, MUX_S1_PIN, MUX_S0_PIN);

void HardwareManager::init() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN, I2C_TRANSMISSION_FREQUENCY);

  lcd.init();
  lcd.setRotation(2); //0: portrait, 1 landscape (CW), 2 portrait (down), 3 lanscape (CCW)
  
  flash_mem.begin(FLASH_MEMORY_SIZE);

  // fuel_gauge.begin();

  //init adc
  adc.setGain(GAIN_ONE);
  adc.begin();
  
  //init shift reg
  shift_reg.begin(SHIFT_REG_PL_BAR_PIN,
                  SHIFT_REG_CE_PIN,
                  SHIFT_REG_Q7_BAR_PIN,
                  SHIFT_REG_CP_PIN);
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

HC165D& HardwareManager::get_shift_reg(){
  return shift_reg;
}

HC4051& HardwareManager::get_mux(){
  return mux;
}
