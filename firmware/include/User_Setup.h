#include "hardware_config.h"

#define ST7735_DRIVER
#define USE_HSPI_PORT

#define TFT_WIDTH  TFT_HOR_RES
#define TFT_HEIGHT TFT_VER_RES

#define TFT_MOSI   SPI_MOSI_PIN
#define TFT_SCLK   SPI_SCK_PIN
#define TFT_CS     TFT_CS_PIN
#define TFT_DC     TFT_DC_PIN
#define TFT_RST    TFT_RES_PIN

// Optional: control backlight
#define TFT_BL     TFT_BL_PIN
#define TFT_BACKLIGHT_ON HIGH

// Fonts to load
#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8

// Optional smooth fonts
#define SMOOTH_FONT

#define SPI_FREQUENCY       27000000
#define SPI_READ_FREQUENCY  20000000
