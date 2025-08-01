#include "hardware_manager.h"

Adafruit_NeoPixel HardwareManager::led_rgb = Adafruit_NeoPixel(NUM_RGB_LEDS, RGB_LED_PIN, NEO_GRB + NEO_KHZ800);
TFT_eSPI HardwareManager::lcd = TFT_eSPI();

void HardwareManager::init() {
  Serial.begin(115200);

  led_rgb.begin();
  led_rgb.setBrightness(50);
  led_rgb.show();

  lcd.init();
  lcd.setRotation(1);
}

Adafruit_NeoPixel& HardwareManager::get_led_rgb(){ return led_rgb; }
TFT_eSPI& HardwareManager::getLCD() { return lcd; }
